package com.winlator.xserver;

import android.util.SparseArray;
import com.winlator.core.Bitmask;
import com.winlator.xconnector.XInputStream;
import com.winlator.xserver.Window;
import com.winlator.xserver.WindowAttributes;
import com.winlator.xserver.errors.BadIdChoice;
import com.winlator.xserver.errors.BadMatch;
import com.winlator.xserver.errors.BadValue;
import com.winlator.xserver.errors.XRequestError;
import com.winlator.xserver.events.ConfigureNotify;
import com.winlator.xserver.events.ConfigureRequest;
import com.winlator.xserver.events.DestroyNotify;
import com.winlator.xserver.events.Expose;
import com.winlator.xserver.events.MapNotify;
import com.winlator.xserver.events.MapRequest;
import com.winlator.xserver.events.ResizeRequest;
import com.winlator.xserver.events.UnmapNotify;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class WindowManager extends XResourceManager {
    public final DrawableManager drawableManager;
    private FocusRevertTo focusRevertTo;
    private Window focusedWindow;
    private final ArrayList<OnWindowModificationListener> onWindowModificationListeners;
    public final Window rootWindow;
    private final SparseArray<Window> windows;

    public enum FocusRevertTo {
        NONE,
        POINTER_ROOT,
        PARENT
    }

    public interface OnWindowModificationListener {
        default void onMapWindow(Window window) {
        }

        default void onUnmapWindow(Window window) {
        }

        default void onChangeWindowZOrder(Window window) {
        }

        default void onUpdateWindowContent(Window window) {
        }

        default void onUpdateWindowGeometry(Window window, boolean resized) {
        }

        default void onUpdateWindowAttributes(Window window, Bitmask mask) {
        }

        default void onModifyWindowProperty(Window window, Property property) {
        }
    }

    public WindowManager(ScreenInfo screenInfo, DrawableManager drawableManager) {
        SparseArray<Window> sparseArray = new SparseArray<>();
        this.windows = sparseArray;
        this.focusRevertTo = FocusRevertTo.NONE;
        this.onWindowModificationListeners = new ArrayList<>();
        this.drawableManager = drawableManager;
        int id = IDGenerator.generate();
        Drawable drawable = drawableManager.createDrawable(id, screenInfo.width, screenInfo.height, drawableManager.getVisual());
        Window window = new Window(id, drawable, 0, 0, screenInfo.width, screenInfo.height, null);
        this.rootWindow = window;
        window.attributes.setMapped(true);
        sparseArray.put(id, window);
    }

    public Window getWindow(int id) {
        return this.windows.get(id);
    }

    public ArrayList<Window> findDialogWindows(int id) {
        ArrayList<Window> result = new ArrayList<>();
        for (int i = 0; i < this.windows.size(); i++) {
            Window window = this.windows.valueAt(i);
            if (window != null && window.getTransientFor() == id && window.isDialogBox()) {
                result.add(window);
            }
        }
        return result;
    }

    public Window findWindowWithProcessId(int processId) {
        for (int i = 0; i < this.windows.size(); i++) {
            Window window = this.windows.valueAt(i);
            if (window != null && window.getProcessId() == processId) {
                return window;
            }
        }
        return null;
    }

    public void destroyWindow(int id) {
        Window window = getWindow(id);
        if (window != null && this.rootWindow.id != id) {
            unmapWindow(window);
            removeAllSubwindowsAndWindow(window);
        }
    }

    private void removeAllSubwindowsAndWindow(Window window) {
        List<Window> children = new ArrayList<>(window.getChildren());
        for (Window child : children) {
            removeAllSubwindowsAndWindow(child);
        }
        Window parent = window.getParent();
        window.sendEvent(131072, new DestroyNotify(window, window));
        parent.sendEvent(524288, new DestroyNotify(parent, window));
        this.windows.remove(window.id);
        if (window.isInputOutput()) {
            this.drawableManager.removeDrawable(window.getContent().id);
        }
        triggerOnFreeResourceListener(window);
        if (window == this.focusedWindow) {
            revertFocus();
        }
        parent.removeChild(window);
    }

    public void mapWindow(Window window) {
        if (!window.attributes.isMapped()) {
            Window parent = window.getParent();
            if (parent.hasEventListenerFor(1048576) && !window.attributes.isOverrideRedirect()) {
                parent.sendEvent(1048576, new MapRequest(parent, window));
                return;
            }
            window.attributes.setMapped(true);
            window.sendEvent(131072, new MapNotify(window, window));
            parent.sendEvent(524288, new MapNotify(parent, window));
            window.sendEvent(32768, new Expose(window));
            triggerOnMapWindow(window);
        }
    }

    public void unmapWindow(Window window) {
        if (this.rootWindow.id != window.id && window.attributes.isMapped()) {
            window.attributes.setMapped(false);
            Window parent = window.getParent();
            window.sendEvent(131072, new UnmapNotify(window, window));
            parent.sendEvent(524288, new UnmapNotify(parent, window));
            if (window == this.focusedWindow) {
                revertFocus();
            }
            triggerOnUnmapWindow(window);
        }
    }

    public void mapSubWindows(Window window) {
        for (Window child : window.getChildren()) {
            mapSubWindows(child);
        }
        mapWindow(window);
    }

    public Window getFocusedWindow() {
        return this.focusedWindow;
    }

    public void revertFocus() {
        switch (AnonymousClass1.$SwitchMap$com$winlator$xserver$WindowManager$FocusRevertTo[this.focusRevertTo.ordinal()]) {
            case 1:
                this.focusedWindow = null;
                break;
            case 2:
                this.focusedWindow = this.rootWindow;
                break;
            case 3:
                if (this.focusedWindow.getParent() != null) {
                    this.focusedWindow = this.focusedWindow.getParent();
                }
                break;
        }
    }

    public void setFocus(Window focusedWindow, FocusRevertTo focusRevertTo) {
        this.focusedWindow = focusedWindow;
        this.focusRevertTo = focusRevertTo;
    }

    public FocusRevertTo getFocusRevertTo() {
        return this.focusRevertTo;
    }

    public Window createWindow(int id, Window parent, short x, short y, short width, short height, WindowAttributes.WindowClass windowClass, Visual visual, byte depth, XClient client) throws XRequestError {
        boolean isInputOutput;
        byte depth2;
        Visual visual2;
        Drawable drawable;
        if (this.windows.indexOfKey(id) >= 0) {
            throw new BadIdChoice(id);
        }
        switch (AnonymousClass1.$SwitchMap$com$winlator$xserver$WindowAttributes$WindowClass[windowClass.ordinal()]) {
            case 1:
                byte depth3 = (depth == 0 && parent.isInputOutput()) ? parent.getContent().visual.depth : depth;
                boolean isInputOutput2 = parent.isInputOutput();
                isInputOutput = isInputOutput2;
                depth2 = depth3;
                break;
            case 2:
                if (parent.isInputOutput()) {
                    isInputOutput = true;
                    depth2 = depth == 0 ? parent.getContent().visual.depth : depth;
                } else {
                    throw new BadMatch();
                }
                break;
            case 3:
                depth2 = depth;
                isInputOutput = false;
                break;
            default:
                depth2 = depth;
                isInputOutput = false;
                break;
        }
        if (!isInputOutput) {
            visual2 = visual;
        } else {
            Visual visual3 = visual == null ? parent.getContent().visual : visual;
            if (depth2 != visual3.depth) {
                throw new BadMatch();
            }
            visual2 = visual3;
        }
        if (!isInputOutput) {
            drawable = null;
        } else {
            Drawable drawable2 = this.drawableManager.createDrawable(id, width, height, visual2);
            if (drawable2 == null) {
                throw new BadIdChoice(id);
            }
            drawable = drawable2;
        }
        final Window window = new Window(id, drawable, x, y, width, height, client);
        window.attributes.setWindowClass(windowClass);
        if (drawable != null) {
            drawable.setOnDrawListener(new Runnable() { // from class: com.winlator.xserver.WindowManager$$ExternalSyntheticLambda0
                @Override // java.lang.Runnable
                public final void run() {
                    this.f$0.lambda$createWindow$0(window);
                }
            });
        }
        this.windows.put(id, window);
        parent.addChild(window);
        triggerOnCreateResourceListener(window);
        return window;
    }

    private void changeWindowGeometry(final Window window, short x, short y, short width, short height) {
        boolean resized = (window.getWidth() == width && window.getHeight() == height) ? false : true;
        if (resized && window.hasEventListenerFor(262144)) {
            window.sendEvent(1048576, new ResizeRequest(window, width, height));
            width = window.getWidth();
            height = window.getHeight();
            resized = false;
        }
        if (resized && window.isInputOutput()) {
            Drawable oldContent = window.getContent();
            this.drawableManager.removeDrawable(oldContent.id);
            Drawable newContent = this.drawableManager.createDrawable(oldContent.id, width, height, oldContent.visual);
            newContent.setOffscreenStorage(oldContent.isOffscreenStorage());
            newContent.setOnDrawListener(new Runnable() { // from class: com.winlator.xserver.WindowManager$$ExternalSyntheticLambda1
                @Override // java.lang.Runnable
                public final void run() {
                    this.f$0.lambda$changeWindowGeometry$1(window);
                }
            });
            window.setContent(newContent);
        }
        if (resized || window.getX() != x || window.getY() != y) {
            window.setX(x);
            window.setY(y);
            window.setWidth(width);
            window.setHeight(height);
            triggerOnUpdateWindowGeometry(window, resized);
        }
        if (resized && window.isInputOutput() && window.attributes.isMapped()) {
            window.sendEvent(new Expose(window));
        }
    }

    /* JADX INFO: renamed from: com.winlator.xserver.WindowManager$1, reason: invalid class name */
    static /* synthetic */ class AnonymousClass1 {
        static final /* synthetic */ int[] $SwitchMap$com$winlator$xserver$Window$StackMode;
        static final /* synthetic */ int[] $SwitchMap$com$winlator$xserver$WindowAttributes$WindowClass;
        static final /* synthetic */ int[] $SwitchMap$com$winlator$xserver$WindowManager$FocusRevertTo;

        static {
            int[] iArr = new int[Window.StackMode.values().length];
            $SwitchMap$com$winlator$xserver$Window$StackMode = iArr;
            try {
                iArr[Window.StackMode.ABOVE.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                $SwitchMap$com$winlator$xserver$Window$StackMode[Window.StackMode.BELOW.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            int[] iArr2 = new int[WindowAttributes.WindowClass.values().length];
            $SwitchMap$com$winlator$xserver$WindowAttributes$WindowClass = iArr2;
            try {
                iArr2[WindowAttributes.WindowClass.COPY_FROM_PARENT.ordinal()] = 1;
            } catch (NoSuchFieldError e3) {
            }
            try {
                $SwitchMap$com$winlator$xserver$WindowAttributes$WindowClass[WindowAttributes.WindowClass.INPUT_OUTPUT.ordinal()] = 2;
            } catch (NoSuchFieldError e4) {
            }
            try {
                $SwitchMap$com$winlator$xserver$WindowAttributes$WindowClass[WindowAttributes.WindowClass.INPUT_ONLY.ordinal()] = 3;
            } catch (NoSuchFieldError e5) {
            }
            int[] iArr3 = new int[FocusRevertTo.values().length];
            $SwitchMap$com$winlator$xserver$WindowManager$FocusRevertTo = iArr3;
            try {
                iArr3[FocusRevertTo.NONE.ordinal()] = 1;
            } catch (NoSuchFieldError e6) {
            }
            try {
                $SwitchMap$com$winlator$xserver$WindowManager$FocusRevertTo[FocusRevertTo.POINTER_ROOT.ordinal()] = 2;
            } catch (NoSuchFieldError e7) {
            }
            try {
                $SwitchMap$com$winlator$xserver$WindowManager$FocusRevertTo[FocusRevertTo.PARENT.ordinal()] = 3;
            } catch (NoSuchFieldError e8) {
            }
        }
    }

    private void changeWindowZOrder(Window.StackMode stackMode, Window window, Window sibling) {
        Window parent = window.getParent();
        switch (AnonymousClass1.$SwitchMap$com$winlator$xserver$Window$StackMode[stackMode.ordinal()]) {
            case 1:
                parent.moveChildAbove(window, sibling);
                break;
            case 2:
                parent.moveChildBelow(window, sibling);
                break;
        }
        triggerOnChangeWindowZOrder(window);
    }

    public void configureWindow(Window window, Bitmask valueMask, XInputStream inputStream) throws XRequestError {
        Window parent;
        short x = window.getX();
        short y = window.getY();
        short width = window.getWidth();
        short height = window.getHeight();
        short borderWidth = window.getBorderWidth();
        Iterator<Integer> it = valueMask.iterator();
        short x2 = x;
        short y2 = y;
        Window sibling = null;
        Window.StackMode stackMode = null;
        short borderWidth2 = width;
        short width2 = borderWidth;
        while (it.hasNext()) {
            int index = it.next().intValue();
            switch (index) {
                case 1:
                    short x3 = (short) inputStream.readInt();
                    x2 = x3;
                    break;
                case 2:
                    short y3 = (short) inputStream.readInt();
                    y2 = y3;
                    break;
                case 4:
                    borderWidth2 = (short) inputStream.readInt();
                    break;
                case 8:
                    height = (short) inputStream.readInt();
                    break;
                case 16:
                    width2 = (short) inputStream.readInt();
                    break;
                case 32:
                    sibling = getWindow(inputStream.readInt());
                    break;
                case 64:
                    stackMode = Window.StackMode.values()[inputStream.readInt()];
                    break;
            }
        }
        if (borderWidth2 <= 0) {
            short width3 = borderWidth2;
            throw new BadValue(width3);
        }
        if (height <= 0) {
            throw new BadValue(height);
        }
        Window parent2 = window.getParent();
        boolean overrideRedirect = window.attributes.isOverrideRedirect();
        if (parent2.hasEventListenerFor(1048576) && !overrideRedirect) {
            parent2.sendEvent(1048576, new ConfigureRequest(parent2, window, window.previousSibling(), x2, y2, borderWidth2, height, width2, stackMode, valueMask));
            return;
        }
        Window sibling2 = sibling;
        short width4 = borderWidth2;
        Window parent3 = parent2;
        Window.StackMode stackMode2 = stackMode;
        Window sibling3 = sibling2;
        short borderWidth3 = width2;
        short borderWidth4 = x2;
        short height2 = height;
        short height3 = y2;
        short width5 = width4;
        changeWindowGeometry(window, borderWidth4, height3, width5, height2);
        window.setBorderWidth(borderWidth3);
        if (stackMode2 != null) {
            parent = parent3;
            changeWindowZOrder(stackMode2, window, sibling3);
        } else {
            parent = parent3;
        }
        Window previousSibling = window.previousSibling();
        short width6 = x2;
        short height4 = y2;
        window.sendEvent(131072, new ConfigureNotify(window, window, previousSibling, width6, height4, width5, height2, borderWidth3, overrideRedirect));
        parent.sendEvent(524288, new ConfigureNotify(parent, window, previousSibling, width6, height4, width5, height2, borderWidth3, overrideRedirect));
    }

    public void reparentWindow(Window window, Window newParent) {
        Window oldParent = window.getParent();
        if (oldParent != null) {
            oldParent.removeChild(window);
        }
        newParent.addChild(window);
    }

    public Window findPointWindow(short rootX, short rootY) {
        return findPointWindow(this.rootWindow, rootX, rootY, false);
    }

    public Window findPointWindow(short rootX, short rootY, boolean useFullscreenTransformation) {
        return findPointWindow(this.rootWindow, rootX, rootY, useFullscreenTransformation);
    }

    private Window findPointWindow(Window window, short rootX, short rootY, boolean useFullscreenTransformation) {
        if (!window.attributes.isMapped() || !window.containsPoint(rootX, rootY, useFullscreenTransformation)) {
            return null;
        }
        Window child = window.getChildByCoords(rootX, rootY, useFullscreenTransformation);
        return child != null ? findPointWindow(child, rootX, rootY, useFullscreenTransformation) : window;
    }

    public void addOnWindowModificationListener(OnWindowModificationListener onWindowModificationListener) {
        this.onWindowModificationListeners.add(onWindowModificationListener);
    }

    public void triggerOnMapWindow(Window window) {
        for (int i = this.onWindowModificationListeners.size() - 1; i >= 0; i--) {
            this.onWindowModificationListeners.get(i).onMapWindow(window);
        }
    }

    public void triggerOnUnmapWindow(Window window) {
        for (int i = this.onWindowModificationListeners.size() - 1; i >= 0; i--) {
            this.onWindowModificationListeners.get(i).onUnmapWindow(window);
        }
    }

    public void triggerOnChangeWindowZOrder(Window window) {
        for (int i = this.onWindowModificationListeners.size() - 1; i >= 0; i--) {
            this.onWindowModificationListeners.get(i).onChangeWindowZOrder(window);
        }
    }

    /* JADX INFO: renamed from: triggerOnUpdateWindowContent, reason: merged with bridge method [inline-methods] and merged with bridge method [inline-methods] */
    public void lambda$createWindow$0(Window window) {
        for (int i = this.onWindowModificationListeners.size() - 1; i >= 0; i--) {
            this.onWindowModificationListeners.get(i).onUpdateWindowContent(window);
        }
    }

    public void triggerOnUpdateWindowGeometry(Window window, boolean resized) {
        for (int i = this.onWindowModificationListeners.size() - 1; i >= 0; i--) {
            this.onWindowModificationListeners.get(i).onUpdateWindowGeometry(window, resized);
        }
    }

    public void triggerOnUpdateWindowAttributes(Window window, Bitmask mask) {
        for (int i = this.onWindowModificationListeners.size() - 1; i >= 0; i--) {
            this.onWindowModificationListeners.get(i).onUpdateWindowAttributes(window, mask);
        }
    }

    public void triggerOnModifyWindowProperty(Window window, Property property) {
        for (int i = this.onWindowModificationListeners.size() - 1; i >= 0; i--) {
            this.onWindowModificationListeners.get(i).onModifyWindowProperty(window, property);
        }
    }
}
