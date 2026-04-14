#!/usr/bin/env bash
# re/ghidra/setup.sh
# Creates a Ghidra project and runs headless analysis on all recovered Winlator v11 .so files.
# Requires: Ghidra installed (brew install --cask ghidra, or set GHIDRA_HOME manually)
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
LIBS_DIR="${REPO_ROOT}/recovered/lib/arm64-v8a"
PROJECT_DIR="${SCRIPT_DIR}/project"
EXPORTS_DIR="${SCRIPT_DIR}/exports"
SCRIPTS_DIR="${SCRIPT_DIR}/scripts"

# ── Locate Ghidra ────────────────────────────────────────────────────────────
if [ -z "${GHIDRA_HOME:-}" ]; then
  # Common install locations
  for candidate in \
    /Applications/ghidra*.app/Contents/MacOS \
    /opt/homebrew/opt/ghidra \
    ~/Applications/ghidra*.app/Contents/MacOS \
    /usr/share/ghidra \
    /opt/ghidra; do
    if [ -f "${candidate}/analyzeHeadless" ] || \
       [ -f "${candidate%/MacOS}/ghidraRun" ]; then
      GHIDRA_HOME="${candidate%/MacOS}"
      break
    fi
  done
  # brew cask installs to /Applications/ghidra_<ver>_PUBLIC
  if [ -z "${GHIDRA_HOME:-}" ]; then
    GHIDRA_HOME=$(find /Applications -maxdepth 2 -name "analyzeHeadless" 2>/dev/null \
      | head -1 | xargs dirname 2>/dev/null || true)
  fi
fi

if [ -z "${GHIDRA_HOME:-}" ] || [ ! -f "${GHIDRA_HOME}/support/analyzeHeadless" ]; then
  echo "ERROR: Ghidra not found. Install with:"
  echo "  brew install --cask ghidra"
  echo "or set GHIDRA_HOME=/path/to/ghidra"
  exit 1
fi

ANALYZE="${GHIDRA_HOME}/support/analyzeHeadless"
echo "Using Ghidra: ${GHIDRA_HOME}"

mkdir -p "${PROJECT_DIR}" "${EXPORTS_DIR}"

PROJECT_NAME="Winlator_v11"
TARGETS=(
  libhook_impl.so
  libvortekrenderer.so
  libgladiorenderer.so
  libfile_redirect_hook.so
  libgsl_alloc_hook.so
  libmain_hook.so
  libwinlator.so
)

# ── Import + analyze each library ────────────────────────────────────────────
for lib in "${TARGETS[@]}"; do
  src="${LIBS_DIR}/${lib}"
  # libwinlator.so comes from the APK, not recovered/lib
  if [ ! -f "$src" ]; then
    echo "SKIP: ${lib} not found at ${src}"
    continue
  fi
  echo ""
  echo "━━━ Importing ${lib} ━━━"
  "${ANALYZE}" "${PROJECT_DIR}" "${PROJECT_NAME}" \
    -import "${src}" \
    -processor AARCH64:LE:64:v8A \
    -cspec default \
    -overwrite \
    -scriptPath "${SCRIPTS_DIR}" \
    -postScript WinlatorExport.java "${EXPORTS_DIR}/${lib%.so}.exports.json" \
    2>&1 | grep -E "INFO|WARN|ERROR|Script|Exporting" || true
done

echo ""
echo "✓ Project: ${PROJECT_DIR}/${PROJECT_NAME}.gpr"
echo "✓ Exports: ${EXPORTS_DIR}/"
echo ""
echo "Open interactively with:"
echo "  ghidra ${PROJECT_DIR}/${PROJECT_NAME}.gpr"
