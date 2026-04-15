package com.winlator.core;

import java.io.BufferedOutputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.util.Enumeration;
import org.apache.commons.compress.archivers.zip.ZipArchiveEntry;
import org.apache.commons.compress.archivers.zip.ZipFile;

/* JADX INFO: loaded from: classes.dex */
public abstract class ZipUtils {
    public static boolean extract(File source, File destination) {
        try {
            ZipFile zipFile = new ZipFile(source);
            Enumeration<ZipArchiveEntry> entries = zipFile.getEntries();
            while (entries.hasMoreElements()) {
                ZipArchiveEntry entry = entries.nextElement();
                File file = new File(destination, entry.getName());
                if (entry.isDirectory()) {
                    if (!file.isDirectory()) {
                        file.mkdirs();
                    }
                } else if (entry.isUnixSymlink()) {
                    FileUtils.symlink(zipFile.getUnixSymlink(entry), file.getAbsolutePath());
                } else {
                    InputStream inStream = zipFile.getInputStream(entry);
                    try {
                        BufferedOutputStream outStream = new BufferedOutputStream(new FileOutputStream(file), 65536);
                        try {
                            if (!StreamUtils.copy(inStream, outStream)) {
                                outStream.close();
                                if (inStream != null) {
                                    inStream.close();
                                }
                                return false;
                            }
                            outStream.close();
                            if (inStream != null) {
                                inStream.close();
                            }
                        } finally {
                        }
                    } finally {
                    }
                }
                FileUtils.chmod(file, 505);
            }
            zipFile.close();
            return true;
        } catch (Exception e) {
            return false;
        }
    }

    public static byte[] read(File source, String localPath) {
        boolean pathIsPrefix = false;
        boolean pathIsSuffix = false;
        try {
            if (localPath.startsWith("*")) {
                pathIsSuffix = true;
            } else if (localPath.endsWith("*")) {
                pathIsPrefix = true;
            }
            String localPath2 = localPath.replace("*", "");
            ByteArrayOutputStream dataOutputStream = new ByteArrayOutputStream();
            ZipFile zipFile = new ZipFile(source);
            Enumeration<ZipArchiveEntry> entries = zipFile.getEntries();
            while (entries.hasMoreElements()) {
                ZipArchiveEntry entry = entries.nextElement();
                String entryName = entry.getName();
                boolean match = pathIsSuffix ? entryName.endsWith(localPath2) : pathIsPrefix ? entryName.startsWith(localPath2) : entryName.equals(localPath2);
                if (match && !entry.isDirectory() && !entry.isUnixSymlink()) {
                    InputStream inStream = zipFile.getInputStream(entry);
                    try {
                        BufferedOutputStream outStream = new BufferedOutputStream(dataOutputStream, 65536);
                        try {
                            if (!StreamUtils.copy(inStream, outStream)) {
                                outStream.close();
                                if (inStream != null) {
                                    inStream.close();
                                }
                                return null;
                            }
                            outStream.close();
                            if (inStream != null) {
                                inStream.close();
                            }
                            return dataOutputStream.toByteArray();
                        } finally {
                        }
                    } finally {
                    }
                }
            }
            zipFile.close();
            return null;
        } catch (Exception e) {
            return null;
        }
    }
}
