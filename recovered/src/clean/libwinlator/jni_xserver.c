// jni_xserver.c — JNI bindings for com.winlator.xserver.Drawable and Pixmap
// Scaffolded from recovered/src/libwinlator/libwinlator.c

#include "winlator_types.h"

#if defined(__has_include) && __has_include(<jni.h>)
#include <jni.h>
#include <string.h>
#include <stdlib.h>

#if defined(__has_include)
#  if __has_include(<android/bitmap.h>)
#    include <android/bitmap.h>
#  endif
#endif

// ── Drawable ─────────────────────────────────────────────────────────────────

JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_drawBitmap(
    JNIEnv *env, jclass cls,
    jobject dst_bitmap, jint dst_x, jint dst_y,
    jobject src_bitmap, jint src_x, jint src_y,
    jint w, jint h)
{
    // TODO: transplant exact pixel copy logic from recovered binary
    (void)env; (void)cls; (void)dst_bitmap; (void)dst_x; (void)dst_y;
    (void)src_bitmap; (void)src_x; (void)src_y; (void)w; (void)h;
}

JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_copyArea(
    JNIEnv *env, jclass cls,
    jobject bitmap, jint src_x, jint src_y,
    jint dst_x, jint dst_y, jint w, jint h)
{
    // TODO: transplant exact pixel copy-within-bitmap logic
    (void)env; (void)cls; (void)bitmap;
    (void)src_x; (void)src_y; (void)dst_x; (void)dst_y; (void)w; (void)h;
}

JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_copyAreaOp(
    JNIEnv *env, jclass cls,
    jobject dst_bitmap, jint dst_x, jint dst_y,
    jobject src_bitmap, jint src_x, jint src_y,
    jint w, jint h, jint op)
{
    // TODO: transplant raster-op (GXcopy / GXxor / etc.) logic
    (void)env; (void)cls; (void)dst_bitmap; (void)dst_x; (void)dst_y;
    (void)src_bitmap; (void)src_x; (void)src_y; (void)w; (void)h; (void)op;
}

JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_fillRect(
    JNIEnv *env, jclass cls,
    jobject bitmap, jint x, jint y, jint w, jint h, jint color)
{
    // TODO: transplant fill-rect loop
    (void)env; (void)cls; (void)bitmap;
    (void)x; (void)y; (void)w; (void)h; (void)color;
}

JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_drawLine(
    JNIEnv *env, jclass cls,
    jobject bitmap,
    jint x1, jint y1, jint x2, jint y2, jint color)
{
    // TODO: transplant Bresenham line-draw logic
    (void)env; (void)cls; (void)bitmap;
    (void)x1; (void)y1; (void)x2; (void)y2; (void)color;
}

JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_drawAlphaMaskedBitmap(
    JNIEnv *env, jclass cls,
    jobject dst_bitmap, jint dst_x, jint dst_y,
    jobject src_bitmap, jint src_x, jint src_y,
    jobject mask_bitmap, jint mask_x, jint mask_y,
    jint w, jint h)
{
    // TODO: transplant alpha-masked blit logic
    (void)env; (void)cls;
    (void)dst_bitmap; (void)dst_x; (void)dst_y;
    (void)src_bitmap; (void)src_x; (void)src_y;
    (void)mask_bitmap; (void)mask_x; (void)mask_y;
    (void)w; (void)h;
}

JNIEXPORT jlong JNICALL
Java_com_winlator_xserver_Drawable_fromBitmap(
    JNIEnv *env, jclass cls, jobject bitmap)
{
    // TODO: transplant bitmap-to-native-buffer allocation
    (void)env; (void)cls; (void)bitmap;
    return 0;
}

// ── Pixmap ───────────────────────────────────────────────────────────────────

JNIEXPORT jobject JNICALL
Java_com_winlator_xserver_Pixmap_toBitmap(
    JNIEnv *env, jclass cls, jlong pixmapPtr, jint width, jint height)
{
    // TODO: transplant native-buffer-to-bitmap
    (void)env; (void)cls; (void)pixmapPtr; (void)width; (void)height;
    return NULL;
}

#else // no jni.h — host build stubs

// When building on host without JNI headers, provide empty stubs.
// The Android NDK build will provide real implementations.

typedef void *jobject;
typedef long   jlong;
typedef int    jint;
typedef void   jvoid;

#define JNIEXPORT
#define JNICALL
#define JNICALL

typedef struct { char *data; } *jstring;

JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_drawBitmap(void) {}
JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_copyArea(void) {}
JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_copyAreaOp(void) {}
JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_fillRect(void) {}
JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_drawLine(void) {}
JNIEXPORT void JNICALL
Java_com_winlator_xserver_Drawable_drawAlphaMaskedBitmap(void) {}
JNIEXPORT jlong JNICALL
Java_com_winlator_xserver_Drawable_fromBitmap(void) { return 0; }
JNIEXPORT jobject JNICALL
Java_com_winlator_xserver_Pixmap_toBitmap(void) { return NULL; }

#endif // jni.h guard
