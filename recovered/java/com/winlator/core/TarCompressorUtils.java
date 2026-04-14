package com.winlator.core;

import android.content.Context;
import android.net.Uri;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.concurrent.atomic.AtomicLong;
import org.apache.commons.compress.archivers.ArchiveOutputStream;
import org.apache.commons.compress.archivers.tar.TarArchiveEntry;
import org.apache.commons.compress.archivers.tar.TarArchiveOutputStream;
import org.apache.commons.compress.compressors.xz.XZCompressorInputStream;
import org.apache.commons.compress.compressors.xz.XZCompressorOutputStream;
import org.apache.commons.compress.compressors.zstandard.ZstdCompressorInputStream;
import org.apache.commons.compress.compressors.zstandard.ZstdCompressorOutputStream;

/* JADX INFO: loaded from: classes.dex */
public abstract class TarCompressorUtils {

    public interface OnExtractFileListener {
        File onExtractFile(File file, long j);
    }

    public enum Type {
        XZ,
        ZSTD
    }

    private static void addFile(ArchiveOutputStream tar, File file, String entryName) {
        try {
            tar.putArchiveEntry(tar.createArchiveEntry(file, entryName));
            BufferedInputStream inStream = new BufferedInputStream(new FileInputStream(file), 65536);
            try {
                StreamUtils.copy(inStream, tar);
                inStream.close();
                tar.closeArchiveEntry();
            } finally {
            }
        } catch (Exception e) {
        }
    }

    private static void addLinkFile(ArchiveOutputStream tar, File file, String entryName) {
        try {
            TarArchiveEntry entry = new TarArchiveEntry(entryName, (byte) 50);
            entry.setLinkName(FileUtils.readSymlink(file));
            tar.putArchiveEntry(entry);
            tar.closeArchiveEntry();
        } catch (Exception e) {
        }
    }

    private static void addDirectory(ArchiveOutputStream tar, File folder, String basePath) throws IOException {
        File[] files = folder.listFiles();
        if (files == null) {
            return;
        }
        for (File file : files) {
            if (FileUtils.isSymlink(file)) {
                addLinkFile(tar, file, basePath + file.getName());
            } else if (file.isDirectory()) {
                String entryName = basePath + file.getName() + "/";
                tar.putArchiveEntry(tar.createArchiveEntry(folder, entryName));
                tar.closeArchiveEntry();
                addDirectory(tar, file, entryName);
            } else {
                addFile(tar, file, basePath + file.getName());
            }
        }
    }

    public static void compress(Type type, File file, File destination, int level) {
        compress(type, new File[]{file}, destination, level);
    }

    public static void compress(Type type, File[] files, File destination, int level) {
        try {
            OutputStream outStream = getCompressorOutputStream(type, destination, level);
            try {
                TarArchiveOutputStream tar = new TarArchiveOutputStream(outStream);
                try {
                    tar.setLongFileMode(2);
                    boolean z = true;
                    if (files.length != 1 || !files[0].getName().equals(".")) {
                        z = false;
                    }
                    boolean skipFirstEntry = z;
                    for (File file : files) {
                        if (FileUtils.isSymlink(file)) {
                            addLinkFile(tar, file, file.getName());
                        } else if (file.isDirectory()) {
                            String basePath = "";
                            if (!skipFirstEntry) {
                                basePath = file.getName() + "/";
                                tar.putArchiveEntry(tar.createArchiveEntry(file, basePath));
                                tar.closeArchiveEntry();
                            }
                            addDirectory(tar, file, basePath);
                        } else {
                            addFile(tar, file, file.getName());
                        }
                    }
                    tar.finish();
                    tar.close();
                    if (outStream != null) {
                        outStream.close();
                    }
                } finally {
                }
            } finally {
            }
        } catch (IOException e) {
        }
    }

    public static boolean extract(Type type, Context context, String assetFile, File destination) {
        return extract(type, context, assetFile, destination, (OnExtractFileListener) null);
    }

