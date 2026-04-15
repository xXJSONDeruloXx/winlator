#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t hook_gsl_memory_alloc_pure_64(unsigned long size, uint32_t flags, uint64_t *out);
uint32_t hook_gsl_memory_free_pure(long handle);

#ifdef __cplusplus
}
#endif
