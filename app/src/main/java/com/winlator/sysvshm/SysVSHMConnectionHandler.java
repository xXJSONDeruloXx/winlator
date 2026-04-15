package com.winlator.sysvshm;

import com.winlator.xconnector.ConnectedClient;
import com.winlator.xconnector.ConnectionHandler;

/* JADX INFO: loaded from: classes.dex */
public class SysVSHMConnectionHandler implements ConnectionHandler {
    private final SysVSharedMemory sysVSharedMemory;

    public SysVSHMConnectionHandler(SysVSharedMemory sysVSharedMemory) {
        this.sysVSharedMemory = sysVSharedMemory;
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleNewConnection(ConnectedClient client) {
        client.setTag(this.sysVSharedMemory);
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleConnectionShutdown(ConnectedClient client) {
    }
}
