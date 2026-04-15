package com.winlator.sysvshm;

import com.winlator.xconnector.ConnectedClient;
import com.winlator.xconnector.RequestHandler;
import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xconnector.XStreamLock;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class SysVSHMRequestHandler implements RequestHandler {
    @Override // com.winlator.xconnector.RequestHandler
    public boolean handleRequest(ConnectedClient client) throws IOException {
        SysVSharedMemory sysVSharedMemory = (SysVSharedMemory) client.getTag();
        XInputStream inputStream = client.getInputStream();
        XOutputStream outputStream = client.getOutputStream();
        if (inputStream.available() < 5) {
            return false;
        }
        byte requestCode = inputStream.readByte();
        switch (requestCode) {
            case 0: {
                long size = inputStream.readUnsignedInt();
                int shmid = sysVSharedMemory.get(size);
                XStreamLock lock = outputStream.lock();
                try {
                    outputStream.writeInt(shmid);
                } finally {
                    if (lock != null) lock.close();
                }
                return true;
            }
            case 1: {
                int shmid2 = inputStream.readInt();
                XStreamLock lock = outputStream.lock();
                try {
                    outputStream.writeByte((byte) 0);
                    outputStream.setAncillaryFd(sysVSharedMemory.getFd(shmid2));
                } finally {
                    if (lock != null) lock.close();
                }
                return true;
            }
            case 2:
                int shmid3 = inputStream.readInt();
                sysVSharedMemory.delete(shmid3);
                return true;
            default:
                return true;
        }
    }
}
