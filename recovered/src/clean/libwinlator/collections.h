#pragma once
#include "winlator_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// ── ArrayBuffer ──────────────────────────────────────────────────────────────
void     ArrayBuffer_put(ArrayBuffer *buf, uint8_t b);
void     ArrayBuffer_putShort(ArrayBuffer *buf, uint16_t v);
void     ArrayBuffer_putInt(ArrayBuffer *buf, uint32_t v);
void     ArrayBuffer_putLong(ArrayBuffer *buf, uint64_t v);
void     ArrayBuffer_putFloat(ArrayBuffer *buf, float v);
void     ArrayBuffer_putFloat2(ArrayBuffer *buf, float x, float y);
void     ArrayBuffer_putFloat3(ArrayBuffer *buf, float x, float y, float z);
void     ArrayBuffer_putFloat4(ArrayBuffer *buf, float x, float y, float z, float w);
void     ArrayBuffer_putDouble(ArrayBuffer *buf, double v);
void     ArrayBuffer_putBytes(ArrayBuffer *buf, const void *src, int n);
void     ArrayBuffer_putString(ArrayBuffer *buf, const char *s);

uint8_t  ArrayBuffer_get(ArrayBuffer *buf);
uint16_t ArrayBuffer_getShort(ArrayBuffer *buf);
uint32_t ArrayBuffer_getInt(ArrayBuffer *buf);
uint64_t ArrayBuffer_getLong(ArrayBuffer *buf);
float    ArrayBuffer_getFloat(ArrayBuffer *buf);
double   ArrayBuffer_getDouble(ArrayBuffer *buf);
void    *ArrayBuffer_getBytes(ArrayBuffer *buf, int n);
void     ArrayBuffer_skip(ArrayBuffer *buf, int n);
int      ArrayBuffer_available(const ArrayBuffer *buf);
void     ArrayBuffer_rewind(ArrayBuffer *buf);
void     ArrayBuffer_free(ArrayBuffer *buf);
void     ArrayBuffer_copy(const ArrayBuffer *src, ArrayBuffer *dst);

// ── IntArray ─────────────────────────────────────────────────────────────────
void     IntArray_add(IntArray *arr, int32_t v);
void     IntArray_addAt(IntArray *arr, int32_t idx, int32_t v);
void     IntArray_addAll(IntArray *arr, int32_t count, ...);
void     IntArray_remove(IntArray *arr, int32_t start, int32_t count);
uint32_t IntArray_removeAt(IntArray *arr, int32_t idx);
void     IntArray_clear(IntArray *arr);
void     IntArray_sort(IntArray *arr);

// ── ArrayList ────────────────────────────────────────────────────────────────
int32_t  ArrayList_indexOf(const ArrayList *arr, const void *item);
void     ArrayList_add(ArrayList *arr, void *item);
void     ArrayList_addAt(ArrayList *arr, int32_t idx, void *item);
void     ArrayList_fill(ArrayList *arr, int32_t count, void *item);
void    *ArrayList_removeAt(ArrayList *arr, int32_t idx);
void    *ArrayList_remove(ArrayList *arr, const void *item);
void     ArrayList_free(ArrayList *arr);
ArrayList *ArrayList_fromStrings(const char **strs, int32_t count);

// ── ArrayMap ─────────────────────────────────────────────────────────────────
int32_t  ArrayMap_indexOfKey(const ArrayMap *map, const char *key);
void     ArrayMap_put(ArrayMap *map, const char *key, void *value);
void    *ArrayMap_get(const ArrayMap *map, const char *key);
void    *ArrayMap_removeAt(ArrayMap *map, int32_t idx);
void    *ArrayMap_remove(ArrayMap *map, const char *key);
void     ArrayMap_free(ArrayMap *map);

// ── SparseArray ──────────────────────────────────────────────────────────────
int32_t  SparseArray_indexOfKey(const SparseArray *arr, int32_t key);
void     SparseArray_put(SparseArray *arr, int32_t key, void *value);
void    *SparseArray_get(const SparseArray *arr, int32_t key);
void    *SparseArray_removeAt(SparseArray *arr, int32_t idx);
void    *SparseArray_remove(SparseArray *arr, int32_t key);
void     SparseArray_free(SparseArray *arr);

// ── SparseIntArray ────────────────────────────────────────────────────────────
int32_t  SparseIntArray_indexOfKey(const SparseIntArray *arr, int32_t key);
void     SparseIntArray_put(SparseIntArray *arr, int32_t key, int32_t value);
int32_t  SparseIntArray_get(const SparseIntArray *arr, int32_t key);
int32_t  SparseIntArray_removeAt(SparseIntArray *arr, int32_t idx);
int32_t  SparseIntArray_remove(SparseIntArray *arr, int32_t key);
void     SparseIntArray_free(SparseIntArray *arr);

// ── ArrayDeque ───────────────────────────────────────────────────────────────
bool     ArrayDeque_isEmpty(const ArrayDeque *dq);
void     ArrayDeque_addFirst(ArrayDeque *dq, void *item);
void     ArrayDeque_addLast(ArrayDeque *dq, void *item);
void    *ArrayDeque_removeFirst(ArrayDeque *dq);
void    *ArrayDeque_removeLast(ArrayDeque *dq);
void    *ArrayDeque_getFirst(ArrayDeque *dq);
void    *ArrayDeque_getLast(ArrayDeque *dq);
void     ArrayDeque_free(ArrayDeque *dq, bool free_items);

// ── RingBuffer ───────────────────────────────────────────────────────────────
RingBuffer *RingBuffer_create(void *shm, int32_t size);
size_t      RingBuffer_getSHMemSize(int32_t capacity);
int32_t     RingBuffer_size(const RingBuffer *rb);
int32_t     RingBuffer_freeSpace(const RingBuffer *rb);
int32_t     RingBuffer_read(RingBuffer *rb, void *dst, int32_t n);
int32_t     RingBuffer_write(RingBuffer *rb, const void *src, int32_t n);
int32_t     RingBuffer_waitForRead(RingBuffer *rb, void *dst, int32_t n);
int32_t     RingBuffer_waitForWrite(RingBuffer *rb, const void *src, int32_t n);
void        RingBuffer_free(RingBuffer *rb);

void     RingBuffer_setHead(RingBuffer *rb, int32_t v);
int32_t  RingBuffer_getHead(const RingBuffer *rb);
void     RingBuffer_setTail(RingBuffer *rb, int32_t v);
int32_t  RingBuffer_getTail(const RingBuffer *rb);
void     RingBuffer_setStatus(RingBuffer *rb, uint32_t flag);
void     RingBuffer_unsetStatus(RingBuffer *rb, uint32_t flag);
bool     RingBuffer_hasStatus(const RingBuffer *rb, uint32_t flag);

#ifdef __cplusplus
}
#endif
