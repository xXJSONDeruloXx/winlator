package com.winlator.box64;

import android.content.Context;
import com.winlator.core.ArrayUtils;
import com.winlator.xenvironment.RootFS;
import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public abstract class Box64Utils {
    public static String extractBinVersion(Context context) {
        BufferedInputStream inStream;
        byte[] buffer;
        byte[] str;
        int bytesRead;
        int index;
        File binFile = new File(RootFS.find(context).getRootDir(), "/usr/local/bin/box64");
        try {
            inStream = new BufferedInputStream(new FileInputStream(binFile), 65536);
            try {
                buffer = new byte[4096];
                str = new byte[]{66, 111, 120, 54, 52, 32, 97, 114, 109, 54, 52, 32, 118};
            } finally {
            }
        } catch (IOException e) {
        }
        do {
            bytesRead = inStream.read(buffer);
            if (bytesRead != -1) {
                index = ArrayUtils.indexOf(buffer, 0, bytesRead, str);
            } else {
                inStream.close();
                return "";
            }
            return "";
        } while (index == -1);
        int start = str.length + index;
        int end = ArrayUtils.indexOf(buffer, start, bytesRead, 32);
        String str2 = end != -1 ? new String(buffer, start, end - start) : "";
        inStream.close();
        return str2;
    }
}
