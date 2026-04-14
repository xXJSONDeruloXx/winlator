package com.winlator.xserver.extensions;

import android.util.SparseArray;
import com.winlator.core.Bitmask;
import com.winlator.renderer.GPUImage;
import com.winlator.renderer.Texture;
import com.winlator.widget.XServerView;
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
import com.winlator.xserver.errors.BadImplementation;
import com.winlator.xserver.errors.BadMatch;
import com.winlator.xserver.errors.BadWindow;
import com.winlator.xserver.errors.XRequestError;
import com.winlator.xserver.events.PresentCompleteNotify;
import com.winlator.xserver.events.PresentIdleNotify;
import java.io.IOException;
import java.util.Objects;

/* JADX INFO: loaded from: classes.dex */
public class PresentExtension extends Extension {
    private final SparseArray<Event> events;
    private SyncExtension syncExtension;

    public enum Kind {
        PIXMAP,
        MSC_NOTIFY
    }

    public enum Mode {
        COPY,
        FLIP,
        SKIP
    }

    private static class Event {
        private XClient client;
        private int id;
        private Bitmask mask;
        private Window window;

        private Event() {
        }
    }

    public PresentExtension(XServer xServer, byte majorOpcode) {
        super(xServer, majorOpcode);
        this.events = new SparseArray<>();
    }

    @Override // com.winlator.xserver.extensions.Extension
    public String getName() {
        return "Present";
    }

    private void sendIdleNotify(Window window, Pixmap pixmap, int serial, int idleFence) throws Throwable {
        if (idleFence != 0) {
            this.syncExtension.setTriggered(idleFence);
        }
        if (this.events.size() == 0) {
            return;
        }
        synchronized (this.events) {
            for (int i = 0; i < this.events.size(); i++) {
                try {
                    Event event = this.events.valueAt(i);
                    if (event.window == window) {
                        try {
                            if (event.mask.isSet(PresentIdleNotify.getEventMask())) {
                                event.client.sendEvent(new PresentIdleNotify(this, event.id, window, pixmap, serial, idleFence));
                            }
                        } catch (Throwable th) {
                            th = th;
                            throw th;
                        }
                    }
                } catch (Throwable th2) {
                    th = th2;
                }
            }
        }
    }

    private void sendCompleteNotify(Window window, int serial, Kind kind, Mode mode, long ust, long msc) throws Throwable {
        long ust2;
        long msc2;
        SparseArray<Event> sparseArray;
        int i;
        PresentExtension presentExtension = this;
        if (presentExtension.events.size() == 0) {
            return;
        }
        if (ust == 0 && msc == 0) {
            long ust3 = System.nanoTime() / 1000;
            ust2 = ust3;
            msc2 = ust3 / 16666;
        } else {
            ust2 = ust;
            msc2 = msc;
        }
        SparseArray<Event> sparseArray2 = presentExtension.events;
        synchronized (sparseArray2) {
            int i2 = 0;
            while (i2 < presentExtension.events.size()) {
                try {
                    Event event = presentExtension.events.valueAt(i2);
                    if (event.window == window && event.mask.isSet(PresentCompleteNotify.getEventMask())) {
                        i = i2;
                        sparseArray = sparseArray2;
                        try {
                            event.client.sendEvent(new PresentCompleteNotify(this, event.id, window, serial, kind, mode, ust2, msc2));
                        } catch (Throwable th) {
                            th = th;
                            throw th;
                        }
                    } else {
                        i = i2;
                        sparseArray = sparseArray2;
                    }
                    i2 = i + 1;
                    presentExtension = this;
                    sparseArray2 = sparseArray;
                } catch (Throwable th2) {
                    th = th2;
                    sparseArray = sparseArray2;
                }
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

    private void presentPixmap(XClient client, XInputStream inputStream, XOutputStream outputStream) throws Throwable {
        Object obj;
        Window window;
        Pixmap pixmap;
        int windowId = inputStream.readInt();
        int pixmapId = inputStream.readInt();
        int serial = inputStream.readInt();
        inputStream.skip(8);
        short xOff = inputStream.readShort();
        short yOff = inputStream.readShort();
        inputStream.skip(8);
        int idleFence = inputStream.readInt();
        inputStream.skip(client.getRemainingRequestLength());
        Window window2 = this.xServer.windowManager.getWindow(windowId);
        if (window2 == null) {
            throw new BadWindow(windowId);
        }
        Pixmap pixmap2 = this.xServer.pixmapManager.getPixmap(pixmapId);
        Drawable content = window2.getContent();
        if (pixmap2 != null && content.visual.depth != pixmap2.drawable.visual.depth) {
            throw new BadMatch();
        }
        Object obj2 = content.renderLock;
        synchronized (obj2) {
            try {
                if (pixmap2 != null) {
                    try {
                        Drawable drawable = pixmap2.drawable;
                        obj = obj2;
                        window = window2;
                        try {
                            content.copyArea((short) 0, (short) 0, xOff, yOff, drawable.width, drawable.height, drawable);
                            pixmap = pixmap2;
                            try {
                                sendIdleNotify(window, pixmap, serial, idleFence);
                            } catch (Throwable th) {
                                th = th;
                                throw th;
                            }
                        } catch (Throwable th2) {
                            th = th2;
                        }
                    } catch (Throwable th3) {
                        th = th3;
                        obj = obj2;
                    }
                } else {
                    obj = obj2;
                    window = window2;
                    pixmap = pixmap2;
                    try {
                        content.forceUpdate();
                    } catch (Throwable th4) {
                        th = th4;
                        throw th;
                    }
                }
                sendCompleteNotify(window, serial, Kind.PIXMAP, Mode.COPY, 0L, 0L);
            } catch (Throwable th5) {
                th = th5;
            }
        }
    }

    private void selectInput(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int eventId = inputStream.readInt();
        int windowId = inputStream.readInt();
        Bitmask mask = new Bitmask(inputStream.readInt());
        Window window = this.xServer.windowManager.getWindow(windowId);
        if (window == null) {
            throw new BadWindow(windowId);
        }
        Drawable content = window.getContent();
        Texture texture = content.getTexture();
        if (!(texture instanceof GPUImage)) {
            XServerView xServerView = this.xServer.getRenderer().xServerView;
            Objects.requireNonNull(texture);
            xServerView.queueEvent(new VortekRendererComponent$$ExternalSyntheticLambda0(texture));
            content.setTexture(new GPUImage(content));
        }
        if (eventId > 0) {
            synchronized (this.events) {
                Event event = this.events.get(eventId);
                if (event != null) {
                    if (event.window != window || event.client != client) {
                        throw new BadMatch();
                    }
                    if (!mask.isEmpty()) {
                        event.mask = mask;
                    } else {
                        this.events.remove(eventId);
                    }
                } else {
                    Event event2 = new Event();
                    event2.id = eventId;
                    event2.window = window;
                    event2.client = client;
                    event2.mask = mask;
                    this.events.put(eventId, event2);
                }
            }
        }
    }

    @Override // com.winlator.xserver.extensions.Extension
    public void handleRequest(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        XLock lock;
        int opcode = client.getRequestData();
        if (this.syncExtension == null) {
            this.syncExtension = (SyncExtension) this.xServer.getExtensionByName("SYNC");
        }
        switch (opcode) {
            case 0:
                queryVersion(client, inputStream, outputStream);
                return;
            case 1:
                lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.PIXMAP_MANAGER);
                try {
                    presentPixmap(client, inputStream, outputStream);
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
                lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER);
                try {
                    selectInput(client, inputStream, outputStream);
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
