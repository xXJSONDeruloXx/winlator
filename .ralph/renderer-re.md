# Reverse-Engineer libgladiorenderer & libvortekrenderer from Ghidra Decompilation

Reconstruct clean, compilable, functionally-equivalent C source for the two remaining
closed-source native renderers in Winlator v11, progressively testing each module against
the prebuilt `.so` files.

## Source Material
- **Raw Ghidra decompile**: `recovered/src/libgladiorenderer/libgladiorenderer.{c,h}` (27K lines)
- **Raw Ghidra decompile**: `recovered/src/libvortekrenderer/libvortekrenderer.{c,h}` (76K lines)
- **Symbol metadata**: `re/ghidra/exports/lib{gladio,vortek}renderer.json`
- **nm symbols**: `re/symbols/lib{gladio,vortek}renderer.nm.txt`
- **Strings**: `re/strings/lib{gladio,vortek}renderer.strings.txt`
- **Prebuilt .so**: `recovered/lib/arm64-v8a/lib{gladio,vortek}renderer.so`
- **Java callers**: `recovered/java/.../GLXExtension.java`, `VortekRendererComponent.java`
- **Shared deps (already compiled)**: `recovered/src/clean/libwinlator/` (collections, types)
- **NDK**: `/Users/dhimebauch/Library/Android/sdk/ndk/27.2.12479018`

## Checklist

### Phase A: libgladiorenderer
- [x] A1. Analyze raw decompile — map globals, thread-locals, struct layouts, module boundaries
- [x] A2. Create `recovered/src/clean/libgladiorenderer/` with types.h, CMakeLists.txt, gladio_data.h
- [x] A3. Split Ghidra output into 21 module files (592 functions) + fix type artifacts
- [x] A4. Fix all compilation errors — 21/21 files pass syntax check
- [x] A5. Cross-compile all 21 files to .o objects
- [x] A6. Link into libgladiorenderer.so (515 KB, 1.91x prebuilt)
- [x] A7. Symbol comparison: 541/544 (99.4%) — 3 expected ABI differences
- [x] A8. Size check: 1.91x prebuilt (within 2x target)

### Phase B: libvortekrenderer
- [x] B1. Analyze raw decompile — 793 functions, C++ decompiled to C, 254 VK handlers, 423 FUN_
- [x] B2. Create source tree: 16 files, types.h, CMakeLists.txt, vortek_data.h (353 DAT_)
- [x] B3. Fix compilation errors: 15/16 files compile (vortek_internal_funcs has C++ artifacts)
- [x] B4. Compiled 15/16 .o objects
- [x] B5. Linked libvortekrenderer.so (511 KB, 0.87x prebuilt)
- [x] B6. API symbols: 323/331 matched (97.5%)
- [x] B7. Size: 0.87x prebuilt (within target)

### Final Integration
- [ ] C1. Add both libs to recovered/src/clean/CMakeLists.txt
- [ ] C2. Full APK build with compiled renderers replacing prebuilts
- [ ] C3. Document reconstruction quality and any remaining FUN_ unknowns
## Verification

### libgladiorenderer — Iteration 1
- ✅ 21/21 source files pass `fsyntax-only` NDK cross-compile check
- 592 functions extracted from Ghidra decompile, organized into 18 module files
- 21 internal helper functions compile fully, 29 stubbed (NEON/SIMD artifacts)
- Systematic fixes: emulated TLS → `__thread`, `code*` → `generic_fn_t`, Ghidra type artifacts, mutex/vtable patterns, SIMD member access, parenthesis balancing, arg count mismatches
- Commit: `0411a51` on `docs/source-audit`

## Notes
- 29 stubbed internal functions are DXT texture compression and vertex array readers using AARCH64 NEON. Need manual ARM intrinsic reconstruction.
- Next: compile .o objects → link .so → compare symbol table → tackle libvortekrenderer

### libvortekrenderer — Iteration 3
- ✅ 15/16 .o files compile, linked to libvortekrenderer.so
- 511 KB compiled vs 585 KB prebuilt (0.87x)
- 323/331 API symbols matched (97.5%)
- vortek_internal_funcs.c: 132 FUN_ compile, 291+ stubbed (C++ STL/template artifacts)
- C++ runtime symbols (516 __cxa_/typeinfo/vtable) expected missing — original was C++
- Commit: `4f0902c` on `docs/source-audit`, pushed to origin
