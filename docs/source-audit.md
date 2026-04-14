# Winlator v11.0.0 — Source Audit

> **Purpose:** Map exactly what is and isn't open source in this repository relative to the
> [v11.0.0 release APK](https://github.com/brunodev85/winlator/releases/tag/v11.0.0), and
> document what can be recovered from that APK.
>
> **Remote setup used for this audit:**
> - `origin`   → `https://github.com/xXJSONDeruloXx/winlator` (this fork)
> - `upstream` → `https://github.com/brunodev85/winlator` (brunodev85's canonical repo)

---

## 1. Repository Overview

The repo is licensed **LGPL-2.1**. It contains:

| Directory | Contents |
|---|---|
| `app/src/main/java/` | Android app Java source — **212 files, frozen at v7.1** |
| `app/src/main/cpp/` | Native C/C++ source — proot, virglrenderer, midihandler, xr, winlator glue (~210 files) |
| `app/src/main/jniLibs/` | Pre-built `.so` dependencies (FluidSynth, PulseAudio, GLib, Oboe, etc.) |
| `app/src/main/assets/` | Bundled binary assets (box64, dxvk, drivers, Wine prefix skeleton) |
| `android_alsa/` | ALSA server module source for Android |
| `glibc_patches/` | glibc patches (from Termux Pacman) |
| `input_controls/` | Input control profile definitions |
| `installable_components/` | Pre-built binaries for optional components |
| `wine_addons/` | Wine Gecko + Wine Mono `.msi` redistributables |

---

## 2. What IS Open Source in This Repo

### 2.1 Android App Java Source (212 files)

Full source for the v7.1 app including:
- **Custom X server implementation** (`xserver/` ~60 files): Window, Pixmap, GC, extensions
  (DRI3, MIT-SHM, Present, Sync, BigReq), event handling, input device management
- UI fragments and activities: containers, shortcuts, settings, controls editor
- ALSA server client, XEnvironment / ImageFs setup
- OpenXR activity (`XrActivity.java`)
- Core utilities: `FileUtils`, `WineUtils`, `WineRegistryEditor`, `ProcessHelper`, etc.

### 2.2 Native C/C++ Source (~210 files)

| Subdirectory | Upstream project | License |
|---|---|---|
| `cpp/proot/` | [PRoot](https://github.com/proot-me/proot) | GPL-2.0 |
| `cpp/virglrenderer/` | [VirGL](https://gitlab.freedesktop.org/virgl/virglrenderer) | MIT |
| `cpp/midihandler/` | Custom (wraps FluidSynth) | — |
| `cpp/xr/` | Custom OpenXR engine | — |
| `cpp/winlator/` | Custom native glue | — |
| `android_alsa/` | Android ALSA PCM plugin | — |

### 2.3 Open-Source Pre-built Binaries

All from upstream open-source projects, distributed pre-built:

**In `installable_components/`:**
- Box64: 0.3.3, 0.3.5, 0.3.7 ([ptitSeb/box64](https://github.com/ptitSeb/box64), LGPL)
- DXVK: 0.96, 1.4.2, 1.7.2, 2.2, 2.3.1, 2.5.2, 2.6.1
  ([doitsujin/dxvk](https://github.com/doitsujin/dxvk), zlib)
- Turnip: 24.1.0, 25.0.0, 26.0.3 (Mesa, MIT)
- VKD3D: 2.12, 2.14.1, 3.0b ([wine/vkd3d](https://gitlab.winehq.org/wine/vkd3d), LGPL)
- WineD3D: 4.21, 7.8, 10.0 (Wine project, LGPL)

**In `wine_addons/`:**
- Wine Gecko 2.47.4 (x86 + x86_64) — redistributable
- Wine Mono 9.0.0, 10.1.0 (x86) — redistributable

---

## 3. What is NOT Open Source / Missing

### 3.1 App Source Frozen at v7.1 — v8–v11 Not Published

`app/build.gradle` declares `versionName "7.1"` while the current release is **v11.0.0**.
The README explicitly states:

> *"the current app source code is up to version 7.1, I do not update this repository
> frequently precisely to avoid unofficial releases before the official releases of Winlator."*

v8 through v11 app improvements (new renderers, file manager, screen effects, Win32 workarounds,
revamped container model, etc.) are intentionally withheld from this repo until after each
official release.

### 3.2 Wine Build / Root Filesystem

The actual Wine binary image shipped in the APK is **not buildable from this repo**:

- `assets/container_pattern.tzst` (7.9 MB) — only the `.wine` prefix skeleton, not Wine itself
- `assets/imagefs_patches.tzst` (3.5 MB) — patches applied to the image, not the image
- The `obb_image_generator/` build scripts were **deleted** (commit `14bbdad`)
- The APK ships `assets/rootfs.tzst` (62 MB → 395 MB unpacked) containing the full Wine +
  glibc Linux rootfs — this is not present in the repo

**Wine version in the v11.0.0 APK:** `Wine 10.10` (confirmed via `strings` on wineserver binary,
built from `/root/wine-build/wine`).

### 3.3 Wine Patches

Custom Wine patches (DInput, XInput, desktop.c, etc.) were briefly committed to `wine_patches/`
then removed (commit `edcf4bd`: "Move wine_patches to another repository"). The referenced
repository is not publicly linked.

### 3.4 New Native Libraries (v11 only)

Five `.so` files in the v11 APK have no corresponding source in this repo:

| Library | Size (APK) | Purpose |
|---|---|---|
| `libvortekrenderer.so` | 598 KB | New Vulkan-based renderer (Vortek) |
| `libgladiorenderer.so` | 276 KB | New OpenGL renderer (Gladio) |
| `libhook_impl.so` | 311 KB | LD_PRELOAD hooks for custom Vulkan driver loading and file redirection |
| `libfile_redirect_hook.so` | 4 KB | fopen redirect hook |
| `libgsl_alloc_hook.so` | 4 KB | Adreno GSL memory allocator hook |

Note: `libmain_hook.so` (4 KB) is also new but is a minimal loader shim.

---

## 4. What Can Be Extracted / Recovered from the v11 APK

The APK (`Winlator_11.0.apk`, 146 MB) was inspected directly. Findings below.

### 4.1 Java Source (v8–v11) — Near-Perfect Recovery via jadx ✅

**Critical finding:** `proguard-rules.pro` contains `-dontobfuscate`. Combined with
`minifyEnabled true` (which only strips dead code, does not rename), **all class, method, and
field names are fully preserved** in the DEX bytecode.

Running `jadx Winlator_11.0.apk` produces 260 Java files (vs 212 in the repo) with original
naming intact.

#### New classes in v11 not present in the repo source

**Win32 / PE layer** (`win32/`):
- `PEParser.java` — parses PE executables; reads icons, metadata, version info
- `MSIcon.java` — Win32 icon resource parsing (moved from `core/`)
- `MSBitmap.java`, `MSLink.java`, `MSLogFont.java` — moved from `core/` to `win32/`
- `WinVersions.java` — Windows version constants and helpers

**Container model** (`container/`):
- `Drive.java` — per-drive configuration model
- `DXWrapperPicker.java`, `DXWrappers.java` — DX wrapper selection logic
- `GraphicsDriverPicker.java`, `GraphicsDrivers.java` — graphics driver selection
- `FileInfo.java` — file metadata for in-app file manager

**Content dialogs** (`contentdialog/`):
- `AboutDialog.java` — app info dialog
- `ActiveWindowsDialog.java` — running Windows task list
- `AudioDriverConfigDialog.java` — audio driver selection/config
- `CreateFolderDialog.java`, `FileInfoDialog.java` — file manager dialogs
- `GamepadPlayerConfigDialog.java` — per-player gamepad assignment UI
- `ScreenEffectDialog.java` — post-processing effects (FXAA, CRT, color)
- `SoundFontTestDialog.java` — MIDI soundfont test playback
- `TurnipConfigDialog.java`, `VirGLConfigDialog.java`, `VKD3DConfigDialog.java`,
  `VortekConfigDialog.java`, `WineD3DConfigDialog.java` — per-renderer config dialogs

**Core utilities** (`core/`):
- `Win32AppWorkarounds.java` — per-game/app compatibility workaround definitions
- `WineInstaller.java` — new Wine install/update logic
- `GPUHelper.java` — Vulkan API version detection, GPU capability checks
- `GeneralComponents.java` — shared component paths and type definitions
- `LocaleHelper.java` — locale/language utilities
- `BatteryUtils.java`, `Bitmask.java`, `ZipUtils.java` — misc utilities

**Renderer** (`renderer/`):
- `EffectComposer.java` — post-processing pipeline manager
- `RenderTarget.java` — off-screen render target abstraction
- `FullscreenTransformation.java` — fullscreen scaling/transform
- `effects/Effect.java`, `FXAAEffect.java`, `CRTEffect.java`, `ColorEffect.java`
- `material/ScreenMaterial.java` — shader material for screen rendering

**Input controls** (`inputcontrols/`):
- `GamepadVibration.java` — gamepad rumble/haptics support
- `GamepadSlot.java` — per-slot gamepad configuration

**XConnector** (`xconnector/`):
- `ConnectedClient.java` — refactored from `Client.java` + `ClientSocket.java`

**XEnvironment** (`xenvironment/`):
- `VortekRendererComponent.java` — integration of the Vortek Vulkan renderer
- `RootFS.java` — replaces `ImageFs.java` (renamed + expanded)
- `RootFSInstaller.java` — replaces `ImageFsInstaller.java`

**XServer** (`xserver/`):
- `Decoration.java` — window decoration support
- `extensions/GLXExtension.java`, `extensions/XComposite.java` — new X11 extensions
- `errors/GLXBadContext.java`, `errors/GLXBadFBConfig.java`

**Top-level**:
- `ContainerFileManagerFragment.java` — in-app container file browser
- `BaseFileManagerFragment.java` — base class for file management fragments

**Box64** (renamed from `box86_64/`):
- `Box64EditPresetDialog.java`, `Box64Preset.java`, `Box64PresetManager.java`, `Box64Utils.java`
  — Box86/32 support dropped; Box64-only preset management

**WinHandler** (`winhandler/`):
- `GamepadHandler.java` — refactored gamepad event handling
- `GamepadPlayerConfig.java` — multi-player gamepad configuration model

#### Classes removed from v7.1 → v11 (renamed/restructured)

- `box86_64/Box86_64*.java` → replaced by `box64/Box64*.java` (Box86/32 support removed)
- `core/MSBitmap.java`, `MSLink.java`, `MSLogFont.java` → moved to `win32/`
- `core/GPUInformation.java` → replaced by `core/GPUHelper.java`
- `core/OnExtractFileListener.java` → inlined/removed
- `xconnector/Client.java`, `ClientSocket.java` → merged into `xconnector/ConnectedClient.java`
- `xenvironment/ImageFs.java`, `ImageFsInstaller.java` → renamed `RootFS`/`RootFSInstaller`
- `xserver/Bitmask.java`, `ClientOpcodes.java` → moved/inlined
- `xserver/errors/BadCursor.java` → removed or inlined
- `XrActivity.java` → removed (OpenXR support dropped or restructured)
- `alsaserver/RequestCodes.java`, `sysvshm/RequestCodes.java`, `winhandler/RequestCodes.java`
  → inlined as constants

#### Key changes to existing classes (sample)

- `XServerDisplayActivity.java` — **+968 net new lines** vs v7.1
- `Container.java` — **+214 net new lines**
- `XServer.java` — grew from 195 → 300 lines

### 4.2 Binary Assets — Fully Extractable ✅

All assets unzip verbatim from the APK:

| APK asset | Repo equivalent | Status |
|---|---|---|
| `assets/rootfs.tzst` (62 MB → 395 MB) | Not in repo | **New** — full Wine 10.10 + glibc Linux rootfs |
| `assets/rootfs_patches.tzst` (3.7 MB) | `imagefs_patches.tzst` | Renamed + updated |
| `assets/graphics_driver/gladio-1.0.tzst` (106 KB) | Not in repo | **New** — Gladio renderer assets |
| `assets/graphics_driver/vortek-2.1.tzst` (123 KB) | Not in repo | **New** — Vortek renderer assets/shaders |
| `assets/graphics_driver/turnip-26.1.0.tzst` | 24.1.0 in repo | Updated |
| `assets/dxwrapper/dxvk-2.4.1.tzst` | 2.3.1 in repo | Updated |
| `assets/dxwrapper/vkd3d-2.14.1.tzst` | 2.12 in repo | Updated |
| `assets/box64/box64-0.4.0.tzst` | 0.3.7 in installable_components | Updated |
| `assets/soundfont/SONiVOX-EAS-GM-Wavetable.sf2` (1.3 MB) | Not in repo | **New** — MIDI soundfont |
| `assets/wallpapers/` (3 wallpapers) | Not in repo | **New** |
| `assets/wincomponents/vcrun2005.tzst` | Not in repo | **New** |
| `assets/wincomponents/xaudio.tzst` | Not in repo | **New** |
| `assets/box64/default.box64rc` | Not in repo | **New** — default Box64 config |

Removed from APK vs repo:
- `assets/graphics_driver/zink-22.2.5.tzst` — dropped (Zink removed)
- `assets/dxwrapper/dxvk-0.96.tzst` — very old version dropped from bundle
- `assets/box86_64/box86-*.tzst` — Box86 (32-bit) support dropped

### 4.3 Wine Root Filesystem (`rootfs.tzst`) — Fully Extractable ✅

```
rootfs.tzst  →  62 MB (zstd) → 395 MB (tar)
```

Contents:
- `/opt/wine/` — full Wine 10.10 installation
  - `bin/`: wine, wineserver, wineboot, msiexec, regedit, widl, winebuild, winedump, etc.
  - `lib/wine/x86_64-unix/` — 64-bit Unix `.so` Wine modules
  - `lib/wine/x86_64-windows/` — 64-bit Windows `.dll` Wine modules
  - `lib/wine/i386-windows/` — 32-bit Windows `.dll` modules
  - `share/wine/` — Wine data files (fonts, etc.)
- `/usr/` — Linux userspace (glibc, etc.)
- `/etc/` — system config (ALSA, PulseAudio, fonts, ld.so.cache)

**Important:** Wine ELF binaries are **not stripped** (contain full symbol tables).
Build path embedded in binaries: `/root/wine-build/wine`

Wine source is LGPL, so the binaries are redistributable; however, brunodev85's custom patches
(formerly in `wine_patches/`, now "moved to another repository") are what make this build
distinct from upstream Wine 10.10.

### 4.4 New Native Libraries — Symbol Names Recoverable ✅ / C Source Needs RE ⚠️

All new `.so` files in the APK are **not stripped** — full symbol names are present in the
dynamic symbol table, making `nm -D` and disassembly very readable.

#### `libvortekrenderer.so` (598 KB) — Vulkan renderer
Key exported symbols:
```
Java_com_winlator_xenvironment_components_VortekRendererComponent_createVkContext
Java_com_winlator_xenvironment_components_VortekRendererComponent_destroyVkContext
Java_com_winlator_xenvironment_components_VortekRendererComponent_handleExtraDataRequest
Java_com_winlator_xenvironment_components_VortekRendererComponent_initVulkanWrapper
AsyncPipelineCreator_create
ResourceMemory_allocate / _free
ShaderInspector_create / _createModule / _inspectShaderStages
TextureDecoder_create / _destroy / _decodeAll / _copyBufferToImage / ...
TimelineSemaphore_asyncWait
VkObject_create / _free / _fromHandle / _fromId / _toHandle
XWindowSwapchain_create / _destroy / _acquireNextImage / _presentImage
adrenotools_open_libvulkan (from libadrenotools)
```
This is a custom Vulkan translation layer that implements an X11 DRI3/Present-style
swapchain on top of Vulkan, with async pipeline creation and a shader inspection/patching
system. Uses `adrenotools` for custom Adreno driver loading.

#### `libgladiorenderer.so` (276 KB) — OpenGL renderer
Key exported symbols:
```
ARBProgram_bind / _create / _delete / _setSource / _setEnvParameter / _setLocalParameter
AttribStack_push / _pop
GLBuffer_allocateMemory / _bind / _delete / _getBound
GLFormats_queryInternalformat
GLFramebuffer_bind / _create / _delete
```
Implements an ARB assembly program-based OpenGL renderer (ARB_vertex_program /
ARB_fragment_program), likely used as the Gladio software/compatibility renderer.

#### `libhook_impl.so` (311 KB) — Driver loading hooks
Hooks `android_dlopen_ext` and `android_load_sphal_library` at runtime to:
1. Intercept Vulkan driver loading and redirect to a custom driver path
2. Apply `libgsl_alloc_hook` (patches Adreno GSL memory allocations)
3. Apply `libfile_redirect_hook` (redirects specific fopen calls, e.g. `/proc`, `/sys`)

Key strings from binary:
```
hook_android_dlopen_ext: loading custom driver: %s%s
hook_android_dlopen_ext: applied libgsl_alloc_hook
hook_android_dlopen_ext: applied libfile_redirect_hook
hook_fopen: %s -> %s
/dev/kgsl-3d0
```

#### `libfile_redirect_hook.so` (4 KB), `libgsl_alloc_hook.so` (4 KB)
Tiny LD_PRELOAD shims — nearly fully reconstructable via disassembly alone.

---

## 5. Recovery Method Summary

| Component | Tool | Fidelity |
|---|---|---|
| v8–v11 Java source | `jadx Winlator_11.0.apk` | ✅ Near-original (names preserved, `-dontobfuscate`) |
| All asset files | `unzip` | ✅ Verbatim |
| rootfs.tzst (Wine + Linux) | `unzip` → `zstd -d` → `tar xf` | ✅ Complete, unstripped ELFs |
| New .so exported symbols | `nm -D <lib>.so` | ✅ Complete |
| New .so C source | Ghidra / IDA disassembly | ⚠️ Tedious; small libs (~4 KB) are trivial, large ones require effort |
| Wine patch set | Binary diff vs upstream Wine 10.10 | ⚠️ Requires significant reverse engineering |

### jadx command used

```bash
jadx Winlator_11.0.apk -d ./winlator_jadx_output --no-res
```

Output: 260 Java files, 3 minor errors (unrelated to app logic).

### rootfs extraction

```bash
unzip -p Winlator_11.0.apk assets/rootfs.tzst > rootfs.tzst
zstd -d rootfs.tzst -o rootfs.tar   # 62 MB → 395 MB
mkdir rootfs && tar xf rootfs.tar -C rootfs
```

---

## 6. Tooling Notes

- `jadx` — [skylot/jadx](https://github.com/skylot/jadx) (`brew install jadx`)
- `apktool` — (`brew install apktool`) — used for manifest/resource inspection
- `nm -D` — from binutils / Xcode CLI tools
- `zstd` — required to decompress `.tzst` files
- APK inspected: `Winlator_11.0.apk` (SHA: not computed here; 146 MB, from GitHub Releases)

---

## 7. Recovered Content Location

All recovered content has been committed to this branch under:

- `recovered/java/` — 260 jadx-decompiled Java files (v8–v11 source, near-original)
- `recovered/lib/arm64-v8a/` — 6 new native libraries extracted from APK
- `recovered/assets/` — new/updated assets (drivers, wincomponents, soundfont, configs)
- `re/` — reverse engineering setup (Ghidra scripts, symbol tables, strings, dependency map)

See `recovered/README.md` for details and `re/README.md` for RE workflow.
