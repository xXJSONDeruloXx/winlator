package com.winlator.core;

/* JADX INFO: loaded from: classes.dex */
public abstract class DefaultVersion {
    public static String DXVK(String vulkanDriver) {
        int vkApiVersion = 0;
        if (vulkanDriver != null && vulkanDriver.equals("vortek")) {
            vkApiVersion = GPUHelper.vkGetApiVersion();
        }
        return (vulkanDriver == null || vulkanDriver.equals("turnip") || vkApiVersion >= GPUHelper.vkMakeVersion(1, 3, 0)) ? "2.4.1" : "1.10.3";
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Removed duplicated region for block: B:38:0x0081  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public static java.lang.String valueOf(java.lang.String r2) {
        /*
            Method dump skipped, instruction units count: 240
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.core.DefaultVersion.valueOf(java.lang.String):java.lang.String");
    }
}
