# Recovered Content — Winlator v11.0.0

All content here was extracted from the official `Winlator_11.0.apk` release.
Nothing was modified; provenance is documented in `docs/source-audit.md`.

## Contents

| Path | Source | Notes |
|---|---|---|
| `java/` | `classes.dex` via jadx | v8–v11 app source, 260 files, names intact (`-dontobfuscate`) |
| `lib/arm64-v8a/` | `lib/arm64-v8a/` in APK | New closed-source native libraries not in upstream repo |
| `assets/box64/` | `assets/box64/` in APK | Updated env_vars.json + new default.box64rc |
| `assets/graphics_driver/` | `assets/graphics_driver/` in APK | New Gladio and Vortek renderer packages |
| `assets/soundfont/` | `assets/soundfont/` in APK | SONiVOX GM soundfont for MIDI |
| `assets/wallpapers/` | `assets/wallpapers/` in APK | Three desktop wallpapers |
| `assets/wincomponents/` | `assets/wincomponents/` in APK | New vcrun2005 + xaudio components |
| `assets/*.json` | APK assets | Updated v11 JSON configs (pretty-printed for diffability) |

## Extraction Commands

```bash
APK=~/Downloads/Winlator_11.0.apk

# Java source
jadx "$APK" -d jadx_output --no-res

# Specific .so
unzip -p "$APK" lib/arm64-v8a/libvortekrenderer.so > libvortekrenderer.so

# rootfs (Wine 10.10 + glibc, 62 MB → 395 MB)
unzip -p "$APK" assets/rootfs.tzst | zstd -d | tar xf - -C rootfs/
```

## Java Source Notes

The jadx output is near-original quality. Key points:
- All class/method/field names preserved (`-dontobfuscate` in proguard-rules.pro)
- `minifyEnabled true` only removed dead code — no obfuscation
- 3 minor decompilation errors (unrelated to app logic)
- `R.java` and synthetic lambda classes (`$$ExternalSyntheticLambda*`) excluded
- This represents the complete app source for v8 through v11

See `docs/source-audit.md` for detailed class-by-class change list vs the v7.1 repo source.
