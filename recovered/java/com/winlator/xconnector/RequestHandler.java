package com.winlator.xconnector;

import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public interface RequestHandler {
    boolean handleRequest(ConnectedClient connectedClient) throws IOException;
}
