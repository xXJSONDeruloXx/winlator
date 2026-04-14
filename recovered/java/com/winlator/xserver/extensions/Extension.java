package com.winlator.xserver.extensions;

import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xserver.XClient;
import com.winlator.xserver.XServer;
import com.winlator.xserver.errors.XRequestError;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public abstract class Extension {
    private final byte majorOpcode;
    protected final XServer xServer;

    public abstract String getName();

    public abstract void handleRequest(XClient xClient, XInputStream xInputStream, XOutputStream xOutputStream) throws XRequestError, IOException;

    public Extension(XServer xServer, byte majorOpcode) {
        this.xServer = xServer;
        this.majorOpcode = majorOpcode;
    }

    public byte getMajorOpcode() {
        return this.majorOpcode;
    }

    public byte getFirstErrorId() {
        return (byte) 0;
    }

    public byte getFirstEventId() {
        return (byte) 0;
    }
}
