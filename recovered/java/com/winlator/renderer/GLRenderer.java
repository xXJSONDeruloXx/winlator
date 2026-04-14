package com.winlator.renderer;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import androidx.core.graphics.ColorUtils;
import com.winlator.R;
import com.winlator.core.Bitmask;
import com.winlator.core.Callback;
import com.winlator.core.GPUHelper;
import com.winlator.core.ImageUtils;
import com.winlator.math.Mathf;
import com.winlator.math.XForm;
import com.winlator.renderer.material.CursorMaterial;
import com.winlator.renderer.material.ScreenMaterial;
import com.winlator.renderer.material.ShaderMaterial;
import com.winlator.renderer.material.WindowMaterial;
import com.winlator.widget.XServerView;
import com.winlator.xserver.Cursor;
import com.winlator.xserver.Decoration;
import com.winlator.xserver.Drawable;
import com.winlator.xserver.Pointer;
import com.winlator.xserver.ScreenInfo;
import com.winlator.xserver.Window;
import com.winlator.xserver.WindowManager;
import com.winlator.xserver.XLock;
import com.winlator.xserver.XServer;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.IntBuffer;
import java.util.ArrayList;
import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/* JADX INFO: loaded from: classes.dex */
public class GLRenderer implements GLSurfaceView.Renderer, WindowManager.OnWindowModificationListener, Pointer.OnPointerMotionListener {
    private int cursorBackColor;
    private int cursorForeColor;
    private final CursorMaterial cursorMaterial;
    private float cursorScale;
    private boolean cursorVisible;
    public final EffectComposer effectComposer;
    private boolean forceWindowsFullscreen;
    private boolean fullscreen;
    private float magnifierZoom;
    protected final VertexAttribute quadVertices;
    private final ArrayList<RenderableWindow> renderableWindows;
    private final Drawable rootCursorDrawable;
    private boolean screenOffsetYRelativeToCursor;
    protected short surfaceHeight;
    protected short surfaceWidth;
    private final float[] tmpXForm1;
    private final float[] tmpXForm2;
    private boolean toggleFullscreen;
    public final ViewTransformation viewTransformation;
    protected boolean viewportNeedsUpdate;
    private final WindowMaterial windowMaterial;
    private final XServer xServer;
    public final XServerView xServerView;

    public GLRenderer(XServerView xServerView, XServer xServer) {
        VertexAttribute vertexAttribute = new VertexAttribute("position", 2);
        this.quadVertices = vertexAttribute;
        this.tmpXForm1 = XForm.getInstance();
        this.tmpXForm2 = XForm.getInstance();
        this.cursorMaterial = new CursorMaterial();
        this.windowMaterial = new WindowMaterial();
        this.viewTransformation = new ViewTransformation();
        this.renderableWindows = new ArrayList<>();
        this.fullscreen = false;
        this.toggleFullscreen = false;
        this.viewportNeedsUpdate = true;
        this.cursorVisible = true;
        this.cursorScale = 1.0f;
        this.cursorBackColor = 16777215;
        this.cursorForeColor = 0;
        this.screenOffsetYRelativeToCursor = false;
        this.magnifierZoom = 1.0f;
        this.effectComposer = new EffectComposer(this);
        this.xServerView = xServerView;
        this.xServer = xServer;
        this.rootCursorDrawable = createRootCursorDrawable();
        vertexAttribute.put(new float[]{0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f});
        xServer.windowManager.addOnWindowModificationListener(this);
        xServer.pointer.addOnPointerMotionListener(this);
    }

