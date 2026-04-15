package com.winlator.core;

import android.content.Context;
import java.nio.charset.Charset;
import java.util.Arrays;
import java.util.Locale;

/* JADX INFO: loaded from: classes.dex */
public class StringUtils {
    public static String removeStartSlash(String value) {
        while (true) {
            if (value.startsWith("/") || value.startsWith("\\")) {
                value = value.substring(1);
            } else {
                return value;
            }
        }
    }

    public static String removeEndSlash(String value) {
        while (true) {
            if (value.endsWith("/") || value.endsWith("\\")) {
                value = value.substring(0, value.length() - 1);
            } else {
                return value;
            }
        }
    }

    public static String addEndSlash(String value) {
        if (value.endsWith("/")) {
            return value;
        }
        return value + "/";
    }

    public static String replace(String text, int start, int end, String value) {
        return text.substring(0, start) + value + text.substring(end);
    }

    public static String escapeDOSPath(String path) {
        return path.replace("\\", "\\\\").replace(" ", "\\ ");
    }

    public static String unescapeDOSPath(String path) {
        return path.replaceAll("\\\\([^\\\\]+)", "$1").replaceAll("\\\\([^\\\\]+)", "$1").replaceAll("\\\\\\\\", "\\\\").trim();
    }

    public static String parseIdentifier(Object text) {
        return text.toString().toLowerCase(Locale.ENGLISH).replaceAll(" *\\(([^\\)]+)\\)$", "").replaceAll("( \\+ )+| +", "-");
    }

    public static String parseNumber(Object text) {
        return parseNumber(text, "");
    }

    public static String parseMemorySize(Object text) {
        return parseMemorySize(text, "MB");
    }

    public static String parseMemorySize(Object text, String targetUnit) {
        String[] units = {"bytes", "KB", "MB", "GB", "TB"};
        String value = text.toString();
        int targetIndex = -1;
        int i = 0;
        while (true) {
            if (i >= units.length) {
                break;
            }
            if (!units[i].equalsIgnoreCase(targetUnit)) {
                i++;
            } else {
                targetIndex = i;
                break;
            }
        }
        if (targetIndex != -1) {
            for (int i2 = 0; i2 < units.length; i2++) {
                try {
                    if (value.endsWith(" " + units[i2])) {
                        long number = Long.parseLong(value.replace(" " + units[i2], ""));
                        int diff = targetIndex - i2;
                        if (diff < 0) {
                            return String.valueOf((long) (number * Math.pow(1024.0d, Math.abs(diff))));
                        }
                        if (diff > 0) {
                            return String.valueOf(number / Math.pow(1024.0d, diff));
                        }
                        return String.valueOf(number);
                    }
                } catch (NumberFormatException e) {
                    return "0";
                }
            }
        }
        return value.matches("[0-9\\.]+") ? value : "0";
    }

    public static String parseNumber(Object text, String fallback) {
        String result = text != null ? text.toString().replaceAll("[^0-9\\.]+", "") : "";
        return !result.isEmpty() ? result : fallback;
    }

    public static String getString(Context context, String resName) {
        try {
            int resID = context.getResources().getIdentifier(resName.toLowerCase(Locale.ENGLISH), "string", context.getPackageName());
            return context.getString(resID);
        } catch (Exception e) {
            return null;
        }
    }

    public static String formatBytes(long bytes) {
        return formatBytes(bytes, true);
    }

    public static String formatBytes(long bytes, boolean withSuffix) {
        String suffix;
        if (bytes <= 0) {
            return "0 bytes";
        }
        String[] units = {"bytes", "KB", "MB", "GB", "TB"};
        int digitGroups = (int) (Math.log10(bytes) / Math.log10(1024.0d));
        if (withSuffix) {
            suffix = " " + units[digitGroups];
        } else {
            suffix = "";
        }
        return String.format(Locale.ENGLISH, "%.2f", Double.valueOf(bytes / Math.pow(1024.0d, digitGroups))) + suffix;
    }

    public static String fromANSIString(byte[] bytes) {
        return fromANSIString(bytes, null);
    }

    public static String fromANSIString(byte[] bytes, Charset charset) {
        String value = charset != null ? new String(bytes, charset) : new String(bytes);
        int indexOfNull = value.indexOf(0);
        return indexOfNull != -1 ? value.substring(0, indexOfNull) : value;
    }

    public static String clearReservedChars(String name) {
        return (name == null || name.isEmpty()) ? "" : name.replaceAll("[\\\\/:*?\"<>\\|]+", "");
    }

    public static String repeat(char chr, int count) {
        char[] buffer = new char[count];
        Arrays.fill(buffer, chr);
        return new String(buffer);
    }
}
