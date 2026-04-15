cmake_minimum_required(VERSION 3.22.1)
project(WinlatorNative C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wno-unused-function -fvisibility=default")

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../recovered/src/clean/libwinlator)

add_library(winlator SHARED
    ${SRC_DIR}/collections.c
    ${SRC_DIR}/jni_gpu.c
    ${SRC_DIR}/jni_shm.c
    ${SRC_DIR}/jni_wine.c
    ${SRC_DIR}/jni_xconnector.c
    ${SRC_DIR}/jni_xserver.c)

target_include_directories(winlator PRIVATE ${SRC_DIR})

# Link against Android libraries used by the JNI code
target_link_libraries(winlator
    log
    android
    jnigraphics
    EGL
    GLESv2)
