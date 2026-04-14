package com.winlator.xserver.extensions;

import android.util.SparseArray;
import android.util.SparseLongArray;
import androidx.annotation.Keep;
import com.winlator.core.Callback;
import com.winlator.renderer.Texture;
import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xconnector.XStreamLock;
import com.winlator.xserver.Drawable;
import com.winlator.xserver.Window;
import com.winlator.xserver.XClient;
import com.winlator.xserver.XServer;
import com.winlator.xserver.errors.BadAlloc;
import com.winlator.xserver.errors.BadImplementation;
import com.winlator.xserver.errors.GLXBadContext;
import com.winlator.xserver.errors.GLXBadFBConfig;
import com.winlator.xserver.errors.XRequestError;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class GLXExtension extends Extension {
    private final SparseArray<SparseLongArray> clientGLContexts;
    private final SparseArray<SparseLongArray> clientGLXContexts;
    private final String glxExtensions;
    private final Callback<XClient> onDestroyClientListener;

    private native long createGLContext(int i);

    private native long createGLXContext(int i, long j);

    private native void destroyGLContext(long j);

    private native void destroyGLXContext(long j);

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$new$0(XClient client) {
        destroyAllGLContexts(client.fd);
        destroyAllGLXContexts(client.fd);
    }

    static {
        System.loadLibrary("gladiorenderer");
    }

    public GLXExtension(XServer xServer, byte majorOpcode) {
        super(xServer, majorOpcode);
        this.clientGLXContexts = new SparseArray<>();
        this.clientGLContexts = new SparseArray<>();
        this.glxExtensions = "GLX_ARB_create_context GLX_ARB_get_proc_address";
        this.onDestroyClientListener = new Callback() { // from class: com.winlator.xserver.extensions.GLXExtension$$ExternalSyntheticLambda0
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                this.f$0.lambda$new$0((XClient) obj);
            }
        };
    }

    @Override // com.winlator.xserver.extensions.Extension
    public String getName() {
        return "GLX";
    }

    @Override // com.winlator.xserver.extensions.Extension
    public byte getFirstErrorId() {
        return (byte) -128;
    }

    private void createGLContext(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int contextId = inputStream.readInt();
        SparseLongArray contexts = this.clientGLContexts.get(client.fd);
        if (contexts == null) {
            SparseArray<SparseLongArray> sparseArray = this.clientGLContexts;
            int i = client.fd;
            SparseLongArray sparseLongArray = new SparseLongArray();
            contexts = sparseLongArray;
            sparseArray.put(i, sparseLongArray);
            client.addOnDestroyListener(this.onDestroyClientListener);
        }
        long context = createGLContext(client.fd);
        if (context != 0) {
            contexts.put(contextId, context);
        }
    }

    private void destroyGLContext(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int contextId = inputStream.readInt();
        SparseLongArray contexts = this.clientGLContexts.get(client.fd);
        if (contexts == null) {
            throw new GLXBadContext();
        }
        long context = contexts.get(contextId, 0L);
        if (context != 0) {
            destroyGLContext(context);
        }
        contexts.delete(contextId);
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writePad(28);
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

    private void createGLXContextForClient(XClient client, int contextId, int shareContextId) throws XRequestError, IOException {
        synchronized (this.clientGLXContexts) {
            SparseLongArray contexts = this.clientGLXContexts.get(client.fd);
            if (contexts == null) {
                SparseArray<SparseLongArray> sparseArray = this.clientGLXContexts;
                int i = client.fd;
                SparseLongArray sparseLongArray = new SparseLongArray();
                contexts = sparseLongArray;
                sparseArray.put(i, sparseLongArray);
                client.addOnDestroyListener(this.onDestroyClientListener);
            }
            long sharedContextPtr = shareContextId > 0 ? contexts.get(shareContextId) : 0L;
            long context = createGLXContext(contextId, sharedContextPtr);
            if (context == 0) {
                throw new BadAlloc();
            }
            contexts.put(contextId, context);
        }
    }

    private void createContext(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int contextId = inputStream.readInt();
        inputStream.skip(8);
        int shareList = inputStream.readInt();
        if (inputStream.readByte() == 1) {
        }
        if (contextId == 0) {
            throw new GLXBadContext();
        }
        createGLXContextForClient(client, contextId, shareList);
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writePad(28);
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

    private void destroyContext(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int contextId = inputStream.readInt();
        synchronized (this.clientGLXContexts) {
            SparseLongArray contexts = this.clientGLXContexts.get(client.fd);
            if (contexts == null) {
                throw new GLXBadContext();
            }
            long context = contexts.get(contextId);
            if (context == 0) {
                throw new GLXBadContext();
            }
            destroyGLXContext(context);
            contexts.delete(contextId);
        }
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
            outputStream.writeInt(4);
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

    private void queryExtensionsString(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        inputStream.skip(4);
        int length = "GLX_ARB_create_context GLX_ARB_get_proc_address".length();
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt((((-length) & 3) + length) / 4);
            outputStream.writeInt(0);
            outputStream.writeInt(length);
            outputStream.writePad(16);
            outputStream.writeString8("GLX_ARB_create_context GLX_ARB_get_proc_address");
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

    private void queryServerString(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        inputStream.skip(4);
        int name = inputStream.readInt();
        String string = "";
        switch (name) {
            case 1:
                string = "Winlator";
                break;
            case 2:
                string = "1.4";
                break;
            case 3:
                string = "GLX_ARB_create_context GLX_ARB_get_proc_address";
                break;
        }
        int length = string.length();
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt((((-length) & 3) + length) / 4);
            outputStream.writeInt(0);
            outputStream.writeInt(length);
            outputStream.writePad(16);
            outputStream.writeString8(string);
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

    private void getFBConfigs(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        inputStream.skip(4);
        int[] properties = {32787, 1, 8, 8, 9, 8, 10, 8, 11, 8, 12, 24, 13, 8, 2, 32, 5, 1, 32784, 1, 32785, 1};
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt(22);
            outputStream.writeInt(1);
            outputStream.writeInt(11);
            outputStream.writePad(16);
            int k = 0;
            for (int i = 0; i < 1; i++) {
                int j = 0;
                while (j < 11) {
                    outputStream.writeInt(properties[(k * 2) + 0]);
                    outputStream.writeInt(properties[(k * 2) + 1]);
                    j++;
                    k++;
                }
            }
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

    private void createContextAttribsARB(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int contextId = inputStream.readInt();
        int fbConfigId = inputStream.readInt();
        inputStream.skip(4);
        int shareContext = inputStream.readInt();
        inputStream.skip(4);
        int numAttribs = inputStream.readInt();
        if (contextId == 0) {
            throw new GLXBadContext();
        }
        if (fbConfigId != 1) {
            throw new GLXBadFBConfig();
        }
        int glMajorVersion = 3;
        int glMinorVersion = 3;
        for (int i = 0; i < numAttribs; i++) {
            int name = inputStream.readInt();
            int value = inputStream.readInt();
            if (name == 8337) {
                glMajorVersion = value;
            } else if (name == 8338) {
                glMinorVersion = value;
            }
        }
        boolean success = glMajorVersion <= 3 && glMinorVersion <= 3;
        if (success) {
            createGLXContextForClient(client, contextId, shareContext);
        }
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte(success ? (byte) 1 : (byte) 0);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writePad(28);
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

    @Override // com.winlator.xserver.extensions.Extension
    public void handleRequest(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int opcode = client.getRequestData();
        switch (opcode) {
            case 1:
                createGLContext(client, inputStream, outputStream);
                return;
            case 2:
                destroyGLContext(client, inputStream, outputStream);
                return;
            case 3:
                createContext(client, inputStream, outputStream);
                return;
            case 4:
                destroyContext(client, inputStream, outputStream);
                return;
            case 7:
                queryVersion(client, inputStream, outputStream);
                return;
            case 18:
                queryExtensionsString(client, inputStream, outputStream);
                return;
            case 19:
                queryServerString(client, inputStream, outputStream);
                return;
            case 21:
                getFBConfigs(client, inputStream, outputStream);
                return;
            case 34:
                createContextAttribsARB(client, inputStream, outputStream);
                return;
            default:
                throw new BadImplementation();
        }
    }

    @Keep
    private short[] getWindowSize(int windowId) {
        Window window = this.xServer.windowManager.getWindow(windowId);
        short[] sArr = {0, 0};
        if (window != null) {
            sArr[0] = window.getWidth();
            sArr[1] = window.getHeight();
        }
        return sArr;
    }

    @Keep
    private void clearWindowContent(int windowId) {
        Window window = this.xServer.windowManager.getWindow(windowId);
        if (window != null) {
            Drawable drawable = window.getContent();
            if (drawable.getData() != null) {
                drawable.setData(null);
                drawable.getTexture().destroy();
            }
        }
    }

    @Keep
    private boolean updateWindowContent(int drawableId, short width, short height, boolean flipY) {
        Drawable drawable = this.xServer.drawableManager.getDrawable(drawableId);
        if (drawable == null) {
            return true;
        }
        synchronized (drawable.renderLock) {
            if (drawable.width == width && drawable.height == height) {
                drawable.setData(null);
                Texture texture = drawable.getTexture();
                texture.setFlipY(flipY);
                texture.copyFromReadBuffer(width, height);
                Runnable onDrawListener = drawable.getOnDrawListener();
                if (onDrawListener != null) {
                    onDrawListener.run();
                }
                return true;
            }
            return false;
        }
    }

    @Keep
    private long getGLXContextPtr(int clientFd, int id) {
        long j;
        synchronized (this.clientGLXContexts) {
            SparseLongArray contexts = this.clientGLXContexts.get(clientFd);
            j = contexts != null ? contexts.get(id) : 0L;
        }
        return j;
    }

    private void destroyAllGLContexts(int clientFd) {
        synchronized (this.clientGLContexts) {
            SparseLongArray contexts = this.clientGLContexts.get(clientFd);
            if (contexts != null) {
                for (int i = 0; i < contexts.size(); i++) {
                    destroyGLContext(contexts.valueAt(i));
                }
                contexts.clear();
            }
            this.clientGLContexts.remove(clientFd);
        }
    }

    private void destroyAllGLXContexts(int clientFd) {
        synchronized (this.clientGLXContexts) {
            SparseLongArray contexts = this.clientGLXContexts.get(clientFd);
            if (contexts != null) {
                for (int i = 0; i < contexts.size(); i++) {
                    destroyGLXContext(contexts.valueAt(i));
                }
                contexts.clear();
            }
            this.clientGLXContexts.remove(clientFd);
        }
    }
}
