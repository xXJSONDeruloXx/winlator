package com.winlator.xenvironment;

import android.content.Context;
import com.winlator.core.FileUtils;
import java.io.File;
import java.io.IOException;

/* JADX INFO: loaded from: classes.dex */
public class RootFS {
    private final File rootDir;
    private String winePath = "/opt/wine";

    private RootFS(File rootDir) {
        this.rootDir = rootDir;
    }

    public static RootFS find(Context context) {
        File legacyDir = new File(context.getFilesDir(), "imagefs");
        File rootDir = new File(context.getFilesDir(), "rootfs");
        if (legacyDir.isDirectory()) {
            legacyDir.renameTo(rootDir);
        }
        return new RootFS(rootDir);
    }

    public File getRootDir() {
        return this.rootDir;
    }

    public boolean isValid() {
        return this.rootDir.isDirectory() && getRFSVersionFile().exists();
    }

    public int getVersion() {
        File rfsVersionFile = getRFSVersionFile();
        if (rfsVersionFile.exists()) {
            return Integer.parseInt(FileUtils.readLines(rfsVersionFile).get(0));
        }
        return 0;
    }

    public void createRFSVersionFile(int version) {
        getImageInfoDir().mkdirs();
        File file = getRFSVersionFile();
        try {
            file.createNewFile();
            FileUtils.writeString(file, String.valueOf(version));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public String getWinePath() {
        return this.winePath;
    }

    public void setWinePath(String winePath) {
        this.winePath = FileUtils.toRelativePath(this.rootDir.getPath(), winePath);
    }

    private File getImageInfoDir() {
        return new File(this.rootDir, ".winlator");
    }

    public File getRFSVersionFile() {
        return new File(getImageInfoDir(), ".rfs_version");
    }

    public File getInstalledWineDir() {
        return new File(this.rootDir, "/opt/installed-wine");
    }

    public File getTmpDir() {
        return new File(this.rootDir, "/tmp");
    }

    public File getLibDir() {
        return new File(this.rootDir, "/usr/lib");
    }

    public String toString() {
        return this.rootDir.getPath();
    }

    public static String getDosUserCachePath() {
        return "Z:" + "/home/xuser/.cache".replace("/", "\\");
    }

    public static String getDosUserConfigPath() {
        return "Z:" + "/home/xuser/.config".replace("/", "\\");
    }
}
