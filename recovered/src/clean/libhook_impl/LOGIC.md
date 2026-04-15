# libhook_impl — isolated control-flow / logic map

This document isolates the major runtime logic in `libhook_impl.so` into coherent modules.
It is the bridge between the raw decompilation (`recovered/src/libhook_impl/libhook_impl.c`) and
future clean source reconstruction in `recovered/src/clean/libhook_impl/`.

## Module 1 — loader bridge bootstrap

### Entry points
- `_INIT_0` → proposed rename: `init_loader_bridge_symbols`
- `_INIT_1` → proposed rename: `init_cpu_quirk_flags`

### What `_INIT_0` does
`_INIT_0` runs on library load and prepares access to hidden Android loader APIs:

1. Reads SDK level via `get_android_sdk_int` (`FUN_00120eb4`)
2. If SDK is high enough (logic checks `> 26`, effectively Android 27+ path), it:
   - finds a page-aligned region around `dlopen`
   - scans instructions to find a branch target into the loader via
     `find_loader_entry_via_dlopen_branch_scan` (`FUN_00120f84`)
   - uses that internal loader entry to open:
     - `ld-android.so`
     - `libdl_android.so`
3. Resolves and stores hidden loader symbols:
   - `__loader_android_link_namespaces_all_libs`
   - `__loader_android_link_namespaces`
   - `__loader_android_create_namespace`
   - `__loader_android_get_exported_namespace`
4. Sets `DAT_0014d564 = 1` on success

### Related helpers
- `FUN_00120eb4` → `get_android_sdk_int`
- `FUN_00120f84` → `find_loader_entry_via_dlopen_branch_scan`
- `FUN_00121014` → `page_align_down`
- `FUN_00121054` → `is_unconditional_branch_insn`

### Functional purpose
This module gives Winlator a portable way to access Android linker namespace APIs even though
those APIs are not part of the normal public NDK surface used by app code.

---

## Module 2 — namespace creation and namespace bypass helpers

### Bridge functions
- `android_create_namespace(...)`
  - thin wrapper over hidden loader function pointer `DAT_0014d568`
- `android_create_namespace_escape(...)`
  - same wrapper, but passes `dlopen` in the last register/argument slot to change
    loader call context
- `linkernsbypass_link_namespace_to_default_all_libs(namespace)`
- `linkernsbypass_load_status()`
- `linkernsbypass_namespace_dlopen(path, flags, namespace)`
- `linkernsbypass_namespace_dlopen_unique(path, soname, flags, namespace)`

### What these do
#### `linkernsbypass_load_status`
Returns whether `_INIT_0` successfully resolved the hidden loader bridge.

#### `linkernsbypass_link_namespace_to_default_all_libs`
1. Lazily creates a copy namespace named `default_copy` via `android_create_namespace_escape`
2. Calls `android_link_namespaces_all_libs(namespace, default_copy)`
3. Returns success/failure as a boolean-ish bit result

This function appears designed to make a custom namespace inherit symbol visibility from a
copy of the default namespace.

#### `linkernsbypass_namespace_dlopen`
Builds an `android_dlextinfo` with namespace flag `0x200` and calls:
```c
android_dlopen_ext(path, flags, &extinfo)
```
inside the requested namespace.

#### `linkernsbypass_namespace_dlopen_unique`
This is the more advanced path. It appears to:
1. open or create a unique file descriptor for a library image
2. patch its SONAME (`elf_soname_patch(...)`)
3. format `/proc/self/fd/%d`
4. call `android_dlopen_ext` with namespace + fd-based extinfo

### Functional purpose
These helpers are how Winlator loads extra hook libraries and possibly custom drivers into a
custom linker namespace without colliding with already-loaded copies.

---

## Module 3 — runtime hook configuration (`HookConfig`)

A runtime configuration pointer is set by:
- `init_hook_param(uint64_t ptr)`

It is stored globally at:
- `DAT_0014d540`

### Inferred `HookConfig` fields in use
```c
typedef struct HookConfig {
    uint64_t flags;              // +0x00
    // bit 0 = load custom driver instead of default
    // bit 1 = enable file redirect hook
    // bit 2 = enable GSL alloc hook

    void *namespace_search;      // +0x20  string-like object
    void *namespace_name;        // +0x38  string-like object
    void *custom_driver_path;    // +0x50  string-like object
    void *redirect_map;          // +0x68  redirect mapping container
    void *cached_gsl_alloc;      // +0x80  cached allocation descriptor
} HookConfig;
```

### String-like accessors used on this config
- `string_like_to_cstr` (`FUN_0011fae0`)
  - converts objects at `+0x20`, `+0x38`, `+0x50` into `char *`
- redirect-map helper cluster rooted in:
  - `build_redirected_path` (`FUN_0011fe00`)
  - and helpers `FUN_00120208` through `FUN_00120684`

---

## Module 4 — Vulkan driver interception (`hook_android_dlopen_ext`)

This is the core of the whole library.

### High-level behavior
#### Case A: non-Vulkan library
If `filename` does **not** contain `"vulkan."`:
- simply call the real `android_dlopen_ext(filename, flags, extinfo)`

#### Case B: Vulkan driver library
If `filename` **does** contain `"vulkan."`:

1. Log the incoming filename
2. Validate that a namespace is present in the supplied `android_dlextinfo`
3. Pull namespace configuration strings from `HookConfig`:
   - `namespace_name` (`+0x38`)
   - `namespace_search` (`+0x20`)
4. Create a new namespace using `android_create_namespace`
5. Link that namespace to `libandroid.so`
6. Load a namespaced copy of `libhook_impl.so`
7. Resolve and call `init_hook_param` inside the namespaced copy
8. If flag bit 1 set:
   - load `libfile_redirect_hook.so` into the namespace
