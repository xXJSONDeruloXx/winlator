// collections.c — exact transplant of ArrayBuffer, IntArray, ArrayList, ArrayMap,
// SparseArray, SparseIntArray, ArrayDeque, and RingBuffer from libwinlator.so.
//
// Struct layouts inferred from recovered/src/libwinlator/libwinlator.c.

#include "collections.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sched.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <pthread.h>

#if defined(__has_include)
#  if __has_include(<android/log.h>)
#    include <android/log.h>
#  else
     extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#  endif
#else
  extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#endif

// ─────────────────────────────────────────────────────────────────────────────
// ArrayBuffer
// ─────────────────────────────────────────────────────────────────────────────

int ArrayBuffer_available(const ArrayBuffer *buf) {
    return buf->size - buf->position;
}

void ArrayBuffer_rewind(ArrayBuffer *buf) {
    buf->position = 0;
}

void ArrayBuffer_skip(ArrayBuffer *buf, int n) {
    buf->position += n;
}

void ArrayBuffer_free(ArrayBuffer *buf) {
    if (buf && buf->data) {
        free(buf->data);
        buf->data = NULL;
    }
    if (buf) {
        buf->size = 0;
        buf->capacity = 0;
    }
}

void ArrayBuffer_copy(const ArrayBuffer *src, ArrayBuffer *dst) {
    if (!src || !src->data) return;
    if (dst && dst->data) {
        free(dst->data);
        dst->data = NULL;
        dst->size = 0;
        dst->capacity = 0;
    }
    dst->size = 0;
    dst->position = 0;
    dst->capacity = 0;
    void *buf = malloc((size_t)src->size);
    if (buf) memcpy(buf, src->data, (size_t)src->size);
    dst->data = buf;
    dst->size = src->size;
    dst->capacity = src->size;
}

// Ensure at least `needed` bytes of capacity, growing if necessary.
static void _abuf_ensure(ArrayBuffer *buf, int needed) {
    if (buf->capacity >= needed) return;
    int nc = needed < 0 ? 0 : needed;
    void *p = realloc(buf->data, (size_t)nc);
    if (p) {
        memset((char *)p + buf->capacity, 0, (size_t)(nc - buf->capacity));
        buf->data = p;
        buf->capacity = nc;
    }
}

void ArrayBuffer_put(ArrayBuffer *buf, uint8_t b) {
    int sz = buf->size;
    if (buf->capacity <= sz) {
        int nc = sz < 0 ? 0 : sz + 1;
        void *p = realloc(buf->data, (size_t)nc);
        if (p) {
            memset((char *)p + buf->capacity, 0, (size_t)(nc - buf->capacity));
            buf->data = p;
            buf->capacity = nc;
        }
    }
    buf->size = sz + 1;
    ((uint8_t *)buf->data)[sz] = b;
}

void ArrayBuffer_putBytes(ArrayBuffer *buf, const void *src, int n) {
    int needed = buf->size + n;
    if (buf->capacity < needed) {
        int nc = needed < 0 ? 0 : needed;
        void *p = realloc(buf->data, (size_t)nc);
        if (p) {
            memset((char *)p + buf->capacity, 0, (size_t)(nc - buf->capacity));
            buf->data = p;
            buf->capacity = nc;
        }
    }
    if (src == NULL)
        memset((char *)buf->data + buf->size, 0, (size_t)n);
    else
        memcpy((char *)buf->data + buf->size, src, (size_t)n);
    buf->size += n;
}

#define _ABUF_PUT_SCALAR(type, suffix) \
void ArrayBuffer_put##suffix(ArrayBuffer *buf, type v) { \
    ArrayBuffer_putBytes(buf, &v, (int)sizeof(v)); \
}
_ABUF_PUT_SCALAR(uint16_t, Short)
_ABUF_PUT_SCALAR(uint32_t, Int)
_ABUF_PUT_SCALAR(uint64_t, Long)
_ABUF_PUT_SCALAR(float,    Float)
_ABUF_PUT_SCALAR(double,   Double)

