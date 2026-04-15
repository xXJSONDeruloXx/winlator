# Building Winlator v11.0 from Source

## Prerequisites

| Tool | Version | Install |
|------|---------|---------|
| **Java JDK** | 17+ | `brew install temurin` or [Adoptium](https://adoptium.net/) |
| **Android SDK** | Platform 35+ | [Android Studio](https://developer.android.com/studio) or cmdline-tools |
| **Android NDK** | r27c+ | Via SDK Manager or [direct download](https://developer.android.com/ndk/downloads) |
| **Gradle** | 8.2 (pinned via wrapper) | Included — just use `./gradlew` |

The repo includes a Gradle wrapper (`gradlew`) pinned to Gradle 8.2 with AGP 8.2.2.

## Quick Start

```bash
# Clone
git clone https://github.com/xXJSONDeruloXx/winlator.git
cd winlator

# Set up local SDK paths
cat > local.properties << EOF
sdk.dir=/path/to/Android/sdk
ndk.dir=/path/to/Android/sdk/ndk/27.2.12479018
EOF

# Build debug APK
./gradlew assembleDebug

# Output: app/build/outputs/apk/debug/app-debug.apk (~154 MB)
```

## Build Configuration

| Setting | Value |
|---------|-------|
| `compileSdk` | 35 |
| `targetSdkVersion` | 34 |
| `minSdkVersion` | 26 |
| `versionName` | "11.0" |
| ABI | arm64-v8a only |

## Architecture

### Current State: Prebuilt Native Libraries

All 35 native `.so` libraries are included as prebuilts in `app/src/main/jniLibs/arm64-v8a/`.
The CMake native build is currently disabled — the app compiles Java source and packages
the prebuilt binaries.

This includes:
- **Winlator core**: `libwinlator.so`, `libmidihandler.so`, `libvirglrenderer.so`
- **v11 renderers**: `libvortekrenderer.so` (Vulkan), `libgladiorenderer.so` (OpenGL)
- **v11 hooks**: `libhook_impl.so`, `libmain_hook.so`, `libfile_redirect_hook.so`, `libgsl_alloc_hook.so`
- **Third-party**: PulseAudio, FluidSynth, GLib, Oboe, zstd-jni, libomp, etc.

### Future: Building Native from Source

To re-enable native compilation, uncomment the `externalNativeBuild` block in
`app/build.gradle` and update `app/src/main/cpp/CMakeLists.txt` to include the
new v11 libraries. See `recovered/src/clean/` for reconstructed C source.

## Java Source

The Java source in `app/src/main/java/com/winlator/` was recovered from the v11.0.0
APK using jadx decompilation. Because the original build used `-dontobfuscate` in
ProGuard, all class/method/field names are preserved. Decompilation artifacts (lambda
captures, register variables, switch/case on R.id) have been manually fixed.

See `docs/source-audit.md` for the full provenance chain and `docs/java-diff-v71-v11.md`
for the class-by-class change list from v7.1 to v11.

## Assets

All binary assets (`rootfs.tzst`, drivers, Box64, wincomponents, etc.) are extracted
verbatim from the official v11.0.0 APK release. The 62 MB `rootfs.tzst` contains the
full Wine 10.10 + glibc Linux root filesystem.

## Signing

Debug builds use the Android debug keystore. For release builds, configure your own
signing key in `app/build.gradle`.
