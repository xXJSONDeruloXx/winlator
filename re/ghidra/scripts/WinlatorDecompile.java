// re/ghidra/scripts/WinlatorDecompile.java
// Decompiles all functions to a .c/.h pair using Ghidra's DecompInterface.
// Produces near-compilable C with proper types and filtered PLT stubs.
//
// Usage (headless):
//   analyzeHeadless <project> Winlator_v11 -process <lib>.so \
//     -scriptPath re/ghidra/scripts \
//     -postScript WinlatorDecompile.java <output_dir>
//
//@category Winlator
//@author xXJSONDeruloXx

import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import java.io.*;
import java.util.*;
import java.util.regex.*;

public class WinlatorDecompile extends GhidraScript {

    // Include inference: imported symbol prefix → header
    private static final Map<String, String> INCLUDE_MAP = new LinkedHashMap<>();
    static {
        INCLUDE_MAP.put("Java_",             "#include <jni.h>");
        INCLUDE_MAP.put("AHardwareBuffer",   "#include <android/hardware_buffer.h>");
        INCLUDE_MAP.put("__android_log",     "#include <android/log.h>");
        INCLUDE_MAP.put("android_dlopen",    "#include <android/dlopen_ext.h>");
        INCLUDE_MAP.put("vk",                "#include <vulkan/vulkan.h>");
        INCLUDE_MAP.put("VK_",               "#include <vulkan/vulkan.h>");
        INCLUDE_MAP.put("egl",               "#include <EGL/egl.h>");
        INCLUDE_MAP.put("gl",                "#include <GLES3/gl32.h>");
        INCLUDE_MAP.put("pthread",           "#include <pthread.h>");
        INCLUDE_MAP.put("dlopen",            "#include <dlfcn.h>");
        INCLUDE_MAP.put("dlsym",             "#include <dlfcn.h>");
        INCLUDE_MAP.put("fopen",             "#include <stdio.h>");
        INCLUDE_MAP.put("sprintf",           "#include <stdio.h>");
        INCLUDE_MAP.put("malloc",            "#include <stdlib.h>");
        INCLUDE_MAP.put("free",              "#include <stdlib.h>");
        INCLUDE_MAP.put("memcpy",            "#include <string.h>");
        INCLUDE_MAP.put("strlen",            "#include <string.h>");
        INCLUDE_MAP.put("open",              "#include <fcntl.h>");
        INCLUDE_MAP.put("hook_",             "#include \"hook_impl.h\"");
        INCLUDE_MAP.put("Array",             "#include \"winlator/containers.h\"");
        INCLUDE_MAP.put("RingBuffer",        "#include \"winlator/containers.h\"");
        INCLUDE_MAP.put("SparseArray",       "#include \"winlator/containers.h\"");
    }

    // Type fixes — ORDER MATTERS: most specific first, use word-boundary regex
    private static final String[][] TYPE_FIXES = {
        {"undefined8",  "uint64_t"},
        {"undefined4",  "uint32_t"},
        {"undefined2",  "uint16_t"},
        {"undefined1",  "uint8_t"},
        {"ulonglong",   "uint64_t"},   // before "uint"
        {"longlong",    "int64_t"},
        {"ushort",      "uint16_t"},   // before "uint"
        {"uchar",       "uint8_t"},    // before "uint"
        {"uint",        "uint32_t"},   // last: \b prevents hitting uint64_t etc.
        {"undefined",   "uint8_t"},    // after undefined4/2/1
        {"BADSPACEBASE","void*"},
    };

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outDir = (args != null && args.length > 0) ? args[0]
            : System.getProperty("user.home") + "/winlator_decompile";
        new File(outDir).mkdirs();

        String progName = currentProgram.getName().replace(".so", "");
        File outFile = new File(outDir, progName + ".c");
        File hFile   = new File(outDir, progName + ".h");
        println("WinlatorDecompile: decompiling " + progName + " -> " + outFile);

        // Collect imported symbol names to identify PLT stubs
        ExternalManager extMgr = currentProgram.getExternalManager();
        Set<String> importedNames = new HashSet<>();
        for (String lib : extMgr.getExternalLibraryNames()) {
            ExternalLocationIterator it = extMgr.getExternalLocations(lib);
            while (it.hasNext()) importedNames.add(it.next().getLabel());
        }

        // Infer includes from imported symbols
        Set<String> includes = new LinkedHashSet<>();
        includes.add("#include <stdint.h>");
        includes.add("#include <stdbool.h>");
        for (String sym : importedNames) {
            for (Map.Entry<String, String> e : INCLUDE_MAP.entrySet()) {
                if (sym.startsWith(e.getKey())) includes.add(e.getValue());
            }
        }

        // Collect exported symbol names
        Set<String> exported = new LinkedHashSet<>();
        SymbolTable symTable = currentProgram.getSymbolTable();
        for (Symbol sym : symTable.getDefinedSymbols()) {
            if (sym.isExternalEntryPoint()) exported.add(sym.getName());
        }

