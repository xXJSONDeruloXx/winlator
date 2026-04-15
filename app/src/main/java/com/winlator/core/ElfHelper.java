package com.winlator.core;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;

/* JADX INFO: loaded from: classes.dex */
public abstract class ElfHelper {
    private static int getEIClass(File binFile) {
        try {
            InputStream inStream = new FileInputStream(binFile);
            try {
                byte[] header = new byte[52];
                inStream.read(header);
                if (header[0] == 127 && header[1] == 69 && header[2] == 76 && header[3] == 70) {
                    return header[4];
                }
                return 0;
            } finally {
                inStream.close();
            }
        } catch (IOException e) {
            return 0;
        }
    }

    public static boolean is64Bit(File binFile) {
        return getEIClass(binFile) == 2;
    }
}
