package com.winlator.core;

import com.winlator.core.WineRegistryEditor;
import com.winlator.math.Mathf;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.CharBuffer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import java.util.function.ToIntFunction;

/* JADX INFO: loaded from: classes.dex */
public class WineRegistryEditor implements Closeable {
    private final File cloneFile;
    private final File file;
    private boolean modified = false;
    private boolean createKeyIfNotExist = true;

    private native int[] getKeyLocation(String str, String str2);

    private native int[] getValueLocation(String str, int[] iArr, String str2);

    static {
        System.loadLibrary("winlator");
    }

    public static class Location {
        public final int end;
        public int mbCount;
        public final int offset;
        public final int start;
        private Object tag;

        public Location(int offset, int start, int end) {
            this.offset = offset;
            this.start = start;
            this.end = end;
        }

        public int length() {
            return this.end - this.start;
        }

        public String toString() {
            return this.offset + "," + this.start + "," + this.end;
        }

        public int[] toIntArray() {
            return new int[]{this.offset, this.start, this.end, this.mbCount};
        }

        public boolean equals(Object obj) {
            if (!(obj instanceof Location)) {
                return false;
            }
            Location other = (Location) obj;
            return this.offset == other.offset && this.start == other.start && this.end == other.end;
        }
    }

    public WineRegistryEditor(File file) {
        this.file = file;
        File fileCreateTempFile = FileUtils.createTempFile(file.getParentFile(), FileUtils.getBasename(file.getPath()));
        this.cloneFile = fileCreateTempFile;
        if (!file.isFile()) {
            try {
                fileCreateTempFile.createNewFile();
            } catch (IOException e) {
            }
        } else {
            FileUtils.copy(file, fileCreateTempFile);
        }
    }

    private static String escape(String str) {
        return str.replace("\\", "\\\\").replace("\"", "\\\"");
    }

    private static String unescape(String str) {
        return str.replace("\\\"", "\"").replace("\\\\", "\\");
    }

    @Override // java.io.Closeable, java.lang.AutoCloseable
    public void close() {
        if (this.modified && this.cloneFile.exists()) {
            this.cloneFile.renameTo(this.file);
        } else {
            this.cloneFile.delete();
        }
    }

    public void setCreateKeyIfNotExist(boolean createKeyIfNotExist) {
        this.createKeyIfNotExist = createKeyIfNotExist;
    }

