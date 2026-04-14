// libmain_hook.c
// Overrides android_dlopen_ext() and android_load_sphal_library() to intercept
// Vulkan and SPHAL driver loading. This is the entry point of the entire hook
// chain — it is loaded first (via System.loadLibrary("main_hook") in Java),
// which causes libhook_impl.so to register itself as a dlopen interceptor.
//
// When the Android Vulkan loader calls android_dlopen_ext("vulkan.*.so", ...),
// this hook intercepts it, creates a new linker namespace, loads libhook_impl.so
// into that namespace, optionally applies libfile_redirect_hook and
// libgsl_alloc_hook, then loads the custom Vulkan driver instead of the default.
//
// Recovered from libmain_hook.so (Winlator v11.0.0)
// Original source inferred via Ghidra decompilation — see ../libmain_hook.c

#include <android/dlext.h>
#include "hook_impl.h"

// Override Android's namespace-aware dlopen. Called by the Vulkan loader when
// loading driver .so files. If the filename contains "vulkan.", the hook
// redirects to a custom driver path; otherwise falls through to the real impl.
void *android_dlopen_ext(const char *filename, int flags,
                          const android_dlextinfo *extinfo) {
    return hook_android_dlopen_ext(filename, flags, extinfo);
}

// Override Android's SPHAL (Supplier Process HAL) library loader.
// SPHAL is used to load vendor-specific HAL implementations in a restricted
// namespace. Intercepted here to apply the same custom driver redirect.
void *android_load_sphal_library(const char *filename, int flags) {
    return hook_android_load_sphal_library(filename, flags);
}
