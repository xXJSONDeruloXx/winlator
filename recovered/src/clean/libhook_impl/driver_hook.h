#pragma once

#include <stdint.h>
#include "internals.h"

#ifdef __cplusplus
extern "C" {
#endif

void *fallback_to_original_android_dlopen_ext(const char *filename, uint32_t flags,
                                              const android_dlextinfo *extinfo);
void *hook_android_dlopen_ext(char *filename, uint32_t flags, uint64_t *extinfo_raw);
uint64_t hook_android_load_sphal_library(uint64_t filename, uint32_t flags);

#ifdef __cplusplus
}
#endif
