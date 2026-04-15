package com.winlator.xserver;

import java.util.ArrayList;
import java.util.Arrays;

/* JADX INFO: loaded from: classes.dex */
public abstract class Atom {
    private static final ArrayList<String> atoms = new ArrayList<>(Arrays.asList(null, "PRIMARY", "SECONDARY", "ARC", "ATOM", "BITMAP", "CARDINAL", "COLORMAP", "CURSOR", "CUT_BUFFER0", "CUT_BUFFER1", "CUT_BUFFER2", "CUT_BUFFER3", "CUT_BUFFER4", "CUT_BUFFER5", "CUT_BUFFER6", "CUT_BUFFER7", "DRAWABLE", "FONT", "INTEGER", "PIXMAP", "POINT", "RECTANGLE", "RESOURCE_MANAGER", "RGB_COLOR_MAP", "RGB_BEST_MAP", "RGB_BLUE_MAP", "RGB_DEFAULT_MAP", "RGB_GRAY_MAP", "RGB_GREEN_MAP", "RGB_RED_MAP", "STRING", "VISUALID", "WINDOW", "WM_COMMAND", "WM_HINTS", "WM_CLIENT_MACHINE", "WM_ICON_NAME", "WM_ICON_SIZE", "WM_NAME", "WM_NORMAL_HINTS", "WM_SIZE_HINTS", "WM_ZOOM_HINTS", "MIN_SPACE", "NORM_SPACE", "MAX_SPACE", "END_SPACE", "SUPERSC.LPT_X", "SUPERSC.LPT_Y", "SUBSC.LPT_X", "SUBSC.LPT_Y", "UNDERLINE_POSITION", "UNDERLINE_THICKNESS", "STRIKEOUT_ASCENT", "STRIKEOUT_DESCENT", "ITALIC_ANGLE", "X_HEIGHT", "QUAD_WIDTH", "WEIGHT", "POINT_SIZE", "RESOLUTION", "COPYRIGHT", "NOTICE", "FONT_NAME", "FAMILY_NAME", "FULL_NAME", "CAP_HEIGHT", "WM_CLASS", "WM_TRANSIENT_FOR", "_MOTIF_WM_HINTS", "_NET_WM_PID", "_NET_WM_WINDOW_TYPE", "_NET_WM_HWND", "_NET_WM_WOW64", "_NET_WM_SURFACE", "_NET_WM_GPU_INFO"));

    public static synchronized String getName(int id) {
        return atoms.get(id);
    }

    public static synchronized int getId(String name) {
        if (name == null) {
            return 0;
        }
        int i = 0;
        while (true) {
            ArrayList<String> arrayList = atoms;
            if (i >= arrayList.size()) {
                return -1;
            }
            if (name.equals(arrayList.get(i))) {
                return i;
            }
            i++;
        }
    }

    public static synchronized int internAtom(String name) {
        int id;
        id = getId(name);
        if (id == -1) {
            ArrayList<String> arrayList = atoms;
            id = arrayList.size();
            arrayList.add(name);
        }
        return id;
    }

    /* JADX WARN: Removed duplicated region for block: B:11:0x0012  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public static synchronized boolean isValid(int r2) {
        /*
            java.lang.Class<com.winlator.xserver.Atom> r0 = com.winlator.xserver.Atom.class
            monitor-enter(r0)
            if (r2 <= 0) goto L12
            java.util.ArrayList<java.lang.String> r1 = com.winlator.xserver.Atom.atoms     // Catch: java.lang.Throwable -> Lf
            int r1 = r1.size()     // Catch: java.lang.Throwable -> Lf
            if (r2 >= r1) goto L12
            r1 = 1
            goto L13
        Lf:
            r2 = move-exception
            monitor-exit(r0)
            throw r2
        L12:
            r1 = 0
        L13:
            monitor-exit(r0)
            return r1
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.xserver.Atom.isValid(int):boolean");
    }
}
