// re/ghidra/scripts/WinlatorLabelImports.java
// Labels all undefined external symbols in the binary with their source library
// based on the dependency map we know from nm -D analysis.
// Run this BEFORE WinlatorExport so the exports have clean symbol names.
//
//@category Winlator
//@author xXJSONDeruloXx

import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.util.*;

public class WinlatorLabelImports extends GhidraScript {

    // Known providers: symbol → providing library
    private static final Map<String, String> PROVIDERS = new HashMap<>();
    static {
        // libwinlator.so custom data structures
        String[] winlatorSyms = {
            "ArrayBuffer_available", "ArrayBuffer_free", "ArrayBuffer_get",
            "ArrayBuffer_getBytes", "ArrayBuffer_getDouble", "ArrayBuffer_getFloat",
            "ArrayBuffer_getInt", "ArrayBuffer_getLong", "ArrayBuffer_getShort",
            "ArrayBuffer_put", "ArrayBuffer_putBytes", "ArrayBuffer_putDouble",
            "ArrayBuffer_putFloat", "ArrayBuffer_putFloat2", "ArrayBuffer_putFloat3",
            "ArrayBuffer_putFloat4", "ArrayBuffer_putInt", "ArrayBuffer_putLong",
            "ArrayBuffer_putShort", "ArrayBuffer_putString", "ArrayBuffer_rewind",
            "ArrayDeque_addLast", "ArrayDeque_free", "ArrayDeque_getLast",
            "ArrayDeque_isEmpty", "ArrayDeque_removeFirst",
            "ArrayList_add", "ArrayList_addAt", "ArrayList_free", "ArrayList_fromStrings",
            "ArrayList_indexOf", "ArrayList_remove", "ArrayList_removeAt",
            "ArrayMap_free", "ArrayMap_get", "ArrayMap_put", "ArrayMap_removeAt",
            "IntArray_add", "IntArray_addAll", "IntArray_clear", "IntArray_sort",
            "RingBuffer_create", "RingBuffer_free", "RingBuffer_getHead",
            "RingBuffer_getSHMemSize", "RingBuffer_getTail", "RingBuffer_hasStatus",
            "RingBuffer_read", "RingBuffer_setHead", "RingBuffer_setStatus",
            "RingBuffer_setTail", "RingBuffer_waitForRead", "RingBuffer_waitForWrite",
            "RingBuffer_write",
            "SparseArray_free", "SparseArray_get", "SparseArray_put",
            "SparseArray_remove", "SparseArray_removeAt",
            "ashmemCreateRegion", "globalEGLContext",
            "AHardwareBuffer_getFd", "ArrayBuffer_copy",
        };
        for (String s : winlatorSyms) PROVIDERS.put(s, "libwinlator.so");

        // libhook_impl.so
        String[] hookSyms = {
            "hook_android_dlopen_ext", "hook_android_load_sphal_library",
            "hook_fopen", "hook_gsl_memory_alloc_pure_64", "hook_gsl_memory_free_pure",
        };
        for (String s : hookSyms) PROVIDERS.put(s, "libhook_impl.so");
    }

    @Override
    public void run() throws Exception {
        SymbolTable symTable = currentProgram.getSymbolTable();
        int labeled = 0;
        for (Symbol sym : symTable.getDefinedSymbols()) {
            String name = sym.getName();
            if (PROVIDERS.containsKey(name)) {
                String provider = PROVIDERS.get(name);
                String comment = "← " + provider;
                // Set plate comment on the function if there is one at this address
                Function func = currentProgram.getFunctionManager()
                    .getFunctionAt(sym.getAddress());
                if (func != null) {
                    String existing = currentProgram.getListing()
                        .getComment(ghidra.program.model.listing.CodeUnit.PLATE_COMMENT,
                                    sym.getAddress());
                    if (existing == null || !existing.contains(provider)) {
                        currentProgram.getListing().setComment(sym.getAddress(),
                            ghidra.program.model.listing.CodeUnit.PLATE_COMMENT,
                            comment);
                        labeled++;
                    }
                }
            }
        }
        println("WinlatorLabelImports: labeled " + labeled + " symbols");
    }
}
