#include "gsl_hook.h"
#include "hook_impl_core.h"
#if defined(__has_include)
#  if __has_include(<android/log.h>)
#    include <android/log.h>
#  else
     extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#  endif
#else
  extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#endif
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

uint32_t hook_gsl_memory_alloc_pure_64(unsigned long size, uint32_t flags, uint64_t *out) {
    CachedGslAlloc *cached = NULL;

    if (g_hook_config != NULL) {
        cached = (CachedGslAlloc *)g_hook_config->cached_gsl_alloc;
    }

    // Exact recovered control flow:
    // if no cached descriptor, or size mismatch, or flags-mask mismatch,
    // forward to the original GSL allocator(s).
    if (cached == NULL ||
        cached->requested_size != (uint64_t)size ||
        (((uint64_t)flags & cached->required_flags_mask) != cached->required_flags_mask)) {
        if (g_orig_gsl_alloc64 == NULL) {
            return g_orig_gsl_alloc32 != NULL
                ? g_orig_gsl_alloc32((uint32_t)size, flags, out)
                : 0;
        }
        return g_orig_gsl_alloc64((uint64_t)size, flags, out);
    }

    // Cached handoff path.
    GslAllocRecord *record = (GslAllocRecord *)out;
    record->q0 = cached->q0;
    record->q1 = cached->q1;
    record->q2 = cached->requested_size;
    record->q3 = cached->required_flags_mask;
    record->marker = HOOK_GSL_ALLOC_MARKER;

    cached->requested_size = 0;
    cached->q1 = HOOK_GSL_CACHE_USED;
    return 0;
}

uint32_t hook_gsl_memory_free_pure(long handle) {
    GslAllocRecord *record = (GslAllocRecord *)handle;

    if (record->marker == HOOK_GSL_ALLOC_MARKER) {
        if (g_kgsl_fd == 0) {
            g_kgsl_fd = open("/dev/kgsl-3d0", O_RDWR);
        }

        KgslGpuMemGetInfoReq get_info;
        memset(&get_info, 0, sizeof(get_info));
        get_info.gpuaddr = *((uint64_t *)handle + 1);

        int rc = ioctl(g_kgsl_fd, IOCTL_KGSL_GPUMEM_GET_INFO, &get_info);
        if (rc < 0) {
            __android_log_print(4, "hook_impl", "IOCTL_KGSL_GPUMEM_GET_INFO failed");
            return 0;
        }

        KgslGpuObjFreeReq free_req;
        memset(&free_req, 0, sizeof(free_req));
        free_req.id_low32 = (uint32_t)get_info.id;
        rc = ioctl(g_kgsl_fd, IOCTL_KGSL_GPUOBJ_FREE, &free_req);
        if (rc < 0) {
            __android_log_print(4, "hook_impl", "IOCTL_KGSL_GPUOBJ_FREE failed");
        }
        return 0;
    }

    return g_orig_gsl_free != NULL ? g_orig_gsl_free((uint64_t)handle) : 0;
}
