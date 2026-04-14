cmake_minimum_required(VERSION 3.22)
project(libmain_hook C)

add_library(main_hook SHARED
    libmain_hook.c
)

target_include_directories(main_hook PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..   # for hook_impl.h
)

add_library(hook_impl SHARED IMPORTED)
set_target_properties(hook_impl PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/arm64-v8a/libhook_impl.so
)

target_link_libraries(main_hook
    hook_impl
    log
    dl
)

target_compile_options(main_hook PRIVATE
    -fvisibility=default
    -fPIC
    -O2
)

set_target_properties(main_hook PROPERTIES
    OUTPUT_NAME "main_hook"
    SUFFIX ".so"
)
