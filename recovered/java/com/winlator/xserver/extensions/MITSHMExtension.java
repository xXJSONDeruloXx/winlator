package com.winlator.xserver.extensions;

import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xconnector.XStreamLock;
import com.winlator.xserver.Drawable;
import com.winlator.xserver.GraphicsContext;
import com.winlator.xserver.XClient;
import com.winlator.xserver.XLock;
import com.winlator.xserver.XServer;
import com.winlator.xserver.errors.BadDrawable;
import com.winlator.xserver.errors.BadGraphicsContext;
import com.winlator.xserver.errors.BadImplementation;
import com.winlator.xserver.errors.BadSHMSegment;
import com.winlator.xserver.errors.XRequestError;
import java.io.IOException;
import java.nio.ByteBuffer;

/* JADX INFO: loaded from: classes.dex */
public class MITSHMExtension extends Extension {
    public MITSHMExtension(XServer xServer, byte majorOpcode) {
        super(xServer, majorOpcode);
    }

    @Override // com.winlator.xserver.extensions.Extension
    public String getName() {
        return "MIT-SHM";
    }

    @Override // com.winlator.xserver.extensions.Extension
    public byte getFirstErrorId() {
        return (byte) -128;
    }

    @Override // com.winlator.xserver.extensions.Extension
    public byte getFirstEventId() {
        return (byte) 64;
    }

    private void queryVersion(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt(0);
            outputStream.writeShort((short) 1);
            outputStream.writeShort((short) 1);
            outputStream.writeShort((short) 0);
            outputStream.writeShort((short) 0);
            outputStream.writeByte((byte) 0);
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

    private void attach(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int xid = inputStream.readInt();
        int shmid = inputStream.readInt();
        inputStream.skip(4);
        this.xServer.getSHMSegmentManager().attach(xid, shmid);
    }

    private void detach(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        this.xServer.getSHMSegmentManager().detach(inputStream.readInt());
    }

    private void putImage(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int drawableId = inputStream.readInt();
        int gcId = inputStream.readInt();
        short totalWidth = inputStream.readShort();
        short totalHeight = inputStream.readShort();
        short srcX = inputStream.readShort();
        short srcY = inputStream.readShort();
        short srcWidth = inputStream.readShort();
        short srcHeight = inputStream.readShort();
        short dstX = inputStream.readShort();
        short dstY = inputStream.readShort();
        byte depth = inputStream.readByte();
        inputStream.skip(3);
        int shmseg = inputStream.readInt();
        inputStream.skip(4);
        Drawable drawable = this.xServer.drawableManager.getDrawable(drawableId);
        if (drawable == null) {
            throw new BadDrawable(drawableId);
        }
        GraphicsContext graphicsContext = this.xServer.graphicsContextManager.getGraphicsContext(gcId);
        if (graphicsContext == null) {
            throw new BadGraphicsContext(gcId);
        }
        ByteBuffer data = this.xServer.getSHMSegmentManager().getData(shmseg);
        if (data == null) {
            throw new BadSHMSegment(shmseg);
        }
        if (graphicsContext.getFunction() != GraphicsContext.Function.COPY) {
            throw new UnsupportedOperationException("GC Function other than COPY is not supported.");
        }
        if (drawable.isUseSharedData()) {
            synchronized (drawable.renderLock) {
                if (drawable.getData() != data) {
                    drawable.setData(data);
                }
                drawable.forceUpdate();
            }
            return;
        }
        drawable.drawImage(srcX, srcY, dstX, dstY, srcWidth, srcHeight, depth, data, totalWidth, totalHeight);
    }

    private void createPixmap(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        inputStream.skip(4);
        int drawableId = inputStream.readInt();
        short width = inputStream.readShort();
        inputStream.skip(14);
        Drawable drawable = this.xServer.drawableManager.getDrawable(drawableId);
        if (drawable == null) {
            throw new BadDrawable(drawableId);
        }
        drawable.setUseSharedData(width == drawable.width);
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
                XLock lock2 = this.xServer.lock(XServer.Lockable.SHMSEGMENT_MANAGER);
                try {
                    attach(client, inputStream, outputStream);
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
                XLock lock3 = this.xServer.lock(XServer.Lockable.SHMSEGMENT_MANAGER);
                try {
                    detach(client, inputStream, outputStream);
                    if (lock3 != null) {
                        lock3.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock3 != null) {
                        try {
                            lock3.close();
                        } catch (Throwable th2) {
                            th.addSuppressed(th2);
                        }
                        break;
                    }
                }
            case 3:
                lock = this.xServer.lock(XServer.Lockable.SHMSEGMENT_MANAGER, XServer.Lockable.DRAWABLE_MANAGER, XServer.Lockable.GRAPHIC_CONTEXT_MANAGER);
                try {
                    putImage(client, inputStream, outputStream);
                    if (lock != null) {
                        lock.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock != null) {
                        try {
                            break;
                        } catch (Throwable th3) {
                        }
                    }
                }
            case 4:
            default:
                throw new BadImplementation();
            case 5:
                lock = this.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER);
                try {
                    createPixmap(client, inputStream, outputStream);
                    if (lock != null) {
                        lock.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock != null) {
                        try {
                            break;
                        } catch (Throwable th32) {
                        }
                    }
                }
        }
    }
}
