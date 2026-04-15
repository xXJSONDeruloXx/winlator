package com.winlator.container;

import android.content.Context;
import com.winlator.core.GPUHelper;
import com.winlator.core.KeyValueSet;

/* JADX INFO: loaded from: classes.dex */
public abstract class GraphicsDrivers {
    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Removed duplicated region for block: B:20:0x003a  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public static java.lang.String getName(java.lang.String r1) {
        /*
            int r0 = r1.hashCode()
            switch(r0) {
                case -1243435282: goto L30;
                case -862428572: goto L26;
                case -810705759: goto L1c;
                case 3738924: goto L12;
                case 112216388: goto L8;
                default: goto L7;
            }
        L7:
            goto L3a
        L8:
            java.lang.String r0 = "virgl"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 3
            goto L3b
        L12:
            java.lang.String r0 = "zink"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 2
            goto L3b
        L1c:
            java.lang.String r0 = "vortek"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 1
            goto L3b
        L26:
            java.lang.String r0 = "turnip"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 0
            goto L3b
        L30:
            java.lang.String r0 = "gladio"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 4
            goto L3b
        L3a:
            r0 = -1
        L3b:
            switch(r0) {
                case 0: goto L4d;
                case 1: goto L4a;
                case 2: goto L47;
                case 3: goto L44;
                case 4: goto L41;
                default: goto L3e;
            }
        L3e:
            java.lang.String r0 = "None"
            return r0
        L41:
            java.lang.String r0 = "Gladio"
            return r0
        L44:
            java.lang.String r0 = "VirGL"
            return r0
        L47:
            java.lang.String r0 = "Zink"
            return r0
        L4a:
            java.lang.String r0 = "Vortek"
            return r0
        L4d:
            java.lang.String r0 = "Turnip"
            return r0
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.container.GraphicsDrivers.getName(java.lang.String):java.lang.String");
    }

    public static boolean isVulkanDriver(String identifier) {
        return identifier != null && (identifier.equals("turnip") || identifier.equals("vortek"));
    }

    public static boolean isOpenGLDriver(String identifier) {
        return identifier != null && (identifier.equals("zink") || identifier.equals("virgl") || identifier.equals("gladio"));
    }

    public static String[] getItems(String apiName) {
        if (apiName.equalsIgnoreCase("VULKAN")) {
            return new String[]{getName("turnip"), getName("vortek")};
        }
        if (apiName.equalsIgnoreCase("OPENGL")) {
            return new String[]{getName("zink"), getName("virgl"), getName("gladio")};
        }
        return new String[0];
    }

    public static String[] parseIdentifiers(String graphicsDriver) {
        if (graphicsDriver == null || graphicsDriver.isEmpty()) {
            return new String[]{"vortek", "gladio"};
        }
        if (graphicsDriver.contains(",")) {
            return graphicsDriver.split(",");
        }
        if (isVulkanDriver(graphicsDriver)) {
            return new String[]{graphicsDriver, "gladio"};
        }
        if (isOpenGLDriver(graphicsDriver)) {
            return new String[]{"vortek", graphicsDriver};
        }
        return new String[]{"vortek", "gladio"};
    }

    public static KeyValueSet[] parseConfigs(String graphicsDriver, String graphicsDriverConfig) {
        if (graphicsDriverConfig == null || graphicsDriverConfig.isEmpty()) {
            return new KeyValueSet[]{new KeyValueSet(), new KeyValueSet()};
        }
        int separator = graphicsDriverConfig.indexOf("|");
        if (separator != -1) {
            String first = graphicsDriverConfig.substring(0, separator);
            String second = graphicsDriverConfig.substring(separator + 1);
            return new KeyValueSet[]{new KeyValueSet(first), new KeyValueSet(second)};
        }
        if (isVulkanDriver(graphicsDriver)) {
            return new KeyValueSet[]{new KeyValueSet(graphicsDriverConfig), new KeyValueSet()};
        }
        if (isOpenGLDriver(graphicsDriver)) {
            return new KeyValueSet[]{new KeyValueSet(), new KeyValueSet(graphicsDriverConfig)};
        }
        return new KeyValueSet[]{new KeyValueSet(), new KeyValueSet()};
    }

    public static String getDefaultDriver(Context context) {
        return GPUHelper.isAdreno(context) ? "turnip,gladio" : "vortek,gladio";
    }
}
