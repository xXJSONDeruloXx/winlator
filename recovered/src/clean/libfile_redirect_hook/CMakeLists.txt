cmake_minimum_required(VERSION 3.22)
project(libfile_redirect_hook C)

add_library(file_redirect_hook SHARED
    libfile_redirect_hook.c
)

target_include_directories(file_redirect_hook PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/..   # for hook_impl.h
)

# hook_* symbols are provided by libhook_impl.so at runtime.
# Link against the recovered binary so the linker can resolve them.
add_library(hook_impl SHARED IMPORTED)
set_target_properties(hook_impl PROPERTIES
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../../../lib/arm64-v8a/libhook_impl.so
)

target_link_libraries(file_redirect_hook
    hook_impl
    log
)

# Match original build flags
target_compile_options(file_redirect_hook PRIVATE
    -fvisibility=default
    -fPIC
    -O2
)

set_target_properties(file_redirect_hook PROPERTIES
    OUTPUT_NAME "file_redirect_hook"
    SUFFIX ".so"
)
