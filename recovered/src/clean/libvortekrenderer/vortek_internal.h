/*
 * vortek_internal.h — Internal declarations for libvortekrenderer
 *
 * Minimal headers. libwinlator and Vulkan functions use implicit declarations
 * resolved at link time. Compilation uses -Wno-implicit-function-declaration.
 */
#pragma once

#include "vortek_types.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <dlfcn.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <android/log.h>
#include <android/hardware_buffer.h>
#include <pthread.h>
#include <dirent.h>
#include <sched.h>
#include <math.h>

/* Forward declarations for cross-module functions */
extern void vortekSerializerCastVkObject();
extern void FUN_00163868();
extern void FUN_001641ec();
extern void FUN_0015ecb0();

/* Command dispatch table */
extern VortekHandler vortek_dispatch_table[VORTEK_OPCODE_COUNT];
