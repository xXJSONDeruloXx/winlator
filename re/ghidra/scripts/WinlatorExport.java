// re/ghidra/scripts/WinlatorExport.java
// Ghidra post-analysis script: exports function list, call edges, and
// resolved symbol names to JSON. Run via analyzeHeadless -postScript or
// from the Script Manager inside Ghidra.
//
// Usage (headless):
//   analyzeHeadless <project_dir> <project_name> -process <binary>
//     -scriptPath re/ghidra/scripts -postScript WinlatorExport.java <output.json>
//
//@category Winlator
//@author xXJSONDeruloXx

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;
import ghidra.program.model.address.*;
import ghidra.util.task.TaskMonitor;
import java.io.*;
import java.util.*;

public class WinlatorExport extends GhidraScript {

    @Override
    public void run() throws Exception {
        String outputPath = null;
        String[] args = getScriptArgs();
        if (args != null && args.length > 0) {
            outputPath = args[0];
        } else {
            outputPath = System.getProperty("user.home") + "/winlator_export_"
                + currentProgram.getName() + ".json";
        }

        println("WinlatorExport: writing to " + outputPath);

        FunctionManager funcMgr = currentProgram.getFunctionManager();
        SymbolTable symTable = currentProgram.getSymbolTable();
        ReferenceManager refMgr = currentProgram.getReferenceManager();

        StringBuilder sb = new StringBuilder();
        sb.append("{\n");
        sb.append("  \"program\": \"").append(escape(currentProgram.getName())).append("\",\n");
        sb.append("  \"imageBase\": \"").append(currentProgram.getImageBase()).append("\",\n");

        // ── Exported symbols ─────────────────────────────────────────────
        sb.append("  \"exports\": [\n");
        boolean first = true;
        for (Symbol sym : symTable.getDefinedSymbols()) {
            if (sym.isExternalEntryPoint() || sym.getSource() == SourceType.IMPORTED
                    || sym.getSource() == SourceType.USER_DEFINED) {
                if (!first) sb.append(",\n");
                first = false;
                sb.append("    {\"name\": \"").append(escape(sym.getName(true)))
                  .append("\", \"addr\": \"").append(sym.getAddress()).append("\"")
                  .append(", \"type\": \"").append(sym.getSymbolType()).append("\"}");
            }
        }
        sb.append("\n  ],\n");

        // ── Functions ────────────────────────────────────────────────────
        sb.append("  \"functions\": [\n");
        first = true;
        for (Function func : funcMgr.getFunctions(true)) {
            if (monitor.isCancelled()) break;
            if (!first) sb.append(",\n");
            first = false;
            sb.append("    {\n");
            sb.append("      \"name\": \"").append(escape(func.getName())).append("\",\n");
            sb.append("      \"addr\": \"").append(func.getEntryPoint()).append("\",\n");
            sb.append("      \"size\": ").append(func.getBody().getNumAddresses()).append(",\n");
            sb.append("      \"isThunk\": ").append(func.isThunk()).append(",\n");
            sb.append("      \"signature\": \"").append(escape(func.getSignature().toString())).append("\"");

            // Callees
            Set<Function> called = func.getCalledFunctions(monitor);
            if (!called.isEmpty()) {
                sb.append(",\n      \"calls\": [");
                boolean fc = true;
                for (Function callee : called) {
                    if (!fc) sb.append(", ");
                    fc = false;
                    sb.append("\"").append(escape(callee.getName())).append("\"");
                }
                sb.append("]");
            }
            sb.append("\n    }");
        }
        sb.append("\n  ],\n");

        // ── External/imported symbols ─────────────────────────────────────
        sb.append("  \"imports\": [\n");
        first = true;
        ExternalManager extMgr = currentProgram.getExternalManager();
        for (ExternalLocation extLoc : (Iterable<ExternalLocation>) extMgr.getExternalLocations()::iterator) {
            if (!first) sb.append(",\n");
            first = false;
            sb.append("    {\"name\": \"").append(escape(extLoc.getLabel()))
              .append("\", \"library\": \"").append(escape(extLoc.getLibraryName())).append("\"}");
        }
        sb.append("\n  ]\n}\n");

        // Write output
        try (FileWriter fw = new FileWriter(outputPath)) {
            fw.write(sb.toString());
        }
        println("WinlatorExport: done → " + outputPath);
    }

    private String escape(String s) {
        return s == null ? "" : s.replace("\\", "\\\\").replace("\"", "\\\"")
                                 .replace("\n", "\\n").replace("\r", "\\r");
    }
}
