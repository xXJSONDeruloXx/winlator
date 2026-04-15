#include "loader_bridge.h"
#include "hook_impl_core.h"

#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dlfcn.h>
#include <fcntl.h>
#include <stdio.h>
#include <pthread.h>
#if defined(__has_include) && __has_include(<sys/syscall.h>)
#  include <sys/syscall.h>
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

// One-time creation of the "default_copy" namespace used as the link target.
// The original binary uses __cxa_guard_acquire/release for this; we use pthread_once.
static void _create_default_copy_ns(void) {
    g_default_copy_namespace = android_create_namespace_escape(
        (uint64_t)"default_copy", 0, 0, 2, 0, 0);
}

uint32_t linkernsbypass_link_namespace_to_default_all_libs(uint64_t namespace_handle) {
    static pthread_once_t once = PTHREAD_ONCE_INIT;
    pthread_once(&once, _create_default_copy_ns);
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

uint8_t elf_soname_patch(const char *path, int dest_fd, const char *new_soname) {
    // Exact transplant of the elf_soname_patch export from the recovered binary.
    // Copies the ELF file at `path` into the already-opened writable `dest_fd` and
    // patches the DT_SONAME entry in the .dynamic section to `new_soname` (written
    // byte-by-byte up to the length of the shorter of the two strings).
    // Returns 1 on success, 0 on failure.
    if (!path || !new_soname) return 0;

    struct stat st;
    memset(&st, 0, sizeof(st));
    if (stat(path, &st) != 0) return 0;

    if (ftruncate(dest_fd, st.st_size) == -1) return 0;

    void *map = mmap(NULL, (size_t)st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, dest_fd, 0);
    if (map == MAP_FAILED) return 0;

    int src_fd = open(path, O_RDONLY);
    if (src_fd < 0) return 0;

    ssize_t nread = read(src_fd, map, (size_t)st.st_size);
    close(src_fd);
    if ((uint64_t)nread != (uint64_t)st.st_size) return 0;

    // Parse ELF64 section headers to find SHT_DYNAMIC and DT_SONAME.
    uint8_t *elf = (uint8_t *)map;
    uint64_t sh_off = *(uint64_t *)(elf + 0x28);   // e_shoff
    uint16_t sh_num = *(uint16_t *)(elf + 0x3c);   // e_shnum

    uint8_t result = 0;
    for (uint16_t i = 0; i < sh_num; i++) {
        uint8_t *shdr = elf + sh_off + (uint64_t)i * 0x40;
        uint32_t sh_type = *(uint32_t *)(shdr + 0x04);
        if (sh_type != 6) continue; // SHT_DYNAMIC = 6

        uint64_t sh_entsize = *(uint64_t *)(shdr + 0x38);
        if (sh_entsize == 0) continue;
        uint64_t sh_size    = *(uint64_t *)(shdr + 0x20);
        uint64_t sh_offset  = *(uint64_t *)(shdr + 0x18);
        uint32_t sh_link    = *(uint32_t *)(shdr + 0x28); // index of .dynstr
        uint64_t num_dyn    = sh_size / sh_entsize;

        for (uint64_t j = 0; j < num_dyn; j++) {
            int64_t *dyn = (int64_t *)(elf + sh_offset + j * 0x10);
            if (dyn[0] != 0xe) continue; // DT_SONAME

            // dyn[1] = offset of the SONAME string within .dynstr
            uint8_t *dynstr_shdr = elf + sh_off + (uint64_t)sh_link * 0x40;
            uint64_t dynstr_off  = *(uint64_t *)(dynstr_shdr + 0x18);
            char *soname_ptr     = (char *)(elf + dynstr_off + (uint64_t)dyn[1]);

            // Patch byte-by-byte, up to min(strlen(orig), strlen(new_soname))
            size_t k = 0;
            while (soname_ptr[k] != '\0' && new_soname[k] != '\0') {
                soname_ptr[k] = new_soname[k];
                k++;
            }
            result = 1;
            goto done;
        }
    }
done:
    return result;
}

uint64_t linkernsbypass_namespace_dlopen_unique(uint64_t path, uint64_t soname,
                                                uint32_t flags, uint64_t namespace_handle) {
    // Exact transplant of the original behavior:
    // 1. Create a writable fd (temp file) to hold a patched copy of the library.
    // 2. Call elf_soname_patch to copy the source ELF and patch the DT_SONAME entry
    //    with the requested soname, making the load appear unique to the linker.
    // 3. Load via /proc/self/fd/<fd> with ANDROID_DLEXT_USE_NAMESPACE | USE_LIBRARY_FD.
    if (path == 0) return 0;

    const char *p       = (const char *)path;
    const char *sname   = soname ? (const char *)soname : "";

    // Create a writable fd: prefer an anonymous memfd, fall back to a temp file.
    int dest_fd = -1;
#if defined(__NR_memfd_create)
    dest_fd = (int)syscall(__NR_memfd_create, sname, 0);
#endif
    // Temp-file fallback (matches the binary's non-memfd path).
    char tmppath[128] = {0};
    if (dest_fd < 0) {
        snprintf(tmppath, sizeof(tmppath), "/data/local/tmp/hook_%p_patched.so", (void *)path);
        dest_fd = open(tmppath, O_RDWR | O_CREAT | O_TRUNC, 0600);
    }
    if (dest_fd < 0) {
        // Could not create a writable fd — fall back to non-unique namespace load
        return linkernsbypass_namespace_dlopen(path, flags, namespace_handle);
    }

    uint8_t ok = elf_soname_patch(p, dest_fd, sname);
    if (!ok) {
        close(dest_fd);
        if (tmppath[0]) unlink(tmppath);
        return 0;
    }

    char procpath[64];
    snprintf(procpath, sizeof(procpath), "/proc/self/fd/%d", dest_fd);

    // flags = ANDROID_DLEXT_USE_NAMESPACE (0x200) | ANDROID_DLEXT_USE_LIBRARY_FD (0x10)
    android_dlextinfo extinfo;
    memset(&extinfo, 0, sizeof(extinfo));
    extinfo.flags = ANDROID_DLEXT_USE_NAMESPACE_UNIQUE; // 0x210
    extinfo.library_fd = dest_fd;
    extinfo.library_fd_offset = 0;
    extinfo.library_namespace = (struct android_namespace_t *)namespace_handle;

    uint64_t handle = (uint64_t)android_dlopen_ext(procpath, (int)flags, &extinfo);

    close(dest_fd);
    if (tmppath[0]) unlink(tmppath);
    return handle;
}
