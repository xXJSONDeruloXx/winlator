# libhook_impl — first-pass API / state identification

This file captures the first-pass manual analysis of the recovered `libhook_impl.so`
from Winlator v11.0.0. It is intended as the starting point for producing a clean,
near-buildable `clean/libhook_impl/` source tree.

## Core exported APIs

These are the meaningful exported entry points used by the 3 hook shim libraries and
runtime loader flow.

### Initialization / bootstrap
- `init_hook_param(uint64_t param_1)`
  - Stores a pointer to the global runtime hook configuration at `DAT_0014d540`.
  - This config pointer is passed in from the freshly-loaded namespaced copy of
    `libhook_impl.so` via `dlsym(..., "init_hook_param")`.
- `init_gsl(uint64_t param_1, uint64_t param_2, uint64_t param_3)`
  - Stores function pointers for:
    - `gsl_memory_alloc_pure`
    - `gsl_memory_alloc_pure_64`
    - `gsl_memory_free_pure`
  - Populates globals:
    - `DAT_0014d548`
    - `DAT_0014d550`
    - `DAT_0014d558`

### Hook entry points
- `hook_android_dlopen_ext(char *filename, uint32_t flags, uint64_t *extinfo)`
  - Main driver loading interceptor.
  - Fast path: if `filename` does **not** contain `"vulkan."`, just calls the real
    `android_dlopen_ext`.
  - Vulkan path:
    1. validates a linker namespace is present in `android_dlextinfo`
    2. creates a new namespace using configured paths from the hook config
    3. links that namespace to `libandroid.so`
    4. loads `libhook_impl.so` into that namespace
    5. calls `init_hook_param` in the namespaced copy
    6. optionally loads `libfile_redirect_hook.so`
    7. optionally loads `libgsl_alloc_hook.so`
    8. optionally probes `vkbgsl.so`, `notgsl.so`, then `libgsl.so`
    9. if GSL symbols resolve, calls `init_gsl` in the namespaced copy
    10. loads either the default driver or configured custom driver path
- `hook_android_load_sphal_library(uint64_t filename, uint32_t flags)`
  - Looks up one of the exported namespaces: `default`, `vendor`, `sphal`
  - Builds an `android_dlextinfo` with the exported namespace handle
  - Delegates to `hook_android_dlopen_ext`
- `hook_fopen(char *path, char *mode)`
  - `/proc` and `/sys` paths are passed through unchanged
  - Other paths are rewritten using the configured redirect mapping located at
    `DAT_0014d540 + 0x68`
- `hook_gsl_memory_alloc_pure_64(ulong size, uint32_t flags, uint64_t *out)`
  - Default path: forwards to original GSL allocator via stored function pointers
  - Special path: if a cached allocation descriptor exists at `DAT_0014d540 + 0x80`
    and requested size/flags match, it returns the cached allocation and stamps
    marker `0xdeadb33f`
- `hook_gsl_memory_free_pure(long handle)`
  - If marker at `handle + 0x20` is `0xdeadb33f`, frees via KGSL ioctls on
    `/dev/kgsl-3d0`
  - Otherwise forwards to the original GSL free function

## Important helper exports / bridge functions

Recovered dynamic-symbol exports that appear architecturally important:
- `android_create_namespace`
- `android_create_namespace_escape`
- `linkernsbypass_namespace_dlopen`
- `linkernsbypass_namespace_dlopen_unique`
- `linkernsbypass_link_namespace_to_default_all_libs`
- `linkernsbypass_load_status`

These appear to support bypassing the normal Android linker restrictions so the hook
stack can operate inside custom namespaces.

## Global state / inferred structs

## 1. `HookConfig` (pointer stored in `DAT_0014d540`)

This is the central runtime configuration block passed into the namespaced copy of
`libhook_impl.so` via `init_hook_param`.

Observed offsets used directly:
- `+0x00` — bitfield flags
  - `bit 0`: load custom driver instead of default driver
  - `bit 1`: enable `libfile_redirect_hook.so`
  - `bit 2`: enable `libgsl_alloc_hook.so`
