#!/usr/bin/env bash
# re/ghidra/decompile.sh
# Runs WinlatorDecompile.java on already-analyzed libraries to produce
# compilable C source in recovered/src/<libname>/
#
# Usage (from repo root):
#   ./re/ghidra/decompile.sh                    # all libs
#   ./re/ghidra/decompile.sh libhook_impl       # one lib
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
GHIDRA_HOME="${SCRIPT_DIR}/ghidra_install/ghidra_12.0.4_PUBLIC"
ANALYZE="${GHIDRA_HOME}/support/analyzeHeadless"
PROJECT="${SCRIPT_DIR}/project"
SCRIPTS="${SCRIPT_DIR}/scripts"
SRC_OUT="${REPO_ROOT}/recovered/src"

if [ ! -f "$ANALYZE" ]; then
  echo "ERROR: Ghidra not found. Run ./re/ghidra/setup.sh first."
  exit 1
fi

mkdir -p "$SRC_OUT"

ALL_TARGETS=(
  libhook_impl
  libfile_redirect_hook
  libgsl_alloc_hook
  libmain_hook
  libvortekrenderer
  libgladiorenderer
  libwinlator
)

# Filter to requested target(s) or run all
if [ $# -gt 0 ]; then
  TARGETS=("$@")
else
  TARGETS=("${ALL_TARGETS[@]}")
fi

for lib in "${TARGETS[@]}"; do
  lib="${lib%.so}"  # strip .so if provided
  OUT="${SRC_OUT}/${lib}"
  mkdir -p "$OUT"
  echo ""
  echo "━━━ Decompiling ${lib}.so ━━━"
  "$ANALYZE" "$PROJECT" Winlator_v11 \
    -process "${lib}.so" \
    -scriptPath "$SCRIPTS" \
    -postScript WinlatorDecompile.java "$OUT" \
    2>&1 | grep -E "WinlatorDecompile|ERROR|SCRIPT" || true
  echo "  → ${OUT}/${lib}.c"
  echo "  → ${OUT}/${lib}.h"
done

echo ""
echo "✓ Done. Source tree:"
find "$SRC_OUT" -name "*.c" -o -name "*.h" | sort | while read f; do
  rel="${f#$REPO_ROOT/}"
  lines=$(wc -l < "$f")
  printf "  %-55s %d lines\n" "$rel" "$lines"
done
