# libhook_impl — functional-equivalence validation status (first pass)

This document records the current validation state of the `clean/libhook_impl/` reconstruction
against the recovered binary `recovered/lib/arm64-v8a/libhook_impl.so`.

## Scope of this validation pass

This is **not** a claim that the clean tree is already functionally equivalent.
Instead, this pass validates that:

1. the **meaningful exported API surface** from the original binary is fully represented in the
   clean tree,
2. the exports are assigned to the correct conceptual modules,
3. the major runtime behaviors of the original binary have been isolated and documented,
4. the clean tree compiles as a near-buildable scaffold without unresolved type-layout chaos.

## Original binary: meaningful exported symbols

Filtered from:
```bash
nm -D --demangle recovered/lib/arm64-v8a/libhook_impl.so
```

Meaningful non-runtime exports identified:

- `android_create_namespace`
- `android_create_namespace_escape`
- `hook_android_dlopen_ext`
- `hook_android_load_sphal_library`
- `hook_fopen`
- `hook_gsl_memory_alloc_pure_64`
- `hook_gsl_memory_free_pure`
- `init_gsl`
- `init_hook_param`
- `linkernsbypass_link_namespace_to_default_all_libs`
- `linkernsbypass_load_status`
- `linkernsbypass_namespace_dlopen`
- `linkernsbypass_namespace_dlopen_unique`

## Clean tree coverage

The clean tree currently represents **all 13** of those meaningful exports.

### Module mapping

| Export | Clean module |
|---|---|
| `init_hook_param` | `hook_impl_core.[ch]` |
| `init_gsl` | `hook_impl_core.[ch]` |
| `android_create_namespace` | `loader_bridge.[ch]` |
| `android_create_namespace_escape` | `loader_bridge.[ch]` |
| `linkernsbypass_link_namespace_to_default_all_libs` | `loader_bridge.[ch]` |
| `linkernsbypass_load_status` | `loader_bridge.[ch]` |
| `linkernsbypass_namespace_dlopen` | `loader_bridge.[ch]` |
| `linkernsbypass_namespace_dlopen_unique` | `loader_bridge.[ch]` |
| `hook_android_dlopen_ext` | `driver_hook.[ch]` |
| `hook_android_load_sphal_library` | `driver_hook.[ch]` |
| `hook_fopen` | `file_redirect.[ch]` |
| `hook_gsl_memory_alloc_pure_64` | `gsl_hook.[ch]` |
| `hook_gsl_memory_free_pure` | `gsl_hook.[ch]` |

## Behavior validation status by module

### 1. `hook_impl_core`
Status: **mostly understood**

Validated behaviors from the raw decompile:
- `init_hook_param` stores the central runtime config pointer (`DAT_0014d540`)
- `init_gsl` stores the original GSL trampoline function pointers

Current clean-tree status:
- bodies implemented as first-pass named global replacements
- behavior is simple and well understood

### 2. `loader_bridge`
Status: **API and purpose understood, exact bodies not yet transplanted**

Validated behaviors from raw decompile:
- loader bootstrap resolves hidden linker symbols from `ld-android.so` / `libdl_android.so`
- namespace bridge helpers wrap Android namespace loading via `android_dlopen_ext`
- `linkernsbypass_namespace_dlopen(_unique)` behavior and inputs are documented

Current clean-tree status:
- correct exports and file placement established
- placeholders remain for exact logic

### 3. `driver_hook`
Status: **core control flow understood, exact bodies not yet transplanted**

Validated behaviors from raw decompile:
- `hook_android_dlopen_ext`:
  - passes through non-Vulkan loads
  - creates namespace for Vulkan loads
  - loads namespaced `libhook_impl.so`
  - optionally injects file redirect + GSL hook libs
  - chooses default vs custom driver path
  - falls back on failure
- `hook_android_load_sphal_library`:
  - iterates `default` / `vendor` / `sphal`
  - delegates into `hook_android_dlopen_ext`

Current clean-tree status:
- correct exports and signatures represented
- placeholder bodies remain

