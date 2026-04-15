package com.winlator.xserver;

import com.winlator.core.ArrayUtils;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;

/* JADX INFO: loaded from: classes.dex */
public class Property {
    private String cachedString;
    public ByteBuffer data;
    public final Format format;
    public final int name;
    public final int type;

    public enum Mode {
        REPLACE,
        PREPEND,
        APPEND
    }

    public enum Format {
        BYTE_ARRAY(8),
        SHORT_ARRAY(16),
        INT_ARRAY(32);

        public final byte value;

        Format(int value) {
            this.value = (byte) value;
        }

        public static Format valueOf(int format) {
            switch (format) {
                case 8:
                    return BYTE_ARRAY;
                case 16:
                    return SHORT_ARRAY;
                case 32:
                    return INT_ARRAY;
                default:
                    return null;
            }
        }
    }

    public Property(int name, int type, Format format, byte[] data) {
        this.name = name;
        this.type = type;
        this.format = format;
        replace(data);
    }

    public void replace(byte[] data) {
        this.cachedString = null;
        this.data = ByteBuffer.wrap(data != null ? data : new byte[0]).order(ByteOrder.LITTLE_ENDIAN);
    }

    public void prepend(byte[] values) {
        this.cachedString = null;
        replace(ArrayUtils.concat(values, this.data.array()));
    }

    public void append(byte[] values) {
        this.cachedString = null;
        replace(ArrayUtils.concat(this.data.array(), values));
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Removed duplicated region for block: B:14:0x0032  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public java.lang.String toString() {
        /*
            Method dump skipped, instruction units count: 226
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.xserver.Property.toString():java.lang.String");
    }

    /* JADX INFO: renamed from: com.winlator.xserver.Property$1, reason: invalid class name */
    static /* synthetic */ class AnonymousClass1 {
        static final /* synthetic */ int[] $SwitchMap$com$winlator$xserver$Property$Format;

        static {
            int[] iArr = new int[Format.values().length];
            $SwitchMap$com$winlator$xserver$Property$Format = iArr;
            try {
                iArr[Format.BYTE_ARRAY.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                $SwitchMap$com$winlator$xserver$Property$Format[Format.SHORT_ARRAY.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            try {
                $SwitchMap$com$winlator$xserver$Property$Format[Format.INT_ARRAY.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
        }
    }

    public int getInt(int index) {
        return this.data.getInt(index * 4);
    }

    public long getLong(int index) {
        return this.data.getLong(index * 8);
    }
}
