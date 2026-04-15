# Phase 2: Native Library Source Reconstruction

## Status: 5 of 7 Libraries Compiled from Source

| Library | Size (prebuilt) | Size (compiled) | Functions | Status |
|---------|-----------------|-----------------|-----------|--------|
| `libmain_hook` | 4.2 KB | 3.8 KB | 2 | ✅ Complete |
| `libfile_redirect_hook` | 3.9 KB | 3.6 KB | 1 | ✅ Complete |
| `libgsl_alloc_hook` | 4.4 KB | 3.9 KB | 3 | ✅ Complete |
| `libwinlator` | 49.6 KB | 39.7 KB | 138 | ✅ Complete |
| `libhook_impl` | 310.6 KB | 17.1 KB | 14 Winlator + C++ runtime | ✅ Complete |
| `libgladiorenderer` | 276 KB | — | 1,313 | ❌ Not started |
| `libvortekrenderer` | 598 KB | — | 1,474 | ❌ Not started |

## Completed Libraries

### libmain_hook (loader shim)
- **Source**: `recovered/src/clean/libmain_hook/libmain_hook.c` (31 lines)
- **Build**: `native/hook_shims/CMakeLists.txt`
- **Function**: Overrides `android_dlopen_ext()` and `android_load_sphal_library()` to intercept Vulkan driver loading. Entry point of the entire hook chain.

### libfile_redirect_hook (fopen hook)
- **Source**: `recovered/src/clean/libfile_redirect_hook/libfile_redirect_hook.c` (16 lines)
- **Build**: `native/hook_shims/CMakeLists.txt`
- **Function**: Overrides `fopen()` to redirect `/proc` and `/sys` reads in the Vulkan driver namespace.

### libgsl_alloc_hook (Adreno GSL hook)
- **Source**: `recovered/src/clean/libgsl_alloc_hook/libgsl_alloc_hook.c` (30 lines)
- **Build**: `native/hook_shims/CMakeLists.txt`
- **Function**: Overrides Qualcomm Adreno GPU's `gsl_memory_alloc_pure{,_64}` and `gsl_memory_free_pure` to work around driver incompatibilities.

### libwinlator (JNI glue + data structures)
- **Source**: `recovered/src/clean/libwinlator/` (6 .c + 2 .h files, ~1,900 lines)
- **Build**: `native/winlator/CMakeLists.txt`
- **Function**: 53 JNI bindings for Java↔native bridge (GPU, SHM, XConnector, XServer, Wine) + 85 collection data structure implementations (ArrayBuffer, ArrayList, ArrayMap, ArrayDeque, IntArray, SparseArray, SparseIntArray, RingBuffer) used by the renderer libraries.
- **Symbol match**: 138/138 exported symbols identical to prebuilt.

### libhook_impl (driver hooking core)
- **Source**: `recovered/src/clean/libhook_impl/` (6 .c + 7 .h files, ~1,030 lines)
- **Build**: `native/hook_impl/CMakeLists.txt`
- **Function**: Core hooking logic — intercepts `android_dlopen_ext` to redirect Vulkan driver loading, creates linker namespaces, patches ELF SONAMEs, manages fopen redirects and GSL memory hooks.
- **Symbol match**: 14/14 Winlator-specific symbols. Prebuilt also exports ~150 C++ runtime symbols from static libc++ (not needed in our pure-C rebuild).
- **Size difference**: 311 KB → 17 KB (prebuilt includes static libc++ linkage).

## Remaining Libraries

### libgladiorenderer (OpenGL ARB renderer)
- **Raw Ghidra output**: `recovered/src/libgladiorenderer/libgladiorenderer.c` (27,080 lines)
- **Ghidra exports**: `re/ghidra/exports/libgladiorenderer.json` (1,313 functions)
- **Clean source**: Not yet started
- **Architecture**: ARB assembly program-based OpenGL renderer (ARB_vertex_program / ARB_fragment_program). Implements texture management, framebuffer objects, attribute stacks, GL state tracking. Imports all `gl*` functions from the system OpenGL ES library plus the custom collection types from libwinlator.
- **Key types**: `ARBProgram`, `AttribStack`, `GLBuffer`, `GLFormats`, `GLFramebuffer`

### libvortekrenderer (Vulkan renderer)
- **Raw Ghidra output**: `recovered/src/libvortekrenderer/libvortekrenderer.c` (76,317 lines)
- **Ghidra exports**: `re/ghidra/exports/libvortekrenderer.json` (1,474 functions)
- **Clean source**: Not yet started
- **Architecture**: Custom Vulkan translation layer implementing X11 DRI3/Present-style swapchain on Vulkan, with async pipeline creation, shader inspection/patching, and timeline semaphores. Uses `adrenotools` for custom Adreno driver loading. Has 4 JNI entry points.
- **Key types**: `VkObject`, `XWindowSwapchain`, `AsyncPipelineCreator`, `ResourceMemory`, `ShaderInspector`, `TextureDecoder`, `TimelineSemaphore`

## Build Instructions

All native libraries are built using the Android NDK cross-compilation toolchain:

```bash
NDK_HOME=~/Library/Android/sdk/ndk/27.2.12479018

# Build hook shims (3 libs)
mkdir -p native/hook_shims/build && cd native/hook_shims/build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$NDK_HOME/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-26 -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Build libwinlator
mkdir -p native/winlator/build && cd native/winlator/build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$NDK_HOME/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-26 -DCMAKE_BUILD_TYPE=Release
cmake --build .

# Build libhook_impl
mkdir -p native/hook_impl/build && cd native/hook_impl/build
cmake .. -DCMAKE_TOOLCHAIN_FILE=$NDK_HOME/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-26 -DANDROID_STL=c++_static \
  -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## Validation Method

For each compiled library:
1. Build with NDK cross-compilation (arm64-v8a, API 26)
2. Compare exported symbol table (`llvm-nm -D`) against prebuilt
3. Verify all required symbols present with correct types
4. Strip and swap into `app/src/main/jniLibs/arm64-v8a/`
5. Rebuild APK with `./gradlew assembleDebug`
6. Verify BUILD SUCCESSFUL
