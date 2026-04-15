package com.winlator.xserver;

import com.winlator.core.Bitmask;
import com.winlator.xconnector.XInputStream;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public class WindowAttributes {
    private Cursor cursor;
    public final Window window;
    private int backingPixel = 0;
    private int backingPlanes = 1;
    private BackingStore backingStore = BackingStore.NOT_USEFUL;
    private BitGravity bitGravity = BitGravity.CENTER;
    private Bitmask doNotPropagateMask = new Bitmask(0);
    private Bitmask eventMask = new Bitmask(0);
    private WinGravity winGravity = WinGravity.CENTER;
    private WindowClass windowClass = WindowClass.INPUT_OUTPUT;
    private final Bitmask attributeFlags = new Bitmask(new int[]{65536, 262144, 524288});

    public enum BackingStore {
        NOT_USEFUL,
        WHEN_MAPPED,
        ALWAYS
    }

    public enum BitGravity {
        FORGET,
        NORTH_WEST,
        NORTH,
        NORTH_EAST,
        WEST,
        CENTER,
        EAST,
        SOUTH_WEST,
        SOUTH,
        SOUTH_EAST,
        STATIC
    }

    public enum WinGravity {
        UNMAP,
        NORTH_WEST,
        NORTH,
        NORTH_EAST,
        WEST,
        CENTER,
        EAST,
        SOUTH_WEST,
        SOUTH,
        SOUTH_EAST,
        STATIC
    }

    public enum WindowClass {
        COPY_FROM_PARENT,
        INPUT_OUTPUT,
        INPUT_ONLY
    }

    public WindowAttributes(Window window) {
        this.window = window;
    }

    public int getBackingPixel() {
        return this.backingPixel;
    }

    public int getBackingPlanes() {
        return this.backingPlanes;
    }

    public BackingStore getBackingStore() {
        return this.backingStore;
    }

    public BitGravity getBitGravity() {
        return this.bitGravity;
    }

    public Cursor getCursor() {
        Window parent = this.window.getParent();
        Cursor cursor = this.cursor;
        return (cursor != null || parent == null) ? cursor : parent.attributes.getCursor();
    }

    public Bitmask getEventMask() {
        return this.eventMask;
    }

    public Bitmask getDoNotPropagateMask() {
        return this.doNotPropagateMask;
    }

    public boolean isMapped() {
        return this.attributeFlags.isSet(32768);
    }

    public void setMapped(boolean mapped) {
        this.attributeFlags.set(32768, mapped);
    }

    public boolean isOverrideRedirect() {
        return this.attributeFlags.isSet(512);
    }

    public boolean isSaveUnder() {
        return this.attributeFlags.isSet(1024);
    }

    public WinGravity getWinGravity() {
        return this.winGravity;
    }

    public WindowClass getWindowClass() {
        return this.windowClass;
    }

    public void setWindowClass(WindowClass windowClass) {
        this.windowClass = windowClass;
    }

    public boolean isEnabled() {
        return this.attributeFlags.isSet(65536);
    }

    public void setEnabled(boolean enabled) {
        this.attributeFlags.set(65536, enabled);
    }

    public boolean isRenderSubwindows() {
        return this.attributeFlags.isSet(262144);
    }

    public void setRenderSubwindows(boolean renderSubwindows) {
        this.attributeFlags.set(262144, renderSubwindows);
    }

    public boolean isViewable() {
        return this.attributeFlags.isSet(524288);
    }

    public void setViewable(boolean viewable) {
        this.attributeFlags.set(524288, viewable);
    }

    public void update(Bitmask valueMask, XInputStream inputStream, XClient client) {
        Iterator<Integer> it = valueMask.iterator();
        while (it.hasNext()) {
            int index = it.next().intValue();
            switch (index) {
                case 1:
                case 4:
                case 8:
                case 8192:
                    inputStream.skip(4);
                    break;
                case 2:
                    this.window.getContent().fillColor(inputStream.readInt());
                    break;
                case 16:
                    this.bitGravity = BitGravity.values()[inputStream.readInt()];
                    break;
                case 32:
                    this.winGravity = WinGravity.values()[inputStream.readInt()];
                    break;
                case 64:
                    this.backingStore = BackingStore.values()[inputStream.readInt()];
                    break;
                case 128:
                    this.backingPlanes = inputStream.readInt();
                    break;
                case 256:
                    this.backingPixel = inputStream.readInt();
                    break;
                case 512:
                case 1024:
                    this.attributeFlags.set(index, inputStream.readInt() == 1);
                    break;
                case 2048:
                    this.eventMask = new Bitmask(inputStream.readInt());
                    break;
                case 4096:
                    this.doNotPropagateMask = new Bitmask(inputStream.readInt());
                    break;
                case 16384:
                    this.cursor = client.xServer.cursorManager.getCursor(inputStream.readInt());
                    break;
            }
        }
        client.xServer.windowManager.triggerOnUpdateWindowAttributes(this.window, valueMask);
    }

    public boolean isTransparent() {
        return this.attributeFlags.isSet(131072);
    }

    public void setTransparent(boolean transparent) {
        this.attributeFlags.set(131072, transparent);
    }
}