    public static boolean extract(Type type, Context context, String assetFile, File destination, OnExtractFileListener onExtractFileListener) {
        try {
            return extract(type, context.getAssets().open(assetFile), destination, onExtractFileListener);
        } catch (IOException e) {
            return false;
        }
    }

    public static boolean extract(Type type, Context context, Uri source, File destination) {
        return extract(type, context, source, destination, (OnExtractFileListener) null);
    }

    public static boolean extract(Type type, Context context, Uri source, File destination, OnExtractFileListener onExtractFileListener) {
        if (source == null) {
            return false;
        }
        try {
            return extract(type, context.getContentResolver().openInputStream(source), destination, onExtractFileListener);
        } catch (FileNotFoundException e) {
            return false;
        }
    }

    public static boolean extract(Type type, File source, File destination) {
        return extract(type, source, destination, (OnExtractFileListener) null);
    }

    public static boolean extract(Type type, File source, File destination, OnExtractFileListener onExtractFileListener) {
        if (source == null || !source.isFile()) {
            return false;
        }
        try {
            return extract(type, new BufferedInputStream(new FileInputStream(source), 65536), destination, onExtractFileListener);
        } catch (FileNotFoundException e) {
            return false;
        }
    }

    /* JADX WARN: Removed duplicated region for block: B:63:0x009e A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    private static boolean extract(com.winlator.core.TarCompressorUtils.Type r8, java.io.InputStream r9, java.io.File r10, com.winlator.core.TarCompressorUtils.OnExtractFileListener r11) {
        /*
            r0 = 0
            if (r9 != 0) goto L4
            return r0
        L4:
            java.io.InputStream r1 = getCompressorInputStream(r8, r9)     // Catch: java.io.IOException -> La7
            org.apache.commons.compress.archivers.tar.TarArchiveInputStream r2 = new org.apache.commons.compress.archivers.tar.TarArchiveInputStream     // Catch: java.lang.Throwable -> L9b
            r2.<init>(r1)     // Catch: java.lang.Throwable -> L9b
        Ld:
            org.apache.commons.compress.archivers.ArchiveEntry r3 = r2.getNextEntry()     // Catch: java.lang.Throwable -> L91
            org.apache.commons.compress.archivers.tar.TarArchiveEntry r3 = (org.apache.commons.compress.archivers.tar.TarArchiveEntry) r3     // Catch: java.lang.Throwable -> L91
            r4 = r3
            if (r3 == 0) goto L87
            boolean r3 = r2.canReadEntryData(r4)     // Catch: java.lang.Throwable -> L91
            if (r3 != 0) goto L1d
            goto Ld
        L1d:
            java.io.File r3 = new java.io.File     // Catch: java.lang.Throwable -> L91
            java.lang.String r5 = r4.getName()     // Catch: java.lang.Throwable -> L91
            r3.<init>(r10, r5)     // Catch: java.lang.Throwable -> L91
            if (r11 == 0) goto L34
            long r5 = r4.getSize()     // Catch: java.lang.Throwable -> L91
            java.io.File r5 = r11.onExtractFile(r3, r5)     // Catch: java.lang.Throwable -> L91
            r3 = r5
            if (r3 != 0) goto L34
            goto Ld
        L34:
            boolean r5 = r4.isDirectory()     // Catch: java.lang.Throwable -> L91
            if (r5 == 0) goto L44
            boolean r5 = r3.isDirectory()     // Catch: java.lang.Throwable -> L91
            if (r5 != 0) goto L77
            r3.mkdirs()     // Catch: java.lang.Throwable -> L91
            goto L77
        L44:
            boolean r5 = r4.isSymbolicLink()     // Catch: java.lang.Throwable -> L91
            if (r5 == 0) goto L56
            java.lang.String r5 = r4.getLinkName()     // Catch: java.lang.Throwable -> L91
            java.lang.String r6 = r3.getAbsolutePath()     // Catch: java.lang.Throwable -> L91
            com.winlator.core.FileUtils.symlink(r5, r6)     // Catch: java.lang.Throwable -> L91
            goto L77
        L56:
            java.io.BufferedOutputStream r5 = new java.io.BufferedOutputStream     // Catch: java.lang.Throwable -> L91
            java.io.FileOutputStream r6 = new java.io.FileOutputStream     // Catch: java.lang.Throwable -> L91
            r6.<init>(r3)     // Catch: java.lang.Throwable -> L91
            r7 = 65536(0x10000, float:9.1835E-41)
            r5.<init>(r6, r7)     // Catch: java.lang.Throwable -> L91
            boolean r6 = com.winlator.core.StreamUtils.copy(r2, r5)     // Catch: java.lang.Throwable -> L7d
            if (r6 != 0) goto L74
            r5.close()     // Catch: java.lang.Throwable -> L91
            r2.close()     // Catch: java.lang.Throwable -> L9b
            if (r1 == 0) goto L73
            r1.close()     // Catch: java.io.IOException -> La7
        L73:
            return r0
        L74:
            r5.close()     // Catch: java.lang.Throwable -> L91
        L77:
            r5 = 505(0x1f9, float:7.08E-43)
            com.winlator.core.FileUtils.chmod(r3, r5)     // Catch: java.lang.Throwable -> L91
            goto Ld
        L7d:
            r6 = move-exception
            r5.close()     // Catch: java.lang.Throwable -> L82
            goto L86
        L82:
            r7 = move-exception
            r6.addSuppressed(r7)     // Catch: java.lang.Throwable -> L91
        L86:
            throw r6     // Catch: java.lang.Throwable -> L91
        L87:
            r3 = 1
            r2.close()     // Catch: java.lang.Throwable -> L9b
            if (r1 == 0) goto L90
            r1.close()     // Catch: java.io.IOException -> La7
        L90:
            return r3
        L91:
            r3 = move-exception
            r2.close()     // Catch: java.lang.Throwable -> L96
            goto L9a
        L96:
            r4 = move-exception
            r3.addSuppressed(r4)     // Catch: java.lang.Throwable -> L9b
        L9a:
            throw r3     // Catch: java.lang.Throwable -> L9b
        L9b:
            r2 = move-exception
            if (r1 == 0) goto La6
            r1.close()     // Catch: java.lang.Throwable -> La2
            goto La6
        La2:
            r3 = move-exception
            r2.addSuppressed(r3)     // Catch: java.io.IOException -> La7
        La6:
            throw r2     // Catch: java.io.IOException -> La7
        La7:
            r1 = move-exception
            return r0
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.core.TarCompressorUtils.extract(com.winlator.core.TarCompressorUtils$Type, java.io.InputStream, java.io.File, com.winlator.core.TarCompressorUtils$OnExtractFileListener):boolean");
    }

    public static long getContentLength(Type type, Context context, String assetFile, File destination) {
        final AtomicLong totalSizeRef = new AtomicLong();
        extract(type, context, assetFile, destination, new OnExtractFileListener() { // from class: com.winlator.core.TarCompressorUtils$$ExternalSyntheticLambda0
            @Override // com.winlator.core.TarCompressorUtils.OnExtractFileListener
            public final File onExtractFile(File file, long j) {
                return TarCompressorUtils.lambda$getContentLength$0(totalSizeRef, file, j);
            }
        });
        return totalSizeRef.get();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ File lambda$getContentLength$0(AtomicLong totalSizeRef, File file, long size) {
        totalSizeRef.addAndGet(size);
        return null;
    }

    /* JADX WARN: Code restructure failed: missing block: B:27:0x0068, code lost:
    
        r10 = new java.io.BufferedOutputStream(r2, 65536);
     */
    /* JADX WARN: Code restructure failed: missing block: B:30:0x0072, code lost:
    
        if (com.winlator.core.StreamUtils.copy(r5, r10) != false) goto L36;
     */
    /* JADX WARN: Code restructure failed: missing block: B:31:0x0074, code lost:
    
        r10.close();
     */
    /* JADX WARN: Code restructure failed: missing block: B:32:0x0077, code lost:
    
        r5.close();
     */
    /* JADX WARN: Code restructure failed: missing block: B:33:0x007a, code lost:
    
        if (r4 == null) goto L35;
     */
    /* JADX WARN: Code restructure failed: missing block: B:34:0x007c, code lost:
    
        r4.close();
     */
    /* JADX WARN: Code restructure failed: missing block: B:35:0x007f, code lost:
    
        return null;
     */
    /* JADX WARN: Code restructure failed: missing block: B:36:0x0080, code lost:
    
        r10.close();
        r6 = r2.toByteArray();
     */
    /* JADX WARN: Code restructure failed: missing block: B:37:0x0087, code lost:
    
        r5.close();
     */
    /* JADX WARN: Code restructure failed: missing block: B:38:0x008a, code lost:
    
        if (r4 == null) goto L40;
     */
    /* JADX WARN: Code restructure failed: missing block: B:39:0x008c, code lost:
    
        r4.close();
     */
    /* JADX WARN: Code restructure failed: missing block: B:40:0x008f, code lost:
    
        return r6;
     */
    /* JADX WARN: Code restructure failed: missing block: B:41:0x0090, code lost:
    
        r10 = move-exception;
     */
    /* JADX WARN: Code restructure failed: missing block: B:46:0x0099, code lost:
    
        throw r10;
     */
    /* JADX WARN: Removed duplicated region for block: B:73:0x00b2 A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public static byte[] read(com.winlator.core.TarCompressorUtils.Type r12, java.io.File r13, java.lang.String r14) {
        /*
            r0 = 0
            r1 = 0
            java.lang.String r2 = "*"
            boolean r3 = r14.startsWith(r2)
            if (r3 == 0) goto Lc
            r1 = 1
            goto L13
        Lc:
            boolean r3 = r14.endsWith(r2)
            if (r3 == 0) goto L13
            r0 = 1
        L13:
            java.lang.String r3 = ""
            java.lang.String r14 = r14.replace(r2, r3)
            java.io.ByteArrayOutputStream r2 = new java.io.ByteArrayOutputStream
            r2.<init>()
            r3 = 0
            java.io.BufferedInputStream r4 = new java.io.BufferedInputStream     // Catch: java.io.IOException -> Lbb
            java.io.FileInputStream r5 = new java.io.FileInputStream     // Catch: java.io.IOException -> Lbb
            r5.<init>(r13)     // Catch: java.io.IOException -> Lbb
            r6 = 65536(0x10000, float:9.1835E-41)
            r4.<init>(r5, r6)     // Catch: java.io.IOException -> Lbb
            java.io.InputStream r4 = getCompressorInputStream(r12, r4)     // Catch: java.io.IOException -> Lbb
            org.apache.commons.compress.archivers.tar.TarArchiveInputStream r5 = new org.apache.commons.compress.archivers.tar.TarArchiveInputStream     // Catch: java.lang.Throwable -> Laf
            r5.<init>(r4)     // Catch: java.lang.Throwable -> Laf
        L34:
            org.apache.commons.compress.archivers.ArchiveEntry r7 = r5.getNextEntry()     // Catch: java.lang.Throwable -> La5
            org.apache.commons.compress.archivers.tar.TarArchiveEntry r7 = (org.apache.commons.compress.archivers.tar.TarArchiveEntry) r7     // Catch: java.lang.Throwable -> La5
            r8 = r7
            if (r7 == 0) goto L9b
            boolean r7 = r5.canReadEntryData(r8)     // Catch: java.lang.Throwable -> La5
            if (r7 != 0) goto L44
            goto L34
        L44:
            java.lang.String r7 = r8.getName()     // Catch: java.lang.Throwable -> La5
            if (r1 == 0) goto L4f
            boolean r9 = r7.endsWith(r14)     // Catch: java.lang.Throwable -> La5
            goto L5a
        L4f:
            if (r0 == 0) goto L56
            boolean r9 = r7.startsWith(r14)     // Catch: java.lang.Throwable -> La5
            goto L5a
        L56:
            boolean r9 = r7.equals(r14)     // Catch: java.lang.Throwable -> La5
        L5a:
            if (r9 == 0) goto L9a
            boolean r10 = r8.isDirectory()     // Catch: java.lang.Throwable -> La5
            if (r10 != 0) goto L9a
            boolean r10 = r8.isSymbolicLink()     // Catch: java.lang.Throwable -> La5
            if (r10 != 0) goto L9a
            java.io.BufferedOutputStream r10 = new java.io.BufferedOutputStream     // Catch: java.lang.Throwable -> La5
            r10.<init>(r2, r6)     // Catch: java.lang.Throwable -> La5
            r6 = r10
            boolean r10 = com.winlator.core.StreamUtils.copy(r5, r6)     // Catch: java.lang.Throwable -> L90
            if (r10 != 0) goto L80
            r6.close()     // Catch: java.lang.Throwable -> La5
            r5.close()     // Catch: java.lang.Throwable -> Laf
            if (r4 == 0) goto L7f
            r4.close()     // Catch: java.io.IOException -> Lbb
        L7f:
            return r3
        L80:
            r6.close()     // Catch: java.lang.Throwable -> La5
            byte[] r6 = r2.toByteArray()     // Catch: java.lang.Throwable -> La5
            r5.close()     // Catch: java.lang.Throwable -> Laf
            if (r4 == 0) goto L8f
            r4.close()     // Catch: java.io.IOException -> Lbb
        L8f:
            return r6
        L90:
            r10 = move-exception
            r6.close()     // Catch: java.lang.Throwable -> L95
            goto L99
        L95:
            r11 = move-exception
            r10.addSuppressed(r11)     // Catch: java.lang.Throwable -> La5
        L99:
            throw r10     // Catch: java.lang.Throwable -> La5
        L9a:
            goto L34
        L9b:
            r5.close()     // Catch: java.lang.Throwable -> Laf
            if (r4 == 0) goto La4
            r4.close()     // Catch: java.io.IOException -> Lbb
        La4:
            return r3
        La5:
            r6 = move-exception
            r5.close()     // Catch: java.lang.Throwable -> Laa
            goto Lae
        Laa:
            r7 = move-exception
            r6.addSuppressed(r7)     // Catch: java.lang.Throwable -> Laf
        Lae:
            throw r6     // Catch: java.lang.Throwable -> Laf
        Laf:
            r5 = move-exception
            if (r4 == 0) goto Lba
            r4.close()     // Catch: java.lang.Throwable -> Lb6
            goto Lba
        Lb6:
            r6 = move-exception
            r5.addSuppressed(r6)     // Catch: java.io.IOException -> Lbb
        Lba:
            throw r5     // Catch: java.io.IOException -> Lbb
        Lbb:
            r4 = move-exception
            return r3
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.core.TarCompressorUtils.read(com.winlator.core.TarCompressorUtils$Type, java.io.File, java.lang.String):byte[]");
    }

    private static InputStream getCompressorInputStream(Type type, InputStream source) throws IOException {
        if (type == Type.XZ) {
            return new XZCompressorInputStream(source);
        }
        if (type == Type.ZSTD) {
            return new ZstdCompressorInputStream(source);
        }
        return null;
    }

    private static OutputStream getCompressorOutputStream(Type type, File destination, int level) throws IOException {
        if (type == Type.XZ) {
            return new XZCompressorOutputStream(new BufferedOutputStream(new FileOutputStream(destination), 65536), level);
        }
        if (type == Type.ZSTD) {
            return new ZstdCompressorOutputStream(new BufferedOutputStream(new FileOutputStream(destination), 65536), level);
        }
        return null;
    }
}
