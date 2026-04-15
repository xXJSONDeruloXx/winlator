/*
 * gladio_data.h — .rodata constant declarations for libgladiorenderer
 *
 * These DAT_* symbols correspond to read-only data in the original binary's
 * .rodata section. Most are string constants, EGL config arrays, or lookup tables.
 * The actual values are defined in gladio_data.c.
 *
 * TODO: As the code is progressively cleaned, replace DAT_ references with
 * meaningful named constants.
 */
#pragma once

#include <stdint.h>

/* String constants — used as format strings, shader fragments, etc. */
extern const char DAT_00110b5e[4096];
extern const char DAT_00110d39[4096];
extern const char DAT_00111039[4096];
extern const char DAT_00111054[4096];
extern const char DAT_001110e2[4096];
extern const char DAT_001111f5[4096];
extern const char DAT_00111326[4096];
extern const char DAT_001116af[4096];
extern const char DAT_00111f3c[4096];
extern const char DAT_00112088[4096];
extern const char DAT_00112166[4096];
extern const char DAT_001121dc[4096];
extern const char DAT_001122d0[4096];
extern const char DAT_001147e7[4096];
extern const char DAT_001148af[4096];
extern const char DAT_001148b2[4096];
extern const char DAT_00114915[4096];
extern const char DAT_001149fb[4096];
extern const char DAT_00114adf[4096];
extern const char DAT_00114aee[4096];
extern const char DAT_00114b12[4096];
extern const char DAT_001152c2[4096];
extern const char DAT_001153a1[4096];

/* EGL config/context attribute arrays */
extern const int32_t DAT_00115688[4096];  /* eglChooseConfig attribs */
extern const int32_t DAT_001156b4[4096];  /* eglCreateContext attribs */

/* Lookup tables (GL format/type mapping) */
extern const int32_t DAT_001156c0[4096];
extern const int32_t DAT_00115740[4096];
extern const int32_t DAT_00115760[4096];
extern const int32_t DAT_001159d8[4096];
extern const uint8_t DAT_00115a20[4096];
extern const uint8_t DAT_00115a30[4096];
extern const uint8_t DAT_00115a80[4096];
extern const uint8_t DAT_00115f44[4096];

/* Data tables for texture compression, format queries, etc. */
extern const uint8_t DAT_001161f7[4096];
extern const uint8_t DAT_00116798[4096];
extern const uint8_t DAT_0011683c[4096];

/* SparseArray/container storage globals */
extern uint64_t DAT_00144ee0;
extern uint64_t DAT_00144ee8;
extern uint64_t DAT_00144eec;
extern uint64_t DAT_00144ef0;
extern uint64_t DAT_00144ef4;
extern uint64_t DAT_00144ef8;
extern uint64_t DAT_00144efc;
extern uint64_t DAT_00144f00;
extern uint64_t DAT_00144f04;
extern uint64_t DAT_00144f08;
extern uint64_t DAT_00144f0c;
extern uint64_t DAT_00144f10;
extern uint64_t DAT_00144f14;
extern uint64_t DAT_00144f18;
extern uint64_t DAT_00144f1c;
extern uint64_t DAT_00144f20;
extern uint64_t DAT_00144f28;
extern uint64_t DAT_00145140;
extern uint64_t DAT_00145148;

/*
 * Internal function forward declarations (FUN_* from Ghidra)
 * NOT declared here — these are defined and called within
 * gladio_internal_funcs.c and other module files.
 * Using -Wno-implicit-function-declaration for cross-file calls.
 */

/* Linker loop pointer (function dispatch in shader converter) */
extern void *PTR_LOOP_00141df0;
extern void *PTR_s_gl_Color_00141df8;
extern void *PTR_DAT_00141ff8;
extern void *PTR_s_program_env_001420e0;
extern void *PTR_s_gd_ProgramEnv_001420e8;

extern uint64_t DAT_00144f24;
extern const uint8_t DAT_001167ac[4096];

/* UNK_ references */
extern uint8_t UNK_0013c5a0;

/* Additional auto-discovered declarations */
extern const uint8_t DAT_00116216[4096];
extern const uint8_t DAT_00116217[4096];
extern const uint8_t DAT_00116416[4096];
extern const uint8_t DAT_00116417[4096];
extern const uint8_t DAT_00116618[4096];
extern const uint8_t DAT_00116698[4096];
extern uint64_t DAT_00141e0c;
extern uint64_t DAT_00144118;
extern uint64_t DAT_00144f38;
extern uint64_t DAT_00144f3c;
extern uint8_t UNK_00141e00;
extern uint8_t UNK_00141e08;
