package com.winlator.xserver.extensions;

import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xconnector.XStreamLock;
import com.winlator.xserver.XClient;
import com.winlator.xserver.XServer;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class BigReqExtension extends Extension {
    public BigReqExtension(XServer xServer, byte majorOpcode) {
        super(xServer, majorOpcode);
    }

    @Override // com.winlator.xserver.extensions.Extension
    public String getName() {
        return "BIG-REQUESTS";
    }

    @Override // com.winlator.xserver.extensions.Extension
    public void handleRequest(XClient client, XInputStream inputStream, XOutputStream outputStream) throws IOException {
        XStreamLock lock = outputStream.lock();
        try {
            outputStream.writeByte((byte) 1);
            outputStream.writeByte((byte) 0);
            outputStream.writeShort(client.getSequenceNumber());
            outputStream.writeInt(0);
            outputStream.writeInt(4194303);
            outputStream.writePad(20);
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
}
