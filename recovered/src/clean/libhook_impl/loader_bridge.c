#include "loader_bridge.h"
#include "hook_impl_core.h"

#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <stdio.h>
#if defined(__has_include)
#  if __has_include(<sys/auxv.h>)
#    include <sys/auxv.h>
#  else
     static inline unsigned long getauxval(unsigned long type) { (void)type; return 0; }
#    ifndef AT_HWCAP
#      define AT_HWCAP 16
#    endif
#  endif
#else
   static inline unsigned long getauxval(unsigned long type) { (void)type; return 0; }
#  ifndef AT_HWCAP
#    define AT_HWCAP 16
#  endif
#endif

#if defined(__has_include)
#  if __has_include(<android/log.h>)
#    include <android/log.h>
#  else
     extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
     extern int __system_property_get(const char *name, char *value);
#  endif
#else
  extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
  extern int __system_property_get(const char *name, char *value);
#endif

extern void *android_dlopen_ext(const char *filename, int flags, const android_dlextinfo *info);

// This file is intentionally a structured landing zone for the exact logic
// documented in LOGIC.md. Several small helper bodies have now been transplanted
// directly from the recovered decompile; larger bootstrap routines still remain TODO.

int get_android_sdk_int(void) {
    char sdk_str[104] = {0};
    int rc = __system_property_get("ro.build.version.sdk", sdk_str);
    if (rc < 1) {
        return -1;
    }
    int sdk = atoi(sdk_str);
    if (sdk < 1) {
        sdk = -1;
    }
    return sdk;
}

uint64_t page_align_down(uint64_t addr) {
    int page_size = getpagesize();
    return addr & (uint64_t)~((uint32_t)page_size - 1u);
}

bool is_unconditional_branch_insn(uint32_t *insn) {
    return ((*insn) >> 26) == 0x25;
}

void *find_loader_entry_via_dlopen_branch_scan(void) {
    // First-pass near-exact transplant of FUN_00120f84.
    // This scans forward from dlopen until it finds an AArch64 unconditional B,
    // then returns the branch target.
    uint32_t *page = (uint32_t *)page_align_down((uint64_t)dlopen);
    int page_size = getpagesize();
    mprotect(page, (size_t)page_size, PROT_READ | PROT_WRITE | PROT_EXEC);

    uint32_t *cur = (uint32_t *)dlopen;
    while (!is_unconditional_branch_insn(cur)) {
        cur += 4;
    }
    int32_t imm26 = ((int32_t)(*cur << 6)) >> 6;
    return cur + imm26 * 4;
}

void init_loader_bridge_symbols(void) {
    // Attempt to locate the system loader bridge by scanning forward from dlopen
    // and calling the discovered loader entry to obtain loader-owned handles for
    // ld-android.so and libdl_android.so. On success, resolve the hidden
    // __loader_* symbols and mark the bridge ready.

    void *entry = find_loader_entry_via_dlopen_branch_scan();
    if (entry == NULL) {
        return;
    }

    // Make the page writable/executable like the original did when patching.
    void *page = (void *)page_align_down((uint64_t)entry);
    int ps = getpagesize();
    mprotect(page, (size_t)ps, PROT_READ | PROT_WRITE | PROT_EXEC);

    typedef void *(*loader_entry_fn)(const char *name, int flags, void *dlopen_fn);
    loader_entry_fn loader = (loader_entry_fn)entry;

    void *ld_handle = NULL;
    void *dl_handle = NULL;

    // Call the loader entry to open ld-android.so and libdl_android.so in loader context.
    // The hardcoded flag '1' and passing dlopen mirrors the recovered binary.
    ld_handle = loader("ld-android.so", 1, (void *)dlopen);
    if (ld_handle != NULL) {
        g_android_link_namespaces_all_libs = (android_link_namespaces_all_libs_fn)dlsym(ld_handle, "__loader_android_link_namespaces_all_libs");
        g_android_link_namespaces = (android_link_namespaces_fn)dlsym(ld_handle, "__loader_android_link_namespaces");
    }

    dl_handle = loader("libdl_android.so", 1, (void *)dlopen);
    if (dl_handle != NULL) {
        g_android_create_namespace_impl = (loader_android_create_namespace_fn)dlsym(dl_handle, "__loader_android_create_namespace");
        g_android_get_exported_namespace = (android_get_exported_namespace_fn)dlsym(dl_handle, "__loader_android_get_exported_namespace");
    }

    if (g_android_link_namespaces_all_libs != NULL && g_android_link_namespaces != NULL &&
        g_android_create_namespace_impl != NULL && g_android_get_exported_namespace != NULL) {
        g_loader_bridge_ready = true;
    }
}

