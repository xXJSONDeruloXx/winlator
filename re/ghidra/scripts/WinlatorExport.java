// re/ghidra/scripts/WinlatorExport.java
// Ghidra post-analysis script: exports function list, call edges, and
// resolved symbol names to JSON. Run via analyzeHeadless -postScript or
// from the Script Manager inside Ghidra.
//
// Fixed for Ghidra 12: ExternalManager.getExternalLocations() no longer
// has a no-arg overload; iterate library names first.
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
        String[] args = getScriptArgs();
        String outputPath = (args != null && args.length > 0)
            ? args[0]
            : System.getProperty("user.home") + "/winlator_export_" + currentProgram.getName() + ".json";

        println("WinlatorExport: writing to " + outputPath);

        FunctionManager funcMgr = currentProgram.getFunctionManager();
        SymbolTable symTable    = currentProgram.getSymbolTable();
        ExternalManager extMgr  = currentProgram.getExternalManager();

        StringBuilder sb = new StringBuilder();
        sb.append("{\n");
        sb.append("  \"program\": \"").append(esc(currentProgram.getName())).append("\",\n");
        sb.append("  \"imageBase\": \"").append(currentProgram.getImageBase()).append("\",\n");

        // ── Exports (entry points + user-defined symbols) ─────────────────
        sb.append("  \"exports\": [\n");
        boolean first = true;
        for (Symbol sym : symTable.getDefinedSymbols()) {
            if (!sym.isExternalEntryPoint() && sym.getSource() != SourceType.IMPORTED) continue;
            if (!first) sb.append(",\n");
            first = false;
            sb.append("    {\"name\":\"").append(esc(sym.getName(true)))
              .append("\",\"addr\":\"").append(sym.getAddress())
              .append("\",\"type\":\"").append(sym.getSymbolType()).append("\"}");
        }
        sb.append("\n  ],\n");

        // ── Functions ─────────────────────────────────────────────────────
        sb.append("  \"functions\": [\n");
        first = true;
        for (Function func : funcMgr.getFunctions(true)) {
            if (monitor.isCancelled()) break;
            if (!first) sb.append(",\n");
            first = false;
            sb.append("    {\"name\":\"").append(esc(func.getName()))
              .append("\",\"addr\":\"").append(func.getEntryPoint())
              .append("\",\"size\":").append(func.getBody().getNumAddresses())
              .append(",\"thunk\":").append(func.isThunk());
            Set<Function> callees = func.getCalledFunctions(monitor);
            if (!callees.isEmpty()) {
                sb.append(",\"calls\":[");
                boolean fc = true;
                for (Function c : callees) {
                    if (!fc) sb.append(",");
                    fc = false;
                    sb.append("\"").append(esc(c.getName())).append("\"");
                }
                sb.append("]");
            }
            sb.append("}");
        }
        sb.append("\n  ],\n");

        // ── Imports (Ghidra 12 API: iterate per library name) ─────────────
        sb.append("  \"imports\": [\n");
        first = true;
        for (String libName : extMgr.getExternalLibraryNames()) {
            ExternalLocationIterator it = extMgr.getExternalLocations(libName);
            while (it.hasNext()) {
                ExternalLocation loc = it.next();
                if (!first) sb.append(",\n");
                first = false;
                sb.append("    {\"name\":\"").append(esc(loc.getLabel()))
                  .append("\",\"library\":\"").append(esc(loc.getLibraryName())).append("\"}");
            }
        }
        sb.append("\n  ]\n}\n");

        try (FileWriter fw = new FileWriter(outputPath)) {
            fw.write(sb.toString());
        }
        println("WinlatorExport: done (" + currentProgram.getFunctionManager().getFunctionCount()
            + " functions) -> " + outputPath);
    }

    private String esc(String s) {
        if (s == null) return "";
        return s.replace("\\", "\\\\").replace("\"", "\\\"")
                .replace("\n", "\\n").replace("\r", "\\r");
    }
}
