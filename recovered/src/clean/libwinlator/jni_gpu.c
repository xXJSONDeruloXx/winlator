// jni_gpu.c — JNI bindings for com.winlator.renderer.GPUImage and core.GPUHelper
// Scaffolded from recovered/src/libwinlator/libwinlator.c

#include "winlator_types.h"
#include <jni.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#if defined(__has_include)
#  if __has_include(<android/hardware_buffer.h>)
#    include <android/hardware_buffer.h>
#  endif
#  if __has_include(<EGL/egl.h>)
#    include <EGL/egl.h>
#    include <EGL/eglext.h>
#  endif
#  if __has_include(<android/log.h>)
#    include <android/log.h>
#  else
     extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#  endif
#else
  extern int __android_log_print(int prio, const char *tag, const char *fmt, ...);
#endif

static EGLContext globalEGLContext = EGL_NO_CONTEXT;

// ── AHardwareBuffer_getFd ─────────────────────────────────────────────────────
// Returns the first native handle fd from the AHardwareBuffer.
// Exact transplant of the recovered binary's export.
uint32_t AHardwareBuffer_getFd(AHardwareBuffer *buffer) {
    const native_handle_t *handle = AHardwareBuffer_getNativeHandle(buffer);
    if (handle && handle->numFds > 0) {
        return (uint32_t)handle->data[0];
    }
    return 0xFFFFFFFF;
}

// ── createHardwareBuffer ──────────────────────────────────────────────────────
AHardwareBuffer *createHardwareBuffer(int32_t w, int32_t h, int32_t layers, uint64_t usage) {
    AHardwareBuffer_Desc desc = {
        .width  = (uint32_t)w,
        .height = (uint32_t)h,
        .layers = (uint32_t)layers,
        .format = AHARDWAREBUFFER_FORMAT_R8G8B8A8_UNORM,
        .usage  = usage,
        .stride = 0,
        .rfu0   = 0,
        .rfu1   = 0,
    };
    AHardwareBuffer *buf = NULL;
    AHardwareBuffer_allocate(&desc, &buf);
    return buf;
}

// ── createImageKHR ────────────────────────────────────────────────────────────
EGLImageKHR createImageKHR(AHardwareBuffer *buffer) {
    typedef EGLImageKHR (*pfn_eglCreateImageKHR)(EGLDisplay, EGLContext, EGLenum,
                                                  EGLClientBuffer, const EGLint *);
    static pfn_eglCreateImageKHR pfn = NULL;
    if (!pfn) pfn = (pfn_eglCreateImageKHR)eglGetProcAddress("eglCreateImageKHR");
    if (!pfn) return EGL_NO_IMAGE_KHR;

    typedef EGLClientBuffer (*pfn_eglGetNativeClientBufferANDROID)(const AHardwareBuffer *);
    static pfn_eglGetNativeClientBufferANDROID pfn2 = NULL;
    if (!pfn2) pfn2 = (pfn_eglGetNativeClientBufferANDROID)
        eglGetProcAddress("eglGetNativeClientBufferANDROID");
    if (!pfn2) return EGL_NO_IMAGE_KHR;

    EGLClientBuffer cb = pfn2(buffer);
    EGLint attrs[] = { EGL_NONE };
    return pfn(eglGetDisplay(EGL_DEFAULT_DISPLAY), EGL_NO_CONTEXT,
               0x3140 /* EGL_NATIVE_BUFFER_ANDROID */, cb, attrs);
}

// ── GPUImage JNI ─────────────────────────────────────────────────────────────

JNIEXPORT jlong JNICALL
Java_com_winlator_renderer_GPUImage_createHardwareBuffer(
    JNIEnv *env, jclass cls, jint w, jint h, jint layers, jlong usage)
{
    (void)env; (void)cls;
    return (jlong)(uintptr_t)createHardwareBuffer(w, h, layers, (uint64_t)usage);
}

JNIEXPORT jlong JNICALL
Java_com_winlator_renderer_GPUImage_createImageKHR(
    JNIEnv *env, jclass cls, jlong hw_buf_ptr)
{
    (void)env; (void)cls;
    return (jlong)(uintptr_t)createImageKHR((AHardwareBuffer *)(uintptr_t)hw_buf_ptr);
}

JNIEXPORT void JNICALL
Java_com_winlator_renderer_GPUImage_destroyHardwareBuffer(
    JNIEnv *env, jclass cls, jlong hw_buf_ptr)
{
    (void)env; (void)cls;
    if (hw_buf_ptr) AHardwareBuffer_release((AHardwareBuffer *)(uintptr_t)hw_buf_ptr);
}

JNIEXPORT jlong JNICALL
Java_com_winlator_renderer_GPUImage_lockHardwareBuffer(
    JNIEnv *env, jclass cls, jlong hw_buf_ptr)
{
    (void)env; (void)cls;
    void *data = NULL;
    AHardwareBuffer_lock((AHardwareBuffer *)(uintptr_t)hw_buf_ptr,
                         AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, NULL, &data);
    return (jlong)(uintptr_t)data;
}

JNIEXPORT void JNICALL
Java_com_winlator_renderer_GPUImage_destroyImageKHR(
    JNIEnv *env, jclass cls, jlong img_ptr)
{
    (void)env; (void)cls;
    if (!img_ptr) return;
    typedef EGLBoolean (*pfn_eglDestroyImageKHR)(EGLDisplay, EGLImageKHR);
    static pfn_eglDestroyImageKHR pfn = NULL;
    if (!pfn) pfn = (pfn_eglDestroyImageKHR)eglGetProcAddress("eglDestroyImageKHR");
    if (pfn) pfn(eglGetDisplay(EGL_DEFAULT_DISPLAY), (EGLImageKHR)(uintptr_t)img_ptr);
}

// ── GPUHelper JNI ─────────────────────────────────────────────────────────────

JNIEXPORT void JNICALL
Java_com_winlator_core_GPUHelper_setGlobalEGLContext(JNIEnv *env, jclass cls)
{
    (void)env; (void)cls;
    globalEGLContext = eglGetCurrentContext();
}

JNIEXPORT jlong JNICALL
Java_com_winlator_core_GPUHelper_vkGetApiVersion(JNIEnv *env, jclass cls)
{
    // TODO: transplant Vulkan API version detection logic
    // (reads /data/data/com.winlator/cache/.vk-api-version, falls back to vkEnumerateInstanceVersion)
    (void)env; (void)cls;
    return 0;
}

JNIEXPORT jstring JNICALL
Java_com_winlator_core_GPUHelper_vkGetDeviceExtensions(JNIEnv *env, jclass cls)
{
    // TODO: transplant Vulkan device extension enumeration logic
    (void)env; (void)cls;
    return NULL;
}
