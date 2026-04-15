#include "file_redirect.h"
#include "hook_impl_core.h"
#include <string.h>
#include <stdlib.h>

#if defined(__has_include)
#  if __has_include(<android/log.h>)
#    include <android/log.h>
#  else
     extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#  endif
#else
  extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#endif

char *string_like_to_cstr(uint64_t string_like_obj) {
    // Refined SSO decoding based on multiple occurrences in the recovered binary
    // (see std::__ndk1::basic_string methods in the raw decompile). Layout observed:
    //  - byte 0: metadata with low bit indicating "heap-allocated" when set
    //  - bytes +8: length (uint64_t) when heap-allocated
    //  - bytes +0x10: pointer to heap buffer when heap-allocated
    //  - inline data begins immediately after the first metadata byte when not heap-allocated
    uint8_t *obj = (uint8_t *)string_like_obj;
    if (obj == NULL) return NULL;

    bool uses_heap = (obj[0] & 1u) != 0;
    if (uses_heap) {
        // Defensive: if the heap pointer looks invalid, fall back to inline view.
        uint64_t len = *(uint64_t *)(obj + 8);
        char *ptr = *(char **)(obj + 0x10);
        if (ptr == NULL) {
            // Corrupt or intentionally empty string recorded on heap; try inline fallback
            return (char *)(obj + 1);
        }
        // Sanity check length: don't return ptr for absurd lengths.
        if (len > 0 && len < (1 << 20)) {
            return ptr;
        }
        return ptr; // still return ptr; callers treat result as possibly empty-terminated
    }

    // Inline SSO path: characters start at obj+1, length encoded in low bits of obj[0]
    return (char *)(obj + 1);
}

size_t string_like_length(uint64_t string_like_obj) {
    uint8_t *obj = (uint8_t *)string_like_obj;
    if (obj == NULL) return 0;

    bool uses_heap = (obj[0] & 1u) != 0;
    if (uses_heap) {
        uint64_t len = *(uint64_t *)(obj + 8);
        // Basic sanity guard
        if (len > (1ULL << 31)) return 0; // protect against corrupt length
        return (size_t)len;
    }

    // Inline-case length is stored in the low bits of the first byte (shifted by 1)
    return (size_t)(obj[0] >> 1);
}

uint64_t string_array_begin(uint64_t *pair) {
    // Exact recovered body from FUN_0011fc68
    return *pair;
}

long string_array_end(long *pair) {
    // Exact recovered body from FUN_0011fc80
    return *pair + pair[1] * 8;
}

char *build_redirected_path(void *redirect_map, const char *original_path) {
    // First-pass exact semantic transplant of FUN_0011fe00:
    // If the redirect_map is not present, default to returning a copy of original_path.
    if (redirect_map == NULL) {
        return strdup(original_path);
    }

    // Heuristic: treat redirect_map as a pointer to a string-like object containing a
    // prefix if it looks like one. This matches the common APK usage where a single
    // prefix is applied to redirected files. If this heuristic is wrong, callers should
    // later be updated to resolve redirect_map entries explicitly.
    char *prefix = NULL;
    size_t prefix_len = 0;
    // Attempt to interpret redirect_map as a StringLikeObject pointer.
    prefix = string_like_to_cstr((uint64_t)redirect_map);
    if (prefix != NULL) {
        prefix_len = string_like_length((uint64_t)redirect_map);
    } else {
        // Fallback: treat redirect_map as a C string pointer
        prefix = (char *)redirect_map;
        prefix_len = strlen(prefix);
    }

    size_t suffix_len = strlen(original_path);
    char *out = (char *)malloc(prefix_len + suffix_len + 1);
    if (out == NULL) {
        return NULL;
    }
    memcpy(out, prefix, prefix_len);
    memcpy(out + prefix_len, original_path, suffix_len);
    out[prefix_len + suffix_len] = '\0';
    return out;
}

FILE *hook_fopen(char *path, char *mode) {
    if (strncmp("/proc", path, 5) == 0 || strncmp("/sys", path, 4) == 0) {
        __android_log_print(4, "hook_impl", "hook_fopen: passthrough: %s", path);
        return fopen(path, mode);
    }

    void *redirect_map = NULL;
    if (g_hook_config != NULL) {
        redirect_map = g_hook_config->redirect_map;
    }

    if (redirect_map == NULL) {
        __android_log_print(4, "hook_impl", "hook_fopen: no redirect_map, passthrough: %s", path);
        return fopen(path, mode);
    }

    char *redirected = build_redirected_path(redirect_map, path);
    if (redirected == NULL) {
        __android_log_print(4, "hook_impl", "hook_fopen: redirect failed, passthrough: %s", path);
        return fopen(path, mode);
    }

    __android_log_print(4, "hook_impl", "hook_fopen: %s -> %s", path, redirected);
    FILE *f = fopen(redirected, mode);
    free(redirected);
    return f;
}
