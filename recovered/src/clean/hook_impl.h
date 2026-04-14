// hook_impl.h
// Declarations of hook implementations provided by libhook_impl.so.
// The three shim libraries (libfile_redirect_hook, libgsl_alloc_hook,
// libmain_hook) all depend on libhook_impl.so at runtime and delegate
// their exported functions here.
//
// Recovered from Winlator v11.0.0 — brunodev85/winlator
#pragma once

#include <stdint.h>
#include <stdio.h>
#include <android/dlext.h>

#ifdef __cplusplus
extern "C" {
#endif

// ── fopen redirect ────────────────────────────────────────────────────────
// Used by: libfile_redirect_hook.so
// Intercepts fopen() calls to redirect specific file paths (e.g. /proc, /sys)
FILE *hook_fopen(const char *filename, const char *modes);

// ── Adreno GSL memory hooks ───────────────────────────────────────────────
// Used by: libgsl_alloc_hook.so
// Patches Qualcomm Adreno GPU's Graphics Sub-Layer (GSL) memory allocator.
// param_1: allocation size
// param_2: flags / alignment
// param_3: opaque handle / descriptor
void hook_gsl_memory_alloc_pure_64(uint64_t size, uint32_t flags, uint64_t handle);
void hook_gsl_memory_free_pure(uint64_t handle);

// ── Android dlopen hooks ──────────────────────────────────────────────────
// Used by: libmain_hook.so
// Intercepts Android's dynamic linker to redirect Vulkan driver loading
// to a custom driver path and apply subsidiary hooks.
void *hook_android_dlopen_ext(const char *filename, int flags,
                               const android_dlextinfo *extinfo);
void *hook_android_load_sphal_library(const char *filename, int flags);

#ifdef __cplusplus
}
#endif
