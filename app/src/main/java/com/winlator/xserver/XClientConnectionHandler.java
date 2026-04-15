package com.winlator.xserver;

import com.winlator.xconnector.ConnectedClient;
import com.winlator.xconnector.ConnectionHandler;

/* JADX INFO: loaded from: classes.dex */
public class XClientConnectionHandler implements ConnectionHandler {
    private final XServer xServer;

    public XClientConnectionHandler(XServer xServer) {
        this.xServer = xServer;
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public ConnectedClient newConnectedClient(long clientPtr, int fd) {
        return new XClient(clientPtr, fd, this.xServer);
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleNewConnection(ConnectedClient client) {
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleConnectionShutdown(ConnectedClient client) {
        ((XClient) client).freeResources();
    }
}
