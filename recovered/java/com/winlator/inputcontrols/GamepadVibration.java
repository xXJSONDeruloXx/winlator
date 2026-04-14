package com.winlator.inputcontrols;

import android.content.Context;
import android.os.Build;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.os.VibratorManager;
import android.view.InputDevice;
import com.winlator.math.Mathf;

/* JADX INFO: loaded from: classes.dex */
public class GamepadVibration {
    private final short[] currentSpeed;
    private final boolean[] vibrating;
    private final Vibrator[] vibrators;

    protected GamepadVibration(Context context) {
        Vibrator[] vibratorArr = new Vibrator[2];
        this.vibrators = vibratorArr;
        this.currentSpeed = new short[2];
        this.vibrating = new boolean[2];
        VibratorManager manager = null;
        Vibrator vibrator = null;
        if (Build.VERSION.SDK_INT >= 31) {
            manager = (VibratorManager) context.getSystemService("vibrator_manager");
        } else {
            vibrator = (Vibrator) context.getSystemService("vibrator");
        }
        vibratorArr[0] = getVibratorAt(0, manager, vibrator);
        vibratorArr[1] = getVibratorAt(1, manager, vibrator);
    }

    protected GamepadVibration(String id) {
        this.vibrators = new Vibrator[2];
        this.currentSpeed = new short[2];
        this.vibrating = new boolean[2];
        VibratorManager manager = null;
        Vibrator vibrator = null;
        int[] deviceIds = InputDevice.getDeviceIds();
        int length = deviceIds.length;
        int i = 0;
        while (true) {
            if (i >= length) {
                break;
            }
            int deviceId = deviceIds[i];
            InputDevice device = InputDevice.getDevice(deviceId);
            if (device == null || !device.getDescriptor().equals(id)) {
                i++;
            } else if (Build.VERSION.SDK_INT >= 31) {
                manager = device.getVibratorManager();
            } else {
                vibrator = device.getVibrator();
            }
        }
        this.vibrators[0] = getVibratorAt(0, manager, vibrator);
        this.vibrators[1] = getVibratorAt(1, manager, vibrator);
    }

    private static Vibrator getVibratorAt(int index, VibratorManager manager, Vibrator defaultVibrator) {
        Vibrator result;
        if (manager != null && Build.VERSION.SDK_INT >= 31) {
            int[] ids = manager.getVibratorIds();
            result = (ids.length < 2 || index >= ids.length) ? manager.getDefaultVibrator() : manager.getVibrator(index);
        } else {
            result = defaultVibrator;
        }
        if (result == null || !result.hasVibrator()) {
            return null;
        }
        return result;
    }

    private void vibrateAt(int index, short newSpeed) {
        if (newSpeed == 0) {
            if (this.vibrating[index]) {
                this.vibrators[index].cancel();
            }
            this.vibrating[index] = false;
        } else if (newSpeed != this.currentSpeed[index]) {
            long[] timings = {0, 60000};
            int[] amplitudes = {0, newSpeed};
            this.vibrators[index].vibrate(VibrationEffect.createWaveform(timings, amplitudes, -1));
            this.vibrating[index] = true;
        }
        this.currentSpeed[index] = newSpeed;
    }

    private short parseAmplitude(int motorSpeed) {
        return (short) Mathf.roundTo((motorSpeed / 65535.0f) * 255.0f, 15.0f);
    }

    public void vibrate(int leftMotorSpeed, int rightMotorSpeed) {
        Vibrator[] vibratorArr = this.vibrators;
        if (vibratorArr[0] != null && vibratorArr[1] != null) {
            short speedX = parseAmplitude(leftMotorSpeed);
            short speedY = parseAmplitude(rightMotorSpeed);
            Vibrator[] vibratorArr2 = this.vibrators;
            if (vibratorArr2[0] == vibratorArr2[1]) {
                short avgSpeed = (short) ((speedX + speedY) * 0.5f);
                vibrateAt(0, avgSpeed);
            } else {
                vibrateAt(0, speedX);
                vibrateAt(1, speedY);
            }
        }
    }
}
