package com.winlator.core;

import java.util.Arrays;
import org.json.JSONArray;
import org.json.JSONException;

/* JADX INFO: loaded from: classes.dex */
public abstract class ArrayUtils {
    public static byte[] concat(byte[]... elements) {
        byte[] result = Arrays.copyOf(elements[0], elements[0].length);
        for (int i = 1; i < elements.length; i++) {
            byte[] newArray = Arrays.copyOf(result, result.length + elements[i].length);
            System.arraycopy(elements[i], 0, newArray, result.length, elements[i].length);
            result = newArray;
        }
        return result;
    }

    @SafeVarargs
    public static <T> T[] concat(T[]... tArr) {
        Object[] objArr = (T[]) Arrays.copyOf(tArr[0], tArr[0].length);
        for (int i = 1; i < tArr.length; i++) {
            Object[] objArrCopyOf = Arrays.copyOf(objArr, objArr.length + tArr[i].length);
            System.arraycopy(tArr[i], 0, objArrCopyOf, objArr.length, tArr[i].length);
            objArr = (T[]) objArrCopyOf;
        }
        return (T[]) objArr;
    }

    public static String[] toStringArray(JSONArray data) {
        String[] stringArray = new String[data.length()];
        for (int i = 0; i < data.length(); i++) {
            try {
                stringArray[i] = data.getString(i);
            } catch (JSONException e) {
            }
        }
        return stringArray;
    }

    public static boolean startsWith(byte[] prefix, byte[] array) {
        if (prefix == null || array == null || array.length < prefix.length) {
            return false;
        }
        for (int i = 0; i < prefix.length; i++) {
            if (array[i] != prefix[i]) {
                return false;
            }
        }
        return true;
    }

    public static boolean contains(int[] array, int value) {
        return indexOf(array, value) != -1;
    }

    public static int indexOf(int[] array, int value) {
        if (array == null) {
            return -1;
        }
        for (int i = 0; i < array.length; i++) {
            if (value == array[i]) {
                return i;
            }
        }
        return -1;
    }

    public static int indexOf(Object[] array, Object value) {
        if (array == null || value == null) {
            return -1;
        }
        for (int i = 0; i < array.length; i++) {
            if (value.equals(array[i])) {
                return i;
            }
        }
        return -1;
    }

    public static int indexOf(byte[] array, int offset, int length, byte... value) {
        byte first = value[0];
        int i = offset;
        while (i < length) {
            if (array[i] != first) {
                do {
                    i++;
                    if (i >= length) {
                        break;
                    }
                } while (array[i] != first);
            }
            if (i < length) {
                int j = i + 1;
                int end = (value.length + j) - 1;
                for (int k = 1; j < end && array[j] == value[k]; k++) {
                    j++;
                }
                if (j == end) {
                    return i;
                }
            }
            i++;
        }
        return -1;
    }
}
