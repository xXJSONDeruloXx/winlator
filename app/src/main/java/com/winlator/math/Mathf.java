package com.winlator.math;

import android.util.Rational;

/* JADX INFO: loaded from: classes.dex */
public abstract class Mathf {
    public static float clamp(float x, float min, float max) {
        return x < min ? min : x > max ? max : x;
    }

    public static int clamp(int x, int min, int max) {
        return x < min ? min : x > max ? max : x;
    }

    public static float roundTo(float x, float step) {
        return roundTo(x, step, true);
    }

    public static float roundTo(float x, float step, boolean roundHalfDown) {
        return (float) ((roundHalfDown ? Math.floor(x / step) : Math.round(x / step)) * ((double) step));
    }

    public static int roundPoint(float x) {
        return (int) (x <= 0.0f ? Math.floor(x) : Math.ceil(x));
    }

    public static byte sign(float x) {
        return (byte) (x < 0.0f ? -1 : x > 0.0f ? 1 : 0);
    }

    public static float lengthSq(float x, float y) {
        return (x * x) + (y * y);
    }

    public static float distance(float x0, float y0, float x1, float y1) {
        return (float) Math.hypot(x0 - x1, y0 - y1);
    }

    public static float fract(float x) {
        return x - ((int) Math.floor(x));
    }

    public static Rational farey(float x, float N) {
        int a = 0;
        int b = 1;
        int c = 1;
        int d = 0;
        while (b <= N && d <= N) {
            float mediant = (a + c) / (b + d);
            if (Math.abs(x - mediant) < 1.0E-5f) {
                if (b + d <= N) {
                    return new Rational(a + c, b + d);
                }
                if (d > b) {
                    return new Rational(c, d);
                }
                return new Rational(a, b);
            }
            if (x > mediant) {
                a += c;
                b += d;
            } else {
                c += a;
                d += b;
            }
        }
        return ((float) b) > N ? new Rational(c, d) : new Rational(a, b);
    }
}
