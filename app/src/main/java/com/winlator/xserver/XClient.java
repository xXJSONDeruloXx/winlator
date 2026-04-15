package com.winlator.xserver;

import androidx.collection.ArrayMap;
import com.winlator.core.Bitmask;
import com.winlator.core.Callback;
import com.winlator.xconnector.ConnectedClient;
import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xserver.XResourceManager;
import com.winlator.xserver.events.Event;
import java.io.IOException;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class XClient extends ConnectedClient implements XResourceManager.OnResourceLifecycleListener {
    private boolean authenticated;
    private final ArrayMap<Window, EventListener> eventListeners;
    private int initialLength;
    private final ArrayList<Callback<XClient>> onDestroyListeners;
    private byte requestData;
    private int requestLength;
    public final Integer resourceIDBase;
    private final ArrayList<XResource> resources;
    private short sequenceNumber;
    public final XServer xServer;

    public XClient(long nativePtr, int fd, XServer xServer) {
        super(nativePtr, fd);
        this.authenticated = false;
        this.sequenceNumber = (short) 0;
        this.eventListeners = new ArrayMap<>();
        this.resources = new ArrayList<>();
        this.onDestroyListeners = new ArrayList<>();
        this.xServer = xServer;
        XLock lock = xServer.lockAll();
        try {
            this.resourceIDBase = xServer.resourceIDs.get();
            xServer.windowManager.addOnResourceLifecycleListener(this);
            xServer.pixmapManager.addOnResourceLifecycleListener(this);
            xServer.graphicsContextManager.addOnResourceLifecycleListener(this);
            xServer.cursorManager.addOnResourceLifecycleListener(this);
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

    public void registerAsOwnerOfResource(XResource resource) {
        this.resources.add(resource);
    }

    public void setEventListenerForWindow(Window window, Bitmask eventMask) {
        EventListener eventListener = this.eventListeners.get(window);
        if (eventListener != null) {
            window.removeEventListener(eventListener);
        }
        if (eventMask.isEmpty()) {
            return;
        }
        EventListener eventListener2 = new EventListener(this, eventMask);
        this.eventListeners.put(window, eventListener2);
        window.addEventListener(eventListener2);
    }

    public void sendEvent(Event event) {
        try {
            event.send(this.sequenceNumber, this.outputStream);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean isInterestedIn(int eventId, Window window) {
        EventListener eventListener = this.eventListeners.get(window);
        return eventListener != null && eventListener.isInterestedIn(eventId);
    }

    public boolean isAuthenticated() {
        return this.authenticated;
    }

    public void setAuthenticated(boolean authenticated) {
        this.authenticated = authenticated;
    }

    public void freeResources() {
        XLock lock = this.xServer.lockAll();
        while (!this.resources.isEmpty()) {
            try {
                XResource resource = this.resources.remove(this.resources.size() - 1);
                if (resource instanceof Window) {
                    this.xServer.windowManager.destroyWindow(resource.id);
                } else if (resource instanceof Pixmap) {
                    this.xServer.pixmapManager.freePixmap(resource.id);
                } else if (resource instanceof GraphicsContext) {
                    this.xServer.graphicsContextManager.freeGraphicsContext(resource.id);
                } else if (resource instanceof Cursor) {
                    this.xServer.cursorManager.freeCursor(resource.id);
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
        while (!this.eventListeners.isEmpty()) {
            int i = this.eventListeners.size() - 1;
            this.eventListeners.keyAt(i).removeEventListener(this.eventListeners.removeAt(i));
        }
        this.xServer.windowManager.removeOnResourceLifecycleListener(this);
        this.xServer.pixmapManager.removeOnResourceLifecycleListener(this);
        this.xServer.graphicsContextManager.removeOnResourceLifecycleListener(this);
        this.xServer.cursorManager.removeOnResourceLifecycleListener(this);
        this.xServer.resourceIDs.free(this.resourceIDBase);
        if (lock != null) {
            lock.close();
        }
    }

    public void generateSequenceNumber() {
        this.sequenceNumber = (short) (this.sequenceNumber + 1);
    }

    public short getSequenceNumber() {
        return this.sequenceNumber;
    }

    public void setRequestLength(int requestLength) {
        this.requestLength = requestLength;
        this.initialLength = this.inputStream.available();
    }

    public byte getRequestData() {
        return this.requestData;
    }

    public void setRequestData(byte requestData) {
        this.requestData = requestData;
    }

    public int getRemainingRequestLength() {
        int actualLength = this.initialLength - this.inputStream.available();
        return this.requestLength - actualLength;
    }

    public void skipRequest() {
        this.inputStream.skip(getRemainingRequestLength());
    }

    @Override // com.winlator.xconnector.ConnectedClient
    public XInputStream getInputStream() {
        return this.inputStream;
    }

    @Override // com.winlator.xconnector.ConnectedClient
    public XOutputStream getOutputStream() {
        return this.outputStream;
    }

    public Bitmask getEventMaskForWindow(Window window) {
        EventListener eventListener = this.eventListeners.get(window);
        return eventListener != null ? eventListener.eventMask : new Bitmask();
    }

    @Override // com.winlator.xserver.XResourceManager.OnResourceLifecycleListener
    public void onFreeResource(XResource resource) {
        if (resource instanceof Window) {
            this.eventListeners.remove(resource);
        }
        this.resources.remove(resource);
    }

    public boolean isValidResourceId(int id) {
        return this.xServer.resourceIDs.isInInterval(id, this.resourceIDBase.intValue());
    }

    public void addOnDestroyListener(Callback<XClient> onDestroyListener) {
        if (!this.onDestroyListeners.contains(onDestroyListener)) {
            this.onDestroyListeners.add(onDestroyListener);
        }
    }

    @Override // com.winlator.xconnector.ConnectedClient
    public void destroy() {
        super.destroy();
        for (Callback<XClient> onDestroyListener : this.onDestroyListeners) {
            onDestroyListener.call(this);
        }
    }
}
