package com.github.luben.zstd;

import com.github.luben.zstd.util.Native;
import java.io.FilterOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.nio.ByteBuffer;

/* JADX INFO: loaded from: classes.dex */
public class ZstdOutputStreamNoFinalizer extends FilterOutputStream {
    private static final int dstSize;
    private final BufferPool bufferPool;
    private boolean closeFrameOnFlush;
    private final byte[] dst;
    private final ByteBuffer dstByteBuffer;
    private long dstPos;
    private boolean frameClosed;
    private boolean isClosed;
    private long srcPos;
    private final long stream;

    private native int compressStream(long j, byte[] bArr, int i, byte[] bArr2, int i2);

    private static native long createCStream();

    private native int endStream(long j, byte[] bArr, int i);

    private native int flushStream(long j, byte[] bArr, int i);

    private static native int freeCStream(long j);

    public static native long recommendedCOutSize();

    private native int resetCStream(long j);

    static {
        Native.load();
        dstSize = (int) recommendedCOutSize();
    }

    public ZstdOutputStreamNoFinalizer(OutputStream outStream, BufferPool bufferPool) throws IOException {
        super(outStream);
        this.srcPos = 0L;
        this.dstPos = 0L;
        this.isClosed = false;
        this.closeFrameOnFlush = false;
        this.frameClosed = true;
        this.stream = createCStream();
        this.bufferPool = bufferPool;
        int i = dstSize;
        ByteBuffer byteBuffer = bufferPool.get(i);
        this.dstByteBuffer = byteBuffer;
        if (byteBuffer == null) {
            throw new IOException("Cannot get ByteBuffer of size " + i + " from the BufferPool");
        }
        this.dst = Zstd.extractArray(byteBuffer);
    }

    public synchronized ZstdOutputStreamNoFinalizer setLevel(int level) throws IOException {
        if (!this.frameClosed) {
            throw new IOException("Change of parameter on initialized stream");
        }
        int size = Zstd.setCompressionLevel(this.stream, level);
        if (Zstd.isError(size)) {
            throw new IOException("Compression param: " + Zstd.getErrorName(size));
        }
        return this;
    }

    @Override // java.io.FilterOutputStream, java.io.OutputStream
    public synchronized void write(byte[] src, int offset, int len) throws IOException {
        if (this.isClosed) {
            throw new IOException("Stream closed");
        }
        if (this.frameClosed) {
            int size = resetCStream(this.stream);
            if (Zstd.isError(size)) {
                throw new IOException("Compression error: cannot create header: " + Zstd.getErrorName(size));
            }
            this.frameClosed = false;
        }
        int size2 = offset + len;
        this.srcPos = offset;
        while (this.srcPos < size2) {
            int size3 = compressStream(this.stream, this.dst, dstSize, src, size2);
            if (Zstd.isError(size3)) {
                throw new IOException("Compression error: " + Zstd.getErrorName(size3));
            }
            long j = this.dstPos;
            if (j > 0) {
                ((FilterOutputStream) this).out.write(this.dst, 0, (int) j);
            }
        }
    }

    @Override // java.io.FilterOutputStream, java.io.OutputStream
    public void write(int i) throws IOException {
        byte[] oneByte = {(byte) i};
        write(oneByte, 0, 1);
    }

    @Override // java.io.FilterOutputStream, java.io.OutputStream, java.io.Flushable
    public synchronized void flush() throws IOException {
        int size;
        int size2;
        if (this.isClosed) {
            throw new IOException("Stream closed");
        }
        if (!this.frameClosed) {
            if (this.closeFrameOnFlush) {
                do {
                    size2 = endStream(this.stream, this.dst, dstSize);
                    if (Zstd.isError(size2)) {
                        throw new IOException("Compression error: " + Zstd.getErrorName(size2));
                    }
                    ((FilterOutputStream) this).out.write(this.dst, 0, (int) this.dstPos);
                } while (size2 > 0);
                this.frameClosed = true;
            } else {
                do {
                    size = flushStream(this.stream, this.dst, dstSize);
                    if (Zstd.isError(size)) {
                        throw new IOException("Compression error: " + Zstd.getErrorName(size));
                    }
                    ((FilterOutputStream) this).out.write(this.dst, 0, (int) this.dstPos);
                } while (size > 0);
            }
            ((FilterOutputStream) this).out.flush();
        }
    }

    @Override // java.io.FilterOutputStream, java.io.OutputStream, java.io.Closeable, java.lang.AutoCloseable
    public synchronized void close() throws IOException {
        close(true);
    }

    private void close(boolean closeParentStream) throws IOException {
        int size;
        if (this.isClosed) {
            return;
        }
        try {
            if (!this.frameClosed) {
                do {
                    size = endStream(this.stream, this.dst, dstSize);
                    if (Zstd.isError(size)) {
                        throw new IOException("Compression error: " + Zstd.getErrorName(size));
                    }
                    ((FilterOutputStream) this).out.write(this.dst, 0, (int) this.dstPos);
                } while (size > 0);
            }
            if (closeParentStream) {
                ((FilterOutputStream) this).out.close();
            }
        } finally {
            this.isClosed = true;
            this.bufferPool.release(this.dstByteBuffer);
            freeCStream(this.stream);
        }
    }
}
