package com.winlator.core;

import android.app.Activity;
import android.content.Context;
import android.os.BatteryManager;

/* JADX INFO: loaded from: classes.dex */
public abstract class BatteryUtils {
    public static int getCapacity(Context context) {
        try {
            Object powerProfile = Class.forName("com.android.internal.os.PowerProfile").getConstructor(Context.class).newInstance(context);
            Double capacity = (Double) Class.forName("com.android.internal.os.PowerProfile").getMethod("getBatteryCapacity", new Class[0]).invoke(powerProfile, new Object[0]);
            if (capacity != null) {
                return capacity.intValue();
            }
            return 0;
        } catch (Exception e) {
            return 0;
        }
    }

    public static int getCurrentMicroamperes(Activity activity) {
        BatteryManager batteryManager = (BatteryManager) activity.getSystemService("batterymanager");
        int currentMicroamperes = batteryManager.getIntProperty(2);
        int currentMicroamperes2 = (currentMicroamperes == 0 || currentMicroamperes == Integer.MIN_VALUE) ? 0 : Math.abs(currentMicroamperes);
        return currentMicroamperes2 <= 1000 ? currentMicroamperes2 * 1000 : currentMicroamperes2;
    }

    public static float computePower(int currentMicroamperes, float voltage) {
        return (currentMicroamperes / 1000000.0f) * voltage;
    }
}
