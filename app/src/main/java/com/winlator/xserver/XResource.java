package com.winlator.xserver;

/* JADX INFO: loaded from: classes.dex */
public abstract class XResource {
    public final int id;

    public XResource(int id) {
        this.id = id;
    }

    public int hashCode() {
        return this.id;
    }
}
