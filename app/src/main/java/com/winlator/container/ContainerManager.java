package com.winlator.container;

import android.content.Context;
import android.os.Handler;
import com.winlator.R;
import com.winlator.container.FileInfo;
import com.winlator.core.Callback;
import com.winlator.core.FileUtils;
import com.winlator.core.TarCompressorUtils;
import com.winlator.core.WineInfo;
import com.winlator.xenvironment.RootFS;
import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.concurrent.Executors;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public class ContainerManager {
    private final Context context;
    private final File homeDir;
    private final ArrayList<Container> containers = new ArrayList<>();
    private int maxContainerId = 0;

    public ContainerManager(Context context) {
        this.context = context;
        File rootDir = RootFS.find(context).getRootDir();
        this.homeDir = new File(rootDir, "home");
        loadContainers();
    }

    public Context getContext() {
        return this.context;
    }

    public ArrayList<Container> getContainers() {
        return this.containers;
    }

    private void loadContainers() {
        this.containers.clear();
        this.maxContainerId = 0;
        try {
            File[] files = this.homeDir.listFiles();
            if (files != null) {
                for (File file : files) {
                    if (file.isDirectory() && file.getName().startsWith("xuser-")) {
                        Container container = new Container(Integer.parseInt(file.getName().replace("xuser-", "")));
                        container.setRootDir(new File(this.homeDir, "xuser-" + container.id));
                        JSONObject data = new JSONObject(FileUtils.readString(container.getConfigFile()));
                        container.loadData(data);
                        this.containers.add(container);
                        this.maxContainerId = Math.max(this.maxContainerId, container.id);
                    }
                }
            }
        } catch (JSONException e) {
        }
    }

    public void activateContainer(Container container) {
        container.setRootDir(new File(this.homeDir, "xuser-" + container.id));
        File file = new File(this.homeDir, "xuser");
        file.delete();
        FileUtils.symlink("xuser-" + container.id, file.getPath());
    }

    public void createContainerAsync(final JSONObject data, final Callback<Container> callback) {
        final Handler handler = new Handler();
        Executors.newSingleThreadExecutor().execute(() -> lambda_createContainerAsync_1(data, handler, callback));
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_createContainerAsync_1(JSONObject data, Handler handler, final Callback callback) {
        final Container container = createContainer(data);
        handler.post(new Runnable() { // from class: com.winlator.container.ContainerManager$$ExternalSyntheticLambda4
            @Override // java.lang.Runnable
            public final void run() {
                callback.call(container);
            }
        });
    }

    public void duplicateContainerAsync(final Container container, final Runnable callback) {
        final Handler handler = new Handler();
        Executors.newSingleThreadExecutor().execute(() -> lambda_duplicateContainerAsync_2(container, handler, callback));
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_duplicateContainerAsync_2(Container container, Handler handler, Runnable callback) {
        duplicateContainer(container);
        handler.post(callback);
    }

    public void removeContainerAsync(final Container container, final Runnable callback) {
        final Handler handler = new Handler();
        Executors.newSingleThreadExecutor().execute(() -> lambda_removeContainerAsync_3(container, handler, callback));
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_removeContainerAsync_3(Container container, Handler handler, Runnable callback) {
        removeContainer(container);
        handler.post(callback);
    }

    private Container createContainer(JSONObject data) {
        try {
            int id = this.maxContainerId + 1;
            data.put("id", id);
            File containerDir = new File(this.homeDir, "xuser-" + id);
            if (!containerDir.mkdirs()) {
                return null;
            }
            Container container = new Container(id);
            container.setRootDir(containerDir);
            container.loadData(data);
            boolean isMainWineVersion = !data.has("wineVersion") || WineInfo.isMainWineVersion(data.getString("wineVersion"));
            if (!isMainWineVersion) {
                container.setWineVersion(data.getString("wineVersion"));
            }
            if (!extractContainerPatternFile(container.getWineVersion(), containerDir)) {
                FileUtils.delete(containerDir);
                return null;
            }
            container.saveData();
            this.maxContainerId++;
            this.containers.add(container);
            return container;
        } catch (JSONException e) {
            return null;
        }
    }

    private void duplicateContainer(Container srcContainer) {
        int id = this.maxContainerId + 1;
        File dstDir = new File(this.homeDir, "xuser-" + id);
        if (dstDir.mkdirs()) {
            if (!FileUtils.copy(srcContainer.getRootDir(), dstDir, new Callback() { // from class: com.winlator.container.ContainerManager$$ExternalSyntheticLambda0
                @Override // com.winlator.core.Callback
                public final void call(Object obj) {
                    FileUtils.chmod((File) obj, 505);
                }
            })) {
                FileUtils.delete(dstDir);
                return;
            }
            Container dstContainer = new Container(id);
            dstContainer.setRootDir(dstDir);
            dstContainer.setName(srcContainer.getName() + " (" + this.context.getString(R.string.copy) + ")");
            dstContainer.setScreenSize(srcContainer.getScreenSize());
            dstContainer.setEnvVars(srcContainer.getEnvVars());
            dstContainer.setCPUList(srcContainer.getCPUList());
            dstContainer.setCPUListWoW64(srcContainer.getCPUListWoW64());
            dstContainer.setGraphicsDriver(srcContainer.getGraphicsDriver());
            dstContainer.setGraphicsDriverConfig(srcContainer.getGraphicsDriverConfig());
            dstContainer.setDXWrapper(srcContainer.getDXWrapper());
            dstContainer.setDXWrapperConfig(srcContainer.getDXWrapperConfig());
            dstContainer.setAudioDriver(srcContainer.getAudioDriver());
            dstContainer.setAudioDriverConfig(srcContainer.getAudioDriverConfig());
            dstContainer.setWinComponents(srcContainer.getWinComponents());
            dstContainer.setDrives(srcContainer.getDrives());
            dstContainer.setHUDMode(srcContainer.getHUDMode());
            dstContainer.setStartupSelection(srcContainer.getStartupSelection());
            dstContainer.setBox64Preset(srcContainer.getBox64Preset());
            dstContainer.setDesktopTheme(srcContainer.getDesktopTheme());
            dstContainer.saveData();
            this.maxContainerId++;
            this.containers.add(dstContainer);
        }
    }

    private void removeContainer(Container container) {
        if (FileUtils.delete(container.getRootDir())) {
            this.containers.remove(container);
        }
    }

    public ArrayList<Shortcut> loadShortcuts(Shortcut selectedFolder) {
        ArrayList<Shortcut> shortcuts = new ArrayList<>();
        if (selectedFolder != null) {
            File[] files = selectedFolder.file.listFiles();
            if (files != null) {
                for (File file : files) {
                    if (file.getName().endsWith(".desktop") || file.isDirectory()) {
                        shortcuts.add(new Shortcut(selectedFolder.container, file));
                    }
                }
            }
        } else {
            for (Container container : this.containers) {
                File desktopDir = new File(container.getUserDir(), "Desktop");
                File[] files2 = desktopDir.listFiles();
                if (files2 != null) {
                    for (File file2 : files2) {
                        if (file2.getName().endsWith(".desktop") || file2.isDirectory()) {
                            shortcuts.add(new Shortcut(container, file2));
                        }
                    }
                }
            }
        }
        shortcuts.sort(new Comparator() { // from class: com.winlator.container.ContainerManager$$ExternalSyntheticLambda5
            @Override // java.util.Comparator
            public final int compare(Object obj, Object obj2) {
                return ContainerManager.lambda_loadShortcuts_5((Shortcut) obj, (Shortcut) obj2);
            }
        });
        return shortcuts;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ int lambda_loadShortcuts_5(Shortcut a, Shortcut b) {
        int value = Boolean.compare(b.file.isDirectory(), a.file.isDirectory());
        return value == 0 ? a.name.compareTo(b.name) : value;
    }

    public ArrayList<FileInfo> loadFiles(Container container, FileInfo parent) {
        ArrayList<FileInfo> fileInfos = new ArrayList<>();
        if (parent != null) {
            return parent.list();
        }
        String rootPath = container.getRootDir().getPath();
        fileInfos.add(new FileInfo(container, "C:", rootPath + "/.wine/drive_c", FileInfo.Type.DRIVE));
        for (Drive drive : container.drivesIterator()) {
            fileInfos.add(new FileInfo(container, drive.letter + ":", drive.path, FileInfo.Type.DRIVE));
        }
        File userDir = container.getUserDir();
        File documentsDir = new File(userDir, "Documents");
        File favoritesDir = new File(userDir, "Favorites");
        String name = documentsDir.getName();
        String path = documentsDir.getPath();
        FileInfo.Type type = FileInfo.Type.DIRECTORY;
        fileInfos.add(new FileInfo(container, name, path, type));
        fileInfos.add(new FileInfo(container, favoritesDir.getName(), favoritesDir.getPath(), type));
        Collections.sort(fileInfos);
        return fileInfos;
    }

    public int getNextContainerId() {
        return this.maxContainerId + 1;
    }

    public Container getContainerById(int id) {
        for (Container container : this.containers) {
            if (container.id == id) {
                return container;
            }
        }
        return null;
    }

    private void copyCommonDlls(String srcName, String dstName, JSONObject commonDlls, File containerDir) throws JSONException {
        File srcDir = new File(RootFS.find(this.context).getRootDir(), "/opt/wine/lib/wine/" + srcName);
        JSONArray dlnames = commonDlls.getJSONArray(dstName);
        for (int i = 0; i < dlnames.length(); i++) {
            String dlname = dlnames.getString(i);
            File dstFile = new File(containerDir, ".wine/drive_c/windows/" + dstName + "/" + dlname);
            FileUtils.copy(new File(srcDir, dlname), dstFile);
        }
    }

    private boolean extractContainerPatternFile(String wineVersion, File containerDir) {
        if (WineInfo.isMainWineVersion(wineVersion)) {
            boolean result = TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this.context, "container_pattern.tzst", containerDir);
            if (result) {
                try {
                    JSONObject commonDlls = new JSONObject(FileUtils.readString(this.context, "common_dlls.json"));
                    copyCommonDlls("x86_64-windows", "system32", commonDlls, containerDir);
                    copyCommonDlls("i386-windows", "syswow64", commonDlls, containerDir);
                } catch (JSONException e) {
                    return false;
                }
            }
            return result;
        }
        File installedWineDir = RootFS.find(this.context).getInstalledWineDir();
        WineInfo wineInfo = WineInfo.fromIdentifier(this.context, wineVersion);
        File file = new File(installedWineDir, "container-pattern-" + wineInfo.fullVersion() + ".tzst");
        return TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, file, containerDir);
    }
}
