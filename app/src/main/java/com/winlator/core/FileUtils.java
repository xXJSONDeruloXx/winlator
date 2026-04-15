package com.winlator.core;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Environment;
import android.os.StatFs;
import android.system.ErrnoException;
import android.system.Os;
import androidx.core.content.FileProvider;
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.RandomAccessFile;
import java.nio.channels.FileChannel;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.Stack;
import java.util.UUID;
import java.util.concurrent.Executors;

/* JADX INFO: loaded from: classes.dex */
public abstract class FileUtils {
    public static byte[] read(Context context, String assetFile) {
        try {
            InputStream inStream = context.getAssets().open(assetFile);
            try {
                byte[] bArrCopyToByteArray = StreamUtils.copyToByteArray(inStream);
                if (inStream != null) {
                    inStream.close();
                }
                return bArrCopyToByteArray;
            } finally {
            }
        } catch (IOException e) {
            return null;
        }
    }

    public static byte[] read(File file) {
        try {
            InputStream inStream = new BufferedInputStream(new FileInputStream(file));
            try {
                byte[] bArrCopyToByteArray = StreamUtils.copyToByteArray(inStream);
                inStream.close();
                return bArrCopyToByteArray;
            } finally {
            }
        } catch (IOException e) {
            return null;
        }
    }

    public static String readString(Context context, String assetFile) {
        return new String(read(context, assetFile), StandardCharsets.UTF_8);
    }

    public static String readString(File file) {
        return new String(read(file), StandardCharsets.UTF_8);
    }

