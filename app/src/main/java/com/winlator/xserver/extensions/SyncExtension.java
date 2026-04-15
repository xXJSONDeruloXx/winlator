package com.winlator.xserver.extensions;

import android.util.SparseBooleanArray;
import com.winlator.xconnector.XInputStream;
import com.winlator.xconnector.XOutputStream;
import com.winlator.xserver.XClient;
import com.winlator.xserver.XServer;
import com.winlator.xserver.errors.BadFence;
import com.winlator.xserver.errors.BadIdChoice;
import com.winlator.xserver.errors.BadImplementation;
import com.winlator.xserver.errors.BadMatch;
import com.winlator.xserver.errors.XRequestError;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class SyncExtension extends Extension {
    private final SparseBooleanArray fences;

    public SyncExtension(XServer xServer, byte majorOpcode) {
        super(xServer, majorOpcode);
        this.fences = new SparseBooleanArray();
    }

    @Override // com.winlator.xserver.extensions.Extension
    public String getName() {
        return "SYNC";
    }

    public void setTriggered(int id) {
        synchronized (this.fences) {
            if (this.fences.indexOfKey(id) >= 0) {
                this.fences.put(id, true);
            }
        }
    }

    private void createFence(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        synchronized (this.fences) {
            inputStream.skip(4);
            int id = inputStream.readInt();
            if (this.fences.indexOfKey(id) >= 0) {
                throw new BadIdChoice(id);
            }
            boolean z = true;
            if (inputStream.readByte() != 1) {
                z = false;
            }
            boolean initiallyTriggered = z;
            inputStream.skip(3);
            this.fences.put(id, initiallyTriggered);
        }
    }

    private void triggerFence(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        synchronized (this.fences) {
            int id = inputStream.readInt();
            if (this.fences.indexOfKey(id) < 0) {
                throw new BadFence(id);
            }
            this.fences.put(id, true);
        }
    }

    private void resetFence(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        synchronized (this.fences) {
            int id = inputStream.readInt();
            if (this.fences.indexOfKey(id) < 0) {
                throw new BadFence(id);
            }
            boolean triggered = this.fences.get(id);
            if (!triggered) {
                throw new BadMatch();
            }
            this.fences.put(id, false);
        }
    }

    private void destroyFence(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        synchronized (this.fences) {
            int id = inputStream.readInt();
            if (this.fences.indexOfKey(id) < 0) {
                throw new BadFence(id);
            }
            this.fences.delete(id);
        }
    }

    private void awaitFence(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        synchronized (this.fences) {
            int length = client.getRemainingRequestLength();
            int[] ids = new int[length / 4];
            int i = 0;
            while (length != 0) {
                ids[i] = inputStream.readInt();
                length -= 4;
                i++;
            }
            boolean anyTriggered = false;
            do {
                for (int id : ids) {
                    if (this.fences.indexOfKey(id) < 0) {
                        throw new BadFence(id);
                    }
                    anyTriggered = this.fences.get(id);
                    if (anyTriggered) {
                        break;
                    }
                }
                Thread.yield();
            } while (!anyTriggered);
        }
    }

    @Override // com.winlator.xserver.extensions.Extension
    public void handleRequest(XClient client, XInputStream inputStream, XOutputStream outputStream) throws XRequestError, IOException {
        int opcode = client.getRequestData();
        switch (opcode) {
            case 14:
                createFence(client, inputStream, outputStream);
                return;
            case 15:
                triggerFence(client, inputStream, outputStream);
                return;
            case 16:
                resetFence(client, inputStream, outputStream);
                return;
            case 17:
                destroyFence(client, inputStream, outputStream);
                return;
            case 18:
            default:
                throw new BadImplementation();
            case 19:
                awaitFence(client, inputStream, outputStream);
                return;
        }
    }
}
