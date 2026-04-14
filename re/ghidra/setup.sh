#!/usr/bin/env bash
# re/ghidra/setup.sh
# Downloads Ghidra if needed, creates a project, and runs headless analysis
# on all recovered Winlator v11 .so files.
#
# Usage (from repo root):
#   ./re/ghidra/setup.sh
# Or from anywhere:
#   /path/to/winlator/re/ghidra/setup.sh
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "${SCRIPT_DIR}/../.." && pwd)"
LIBS_DIR="${REPO_ROOT}/recovered/lib/arm64-v8a"
PROJECT_DIR="${SCRIPT_DIR}/project"
EXPORTS_DIR="${SCRIPT_DIR}/exports"
SCRIPTS_DIR="${SCRIPT_DIR}/scripts"
GHIDRA_INSTALL_DIR="${SCRIPT_DIR}/ghidra_install"

GHIDRA_VERSION="12.0.4"
GHIDRA_BUILD="20260303"
GHIDRA_ZIP="ghidra_${GHIDRA_VERSION}_PUBLIC_${GHIDRA_BUILD}.zip"
GHIDRA_URL="https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_${GHIDRA_VERSION}_build/${GHIDRA_ZIP}"

# ── Locate or install Ghidra ─────────────────────────────────────────────────
find_ghidra() {
  # Check known locations
  for candidate in \
    "${GHIDRA_INSTALL_DIR}/ghidra_${GHIDRA_VERSION}_PUBLIC" \
    "${GHIDRA_INSTALL_DIR}/ghidra_"*"_PUBLIC" \
    /Applications/ghidra_*_PUBLIC \
    ~/Applications/ghidra_*_PUBLIC \
    /opt/ghidra \
    /usr/local/ghidra; do
    # shellcheck disable=SC2231
    for dir in $candidate; do
      if [ -f "${dir}/support/analyzeHeadless" ]; then
        echo "$dir"
        return 0
      fi
    done
  done
  return 1
}

if GHIDRA_HOME=$(find_ghidra 2>/dev/null); then
  echo "✓ Found Ghidra: ${GHIDRA_HOME}"
else
  echo "Ghidra not found. Downloading ${GHIDRA_VERSION}..."
  echo "  URL: ${GHIDRA_URL}"
  mkdir -p "${GHIDRA_INSTALL_DIR}"
  ZIP_PATH="${GHIDRA_INSTALL_DIR}/${GHIDRA_ZIP}"

  if command -v curl &>/dev/null; then
    curl -L --progress-bar -o "${ZIP_PATH}" "${GHIDRA_URL}"
  elif command -v wget &>/dev/null; then
    wget -q --show-progress -O "${ZIP_PATH}" "${GHIDRA_URL}"
  else
    echo "ERROR: Neither curl nor wget found. Download manually:"
    echo "  ${GHIDRA_URL}"
    echo "  Extract to: ${GHIDRA_INSTALL_DIR}/"
    exit 1
  fi

  echo "Extracting..."
  unzip -q "${ZIP_PATH}" -d "${GHIDRA_INSTALL_DIR}"
  rm -f "${ZIP_PATH}"

  GHIDRA_HOME=$(find_ghidra) || {
    echo "ERROR: Extraction failed — analyzeHeadless not found in ${GHIDRA_INSTALL_DIR}"
    exit 1
  }
  echo "✓ Installed Ghidra: ${GHIDRA_HOME}"
fi

ANALYZE="${GHIDRA_HOME}/support/analyzeHeadless"

# ── Verify Java ───────────────────────────────────────────────────────────────
if ! java -version &>/dev/null; then
  echo "ERROR: Java not found. Install with: brew install openjdk"
  exit 1
fi
JAVA_VER=$(java -version 2>&1 | awk -F'"' '/version/{print $2}' | cut -d. -f1)
if [ "${JAVA_VER:-0}" -lt 17 ] 2>/dev/null; then
  echo "WARNING: Ghidra requires Java 17+. Found: $(java -version 2>&1 | head -1)"
fi

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
echo ""
echo "Analyzing ${#TARGETS[@]} libraries → project: ${PROJECT_DIR}/${PROJECT_NAME}"
echo ""

for lib in "${TARGETS[@]}"; do
  src="${LIBS_DIR}/${lib}"
  if [ ! -f "$src" ]; then
    echo "  SKIP: ${lib} (not found at ${src})"
    continue
  fi
  echo "  ━━━ ${lib} ($(du -h "$src" | cut -f1)) ━━━"
  "${ANALYZE}" "${PROJECT_DIR}" "${PROJECT_NAME}" \
    -import "${src}" \
    -processor AARCH64:LE:64:v8A \
    -cspec default \
    -overwrite \
    -scriptPath "${SCRIPTS_DIR}" \
    -postScript WinlatorExport.java "${EXPORTS_DIR}/${lib%.so}.json" \
    2>&1 | grep -E "^(INFO|WARN|ERROR|SCRIPT|.*Script.*|.*Exporting.*)" | grep -v "^INFO  - HEADLESS" \
    || true
  echo "  ✓ exported → ${EXPORTS_DIR}/${lib%.so}.json"
done

echo ""
echo "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
echo "✓ Project:  ${PROJECT_DIR}/${PROJECT_NAME}.gpr"
echo "✓ Exports:  ${EXPORTS_DIR}/"
echo ""
echo "Open interactively:"
echo "  ${GHIDRA_HOME}/ghidraRun ${PROJECT_DIR}/${PROJECT_NAME}.gpr"
echo ""
echo "Recommended first targets:"
echo "  1. libfile_redirect_hook.so  (4 KB — warm-up)"
echo "  2. libgsl_alloc_hook.so      (4 KB — Adreno GSL hook)"
echo "  3. libhook_impl.so           (311 KB — core dlopen interceptor)"
echo "  4. libvortekrenderer.so      (598 KB — start from Java_* JNI entries)"
