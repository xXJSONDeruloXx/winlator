package com.winlator.xenvironment.components;

import android.opengl.GLES20;
import androidx.annotation.Keep;
import com.winlator.renderer.Texture;
import com.winlator.xconnector.ConnectedClient;
import com.winlator.xconnector.ConnectionHandler;
import com.winlator.xconnector.RequestHandler;
import com.winlator.xconnector.UnixSocketConfig;
import com.winlator.xconnector.XConnectorEpoll;
import com.winlator.xenvironment.EnvironmentComponent;
import com.winlator.xserver.Drawable;
import com.winlator.xserver.XServer;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class VirGLRendererComponent extends EnvironmentComponent implements ConnectionHandler, RequestHandler {
    private XConnectorEpoll connector;
    private final UnixSocketConfig socketConfig;
    private final XServer xServer;

    private native void destroyClient(long j);

    private native long handleNewConnection(int i);

    private native void handleRequest(long j);

    static {
        System.loadLibrary("virglrenderer");
    }

    public VirGLRendererComponent(XServer xServer, UnixSocketConfig socketConfig) {
        this.xServer = xServer;
        this.socketConfig = socketConfig;
    }

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void start() {
        if (this.connector != null) {
            return;
        }
        XConnectorEpoll xConnectorEpoll = new XConnectorEpoll(this.socketConfig, this, this);
        this.connector = xConnectorEpoll;
        xConnectorEpoll.setInitialInputBufferCapacity(0);
        this.connector.setInitialOutputBufferCapacity(0);
        this.connector.start();
    }

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void stop() {
        XConnectorEpoll xConnectorEpoll = this.connector;
        if (xConnectorEpoll != null) {
            xConnectorEpoll.destroy();
            this.connector = null;
        }
    }

    @Keep
    private void killConnection(int fd) {
        XConnectorEpoll xConnectorEpoll = this.connector;
        xConnectorEpoll.killConnection(xConnectorEpoll.getClientWidthFd(fd));
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleConnectionShutdown(ConnectedClient client) {
        long clientPtr = ((Long) client.getTag()).longValue();
        destroyClient(clientPtr);
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleNewConnection(ConnectedClient client) {
        long clientPtr = handleNewConnection(client.fd);
        client.setTag(Long.valueOf(clientPtr));
    }

    @Override // com.winlator.xconnector.RequestHandler
    public boolean handleRequest(ConnectedClient client) throws IOException {
        long clientPtr = ((Long) client.getTag()).longValue();
        handleRequest(clientPtr);
        return true;
    }

    @Keep
    private void flushFrontbuffer(int drawableId, int framebuffer) {
        Drawable drawable = this.xServer.drawableManager.getDrawable(drawableId);
        if (drawable == null) {
            return;
        }
        synchronized (drawable.renderLock) {
            drawable.setData(null);
            Texture texture = drawable.getTexture();
            GLES20.glBindFramebuffer(36160, framebuffer);
            texture.copyFromReadBuffer(drawable.width, drawable.height);
            GLES20.glBindFramebuffer(36160, 0);
        }
        Runnable onDrawListener = drawable.getOnDrawListener();
        if (onDrawListener != null) {
            onDrawListener.run();
        }
    }
}
