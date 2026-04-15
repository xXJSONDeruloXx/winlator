/*
 * vortek_types.h — Core type definitions for libvortekrenderer
 *
 * Reconstructed from Ghidra decompilation of libvortekrenderer.so (Winlator v11).
 */
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <pthread.h>

/* SIMD 128-bit register emulation (Ghidra decompiles NEON regs as uint8_t[16]) */
typedef union {
    uint8_t   bytes[16];
    uint16_t  shorts[8];
    uint32_t  ints[4];
    uint64_t  longs[2];
    float     floats[4];
    double    doubles[2];
} simd128_t;

/* NEON_fmov: reinterpret int bits as float */
static inline float neon_fmov_helper(uint32_t bits) {
    union { uint32_t i; float f; } u; u.i = bits; return u.f;
}

/* Generic function pointer for vtable/indirect calls */
typedef long (*generic_fn_t)();

/* Vortek command dispatch handler signature */
typedef void (*VortekHandler)(long ctx);

/* Dispatch table constants */
#define VORTEK_OPCODE_BASE  100
#define VORTEK_OPCODE_COUNT 254
