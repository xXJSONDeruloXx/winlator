cmake_minimum_required(VERSION 3.22.1)
project(HookImpl CXX C)

# The original binary statically links libc++ (exports C++ runtime symbols).
# Use C++ for the project even though most source is C — this enables
# static libc++ linking which reproduces the original symbol table.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wno-unused-function -fvisibility=default")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wno-unused-function -fvisibility=default")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../recovered/src/clean/libhook_impl)

add_library(hook_impl SHARED
    ${SRC_DIR}/hook_impl_core.c
    ${SRC_DIR}/driver_hook.c
    ${SRC_DIR}/loader_bridge.c
    ${SRC_DIR}/file_redirect.c
    ${SRC_DIR}/gsl_hook.c
    ${SRC_DIR}/quirks.c)

target_include_directories(hook_impl PRIVATE ${SRC_DIR})

# Link against Android log + dl
target_link_libraries(hook_impl log dl)

# Static libc++ to match the original's exported C++ runtime symbols
target_link_options(hook_impl PRIVATE -static-libstdc++)
