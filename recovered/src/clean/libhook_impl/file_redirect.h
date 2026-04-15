#pragma once

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

char *string_like_to_cstr(uint64_t string_like_obj);
size_t string_like_length(uint64_t string_like_obj);
uint64_t string_array_begin(uint64_t *pair);
long string_array_end(long *pair);
char *build_redirected_path(void *redirect_map, const char *original_path);
FILE *hook_fopen(char *path, char *mode);

#ifdef __cplusplus
}
#endif
