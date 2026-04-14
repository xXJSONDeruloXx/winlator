package com.winlator.renderer;

/* JADX INFO: compiled from: R8$$SyntheticClass */
/* JADX INFO: loaded from: classes.dex */
public final /* synthetic */ class GLRenderer$$ExternalSyntheticLambda0 implements Runnable {
    public final /* synthetic */ GLRenderer f$0;

    public /* synthetic */ GLRenderer$$ExternalSyntheticLambda0(GLRenderer gLRenderer) {
        this.f$0 = gLRenderer;
    }

    @Override // java.lang.Runnable
    public final void run() {
        this.f$0.updateScene();
    }
}
