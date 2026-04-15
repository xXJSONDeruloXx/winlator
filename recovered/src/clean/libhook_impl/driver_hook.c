#include "driver_hook.h"
#include "hook_impl_core.h"
#include "loader_bridge.h"
#include "file_redirect.h"

#include <string.h>
#include <dlfcn.h>

#if defined(__has_include)
#  if __has_include(<android/log.h>)
#    include <android/log.h>
#  else
     extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#  endif
#else
  extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#endif

// Host-friendly fallback declaration when android_dlextinfo is only forward-declared.
extern void *android_dlopen_ext(const char *filename, int flags, const android_dlextinfo *info);

// Local layout used by hook_android_load_sphal_library when we need to materialize an
// android_dlextinfo-like payload without depending on the full Android header in host builds.
typedef struct HookAndroidDlextInfoCompat {
    uint64_t flags;
    void *reserved_addr;
    uint64_t reserved_size;
    int relro_fd;
    int library_fd;
    uint64_t library_fd_offset;
    void *library_namespace;
} HookAndroidDlextInfoCompat;

typedef void (*init_hook_param_fn)(uint64_t);
typedef void (*init_gsl_fn)(uint64_t, uint64_t, uint64_t);

// This file now carries the main driver interception control flow in first-pass form.

void *fallback_to_original_android_dlopen_ext(const char *filename, uint32_t flags,
                                              const android_dlextinfo *extinfo) {
    __android_log_print(4, "hook_impl", "hook_android_dlopen_ext: falling back!");
    return android_dlopen_ext(filename, (int)flags, extinfo);
}

