package com.winlator.alsaserver;

import com.winlator.alsaserver.ALSAClient;
import com.winlator.xconnector.ConnectedClient;
import com.winlator.xconnector.ConnectionHandler;

/* JADX INFO: loaded from: classes.dex */
public class ALSAClientConnectionHandler implements ConnectionHandler {
    private final ALSAClient.Options options;

    public ALSAClientConnectionHandler(ALSAClient.Options options) {
        this.options = options;
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleNewConnection(ConnectedClient client) {
        client.setTag(new ALSAClient(this.options));
    }

    @Override // com.winlator.xconnector.ConnectionHandler
    public void handleConnectionShutdown(ConnectedClient client) {
        if (client.getTag() != null) {
            ((ALSAClient) client.getTag()).release();
        }
    }
}
