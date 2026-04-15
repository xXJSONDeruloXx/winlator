package com.winlator.core;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.PopupMenu;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import com.winlator.MainActivity;
import com.winlator.R;
import com.winlator.contentdialog.ContentDialog;
import com.winlator.core.TarCompressorUtils;
import com.winlator.xenvironment.RootFS;
import java.io.File;
import java.io.FilenameFilter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Locale;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public abstract class GeneralComponents {

    public enum InstallMode {
        DOWNLOAD,
        FILE,
        BOTH
    }

    public enum Type {
        BOX64,
        TURNIP,
        DXVK,
        VKD3D,
        WINED3D,
        SOUNDFONT,
        ADRENOTOOLS_DRIVER;

        /* JADX INFO: Access modifiers changed from: private */
        public String lowerName() {
            return name().toLowerCase(Locale.ENGLISH);
        }

        /* JADX INFO: Access modifiers changed from: private */
        public String title() {
            switch (AnonymousClass1.$SwitchMap$com$winlator$core$GeneralComponents$Type[ordinal()]) {
                case 1:
                    return "Box64";
                case 2:
                    return "Turnip";
                case 3:
                    return "DXVK";
                case 4:
                    return "VKD3D";
                case 5:
                    return "WineD3D";
                case 6:
                    return "SoundFont";
                case 7:
                    return "Adrenotools Driver";
                default:
                    return "";
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        public String assetFolder() {
            switch (AnonymousClass1.$SwitchMap$com$winlator$core$GeneralComponents$Type[ordinal()]) {
                case 1:
                    return "box64";
                case 2:
                    return "graphics_driver";
                case 3:
                case 4:
                case 5:
                    return "dxwrapper";
                case 6:
                    return "soundfont";
                default:
                    return "";
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        public File getSource(Context context, String identifier) {
            File componentDir = GeneralComponents.getComponentDir(this, context);
            switch (AnonymousClass1.$SwitchMap$com$winlator$core$GeneralComponents$Type[ordinal()]) {
                case 6:
                    return new File(componentDir, identifier + ".sf2");
                case 7:
                    return new File(componentDir, identifier);
                default:
                    return new File(componentDir, lowerName() + "-" + identifier + ".tzst");
            }
        }

        public File getDestination(Context context) {
            File rootDir = RootFS.find(context).getRootDir();
            switch (AnonymousClass1.$SwitchMap$com$winlator$core$GeneralComponents$Type[ordinal()]) {
                case 3:
                case 4:
                case 5:
                    return new File(rootDir, "/home/xuser/.wine/drive_c/windows");
                case 6:
                    File destination = new File(context.getCacheDir(), "soundfont");
                    if (!destination.isDirectory()) {
                        destination.mkdirs();
                    }
                    return destination;
                default:
                    return rootDir;
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        public InstallMode getInstallMode() {
            if (this == SOUNDFONT || this == ADRENOTOOLS_DRIVER) {
                InstallMode installMode = InstallMode.FILE;
                return installMode;
            }
            if (this == WINED3D || this == DXVK || this == VKD3D) {
                InstallMode installMode2 = InstallMode.BOTH;
                return installMode2;
            }
            InstallMode installMode3 = InstallMode.DOWNLOAD;
            return installMode3;
        }

        /* JADX INFO: Access modifiers changed from: private */
        public boolean isVersioned() {
            return this == BOX64 || this == TURNIP || this == DXVK || this == VKD3D || this == WINED3D;
        }
    }

    public static ArrayList<String> getBuiltinComponentNames(Type type) {
        String[] items = new String[0];
        switch (AnonymousClass1.$SwitchMap$com$winlator$core$GeneralComponents$Type[type.ordinal()]) {
            case 1:
                items = new String[]{"0.4.0"};
                break;
            case 2:
                items = new String[]{"26.1.0"};
                break;
            case 3:
                items = new String[]{"1.10.3", "2.4.1"};
                break;
            case 4:
                items = new String[]{"2.14.1"};
                break;
            case 5:
                items = new String[]{"10.10"};
                break;
            case 6:
                items = new String[]{"SONiVOX-EAS-GM-Wavetable"};
                break;
            case 7:
                items = new String[]{"System"};
                break;
        }
        return new ArrayList<>(Arrays.asList(items));
    }

    public static File getComponentDir(Type type, Context context) {
        File file = new File(context.getFilesDir(), "/installed_components/" + type.lowerName());
        if (!file.isDirectory()) {
            file.mkdirs();
        }
        return file;
    }

    public static ArrayList<String> getInstalledComponentNames(Type type, Context context) {
        String[] names;
        File componentDir = getComponentDir(type, context);
        ArrayList<String> result = new ArrayList<>();
        if (componentDir.isDirectory() && (names = componentDir.list()) != null) {
            for (String name : names) {
                result.add(parseDisplayText(type, name));
            }
        }
        return result;
    }

    public static boolean isBuiltinComponent(Type type, String identifier) {
        for (String builtinComponentName : getBuiltinComponentNames(type)) {
            if (builtinComponentName.equalsIgnoreCase(identifier)) {
                return true;
            }
        }
        return false;
    }

    public static String getDefinitivePath(Type type, Context context, String identifier) {
        if (identifier.isEmpty()) {
            return null;
        }
        if (type == Type.SOUNDFONT && isBuiltinComponent(type, identifier)) {
            File destination = type.getDestination(context);
            FileUtils.clear(destination);
            String filename = identifier + ".sf2";
            File destination2 = new File(destination, filename);
            FileUtils.copy(context, type.assetFolder() + "/" + filename, destination2);
            return destination2.getPath();
        }
        if (type == Type.ADRENOTOOLS_DRIVER) {
            if (isBuiltinComponent(type, identifier)) {
                return null;
            }
            File source = type.getSource(context, identifier);
            File[] manifestFiles = source.listFiles(new FilenameFilter() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda8
                @Override // java.io.FilenameFilter
                public final boolean accept(File file, String str) {
                    return GeneralComponents.lambda_getDefinitivePath_0(file, str);
                }
            });
            if (manifestFiles != null) {
                try {
                    JSONObject manifestJSONObject = new JSONObject(FileUtils.readString(manifestFiles[0]));
                    String libraryName = manifestJSONObject.optString("libraryName", "");
                    File libraryFile = new File(source, libraryName);
                    if (libraryFile.isFile()) {
                        return libraryFile.getPath();
                    }
                    return null;
                } catch (JSONException e) {
                    return null;
                }
            }
        }
        return type.getSource(context, identifier).getPath();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ boolean lambda_getDefinitivePath_0(File file, String name) {
        return name.endsWith(".json");
    }

    public static void extractFile(Type type, Context context, String identifier, String defaultVersion) {
        extractFile(type, context, identifier, defaultVersion, null);
    }

    public static void extractFile(Type type, Context context, String identifier, String defaultVersion, TarCompressorUtils.OnExtractFileListener onExtractFileListener) {
        File destination = type.getDestination(context);
        if (isBuiltinComponent(type, identifier)) {
            String sourcePath = type.assetFolder() + "/" + type.lowerName() + "-" + identifier + ".tzst";
            TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, context, sourcePath, destination, onExtractFileListener);
            return;
        }
        File componentDir = getComponentDir(type, context);
        File source = new File(componentDir, type.lowerName() + "-" + identifier + ".tzst");
        TarCompressorUtils.Type type2 = TarCompressorUtils.Type.ZSTD;
        boolean success = TarCompressorUtils.extract(type2, source, destination, onExtractFileListener);
        if (!success) {
            String sourcePath2 = type.assetFolder() + "/" + type.lowerName() + "-" + defaultVersion + ".tzst";
            TarCompressorUtils.extract(type2, context, sourcePath2, destination, onExtractFileListener);
        }
    }

    private static String parseDisplayText(Type type, String filename) {
        return filename.replace(type.lowerName() + "-", "").replace(".tzst", "").replace(".sf2", "");
    }

    private static void downloadComponentFile(final Type type, final String filename, final Spinner spinner, final String defaultItem) {
        final Activity activity = (Activity) spinner.getContext();
        File destination = new File(getComponentDir(type, activity), filename);
        if (destination.isFile()) {
            destination.delete();
        }
        HttpUtils.download(activity, String.format("https://raw.githubusercontent.com/brunodev85/winlator/main/installable_components/%s", type.lowerName() + "/" + filename), destination, new Callback() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda4
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                GeneralComponents.lambda_downloadComponentFile_1(type, spinner, filename, defaultItem, activity, (Boolean) obj);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_downloadComponentFile_1(Type type, Spinner spinner, String filename, String defaultItem, Activity activity, Boolean success) {
        if (success.booleanValue()) {
            loadSpinner(type, spinner, parseDisplayText(type, filename), defaultItem);
        } else {
            AppUtils.showToast(activity, R.string.a_network_error_occurred);
        }
    }

    private static void installFromPackagedFile(Context context, TarCompressorUtils.Type compressedType, Type type, File originFile, String identifier, JSONArray filesJSONArray) throws JSONException {
        File componentDir = getComponentDir(type, context);
        File tempDir = new File(componentDir, type.lowerName() + "-" + identifier);
        if (tempDir.isDirectory()) {
            FileUtils.delete(tempDir);
        }
        tempDir.mkdirs();
        for (int i = 0; i < filesJSONArray.length(); i++) {
            JSONObject fileJSONObject = filesJSONArray.getJSONObject(i);
            String target = fileJSONObject.getString("target");
            File file = null;
            if (target.contains("system32")) {
                file = new File(tempDir, "system32/" + FileUtils.getName(target));
            } else if (target.contains("syswow64")) {
                file = new File(tempDir, "syswow64/" + FileUtils.getName(target));
            }
            if (file != null) {
                File parent = file.getParentFile();
                parent.mkdirs();
                final String source = fileJSONObject.getString("source");
                TarCompressorUtils.extract(compressedType, originFile, tempDir, new TarCompressorUtils.OnExtractFileListener() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda7
                    @Override // com.winlator.core.TarCompressorUtils.OnExtractFileListener
                    public final File onExtractFile(File file2, long j) {
                        return GeneralComponents.lambda_installFromPackagedFile_2(source, file2, j);
                    }
                });
            }
        }
        String filename = type.lowerName() + "-" + identifier + ".tzst";
        File destination = new File(componentDir, filename);
        TarCompressorUtils.compress(TarCompressorUtils.Type.ZSTD, new File(tempDir, "/."), destination, 9);
        FileUtils.delete(tempDir);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ File lambda_installFromPackagedFile_2(String source, File destination, long size) {
        if (destination.getPath().endsWith(source)) {
            return destination;
        }
        return null;
    }

    private static void openFileForInstall(final MainActivity activity, final Type type, final Spinner spinner, final String defaultItem) {
        activity.setOpenFileCallback(new Callback() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda5
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                GeneralComponents.lambda_openFileForInstall_3(type, activity, spinner, defaultItem, (Uri) obj);
            }
        });
        Intent intent = new Intent("android.intent.action.OPEN_DOCUMENT");
        intent.addCategory("android.intent.category.OPENABLE");
        intent.setType("*/*");
        activity.startActivityForResult(intent, 2);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_openFileForInstall_3(Type type, MainActivity activity, Spinner spinner, String defaultItem, Uri uri) {
        String path = FileUtils.getFilePathFromUri(uri);
        if (path == null) {
        }
        try {
            File source = new File(path);
            switch (AnonymousClass1.$SwitchMap$com$winlator$core$GeneralComponents$Type[type.ordinal()]) {
                case 6:
                    String filename = FileUtils.getName(path);
                    File destination = new File(getComponentDir(type, activity), filename);
                    if (destination.isFile()) {
                        FileUtils.delete(destination);
                    }
                    if (FileUtils.copy(source, destination)) {
                        loadSpinner(type, spinner, parseDisplayText(type, filename), defaultItem);
                    }
                    break;
                case 7:
                    byte[] manifestData = ZipUtils.read(source, "*.json");
                    if (manifestData != null) {
                        JSONObject manifestJSONObject = new JSONObject(new String(manifestData));
                        String filename2 = manifestJSONObject.optString("name", manifestJSONObject.optString("libraryName", ""));
                        File destination2 = new File(getComponentDir(type, activity), filename2);
                        if (destination2.isDirectory()) {
                            FileUtils.delete(destination2);
                        }
                        destination2.mkdirs();
                        if (ZipUtils.extract(source, destination2)) {
                            loadSpinner(type, spinner, filename2, defaultItem);
                        }
                    }
                    break;
                default:
                    TarCompressorUtils.Type compressedType = TarCompressorUtils.Type.ZSTD;
                    byte[] manifestData2 = TarCompressorUtils.read(compressedType, source, "*.json");
                    if (manifestData2 == null) {
                        TarCompressorUtils.Type type2 = TarCompressorUtils.Type.XZ;
                        compressedType = type2;
                        manifestData2 = TarCompressorUtils.read(type2, source, "*.json");
                    }
                    TarCompressorUtils.Type compressedType2 = compressedType;
                    byte[] manifestData3 = manifestData2;
                    if (manifestData3 != null) {
                        JSONObject manifestJSONObject2 = new JSONObject(new String(manifestData3));
                        String contentType = manifestJSONObject2.optString("type", "").toUpperCase(Locale.ENGLISH);
                        String identifier = StringUtils.parseIdentifier(manifestJSONObject2.optString("versionName", ""));
                        JSONArray filesJSONArray = manifestJSONObject2.optJSONArray("files");
                        if (contentType.equals(type.name()) && !identifier.isEmpty() && filesJSONArray != null) {
                            installFromPackagedFile(activity, compressedType2, type, source, identifier, filesJSONArray);
                            loadSpinner(type, spinner, identifier, defaultItem);
                            break;
                        }
                    }
                    break;
            }
        } catch (JSONException e) {
        }
    }

    private static void showDownloadableListDialog(final Type type, final Spinner spinner, final String defaultItem) {
        final Activity activity = (Activity) spinner.getContext();
        final PreloaderDialog preloaderDialog = new PreloaderDialog(activity);
        preloaderDialog.show(R.string.loading);
        HttpUtils.download(String.format("https://raw.githubusercontent.com/brunodev85/winlator/main/installable_components/%s", type.lowerName() + "/index.txt"), new Callback() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda3
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                GeneralComponents.lambda_showDownloadableListDialog_6(activity, preloaderDialog, type, spinner, defaultItem, (String) obj);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_showDownloadableListDialog_6(final Activity activity, final PreloaderDialog preloaderDialog, final Type type, final Spinner spinner, final String defaultItem, final String content) {
        activity.runOnUiThread(new Runnable() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda9
            @Override // java.lang.Runnable
            public final void run() {
                GeneralComponents.lambda_showDownloadableListDialog_5(preloaderDialog, content, activity, type, spinner, defaultItem);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_showDownloadableListDialog_5(PreloaderDialog preloaderDialog, String content, Activity activity, final Type type, final Spinner spinner, final String defaultItem) {
        preloaderDialog.close();
        if (content != null) {
            if (content.isEmpty()) {
                AppUtils.showToast(activity, R.string.there_are_no_items_to_download);
                return;
            }
            final String[] filenames = content.split("\n");
            String[] items = (String[]) filenames.clone();
            for (int i = 0; i < items.length; i++) {
                items[i] = type.title() + " " + parseDisplayText(type, items[i]);
            }
            ContentDialog.showSelectionList((Context) activity, R.string.install_component, items, false, (Callback<ArrayList<Integer>>) new Callback() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda6
                @Override // com.winlator.core.Callback
                public final void call(Object obj) {
                    GeneralComponents.lambda_showDownloadableListDialog_4(type, filenames, spinner, defaultItem, (ArrayList) obj);
                }
            });
            return;
        }
        AppUtils.showToast(activity, R.string.a_network_error_occurred);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_showDownloadableListDialog_4(Type type, String[] filenames, Spinner spinner, String defaultItem, ArrayList positions) {
        if (!positions.isEmpty()) {
            downloadComponentFile(type, filenames[((Integer) positions.get(0)).intValue()], spinner, defaultItem);
        }
    }

    public static void initViews(final Type type, View toolbox, final Spinner spinner, final String selectedItem, final String defaultItem) {
        final Context context = spinner.getContext();
        toolbox.findViewWithTag("install").setOnClickListener(new View.OnClickListener() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda1
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                GeneralComponents.lambda_initViews_8(type, spinner, defaultItem, context, view);
            }
        });
        toolbox.findViewWithTag("remove").setOnClickListener(new View.OnClickListener() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda0
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                GeneralComponents.lambda_initViews_10(spinner, type, context, selectedItem, defaultItem, view);
            }
        });
        loadSpinner(type, spinner, selectedItem, defaultItem);
    }

    /* JADX INFO: renamed from: com.winlator.core.GeneralComponents$1, reason: invalid class name */
    static /* synthetic */ class AnonymousClass1 {
        static final /* synthetic */ int[] $SwitchMap$com$winlator$core$GeneralComponents$InstallMode;
        static final /* synthetic */ int[] $SwitchMap$com$winlator$core$GeneralComponents$Type;

        static {
            int[] iArr = new int[InstallMode.values().length];
            $SwitchMap$com$winlator$core$GeneralComponents$InstallMode = iArr;
            try {
                iArr[InstallMode.DOWNLOAD.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$InstallMode[InstallMode.FILE.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$InstallMode[InstallMode.BOTH.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
            int[] iArr2 = new int[Type.values().length];
            $SwitchMap$com$winlator$core$GeneralComponents$Type = iArr2;
            try {
                iArr2[Type.BOX64.ordinal()] = 1;
            } catch (NoSuchFieldError e4) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$Type[Type.TURNIP.ordinal()] = 2;
            } catch (NoSuchFieldError e5) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$Type[Type.DXVK.ordinal()] = 3;
            } catch (NoSuchFieldError e6) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$Type[Type.VKD3D.ordinal()] = 4;
            } catch (NoSuchFieldError e7) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$Type[Type.WINED3D.ordinal()] = 5;
            } catch (NoSuchFieldError e8) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$Type[Type.SOUNDFONT.ordinal()] = 6;
            } catch (NoSuchFieldError e9) {
            }
            try {
                $SwitchMap$com$winlator$core$GeneralComponents$Type[Type.ADRENOTOOLS_DRIVER.ordinal()] = 7;
            } catch (NoSuchFieldError e10) {
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_initViews_8(final Type type, final Spinner spinner, final String defaultItem, final Context context, View v) {
        InstallMode installMode = type.getInstallMode();
        switch (AnonymousClass1.$SwitchMap$com$winlator$core$GeneralComponents$InstallMode[installMode.ordinal()]) {
            case 1:
                showDownloadableListDialog(type, spinner, defaultItem);
                break;
            case 2:
                openFileForInstall((MainActivity) context, type, spinner, defaultItem);
                break;
            case 3:
                PopupMenu popupMenu = new PopupMenu(context, v);
                if (Build.VERSION.SDK_INT >= 29) {
                    popupMenu.setForceShowIcon(true);
                }
                popupMenu.inflate(R.menu.open_file_popup_menu);
                popupMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda2
                    @Override // android.widget.PopupMenu.OnMenuItemClickListener
                    public final boolean onMenuItemClick(MenuItem menuItem) {
                        return GeneralComponents.lambda_initViews_7(context, type, spinner, defaultItem, menuItem);
                    }
                });
                popupMenu.show();
                break;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ boolean lambda_initViews_7(Context context, Type type, Spinner spinner, String defaultItem, MenuItem menuItem) {
        int itemId = menuItem.getItemId();
        if (itemId == R.id.menu_item_open_file) {
            openFileForInstall((MainActivity) context, type, spinner, defaultItem);
            return true;
        }
        if (itemId == R.id.menu_item_download_file) {
            showDownloadableListDialog(type, spinner, defaultItem);
            return true;
        }
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_initViews_10(final Spinner spinner, final Type type, Context context, final String selectedItem, final String defaultItem, View v) {
        String identifier = spinner.getSelectedItem().toString();
        if (!isBuiltinComponent(type, identifier)) {
            final File source = type.getSource(context, identifier);
            if (source.exists()) {
                ContentDialog.confirm(context, R.string.do_you_want_to_remove_this_component_version, new Runnable() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda10
                    @Override // java.lang.Runnable
                    public final void run() {
                        GeneralComponents.lambda_initViews_9(source, type, spinner, selectedItem, defaultItem);
                    }
                });
                return;
            }
            return;
        }
        AppUtils.showToast(context, R.string.you_cannot_remove_this_component_version);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_initViews_9(File source, Type type, Spinner spinner, String selectedItem, String defaultItem) {
        FileUtils.delete(source);
        loadSpinner(type, spinner, selectedItem, defaultItem);
    }

    private static void loadSpinner(Type type, Spinner spinner, String selectedItem, String defaultItem) {
        ArrayList<String> items = getBuiltinComponentNames(type);
        items.addAll(getInstalledComponentNames(type, spinner.getContext()));
        if (type.isVersioned()) {
            items.sort(new Comparator() { // from class: com.winlator.core.GeneralComponents$$ExternalSyntheticLambda11
                @Override // java.util.Comparator
                public final int compare(Object obj, Object obj2) {
                    return GeneralComponents.lambda_loadSpinner_11((String) obj, (String) obj2);
                }
            });
        }
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(spinner.getContext(), android.R.layout.simple_spinner_dropdown_item, items));
        if (selectedItem == null || selectedItem.isEmpty() || !AppUtils.setSpinnerSelectionFromValue(spinner, selectedItem)) {
            AppUtils.setSpinnerSelectionFromValue(spinner, defaultItem);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ int lambda_loadSpinner_11(String o1, String o2) {
        return Integer.compare(GPUHelper.vkMakeVersion(o1), GPUHelper.vkMakeVersion(o2));
    }
}
