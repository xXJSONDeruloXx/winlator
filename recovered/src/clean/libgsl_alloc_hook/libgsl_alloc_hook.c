// libgsl_alloc_hook.c
// Patches Qualcomm Adreno GPU's closed-source GSL (Graphics Sub-Layer)
// memory allocator. Loaded into the Vulkan driver namespace by libhook_impl.so
// so that GPU memory allocations can be intercepted and redirected.
//
// The Adreno driver exports gsl_memory_alloc_pure / gsl_memory_alloc_pure_64
// and gsl_memory_free_pure as its GPU memory allocation API. This library
// overrides them to route through hook_impl's custom allocator which works
// around driver incompatibilities on Android.
//
// Recovered from libgsl_alloc_hook.so (Winlator v11.0.0)
// Original source inferred via Ghidra decompilation — see ../libgsl_alloc_hook.c

#include <stdint.h>
#include "hook_impl.h"

// 32-bit size variant — delegates to the 64-bit hook.
void gsl_memory_alloc_pure(uint32_t size, uint32_t flags, uint64_t handle) {
    hook_gsl_memory_alloc_pure_64((uint64_t)size, flags, handle);
}

// Primary 64-bit GPU memory allocation.
void gsl_memory_alloc_pure_64(uint64_t size, uint32_t flags, uint64_t handle) {
    hook_gsl_memory_alloc_pure_64(size, flags, handle);
}

// GPU memory free.
void gsl_memory_free_pure(uint64_t handle) {
    hook_gsl_memory_free_pure(handle);
}
