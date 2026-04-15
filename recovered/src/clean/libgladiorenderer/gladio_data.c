/*
 * gladio_data.c — .rodata constant definitions for libgladiorenderer
 *
 * Placeholder values for DAT_* symbols. Many of these are string constants
 * that will be replaced with actual values as reverse engineering progresses.
 * For now, they provide linkable symbols so the rest of the code compiles.
 */
#include "gladio_data.h"
#include <stdint.h>

/* String constants — placeholder values (actual strings from binary TBD) */
const char DAT_00110b5e[] = "";      /* shader fragment */
const char DAT_00110d39[] = "";      /* shader fragment */
const char DAT_00111039[] = "";      /* shader string */
const char DAT_00111054[] = "";      /* strcat fragment */
const char DAT_001110e2[] = "";      /* format string arg */
const char DAT_001111f5[] = "";      /* strcat fragment */
const char DAT_00111326[] = "";      /* shader string */
const char DAT_001116af[] = "";      /* format string */
const char DAT_00111f3c[] = "";      /* JNI method sig */
const char DAT_00112088[] = "";      /* strcat fragment */
const char DAT_00112166[] = "";      /* strcat fragment */
const char DAT_001121dc[] = "";      /* uniform name fragment */
const char DAT_001122d0[] = "";      /* shader string */
const char DAT_001147e7[] = "";      /* shader string */
const char DAT_001148af[] = "";      /* shader string */
const char DAT_001148b2[] = "";      /* format string */
const char DAT_00114915[] = "";      /* shader string */
const char DAT_001149fb[] = "";      /* shader string */
const char DAT_00114adf[] = "";      /* strcat fragment */
const char DAT_00114aee[] = "";      /* shader string */
const char DAT_00114b12[] = "";      /* format string */
const char DAT_001152c2[] = "";      /* uniform name fragment */
const char DAT_001153a1[] = "";      /* format string */

/* EGL config attributes for eglChooseConfig */
const int32_t DAT_00115688[] = {
    0x3024, 8,    /* EGL_RED_SIZE 8 */
    0x3023, 8,    /* EGL_GREEN_SIZE 8 */
    0x3022, 8,    /* EGL_BLUE_SIZE 8 */
    0x3021, 8,    /* EGL_ALPHA_SIZE 8 */
    0x3025, 24,   /* EGL_DEPTH_SIZE 24 */
    0x3026, 8,    /* EGL_STENCIL_SIZE 8 */
    0x3038        /* EGL_NONE */
};

/* EGL context attributes for eglCreateContext */
const int32_t DAT_001156b4[] = {
    0x3098, 3,    /* EGL_CONTEXT_MAJOR_VERSION 3 */
    0x30FB, 2,    /* EGL_CONTEXT_MINOR_VERSION 2 */
    0x3038        /* EGL_NONE */
};

/* GL format/type lookup tables — placeholder zeros */
const int32_t DAT_001156c0[4096] = {0};
const int32_t DAT_00115740[4096] = {0};
const int32_t DAT_00115760[4096] = {0};
const int32_t DAT_001159d8[4096] = {0};
const uint8_t DAT_00115a20[4096] = {0};
const uint8_t DAT_00115a30[4096] = {0};
const uint8_t DAT_00115a80[4096] = {0};
const uint8_t DAT_00115f44[4096] = {0};

/* Texture compression data */
const uint8_t DAT_001161f7[4096] = {0};
const uint8_t DAT_00116798[4096] = {0};
const uint8_t DAT_0011683c[4096] = {0};

/* Mutable global storage (originally in .bss/.data) */
uint64_t DAT_00144ee0 = 0;
uint64_t DAT_00144ee8 = 0;
uint64_t DAT_00144eec = 0;
uint64_t DAT_00144ef0 = 0;
uint64_t DAT_00144ef4 = 0;
uint64_t DAT_00144ef8 = 0;
uint64_t DAT_00144efc = 0;
uint64_t DAT_00144f00 = 0;
uint64_t DAT_00144f04 = 0;
uint64_t DAT_00144f08 = 0;
uint64_t DAT_00144f0c = 0;
uint64_t DAT_00144f10 = 0;
uint64_t DAT_00144f14 = 0;
uint64_t DAT_00144f18 = 0;
uint64_t DAT_00144f1c = 0;
uint64_t DAT_00144f20 = 0;
uint64_t DAT_00144f28 = 0;
uint64_t DAT_00145140 = 0;
uint64_t DAT_00145148 = 0;  /* globalEGLContext alias */

/* Linker/dispatch pointers */
void *PTR_LOOP_00141df0 = 0;
void *PTR_s_gl_Color_00141df8 = 0;
void *PTR_DAT_00141ff8 = 0;
void *PTR_s_program_env_001420e0 = 0;
void *PTR_s_gd_ProgramEnv_001420e8 = 0;

/* Unknown references */
uint8_t UNK_0013c5a0 = 0;

uint64_t DAT_00144f24 = 0;

const uint8_t DAT_001167ac[4096] = {0};

/* Additional auto-discovered definitions */
const uint8_t DAT_00116216[4096] = {0};
const uint8_t DAT_00116217[4096] = {0};
const uint8_t DAT_00116416[4096] = {0};
const uint8_t DAT_00116417[4096] = {0};
const uint8_t DAT_00116618[4096] = {0};
const uint8_t DAT_00116698[4096] = {0};
uint64_t DAT_00141e0c = 0;
uint64_t DAT_00144118 = 0;
uint64_t DAT_00144f38 = 0;
uint64_t DAT_00144f3c = 0;
uint8_t UNK_00141e00 = 0;
uint8_t UNK_00141e08 = 0;
