cmake_minimum_required(VERSION 3.22.1)
project(WinlatorHookShims C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -fvisibility=default")

# Shared include for hook_impl.h
set(HOOK_IMPL_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../../recovered/src/clean)

# These shim libraries have undefined symbols resolved at runtime by libhook_impl.so.
# Tell the linker to allow undefined symbols in the output .so.
set(ALLOW_UNDEF "-Wl,--allow-shlib-undefined -Wl,--unresolved-symbols=ignore-all")

# ── libmain_hook ──────────────────────────────────────────────────────────
add_library(main_hook SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/../../recovered/src/clean/libmain_hook/libmain_hook.c)
target_include_directories(main_hook PRIVATE ${HOOK_IMPL_INCLUDE})
set_target_properties(main_hook PROPERTIES LINK_FLAGS "${ALLOW_UNDEF}")

# ── libfile_redirect_hook ────────────────────────────────────────────────
add_library(file_redirect_hook SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/../../recovered/src/clean/libfile_redirect_hook/libfile_redirect_hook.c)
target_include_directories(file_redirect_hook PRIVATE ${HOOK_IMPL_INCLUDE})
set_target_properties(file_redirect_hook PROPERTIES LINK_FLAGS "${ALLOW_UNDEF}")

# ── libgsl_alloc_hook ────────────────────────────────────────────────────
add_library(gsl_alloc_hook SHARED
    ${CMAKE_CURRENT_SOURCE_DIR}/../../recovered/src/clean/libgsl_alloc_hook/libgsl_alloc_hook.c)
target_include_directories(gsl_alloc_hook PRIVATE ${HOOK_IMPL_INCLUDE})
set_target_properties(gsl_alloc_hook PROPERTIES LINK_FLAGS "${ALLOW_UNDEF}")
