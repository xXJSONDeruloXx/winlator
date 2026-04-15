package com.winlator.renderer;

import androidx.annotation.Keep;
import com.winlator.xserver.Drawable;
import java.nio.ByteBuffer;

/* JADX INFO: loaded from: classes.dex */
public class GPUImage extends Texture {
    private long hardwareBufferPtr;
    private long imageKHRPtr;
    private boolean locked;
    private int nativeHandle;
    private short stride;
    private ByteBuffer virtualData;

    private native long createHardwareBuffer(short s, short s2, boolean z, boolean z2);

    private native long createImageKHR(long j, int i);

    private native void destroyHardwareBuffer(long j, boolean z);

    private native void destroyImageKHR(long j);

    private native ByteBuffer lockHardwareBuffer(long j);

    static {
        System.loadLibrary("winlator");
    }

    public GPUImage(Drawable owner) {
        this(owner, true, true);
    }

    public GPUImage(Drawable owner, boolean cpuAccess) {
        this(owner, cpuAccess, true);
    }

    public GPUImage(Drawable owner, boolean cpuAccess, boolean useHALPixelFormatBGRA8888) {
        super(owner);
        this.locked = false;
        long jCreateHardwareBuffer = createHardwareBuffer(owner.width, owner.height, cpuAccess, useHALPixelFormatBGRA8888);
        this.hardwareBufferPtr = jCreateHardwareBuffer;
        if (cpuAccess && jCreateHardwareBuffer != 0) {
            this.virtualData = lockHardwareBuffer(jCreateHardwareBuffer);
            this.locked = true;
        }
    }

    @Override // com.winlator.renderer.Texture
    public void allocateTexture(short width, short height, ByteBuffer data) {
        if (isAllocated()) {
            return;
        }
        super.allocateTexture(width, height, null);
        this.imageKHRPtr = createImageKHR(this.hardwareBufferPtr, this.textureId);
    }

    @Override // com.winlator.renderer.Texture
    public void updateFromDrawable() {
        Drawable drawable;
        if (!isAllocated() && (drawable = this.owner) != null) {
            allocateTexture(drawable.width, drawable.height, null);
        }
        this.needsUpdate = false;
    }

    public short getStride() {
        return this.stride;
    }

    @Keep
    private void setStride(short stride) {
        this.stride = stride;
    }

    public int getNativeHandle() {
        return this.nativeHandle;
    }

    @Keep
    private void setNativeHandle(int nativeHandle) {
        this.nativeHandle = nativeHandle;
    }

    public ByteBuffer getVirtualData() {
        return this.virtualData;
    }

    @Override // com.winlator.renderer.Texture
    public void destroy() {
        destroyImageKHR(this.imageKHRPtr);
        destroyHardwareBuffer(this.hardwareBufferPtr, this.locked);
        this.virtualData = null;
        this.imageKHRPtr = 0L;
        this.hardwareBufferPtr = 0L;
        super.destroy();
    }

    public long getHardwareBufferPtr() {
        return this.hardwareBufferPtr;
    }
}
