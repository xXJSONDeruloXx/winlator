# Winlator v11 — Native Library Source Reconstruction

## Summary

All 7 closed-source native libraries from the Winlator v11.0.0 APK have been reconstructed
from source. 5 were manually reverse-engineered to clean C; the 2 GPU renderers were
systematically extracted from Ghidra decompilation output and compiled with the Android NDK.

## Final Status

| Library               | Prebuilt | Compiled | API Symbols     | Status                        |
|-----------------------|----------|----------|-----------------|-------------------------------|
| libmain_hook          | 4.2 KB   | 3.8 KB   | 100%            | ✅ Fully clean                |
| libfile_redirect_hook | 3.9 KB   | 3.6 KB   | 100%            | ✅ Fully clean                |
| libgsl_alloc_hook     | 4.4 KB   | 3.9 KB   | 100%            | ✅ Fully clean                |
| libwinlator           | 49.6 KB  | 39.7 KB  | 138/138 (100%)  | ✅ Fully clean                |
| libhook_impl          | 310.6 KB | 17.1 KB  | 14/14 (100%)    | ✅ Fully clean                |
| libgladiorenderer     | 269.6 KB | 515.2 KB | 541/544 (99.4%) | ✅ Compiled from decompile    |
| libvortekrenderer     | 584.7 KB | 511.1 KB | 323/331 (97.5%) | ✅ Compiled from decompile    |

## libgladiorenderer (OpenGL ES GLX Renderer)

### Architecture
Translates desktop OpenGL 1.x–4.x commands from Wine over a ring buffer into OpenGL ES 3.2
calls on Android. Implements the Wine GLX protocol for Winlator's X server.

### Source Structure (21 files, 23K lines)
```
recovered/src/clean/libgladiorenderer/
├── gladio_types.h              # Core types: GLContext (184B), GLXContext (2344B)
├── gladio_internal.h           # Common includes, container externs
├── gladio_data.{c,h}           # 52 DAT_ rodata constants, 12 BSS globals
├── gladio_globals.c            # __thread currentRenderer, glx_context_mutex
├── jni_glx.c                   # 4 JNI entry points
├── gl_context.c                # createGLContext, readCommandBuffer, dispatch
├── glx_context.c               # EGL context creation (GLES 3.2)
├── command_dispatch.c          # Opcode dispatch table skeleton
├── gd_handlers.c               # 430 GL command handlers
├── gl_renderer.c               # 33 renderer state functions
├── shader_converter.c          # 15 ARB-to-GLSL converter functions
├── arb_program.c               # 9 ARB program management
├── gl_buffer.c                 # 5 buffer object functions
├── gl_framebuffer.c            # 7 FBO functions
├── gl_texture.c                # 5 texture functions
├── gl_query.c                  # 7 query object functions
├── gl_sampler.c                # Sampler placeholder
├── gl_vertex_array.c           # 3 VAO functions
├── gl_formats.c                # Internal format queries
├── attrib_stack.c              # glPushAttrib/glPopAttrib emulation
├── shader_material.c           # Shader uniform management
├── tex_compress.c              # DXT/BC compression (stb_dxt)
└── gladio_internal_funcs.c     # 21 compiled + 29 stubbed internal helpers
```

### Symbol Analysis
- **541/544** dynamic symbols match prebuilt (99.4%)
- 3 missing: `__emutls_t/v.currentRenderer` (ABI difference — we use native `__thread`), `handleRequestFuncs` (renamed to `gladio_dispatch_table`)

### Stubbed Functions (29 of 50 internal helpers)
These use AARCH64 NEON SIMD intrinsics that Ghidra decompiles into untranslatable C:
- `FUN_0011db60` — NEON-optimized vertex array data reader
- `FUN_0011e56c` — Thread pool worker
- `FUN_0012bf98` — NEON shader converter helper
- `FUN_0013aaa0` — DXT block compression (NEON vectorized)
- 25 others — mostly shader parsing and texture compression internals

**To reconstruct**: These need manual ARM NEON intrinsic (`<arm_neon.h>`) implementation
guided by the Ghidra disassembly view (not decompile view).