void ArrayBuffer_putFloat2(ArrayBuffer *buf, float x, float y) {
    ArrayBuffer_putBytes(buf, &x, 4); ArrayBuffer_putBytes(buf, &y, 4);
}
void ArrayBuffer_putFloat3(ArrayBuffer *buf, float x, float y, float z) {
    ArrayBuffer_putBytes(buf, &x, 4); ArrayBuffer_putBytes(buf, &y, 4); ArrayBuffer_putBytes(buf, &z, 4);
}
void ArrayBuffer_putFloat4(ArrayBuffer *buf, float x, float y, float z, float w) {
    ArrayBuffer_putBytes(buf, &x, 4); ArrayBuffer_putBytes(buf, &y, 4);
    ArrayBuffer_putBytes(buf, &z, 4); ArrayBuffer_putBytes(buf, &w, 4);
}

void ArrayBuffer_putString(ArrayBuffer *buf, const char *s) {
    if (!s) return;
    int len = (int)strlen(s);
    ArrayBuffer_putInt(buf, (uint32_t)len);
    ArrayBuffer_putBytes(buf, s, len);
}

uint8_t ArrayBuffer_get(ArrayBuffer *buf) {
    int pos = buf->position++;
    return ((uint8_t *)buf->data)[pos];
}

#define _ABUF_GET_SCALAR(type, suffix) \
type ArrayBuffer_get##suffix(ArrayBuffer *buf) { \
    type v; \
    memcpy(&v, (char *)buf->data + buf->position, sizeof(v)); \
    buf->position += (int)sizeof(v); \
    return v; \
}
_ABUF_GET_SCALAR(uint16_t, Short)
_ABUF_GET_SCALAR(uint32_t, Int)
_ABUF_GET_SCALAR(uint64_t, Long)
_ABUF_GET_SCALAR(float,    Float)
_ABUF_GET_SCALAR(double,   Double)

void *ArrayBuffer_getBytes(ArrayBuffer *buf, int n) {
    int pos = buf->position;
    buf->position += n;
    return (char *)buf->data + pos;
}

// ─────────────────────────────────────────────────────────────────────────────
// IntArray
// ─────────────────────────────────────────────────────────────────────────────

void IntArray_clear(IntArray *arr) {
    if (arr && arr->data) {
        free(arr->data);
        arr->count = 0;
        arr->byte_capacity = 0;
        arr->data = NULL;
    }
}

void IntArray_add(IntArray *arr, int32_t v) {
    int32_t cnt = arr->count;
    int32_t needed_bytes = (cnt + 1) * 4;
    if (arr->byte_capacity < needed_bytes) {
        int32_t nc = needed_bytes;
        void *p = realloc(arr->data, (size_t)nc);
        if (p) {
            memset((char *)p + arr->byte_capacity, 0, (size_t)(nc - arr->byte_capacity));
            arr->data = (int32_t *)p;
            arr->byte_capacity = nc;
        }
    }
    arr->count = cnt + 1;
    arr->data[cnt] = v;
}

void IntArray_addAt(IntArray *arr, int32_t idx, int32_t v) {
    int32_t cnt = arr->count;
    if (idx < 0 || idx >= cnt) {
        // Append at end
        IntArray_add(arr, v);
        return;
    }
    int32_t needed_bytes = (cnt + 1) * 4;
    if (arr->byte_capacity < needed_bytes) {
        int32_t nc = needed_bytes;
        void *p = realloc(arr->data, (size_t)nc);
        if (p) {
            memset((char *)p + arr->byte_capacity, 0, (size_t)(nc - arr->byte_capacity));
            arr->data = (int32_t *)p;
            arr->byte_capacity = nc;
        }
    }
    void *dst = arr->data + idx;
    memmove((char *)dst + 4, dst, (size_t)((cnt - idx) * 4));
    arr->data[idx] = v;
    arr->count = cnt + 1;
}

void IntArray_addAll(IntArray *arr, int32_t count, ...) {
    int32_t cur = arr->count;
    int32_t needed = (cur + count) * 4;
    if (arr->byte_capacity < needed) {
        void *p = realloc(arr->data, (size_t)needed);
        if (p) {
            memset((char *)p + arr->byte_capacity, 0, (size_t)(needed - arr->byte_capacity));
            arr->data = (int32_t *)p;
            arr->byte_capacity = needed;
        }
    }
    va_list ap;
    va_start(ap, count);
    for (int32_t i = 0; i < count; i++) {
        arr->data[cur++] = va_arg(ap, int32_t);
    }
    va_end(ap);
    arr->count = cur;
}

