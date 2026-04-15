// jni_shm.c — JNI bindings for com.winlator.sysvshm.SysVSharedMemory
// Scaffolded from recovered/src/libwinlator/libwinlator.c

#include "winlator_types.h"
#include <jni.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#if defined(__has_include)
#  if __has_include(<android/sharedmem.h>)
#    include <android/sharedmem.h>
#  endif
#endif

// ── ashmemCreateRegion ────────────────────────────────────────────────────────
// Creates an ASharedMemory region with the given name and size.
// Exact transplant: wraps ASharedMemory_create.
int ashmemCreateRegion(const char *name, size_t size) {
#if defined(__has_include) && __has_include(<android/sharedmem.h>)
    return ASharedMemory_create(name, size);
#else
    (void)name; (void)size;
    return -1;
#endif
}

// ── createMemoryFd ────────────────────────────────────────────────────────────
// Creates an anonymous file fd (memfd_create or ashmem) of the given size.
int createMemoryFd(size_t size) {
    int fd = ashmemCreateRegion("winlator_mem", size);
    return fd;
}

// ── SysVSharedMemory JNI ──────────────────────────────────────────────────────

JNIEXPORT jint JNICALL
Java_com_winlator_sysvshm_SysVSharedMemory_ashmemCreateRegion(
    JNIEnv *env, jclass cls, jstring name_jstr, jlong size)
{
    (void)env; (void)cls;
    const char *name = (*env)->GetStringUTFChars(env, name_jstr, NULL);
    int fd = ashmemCreateRegion(name, (size_t)size);
    (*env)->ReleaseStringUTFChars(env, name_jstr, name);
    return (jint)fd;
}

JNIEXPORT jlong JNICALL
Java_com_winlator_sysvshm_SysVSharedMemory_mapSHMSegment(
    JNIEnv *env, jclass cls, jint fd, jlong size, jlong offset, jboolean read_only)
{
    (void)env; (void)cls;
    int prot = PROT_READ | (read_only ? 0 : PROT_WRITE);
    void *ptr = mmap(NULL, (size_t)size, prot, MAP_SHARED, (int)fd, (off_t)offset);
    if (ptr == MAP_FAILED) return 0;
    return (jlong)(uintptr_t)ptr;
}

JNIEXPORT void JNICALL
Java_com_winlator_sysvshm_SysVSharedMemory_unmapSHMSegment(
    JNIEnv *env, jclass cls, jlong ptr, jlong size)
{
    (void)env; (void)cls;
    if (ptr) munmap((void *)(uintptr_t)ptr, (size_t)size);
}

JNIEXPORT jint JNICALL
Java_com_winlator_sysvshm_SysVSharedMemory_createMemoryFd(
    JNIEnv *env, jclass cls, jlong size)
{
    (void)env; (void)cls;
    return (jint)createMemoryFd((size_t)size);
}
