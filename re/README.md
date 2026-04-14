# Winlator v11 — Reverse Engineering Setup

This directory contains tooling to reverse-engineer the closed-source native libraries
extracted from the v11.0.0 APK.

## Targets (priority order)

| Library | Size | Priority | Reason |
|---|---|---|---|
| `libhook_impl.so` | 311 KB | 🔴 HIGH | Core hooking logic — dlopen/fopen intercept for custom Vulkan driver loading |
| `libvortekrenderer.so` | 598 KB | 🔴 HIGH | New Vulkan renderer — the main v11 graphics backend |
| `libgladiorenderer.so` | 276 KB | 🟡 MED | New GL renderer (Gladio) — ARB assembly program based |
| `libfile_redirect_hook.so` | 4 KB | 🟢 LOW | Tiny fopen hook — nearly trivially reconstructable |
| `libgsl_alloc_hook.so` | 4 KB | 🟢 LOW | Tiny Adreno GSL memory hook |
| `libmain_hook.so` | 4 KB | 🟢 LOW | Loader shim — just re-exports hooks |

All targets are ARM64 ELF shared objects. All are stripped (no debug symbols in `.symtab`),
but the dynamic symbol table (`.dynsym`) is fully intact — `nm -D` gives complete exported
symbol names.

## Library Architecture

```
libwinlator.so  ←──── custom data structures (ArrayBuffer, ArrayDeque, ArrayList,
    │                  ArrayMap, SparseArray, RingBuffer, IntArray, ashmemCreateRegion)
    │
    ├──→ libgladiorenderer.so   (OpenGL ES renderer — imports all gl* + custom containers)
    │
    └──→ libvortekrenderer.so   (Vulkan renderer — imports AHardwareBuffer + containers)

libhook_impl.so
    ├── exports: hook_android_dlopen_ext, hook_android_load_sphal_library
    │            hook_fopen, hook_gsl_memory_alloc_pure_64, hook_gsl_memory_free_pure
    ├──→ libfile_redirect_hook.so  (imports hook_fopen from libhook_impl)
    ├──→ libgsl_alloc_hook.so      (imports hook_gsl_memory_alloc_pure_64/free from libhook_impl)
    └──→ libmain_hook.so           (imports hook_android_dlopen_ext/load_sphal from libhook_impl)
```

`libmain_hook.so` is loaded via `System.loadLibrary("main_hook")` at startup. It triggers
`libhook_impl.so` which intercepts `android_dlopen_ext` — when Vulkan or SPHAL drivers are
loaded, it redirects to a custom driver path and optionally applies the GSL/fopen hooks for
Adreno GPU workarounds.

## Pre-extracted Data

- `symbols/` — `nm -D` output for each library (full dynamic symbol table)
- `strings/` — filtered `strings` output (paths, function names, error messages)
- `symbols/dependency_map.md` — undefined symbol cross-reference (what each lib imports)

## Setup: Ghidra

### Install

The Homebrew cask for Ghidra was removed. Use the setup script — it auto-downloads
Ghidra 12.0.4 from GitHub releases if it isn't already installed:

```bash
# From the repo root:
./re/ghidra/setup.sh
```

Requires Java 17+ (already present: `brew install openjdk` if needed).

Or install manually:
```bash
# Download from: https://github.com/NationalSecurityAgency/ghidra/releases
# Extract the zip, then set GHIDRA_HOME:
export GHIDRA_HOME=/path/to/ghidra_12.0.4_PUBLIC
./re/ghidra/setup.sh
```

### Create project and analyze (headless)

```bash
# From the repo root (winlator/):
./re/ghidra/setup.sh
```

This will:
1. Download Ghidra 12.0.4 into `re/ghidra/ghidra_install/` if not found
2. Create a project at `re/ghidra/project/Winlator_v11.gpr`
3. Import all 7 target `.so` files with AARCH64:LE:64:v8A processor spec
4. Run full auto-analysis on each
5. Export function list + call tree for each binary to `re/ghidra/exports/`

### Interactive analysis

```bash
# After setup.sh runs, open the project:
re/ghidra/ghidra_install/ghidra_12.0.4_PUBLIC/ghidraRun \
  re/ghidra/project/Winlator_v11.gpr
```

Then open any of the imported programs. Recommended workflow:
1. Start with `libfile_redirect_hook.so` — 4 KB, single function, excellent warm-up
2. Then `libgsl_alloc_hook.so` — same size, patches Adreno GPU allocator
3. Then `libhook_impl.so` — the core; focus on `hook_android_dlopen_ext`
4. Then `libvortekrenderer.so` — start from the 4 `Java_*` JNI entry points

### Useful Ghidra settings for ARM64 Android

- **Processor:** AARCH64:LE:64:v8A
- **Compiler spec:** default
- Enable: *Demangler GNU*, *DWARF* (even if stripped, it tries), *Stack Analysis*
- After import: run **Symbol Table** → filter for `Java_*` to find JNI entry points immediately

## Setup: radare2 / rizin (lightweight alternative)

```bash
brew install rizin
cd re

# Quick disassembly of hook entry point
rizin -A recovered/lib/arm64-v8a/libhook_impl.so
> afl         # list all functions
> pdf @ sym.hook_android_dlopen_ext   # disassemble

# Batch analysis
for lib in recovered/lib/arm64-v8a/lib*.so; do
  echo "=== $lib ===" >> ghidra/exports/rizin_functions.txt
  rizin -qc 'aaa; afl' "$lib" 2>/dev/null >> ghidra/exports/rizin_functions.txt
done
```

## Setup: Binary Ninja (if available)

The Ghidra script at `ghidra/scripts/WinlatorExport.java` has an equivalent
Binary Ninja workflow — open any `.so` and run the analysis; BNDB files can be committed
to `re/binja/` for sharing analysis state.

## Wine Binary Diff

The Wine 10.10 build in `assets/rootfs.tzst` is a custom patched build.
To recover the patches:

```bash
# 1. Extract rootfs
unzip -p Winlator_11.0.apk assets/rootfs.tzst | zstd -d | tar xf - -C /tmp/winlator_rootfs

# 2. Get upstream Wine 10.10 source
git clone --branch wine-10.10 https://gitlab.winehq.org/wine/wine.git /tmp/wine-upstream
cd /tmp/wine-upstream && ./configure --enable-win64 && make -j$(nproc)

# 3. Binary diff key DLLs (e.g. dinput)
bindiff /tmp/winlator_rootfs/opt/wine/lib/wine/x86_64-unix/dinput.so \
        /tmp/wine-upstream/dlls/dinput/dinput.so.so
# or use Ghidra BinDiff plugin / Diaphora
```

Suspected patch areas (based on historical wine_patches directory before removal):
- `dlls/dinput/dinput_main.c` — gamepad/input mapping
- `dlls/dinput/gamepad.c` — Android gamepad integration
- `dlls/user32/desktop.c` — desktop/window management
- `dlls/xinput/main.c` — XInput controller support