void IntArray_remove(IntArray *arr, int32_t start, int32_t count) {
    int32_t total = arr->count;
    int32_t end = start + count;
    if (end > total) return;
    int32_t remaining = total - end;
    if (remaining > 0)
        memmove(arr->data + start, arr->data + end, (size_t)(remaining * 4));
    arr->count = total - count;
}

uint32_t IntArray_removeAt(IntArray *arr, int32_t idx) {
    if (idx < 0 || idx >= arr->count) return 0xFFFFFFFF;
    uint32_t v = (uint32_t)arr->data[idx];
    IntArray_remove(arr, idx, 1);
    return v;
}

static int _int_cmp(const void *a, const void *b) {
    return *(const int32_t *)a - *(const int32_t *)b;
}
void IntArray_sort(IntArray *arr) {
    if (arr) qsort(arr->data, (size_t)arr->count, 4, _int_cmp);
}

// ─────────────────────────────────────────────────────────────────────────────
// ArrayList
// ─────────────────────────────────────────────────────────────────────────────

int32_t ArrayList_indexOf(const ArrayList *arr, const void *item) {
    for (int32_t i = 0; i < arr->count; i++)
        if (arr->data[i] == item) return i;
    return -1;
}

void ArrayList_add(ArrayList *arr, void *item) {
    if (arr->capacity <= arr->count) {
        int32_t nc = arr->capacity < 4 ? 4 : arr->capacity + (arr->capacity >> 1);
        if (nc <= arr->count) nc = arr->count + 1;
        void **p = (void **)realloc(arr->data, (size_t)(nc * (int32_t)sizeof(void *)));
        if (p) {
            memset(p + arr->capacity, 0, (size_t)((nc - arr->capacity) * (int32_t)sizeof(void *)));
            arr->data = p;
            arr->capacity = nc;
        }
    }
    arr->data[arr->count++] = item;
}

void ArrayList_addAt(ArrayList *arr, int32_t idx, void *item) {
    if (idx < 0 || idx >= arr->count) {
        ArrayList_add(arr, item);
        return;
    }
    if (arr->capacity <= arr->count) {
        int32_t nc = arr->capacity < 4 ? 4 : arr->capacity + (arr->capacity >> 1);
        if (nc <= arr->count) nc = arr->count + 1;
        void **p = (void **)realloc(arr->data, (size_t)(nc * (int32_t)sizeof(void *)));
        if (p) {
            memset(p + arr->capacity, 0, (size_t)((nc - arr->capacity) * (int32_t)sizeof(void *)));
            arr->data = p;
            arr->capacity = nc;
        }
    }
    memmove(arr->data + idx + 1, arr->data + idx,
            (size_t)((arr->count - idx) * (int32_t)sizeof(void *)));
    arr->data[idx] = item;
    arr->count++;
}

void ArrayList_fill(ArrayList *arr, int32_t count, void *item) {
    for (int32_t i = 0; i < count; i++) ArrayList_add(arr, item);
}

void *ArrayList_removeAt(ArrayList *arr, int32_t idx) {
    if (idx < 0 || idx >= arr->count) return NULL;
    void *item = arr->data[idx];
    int32_t tail = arr->count - idx - 1;
    if (tail > 0)
        memmove(arr->data + idx, arr->data + idx + 1, (size_t)(tail * (int32_t)sizeof(void *)));
    arr->data[--arr->count] = NULL;
    return item;
}

void *ArrayList_remove(ArrayList *arr, const void *item) {
    int32_t idx = ArrayList_indexOf(arr, item);
    if (idx < 0) return NULL;
    return ArrayList_removeAt(arr, idx);
}

void ArrayList_free(ArrayList *arr) {
    if (arr && arr->data) {
        free(arr->data);
        arr->data = NULL;
        arr->count = 0;
        arr->capacity = 0;
    }
}

ArrayList *ArrayList_fromStrings(const char **strs, int32_t count) {
    ArrayList *arr = (ArrayList *)calloc(1, sizeof(ArrayList));
    if (!arr) return NULL;
    for (int32_t i = 0; i < count; i++) ArrayList_add(arr, (void *)strs[i]);
    return arr;
}

