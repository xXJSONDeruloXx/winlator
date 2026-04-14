package com.winlator.core;

import android.content.Context;
import android.content.SharedPreferences;
import androidx.collection.ArrayMap;
import androidx.preference.PreferenceManager;
import dalvik.annotation.optimization.CriticalNative;
import java.util.Locale;
import java.util.Objects;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.microedition.khronos.egl.EGL10;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.egl.EGLContext;
import javax.microedition.khronos.egl.EGLDisplay;
import javax.microedition.khronos.egl.EGLSurface;
import javax.microedition.khronos.opengles.GL10;

/* JADX INFO: loaded from: classes.dex */
public abstract class GPUHelper {
    public static int VK_API_VERSION_1_3 = vkMakeVersion(1, 3, 0);

    public static native void setGlobalEGLContext();

    @CriticalNative
    public static native int vkGetApiVersion();

    public static native String[] vkGetDeviceExtensions();

    static {
        System.loadLibrary("winlator");
    }

    private static ArrayMap<String, String> loadGPUInformation(final Context context) {
        final Thread thread = Thread.currentThread();
        final ArrayMap<String, String> gpuInfo = new ArrayMap<>();
        gpuInfo.put("renderer", "");
        gpuInfo.put("vendor", "");
        gpuInfo.put("version", "");
        new Thread(new Runnable() { // from class: com.winlator.core.GPUHelper$$ExternalSyntheticLambda0
            @Override // java.lang.Runnable
            public final void run() {
                GPUHelper.lambda$loadGPUInformation$0(gpuInfo, context, thread);
            }
        }).start();
        synchronized (thread) {
            try {
                thread.wait();
            } catch (InterruptedException e) {
            }
        }
        return gpuInfo;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$loadGPUInformation$0(ArrayMap gpuInfo, Context context, Thread thread) {
        int[] attribList = {12339, 1, 12352, 4, 12324, 8, 12323, 8, 12322, 8, 12321, 0, 12344};
        EGLConfig[] configs = new EGLConfig[1];
        int[] configCounts = new int[1];
        EGL10 egl = (EGL10) EGLContext.getEGL();
        EGLDisplay eglDisplay = egl.eglGetDisplay(EGL10.EGL_DEFAULT_DISPLAY);
        int[] version = new int[2];
        egl.eglInitialize(eglDisplay, version);
        egl.eglChooseConfig(eglDisplay, attribList, configs, 1, configCounts);
        int[] attribList2 = {12440, 2, 12344};
        EGLContext eglContext = egl.eglCreateContext(eglDisplay, configs[0], EGL10.EGL_NO_CONTEXT, attribList2);
        EGLSurface eGLSurface = EGL10.EGL_NO_SURFACE;
        egl.eglMakeCurrent(eglDisplay, eGLSurface, eGLSurface, eglContext);
        GL10 gl = (GL10) eglContext.getGL();
        String gpuRenderer = Objects.toString(gl.glGetString(7937), "");
        String gpuVendor = Objects.toString(gl.glGetString(7936), "");
        String gpuVersion = Objects.toString(gl.glGetString(7938), "");
        gpuInfo.put("renderer", gpuRenderer);
        gpuInfo.put("vendor", gpuVendor);
        gpuInfo.put("version", gpuVersion);
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        preferences.edit().putString("gpu_renderer", gpuRenderer).putString("gpu_vendor", gpuVendor).putString("gpu_version", gpuVersion).apply();
        synchronized (thread) {
            thread.notify();
        }
    }

    public static String glGetRenderer(Context context) {
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        String value = preferences.getString("gpu_renderer", "");
        if (!value.isEmpty()) {
            return value;
        }
        ArrayMap<String, String> gpuInfo = loadGPUInformation(context);
        return gpuInfo.get("renderer");
    }

    public static boolean isAdreno(Context context) {
        return glGetRenderer(context).toLowerCase(Locale.ENGLISH).contains("adreno");
    }

    public static int vkMakeVersion(String value) {
        Pattern pattern = Pattern.compile("([0-9]+)\\.([0-9]+)\\.?([0-9]+)?");
        Matcher matcher = pattern.matcher(value);
        if (!matcher.find()) {
            return 0;
        }
        try {
            int major = matcher.group(1) != null ? Integer.parseInt(matcher.group(1)) : 0;
            int minor = matcher.group(2) != null ? Integer.parseInt(matcher.group(2)) : 0;
            int patch = matcher.group(3) != null ? Integer.parseInt(matcher.group(3)) : 0;
            if (matcher.group(1) == null && patch == 0) {
                patch = minor;
            }
            return vkMakeVersion(major, minor, patch);
        } catch (NumberFormatException e) {
            return 0;
        }
    }

    public static int vkMakeVersion(int major, int minor, int patch) {
        return (major << 22) | (minor << 12) | patch;
    }

    public static int vkVersionMajor(int version) {
        return version >> 22;
    }

    public static int vkVersionMinor(int version) {
        return (version >> 12) & 1023;
    }
}
