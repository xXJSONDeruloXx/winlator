package com.winlator.xserver.extensions;

import com.winlator.renderer.Texture;
import com.winlator.widget.XServerView;
import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xconnector.XStreamLock;
import com.winlator.xenvironment.components.VortekRendererComponent$$ExternalSyntheticLambda0;
import com.winlator.xserver.Drawable;
import com.winlator.xserver.Window;
import com.winlator.xserver.XClient;
import com.winlator.xserver.XLock;
import com.winlator.xserver.XServer;
import com.winlator.xserver.errors.BadAccess;
import com.winlator.xserver.errors.BadImplementation;
import com.winlator.xserver.errors.BadMatch;
import com.winlator.xserver.errors.BadValue;
import com.winlator.xserver.errors.BadWindow;
import com.winlator.xserver.errors.XRequestError;
import java.io.IOException;
import java.util.Objects;

/* JADX INFO: loaded from: classes.dex */
public class XComposite extends Extension {

    public enum UpdateMode {
        REDIRECT_AUTOMATIC,
        REDIRECT_MANUAL
    }

    public XComposite(XServer xServer, byte majorOpcode) {
        super(xServer, majorOpcode);
    }

    @Override // com.winlator.xserver.extensions.Extension
    public String getName() {
        return "Composite";
    }

    private void setWindowsToOffscreenStorage(Window window, boolean offscreenStorage) {
        if (window.attributes.isMapped()) {
            window.getContent().setOffscreenStorage(offscreenStorage);
            for (Window child : window.getChildren()) {
                setWindowsToOffscreenStorage(child, offscreenStorage);
            }
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
            outputStream.writeInt(0);
            outputStream.writeInt(1);
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

    private void redirectWindow(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int windowId = inputStream.readInt();
        byte updateMode = inputStream.readByte();
        inputStream.skip(3);
        Window window = this.xServer.windowManager.getWindow(windowId);
        if (window == null) {
            throw new BadWindow(windowId);
        }
        if (window == this.xServer.windowManager.rootWindow) {
            throw new BadMatch();
        }
        if (window.getTag("compositeRedirectParent") != null) {
            throw new BadAccess();
        }
        if (window.isSurface()) {
            updateMode = (byte) UpdateMode.REDIRECT_AUTOMATIC.ordinal();
        }
        Window parent = window.getParent();
        window.setTag("compositeRedirectParent", parent);
        setWindowsToOffscreenStorage(window, true);
        parent.attributes.setRenderSubwindows(false);
        this.xServer.windowManager.triggerOnChangeWindowZOrder(window);
        if (updateMode == UpdateMode.REDIRECT_AUTOMATIC.ordinal()) {
            Drawable parentContent = parent.getContent();
            Texture texture = parentContent.getTexture();
            if (texture != null) {
                XServerView xServerView = this.xServer.getRenderer().xServerView;
                Objects.requireNonNull(texture);
                xServerView.queueEvent(new VortekRendererComponent$$ExternalSyntheticLambda0(texture));
            }
            parentContent.setTexture(window.getContent().getTexture());
        }
    }

    private void unredirectWindow(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int windowId = inputStream.readInt();
        byte updateMode = inputStream.readByte();
        inputStream.skip(3);
        Window window = this.xServer.windowManager.getWindow(windowId);
        if (window == null) {
            throw new BadWindow(windowId);
        }
        if (window == this.xServer.windowManager.rootWindow) {
            throw new BadMatch();
        }
        Window oldParent = (Window) window.getTag("compositeRedirectParent");
        if (oldParent == null) {
            throw new BadValue(windowId);
        }
        if (window.isSurface()) {
            updateMode = (byte) UpdateMode.REDIRECT_AUTOMATIC.ordinal();
        }
        window.removeTag("compositeRedirectParent");
        setWindowsToOffscreenStorage(window, false);
        oldParent.attributes.setRenderSubwindows(true);
        this.xServer.windowManager.triggerOnChangeWindowZOrder(window);
        if (updateMode == UpdateMode.REDIRECT_AUTOMATIC.ordinal()) {
            Drawable parentContent = oldParent.getContent();
            parentContent.setTexture(new Texture(parentContent));
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
                lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                try {
                    redirectWindow(client, inputStream, outputStream);
                    if (lock != null) {
                        lock.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock != null) {
                        try {
                            break;
                        } catch (Throwable th) {
                        }
                    }
                }
            case 2:
            default:
                throw new BadImplementation();
            case 3:
                lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
                try {
                    unredirectWindow(client, inputStream, outputStream);
                    if (lock != null) {
                        lock.close();
                        return;
                    }
                    return;
                } finally {
                    if (lock != null) {
                        try {
                            break;
                        } catch (Throwable th2) {
                        }
                    }
                }
        }
    }
}
