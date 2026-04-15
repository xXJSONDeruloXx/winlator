# clean/libhook_impl

This directory is the **human-organized** reconstruction target for `libhook_impl.so`.

It intentionally starts as a **structured, non-compiling source tree** derived from:
- `ANALYSIS.md`
- `RENAMES.md`
- `LOGIC.md`
- `../../libhook_impl/libhook_impl.c` (raw Ghidra decompile)

## Goal

Turn the monolithic recovered decompile into module-oriented source that can eventually be:
1. understood by humans,
2. cleaned up,
3. typed correctly,
4. compiled and validated against the original binary.

## Planned module split

- `hook_impl_core.[ch]`
  - global runtime state
  - `init_hook_param`
  - `init_gsl`
- `loader_bridge.[ch]`
  - `_INIT_0` / loader symbol bootstrap
  - namespace bridge helpers
  - `android_create_namespace*`
  - `linkernsbypass_*`
- `driver_hook.[ch]`
  - `hook_android_dlopen_ext`
  - `hook_android_load_sphal_library`
  - fallback path
- `file_redirect.[ch]`
  - `hook_fopen`
  - redirected path construction helpers
- `gsl_hook.[ch]`
  - `hook_gsl_memory_alloc_pure_64`
  - `hook_gsl_memory_free_pure`
- `quirks.[ch]`
  - `_INIT_1` / device quirk detection

## Current status

This tree exists to establish file/module boundaries.

It is **not compile-ready yet**. The next iteration should focus on:
- introducing stable typedefs for `HookConfig`, `CachedGslAlloc`, loader bridge function pointers,
- replacing raw `DAT_...` globals with named externs,
- moving exact decompiled logic into the correct module files.
