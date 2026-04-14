package com.winlator.sysvshm;

import android.util.SparseArray;
import com.winlator.xconnector.XConnectorEpoll;
import java.nio.ByteBuffer;

/* JADX INFO: loaded from: classes.dex */
public class SysVSharedMemory {
    private final SparseArray<SHMemory> shmemories = new SparseArray<>();
    private int maxSHMemoryId = 0;

    private static native int ashmemCreateRegion(int i, long j);

    public static native int createMemoryFd(String str, int i);

    public static native ByteBuffer mapSHMSegment(int i, long j, int i2, boolean z);

    public static native void unmapSHMSegment(ByteBuffer byteBuffer, long j);

    static {
        System.loadLibrary("winlator");
    }

    private static class SHMemory {
        private ByteBuffer data;
        private int fd;
        private long size;

        private SHMemory() {
        }
    }

    public int getFd(int shmid) {
        int i;
        synchronized (this.shmemories) {
            SHMemory shmemory = this.shmemories.get(shmid);
            i = shmemory != null ? shmemory.fd : -1;
        }
        return i;
    }

    public int get(long size) {
        synchronized (this.shmemories) {
            int index = this.shmemories.size();
            int fd = ashmemCreateRegion(index, size);
            if (fd < 0) {
                return -1;
            }
            SHMemory shmemory = new SHMemory();
            int id = this.maxSHMemoryId + 1;
            this.maxSHMemoryId = id;
            shmemory.fd = fd;
            shmemory.size = size;
            this.shmemories.put(id, shmemory);
            return id;
        }
    }

    public void delete(int shmid) {
        synchronized (this.shmemories) {
            SHMemory shmemory = this.shmemories.get(shmid);
            if (shmemory != null) {
                if (shmemory.fd != -1) {
                    XConnectorEpoll.closeFd(shmemory.fd);
                    shmemory.fd = -1;
                }
                this.shmemories.remove(shmid);
            }
        }
    }

    public void deleteAll() {
        synchronized (this.shmemories) {
            for (int i = this.shmemories.size() - 1; i >= 0; i--) {
                delete(this.shmemories.keyAt(i));
            }
        }
    }

    public ByteBuffer attach(int shmid) {
        synchronized (this.shmemories) {
            SHMemory shmemory = this.shmemories.get(shmid);
            if (shmemory != null) {
                if (shmemory.data == null) {
                    shmemory.data = mapSHMSegment(shmemory.fd, shmemory.size, 0, true);
                }
                return shmemory.data;
            }
            return null;
        }
    }

    public void detach(ByteBuffer data) {
        synchronized (this.shmemories) {
            int i = 0;
            while (true) {
                if (i >= this.shmemories.size()) {
                    break;
                }
                SHMemory shmemory = this.shmemories.valueAt(i);
                if (shmemory.data == data) {
                    if (shmemory.data != null) {
                        unmapSHMSegment(shmemory.data, shmemory.size);
                        shmemory.data = null;
                    }
                } else {
                    i++;
                }
            }
        }
    }
}