- `+0x20` — string-ish object used as namespace / search path input to
  `android_create_namespace`
- `+0x38` — string-ish object used as namespace name or base path for logging / loading
- `+0x50` — string-ish object used as the final custom driver path
- `+0x68` — redirect mapping / path rewrite container used by `hook_fopen`
- `+0x80` — pointer to cached GSL allocation descriptor

### First-pass inferred C sketch
```c
typedef struct HookConfig {
    uint64_t flags;              // +0x00
    uint8_t  pad_08[0x18];
    void    *namespace_search;   // +0x20  std::string-like / container
    uint8_t  pad_28[0x10];
    void    *namespace_name;     // +0x38  std::string-like / container
    uint8_t  pad_40[0x10];
    void    *custom_driver_path; // +0x50  std::string-like / container
    uint8_t  pad_58[0x10];
    void    *redirect_map;       // +0x68  path rewrite container
    uint8_t  pad_70[0x10];
    void    *cached_gsl_alloc;   // +0x80
} HookConfig;
```

## 2. `CachedGslAlloc` (pointer stored at `HookConfig + 0x80`)

Used in `hook_gsl_memory_alloc_pure_64` and `hook_gsl_memory_free_pure`.

Observed fields:
- `+0x00 .. +0x18` copied into output allocation record (5 qwords total)
- `+0x08` overwritten with `0xdeadbeef` after successful handoff
- `+0x10` compared with requested allocation size and then zeroed
- `+0x18` compared as a mask against requested allocation flags
- `+0x20` in the returned handle is checked for marker `0xdeadb33f`

### First-pass inferred C sketch
```c
typedef struct CachedGslAlloc {
    uint64_t q0;            // copied to out[0]
    uint64_t q1;            // copied to out[1], also overwritten with 0xdeadbeef in source object
    uint64_t requested_sz;  // +0x10 compared against requested size, then zeroed
    uint64_t required_mask; // +0x18 required bits for flags
    uint64_t marker;        // copied to out[4], set to 0xdeadb33f in returned handle
} CachedGslAlloc;
```

## 3. Linker bridge function pointers / globals

In `_INIT_0`, the library resolves hidden loader symbols from `ld-android.so` and
`libdl_android.so` and stores them globally.

Recovered names:
- `android_link_namespaces_all_libs`
- `android_link_namespaces`
- `android_get_exported_namespace`
- `DAT_0014d568` = `__loader_android_create_namespace`
- `DAT_0014d564` = init success / availability flag

These globals form the Android namespace bypass bridge used by all driver interception.

## 4. GSL trampoline globals

Set by `init_gsl` and used by `hook_gsl_*`:
- `DAT_0014d548` — original `gsl_memory_alloc_pure`
- `DAT_0014d550` — original `gsl_memory_alloc_pure_64`
- `DAT_0014d558` — original `gsl_memory_free_pure`
- `DAT_0014d560` — lazily-opened `/dev/kgsl-3d0` file descriptor

## Supporting helper function roles (first pass)

Likely rename targets from `FUN_*`:
- `FUN_0011fae0` — convert internal string-like object to `char *`
- `FUN_0011fa84` — fallback path / original `android_dlopen_ext` call wrapper
- `FUN_0011fc68` — vector/string-array begin accessor
- `FUN_0011fc80` — vector/string-array end accessor
- `FUN_0011fe00` — build redirected path string from redirect map + original path
- `FUN_00120208` family — string/container accessors on redirect map object

## Verification used for this pass
- `recovered/src/libhook_impl/libhook_impl.c`
- `re/ghidra/exports/libhook_impl.json`
- `re/symbols/libhook_impl.nm.txt`
- `re/strings/libhook_impl.strings.txt`

## Open questions
- Exact concrete type of string-like fields at `HookConfig + 0x20/+0x38/+0x50`
- Exact concrete type of redirect map at `HookConfig + 0x68`
- Exact type and producer of `CachedGslAlloc`
- Exact prototypes for `linkernsbypass_*` helpers and hidden loader symbols
