#pragma once

#include <stdint.h>
#include <stdbool.h>
#if defined(__has_include)
#  if __has_include(<android/dlext.h>)
#    include <android/dlext.h>
#  else
     struct android_namespace_t;
     typedef struct android_dlextinfo {
         uint64_t flags;
         void *reserved_addr;
         uint64_t reserved_size;
         int relro_fd;
         int library_fd;
         uint64_t library_fd_offset;
         struct android_namespace_t *library_namespace;
     } android_dlextinfo;
#  endif
#else
  struct android_namespace_t;
  typedef struct android_dlextinfo {
      uint64_t flags;
      void *reserved_addr;
      uint64_t reserved_size;
      int relro_fd;
      int library_fd;
      uint64_t library_fd_offset;
      struct android_namespace_t *library_namespace;
  } android_dlextinfo;
#endif

#ifdef __cplusplus
extern "C" {
#endif

// -----------------------------------------------------------------------------
// First-pass inferred constants
// -----------------------------------------------------------------------------

enum HookConfigFlags {
    HOOK_FLAG_USE_CUSTOM_DRIVER   = 1u << 0,
    HOOK_FLAG_ENABLE_FILE_REDIRECT= 1u << 1,
    HOOK_FLAG_ENABLE_GSL_HOOK     = 1u << 2,
};

enum HookGslMarkers {
    HOOK_GSL_ALLOC_MARKER = 0xdeadb33f,
    HOOK_GSL_CACHE_USED   = 0xdeadbeef,
};

// KGSL ioctls observed in hook_gsl_memory_free_pure.
#define IOCTL_KGSL_GPUMEM_GET_INFO 0xc0480936u
#define IOCTL_KGSL_GPUOBJ_FREE     0x40200946u

// Namespace load flag observed in linkernsbypass_namespace_dlopen.
#define ANDROID_DLEXT_USE_NAMESPACE 0x00000200u
// Unique namespace load path uses 0x210 (= namespace + use library fd offset semantics).
#define ANDROID_DLEXT_USE_NAMESPACE_UNIQUE 0x00000210u

// -----------------------------------------------------------------------------
// Opaque / inferred types
// -----------------------------------------------------------------------------

typedef uint64_t android_namespace_handle_t;

typedef struct StringLikeObject {
    // Opaque std::string-like object. Accessed through helper functions;
    // exact layout still TBD.
    uint8_t raw[24];
} StringLikeObject;

typedef struct StringArrayRef {
    uint64_t begin;
    uint64_t count;
} StringArrayRef;

typedef struct HookConfig {
    uint64_t flags;                     // +0x00
    uint8_t  unknown_08[0x18];
    uint8_t  namespace_search_raw[0x18]; // +0x20 string-like object (opaque)
    uint8_t  namespace_name_raw[0x18];   // +0x38 string-like object (opaque)
    uint8_t  custom_driver_path_raw[0x18]; // +0x50 string-like object (opaque)
    void    *redirect_map;              // +0x68 container type still TBD
    uint8_t  unknown_70[0x10];
    void    *cached_gsl_alloc;          // +0x80
} HookConfig;

typedef struct CachedGslAlloc {
    uint64_t q0;
    uint64_t q1;
    uint64_t requested_size;       // +0x10
    uint64_t required_flags_mask;  // +0x18
    uint64_t marker;               // +0x20
} CachedGslAlloc;

// First-pass view of the 5-qword record copied into GSL alloc outputs.
typedef struct GslAllocRecord {
    uint64_t q0;
    uint64_t q1;
    uint64_t q2;
    uint64_t q3;
    uint64_t marker;
} GslAllocRecord;

// First-pass opaque structs for the two KGSL ioctls used by the GSL free hook.
// Only the touched fields are represented explicitly; the rest are preserved as padding.
typedef struct KgslGpuMemGetInfoReq {
    uint64_t gpuaddr;      // initialized from handle + 8
    uint64_t flags;        // left zeroed in recovered logic
    uint64_t size;         // output / scratch
    uint64_t mmapsize;     // output / scratch
    uint64_t useraddr;     // output / scratch
    uint64_t id;           // low 32 bits later copied into free request
    uint64_t metadata[2];  // preserves overall shape of the zeroed stack object
} KgslGpuMemGetInfoReq;

typedef struct KgslGpuObjFreeReq {
    uint64_t flags0;
    uint64_t flags1;
    uint64_t id_low32;     // populated from get-info request
} KgslGpuObjFreeReq;

// -----------------------------------------------------------------------------
// Hidden Android loader bridge function pointers
// -----------------------------------------------------------------------------

typedef uint32_t (*android_link_namespaces_all_libs_fn)(android_namespace_handle_t from_ns,
                                                        android_namespace_handle_t to_ns);
typedef uint32_t (*android_link_namespaces_fn)(android_namespace_handle_t from_ns,
                                               android_namespace_handle_t to_ns,
                                               const char *shared_libs);
typedef android_namespace_handle_t (*loader_android_create_namespace_fn)(
    const char *name,
    const char *ld_library_path,
    const char *default_library_path,
    uint64_t type,
    const char *permitted_when_isolated_path,
    android_namespace_handle_t parent_namespace);
typedef android_namespace_handle_t (*android_get_exported_namespace_fn)(const char *name);

// GSL trampoline originals loaded from vkbgsl.so / notgsl.so / libgsl.so.
typedef uint32_t (*gsl_alloc32_fn)(uint32_t size, uint32_t flags, uint64_t *out);
typedef uint32_t (*gsl_alloc64_fn)(uint64_t size, uint32_t flags, uint64_t *out);
typedef uint32_t (*gsl_free_fn)(uint64_t handle);

// -----------------------------------------------------------------------------
// Named replacements for key DAT_ globals from the raw decompile
// -----------------------------------------------------------------------------

extern HookConfig *g_hook_config;
extern gsl_alloc32_fn g_orig_gsl_alloc32;
extern gsl_alloc64_fn g_orig_gsl_alloc64;
extern gsl_free_fn g_orig_gsl_free;
extern int g_kgsl_fd;
extern bool g_loader_bridge_ready;
extern bool g_cpu_quirk_enabled;
extern android_namespace_handle_t g_default_copy_namespace;
extern android_link_namespaces_all_libs_fn g_android_link_namespaces_all_libs;
extern android_link_namespaces_fn g_android_link_namespaces;
extern loader_android_create_namespace_fn g_android_create_namespace_impl;
extern android_get_exported_namespace_fn g_android_get_exported_namespace;

#ifdef __cplusplus
}
#endif
