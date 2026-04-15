/*
 * jni_glx.c — JNI entry points for libgladiorenderer
 *
 * These are the 4 functions called from Java via System.loadLibrary("gladiorenderer"):
 *   GLXExtension.createGLContext(int fd)
 *   GLXExtension.destroyGLContext(long ptr)
 *   GLXExtension.createGLXContext(int version, long sharePtr)
 *   GLXExtension.destroyGLXContext(long ptr)
 */
#include "gladio_types.h"
#include "gladio_internal.h"
#include <jni.h>

JNIEXPORT jlong JNICALL
Java_com_winlator_xserver_extensions_GLXExtension_createGLContext(
    JNIEnv *env, jobject thiz, jint clientFd)
{
    return (jlong)(uintptr_t)createGLContext(env, (uint64_t)(uintptr_t)thiz, clientFd);
}

JNIEXPORT void JNICALL
Java_com_winlator_xserver_extensions_GLXExtension_destroyGLContext(
    JNIEnv *env, jobject thiz, jlong ctxPtr)
{
    destroyGLContext(env, (void *)(uintptr_t)ctxPtr);
}

JNIEXPORT jlong JNICALL
Java_com_winlator_xserver_extensions_GLXExtension_createGLXContext(
    JNIEnv *env, jobject thiz, jint version, jlong sharePtr)
{
    return (jlong)(uintptr_t)createGLXContext(version, (GLXContext *)(uintptr_t)sharePtr);
}

JNIEXPORT void JNICALL
Java_com_winlator_xserver_extensions_GLXExtension_destroyGLXContext(
    JNIEnv *env, jobject thiz, jlong ctxPtr)
{
    destroyGLXContext((GLXContext *)(uintptr_t)ctxPtr);
}
