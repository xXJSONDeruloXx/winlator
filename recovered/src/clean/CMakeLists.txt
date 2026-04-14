cmake_minimum_required(VERSION 3.22)
project(winlator_hooks C)

# Build all three hook shim libraries
add_subdirectory(libfile_redirect_hook)
add_subdirectory(libgsl_alloc_hook)
add_subdirectory(libmain_hook)
