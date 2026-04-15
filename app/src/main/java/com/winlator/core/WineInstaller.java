package com.winlator.core;

import android.app.Activity;
import android.content.Context;
import android.net.Uri;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.TarCompressorUtils;
import com.winlator.xenvironment.RootFS;
import com.winlator.xenvironment.XEnvironment;
import com.winlator.xenvironment.components.GuestProgramLauncherComponent;
import java.io.File;
import java.util.ArrayList;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicReference;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public abstract class WineInstaller {
    public static void generateWineprefix(final WineInfo wineInfo, XEnvironment environment) {
        final Activity activity = (Activity) environment.getContext();
        RootFS rootFS = environment.getRootFS();
        final File rootDir = rootFS.getRootDir();
        final File installedWineDir = rootFS.getInstalledWineDir();
        rootFS.setWinePath(wineInfo.path);
        File containerPatternDir = new File(installedWineDir, "/preinstall/container-pattern");
        if (containerPatternDir.isDirectory()) {
            FileUtils.delete(containerPatternDir);
        }
        containerPatternDir.mkdirs();
        File linkFile = new File(rootDir, "/home/xuser");
        FileUtils.symlink(containerPatternDir.getPath(), linkFile.getPath());
        GuestProgramLauncherComponent guestProgramLauncherComponent = (GuestProgramLauncherComponent) environment.getComponent(GuestProgramLauncherComponent.class);
        guestProgramLauncherComponent.setBox64Preset("STABILITY");
        guestProgramLauncherComponent.setGuestExecutable("wine explorer /desktop=shell,1280x720 C:\\windows\\system32\\winecfg.exe");
        final PreloaderDialog preloaderDialog = new PreloaderDialog(activity);
        guestProgramLauncherComponent.setTerminationCallback(new Callback() { // from class: com.winlator.core.WineInstaller$$ExternalSyntheticLambda0
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                WineInstaller.lambda_generateWineprefix_1(activity, installedWineDir, preloaderDialog, rootDir, wineInfo, (Integer) obj);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_generateWineprefix_1(final Activity activity, final File installedWineDir, final PreloaderDialog preloaderDialog, final File rootDir, final WineInfo wineInfo, final Integer status) {
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.core.WineInstaller$$ExternalSyntheticLambda4
            @Override // java.lang.Runnable
            public final void run() {
                WineInstaller.lambda_generateWineprefix_0(status, activity, installedWineDir, preloaderDialog, rootDir, wineInfo);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_generateWineprefix_0(Integer status, Activity activity, File installedWineDir, PreloaderDialog preloaderDialog, File rootDir, WineInfo wineInfo) {
        if (status.intValue() > 0) {
            AppUtils.showToast(activity, R.string.unable_to_install_wine);
            FileUtils.delete(new File(installedWineDir, "/preinstall"));
            AppUtils.restartApplication(activity);
            return;
        }
        preloaderDialog.showOnUiThread(R.string.finishing_installation);
        FileUtils.writeString(new File(rootDir, "/home/xuser/.wine/.update-timestamp"), "disable\n");
        File userDir = new File(rootDir, "/home/xuser/.wine/drive_c/users/xuser");
        File[] userFiles = userDir.listFiles();
        if (userFiles != null) {
            for (File userFile : userFiles) {
                if (FileUtils.isSymlink(userFile)) {
                    String path = userFile.getPath();
                    userFile.delete();
                    new File(path).mkdirs();
                }
            }
        }
        File containerPatternFile = new File(installedWineDir, "/preinstall/container-pattern-" + wineInfo.fullVersion() + ".tzst");
        TarCompressorUtils.compress(TarCompressorUtils.Type.ZSTD, new File(rootDir, "/home/xuser/.wine"), containerPatternFile, 9);
        if (!containerPatternFile.renameTo(new File(installedWineDir, containerPatternFile.getName())) || !new File(wineInfo.path).renameTo(new File(installedWineDir, wineInfo.identifier()))) {
            containerPatternFile.delete();
        }
        FileUtils.delete(new File(installedWineDir, "/preinstall"));
        preloaderDialog.closeOnUiThread();
        AppUtils.RestartApplicationOptions options = new AppUtils.RestartApplicationOptions();
        options.selectedMenuItemId = R.id.menu_item_settings;
        AppUtils.restartApplication(activity, options);
    }

    public static void extractWineFileForInstallAsync(final Context context, final Uri uri, final Callback<File> callback) {
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.core.WineInstaller$$ExternalSyntheticLambda3
            @Override // java.lang.Runnable
            public final void run() {
                WineInstaller.lambda_extractWineFileForInstallAsync_2(context, uri, callback);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_extractWineFileForInstallAsync_2(Context context, Uri uri, Callback callback) {
        File destination = new File(RootFS.find(context).getInstalledWineDir(), "/preinstall/wine");
        FileUtils.delete(destination);
        destination.mkdirs();
        boolean success = TarCompressorUtils.extract(TarCompressorUtils.Type.XZ, context, uri, destination);
        if (!success) {
            FileUtils.delete(destination);
        }
        if (callback != null) {
            callback.call(success ? destination : null);
        }
    }

    public static void findWineVersionAsync(Context context, File wineDir, final Callback<WineInfo> callback) {
        File wineDir2;
        if (wineDir == null || !wineDir.isDirectory()) {
            callback.call(null);
            return;
        }
        File[] files = wineDir.listFiles();
        if (files == null || files.length == 0) {
            callback.call(null);
            return;
        }
        boolean is64Bit = true;
        if (files.length != 1) {
            wineDir2 = wineDir;
        } else {
            if (!files[0].isDirectory()) {
                callback.call(null);
                return;
            }
            wineDir2 = files[0];
            files = wineDir2.listFiles();
            if (files == null || files.length == 0) {
                callback.call(null);
                return;
            }
        }
        File binDir = null;
        int length = files.length;
        int i = 0;
        while (true) {
            if (i >= length) {
                break;
            }
            File file = files[i];
            if (!file.isDirectory() || !file.getName().equals("bin")) {
                i++;
            } else {
                binDir = file;
                break;
            }
        }
        if (binDir == null) {
            callback.call(null);
            return;
        }
        File wineBin = new File(binDir, "wine");
        File wineBin64 = new File(binDir, "wine64");
        if (!wineBin.isFile()) {
            callback.call(null);
            return;
        }
        if ((!wineBin64.isFile() || !ElfHelper.is64Bit(wineBin64)) && !ElfHelper.is64Bit(wineBin)) {
            is64Bit = false;
        }
        if (!is64Bit) {
            callback.call(null);
            return;
        }
        RootFS rootFS = RootFS.find(context);
        File rootDir = rootFS.getRootDir();
        String wineBinPath = wineBin64.isFile() ? wineBin64.getPath() : wineBin.getPath();
        final String winePath = wineDir2.getPath();
        final AtomicReference<WineInfo> wineInfoRef = new AtomicReference<>();
        final Callback<String> debugCallback = new Callback() { // from class: com.winlator.core.WineInstaller$$ExternalSyntheticLambda2
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                WineInstaller.lambda_findWineVersionAsync_3(wineInfoRef, winePath, (String) obj);
            }
        };
        ProcessHelper.addDebugCallback(debugCallback);
        File linkFile = new File(rootDir, "/home/xuser");
        linkFile.delete();
        FileUtils.symlink(wineDir2, linkFile);
        XEnvironment environment = new XEnvironment(context, rootFS);
        GuestProgramLauncherComponent guestProgramLauncherComponent = new GuestProgramLauncherComponent();
        guestProgramLauncherComponent.setGuestExecutable(wineBinPath + " --version");
        guestProgramLauncherComponent.setTerminationCallback(new Callback() { // from class: com.winlator.core.WineInstaller$$ExternalSyntheticLambda1
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                WineInstaller.lambda_findWineVersionAsync_4(callback, wineInfoRef, debugCallback, (Integer) obj);
            }
        });
        environment.addComponent(guestProgramLauncherComponent);
        environment.startEnvironmentComponents();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_findWineVersionAsync_3(AtomicReference wineInfoRef, String winePath, String line) {
        Pattern pattern = Pattern.compile("^wine\\-([0-9\\.]+)\\-?([0-9\\.]+)?", 2);
        Matcher matcher = pattern.matcher(line);
        if (matcher.find()) {
            String version = matcher.group(1);
            String subversion = matcher.groupCount() >= 2 ? matcher.group(2) : null;
            wineInfoRef.set(new WineInfo(version, subversion, winePath));
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_findWineVersionAsync_4(Callback callback, AtomicReference wineInfoRef, Callback debugCallback, Integer status) {
        callback.call((WineInfo) wineInfoRef.get());
        ProcessHelper.removeDebugCallback(debugCallback);
    }

    public static ArrayList<WineInfo> getInstalledWineInfos(Context context) {
        ArrayList<WineInfo> wineInfos = new ArrayList<>();
        wineInfos.add(WineInfo.MAIN_WINE_INFO);
        File installedWineDir = RootFS.find(context).getInstalledWineDir();
        File[] files = installedWineDir.listFiles();
        if (files != null) {
            for (File file : files) {
                String name = file.getName();
                if (name.startsWith("wine")) {
                    wineInfos.add(WineInfo.fromIdentifier(context, name));
                }
            }
        }
        return wineInfos;
    }
}
