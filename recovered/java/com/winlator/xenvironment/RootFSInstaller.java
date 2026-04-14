package com.winlator.xenvironment;

import android.content.Context;
import com.winlator.MainActivity;
import com.winlator.R;
import com.winlator.SettingsFragment;
import com.winlator.container.Container;
import com.winlator.container.ContainerManager;
import com.winlator.core.AppUtils;
import com.winlator.core.DownloadProgressDialog;
import com.winlator.core.FileUtils;
import com.winlator.core.TarCompressorUtils;
import com.winlator.core.WineInfo;
import java.io.File;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicLong;

/* JADX INFO: loaded from: classes.dex */
public abstract class RootFSInstaller {
    private static void resetContainerRFSVersions(Context context) {
        ContainerManager manager = new ContainerManager(context);
        for (Container container : manager.getContainers()) {
            String rfsVersion = container.getExtra("rfsVersion");
            String wineVersion = container.getWineVersion();
            if (!rfsVersion.isEmpty() && WineInfo.isMainWineVersion(wineVersion) && Short.parseShort(rfsVersion) <= 16) {
                container.putExtra("wineprefixNeedsUpdate", "t");
            }
            container.putExtra("rfsVersion", null);
            container.saveData();
        }
    }

    public static void install(final MainActivity activity) {
        AppUtils.keepScreenOn(activity);
        final RootFS rootFS = RootFS.find(activity);
        final File rootDir = rootFS.getRootDir();
        SettingsFragment.resetBox64Version(activity);
        final DownloadProgressDialog dialog = new DownloadProgressDialog(activity);
        dialog.show(R.string.installing_system_files);
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.xenvironment.RootFSInstaller$$ExternalSyntheticLambda2
            @Override // java.lang.Runnable
            public final void run() {
                RootFSInstaller.lambda$install$2(rootDir, activity, dialog, rootFS);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$install$2(File rootDir, final MainActivity activity, final DownloadProgressDialog dialog, RootFS rootFS) {
        clearRootDir(rootDir);
        TarCompressorUtils.Type type = TarCompressorUtils.Type.ZSTD;
        final long contentLength = TarCompressorUtils.getContentLength(type, activity, "rootfs.tzst", rootDir);
        final AtomicLong totalSizeRef = new AtomicLong();
        boolean success = TarCompressorUtils.extract(type, activity, "rootfs.tzst", rootDir, new TarCompressorUtils.OnExtractFileListener() { // from class: com.winlator.xenvironment.RootFSInstaller$$ExternalSyntheticLambda0
            @Override // com.winlator.core.TarCompressorUtils.OnExtractFileListener
            public final File onExtractFile(File file, long j) {
                return RootFSInstaller.lambda$install$1(totalSizeRef, contentLength, activity, dialog, file, j);
            }
        });
        if (success) {
            rootFS.createRFSVersionFile(19);
            resetContainerRFSVersions(activity);
        } else {
            AppUtils.showToast(activity, R.string.unable_to_install_system_files);
        }
        dialog.closeOnUiThread();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ File lambda$install$1(AtomicLong totalSizeRef, long contentLength, MainActivity activity, final DownloadProgressDialog dialog, File file, long size) {
        if (size > 0) {
            long totalSize = totalSizeRef.addAndGet(size);
            final int progress = (int) ((totalSize / contentLength) * 100.0f);
            activity.runOnUiThread(new Runnable() { // from class: com.winlator.xenvironment.RootFSInstaller$$ExternalSyntheticLambda1
                @Override // java.lang.Runnable
                public final void run() {
                    dialog.setProgress(progress);
                }
            });
        }
        return file;
    }

    public static void installIfNeeded(MainActivity activity) {
        RootFS rootFS = RootFS.find(activity);
        if (!rootFS.isValid() || rootFS.getVersion() < 19) {
            install(activity);
        }
    }

    private static void clearOptDir(File optDir) {
        File[] files = optDir.listFiles();
        if (files != null) {
            for (File file : files) {
                if (!file.getName().equals("installed-wine")) {
                    FileUtils.delete(file);
                }
            }
        }
    }

    /* JADX WARN: Removed duplicated region for block: B:17:0x0036  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    private static void clearRootDir(java.io.File r7) {
        /*
            boolean r0 = r7.isDirectory()
            if (r0 == 0) goto L3d
            java.io.File[] r0 = r7.listFiles()
            if (r0 == 0) goto L3c
            int r1 = r0.length
            r2 = 0
        Le:
            if (r2 >= r1) goto L3c
            r3 = r0[r2]
            boolean r4 = r3.isDirectory()
            if (r4 == 0) goto L36
            java.lang.String r4 = r3.getName()
            java.lang.String r5 = "home"
            boolean r5 = r4.equals(r5)
            java.lang.String r6 = "opt"
            if (r5 != 0) goto L2c
            boolean r5 = r4.equals(r6)
            if (r5 == 0) goto L36
        L2c:
            boolean r5 = r4.equals(r6)
            if (r5 == 0) goto L39
            clearOptDir(r3)
            goto L39
        L36:
            com.winlator.core.FileUtils.delete(r3)
        L39:
            int r2 = r2 + 1
            goto Le
        L3c:
            goto L40
        L3d:
            r7.mkdirs()
        L40:
            return
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.xenvironment.RootFSInstaller.clearRootDir(java.io.File):void");
    }
}
