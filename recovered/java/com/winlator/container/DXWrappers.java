package com.winlator.container;

import com.winlator.core.KeyValueSet;

/* JADX INFO: loaded from: classes.dex */
public abstract class DXWrappers {
    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Removed duplicated region for block: B:17:0x0030  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public static java.lang.String getName(java.lang.String r1) {
        /*
            int r0 = r1.hashCode()
            switch(r0) {
                case -1061449997: goto L26;
                case 3098185: goto L1c;
                case 112260896: goto L12;
                case 1349510476: goto L8;
                default: goto L7;
            }
        L7:
            goto L30
        L8:
            java.lang.String r0 = "wined3d"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 0
            goto L31
        L12:
            java.lang.String r0 = "vkd3d"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 2
            goto L31
        L1c:
            java.lang.String r0 = "dxvk"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 1
            goto L31
        L26:
            java.lang.String r0 = "cnc-ddraw"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 3
            goto L31
        L30:
            r0 = -1
        L31:
            switch(r0) {
                case 0: goto L40;
                case 1: goto L3d;
                case 2: goto L3a;
                case 3: goto L37;
                default: goto L34;
            }
        L34:
            java.lang.String r0 = "None"
            return r0
        L37:
            java.lang.String r0 = "CNC DDraw"
            return r0
        L3a:
            java.lang.String r0 = "VKD3D"
            return r0
        L3d:
            java.lang.String r0 = "DXVK"
            return r0
        L40:
            java.lang.String r0 = "WineD3D"
            return r0
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.container.DXWrappers.getName(java.lang.String):java.lang.String");
    }

    public static String parseIdentifier(String dxwrapper) {
        if (dxwrapper == null || dxwrapper.isEmpty()) {
            return "dxvk";
        }
        return (dxwrapper.equals("wined3d") || dxwrapper.equals("dxvk")) ? dxwrapper : "dxvk";
    }

    public static KeyValueSet[] parseConfigs(String dxwrapper, String dxwrapperConfig) {
        if (dxwrapperConfig == null || dxwrapperConfig.isEmpty()) {
            return new KeyValueSet[]{new KeyValueSet(), new KeyValueSet()};
        }
        int separator = dxwrapperConfig.indexOf("|");
        if (separator != -1) {
            String first = dxwrapperConfig.substring(0, separator);
            String second = dxwrapperConfig.substring(separator + 1);
            return new KeyValueSet[]{new KeyValueSet(first), new KeyValueSet(second)};
        }
        if (dxwrapper != null) {
            if (dxwrapper.equals("wined3d") || dxwrapper.equals("dxvk")) {
                return new KeyValueSet[]{new KeyValueSet(dxwrapperConfig), new KeyValueSet()};
            }
            if (dxwrapper.equals("vkd3d")) {
                return new KeyValueSet[]{new KeyValueSet(), new KeyValueSet(dxwrapperConfig)};
            }
        }
        return new KeyValueSet[]{new KeyValueSet(), new KeyValueSet()};
    }
}