void *hook_android_dlopen_ext(char *filename, uint32_t flags, uint64_t *extinfo_raw) {
    __android_log_print(4, "hook_impl", "hook_android_dlopen_ext: filename: %s", filename);

    // Non-Vulkan path: pass straight through.
    if (strstr(filename, "vulkan.") == NULL) {
        return android_dlopen_ext(filename, (int)flags, (const android_dlextinfo *)extinfo_raw);
    }

    android_dlextinfo *extinfo = (android_dlextinfo *)extinfo_raw;
    if (extinfo == NULL || extinfo->library_namespace == NULL ||
        (extinfo->flags & ANDROID_DLEXT_USE_NAMESPACE) == 0) {
        __android_log_print(4, "hook_impl",
                            "hook_android_dlopen_ext: hook failed: namespace not supplied!");
        return fallback_to_original_android_dlopen_ext(filename, flags, extinfo);
    }

    const char *namespace_name = g_hook_config ? string_like_to_cstr((uint64_t)&g_hook_config->namespace_name_raw[0]) : NULL;
    const char *namespace_search = g_hook_config ? string_like_to_cstr((uint64_t)&g_hook_config->namespace_search_raw[0]) : NULL;

    android_namespace_handle_t ns = android_create_namespace(
        (uint64_t)filename,
        (uint64_t)namespace_name,
        (uint64_t)namespace_search,
        2,
        0,
        (uint64_t)extinfo->library_namespace);

    if (ns == 0) {
        __android_log_print(4, "hook_impl",
                            "hook_android_dlopen_ext: hook failed: namespace not supplied!");
        return fallback_to_original_android_dlopen_ext(filename, flags, extinfo);
    }

    if (g_android_link_namespaces != NULL) {
        g_android_link_namespaces(ns, 0, "libandroid.so");
    }

    void *hook_impl_handle = (void *)linkernsbypass_namespace_dlopen((uint64_t)"libhook_impl.so", 2, ns);
    if (hook_impl_handle == NULL) {
        return NULL;
    }

    init_hook_param_fn init_param = (init_hook_param_fn)dlsym(hook_impl_handle, "init_hook_param");
    if (init_param == NULL) {
        return NULL;
    }
    init_param((uint64_t)g_hook_config);

    if (g_hook_config && (g_hook_config->flags & HOOK_FLAG_ENABLE_FILE_REDIRECT)) {
        void *fredirect = (void *)linkernsbypass_namespace_dlopen((uint64_t)"libfile_redirect_hook.so", 0x100, ns);
        if (fredirect == NULL) {
            __android_log_print(4, "hook_impl",
                                "hook_android_dlopen_ext: hook failed: failed to apply libfopen_redirect_hook!");
            return fallback_to_original_android_dlopen_ext(filename, flags, extinfo);
        }
        __android_log_print(4, "hook_impl",
                            "hook_android_dlopen_ext: applied libfile_redirect_hook");
    }

    HookAndroidDlextInfoCompat local_extinfo = {
        .flags = extinfo->flags,
        .reserved_addr = extinfo->reserved_addr,
        .reserved_size = extinfo->reserved_size,
        .relro_fd = extinfo->relro_fd,
        .library_fd = extinfo->library_fd,
        .library_fd_offset = extinfo->library_fd_offset,
        .library_namespace = (void *)ns,
    };

    if (g_hook_config && (g_hook_config->flags & HOOK_FLAG_ENABLE_GSL_HOOK)) {
        void *gsl_hook = (void *)linkernsbypass_namespace_dlopen((uint64_t)"libgsl_alloc_hook.so", 0x100, ns);
        if (gsl_hook == NULL) {
            __android_log_print(4, "hook_impl",
                                "hook_android_dlopen_ext: hook failed: failed to apply libgsl_alloc_hook!");
            return fallback_to_original_android_dlopen_ext(filename, flags, extinfo);
        }

        void *gsl_handle = android_dlopen_ext("vkbgsl.so", 2, (const android_dlextinfo *)&local_extinfo);
        if (gsl_handle == NULL) {
            gsl_handle = android_dlopen_ext("notgsl.so", 2, (const android_dlextinfo *)&local_extinfo);
            if (gsl_handle == NULL) {
                gsl_handle = android_dlopen_ext("libgsl.so", 2, (const android_dlextinfo *)&local_extinfo);
            }
        }

        if (gsl_handle != NULL) {
            g_orig_gsl_alloc32 = (gsl_alloc32_fn)dlsym(gsl_handle, "gsl_memory_alloc_pure");
            g_orig_gsl_alloc64 = (gsl_alloc64_fn)dlsym(gsl_handle, "gsl_memory_alloc_pure_64");
            g_orig_gsl_free = (gsl_free_fn)dlsym(gsl_handle, "gsl_memory_free_pure");

            if (((g_orig_gsl_alloc32 != NULL) || (g_orig_gsl_alloc64 != NULL)) && g_orig_gsl_free != NULL) {
                init_gsl_fn init_gsl_cb = (init_gsl_fn)dlsym(hook_impl_handle, "init_gsl");
                if (init_gsl_cb == NULL) {
                    return fallback_to_original_android_dlopen_ext(filename, flags, extinfo);
                }
                init_gsl_cb((uint64_t)g_orig_gsl_alloc32,
                            (uint64_t)g_orig_gsl_alloc64,
                            (uint64_t)g_orig_gsl_free);
                __android_log_print(4, "hook_impl",
                                    "hook_android_dlopen_ext: applied libgsl_alloc_hook");
                if (g_hook_config && g_hook_config->cached_gsl_alloc != NULL) {
                    ((uint64_t *)g_hook_config->cached_gsl_alloc)[1] = HOOK_GSL_CACHE_USED;
                }
            }
        }

        if (((g_orig_gsl_alloc32 == NULL) && (g_orig_gsl_alloc64 == NULL)) || g_orig_gsl_free == NULL) {
            __android_log_print(4, "hook_impl",
                                "hook_android_dlopen_ext: hook failed: failed to apply libgsl_alloc_hook!");
        }
    }

    if (g_hook_config == NULL || (g_hook_config->flags & HOOK_FLAG_USE_CUSTOM_DRIVER) == 0) {
        __android_log_print(4, "hook_impl",
                            "hook_android_dlopen_ext: loading default driver: %s", filename);
        return android_dlopen_ext(filename, (int)flags, (const android_dlextinfo *)&local_extinfo);
    }

    const char *driver_base = string_like_to_cstr((uint64_t)&g_hook_config->namespace_name_raw[0]);
    const char *custom_driver = string_like_to_cstr((uint64_t)&g_hook_config->custom_driver_path_raw[0]);
    __android_log_print(4, "hook_impl",
                        "hook_android_dlopen_ext: loading custom driver: %s%s",
                        driver_base, custom_driver);
    void *driver = android_dlopen_ext(custom_driver, (int)flags, (const android_dlextinfo *)&local_extinfo);
    if (driver == NULL) {
        const char *err = dlerror();
        __android_log_print(4, "hook_impl",
                            "hook_android_dlopen_ext: hook failed: failed to load custom driver: %s!",
                            err);
        return fallback_to_original_android_dlopen_ext(filename, flags, extinfo);
    }
    return driver;
}

uint64_t hook_android_load_sphal_library(uint64_t filename, uint32_t flags) {
    __android_log_print(4, "hook_impl", "hook_android_load_sphal_library: filename: %s", (const char *)filename);

    static const char *kExportedNamespaces[] = {
        "default",
        "vendor",
        "sphal",
    };

    for (size_t i = 0; i < sizeof(kExportedNamespaces) / sizeof(kExportedNamespaces[0]); ++i) {
        if (g_android_get_exported_namespace == NULL) {
            break;
        }
        void *ns = (void *)g_android_get_exported_namespace(kExportedNamespaces[i]);
        if (ns != NULL) {
            HookAndroidDlextInfoCompat extinfo = {
                .flags = ANDROID_DLEXT_USE_NAMESPACE,
                .reserved_addr = NULL,
                .reserved_size = 0,
                .relro_fd = 0,
                .library_fd = 0,
                .library_fd_offset = 0,
                .library_namespace = ns,
            };
            return (uint64_t)hook_android_dlopen_ext((char *)filename, flags, (uint64_t *)&extinfo);
        }
    }

    return 0;
}
