cmake_minimum_required(VERSION 3.22)
project(libvortekrenderer_clean C)

file(GLOB VORTEK_SOURCES "*.c")

add_library(vortekrenderer SHARED ${VORTEK_SOURCES})

target_include_directories(vortekrenderer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../libwinlator
)

target_link_libraries(vortekrenderer
    log
    android
    dl
)

target_compile_options(vortekrenderer PRIVATE
    -O2 -fPIC -Wall
    -Wno-unused-variable -Wno-unused-function -Wno-unused-but-set-variable
    -Wno-int-conversion -Wno-pointer-sign -Wno-incompatible-pointer-types
    -Wno-parentheses -Wno-implicit-function-declaration -Wno-implicit-int
    -Wno-return-type -Wno-format -Wno-incompatible-library-redeclaration
    -Wno-tautological-compare -Wno-sometimes-uninitialized
    -Wno-pointer-to-int-cast -Wno-int-to-pointer-cast
    -Wno-builtin-requires-header
)
