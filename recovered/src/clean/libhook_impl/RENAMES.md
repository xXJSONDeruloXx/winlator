# libhook_impl — first-pass helper rename map

This maps major `FUN_*` helpers in `recovered/src/libhook_impl/libhook_impl.c` to
human-meaningful names based on direct control-flow inspection.

## High-confidence renames

| Current name | Proposed name | Why |
|---|---|---|
| `FUN_0011fa84` | `fallback_to_original_android_dlopen_ext` | Logs `"falling back!"` then calls the real `android_dlopen_ext` with the original filename/flags/extinfo triple. |
| `FUN_0011fc68` | `string_array_begin` | In `hook_android_load_sphal_library`, returns the first element of a `{char** data, size_t count}`-like pair. |
| `FUN_0011fc80` | `string_array_end` | Returns `begin + count * 8`; used as the end iterator in the `default/vendor/sphal` namespace scan. |
| `FUN_0011fe00` | `build_redirected_path` | Builds a new `std::string` from the redirect map at `HookConfig + 0x68` plus the original path, then appends the original suffix. |
| `FUN_00120478` | `cstring_length` | Thin wrapper around `strlen`. |
| `FUN_00120eb4` | `get_android_sdk_int` | Reads `ro.build.version.sdk` via `__system_property_get`, parses with `atoi`, returns `-1` on failure. |
| `FUN_00121014` | `page_align_down` | Returns `addr & ~(pagesize-1)`. |
| `FUN_00121054` | `is_unconditional_branch_insn` | Tests top opcode bits for AArch64 unconditional `B` instruction; used while scanning around `dlopen`. |

## Medium-confidence renames

| Current name | Proposed name | Why |
|---|---|---|
| `FUN_0011fae0` | `string_like_to_cstr` | Used on `HookConfig + 0x20/+0x38/+0x50`; returns `char*` used as namespace names / paths for logging and loading. |
| `FUN_00120f84` | `find_loader_entry_via_dlopen_branch_scan` | Called in `_INIT_0` after SDK check; page-aligns `dlopen`, scans instructions until it finds an unconditional branch, then returns its target. This appears to recover an internal loader trampoline used to open `ld-android.so` / `libdl_android.so`. |

## Redirect-map / string-container helper cluster

These helpers appear to implement accessors over the redirect-map string-like object at
`HookConfig + 0x68`. The decompiler flattened a lot of trivial wrappers, so the names below
reflect behavior, not exact original symbols.

| Current name | Proposed name | Why |
|---|---|---|
| `FUN_00120208` | `redirect_map_get_path_data` | Used by `FUN_0011fae0`; final result is treated as `char*`. |
| `FUN_00120230` | `identity_u64_20230` | Pure identity wrapper in the access chain. |
| `FUN_00120244` | `redirect_map_select_storage_ptr` | Chooses one of two storage paths based on the low-bit / short-string-like flag. |
| `FUN_00120298` | `redirect_map_uses_heap_storage` | Reads low bit and interprets it as storage-kind flag. |
| `FUN_001202cc` | `redirect_map_get_heap_ptr` | Returns pointer field at `+0x10` when heap-backed. |
| `FUN_001202f4` | `redirect_map_get_inline_ptr` | Returns inline buffer pointer (`obj + 1`) when not heap-backed. |
| `FUN_00120320` | `identity_u64_20320` | Pure wrapper in pointer access chain. |
| `FUN_00120344` | `identity_u64_20344` | Pure identity wrapper. |
| `FUN_00120358` | `identity_u64_20358` | Pure wrapper over pointer adjustment result. |
| `FUN_0012037c` | `identity_u64_2037c` | Pure identity wrapper. |
| `FUN_00120390` | `redirect_map_prepare_string_access` | Start of string-access helper chain before constructing redirected path. |
| `FUN_001203b4` | `redirected_path_string_init_from_map` | Constructs / initializes temporary string state from redirect-map data. |
| `FUN_00120424` | `redirect_map_string_length` | Chooses heap vs inline storage length path. |

## Bootstrap / loader-resolution helpers

| Current name | Proposed name | Why |
|---|---|---|
| `_INIT_0` | `init_loader_bridge_symbols` | Resolves hidden loader symbols from `ld-android.so` and `libdl_android.so`, sets init success flag. |
| `_INIT_1` | `init_cpu_quirk_flags` | Reads `AT_HWCAP` and `ro.arch`, sets `DAT_0014e870` based on a hardware quirk check (notably `exynos9810`). |

## Suggested next renames to apply in clean source

These are the most useful names to actually use when creating `clean/libhook_impl/`:

- `FUN_0011fa84` → `fallback_to_original_android_dlopen_ext`
- `FUN_0011fae0` → `string_like_to_cstr`
- `FUN_0011fc68` → `string_array_begin`
- `FUN_0011fc80` → `string_array_end`
- `FUN_0011fe00` → `build_redirected_path`
- `_INIT_0` → `init_loader_bridge_symbols`
- `_INIT_1` → `init_cpu_quirk_flags`
- `FUN_00120eb4` → `get_android_sdk_int`
- `FUN_00120f84` → `find_loader_entry_via_dlopen_branch_scan`
- `FUN_00121014` → `page_align_down`
- `FUN_00121054` → `is_unconditional_branch_insn`

## Verification used for this pass

- Direct inspection of `recovered/src/libhook_impl/libhook_impl.c`
- Dynamic-symbol list from `recovered/lib/arm64-v8a/libhook_impl.so`
- Prior API/state analysis in `recovered/src/clean/libhook_impl/ANALYSIS.md`
