#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hook_impl_core.h"
#include "file_redirect.h"
#include "internals.h"

// Helpers to construct StringLikeObject inline/heap variants
static void init_inline_string(StringLikeObject *obj, const char *s) {
    size_t len = strlen(s);
    if (len > sizeof(obj->raw)-1) len = sizeof(obj->raw)-1;
    memset(obj->raw, 0, sizeof(obj->raw));
    obj->raw[0] = (uint8_t)(len << 1); // low bit clear => inline
    memcpy(&obj->raw[1], s, len);
    obj->raw[1+len] = '\0';
}

static void init_heap_string(StringLikeObject *obj, const char *s) {
    size_t len = strlen(s);
    char *buf = strdup(s);
    memset(obj->raw, 0, sizeof(obj->raw));
    obj->raw[0] = 1; // low bit set => heap
    *(uint64_t *)&obj->raw[8] = (uint64_t)len;
    *(char **)&obj->raw[0x10] = buf;
}

int main(void) {
    HookConfig cfg;
    memset(&cfg, 0, sizeof(cfg));

    // Prepare a redirect_map as a heap-style StringLikeObject prefix
    StringLikeObject *prefix = malloc(sizeof(StringLikeObject));
    init_inline_string(prefix, "/tmp/host-prefix/");

    cfg.redirect_map = prefix;
    g_hook_config = &cfg;

    char *out = build_redirected_path(cfg.redirect_map, "config.ini");
    if (out) {
        printf("build_redirected_path -> %s\n", out);
        free(out);
    } else {
        printf("build_redirected_path returned NULL\n");
    }

    // Test hook_fopen (will likely return NULL if file doesn't exist)
    FILE *f = hook_fopen("config.ini", "r");
    if (f) {
        printf("hook_fopen opened file via redirect\n");
        fclose(f);
    } else {
        printf("hook_fopen returned NULL as expected (file may not exist)\n");
    }

    free(prefix);
    return 0;
}
