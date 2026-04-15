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
        File binFile = new File(RootFS.find(context).getRootDir(), "/usr/local/bin/box64");
        try {
            BufferedInputStream inStream = new BufferedInputStream(new FileInputStream(binFile), 65536);
            try {
                byte[] buffer = new byte[4096];
                byte[] marker = new byte[]{66, 111, 120, 54, 52, 32, 97, 114, 109, 54, 52, 32, 118};
                int bytesRead;
                while ((bytesRead = inStream.read(buffer)) != -1) {
                    int index = ArrayUtils.indexOf(buffer, 0, bytesRead, marker);
                    if (index != -1) {
                        int start = marker.length + index;
                        int end = ArrayUtils.indexOf(buffer, start, bytesRead, (byte) 32);
                        return end != -1 ? new String(buffer, start, end - start) : "";
                    }
                }
                return "";
            } finally {
                inStream.close();
            }
        } catch (IOException e) {
            return "";
        }
    }
}
