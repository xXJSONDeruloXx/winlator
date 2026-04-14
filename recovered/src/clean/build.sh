#!/usr/bin/env bash
# recovered/src/clean/build.sh
# Builds the three hook shim libraries targeting Android ARM64.
# Output .so files are placed in build/arm64-v8a/.
#
# Usage:
#   ./build.sh               # build all
#   ./build.sh clean         # clean build dir
#   NDK=/path/to/ndk ./build.sh   # specify NDK manually
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${SCRIPT_DIR}/build"
OUT_DIR="${BUILD_DIR}/arm64-v8a"

# ── Locate NDK ────────────────────────────────────────────────────────────
NDK="${NDK:-${ANDROID_NDK_HOME:-${ANDROID_NDK:-}}}"
if [ -z "$NDK" ] || [ ! -d "$NDK" ]; then
  # Common macOS locations
  for candidate in \
    /opt/homebrew/share/android-ndk \
    "$HOME/Library/Android/sdk/ndk/$(ls "$HOME/Library/Android/sdk/ndk/" 2>/dev/null | sort -V | tail -1)" \
    /usr/local/lib/android/sdk/ndk/*; do
    if [ -d "$candidate" ]; then NDK="$candidate"; break; fi
  done
fi
[ -d "$NDK" ] || { echo "ERROR: Android NDK not found. Set NDK=/path/to/ndk"; exit 1; }
echo "NDK: $NDK"

if [ "${1:-}" = "clean" ]; then
  rm -rf "$BUILD_DIR"
  echo "✓ cleaned"
  exit 0
fi

mkdir -p "$OUT_DIR"

cmake \
  -S "$SCRIPT_DIR" \
  -B "$BUILD_DIR" \
  -DCMAKE_TOOLCHAIN_FILE="$NDK/build/cmake/android.toolchain.cmake" \
  -DANDROID_ABI=arm64-v8a \
  -DANDROID_PLATFORM=android-26 \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_LIBRARY_OUTPUT_DIRECTORY="$OUT_DIR" \
  -G Ninja

cmake --build "$BUILD_DIR" -- -j$(sysctl -n hw.logicalcpu 2>/dev/null || nproc)

echo ""
echo "✓ Built:"
ls -lh "$OUT_DIR"/*.so 2>/dev/null || ls -lh "$BUILD_DIR"/**/*.so 2>/dev/null

echo ""
echo "Verify symbols match originals:"
for lib in file_redirect_hook gsl_alloc_hook main_hook; do
  built="$OUT_DIR/lib${lib}.so"
  orig="$SCRIPT_DIR/../../lib/arm64-v8a/lib${lib}.so"
  [ -f "$built" ] || continue
  echo ""
  echo "  lib${lib}.so exports:"
  nm -D "$built" 2>/dev/null | grep " T " | awk '{print "    +",$3}'
  if [ -f "$orig" ]; then
    echo "  vs original:"
    nm -D "$orig" 2>/dev/null | grep " T " | awk '{print "    =",$3}'
  fi
done
