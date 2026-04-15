/*
 * gladio_types.h — Core type definitions for libgladiorenderer
 *
 * Reconstructed from Ghidra decompilation of libgladiorenderer.so (Winlator v11).
 * Struct layouts are inferred from field offset patterns in the decompiled code.
 */
#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>
#include <EGL/egl.h>

/* SIMD 128-bit register emulation (Ghidra decompiles NEON regs as uint8_t[16]) */
typedef union {
    uint8_t   bytes[16];
    uint16_t  shorts[8];
    uint32_t  ints[4];
    uint64_t  longs[2];
    float     floats[4];
    double    doubles[2];
} simd128_t;

/* Generic function pointer for vtable calls */
typedef long (*generic_fn_t)();

/* Forward declarations for libwinlator types (opaque pointers for most) */
typedef struct ArrayList    ArrayList;
typedef struct ArrayDeque   ArrayDeque;
typedef struct ArrayMap     ArrayMap;
typedef struct SparseArray  SparseArray;
typedef struct IntArray     IntArray;

/*
 * ArrayBuffer — inline-embedded in GLContext.
 * Layout inferred from field accesses: pos at +4, capacity at +8, data at +16.
 */
typedef struct ArrayBuffer {
    int32_t     _reserved;  /* +0x00 */
    int32_t     pos;        /* +0x04 */
    int32_t     capacity;   /* +0x08 */
    int32_t     _pad;       /* +0x0C */
    void       *data;       /* +0x10 */
} ArrayBuffer;

/*
 * ── GLContext ────────────────────────────────────────────────────────────────
 * Per-client GL context wrapper.  Created by createGLContext(), size = 0xB8.
 * Owns the ring buffers and the render thread that processes commands.
 */
typedef struct GLContext {
    uint64_t    reserved0;          /* +0x00 */
    int32_t     clientFd;           /* +0x08  client socket fd */
    int32_t     _pad0;
    void       *clientRing;         /* +0x10  RingBuffer (client → server) */
    void       *serverRing;         /* +0x18  RingBuffer (server → client) */
    uint8_t     jniEnvData[16];     /* +0x20  JNIEnv-related data */
    uint64_t    javaObjRef;         /* +0x30  Java object reference */
    uint8_t     _gap38[0x20];       /* +0x38..0x57 */
    pthread_t   renderThread;       /* +0x58 */
    uint8_t     running;            /* +0x60 */
    uint8_t     _pad60[7];
    ArrayBuffer cmdBuf;             /* +0x68  command data buffer */
    ArrayBuffer cmdBuf2;            /* +0x80  second embedded buffer */
    void       *threadPool;         /* +0x98  ThreadPoolCtl* */
    uint8_t     _gapA0[0x18];       /* +0xA0..0xB7 */
} GLContext;                        /* total 0xB8 = 184 bytes */

/*
 * ── VertexAttrib ─────────────────────────────────────────────────────────────
 * Per-attribute state within a VAO. 0x20 (32) bytes each.
 * Layout inferred from readCommandBuffer vertex-array stride of 0x20.
 */
typedef struct VertexAttrib {
    uint8_t     _gap00[0x18];       /* +0x00 pointer storage, offsets, etc. */
    int16_t     stride;             /* +0x1E  stride in bytes (at pbVar12 + -2) */
    uint8_t     _gap1C[2];
    uint8_t     enabled;            /* +0x22  (at pbVar12[0]) */
    uint8_t     _pad[0x0D];
} VertexAttrib;                     /* total 0x20 = 32 bytes */

/*
 * ── VertexArrayHeader ────────────────────────────────────────────────────────
 * Pointed to by GLXContext+0x540.  First byte is attrib count.
 */
typedef struct VertexArrayHeader {
    uint8_t         attribCount;    /* +0x00  number of VertexAttrib entries */
    uint8_t         _pad[1];
    VertexAttrib    attribs[];      /* +0x02  flexible array (count * 0x20 bytes) */
} VertexArrayHeader;

/*
 * ── GLXContext ───────────────────────────────────────────────────────────────
 * The main per-thread GL state machine.  Thread-local via __emutls_v_currentRenderer.
 * Created by createGLXContext(), size = 0x928 (2344 bytes).
 *
 * Only known fields are placed; the rest is opaque padding to preserve layout.
 * Field offsets documented as [+0xNNN] comments.
 */
typedef struct GLXContext {
    EGLContext      eglContext;      /* +0x000 */
    uint32_t        glxVersion;     /* +0x008 */
    uint8_t         _gap00C[0x38C]; /* +0x00C .. +0x397 */

    /* +0x398 .. +0x39B: some state field */
    uint32_t        drawMode;       /* +0x39C  set by readCommandBuffer */

    uint8_t         _gap3A0[0x1A0]; /* +0x3A0 .. +0x53F */

    void           *vertexArrays;   /* +0x540  VertexArrayHeader* */
    uint8_t         _gap548[0x10];  /* +0x548 .. +0x557 */

    /* SparseArrays for GL object tracking */
    uint8_t         _gap558[0x60];  /* +0x558 .. +0x5B7 */
    SparseArray    *arbPrograms;    /* +0x5B8  ARB programs by GL name */

    uint8_t         _gap5C0[0x28];  /* +0x5C0 .. +0x5E7 */
    bool            sharedContext;  /* +0x5E8 */

    uint8_t         _gap5E9[0x33F]; /* +0x5E9 .. +0x927 */
} GLXContext;                       /* total 0x928 = 2344 bytes */

/*
 * ── ThreadPoolCtl ────────────────────────────────────────────────────────────
 * Worker thread pool control block.  Size = 0xC8 (200 bytes).
 */
typedef struct ThreadPoolCtl {
    uint8_t         workerCount;    /* +0x00  typically 4 */
    uint8_t         _pad01;
    uint8_t         flag;           /* +0x02 */
    uint8_t         _pad03;
    pthread_mutex_t mutex1;         /* +0x04 */
    pthread_cond_t  cond1;          /* +0x2C */
    pthread_mutex_t mutex2;         /* +0x5C */
    pthread_cond_t  cond2;          /* +0x84 */
    uint8_t         _gapB4[0x14];   /* +0xB4..0xC7 */
} ThreadPoolCtl;                    /* total 0xC8 = 200 bytes */

/*
 * ── ARBProgram ───────────────────────────────────────────────────────────────
 * ARB assembly program object.  Stored in SparseArray keyed by GL name.
 */
typedef struct ARBProgram {
    uint32_t    glName;             /* +0x00 */
    uint32_t    boundTarget;        /* +0x04  GL_VERTEX_PROGRAM_ARB etc. */
    uint32_t    fragmentShader;     /* +0x08  compiled ES shader for fragment */
    uint8_t     _gap0C[0x24];       /* remaining fields TBD */
} ARBProgram;

/*
 * ── Dispatch opcodes ─────────────────────────────────────────────────────────
 * Command buffer opcodes: 100..529 (430 entries).
 * getHandleRequestFunc() indexes a function-pointer table: table[(opcode - 100) * 8].
 */
#define GLADIO_OPCODE_BASE  100
#define GLADIO_OPCODE_COUNT 430

/* Handler function signature: void handler(GLContext* ctx) */
typedef void (*GladioHandler)(GLContext *ctx);

/*
 * ── Global externs ───────────────────────────────────────────────────────────
 */
extern pthread_mutex_t  glx_context_mutex;
extern EGLContext        globalEGLContext;

/* Thread-local current renderer (via emulated TLS) */
extern __thread GLXContext *currentRenderer;