        // Init decompiler
        DecompInterface decomp = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.setMaxPayloadMBytes(64);
        decomp.setOptions(opts);
        decomp.toggleCCode(true);
        decomp.toggleSyntaxTree(true);
        decomp.setSimplificationStyle("decompile");
        decomp.openProgram(currentProgram);

        FunctionManager funcMgr = currentProgram.getFunctionManager();
        int total = funcMgr.getFunctionCount();
        int done = 0, skipped = 0;

        // Sort: exported first, then by name
        List<Function> funcs = new ArrayList<>();
        for (Function f : funcMgr.getFunctions(true)) funcs.add(f);
        funcs.sort((a, b) -> {
            boolean ae = exported.contains(a.getName());
            boolean be = exported.contains(b.getName());
            if (ae != be) return ae ? -1 : 1;
            return a.getName().compareTo(b.getName());
        });

        StringBuilder header = new StringBuilder();
        header.append("// ").append(progName).append(".h — auto-generated by WinlatorDecompile\n");
        header.append("// Source: ").append(currentProgram.getName()).append("\n\n");
        header.append("#pragma once\n#include <stdint.h>\n#include <stdbool.h>\n\n");

        StringBuilder src = new StringBuilder();
        src.append("// ").append(progName).append(".c — auto-generated by WinlatorDecompile\n");
        src.append("// Source: ").append(currentProgram.getName()).append("\n\n");
        for (String inc : includes) src.append(inc).append("\n");
        src.append("#include \"").append(progName).append(".h\"\n\n");

        String lastSection = "";
        for (Function func : funcs) {
            if (monitor.isCancelled()) break;
            done++;
            if (done % 50 == 0) println("  " + done + "/" + total);

            // Skip PLT stubs: tiny functions with same name as an import
            if (importedNames.contains(func.getName())
                    && func.getBody().getNumAddresses() <= 32) {
                skipped++;
                continue;
            }

            DecompileResults res = decomp.decompileFunction(func, 30, monitor);
            if (res == null || !res.decompileCompleted()) continue;
            DecompiledFunction df = res.getDecompiledFunction();
            if (df == null) continue;

            String c = applyTypeFixes(df.getC());

            // Skip self-calling stubs: body is just funcName(...); return;
            if (isSelfCallingStub(func.getName(), c)) {
                skipped++;
                continue;
            }

            // Skip halt_baddata stubs
            if (c.contains("halt_baddata()")) {
                skipped++;
                continue;
            }

            String section = exported.contains(func.getName()) ? "exported" : "internal";
            if (!section.equals(lastSection)) {
                src.append("\n// ─────────────────────────────────────────────\n");
                src.append("// ").append(section.toUpperCase()).append("\n");
                src.append("// ─────────────────────────────────────────────\n\n");
                if ("exported".equals(section)) header.append("// Exported API\n");
                lastSection = section;
            }

            if (exported.contains(func.getName())) {
                String sig = df.getSignature();
                if (sig != null) header.append(applyTypeFixes(sig)).append(";\n");
            }

            src.append("/* @").append(func.getEntryPoint())
               .append("  size=").append(func.getBody().getNumAddresses()).append(" */\n");
            src.append(c).append("\n");
        }

        decomp.closeProgram();

        try (FileWriter fw = new FileWriter(hFile))  { fw.write(header.toString()); }
        try (FileWriter fw = new FileWriter(outFile)) { fw.write(src.toString()); }

        println("WinlatorDecompile: wrote " + (done - skipped) + " functions ("
            + skipped + " PLT stubs skipped)");
        println("  .h -> " + hFile);
        println("  .c -> " + outFile);
    }

    /** Returns true if the function body is just a call to itself (PLT trampoline).
     *  Uses word-boundary matching so "gsl_foo" is not confused with "hook_gsl_foo".
     *  Checks only the body (between outer braces), NOT the signature line, so that
     *  "gsl_memory_alloc_pure_64(...)" in the signature doesn't match itself. */
    private boolean isSelfCallingStub(String name, String c) {
        if (c == null) return false;
        String stripped = c.replaceAll("/\\*.*?\\*/", "");
        // Extract just the body between the outermost braces
        int open = stripped.indexOf('{');
        int close = stripped.lastIndexOf('}');
        if (open < 0 || close < 0 || close <= open) return false;
        String body = stripped.substring(open + 1, close);
        // Count real statements (non-empty, non-return)
        int stmts = 0;
        for (String line : body.split("\n")) {
            line = line.trim();
            if (line.isEmpty() || line.startsWith("//") || line.equals("return;")) continue;
            stmts++;
        }
        // Self-call: body calls the exact same function name (word boundary, not a prefix)
        boolean selfCall = Pattern.compile("\\b" + Pattern.quote(name) + "\\s*\\(")
                                  .matcher(body).find();
        return stmts == 1 && selfCall;
    }

    /** Apply type substitutions using word-boundary regex to prevent cascading */
    private String applyTypeFixes(String c) {
        if (c == null) return "";
        for (String[] fix : TYPE_FIXES) {
            c = c.replaceAll("\\b" + Pattern.quote(fix[0]) + "\\b", fix[1]);
        }
        return c;
    }
}
