cmake_minimum_required(VERSION 3.22)
project(libgsl_alloc_hook C)

add_library(gsl_alloc_hook SHARED
    libgsl_alloc_hook.c
)

target_include_directories(gsl_alloc_hook PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..   # for hook_impl.h
)

add_library(hook_impl SHARED IMPORTED)
set_target_properties(hook_impl PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/arm64-v8a/libhook_impl.so
)

target_link_libraries(gsl_alloc_hook
    hook_impl
    log
)

target_compile_options(gsl_alloc_hook PRIVATE
    -fvisibility=default
    -fPIC
    -O2
)

set_target_properties(gsl_alloc_hook PROPERTIES
    OUTPUT_NAME "gsl_alloc_hook"
    SUFFIX ".so"
)
