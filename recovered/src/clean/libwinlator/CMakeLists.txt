cmake_minimum_required(VERSION 3.22)
project(libwinlator_clean C)

add_library(winlator_clean OBJECT
    collections.c
)

# JNI files require Android NDK headers; excluded from host OBJECT build.
# They are included here for documentation/scaffold purposes.
if(FALSE)
  target_sources(winlator_clean PRIVATE
      jni_xserver.c
      jni_gpu.c
      jni_shm.c
      jni_xconnector.c
      jni_wine.c
  )
endif()

target_include_directories(winlator_clean PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Deliberately not linked or exposed as a shared library yet.
