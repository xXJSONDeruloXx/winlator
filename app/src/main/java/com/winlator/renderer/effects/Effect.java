package com.winlator.renderer.effects;

import com.winlator.renderer.material.ScreenMaterial;

/* JADX INFO: loaded from: classes.dex */
public abstract class Effect {
    private ScreenMaterial material;

    protected ScreenMaterial createMaterial() {
        return null;
    }

    public ScreenMaterial getMaterial() {
        if (this.material == null) {
            this.material = createMaterial();
        }
        return this.material;
    }
}
