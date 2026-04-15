# libgladiorenderer — Structural Analysis

## Architecture Overview

libgladiorenderer is a **GLX extension renderer** that translates OpenGL 1.x–4.x desktop GL
commands received over a ring buffer into OpenGL ES 3.2 calls on Android. It implements
the Wine GLX protocol for Winlator's X server.

### Communication Model
```
Java (GLXExtension) → JNI → createGLContext() → spawns render thread
  Wine process → X protocol → GLX extension commands → RingBuffer → readCommandBuffer()
  readCommandBuffer() → getHandleRequestFunc(opcode) → gd_handle_gl*(cmd_buf)
  gd_handle_gl*() → actual glES3 calls + helper modules
```

## Key Structures

### GLContext (0xB8 = 184 bytes)
Created in `createGLContext()`. One per X client GL context.
```
+0x00: (unknown, possibly vtable/type)
+0x08: int  fd (client socket fd, from param_3)
+0x10: long clientRingBuffer (RingBuffer for client→server)
+0x18: long serverRingBuffer (RingBuffer for server→client)
+0x20: JNIEnv reference (from param_1)
+0x30: uint64_t (Java object ref from GetObjectClass)
+0x58: pthread_t renderThread
+0x60: uint8_t running flag
+0x68: ArrayBuffer cmdBuf (embedded, inline)
+0x78: void* vertexData (realloc'd buffer for vertex arrays)
+0x98: uint8_t* threadPool (thread pool control struct, 200 bytes)
```

### GLXContext (0x928 = 2344 bytes)
Created in `createGLXContext()`. The actual OpenGL state machine.
Thread-local via `__emutls_v_currentRenderer`.
```
+0x000: EGLContext eglContext
+0x008: uint32_t glxVersion
+0x074: GLVertexArrayObject[...] (starts at uint64_t offset 0x74 = byte 0x3A0)
+0x560: SparseArray* programs (ARBProgram storage)
+0x5B8: SparseArray* arbPrograms (by target)
+0x5E8: bool sharedContext
...+0x918: (max field seen)
```

Large struct with inline storage for:
- Vertex array objects and attribute state
- Bound buffers, textures, framebuffers per target
- Shader/program state
- ARB program state
- Sampler objects
- Query objects
- Attrib stack
- GL state machine (enable/disable flags, blend, depth, stencil, etc.)

### ThreadPool Worker (0xC8 = 200 bytes)
```
+0x00: uint8_t workerCount (=4)
+0x02: uint8_t flag
+0x04: pthread_mutex_t mutex1 (size 0x28 on aarch64)
+0x2C: pthread_cond_t cond1 (size 0x30 on aarch64)
+0x5C: pthread_mutex_t mutex2
+0x84: pthread_cond_t cond2
```

## Thread-Local Storage
- `__emutls_v_currentRenderer` → `GLXContext*` — the active renderer for the current thread
- Accessed via `__emutls_get_address()` (GCC/Clang emulated TLS)

## Global Variables
- `glx_context_mutex` — pthread_mutex protecting context creation/destruction (73 refs)
- `globalEGLContext` — shared EGL context for context sharing
- ~55 DAT_ globals — mostly string constants in .rodata (log tags, shader source fragments)

## Command Dispatch
- `readCommandBuffer()` reads from the server RingBuffer
- Each command: 4 ints header (mode, vertexCount, vertexDataSize, extraDataSize) + opcode shorts
- `getHandleRequestFunc(opcode)` looks up handler in table at rodata+0x143e58
  - Opcodes 100..529 (range 0x1AE = 430 entries)
  - Returns function pointer to `gd_handle_gl*`

## Module Breakdown

| Module | Functions | Description |
|--------|-----------|-------------|
| gd_handle_gl* | 430 | Command handlers — thin wrappers reading args from ArrayBuffer and calling GL/helpers |
| GLRenderer_* | 32 | Renderer lifecycle, vertex submission, draw calls, state management |
| ShaderConverter_* | 15 | ARB assembly → GLSL converter, shader/program management |
| ARBProgram_* | 9 | ARB program objects (bind, create, delete, env/local params) |
| GLFramebuffer_* | 7 | FBO management |
| GLQuery_* | 7 | Query objects |
| GLBuffer_* | 5 | Buffer objects |
| GLTexture_* | 5 | Texture binding/state |
| GLVertexArrayObject_* | 3 | VAO state |
| ShaderMaterial_* | 3 | Shader uniform updates |
| AttribStack_* | 2 | glPushAttrib/glPopAttrib emulation |
| stb_compress_* | 3 | DXT/BC texture compression (stb_dxt embedded) |
| GLFormats_* | 1 | Internal format queries |
| JNI entry | 4 | create/destroyGLContext, create/destroyGLXContext |
| Internal (FUN_) | 46 | Thread workers, helpers, shader parsing internals |
| Misc named | ~15 | readCommandBuffer, readVertexArrayElement, etc. |

## Dependencies
- libwinlator.so: ArrayBuffer, ArrayList, ArrayDeque, ArrayMap, SparseArray, RingBuffer, IntArray, ashmemCreateRegion
- Android: log, EGL, GLES3/gl32.h, pthread, AHardwareBuffer (not used directly)
- libc: malloc, calloc, realloc, free, memcpy, memset, sendmsg, close, etc.