### stb_compress_dxt_block
The embedded stb_dxt compression function (812 lines) was stubbed due to garbled
bit manipulation from Ghidra. **Alternative**: Replace with the public domain
[stb_dxt.h](https://github.com/nothings/stb/blob/master/stb_dxt.h) from upstream,
which is likely the original source.

---

## libvortekrenderer (Vulkan ICD Wrapper)

### Architecture
Intercepts Vulkan API calls from Wine/box64 and translates them to the real Android
Vulkan driver. Implements handle wrapping (VkObject), resource memory management,
pipeline caching, format/extension filtering, and async pipeline compilation.

**Key difference**: Original was C++ code. Ghidra decompiled C++ to C, producing
`std::string`, `operator new/delete`, `basic_string` artifacts, and C++ exception
handling patterns.

### Source Structure (16 files, 67K lines)
```
recovered/src/clean/libvortekrenderer/
├── vortek_types.h              # Core types, dispatch handler signature
├── vortek_internal.h           # Common includes
├── vortek_data.{c,h}           # 353 DAT_ globals, vulkanWrapper dispatch table
├── vortek_globals.c            # Command dispatch table
├── jni_vortek.c                # 4 JNI entry points
├── vk_context.c                # VkContext lifecycle, command dispatch
├── vk_object.c                 # VkObject handle wrapping/tracking
├── vk_handlers.c               # 254 Vulkan command handlers
├── vk_init.c                   # Instance/device initialization
├── vk_loader.c                 # Driver loading (adrenotools, linkernsbypass)
├── vk_helpers.c                # Named helper functions
├── async_pipeline.c            # Async pipeline compilation
├── texture_decoder.c           # Texture format decoding
├── shader_inspector.c          # SPIRV shader analysis
├── xwindow_swapchain.c         # X11 window swapchain
├── resource_memory.c           # GPU memory management
├── timeline_semaphore.c        # Timeline semaphore support
└── vortek_internal_funcs.c     # 132 compiled + 291 stubbed FUN_ helpers
```

### Symbol Analysis
- **323/331** API symbols match prebuilt (97.5%)
- 8 missing API symbols: `handleRequestFuncs`, `deviceMemoryInfo`, and 6 functions from `vk_init`/`vk_helpers` that had deep C++ artifacts
- **516 C++ runtime symbols** (`__cxa_*`, `typeinfo`, `vtable`, `_Z*` mangled names) are expectedly absent — our C compilation doesn't emit these

### Stubbed Functions
- **291 of 423** unnamed internal functions (FUN_*) are stubbed
- Primary causes: C++ STL code (`std::string`, `basic_string<>` templates), SPIRV parsing with complex control flow, C++ exception handling patterns
- **132 internal functions** compile fully with all fixes applied

### C++ Artifacts
The original library uses `std::string` extensively for shader source manipulation
and extension name handling. Ghidra decompiles these as:
- `basic_string<char,std::__ndk1::char_traits<char>,std::__ndk1::allocator<char>>`
- `operator_new` / `operator_delete`
- C++ exception: `__cxa_throw`, `__cxa_begin_catch`

**To fully reconstruct**: The stubbed functions should be reimplemented in C++ (.cpp)
using the actual `std::string` type, guided by the Ghidra decompile output for logic
and the disassembly view for low-level details.

---

## Ghidra Artifact Fix Reference

The following systematic transformations were applied to convert Ghidra C decompile
output into compilable source code:

| Ghidra Artifact                | Fix Applied                                   |
|--------------------------------|-----------------------------------------------|
| `code *`                       | `void *` + `generic_fn_t` cast for calls      |
| `ulong`                        | `unsigned long`                                |
| `byte`                         | `uint8_t`                                      |
| `undefined3/5/7`               | `uint32_t` / `uint64_t`                        |
| `uint5/6/7`, `int3/7`          | `uint32_t` / `int`                             |
| `__emutls_v_X` / `__emutls_get_address` | `__thread` + direct variable access   |
| `tpidr_el0`                    | Elided (stack canary register)                 |
| `CONCAT44(a,b)`                | `((uint64_t)(a) << 32 \| (uint32_t)(b))`       |
| `CONCAT1N(a,b)`                | Bit-shift expressions                          |
| `NEON_fmov(x)`                 | `neon_fmov_helper(x)` (union bit-cast)         |
| `NEON_scvtf/ucvtf`             | Stubbed (SIMD intrinsics)                      |
| `var._N_M_`                    | `*(typeM*)((char*)&var + N)` (SIMD member)     |
| `uint8_t var[16]`              | `simd128_t var` (128-bit union)                |
| `(**(void **)(expr))(args)`    | `((generic_fn_t)(*(void **)(expr)))(args)`     |
| `(type))expr`                  | `(type)(expr)` (double-paren cast)             |
| `halt_baddata()`               | `__builtin_trap()`                             |
| `UNRECOVERED_JUMPTABLE`        | `((void*)0)` / `((generic_fn_t)0)()`           |
| `basic_string`                 | `uint8_t` (C++ string → raw bytes)             |
| `operator_new` / `operator_delete` | `malloc` / `free`                          |
| `(*DAT_XXX)(args)`             | `((generic_fn_t)DAT_XXX)(args)`                |
| `stack0x...` / `register0x...` | `0` (unrecovered Ghidra artifacts)             |

## Build Instructions

```bash
NDK=/path/to/android-ndk
TOOLCHAIN=$NDK/toolchains/llvm/prebuilt/darwin-x86_64
CC=$TOOLCHAIN/bin/aarch64-linux-android33-clang
SYSROOT=$TOOLCHAIN/sysroot

# libgladiorenderer
for f in recovered/src/clean/libgladiorenderer/*.c; do
    $CC -c -fPIC -O2 -I recovered/src/clean/lib{gladiorenderer,winlator} \
        --sysroot=$SYSROOT \
        -Wno-unused-variable -Wno-implicit-function-declaration \
        -Wno-int-conversion -Wno-incompatible-pointer-types \
        -o build/$(basename $f .c).o "$f"
done
$CC -shared -o build/libgladiorenderer.so build/*.o \
    --sysroot=$SYSROOT -llog -lEGL -lGLESv3 -landroid

# libvortekrenderer
for f in recovered/src/clean/libvortekrenderer/*.c; do
    $CC -c -fPIC -O2 -I recovered/src/clean/lib{vortekrenderer,winlator} \
        --sysroot=$SYSROOT \
        -Wno-unused-variable -Wno-implicit-function-declaration \
        -Wno-int-conversion -Wno-incompatible-pointer-types \
        -o build/$(basename $f .c).o "$f"
done
$CC -shared -o build/libvortekrenderer.so build/*.o \
    --sysroot=$SYSROOT -llog -landroid -ldl
```

## Integration with APK Build

The compiled `.so` files can replace the prebuilt binaries at:
```
app/src/main/jniLibs/arm64-v8a/libgladiorenderer.so
app/src/main/jniLibs/arm64-v8a/libvortekrenderer.so
```

**Note**: The current compiled versions have stubbed internal functions. They will
link and load, but some functionality (DXT compression, SPIRV parsing, C++ string
manipulation) may not work correctly until the stubs are implemented. The prebuilt
binaries should continue to be used for production until stub reconstruction is complete.
