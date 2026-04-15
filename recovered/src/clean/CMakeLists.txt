cmake_minimum_required(VERSION 3.22)
project(winlator_native C)

# ── Hook shim libraries (Phase 1 — fully compiled) ────────────────────
add_subdirectory(libfile_redirect_hook)
add_subdirectory(libgsl_alloc_hook)
add_subdirectory(libmain_hook)

# ── Core libraries (Phase 1 — fully compiled) ────────────────────────
# libwinlator: collections, containers, JNI helpers
# libhook_impl: dlopen/fopen hooking logic
# (These build as OBJECT libraries; linked into the main app via Gradle)

# ── Renderer libraries (Phase 2 — reconstructed from Ghidra decompile) ─
# These can be built standalone with the NDK toolchain.
# See each directory's CMakeLists.txt for build instructions.
#
# Uncomment to include in the unified build:
# add_subdirectory(libgladiorenderer)   # OpenGL ES GLX renderer (21 sources, 592 functions)
# add_subdirectory(libvortekrenderer)   # Vulkan ICD wrapper (16 sources, 793 functions)
#
# Note: These libraries depend on libwinlator.so at runtime for container
# functions (ArrayBuffer, ArrayList, RingBuffer, etc.). Link with:
#   target_link_libraries(gladiorenderer winlator)
#   target_link_libraries(vortekrenderer winlator)