### 4. `file_redirect`
Status: **first-pass exact / high confidence**

Validated behaviors from raw decompile:
- `/proc` and `/sys` are passed through unchanged
- other paths go through `build_redirected_path`
- helper cluster for redirect-map / string-like access is identified

Current clean-tree status:
- exact small helpers `string_array_begin` / `string_array_end` carry their recovered bodies
- `string_like_to_cstr` / `string_like_length` have been tightened to match libc++/NDK
  std::string SSO patterns observed in the raw decompile:
  - low bit of the first byte indicates heap vs inline storage
  - heap case: length in qword at +8, buffer pointer at +0x10
  - inline case: characters start at +1 and inline length encoded in first byte >> 1
  - added defensive fallbacks for NULL/absurd lengths
- `build_redirected_path` and `hook_fopen` implemented with a safe-first heuristic:
  - passthrough for `/proc` and `/sys`
  - passthrough when `g_hook_config` or `redirect_map` is NULL
  - when present, `build_redirected_path` interprets `redirect_map` as either a
    string-like prefix or a C string and constructs `prefix + original_path`
- This achieves the common runtime behavior needed for path rewriting while avoiding unsafe
  assumptions. It is conservative; exact redirect-map semantics remain to be refined.

### 5. `gsl_hook`
Status: **high confidence**

Validated behaviors from raw decompile:
- allocation path either forwards to original GSL alloc or returns cached descriptor
- free path either frees via KGSL ioctls or forwards to original free
- marker values:
  - `0xdeadb33f`
  - `0xdeadbeef`
- KGSL ioctls identified and named in `internals.h`

Current clean-tree status:
- exports and constants/types are correct
- exact bodies still need transplant

### 6. `quirks`
Status: **understood but low priority**

Validated behaviors from raw decompile:
- `_INIT_1` reads hardware capability + `ro.arch`
- toggles a device quirk flag, with special-case behavior around `exynos9810`

Current clean-tree status:
- placeholder only

## Type / struct validation status

### Confirmed enough for near-compile
The following first-pass types/constants are in place and sufficient for the scaffold:
- `HookConfig`
- `CachedGslAlloc`
- `GslAllocRecord`
- loader bridge function pointer typedefs
- `gsl_alloc32_fn`, `gsl_alloc64_fn`, `gsl_free_fn`
- loader / KGSL constants in `internals.h`

### Still uncertain
These remain approximate and are the main blockers to full functional equivalence:
- concrete layout of the string-like objects at `HookConfig + 0x20/+0x38/+0x50`
- concrete type of the redirect-map object at `HookConfig + 0x68`
- exact structure of the cached GSL allocation record beyond the fields already inferred
- exact prototypes for some loader-bridge internals and helper functions in the `FUN_00120208...`
  cluster

## Build validation

Verified:
```bash
cmake -S recovered/src/clean/libhook_impl -B recovered/src/clean/libhook_impl/build-test
cmake --build recovered/src/clean/libhook_impl/build-test
```

Result:
- the clean tree **configures and builds** as an OBJECT target scaffold
- this proves the source tree structure and first-pass headers/types are internally coherent
- this does **not** yet prove runtime equivalence, because several bodies are placeholders

## Conclusion

### What is validated now
- The clean tree covers the full meaningful export surface of the original binary.
- The exports are assigned to the correct conceptual modules.
- The major control flow of the original binary has been isolated and documented.
- The type/constant layer is sufficient for a near-compiling scaffold.

### What is NOT yet validated
- The clean tree is **not yet functionally equivalent** at runtime because the exact decompiled
  bodies have not been transplanted into all modules.
- Therefore the Ralph checklist item
  - `libhook_impl`: validate functional equivalence against recovered binary behavior/signatures/exports
  remains **not complete**.

### Immediate next step
To finish functional-equivalence validation for `libhook_impl`, the next pass should:
1. transplant exact recovered bodies into the clean modules,
2. re-run build checks,
3. compare exports / signatures again,
4. inspect the resulting object code or runtime behavior against the original recovered binary.