    private Location createKey(String key) {
        Location location = getParentKeyLocation(key);
        boolean success = false;
        char[] buffer = new char[65536];
        File tempFile = FileUtils.createTempFile(this.file.getParentFile(), FileUtils.getBasename(this.file.getPath()));
        try {
            BufferedReader reader = new BufferedReader(new FileReader(this.cloneFile), 65536);
            try {
                BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile), 65536);
                try {
                    if (location == null) {
                        while (true) {
                            int length = reader.read(buffer);
                            if (length == -1) {
                                break;
                            }
                            writer.write(buffer, 0, length);
                        }
                    } else {
                        int i = 0;
                        int end = location.end + 1;
                        while (i < end) {
                            int length2 = Math.min(buffer.length, end - i);
                            reader.read(buffer, 0, length2);
                            writer.write(buffer, 0, length2);
                            i += length2;
                        }
                    }
                    long currentTime = System.currentTimeMillis() + 116444736000000000L;
                    String content = "\n[" + escape(key) + "] " + ((currentTime - 116444736000000000L) / 1000) + String.format(Locale.ENGLISH, "\n#time=%x%08x", Long.valueOf(currentTime >> 32), Integer.valueOf((int) currentTime)) + "\n";
                    writer.write(content);
                    while (true) {
                        int length3 = reader.read(buffer);
                        if (length3 == -1) {
                            break;
                        }
                        writer.write(buffer, 0, length3);
                    }
                    success = true;
                    writer.close();
                    reader.close();
                } finally {
                }
            } finally {
            }
        } catch (IOException e) {
        }
        if (success) {
            this.modified = true;
            tempFile.renameTo(this.cloneFile);
            return getKeyLocation(key);
        }
        tempFile.delete();
        return null;
    }

    public String getStringValue(String key, String name, String fallback) {
        String value = getRawValue(key, name);
        return value != null ? value.substring(1, value.length() - 1) : fallback;
    }

    public void setStringValue(String key, String name, String value) {
        String str;
        if (value != null) {
            str = "\"" + escape(value) + "\"";
        } else {
            str = "\"\"";
        }
        setRawValue(key, name, str);
    }

    public void setStringValues(String key, String[]... items) {
        String[][] escapedItems = new String[items.length][];
        for (int i = 0; i < items.length; i++) {
            String[] strArr = new String[2];
            strArr[0] = items[i][0];
            strArr[1] = items[i][1] != null ? "\"" + escape(items[i][1]) + "\"" : "\"\"";
            escapedItems[i] = strArr;
        }
        setRawValues(key, escapedItems);
    }

    public Integer getDwordValue(String key, String name, Integer fallback) {
        String value = getRawValue(key, name);
        if (value == null) {
            return fallback;
        }
        return Integer.decode("0x" + value.substring(6));
    }

    public void setDwordValue(String key, String name, int value) {
        setRawValue(key, name, "dword:" + String.format("%08x", Integer.valueOf(value)));
    }

    public void setHexValue(String key, String name, String value) {
        int start = ((int) Mathf.roundTo(name.length(), 2.0f)) + 7;
        StringBuilder lines = new StringBuilder();
        int j = start;
        for (int i = 0; i < value.length(); i++) {
            if (i > 0 && i % 2 == 0) {
                lines.append(",");
            }
            int j2 = j + 1;
            if (j <= 56) {
                j = j2;
            } else {
                lines.append("\\\n  ");
                j = 8;
            }
            lines.append(value.charAt(i));
        }
        setRawValue(key, name, "hex:" + ((Object) lines));
    }

    public void setHexValues(String key, String name, byte[] bytes) {
        StringBuilder data = new StringBuilder();
        for (byte b : bytes) {
            data.append(String.format(Locale.ENGLISH, "%02x", Integer.valueOf(Byte.toUnsignedInt(b))));
        }
        setHexValue(key, name, data.toString());
    }

    public byte[] getHexValues(String key, String name) {
        String value = getRawValue(key, name);
        if (value == null) {
            return null;
        }
        if (value.startsWith("hex:") || value.startsWith("hex(")) {
            String[] items = value.replaceAll("hex[\\(\\)0-9]*:", "").replace("\\\n  ", "").split(",");
            byte[] bytes = new byte[items.length];
            for (int i = 0; i < items.length; i++) {
                try {
                    bytes[i] = Integer.decode("0x" + items[i]).byteValue();
                } catch (NumberFormatException e) {
                }
            }
            return bytes;
        }
        return null;
    }

    public String getSymlinkValue(String key, String name) {
        byte[] symlinkBytes = getHexValues(key, name);
        if (symlinkBytes != null) {
            CharBuffer buffer = ByteBuffer.wrap(symlinkBytes).order(ByteOrder.LITTLE_ENDIAN).asCharBuffer();
            return buffer.toString().replace("\\Registry\\Machine\\", "");
        }
        return null;
    }

    private String getRawValue(String key, String name) {
        Location valueLocation;
        Location keyLocation = getKeyLocation(key);
        if (keyLocation == null || (valueLocation = getValueLocation(keyLocation, name)) == null) {
            return null;
        }
        boolean success = false;
        char[] buffer = new char[valueLocation.length()];
        try {
            BufferedReader reader = new BufferedReader(new FileReader(this.cloneFile), 65536);
            try {
                reader.skip(valueLocation.start);
                success = reader.read(buffer) == buffer.length;
                reader.close();
            } finally {
            }
        } catch (IOException e) {
        }
        if (success) {
            return unescape(new String(buffer));
        }
        return null;
    }

    private void setRawValue(String key, String name, String value) {
        BufferedReader reader = null;
        String str;
        Location keyLocation = getKeyLocation(key);
        if (keyLocation == null) {
            if (this.createKeyIfNotExist) {
                keyLocation = createKey(key);
            } else {
                return;
            }
        }
        Location valueLocation = getValueLocation(keyLocation, name);
        char[] buffer = new char[65536];
        boolean success = false;
        File tempFile = FileUtils.createTempFile(this.file.getParentFile(), FileUtils.getBasename(this.file.getPath()));
        try {
            reader = new BufferedReader(new FileReader(this.cloneFile), 65536);
        } catch (IOException e) {
            return;
        }
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile), 65536);
            int i = 0;
                int end = valueLocation != null ? valueLocation.start : keyLocation.end;
                while (i < end) {
                    int length = Math.min(buffer.length, end - i);
                    reader.read(buffer, 0, length);
                    writer.write(buffer, 0, length);
                    i += length;
                }
                if (valueLocation == null) {
                    StringBuilder sb = new StringBuilder();
                    sb.append("\n");
                    if (name != null) {
                        str = "\"" + escape(name) + "\"";
                    } else {
                        str = "@";
                    }
                    sb.append(str);
                    sb.append("=");
                    sb.append(value);
                    writer.write(sb.toString());
                } else {
                    writer.write(value);
                    reader.skip(valueLocation.length());
                }
                while (true) {
                    int length2 = reader.read(buffer);
                    if (length2 == -1) {
                        break;
                    } else {
                        writer.write(buffer, 0, length2);
                    }
                }
                success = true;
                writer.close();
                reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        if (success) {
            this.modified = true;
            tempFile.renameTo(this.cloneFile);
        } else {
            tempFile.delete();
        }
    }

    private void setRawValues(String key, String[]... items) {
        int i;
        BufferedWriter writer;
        int i2;
        Location keyLocation = getKeyLocation(key);
        if (keyLocation == null) {
            if (this.createKeyIfNotExist) {
                keyLocation = createKey(key);
            } else {
                return;
            }
        }
        ArrayList<Location> valueLocations = new ArrayList<>();
        int i3 = 0;
        while (true) {
            i = -1;
            if (i3 >= items.length) {
                break;
            }
            Location valueLocation = getValueLocation(keyLocation, items[i3][0]);
            if (valueLocation == null) {
                valueLocation = new Location(0, (Integer.MAX_VALUE - items.length) + i3, -1);
            }
            valueLocation.tag = items[i3];
            valueLocations.add(valueLocation);
            i3++;
        }
        valueLocations.sort(Comparator.comparingInt(new ToIntFunction() { // from class: com.winlator.core.WineRegistryEditor$$ExternalSyntheticLambda0
            @Override // java.util.function.ToIntFunction
            public final int applyAsInt(Object obj) {
                return ((WineRegistryEditor.Location) obj).start;
            }
        }));
        char[] buffer = new char[65536];
        boolean success = false;
        File tempFile = FileUtils.createTempFile(this.file.getParentFile(), FileUtils.getBasename(this.file.getPath()));
        try {
            BufferedReader reader = new BufferedReader(new FileReader(this.cloneFile), 65536);
            try {
                writer = new BufferedWriter(new FileWriter(tempFile), 65536);
                int position = 0;
                try {
                    for (Location valueLocation2 : valueLocations) {
                        if (valueLocation2.end != i) {
                            int i4 = position;
                            while (true) {
                                int i5 = valueLocation2.start;
                                if (i4 >= i5) {
                                    break;
                                }
                                int length = Math.min(buffer.length, i5 - i4);
                                reader.read(buffer, 0, length);
                                writer.write(buffer, 0, length);
                                position += length;
                                i4 += length;
                            }
                            writer.write(((String[]) valueLocation2.tag)[1]);
                            reader.skip(valueLocation2.length());
                            position += valueLocation2.length();
                            i = -1;
                        }
                    }
                    i2 = position;
                } finally {
                }
            } finally {
            }
            while (true) {
                int i6 = keyLocation.end;
                if (i2 >= i6) {
                    break;
                }
                int length2 = Math.min(buffer.length, i6 - i2);
                reader.read(buffer, 0, length2);
                writer.write(buffer, 0, length2);
                i2 += length2;
            }
            for (Location valueLocation3 : valueLocations) {
                if (valueLocation3.end == -1) {
                    String[] item = (String[]) valueLocation3.tag;
                    StringBuilder sb = new StringBuilder();
                    sb.append("\n");
                    sb.append(item[0] != null ? "\"" + escape(item[0]) + "\"" : "@");
                    sb.append("=");
                    sb.append(item[1]);
                    writer.write(sb.toString());
                }
            }
            while (true) {
                int length3 = reader.read(buffer);
                if (length3 == -1) {
                    break;
                } else {
                    writer.write(buffer, 0, length3);
                }
            }
            success = true;
            writer.close();
            reader.close();
        } catch (IOException e) {
        }
        if (success) {
            this.modified = true;
            tempFile.renameTo(this.cloneFile);
        } else {
            tempFile.delete();
        }
    }

    public void removeValue(String key, String name) {
        Location valueLocation;
        Location keyLocation = getKeyLocation(key);
        if (keyLocation == null || (valueLocation = getValueLocation(keyLocation, name)) == null) {
            return;
        }
        removeRegion(valueLocation);
    }

    public boolean removeKey(String key) {
        return removeKey(key, false);
    }

    public boolean removeKey(String key, boolean removeTree) {
        boolean removed = false;
        if (!removeTree) {
            Location location = getKeyLocation(key, false);
            return location != null && removeRegion(location);
        }
        while (true) {
            Location location2 = getKeyLocation(key, true);
            if (location2 != null) {
                if (removeRegion(location2)) {
                    removed = true;
                }
            } else {
                return removed;
            }
        }
    }

    private boolean removeRegion(Location location) {
        BufferedWriter writer;
        int length;
        int i;
        int i2;
        char[] buffer = new char[65536];
        boolean success = false;
        File tempFile = FileUtils.createTempFile(this.file.getParentFile(), FileUtils.getBasename(this.file.getPath()));
        try {
            BufferedReader reader = new BufferedReader(new FileReader(this.cloneFile), 65536);
            try {
                writer = new BufferedWriter(new FileWriter(tempFile), 65536);
                length = 0;
                i = 0;
            } finally {
            }
            while (true) {
                try {
                    i2 = location.offset;
                    if (i >= i2) {
                        break;
                    }
                    length = Math.min(buffer.length, i2 - i);
                    reader.read(buffer, 0, length);
                    writer.write(buffer, 0, length);
                    i += length;
                } finally {
                }
            }
            boolean skipLine = length > 1 && buffer[length + (-1)] == '\n';
            reader.skip((location.end - i2) + (skipLine ? 1 : 0));
            while (true) {
                int length2 = reader.read(buffer);
                if (length2 == -1) {
                    break;
                }
                writer.write(buffer, 0, length2);
            }
            success = true;
            writer.close();
            reader.close();
        } catch (IOException e) {
        }
        if (success) {
            this.modified = true;
            tempFile.renameTo(this.cloneFile);
        } else {
            tempFile.delete();
        }
        return success;
    }

    private Location getParentKeyLocation(String key) {
        String[] parts = key.split("\\\\");
        ArrayList<String> stack = new ArrayList<>(Arrays.asList(parts).subList(0, parts.length - 1));
        while (!stack.isEmpty()) {
            String currentKey = String.join("\\", stack);
            Location location = getKeyLocation(currentKey, true);
            if (location != null) {
                return location;
            }
            stack.remove(stack.size() - 1);
        }
        return null;
    }

    private Location getKeyLocation(String key) {
        return getKeyLocation(key, false);
    }

    private Location getKeyLocation(String key, boolean keyAsPrefix) {
        if (!this.cloneFile.isFile()) {
            return null;
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        sb.append(escape(key));
        sb.append(!keyAsPrefix ? "]" : "");
        String key2 = sb.toString();
        int[] result = getKeyLocation(this.cloneFile.getPath(), key2);
        Location location = new Location(result[0], result[1], result[2]);
        location.mbCount = result[3];
        if (location.start != -1) {
            return location;
        }
        return null;
    }

    private Location getValueLocation(Location keyLocation, String name) {
        String name2;
        if (!this.cloneFile.isFile() || keyLocation.start == keyLocation.end) {
            return null;
        }
        if (name != null) {
            name2 = "\"" + escape(name) + "\"=";
        } else {
            name2 = "@=";
        }
        int[] result = getValueLocation(this.cloneFile.getPath(), keyLocation.toIntArray(), name2);
        Location location = new Location(result[0], result[1], result[2]);
        if (location.start != -1) {
            return location;
        }
        return null;
    }
}