    @Override // android.opengl.GLSurfaceView.Renderer
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        GPUHelper.setGlobalEGLContext();
        GLES20.glFrontFace(2305);
        GLES20.glDisable(2884);
        GLES20.glDisable(2929);
        GLES20.glDepthMask(false);
        GLES20.glEnable(3042);
        GLES20.glBlendFunc(770, 771);
        GLES20.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    }

    @Override // android.opengl.GLSurfaceView.Renderer
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        this.surfaceWidth = (short) width;
        this.surfaceHeight = (short) height;
        ViewTransformation viewTransformation = this.viewTransformation;
        ScreenInfo screenInfo = this.xServer.screenInfo;
        viewTransformation.update(width, height, screenInfo.width, screenInfo.height);
        this.viewportNeedsUpdate = true;
    }

    @Override // android.opengl.GLSurfaceView.Renderer
    public void onDrawFrame(GL10 gl) {
        if (this.toggleFullscreen) {
            this.fullscreen = !this.fullscreen;
            this.toggleFullscreen = false;
            this.viewportNeedsUpdate = true;
        }
        if (this.effectComposer.hasEffects()) {
            this.effectComposer.render();
        } else {
            drawFrame();
        }
    }

    protected void drawFrame() {
        if (this.viewportNeedsUpdate) {
            if (this.fullscreen) {
                GLES20.glViewport(0, 0, this.surfaceWidth, this.surfaceHeight);
            } else {
                ViewTransformation viewTransformation = this.viewTransformation;
                GLES20.glViewport(viewTransformation.viewOffsetX, viewTransformation.viewOffsetY, viewTransformation.viewWidth, viewTransformation.viewHeight);
            }
            this.viewportNeedsUpdate = false;
        }
        GLES20.glClear(16384);
        float pointerX = 0.0f;
        float pointerY = 0.0f;
        float magnifierZoom = !this.screenOffsetYRelativeToCursor ? this.magnifierZoom : 1.0f;
        if (magnifierZoom != 1.0f) {
            short s = this.xServer.screenInfo.width;
            pointerX = Mathf.clamp((this.xServer.pointer.getX() * magnifierZoom) - (s * 0.5f), 0.0f, s * Math.abs(1.0f - magnifierZoom));
        }
        if (this.screenOffsetYRelativeToCursor || magnifierZoom != 1.0f) {
            float scaleY = magnifierZoom != 1.0f ? Math.abs(1.0f - magnifierZoom) : 0.5f;
            XServer xServer = this.xServer;
            float offsetY = xServer.screenInfo.height * (this.screenOffsetYRelativeToCursor ? 0.25f : 0.5f);
            pointerY = Mathf.clamp((xServer.pointer.getY() * magnifierZoom) - offsetY, 0.0f, this.xServer.screenInfo.height * scaleY);
        }
        XForm.makeTransform(this.tmpXForm2, -pointerX, -pointerY, magnifierZoom, magnifierZoom, 0.0f);
        renderWindows();
        if (this.cursorVisible) {
            renderCursor();
        }
    }

    @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
    public void onMapWindow(Window window) {
        this.xServerView.queueEvent(new GLRenderer$$ExternalSyntheticLambda0(this));
        this.xServerView.requestRender();
    }

    @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
    public void onUnmapWindow(Window window) {
        this.xServerView.queueEvent(new GLRenderer$$ExternalSyntheticLambda0(this));
        this.xServerView.requestRender();
    }

    @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
    public void onChangeWindowZOrder(Window window) {
        this.xServerView.queueEvent(new GLRenderer$$ExternalSyntheticLambda0(this));
        this.xServerView.requestRender();
    }

    @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
    public void onUpdateWindowContent(Window window) {
        this.xServerView.requestRender();
    }

    @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
    public void onUpdateWindowGeometry(final Window window, boolean resized) {
        if (resized) {
            this.xServerView.queueEvent(new GLRenderer$$ExternalSyntheticLambda0(this));
        } else {
            this.xServerView.queueEvent(new Runnable() { // from class: com.winlator.renderer.GLRenderer$$ExternalSyntheticLambda2
                @Override // java.lang.Runnable
                public final void run() {
                    this.f$0.lambda$onUpdateWindowGeometry$0(window);
                }
            });
        }
        this.xServerView.requestRender();
    }

    @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
    public void onUpdateWindowAttributes(Window window, Bitmask mask) {
        if (mask.isSet(16384)) {
            this.xServerView.requestRender();
        }
    }

    @Override // com.winlator.xserver.Pointer.OnPointerMotionListener
    public void onPointerMove(short x, short y) {
        this.xServerView.requestRender();
    }

    private void renderCursorDrawable(Drawable drawable, int x, int y) {
        synchronized (drawable.renderLock) {
            Texture texture = drawable.getTexture();
            texture.updateFromDrawable();
            float f = drawable.width;
            float f2 = this.cursorScale;
            XForm.set(this.tmpXForm1, x, y, f * f2, drawable.height * f2);
            float[] fArr = this.tmpXForm1;
            XForm.multiply(fArr, fArr, this.tmpXForm2);
            CursorMaterial cursorMaterial = this.cursorMaterial;
            cursorMaterial.setUniformColor(cursorMaterial.uniforms.backColor, this.cursorBackColor);
            CursorMaterial cursorMaterial2 = this.cursorMaterial;
            cursorMaterial2.setUniformColor(cursorMaterial2.uniforms.foreColor, this.cursorForeColor);
            GLES20.glActiveTexture(33984);
            GLES20.glBindTexture(3553, texture.getTextureId());
            CursorMaterial cursorMaterial3 = this.cursorMaterial;
            cursorMaterial3.setUniformInt(cursorMaterial3.uniforms.texture, 0);
            CursorMaterial cursorMaterial4 = this.cursorMaterial;
            cursorMaterial4.setUniformFloatArray(cursorMaterial4.uniforms.xform, this.tmpXForm1);
            GLES20.glDrawArrays(5, 0, this.quadVertices.count());
            GLES20.glBindTexture(3553, 0);
        }
    }

    private void renderWindowDrawable(Drawable drawable, int x, int y, boolean transparent, FullscreenTransformation fullscreenTransformation) {
        synchronized (drawable.renderLock) {
            Texture texture = drawable.getTexture();
            texture.updateFromDrawable();
            if (fullscreenTransformation != null) {
                XForm.set(this.tmpXForm1, fullscreenTransformation.x, fullscreenTransformation.y, fullscreenTransformation.width, fullscreenTransformation.height);
            } else {
                XForm.set(this.tmpXForm1, x, y, drawable.width, drawable.height);
            }
            float[] fArr = this.tmpXForm1;
            XForm.multiply(fArr, fArr, this.tmpXForm2);
            GLES20.glActiveTexture(33984);
            GLES20.glBindTexture(3553, texture.getTextureId());
            WindowMaterial windowMaterial = this.windowMaterial;
            windowMaterial.setUniformInt(windowMaterial.uniforms.texture, 0);
            WindowMaterial windowMaterial2 = this.windowMaterial;
            windowMaterial2.setUniformFloat(windowMaterial2.uniforms.noAlpha, !transparent ? 1.0f : 0.0f);
            WindowMaterial windowMaterial3 = this.windowMaterial;
            windowMaterial3.setUniformFloatArray(windowMaterial3.uniforms.xform, this.tmpXForm1);
            WindowMaterial windowMaterial4 = this.windowMaterial;
            windowMaterial4.setUniformBool(windowMaterial4.uniforms.flipY, texture.isFlipY());
            GLES20.glDrawArrays(5, 0, this.quadVertices.count());
            GLES20.glBindTexture(3553, 0);
        }
    }

    private void renderWindows() {
        this.windowMaterial.use();
        WindowMaterial windowMaterial = this.windowMaterial;
        ShaderMaterial.Uniform uniform = windowMaterial.uniforms.viewSize;
        ScreenInfo screenInfo = this.xServer.screenInfo;
        windowMaterial.setUniformVec2(uniform, screenInfo.width, screenInfo.height);
        this.quadVertices.bind(this.windowMaterial.programId);
        XLock lock = this.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER);
        try {
            for (RenderableWindow window : this.renderableWindows) {
                if (!window.content.isOffscreenStorage()) {
                    renderWindowDrawable(window.content, window.rootX, window.rootY, window.transparent, window.fullscreenTransformation);
                }
            }
            if (lock != null) {
                lock.close();
            }
            this.quadVertices.disable();
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

    private void renderCursor() {
        this.cursorMaterial.use();
        CursorMaterial cursorMaterial = this.cursorMaterial;
        ShaderMaterial.Uniform uniform = cursorMaterial.uniforms.viewSize;
        ScreenInfo screenInfo = this.xServer.screenInfo;
        cursorMaterial.setUniformVec2(uniform, screenInfo.width, screenInfo.height);
        this.quadVertices.bind(this.cursorMaterial.programId);
        XLock lock = this.xServer.lock(XServer.Lockable.DRAWABLE_MANAGER);
        try {
            Window pointWindow = this.xServer.inputDeviceManager.getPointWindow();
            Cursor cursor = pointWindow != null ? pointWindow.attributes.getCursor() : null;
            short x = this.xServer.pointer.getClampedX();
            short y = this.xServer.pointer.getClampedY();
            if (cursor != null) {
                if (cursor.isVisible()) {
                    renderCursorDrawable(cursor.cursorImage, x - cursor.hotSpotX, y - cursor.hotSpotY);
                }
            } else {
                renderCursorDrawable(this.rootCursorDrawable, x, y);
            }
            if (lock != null) {
                lock.close();
            }
            this.quadVertices.disable();
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

    public void toggleFullscreen() {
        this.toggleFullscreen = true;
        this.xServerView.requestRender();
    }

    private Drawable createRootCursorDrawable() {
        Context context = this.xServerView.getContext();
        BitmapFactory.Options options = new BitmapFactory.Options();
        options.inScaled = false;
        Bitmap bitmap = BitmapFactory.decodeResource(context.getResources(), R.drawable.cursor, options);
        return Drawable.fromBitmap(bitmap);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void updateScene() {
        XLock lock = this.xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
        try {
            this.renderableWindows.clear();
            Window window = this.xServer.windowManager.rootWindow;
            collectRenderableWindows(window, window.getX(), this.xServer.windowManager.rootWindow.getY());
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

    private void collectRenderableWindows(Window window, int x, int y) {
        FullscreenTransformation fullscreenTransformation;
        if (window.isRenderable()) {
            if (window != this.xServer.windowManager.rootWindow && window.attributes.isViewable()) {
                Window parent = window.getParent();
                boolean inBounds = false;
                boolean transparent = window.attributes.isTransparent() || parent.attributes.isTransparent() || parent.isLayered() || window.isLayered();
                if (this.forceWindowsFullscreen) {
                    short width = window.getWidth();
                    short height = window.getHeight();
                    if (width >= 320 && height >= 200) {
                        ScreenInfo screenInfo = this.xServer.screenInfo;
                        if (width < screenInfo.width && height < screenInfo.height) {
                            inBounds = true;
                        }
                    }
                    if (window.getType() == Window.Type.NORMAL && inBounds && window.hasNoDecorations()) {
                        FullscreenTransformation fullscreenTransformation2 = window.getFullscreenTransformation();
                        if (fullscreenTransformation2 == null) {
                            FullscreenTransformation fullscreenTransformation3 = new FullscreenTransformation(window);
                            fullscreenTransformation2 = fullscreenTransformation3;
                            window.setFullscreenTransformation(fullscreenTransformation3);
                        }
                        fullscreenTransformation2.update(this.xServer.screenInfo, window.getWidth(), window.getHeight());
                        if (parent != this.xServer.windowManager.rootWindow && parent.getChildCount() == 1 && parent.hasDecoration(Decoration.BORDER) && parent.hasDecoration(Decoration.TITLE)) {
                            FullscreenTransformation parentFullscreenTransformation = parent.getFullscreenTransformation();
                            if (parentFullscreenTransformation == null) {
                                FullscreenTransformation fullscreenTransformation4 = new FullscreenTransformation(parent);
                                parentFullscreenTransformation = fullscreenTransformation4;
                                parent.setFullscreenTransformation(fullscreenTransformation4);
                            }
                            parentFullscreenTransformation.update(this.xServer.screenInfo, parent.getWidth(), parent.getHeight());
                            removeRenderableWindow(parent);
                        } else {
                            parent.setFullscreenTransformation(null);
                        }
                        fullscreenTransformation = fullscreenTransformation2;
                    } else {
                        window.setFullscreenTransformation(null);
                        fullscreenTransformation = null;
                    }
                    this.renderableWindows.add(new RenderableWindow(window.getContent(), x, y, transparent, fullscreenTransformation));
                } else {
                    this.renderableWindows.add(new RenderableWindow(window.getContent(), x, y, transparent, null));
                }
            }
            if (window.attributes.isRenderSubwindows()) {
                for (Window child : window.getChildren()) {
                    collectRenderableWindows(child, child.getX() + x, child.getY() + y);
                }
            }
        }
    }

    private void removeRenderableWindow(Window window) {
        for (int i = 0; i < this.renderableWindows.size(); i++) {
            if (this.renderableWindows.get(i).content == window.getContent()) {
                this.renderableWindows.remove(i);
                return;
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: updateWindowPosition, reason: merged with bridge method [inline-methods] */
    public void lambda$onUpdateWindowGeometry$0(Window window) {
        for (RenderableWindow renderableWindow : this.renderableWindows) {
            if (renderableWindow.content == window.getContent()) {
                renderableWindow.rootX = window.getRootX();
                renderableWindow.rootY = window.getRootY();
                return;
            }
        }
    }

    public void setCursorVisible(boolean cursorVisible) {
        this.cursorVisible = cursorVisible;
        this.xServerView.requestRender();
    }

    public void setCursorScale(float cursorScale) {
        this.cursorScale = cursorScale;
    }

    public void setCursorColor(int cursorColor) {
        this.cursorBackColor = cursorColor;
        this.cursorForeColor = ColorUtils.calculateLuminance(cursorColor) < 0.5d ? 16777215 : 0;
    }

    public void setScreenOffsetYRelativeToCursor(boolean screenOffsetYRelativeToCursor) {
        this.screenOffsetYRelativeToCursor = screenOffsetYRelativeToCursor;
        this.xServerView.requestRender();
    }

    public void setForceWindowsFullscreen(boolean forceWindowsFullscreen) {
        this.forceWindowsFullscreen = forceWindowsFullscreen;
    }

    public boolean isFullscreen() {
        return this.fullscreen;
    }

    public float getMagnifierZoom() {
        return this.magnifierZoom;
    }

    public void setMagnifierZoom(float magnifierZoom) {
        this.magnifierZoom = magnifierZoom;
        this.xServerView.requestRender();
    }

    public int[] getPixelsARGB(int x, int y, int width, int height, boolean flipY) {
        ByteBuffer pixelBuffer = ByteBuffer.allocateDirect(width * height * 4).order(ByteOrder.nativeOrder());
        GLES20.glReadPixels(x, y, width, height, 6408, 5121, pixelBuffer);
        IntBuffer colors = pixelBuffer.asIntBuffer();
        int[] result = new int[width * height];
        if (flipY) {
            for (int i = 0; i < height; i++) {
                colors.position(((height - i) - 1) * width);
                colors.get(result, i * width, width);
            }
        } else {
            colors.get(result);
        }
        for (int i2 = 0; i2 < result.length; i2++) {
            result[i2] = (result[i2] & (-16711936)) | ((result[i2] & 255) << 16) | ((result[i2] & 16711680) >> 16);
        }
        return result;
    }

    public void takeWindowScreenshot(final Drawable drawable, final Callback<Bitmap> callback) {
        this.xServerView.queueEvent(new Runnable() { // from class: com.winlator.renderer.GLRenderer$$ExternalSyntheticLambda1
            @Override // java.lang.Runnable
            public final void run() throws Throwable {
                this.f$0.lambda$takeWindowScreenshot$1(drawable, callback);
            }
        });
        this.xServerView.requestRender();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$takeWindowScreenshot$1(Drawable drawable, Callback callback) throws Throwable {
        synchronized (drawable.renderLock) {
            try {
                try {
                    Texture texture = drawable.getTexture();
                    texture.updateFromDrawable();
                    int[] framebufferSize = ImageUtils.getScaledSize(drawable.width, drawable.height, 0.0f, 256.0f);
                    RenderTarget renderTarget = new RenderTarget();
                    renderTarget.allocateFramebuffer(framebufferSize[0], framebufferSize[1]);
                    GLES20.glBindFramebuffer(36160, renderTarget.getFramebuffer());
                    GLES20.glViewport(0, 0, framebufferSize[0], framebufferSize[1]);
                    this.viewportNeedsUpdate = true;
                    GLES20.glClear(16384);
                    ScreenMaterial material = new ScreenMaterial();
                    material.use();
                    material.setUniformBool(material.uniforms.flipY, texture.isFlipY());
                    this.quadVertices.bind(material.programId);
                    GLES20.glActiveTexture(33984);
                    GLES20.glBindTexture(3553, texture.getTextureId());
                    material.setUniformInt(material.uniforms.screenTexture, 0);
                    GLES20.glDrawArrays(5, 0, this.quadVertices.count());
                    GLES20.glBindTexture(3553, 0);
                    this.quadVertices.disable();
                    int[] colors = getPixelsARGB(0, 0, framebufferSize[0], framebufferSize[1], false);
                    Bitmap bitmap = Bitmap.createBitmap(colors, framebufferSize[0], framebufferSize[1], Bitmap.Config.ARGB_8888);
                    GLES20.glBindFramebuffer(36160, 0);
                    renderTarget.destroy();
                    material.destroy();
                    callback.call(bitmap);
                } catch (Throwable th) {
                    th = th;
                    throw th;
                }
            } catch (Throwable th2) {
                th = th2;
                throw th;
            }
        }
    }
}
