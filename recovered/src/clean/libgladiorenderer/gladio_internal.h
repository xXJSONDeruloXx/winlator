/*
 * gladio_internal.h — Internal declarations for libgladiorenderer
 *
 * Provides common headers and forward declarations.
 * libwinlator container functions are resolved at link time (implicit declarations).
 */
#pragma once

#include "gladio_types.h"
#include <GLES3/gl32.h>
#include <EGL/egl.h>
#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/uio.h>
#include <android/log.h>
#include <pthread.h>
#include <stdio.h>

/*
 * libwinlator container functions are NOT declared here.
 * They have varying calling conventions in the Ghidra decompile output
 * (e.g., ArrayList_free takes 1 or 2 args depending on context).
 * They are resolved at link time against libwinlator.so.
 * Compilation uses -Wno-implicit-function-declaration.
 */

/* ── Command dispatch table ────────────────────────────────────────────────── */
extern GladioHandler gladio_dispatch_table[GLADIO_OPCODE_COUNT];
