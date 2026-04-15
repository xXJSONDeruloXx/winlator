package com.winlator.xconnector;

import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public interface XStreamLock extends AutoCloseable {
    @Override // java.lang.AutoCloseable
    void close() throws IOException;
}