void init_cpu_quirk_flags(void) {
    // Heuristic transplant of _INIT_1: check HWCAP-like bits and system property
    unsigned long hwcap = getauxval(AT_HWCAP);
    bool enabled = false;

    // original checks (shift/right tests) are approximated here; we follow the
    // decompiled intent: if a particular hwcap bit is present, consult ro.arch string
    if (((uint32_t)(hwcap >> 8) & 1u) != 0) {
        char arch[128] = {0};
        int rc = __system_property_get("ro.arch", arch);
        uint32_t candidate = (uint32_t)(hwcap >> 8);
        if (rc < 1) {
            enabled = (candidate & 1u) != 0;
        } else {
            if (strncmp(arch, "exynos9810", 10) != 0) {
                enabled = (candidate & 1u) != 0;
            } else {
                enabled = false;
            }
        }
    } else {
        enabled = false;
    }

    g_cpu_quirk_enabled = enabled;
}

uint64_t android_create_namespace(uint64_t name, uint64_t ld_library_path,
                                  uint64_t default_library_path, uint64_t type,
                                  uint64_t permitted_when_isolated_path,
                                  uint64_t parent_namespace) {
    if (g_android_create_namespace_impl == NULL) {
        return 0;
    }
    return g_android_create_namespace_impl((const char *)name,
                                           (const char *)ld_library_path,
                                           (const char *)default_library_path,
                                           type,
                                           (const char *)permitted_when_isolated_path,
                                           parent_namespace);
}

uint64_t android_create_namespace_escape(uint64_t name, uint64_t ld_library_path,
                                         uint64_t default_library_path, uint64_t type,
                                         uint64_t permitted_when_isolated_path,
                                         uint64_t parent_namespace) {
    // The recovered raw binary uses a slightly different final register/call context here.
    // For now, route through the same loader hook entrypoint until the exact call convention
    // is transplanted.
    return android_create_namespace(name,
                                    ld_library_path,
                                    default_library_path,
                                    type,
                                    permitted_when_isolated_path,
                                    parent_namespace);
}

uint32_t linkernsbypass_link_namespace_to_default_all_libs(uint64_t namespace_handle) {
    // TODO: preserve exact one-time default_copy namespace creation semantics.
    if (g_android_link_namespaces_all_libs == NULL) {
        return 0;
    }
    return g_android_link_namespaces_all_libs(namespace_handle, g_default_copy_namespace) & 1u;
}

uint8_t linkernsbypass_load_status(void) {
    return g_loader_bridge_ready ? 1 : 0;
}

uint64_t linkernsbypass_namespace_dlopen(uint64_t path, uint32_t flags, uint64_t namespace_handle) {
    android_dlextinfo extinfo;
    memset(&extinfo, 0, sizeof(extinfo));
    extinfo.flags = ANDROID_DLEXT_USE_NAMESPACE;
    extinfo.library_namespace = (struct android_namespace_t *)namespace_handle;
    return (uint64_t)android_dlopen_ext((const char *)path, (int)flags, &extinfo);
}

uint64_t linkernsbypass_namespace_dlopen_unique(uint64_t path, uint64_t soname,
                                                uint32_t flags, uint64_t namespace_handle) {
    // Conservative, practical transplant of the original behavior: open the file path,
    // construct a /proc/self/fd/<fd> path, and call android_dlopen_ext with
    // ANDROID_DLEXT_USE_NAMESPACE_UNIQUE and library_fd set. This avoids reimplementing
    // the full SONAME-patching logic while matching the loader's unique-FD load path.
    if (path == 0) return 0;

    const char *p = (const char *)path;
    int fd = open(p, O_RDONLY | O_CLOEXEC);
    if (fd < 0) {
        // Could not open the file — fall back to non-unique namespace load
        return linkernsbypass_namespace_dlopen(path, flags, namespace_handle);
    }

    char procpath[64];
    snprintf(procpath, sizeof(procpath), "/proc/self/fd/%d", fd);

    android_dlextinfo extinfo;
    memset(&extinfo, 0, sizeof(extinfo));
    extinfo.flags = ANDROID_DLEXT_USE_NAMESPACE_UNIQUE;
    extinfo.library_fd = fd;
    extinfo.library_fd_offset = 0;
    extinfo.library_namespace = (struct android_namespace_t *)namespace_handle;

    uint64_t handle = (uint64_t)android_dlopen_ext(procpath, (int)flags, &extinfo);

    // Close FD after loading attempt — loader is expected to duplicate/consume fd if needed.
    close(fd);
    return handle;
}
