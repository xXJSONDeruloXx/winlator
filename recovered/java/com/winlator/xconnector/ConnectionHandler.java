package com.winlator.xconnector;

/* JADX INFO: loaded from: classes.dex */
public interface ConnectionHandler {
    void handleConnectionShutdown(ConnectedClient connectedClient);

    void handleNewConnection(ConnectedClient connectedClient);

    default ConnectedClient newConnectedClient(long clientPtr, int fd) {
        return new ConnectedClient(clientPtr, fd);
    }
}
