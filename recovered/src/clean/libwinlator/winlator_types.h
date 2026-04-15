#pragma once

// ─────────────────────────────────────────────────────────────────────────────
// libwinlator — shared type definitions
// Inferred from recovered/src/libwinlator/libwinlator.c
// ─────────────────────────────────────────────────────────────────────────────

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ── ArrayBuffer ──────────────────────────────────────────────────────────────
// Growable byte buffer with separate write-cursor (size) and read-cursor (position).
// Layout inferred from ArrayBuffer_put/get/free/copy.
typedef struct ArrayBuffer {
    int32_t size;       // +0x00  bytes written (write cursor)
    int32_t position;   // +0x04  read cursor
    int32_t capacity;   // +0x08  allocated bytes
    int32_t _pad;       // +0x0c  unused
    void   *data;       // +0x10  heap buffer (8-byte pointer)
} ArrayBuffer;          // sizeof = 24

// ── IntArray ─────────────────────────────────────────────────────────────────
// Dynamic array of int32_t values.
// Layout inferred from IntArray_add/clear/removeAt.
typedef struct IntArray {
    int32_t count;         // +0x00  number of elements
    int32_t byte_capacity; // +0x04  allocated bytes (count * sizeof(int32_t))
    int32_t *data;         // +0x08  heap array (8-byte pointer)
} IntArray;                // sizeof = 16

// ── ArrayList ────────────────────────────────────────────────────────────────
// Dynamic array of opaque (void *) pointers.
// Layout inferred from ArrayList_add/removeAt/free.
typedef struct ArrayList {
    int32_t  count;        // +0x00  number of elements
    int32_t  capacity;     // +0x04  allocated slots
    void   **data;         // +0x08  heap array of void* (8-byte pointer)
} ArrayList;               // sizeof = 16

// ── ArrayMap ─────────────────────────────────────────────────────────────────
// Sorted string-keyed map: binary-search lookup by key hash then strcmp.
// Each entry = { char *key, void *value } = 16 bytes.
// Layout inferred from ArrayMap_indexOfKey/put/get.
typedef struct ArrayMapEntry {
    char  *key;    // +0x00
    void  *value;  // +0x08
} ArrayMapEntry;

typedef struct ArrayMap {
    int32_t      count;    // +0x00
    int32_t      capacity; // +0x04
    ArrayMapEntry *data;   // +0x08  heap array of ArrayMapEntry (8-byte pointer)
} ArrayMap;                // sizeof = 16

// ── SparseArray ──────────────────────────────────────────────────────────────
// Sorted int-keyed map to void*.
// Layout inferred from SparseArray_indexOfKey/put/get.
typedef struct SparseArrayEntry {
    int32_t key;    // +0x00
    int32_t _pad;   // +0x04
    void   *value;  // +0x08
} SparseArrayEntry;

typedef struct SparseArray {
    int32_t        count;    // +0x00
    int32_t        capacity; // +0x04
    SparseArrayEntry *data;  // +0x08
} SparseArray;               // sizeof = 16

// ── SparseIntArray ────────────────────────────────────────────────────────────
// Sorted int-keyed map to int32_t.
typedef struct SparseIntArrayEntry {
    int32_t key;   // +0x00
    int32_t value; // +0x04
} SparseIntArrayEntry;

typedef struct SparseIntArray {
    int32_t           count;    // +0x00
    int32_t           capacity; // +0x04
    SparseIntArrayEntry *data;  // +0x08
} SparseIntArray;               // sizeof = 16

// ── ArrayDeque ───────────────────────────────────────────────────────────────
// Circular buffer double-ended queue of void* pointers.
// Layout inferred from ArrayDeque_addFirst/addLast/free.
typedef struct ArrayDeque {
    int32_t  head;     // +0x00  front index (inclusive)
    int32_t  tail;     // +0x04  back index (exclusive)
    int32_t  capacity; // +0x08  number of allocated slots
    int32_t  _pad;     // +0x0c
    void   **data;     // +0x10  heap array of void* (8-byte pointer)
} ArrayDeque;          // sizeof = 24

// ── RingBuffer ───────────────────────────────────────────────────────────────
// Shared-memory ring buffer with atomic head/tail and status flags.
// Struct is laid out at the start of a shared-memory region.
// Exact field layout inferred from RingBuffer_setHead/getTail/etc.
typedef struct RingBuffer {
    volatile int32_t  head;     // +0x00  read index
    volatile int32_t  tail;     // +0x04  write index
    volatile uint32_t status;   // +0x08  bitfield status flags
    int32_t           _pad;     // +0x0c
    int32_t           capacity; // +0x10  usable data capacity (bytes)
    int32_t           _pad2;    // +0x14
    // data bytes follow immediately at +0x18
} RingBuffer;

#ifdef __cplusplus
}
#endif
