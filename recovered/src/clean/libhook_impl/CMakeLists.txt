cmake_minimum_required(VERSION 3.22)
project(libhook_impl_clean C CXX)

# This target is intentionally NOT ready to build yet.
# It exists to establish module/file boundaries for the reconstructed source tree.
# Once enough types/constants are defined, this can be flipped into a real build.

add_library(hook_impl_clean OBJECT
    hook_impl_core.c
    loader_bridge.c
    driver_hook.c
    file_redirect.c
    gsl_hook.c
    quirks.c
)

target_include_directories(hook_impl_clean PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Deliberately not linked or exposed as a shared library yet.
