package com.winlator.xenvironment;

import android.content.Context;
import com.winlator.core.FileUtils;
import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public class XEnvironment implements Iterable<EnvironmentComponent> {
    private final ArrayList<EnvironmentComponent> components = new ArrayList<>();
    private final Context context;
    private final RootFS rootFS;

    public XEnvironment(Context context, RootFS rootFS) {
        this.context = context;
        this.rootFS = rootFS;
    }

    public Context getContext() {
        return this.context;
    }

    public RootFS getRootFS() {
        return this.rootFS;
    }

    public void addComponent(EnvironmentComponent environmentComponent) {
        environmentComponent.environment = this;
        this.components.add(environmentComponent);
    }

    public <T extends EnvironmentComponent> T getComponent(Class<T> componentClass) {
        Iterator<EnvironmentComponent> it = this.components.iterator();
        while (it.hasNext()) {
            T t = (T) it.next();
            if (t.getClass() == componentClass) {
                return t;
            }
        }
        return null;
    }

    @Override // java.lang.Iterable
    public Iterator<EnvironmentComponent> iterator() {
        return this.components.iterator();
    }

    public File getTmpDir() {
        File tmpDir = new File(this.context.getFilesDir(), "tmp");
        if (!tmpDir.isDirectory()) {
            tmpDir.mkdirs();
            FileUtils.chmod(tmpDir, 505);
        }
        return tmpDir;
    }

    public void startEnvironmentComponents() {
        FileUtils.clear(getTmpDir());
        for (EnvironmentComponent environmentComponent : this) {
            environmentComponent.start();
        }
    }

    public void stopEnvironmentComponents() {
        for (EnvironmentComponent environmentComponent : this) {
            environmentComponent.stop();
        }
    }

    public void onPause() {
        for (EnvironmentComponent environmentComponent : this) {
            environmentComponent.onPause();
        }
    }

    public void onResume() {
        for (EnvironmentComponent environmentComponent : this) {
            environmentComponent.onResume();
        }
    }
}
