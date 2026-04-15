package com.winlator.xenvironment.components;

import com.winlator.xconnector.UnixSocketConfig;
import com.winlator.xconnector.XConnectorEpoll;
import com.winlator.xenvironment.EnvironmentComponent;
import com.winlator.xserver.XClientConnectionHandler;
import com.winlator.xserver.XClientRequestHandler;
import com.winlator.xserver.XServer;

/* JADX INFO: loaded from: classes.dex */
public class XServerComponent extends EnvironmentComponent {
    private XConnectorEpoll connector;
    private final UnixSocketConfig socketConfig;
    private final XServer xServer;

    public XServerComponent(XServer xServer, UnixSocketConfig socketConfig) {
        this.xServer = xServer;
        this.socketConfig = socketConfig;
    }

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void start() {
        if (this.connector != null) {
            return;
        }
        XConnectorEpoll xConnectorEpoll = new XConnectorEpoll(this.socketConfig, new XClientConnectionHandler(this.xServer), new XClientRequestHandler());
        this.connector = xConnectorEpoll;
        xConnectorEpoll.setInitialInputBufferCapacity(4096);
        this.connector.setInitialOutputBufferCapacity(4096);
        this.connector.setCanReceiveAncillaryMessages(true);
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
}
