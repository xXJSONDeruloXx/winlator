package com.winlator.winhandler;

import com.winlator.core.KeyValueSet;

/* JADX INFO: loaded from: classes.dex */
public class GamepadPlayerConfig {
    public final byte mode;
    public final String name;
    public final boolean vibration;

    public GamepadPlayerConfig(String values) {
        KeyValueSet config = new KeyValueSet(values);
        this.mode = (byte) config.getInt("mode");
        this.name = config.get("name");
        this.vibration = config.getBoolean("vibration");
    }
}