// ─────────────────────────────────────────────────────────────────────────────
// ArrayMap  (sorted by string key, binary search + strcmp)
// ─────────────────────────────────────────────────────────────────────────────

// Compute the same hash used by the binary for binary-search bucket.
static int32_t _str_hash(const char *s) {
    int32_t h = 0;
    for (unsigned char c = (unsigned char)*s; c != 0; s++, c = (unsigned char)*s)
        h = h * 0x1f + c;
    return h;
}

int32_t ArrayMap_indexOfKey(const ArrayMap *map, const char *key) {
    int32_t n = map->count;
    if (n == 0) return -1;
    int32_t khash = _str_hash(key);
    int32_t lo = 0, hi = n - 1;
    while (lo <= hi) {
        int32_t mid = (lo + hi) / 2;
        const char *mkey = map->data[mid].key;
        int32_t mhash = mkey ? _str_hash(mkey) : 0;
        if (mhash < khash) { lo = mid + 1; continue; }
        if (mhash > khash) { hi = mid - 1; continue; }
        // hashes equal — do strcmp scan
        int cmp = strcmp(key, mkey);
        if (cmp == 0) return mid;
        if (cmp < 0)  { hi = mid - 1; }
        else          { lo = mid + 1; }
    }
    return ~lo; // not found: return -(insertion_point) - 1
}

void ArrayMap_put(ArrayMap *map, const char *key, void *value) {
    int32_t idx = ArrayMap_indexOfKey(map, key);
    if (idx >= 0) {
        map->data[idx].value = value;
        return;
    }
    int32_t ins = ~idx;
    if (map->capacity <= map->count) {
        int32_t nc = map->capacity < 4 ? 4 : map->capacity + (map->capacity >> 1);
        if (nc <= map->count) nc = map->count + 1;
        ArrayMapEntry *p = (ArrayMapEntry *)realloc(map->data,
            (size_t)(nc * (int32_t)sizeof(ArrayMapEntry)));
        if (p) {
            memset(p + map->capacity, 0,
                   (size_t)((nc - map->capacity) * (int32_t)sizeof(ArrayMapEntry)));
            map->data = p;
            map->capacity = nc;
        }
    }
    int32_t tail = map->count - ins;
    if (tail > 0)
        memmove(map->data + ins + 1, map->data + ins,
                (size_t)(tail * (int32_t)sizeof(ArrayMapEntry)));
    map->data[ins].key   = (char *)key;
    map->data[ins].value = value;
    map->count++;
}

void *ArrayMap_get(const ArrayMap *map, const char *key) {
    int32_t idx = ArrayMap_indexOfKey(map, key);
    return idx < 0 ? NULL : map->data[idx].value;
}

void *ArrayMap_removeAt(ArrayMap *map, int32_t idx) {
    if (idx < 0 || idx >= map->count) return NULL;
    void *v = map->data[idx].value;
    int32_t tail = map->count - idx - 1;
    if (tail > 0)
        memmove(map->data + idx, map->data + idx + 1,
                (size_t)(tail * (int32_t)sizeof(ArrayMapEntry)));
    map->count--;
    map->data[map->count].key   = NULL;
    map->data[map->count].value = NULL;
    return v;
}

void *ArrayMap_remove(ArrayMap *map, const char *key) {
    int32_t idx = ArrayMap_indexOfKey(map, key);
    if (idx < 0 || idx >= map->count) return NULL;
    return ArrayMap_removeAt(map, idx);
}

