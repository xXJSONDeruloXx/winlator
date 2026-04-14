// libfile_redirect_hook.c
// LD_PRELOAD-style hook that overrides fopen() to redirect specific file paths.
// Loaded by libhook_impl.so into the Vulkan driver's namespace so that
// /proc and /sys reads can be intercepted and redirected.
//
// Recovered from libfile_redirect_hook.so (Winlator v11.0.0)
// Original source inferred via Ghidra decompilation — see ../libfile_redirect_hook.c

#include <stdio.h>
#include "hook_impl.h"

// Override libc fopen. Delegates to hook_fopen() in libhook_impl.so which
// maintains a path redirect table (e.g. /proc/self/fd/N → actual fd path).
FILE *fopen(const char *filename, const char *modes) {
    return hook_fopen(filename, modes);
}