    /* JADX WARN: Removed duplicated region for block: B:29:0x003c A[EXC_TOP_SPLITTER, SYNTHETIC] */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public static java.lang.String readString(android.content.Context r5, android.net.Uri r6) {
        /*
            java.lang.StringBuilder r0 = new java.lang.StringBuilder
            r0.<init>()
            android.content.ContentResolver r1 = r5.getContentResolver()     // Catch: java.io.IOException -> L45
            java.io.InputStream r1 = r1.openInputStream(r6)     // Catch: java.io.IOException -> L45
            java.io.BufferedReader r2 = new java.io.BufferedReader     // Catch: java.lang.Throwable -> L39
            java.io.InputStreamReader r3 = new java.io.InputStreamReader     // Catch: java.lang.Throwable -> L39
            r3.<init>(r1)     // Catch: java.lang.Throwable -> L39
            r2.<init>(r3)     // Catch: java.lang.Throwable -> L39
        L17:
            java.lang.String r3 = r2.readLine()     // Catch: java.lang.Throwable -> L2f
            r4 = r3
            if (r3 == 0) goto L22
            r0.append(r4)     // Catch: java.lang.Throwable -> L2f
            goto L17
        L22:
            java.lang.String r3 = r0.toString()     // Catch: java.lang.Throwable -> L2f
            r2.close()     // Catch: java.lang.Throwable -> L39
            if (r1 == 0) goto L2e
            r1.close()     // Catch: java.io.IOException -> L45
        L2e:
            return r3
        L2f:
            r3 = move-exception
            r2.close()     // Catch: java.lang.Throwable -> L34
            goto L38
        L34:
            r4 = move-exception
            r3.addSuppressed(r4)     // Catch: java.lang.Throwable -> L39
        L38:
            throw r3     // Catch: java.lang.Throwable -> L39
        L39:
            r2 = move-exception
            if (r1 == 0) goto L44
            r1.close()     // Catch: java.lang.Throwable -> L40
            goto L44
        L40:
            r3 = move-exception
            r2.addSuppressed(r3)     // Catch: java.io.IOException -> L45
        L44:
            throw r2     // Catch: java.io.IOException -> L45
        L45:
            r1 = move-exception
            r2 = 0
            return r2
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.core.FileUtils.readString(android.content.Context, android.net.Uri):java.lang.String");
    }

    public static boolean writeString(File file, String data) {
        try {
            BufferedWriter bw = new BufferedWriter(new FileWriter(file));
            try {
                bw.write(data);
                bw.flush();
                bw.close();
                return true;
            } finally {
            }
        } catch (IOException e) {
            e.printStackTrace();
            return false;
        }
    }

    public static void symlink(File linkTarget, File linkFile) {
        symlink(linkTarget.getAbsolutePath(), linkFile.getAbsolutePath());
    }

    public static void symlink(String linkTarget, String linkFile) {
        try {
            new File(linkFile).delete();
            Os.symlink(linkTarget, linkFile);
        } catch (ErrnoException e) {
        }
    }

    public static boolean isSymlink(File file) {
        return Files.isSymbolicLink(file.toPath());
    }

    public static boolean delete(File targetFile) {
        if (targetFile == null) {
            return false;
        }
        if (targetFile.isDirectory() && !isSymlink(targetFile) && !clear(targetFile)) {
            return false;
        }
        return targetFile.delete();
    }

    public static boolean clear(File targetFile) {
        File[] files;
        if (targetFile == null) {
            return false;
        }
        if (targetFile.isDirectory() && (files = targetFile.listFiles()) != null) {
            for (File file : files) {
                if (!delete(file)) {
                    return false;
                }
            }
            return true;
        }
        return true;
    }

    public static boolean isEmpty(File targetFile) {
        if (targetFile == null) {
            return true;
        }
        if (!targetFile.isDirectory()) {
            return targetFile.length() == 0;
        }
        String[] files = targetFile.list();
        return files == null || files.length == 0;
    }

    public static boolean isAscendantOf(File srcFile, File dstFile) {
        for (File parent = dstFile.getParentFile(); parent != null; parent = parent.getParentFile()) {
            if (parent.equals(srcFile)) {
                return true;
            }
        }
        return false;
    }

    public static boolean copy(File srcFile, File dstFile) {
        return copy(srcFile, dstFile, (Callback<File>) null);
    }

    public static boolean copy(File srcFile, File dstFile, Callback<File> callback) {
        if (isSymlink(srcFile)) {
            return true;
        }
        if (srcFile.isDirectory()) {
            if (isAscendantOf(srcFile, dstFile) || !(dstFile.exists() || dstFile.mkdirs())) {
                return false;
            }
            if (callback != null) {
                callback.call(dstFile);
            }
            String[] filenames = srcFile.list();
            if (filenames != null) {
                for (String filename : filenames) {
                    if (!copy(new File(srcFile, filename), new File(dstFile, filename), callback)) {
                        return false;
                    }
                }
            }
            return true;
        }
        File parent = dstFile.getParentFile();
        if (!srcFile.exists() || (parent != null && !parent.exists() && !parent.mkdirs())) {
            return false;
        }
        try {
            FileChannel inChannel = new FileInputStream(srcFile).getChannel();
            FileChannel outChannel = new FileOutputStream(dstFile).getChannel();
            inChannel.transferTo(0L, inChannel.size(), outChannel);
            inChannel.close();
            outChannel.close();
            if (callback != null) {
                callback.call(dstFile);
            }
            return dstFile.exists();
        } catch (IOException e) {
            return false;
        }
    }

    public static void copy(Context context, String assetFile, File dstFile) {
        if (isDirectory(context, assetFile)) {
            if (!dstFile.isDirectory()) {
                dstFile.mkdirs();
            }
            try {
                String[] filenames = context.getAssets().list(assetFile);
                for (String filename : filenames) {
                    String relativePath = StringUtils.addEndSlash(assetFile) + filename;
                    if (isDirectory(context, relativePath)) {
                        copy(context, relativePath, new File(dstFile, filename));
                    } else {
                        copy(context, relativePath, dstFile);
                    }
                }
                return;
            } catch (IOException e) {
                return;
            }
        }
        if (dstFile.isDirectory()) {
            dstFile = new File(dstFile, getName(assetFile));
        }
        File parent = dstFile.getParentFile();
        if (!parent.isDirectory()) {
            parent.mkdirs();
        }
        try {
            InputStream inStream = context.getAssets().open(assetFile);
            try {
                BufferedOutputStream outStream = new BufferedOutputStream(new FileOutputStream(dstFile), 65536);
                try {
                    StreamUtils.copy(inStream, outStream);
                    outStream.close();
                    if (inStream != null) {
                        inStream.close();
                    }
                } finally {
                }
            } finally {
            }
        } catch (IOException e2) {
        }
    }

    public static ArrayList<String> readLines(File file) {
        return readLines(file, false);
    }

    public static ArrayList<String> readLines(File file, boolean skipEmptyLines) {
        ArrayList<String> lines = new ArrayList<>();
        try {
            FileInputStream fis = new FileInputStream(file);
            try {
                BufferedReader reader = new BufferedReader(new InputStreamReader(fis));
                while (true) {
                    String line = reader.readLine();
                    String line2 = line;
                    if (line == null) {
                        break;
                    }
                    if (skipEmptyLines) {
                        line2 = line2.trim();
                        if (line2.isEmpty()) {
                        }
                    }
                    lines.add(line2);
                }
                fis.close();
            } finally {
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return lines;
    }

    public static String getName(String path) {
        if (path == null) {
            return "";
        }
        String path2 = StringUtils.removeEndSlash(path);
        int index = Math.max(path2.lastIndexOf(47), path2.lastIndexOf(92));
        return path2.substring(index + 1);
    }

    public static String getBasename(String path) {
        return getName(path).replaceFirst("\\.[^\\.]+$", "");
    }

    public static String getDirname(String path) {
        if (path == null) {
            return "";
        }
        String path2 = StringUtils.removeEndSlash(path);
        int index = Math.max(path2.lastIndexOf(47), path2.lastIndexOf(92));
        return path2.substring(0, index);
    }

    public static void chmod(File file, int mode) {
        try {
            Os.chmod(file.getAbsolutePath(), mode);
        } catch (ErrnoException e) {
        }
    }

    public static File createTempFile(File parent, String prefix) {
        File tempFile = null;
        boolean exists = true;
        while (exists) {
            tempFile = new File(parent, prefix + "-" + UUID.randomUUID().toString().replace("-", "") + ".tmp");
            exists = tempFile.exists();
        }
        return tempFile;
    }

    public static String getFilePathFromUri(Uri uri) {
        if (!uri.getAuthority().equals("com.android.externalstorage.documents")) {
            return null;
        }
        String[] parts = uri.getLastPathSegment().split(":");
        if (!parts[0].equalsIgnoreCase("primary")) {
            return null;
        }
        String path = Environment.getExternalStorageDirectory() + "/" + parts[1];
        return path;
    }

    public static void getSizeAsync(final File file, final Callback<Long> callback) {
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.core.FileUtils$$ExternalSyntheticLambda0
            @Override // java.lang.Runnable
            public final void run() {
                FileUtils.getSize(file, callback);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static void getSize(File file, Callback<Long> callback) {
        if (file == null) {
            return;
        }
        if (file.isFile()) {
            callback.call(Long.valueOf(file.length()));
            return;
        }
        Stack<File> stack = new Stack<>();
        stack.push(file);
        while (!stack.isEmpty()) {
            File current = stack.pop();
            File[] files = current.listFiles();
            if (files != null) {
                for (File f : files) {
                    if (f.isDirectory()) {
                        stack.push(f);
                    } else {
                        long length = f.length();
                        if (length > 0) {
                            callback.call(Long.valueOf(length));
                        }
                    }
                }
            }
        }
    }

    public static long getInternalStorageSize() {
        File dataDir = Environment.getDataDirectory();
        StatFs stat = new StatFs(dataDir.getPath());
        long blockSize = stat.getBlockSizeLong();
        long totalBlocks = stat.getBlockCountLong();
        return totalBlocks * blockSize;
    }

    public static boolean isDirectory(Context context, String assetFile) {
        try {
            String[] files = context.getAssets().list(assetFile);
            if (files != null) {
                return files.length > 0;
            }
            return false;
        } catch (IOException e) {
            return false;
        }
    }

    public static String toRelativePath(String basePath, String fullPath) {
        StringBuilder sb = new StringBuilder();
        sb.append(fullPath.startsWith("/") ? "/" : "");
        sb.append(new File(basePath).toURI().relativize(new File(fullPath).toURI()).getPath());
        return StringUtils.removeEndSlash(sb.toString());
    }

    public static int readInt(String path) {
        int result = 0;
        try {
            RandomAccessFile reader = new RandomAccessFile(path, "r");
            try {
                String line = reader.readLine();
                result = !line.isEmpty() ? Integer.parseInt(line) : 0;
                reader.close();
            } finally {
            }
        } catch (Exception e) {
        }
        return result;
    }

    public static String readSymlink(File file) {
        try {
            return Files.readSymbolicLink(file.toPath()).toString();
        } catch (IOException e) {
            return "";
        }
    }

    public static String getExtension(String filename) {
        int dotIndex;
        return (filename == null || filename.isEmpty() || (dotIndex = filename.lastIndexOf(".")) == -1) ? "" : filename.substring(dotIndex + 1);
    }

    public static void openIntent(Activity activity, String path) {
        Intent intent;
        if (path.startsWith("file://")) {
            File file = new File(Uri.decode(path.replace("file://", "")));
            intent = new Intent("android.intent.action.VIEW", FileProvider.getUriForFile(activity, "com.winlator.FileProvider", file));
            intent.addFlags(1);
        } else {
            intent = new Intent("android.intent.action.VIEW", Uri.parse(path));
        }
        intent.addFlags(268439552);
        activity.startActivity(intent);
    }
}
