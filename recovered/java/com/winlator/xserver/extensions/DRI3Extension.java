package com.winlator.xserver.extensions;

import com.winlator.core.Callback;
import com.winlator.renderer.GPUImage;
import com.winlator.renderer.Texture;
import com.winlator.sysvshm.SysVSharedMemory;
import com.winlator.widget.XServerView;
import com.winlator.xconnector.XConnectorEpoll;
import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xconnector.XStreamLock;
import com.winlator.xenvironment.components.VortekRendererComponent$$ExternalSyntheticLambda0;
import com.winlator.xserver.Drawable;
import com.winlator.xserver.Pixmap;
import com.winlator.xserver.Window;
import com.winlator.xserver.XClient;
import com.winlator.xserver.XLock;
import com.winlator.xserver.XServer;
import com.winlator.xserver.errors.BadAlloc;
import com.winlator.xserver.errors.BadDrawable;
import com.winlator.xserver.errors.BadIdChoice;
import com.winlator.xserver.errors.BadImplementation;
import com.winlator.xserver.errors.BadPixmap;
import com.winlator.xserver.errors.BadWindow;
import com.winlator.xserver.errors.XRequestError;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.Objects;

/* JADX INFO: loaded from: classes.dex */
public class DRI3Extension extends Extension {
    private final Callback<Drawable> onDestroyDrawableListener;

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$new$0(Drawable drawable) {
        ByteBuffer data = drawable.getData();
        SysVSharedMemory.unmapSHMSegment(data, data.capacity());
    }

