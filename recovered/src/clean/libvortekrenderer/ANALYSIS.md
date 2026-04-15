# libvortekrenderer — Structural Analysis

## Architecture Overview

libvortekrenderer is a **Vulkan ICD wrapper** that intercepts and translates Vulkan API
calls from Wine/box64 to the real Android Vulkan driver. It implements Vulkan handle
wrapping, resource memory management, pipeline caching, and format/extension filtering.

**Key difference from libgladiorenderer**: This is **C++ code** that Ghidra decompiled to
C. The output contains `std::string`, `operator new/delete`, `basic_string` operations,
and C++ exception patterns. The clean source should be reconstructed as C++ (.cpp).

### Communication Model
```
Java (VortekRendererComponent) → JNI → initVulkanWrapper(libvulkan_path)
  Wine/box64 Vulkan ICD → X socket → RingBuffer → getHandleRequestFunc(opcode)
  getHandleRequestFunc() → vt_handle_vk*(context) → real vkFunction via dispatch table
```

## Key Structures

### vulkanWrapper (global, 0x820 bytes at DAT_00193ae0+)
Holds function pointers resolved via dlsym/vkGetInstanceProcAddr/vkGetDeviceProcAddr.
```
+0x000: (base)
+0x008: vkGetInstanceProcAddr (DAT_00193ae8)
+0x010: vkGetDeviceProcAddr
+0x018: vkDestroyInstance (DAT_00193af8)
...
+0x790: (last function pointer)
```

### VkObject
Handle wrapper that maps between Wine's Vulkan handles and real Android handles.
- `VkObject_create(type, realHandle)` → wrapped handle
- `VkObject_fromHandle(wrappedHandle)` → VkObject*
- `VkObject_fromId(id)` → VkObject*
- `VkObject_toHandle(obj)` → wrappedHandle
- `VkObject_free(obj)`
- 4 types of VkObjects tracked in global arrays at DAT_00194310+

### Command Dispatch
- `getHandleRequestFunc(opcode)`: opcodes 100..353 (254 entries), table at 0x192d88
- Each `vt_handle_vk*` reads args from RingBuffer, translates handles, calls real Vulkan

## Module Breakdown (793 unique functions)

| Module              | Functions | Size  | Description |
|---------------------|-----------|-------|-------------|
| vk_handlers         | 254       | 682KB | Vulkan command handlers (dispatch table) |
| internal (FUN_)     | 423       | 950KB | Unnamed helpers, C++ STL code, SPIRV parsing |
| vk_helpers          | 45        | 47KB  | Named helper functions |
| vk_init             | 20        | 50KB  | Vulkan instance/device initialization |
| texture_decoder     | 9         | 27KB  | Texture format decoding |
| vk_loader           | 12        | 12KB  | Driver loading (adrenotools, linkernsbypass) |
| vk_context          | 5         | 10KB  | VkContext lifecycle |
| vk_object           | 5         | 2KB   | VkObject handle wrapping |
| jni_vortek          | 4         | 2KB   | JNI entry points |
| xwindow_swapchain   | 4         | 7KB   | X11 window swapchain |
| shader_inspector    | 3         | 28KB  | SPIRV shader analysis |
| resource_memory     | 2         | 10KB  | GPU memory management |
| async_pipeline      | 1         | 49KB  | Async pipeline compilation |
| timeline_semaphore  | 1         | 1KB   | Timeline semaphore support |

## C++ Patterns (Ghidra C decompile of C++ code)
- `std::string` → `basic_string` with `operator_new`, `operator_delete`, `append`, `assign`
- C++ exception: `__cxa_throw`, `__cxa_begin_catch`, `__cxa_end_catch`
- vtable calls: `(**(code **)(obj + offset))(...)` 
- 920 `basic_string` references, 244 `operator_delete`, 66 `operator_new`

## Ghidra Artifacts
- 87 CONCAT44 macros
- 278 tpidr_el0 (stack canary) 
- 3168 `ulong`, 878 `byte`, 351 `code` type artifacts
- 362 DAT_ global references
- 3 UNRECOVERED_JUMPTABLE

## Dependencies
- libwinlator.so: ArrayList, ArrayDeque, IntArray, RingBuffer, ashmemCreateRegion
- Android: log, AHardwareBuffer, dlopen/dlsym
- libc: pthread, malloc, memcpy, std C++ runtime
- adrenotools: custom Vulkan driver loading
- libhook_impl.so: linkernsbypass functions
