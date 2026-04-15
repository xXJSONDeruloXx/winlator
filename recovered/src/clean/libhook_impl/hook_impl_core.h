#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include "internals.h"

#ifdef __cplusplus
extern "C" {
#endif

void init_hook_param(uint64_t hook_config_ptr);
void init_gsl(uint64_t alloc32, uint64_t alloc64, uint64_t free_fn);

#ifdef __cplusplus
}
#endif
