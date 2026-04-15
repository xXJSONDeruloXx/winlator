# Phase 1 Changelog: Buildable v11 APK

**Goal:** Get a buildable v11.0 APK using prebuilt native libraries extracted from the
official release, establishing a known-good baseline for Phase 2 (native source RE).

## Summary

- **387 compilation errors fixed** (353 jadx artifacts + 34 API mismatches)
- **257 Java files** in final build (67 new, 193 updated, 19 removed vs v7.1)
- **35 native libraries** as prebuilts
- **68 asset files** including Wine 10.10 rootfs
- **154 MB APK** output (vs 146 MB official — difference from debug signing)

## Changes

### Build System (new files)
- `build.gradle` — top-level with AGP 8.2.2 classpath
- `settings.gradle` — project structure, dependency repositories
- `gradle.properties` — AndroidX, JVM args, suppressions
- `gradlew` + `gradle/wrapper/` — Gradle 8.2 wrapper
- `.gitignore` — updated for build artifacts, IDE files, local config

### app/build.gradle
- `compileSdk`: 30 → 35
- `targetSdkVersion`: 28 → 34
- `versionName`: "7.1" → "11.0"
- `versionCode`: 16 → 30
- Added `namespace 'com.winlator'` (required by AGP 8.x)
- ABI filter: `arm64-v8a` only (removed `armeabi-v7a`)
- Added `compileOptions` for Java 1.8
- Disabled `externalNativeBuild` (using prebuilts)
- Updated dependency versions (appcompat 1.6.1, material 1.9.0, etc.)

### AndroidManifest.xml
- Replaced v7.1 manifest with v11 version
- Added `VIBRATE` permission
- Added `FileProvider`, `InitializationProvider`
- Added `supportsPictureInPicture` to XServerDisplayActivity
- Removed `package` attribute (moved to namespace in build.gradle)
- Removed build-time attributes (compileSdkVersion, debuggable, appComponentFactory)

### Java Source (app/src/main/java/com/winlator/)

**67 new classes added:**
- `win32/` package: PEParser, MSIcon, MSBitmap, MSLink, MSLogFont, WinVersions
- `container/`: Drive, DXWrapperPicker, DXWrappers, GraphicsDriverPicker, GraphicsDrivers, FileInfo
- `contentdialog/`: 15 new dialog classes (About, ActiveWindows, AudioDriverConfig, ScreenEffect, TurnipConfig, VortekConfig, etc.)
- `core/`: Win32AppWorkarounds, WineInstaller, GPUHelper, GeneralComponents, LocaleHelper, BatteryUtils, Bitmask, ZipUtils
- `renderer/`: EffectComposer, RenderTarget, FullscreenTransformation, effects/ (FXAA, CRT, Color, Effect), material/ScreenMaterial
- `box64/`: Box64EditPresetDialog, Box64Preset, Box64PresetManager, Box64Utils
- `inputcontrols/`: GamepadVibration, GamepadSlot
- `xconnector/`: ConnectedClient
- `xenvironment/`: RootFS, RootFSInstaller, VortekRendererComponent
- `xserver/`: Decoration, GLXExtension, XComposite, GLXBadContext, GLXBadFBConfig
- `winhandler/`: GamepadHandler, GamepadPlayerConfig
- `widget/`: GPUCardAdapter, SeekBar, SimplePianoKeyboard, TaggedSelectionBox
- Top-level: BaseFileManagerFragment, ContainerFileManagerFragment

**19 classes removed:**
- `box86_64/` package (Box86/32 support dropped)
- `core/MSBitmap, MSLink, MSLogFont` (moved to `win32/`)
- `core/GPUInformation` (replaced by GPUHelper)
- `core/OnExtractFileListener` (inlined)
- `xenvironment/ImageFs, ImageFsInstaller` (renamed to RootFS/RootFSInstaller)
- `xconnector/Client, ClientSocket` (merged into ConnectedClient)
- `xserver/Bitmask, ClientOpcodes` (moved/inlined)
- `XrActivity` (OpenXR support dropped)
- Various `RequestCodes` classes (inlined as constants)

**193 classes updated** — major changes include:
- `XServerDisplayActivity` (+968 lines)
- `Container` (+214 lines)
- `XServer` (195 → 300 lines)

**387 decompilation fixes:**
- Lambda captures (`this.f$0.lambda$...`) → proper lambda expressions
- `switch(R.id.xxx)` → `if/else if` chains (R.id not constant in library modules)
- Synthetic lambda classes → inline lambdas
- `throws Throwable` on interface overrides → removed
- Register variables (`r0`, `r1`, `th`) → correct variable names
- `(T)` generic casts → concrete types
- Missing `ViewHolder` inner classes → qualified references
- Broken try-with-resources → restructured
- API mismatches between recovered classes → added missing methods/constants

### Native Libraries (app/src/main/jniLibs/arm64-v8a/)
All 35 `.so` files replaced with v11 versions from APK. New libraries:
- `libvortekrenderer.so` (598 KB) — Vulkan renderer
- `libgladiorenderer.so` (276 KB) — OpenGL renderer
- `libhook_impl.so` (311 KB) — Driver loading hooks
- `libfile_redirect_hook.so` (4 KB) — fopen redirect
- `libgsl_alloc_hook.so` (4 KB) — Adreno GSL hook
- `libmain_hook.so` (4 KB) — Loader shim
- `libzstd-jni-1.5.2-3.so` (571 KB) — zstd Java bindings
- `libomp.so` (830 KB) — OpenMP runtime

### Assets (app/src/main/assets/)
Full v11 asset set from APK:
- `rootfs.tzst` (62 MB) — Wine 10.10 + glibc rootfs (NEW)
- `rootfs_patches.tzst` — renamed from imagefs_patches
- `box64/box64-0.4.0.tzst` — updated from 0.2.x
- `dxwrapper/dxvk-2.4.1.tzst`, `dxvk-1.10.3.tzst` — updated
- `dxwrapper/vkd3d-2.14.1.tzst` — updated
- `graphics_driver/turnip-26.1.0.tzst` — updated
- `graphics_driver/vortek-2.1.tzst` — NEW
- `graphics_driver/gladio-1.0.tzst` — NEW
- `soundfont/SONiVOX-EAS-GM-Wavetable.sf2` — NEW
- `wallpapers/` — NEW (3 wallpapers)
- `wincomponents/vcrun2005.tzst`, `xaudio.tzst` — NEW
- `box64/default.box64rc` — NEW

Removed: `box86_64/` (Box86/32 dropped), `dxvk-0.96` (old version dropped)

### Resources (app/src/main/res/)
Updated from v7.1 → v11:
- 26 new layout files (file manager, config dialogs, etc.)
- 20 updated layout files
- 4 removed layouts (Box86 era)
- Updated strings.xml (203 → 322 entries)
- Updated styles.xml (new AppThemeBase/Dark/Light theme system)
- Updated arrays.xml (new driver/config options)
- New attrs.xml entries (SeekBar styleable, custom theme colors)
- New xml/file_paths.xml (for FileProvider)
- New drawable resources (file browser, UI elements)
- New menu resources (file manager, container popup)

### Documentation
- `docs/BUILD.md` — build instructions
- `docs/PHASE1-CHANGELOG.md` — this file