    public DRI3Extension(XServer xServer, byte majorOpcode) {
        super(xServer, majorOpcode);
        this.onDestroyDrawableListener = new Callback() { // from class: com.winlator.xserver.extensions.DRI3Extension$$ExternalSyntheticLambda0
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                DRI3Extension.lambda$new$0((Drawable) obj);
            }
        };
    }

    @Override // com.winlator.xserver.extensions.Extension
    public String getName() {
        return "DRI3";
    }

    private void queryVersion(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        inputStream.skip(8);
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt(0);
            outputStream.writeInt(1);
            outputStream.writeInt(0);
            outputStream.writePad(16);
            if (lock != null) {
                lock.close();
            }
        } catch (Throwable th) {
            if (lock != null) {
                try {
                    lock.close();
                } catch (Throwable th2) {
                    th.addSuppressed(th2);
                }
            }
            throw th;
        }
    }

    private void open(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int drawableId = inputStream.readInt();
        inputStream.skip(4);
        Drawable drawable = this.xServer.drawableManager.getDrawable(drawableId);
        if (drawable == null) {
            throw new BadDrawable(drawableId);
        }
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt(0);
            outputStream.writePad(24);
            if (lock != null) {
                lock.close();
            }
        } catch (Throwable th) {
            if (lock != null) {
                try {
                    lock.close();
                } catch (Throwable th2) {
                    th.addSuppressed(th2);
                }
            }
            throw th;
        }
    }

    private void pixmapFromBuffer(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int pixmapId = inputStream.readInt();
        int windowId = inputStream.readInt();
        int size = inputStream.readInt();
        short width = inputStream.readShort();
        short height = inputStream.readShort();
        short stride = inputStream.readShort();
        byte depth = inputStream.readByte();
        inputStream.skip(1);
        Window window = this.xServer.windowManager.getWindow(windowId);
        if (window == null) {
            throw new BadWindow(windowId);
        }
        Pixmap pixmap = this.xServer.pixmapManager.getPixmap(pixmapId);
        if (pixmap != null) {
            throw new BadIdChoice(pixmapId);
        }
        int fd = inputStream.getAncillaryFd();
        pixmapFromFd(client, pixmapId, width, height, stride, 0, depth, fd, size);
    }

    private void bufferFromPixmap(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int windowId = inputStream.readInt();
        Window window = this.xServer.windowManager.getWindow(windowId);
        if (window == null) {
            throw new BadPixmap(windowId);
        }
        Drawable content = window.getContent();
        Texture texture = content.getTexture();
        if (!(texture instanceof GPUImage)) {
            XServerView xServerView = this.xServer.getRenderer().xServerView;
            Objects.requireNonNull(texture);
            xServerView.queueEvent(new VortekRendererComponent$$ExternalSyntheticLambda0(texture));
            content.setTexture(new GPUImage(content, false));
        }
        GPUImage gpuImage = (GPUImage) content.getTexture();
        short stride = gpuImage.getStride();
        int nativeHandle = gpuImage.getNativeHandle();
        this.xServer.debugPrint("bufferFromPixmap handle " + nativeHandle + ", width " + ((int) content.width) + ", height " + ((int) content.height) + ", stride " + ((int) stride));
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 1);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt(0);
            outputStream.writeInt(content.height * stride * 4);
            outputStream.writeShort(content.width);
            outputStream.writeShort(content.height);
            outputStream.writeShort(stride);
            outputStream.writeByte((byte) 32);
            outputStream.writeByte((byte) 32);
            outputStream.writePad(12);
            outputStream.setAncillaryFd(nativeHandle);
            if (lock != null) {
                lock.close();
            }
        } catch (Throwable th) {
            if (lock != null) {
                try {
                    lock.close();
                } catch (Throwable th2) {
                    th.addSuppressed(th2);
                }
            }
            throw th;
        }
    }

    private void pixmapFromBuffers(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int pixmapId = inputStream.readInt();
        int windowId = inputStream.readInt();
        inputStream.skip(4);
        short width = inputStream.readShort();
        short height = inputStream.readShort();
        int stride = inputStream.readInt();
        int offset = inputStream.readInt();
        inputStream.skip(24);
        byte depth = inputStream.readByte();
        inputStream.skip(11);
        Window window = this.xServer.windowManager.getWindow(windowId);
        if (window == null) {
            throw new BadWindow(windowId);
        }
        Pixmap pixmap = this.xServer.pixmapManager.getPixmap(pixmapId);
        if (pixmap != null) {
            throw new BadIdChoice(pixmapId);
        }
        int fd = inputStream.getAncillaryFd();
        long size = ((long) stride) * ((long) height);
        pixmapFromFd(client, pixmapId, width, height, stride, offset, depth, fd, size);
    }

    private void pixmapFromFd(XClient client, int pixmapId, short width, short height, int stride, int offset, byte depth, int fd, long size) throws XRequestError, IOException {
        try {
            ByteBuffer buffer = SysVSharedMemory.mapSHMSegment(fd, size, offset, true);
            if (buffer == null) {
                throw new BadAlloc();
            }
            short totalWidth = (short) (stride / 4);
            Drawable drawable = this.xServer.drawableManager.createDrawable(pixmapId, totalWidth, height, depth);
            drawable.setData(buffer);
            drawable.setTexture(null);
            drawable.setOnDestroyListener(this.onDestroyDrawableListener);
            this.xServer.pixmapManager.createPixmap(drawable);
        } finally {
            XConnectorEpoll.closeFd(fd);
        }
    }

    @Override // com.winlator.xserver.extensions.Extension
    public void handleRequest(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        XLock lock;
        int opcode = client.getRequestData();
        switch (opcode) {
            case 0:
                queryVersion(client, inputStream, outputStream);
                return;
            case 1:
                XLock lock2 = this.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER);
                try {
                    open(client, inputStream, outputStream);
                    if (lock2 != null) {
                        lock2.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock2 != null) {
                        try {
                            lock2.close();
                        } catch (Throwable th) {
                            th.addSuppressed(th);
                        }
                        break;
                    }
                }
            case 2:
                lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                try {
                    pixmapFromBuffer(client, inputStream, outputStream);
                    if (lock != null) {
                        lock.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock != null) {
                        try {
                            lock.close();
                        } catch (Throwable th2) {
                            th.addSuppressed(th2);
                        }
                        break;
                    }
                }
            case 3:
                lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                try {
                    bufferFromPixmap(client, inputStream, outputStream);
                    if (lock != null) {
                        lock.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock != null) {
                        try {
                            break;
                        } catch (Throwable th22) {
                        }
                    }
                }
            case 4:
            case 5:
            case 6:
            default:
                throw new BadImplementation();
            case 7:
                lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.PIXMAP_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                try {
                    pixmapFromBuffers(client, inputStream, outputStream);
                    if (lock != null) {
                        lock.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock != null) {
                        try {
                            break;
                        } catch (Throwable th222) {
                        }
                    }
                }
        }
    }
}