9. If flag bit 2 set:
   - load `libgsl_alloc_hook.so`
   - probe GSL providers in order:
     - `vkbgsl.so`
     - `notgsl.so`
     - `libgsl.so`
   - if symbols resolve, call `init_gsl` in the namespaced copy
10. If flag bit 0 is **not** set:
   - load the default Vulkan driver (`filename`)
11. Else:
   - get `custom_driver_path` (`+0x50`)
   - load custom driver path instead
12. If custom load fails:
   - log `dlerror()`
   - fall back using `fallback_to_original_android_dlopen_ext`

### Related helper
- `FUN_0011fa84` → `fallback_to_original_android_dlopen_ext`
  - logs `"falling back!"`
  - reissues the original call triple `(filename, flags, extinfo)`

### Functional purpose
This module is the decisive mechanism that makes Winlator use either the system Vulkan driver
or a user-specified custom driver stack while still applying additional helper hooks in the
same namespace.

---

## Module 5 — SPHAL namespace interception (`hook_android_load_sphal_library`)

### High-level behavior
1. Logs the incoming filename
2. Builds a static namespace candidate list:
   - `default`
   - `vendor`
   - `sphal`
3. Iterates that list and calls `android_get_exported_namespace(name)`
4. On first non-null namespace:
   - constructs an `android_dlextinfo` with namespace flag `0x200`
   - calls `hook_android_dlopen_ext(filename, flags, &extinfo)`

### Supporting helpers
- `string_array_begin` (`FUN_0011fc68`)
- `string_array_end` (`FUN_0011fc80`)

### Functional purpose
This makes the driver interception logic work not only for ordinary `android_dlopen_ext`
requests, but also for vendor/SPHAL library loads done through Android’s HAL namespace model.

---

## Module 6 — file redirect hook (`hook_fopen`)

### High-level behavior
1. If path starts with `/proc` or `/sys`:
   - log `passthrough`
   - call real `fopen(path, mode)`
2. Otherwise:
   - call `build_redirected_path(HookConfig.redirect_map, path)`
   - log `original -> redirected`
   - `fopen(redirected_path, mode)`

### Supporting helper cluster
- `build_redirected_path` (`FUN_0011fe00`)
- `redirect_map_get_path_data` / `redirect_map_string_length` / storage selection helpers
  in the `FUN_00120208`…`FUN_00120684` range

### Functional purpose
This lets the hook stack substitute user-controlled or synthesized files for ordinary path
accesses while intentionally leaving `/proc` and `/sys` alone.

---

## Module 7 — GSL allocation hook (`hook_gsl_memory_alloc_pure_64` / `hook_gsl_memory_free_pure`)

### Setup
- `init_gsl(alloc32, alloc64, free)` stores original GSL function pointers in:
  - `DAT_0014d548`
  - `DAT_0014d550`
  - `DAT_0014d558`

### `hook_gsl_memory_alloc_pure_64`
#### Fast/default path
If there is no cached allocation descriptor at `HookConfig + 0x80`, or requested size/flags do
not match the descriptor:
- forward to original allocator (`alloc64` if present, else `alloc32`)

#### Cached override path
If cached allocation descriptor exists and size/flags match:
- copy 5 qwords from cached descriptor into caller output
- stamp marker `0xdeadb33f` in the returned object
- zero `cached->requested_size`
- stamp `0xdeadbeef` into `cached->q1`
- return success (`0`)

### `hook_gsl_memory_free_pure`
If `handle + 0x20 == 0xdeadb33f`:
1. lazily open `/dev/kgsl-3d0`
2. issue `IOCTL_KGSL_GPUMEM_GET_INFO`
3. issue `IOCTL_KGSL_GPUOBJ_FREE`
4. return success (`0`)

Else:
- forward to original `gsl_memory_free_pure`

### Functional purpose
This module allows Winlator to substitute and later manually free a GPU allocation using
KGSL ioctls, likely to work around vendor driver behavior when loading custom Vulkan stacks.

---

## Module 8 — hardware quirk detection (`_INIT_1`)

`_INIT_1` reads `AT_HWCAP` via `getauxval(AT_HWCAP)` and also checks `ro.arch`.
If a certain capability bit is set, and the platform is **not** `exynos9810`, it sets:
- `DAT_0014e870 = true`

This appears to be a device-specific quirk flag used elsewhere in the binary.
It is currently peripheral to the namespace / fopen / GSL hook path.

---

## Suggested clean-source module split

When creating `recovered/src/clean/libhook_impl/`, the library should likely be split into:

- `hook_impl_core.c`
  - global state
  - `init_hook_param`
  - `init_gsl`
- `loader_bridge.c`
  - `_INIT_0`
  - `android_create_namespace*`
  - `linkernsbypass_*`
- `driver_hook.c`
  - `hook_android_dlopen_ext`
  - `fallback_to_original_android_dlopen_ext`
  - `hook_android_load_sphal_library`
- `file_redirect.c`
  - `hook_fopen`
  - redirect-map string/path helpers
- `gsl_hook.c`
  - `hook_gsl_memory_alloc_pure_64`
  - `hook_gsl_memory_free_pure`
- `quirks.c`
  - `_INIT_1`

## Verification used for this pass
- `recovered/src/libhook_impl/libhook_impl.c`
- `recovered/src/clean/libhook_impl/ANALYSIS.md`
- `recovered/src/clean/libhook_impl/RENAMES.md`
- `re/ghidra/exports/libhook_impl.json`
- `re/symbols/libhook_impl.nm.txt`
- `re/strings/libhook_impl.strings.txt`
