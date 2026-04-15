cmake_minimum_required(VERSION 3.22)
project(libgladiorenderer_clean C)

# Reconstructed libgladiorenderer — OpenGL ES GLX renderer
# Cross-compile for aarch64 Android using NDK toolchain.

set(GLADIO_SOURCES
    gladio_globals.c
    gl_context.c
    glx_context.c
    gl_renderer.c
    command_dispatch.c
    arb_program.c
    gl_buffer.c
    gl_framebuffer.c
    gl_texture.c
    gl_sampler.c
    gl_query.c
    gl_vertex_array.c
    shader_converter.c
    shader_material.c
    attrib_stack.c
    gl_formats.c
    tex_compress.c
    jni_glx.c
    gd_handlers.c
)

add_library(gladiorenderer SHARED ${GLADIO_SOURCES})

target_include_directories(gladiorenderer PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../libwinlator
)

target_link_libraries(gladiorenderer
    log
    EGL
    GLESv3
    android
)

# Link against libwinlator for collections/containers
# (In the actual APK build, this would link against the prebuilt or compiled libwinlator.so)
target_compile_options(gladiorenderer PRIVATE
    -O2
    -fPIC
    -Wall
    -Wno-unused-variable
    -Wno-unused-function
    -Wno-unused-but-set-variable
)