void ArrayMap_free(ArrayMap *map) {
    if (map && map->data) {
        free(map->data);
        map->data = NULL;
        map->count = 0;
        map->capacity = 0;
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// SparseArray  (sorted int key → void*)
// ─────────────────────────────────────────────────────────────────────────────

int32_t SparseArray_indexOfKey(const SparseArray *arr, int32_t key) {
    int32_t lo = 0, hi = arr->count - 1;
    while (lo <= hi) {
        int32_t mid = (lo + hi) >> 1;
        int32_t k = arr->data[mid].key;
        if (k < key) { lo = mid + 1; continue; }
        if (k > key) { hi = mid - 1; continue; }
        return mid;
    }
    return ~lo;
}

void SparseArray_put(SparseArray *arr, int32_t key, void *value) {
    int32_t idx = SparseArray_indexOfKey(arr, key);
    if (idx >= 0) { arr->data[idx].value = value; return; }
    int32_t ins = ~idx;
    if (arr->capacity <= arr->count) {
        int32_t nc = arr->capacity < 4 ? 4 : arr->capacity + (arr->capacity >> 1);
        if (nc <= arr->count) nc = arr->count + 1;
        SparseArrayEntry *p = (SparseArrayEntry *)realloc(arr->data,
            (size_t)(nc * (int32_t)sizeof(SparseArrayEntry)));
        if (p) {
            memset(p + arr->capacity, 0,
                   (size_t)((nc - arr->capacity) * (int32_t)sizeof(SparseArrayEntry)));
            arr->data = p;
            arr->capacity = nc;
        }
    }
    int32_t tail = arr->count - ins;
    if (tail > 0)
        memmove(arr->data + ins + 1, arr->data + ins,
                (size_t)(tail * (int32_t)sizeof(SparseArrayEntry)));
    arr->data[ins].key   = key;
    arr->data[ins]._pad  = 0;
    arr->data[ins].value = value;
    arr->count++;
}

void *SparseArray_get(const SparseArray *arr, int32_t key) {
    int32_t idx = SparseArray_indexOfKey(arr, key);
    return idx < 0 ? NULL : arr->data[idx].value;
}

void *SparseArray_removeAt(SparseArray *arr, int32_t idx) {
    if (idx < 0 || idx >= arr->count) return NULL;
    void *v = arr->data[idx].value;
    int32_t tail = arr->count - idx - 1;
    if (tail > 0)
        memmove(arr->data + idx, arr->data + idx + 1,
                (size_t)(tail * (int32_t)sizeof(SparseArrayEntry)));
    arr->count--;
    memset(arr->data + arr->count, 0, sizeof(SparseArrayEntry));
    return v;
}

void *SparseArray_remove(SparseArray *arr, int32_t key) {
    int32_t idx = SparseArray_indexOfKey(arr, key);
    if (idx < 0) return NULL;
    return SparseArray_removeAt(arr, idx);
}

void SparseArray_free(SparseArray *arr) {
    if (arr && arr->data) {
        free(arr->data);
        arr->data = NULL;
        arr->count = 0;
        arr->capacity = 0;
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// SparseIntArray  (sorted int key → int32_t)
// ─────────────────────────────────────────────────────────────────────────────

int32_t SparseIntArray_indexOfKey(const SparseIntArray *arr, int32_t key) {
    int32_t lo = 0, hi = arr->count - 1;
    while (lo <= hi) {
        int32_t mid = (lo + hi) >> 1;
        int32_t k = arr->data[mid].key;
        if (k < key) { lo = mid + 1; continue; }
        if (k > key) { hi = mid - 1; continue; }
        return mid;
    }
    return ~lo;
}

void SparseIntArray_put(SparseIntArray *arr, int32_t key, int32_t value) {
    int32_t idx = SparseIntArray_indexOfKey(arr, key);
    if (idx >= 0) { arr->data[idx].value = value; return; }
    int32_t ins = ~idx;
    if (arr->capacity <= arr->count) {
        int32_t nc = arr->capacity < 4 ? 4 : arr->capacity + (arr->capacity >> 1);
        if (nc <= arr->count) nc = arr->count + 1;
        SparseIntArrayEntry *p = (SparseIntArrayEntry *)realloc(arr->data,
            (size_t)(nc * (int32_t)sizeof(SparseIntArrayEntry)));
        if (p) {
            memset(p + arr->capacity, 0,
                   (size_t)((nc - arr->capacity) * (int32_t)sizeof(SparseIntArrayEntry)));
            arr->data = p;
            arr->capacity = nc;
        }
    }
    int32_t tail = arr->count - ins;
    if (tail > 0)
        memmove(arr->data + ins + 1, arr->data + ins,
                (size_t)(tail * (int32_t)sizeof(SparseIntArrayEntry)));
    arr->data[ins].key   = key;
    arr->data[ins].value = value;
    arr->count++;
}

int32_t SparseIntArray_get(const SparseIntArray *arr, int32_t key) {
    int32_t idx = SparseIntArray_indexOfKey(arr, key);
    return idx < 0 ? 0 : arr->data[idx].value;
}

int32_t SparseIntArray_removeAt(SparseIntArray *arr, int32_t idx) {
    if (idx < 0 || idx >= arr->count) return 0;
    int32_t v = arr->data[idx].value;
    int32_t tail = arr->count - idx - 1;
    if (tail > 0)
        memmove(arr->data + idx, arr->data + idx + 1,
                (size_t)(tail * (int32_t)sizeof(SparseIntArrayEntry)));
    arr->count--;
    memset(arr->data + arr->count, 0, sizeof(SparseIntArrayEntry));
    return v;
}

int32_t SparseIntArray_remove(SparseIntArray *arr, int32_t key) {
    int32_t idx = SparseIntArray_indexOfKey(arr, key);
    if (idx < 0) return 0;
    return SparseIntArray_removeAt(arr, idx);
}

void SparseIntArray_free(SparseIntArray *arr) {
    if (arr && arr->data) {
        free(arr->data);
        arr->data = NULL;
        arr->count = 0;
        arr->capacity = 0;
    }
}

// ─────────────────────────────────────────────────────────────────────────────
// ArrayDeque  (circular buffer of void* with power-of-2 capacity)
// ─────────────────────────────────────────────────────────────────────────────

bool ArrayDeque_isEmpty(const ArrayDeque *dq) {
    return dq == NULL || dq->head == dq->tail;
}

static void _dq_ensure_init(ArrayDeque *dq) {
    if (!dq->data) {
        dq->head = 0; dq->tail = 0; dq->capacity = 8;
        dq->data = (void **)calloc(8, sizeof(void *));
    }
}

static void _dq_grow(ArrayDeque *dq) {
    int32_t nc = dq->capacity << 1;
    if (nc <= 0) return;
    void **p = (void **)calloc((size_t)nc, sizeof(void *));
    if (!p) return;
    int32_t head = dq->head;
    int32_t tail = dq->tail;
    int32_t cap  = dq->capacity;
    // copy from head to end, then 0..tail
    int32_t n1 = cap - head; // elements from head to wrap
    memcpy(p, dq->data + head, (size_t)(n1 * (int32_t)sizeof(void *)));
    memcpy(p + n1, dq->data,   (size_t)(tail * (int32_t)sizeof(void *)));
    free(dq->data);
    dq->data = p;
    dq->head = 0;
    dq->tail = cap; // size = cap (old capacity = number of elements)
    dq->capacity = nc;
}

void ArrayDeque_addFirst(ArrayDeque *dq, void *item) {
    _dq_ensure_init(dq);
    int32_t head = (dq->head - 1 + dq->capacity) & (dq->capacity - 1);
    dq->head = head;
    dq->data[head] = item;
    if (dq->head == dq->tail) _dq_grow(dq);
}

void ArrayDeque_addLast(ArrayDeque *dq, void *item) {
    _dq_ensure_init(dq);
    dq->data[dq->tail] = item;
    dq->tail = (dq->tail + 1) & (dq->capacity - 1);
    if (dq->head == dq->tail) _dq_grow(dq);
}

void *ArrayDeque_removeFirst(ArrayDeque *dq) {
    if (!dq || !dq->data) return NULL;
    if (dq->head == dq->tail) return NULL;
    void *item = dq->data[dq->head];
    dq->data[dq->head] = NULL;
    dq->head = (dq->head + 1) & (dq->capacity - 1);
    return item;
}

void *ArrayDeque_removeLast(ArrayDeque *dq) {
    if (!dq || !dq->data) return NULL;
    if (dq->head == dq->tail) return NULL;
    int32_t tail = (dq->tail - 1 + dq->capacity) & (dq->capacity - 1);
    dq->tail = tail;
    void *item = dq->data[tail];
    dq->data[tail] = NULL;
    return item;
}

void *ArrayDeque_getFirst(ArrayDeque *dq) {
    _dq_ensure_init(dq);
    return dq->data[dq->head];
}

void *ArrayDeque_getLast(ArrayDeque *dq) {
    _dq_ensure_init(dq);
    int32_t tail = (dq->tail - 1 + dq->capacity) & (dq->capacity - 1);
    return dq->data[tail];
}

void ArrayDeque_free(ArrayDeque *dq, bool free_items) {
    if (!dq || !dq->data) return;
    if (free_items) {
        for (int32_t i = dq->head; i != dq->tail; i = (i+1) & (dq->capacity-1)) {
            if (dq->data[i]) { free(dq->data[i]); dq->data[i] = NULL; }
        }
    }
    free(dq->data);
    dq->data = NULL;
    dq->head = 0;
    dq->tail = 0;
}

// ─────────────────────────────────────────────────────────────────────────────
// RingBuffer  (shared-memory ring buffer with pointer-based accessors)
//
// Management struct layout (0x30 = 48 bytes):
//   +0x00 int32_t  *head_ptr   → shm + 0x00
//   +0x08 int32_t  *tail_ptr   → shm + 0x04
//   +0x10 uint32_t *status_ptr → shm + 0x08
//   +0x18 uint8_t  *data_ptr   → shm + 0x10
//   +0x20 void     *shm_base   → for munmap
//   +0x28 int32_t   capacity   → data capacity in bytes
//   +0x2c int32_t   _pad
//
// Shared-memory layout: [head(4)][tail(4)][status(4)][_pad(4)][data(capacity)]
// Total shm size = capacity + 0x10
// ─────────────────────────────────────────────────────────────────────────────

typedef struct RingBufferHandle {
    int32_t  *head_ptr;    // +0x00
    int32_t  *tail_ptr;    // +0x08
    uint32_t *status_ptr;  // +0x10
    uint8_t  *data_ptr;    // +0x18
    void     *shm_base;    // +0x20
    int32_t   capacity;    // +0x28
    int32_t   _pad;        // +0x2c
} RingBufferHandle;

size_t RingBuffer_getSHMemSize(int32_t capacity) {
    return (size_t)(capacity + 0x10);
}

RingBuffer *RingBuffer_create(void *shm_or_fd_cookie, int32_t capacity) {
    // In the binary: param_1 = fd, param_2 = capacity.
    // mmap(NULL, capacity+16, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0)
    // For the clean tree we accept an already-mapped shm pointer.
    RingBufferHandle *rb = (RingBufferHandle *)calloc(1, sizeof(RingBufferHandle));
    if (!rb) return NULL;
    uint8_t *shm = (uint8_t *)shm_or_fd_cookie;
    memset(shm, 0, (size_t)(capacity + 0x10));
    rb->head_ptr   = (int32_t *)(shm + 0x00);
    rb->tail_ptr   = (int32_t *)(shm + 0x04);
    rb->status_ptr = (uint32_t *)(shm + 0x08);
    rb->data_ptr   = shm + 0x10;
    rb->shm_base   = shm;
    rb->capacity   = capacity;
    return (RingBuffer *)rb;
}

void RingBuffer_free(RingBuffer *rb) {
    if (!rb) return;
    free(rb);
}

void RingBuffer_setHead(RingBuffer *rb, int32_t v) {
    *((RingBufferHandle *)rb)->head_ptr = v;
}
int32_t RingBuffer_getHead(const RingBuffer *rb) {
    return *((const RingBufferHandle *)rb)->head_ptr;
}
void RingBuffer_setTail(RingBuffer *rb, int32_t v) {
    *((RingBufferHandle *)rb)->tail_ptr = v;
}
int32_t RingBuffer_getTail(const RingBuffer *rb) {
    return *((const RingBufferHandle *)rb)->tail_ptr;
}
void RingBuffer_setStatus(RingBuffer *rb, uint32_t flag) {
    __sync_fetch_and_or(((RingBufferHandle *)rb)->status_ptr, flag);
}
void RingBuffer_unsetStatus(RingBuffer *rb, uint32_t flag) {
    __sync_fetch_and_and(((RingBufferHandle *)rb)->status_ptr, ~flag);
}
bool RingBuffer_hasStatus(const RingBuffer *rb, uint32_t flag) {
    return (*((const RingBufferHandle *)rb)->status_ptr & flag) != 0;
}

int32_t RingBuffer_size(const RingBuffer *rb) {
    const RingBufferHandle *h = (const RingBufferHandle *)rb;
    return *h->tail_ptr - *h->head_ptr;
}

int32_t RingBuffer_freeSpace(const RingBuffer *rb) {
    const RingBufferHandle *h = (const RingBufferHandle *)rb;
    return h->capacity - *h->tail_ptr + *h->head_ptr;
}

// Exact transplant: spin-wait with sched_yield/usleep fallback.
#define _RB_STOPPED(h) ((*((h)->status_ptr) >> 1) & 1)

int32_t RingBuffer_read(RingBuffer *rb, void *dst, int32_t n) {
    RingBufferHandle *h = (RingBufferHandle *)rb;
    if ((uint32_t)h->capacity < (uint32_t)n) {
        __android_log_print(3, "System.out", "ring: buffer overflow on read (%d/%d)\n",
                            n, h->capacity);
        return 0;
    }
    uint32_t spin = 1;
    do {
        if ((uint32_t)(*h->tail_ptr - *h->head_ptr) >= (uint32_t)n) {
            uint32_t head  = (uint32_t)*h->head_ptr;
            uint32_t cap   = (uint32_t)h->capacity;
            uint32_t start = (cap - 1) & head;
            uint8_t *out   = (uint8_t *)dst;
            if (start + (uint32_t)n > cap) {
                uint32_t part1 = cap - start;
                memcpy(out, h->data_ptr + start, part1);
                memcpy(out + part1, h->data_ptr, (size_t)((uint32_t)n - part1));
            } else {
                memcpy(out, h->data_ptr + start, (size_t)n);
            }
            *h->head_ptr = (int32_t)(head + (uint32_t)n);
            return 1;
        }
        if (spin < 500) sched_yield(); else usleep(100);
        spin++;
    } while (!_RB_STOPPED(h));
    return 0;
}

int32_t RingBuffer_waitForRead(RingBuffer *rb, void *dst, int32_t n) {
    RingBufferHandle *h = (RingBufferHandle *)rb;
    uint32_t spin = 1;
    int32_t avail = 0;
    do {
        avail = *h->tail_ptr - *h->head_ptr;
        if ((uint32_t)avail >= (uint32_t)n) break;
        if (spin < 500) sched_yield(); else usleep(100);
        spin++;
    } while (!_RB_STOPPED(h));
    (void)dst; // dst not used here; caller uses RingBuffer_read for actual transfer
    return (uint32_t)avail >= (uint32_t)n;
}

int32_t RingBuffer_write(RingBuffer *rb, const void *src, int32_t n) {
    RingBufferHandle *h = (RingBufferHandle *)rb;
    if ((uint32_t)h->capacity < (uint32_t)n) {
        __android_log_print(3, "System.out", "ring: buffer overflow on write (%d/%d)\n",
                            n, h->capacity);
        return 0;
    }
    uint32_t spin = 1;
    do {
        uint32_t free_bytes = (uint32_t)h->capacity - (uint32_t)(*h->tail_ptr - *h->head_ptr);
        if (free_bytes >= (uint32_t)n) {
            uint32_t tail  = (uint32_t)*h->tail_ptr;
            uint32_t cap   = (uint32_t)h->capacity;
            uint32_t start = (cap - 1) & tail;
            const uint8_t *in = (const uint8_t *)src;
            if (start + (uint32_t)n > cap) {
                uint32_t part1 = cap - start;
                memcpy(h->data_ptr + start, in, part1);
                memcpy(h->data_ptr, in + part1, (size_t)((uint32_t)n - part1));
            } else {
                memcpy(h->data_ptr + start, in, (size_t)n);
            }
            *h->tail_ptr = (int32_t)(tail + (uint32_t)n);
            return 1;
        }
        if (spin < 500) sched_yield(); else usleep(100);
        spin++;
    } while (!_RB_STOPPED(h));
    return 0;
}

int32_t RingBuffer_waitForWrite(RingBuffer *rb, const void *src, int32_t n) {
    RingBufferHandle *h = (RingBufferHandle *)rb;
    uint32_t spin = 1;
    uint32_t free_bytes = 0;
    do {
        free_bytes = (uint32_t)h->capacity - (uint32_t)(*h->tail_ptr - *h->head_ptr);
        if (free_bytes >= (uint32_t)n) break;
        if (spin < 500) sched_yield(); else usleep(100);
        spin++;
    } while (!_RB_STOPPED(h));
    (void)src;
    return free_bytes >= (uint32_t)n;
}
