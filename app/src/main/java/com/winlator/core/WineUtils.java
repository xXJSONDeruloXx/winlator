package com.winlator.core;

import android.content.Context;
import android.net.Uri;

import com.winlator.container.Container;
import com.winlator.container.Drive;
import com.winlator.win32.MSLogFont;
import com.winlator.win32.WinVersions;
import com.winlator.xenvironment.RootFS;
import com.winlator.xenvironment.XEnvironment;
import com.winlator.xenvironment.components.GuestProgramLauncherComponent;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Locale;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicReference;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public abstract class WineUtils {
    private static final String WINEPREFIX_PATH = "/home/xuser/.wine";
    private static final String HOME_PATH = "/home/xuser";
    private static final String DEFAULT_WINCOMPONENTS = "direct3d=1,directsound=1,directmusic=1,directshow=0,directplay=0,xaudio=1,vcrun2005=0,vcrun2010=1,wmdecoder=1";

    public static void createDosdevicesSymlinks(Container container) {
        createDosdevicesSymlinks(container, false);
    }

    public static void createDosdevicesSymlinks(Container container, boolean addDriveCDRom) {
        File rootDir = container.getRootDir();
        String dosdevicesPath = (new File(rootDir, ".wine/dosdevices")).getPath();
        File[] files = (new File(dosdevicesPath)).listFiles();
        if (files != null) for (File file : files) if (file.getName().matches("[a-z]:")) file.delete();

        FileUtils.symlink("../drive_c", dosdevicesPath+"/c:");
        FileUtils.symlink("../../../../", dosdevicesPath+"/z:");

        if (addDriveCDRom) {
            File driveX = new File(rootDir, ".wine/drive_x");
            if (!driveX.isDirectory()) {
                driveX.mkdir();
                FileUtils.chmod(driveX, 505);
            }
            String serial = String.format(Locale.ENGLISH, "%-8x", 88).replace(' ', '0');
            FileUtils.writeString(new File(driveX, ".windows-serial"), serial + "\n");
            FileUtils.symlink("../drive_x", dosdevicesPath+"/x:");
        }

        for (Drive drive : container.drivesIterator()) {
            File linkTarget = new File(drive.path);
            String path = linkTarget.getAbsolutePath();
            if (!linkTarget.isDirectory() && path.startsWith("/data/data/com.winlator/storage")) {
                linkTarget.mkdirs();
                FileUtils.chmod(linkTarget, 505);
            }
            FileUtils.symlink(path, dosdevicesPath+"/"+drive.letter.toLowerCase(Locale.ENGLISH)+":");
        }
    }

    public static void extractWineFileForInstallAsync(Context context, Uri uri, Callback<File> callback) {
        Executors.newSingleThreadExecutor().execute(() -> {
            File destination = new File(RootFS.find(context).getInstalledWineDir(), "/preinstall/wine");
            FileUtils.delete(destination);
            destination.mkdirs();
            boolean success = TarCompressorUtils.extract(TarCompressorUtils.Type.XZ, context, uri, destination);
            if (!success) FileUtils.delete(destination);
            if (callback != null) callback.call(success ? destination : null);
        });
    }

    public static void findWineVersionAsync(Context context, File wineDir, Callback<WineInfo> callback) {
        if (wineDir == null || !wineDir.isDirectory()) {
            callback.call(null);
            return;
        }
        File[] files = wineDir.listFiles();
        if (files == null || files.length == 0) {
            callback.call(null);
            return;
        }

        if (files.length == 1) {
            if (!files[0].isDirectory()) {
                callback.call(null);
                return;
            }
            wineDir = files[0];
            files = wineDir.listFiles();
            if (files == null || files.length == 0) {
                callback.call(null);
                return;
            }
        }

        File binDir = null;
        for (File file : files) {
            if (file.isDirectory() && file.getName().equals("bin")) {
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

        RootFS imageFs = RootFS.find(context);
        File rootDir = imageFs.getRootDir();
        String wineBinAbsPath = wineBin64.isFile() ? wineBin64.getPath() : wineBin.getPath();
        String wineBinRelPath = FileUtils.toRelativePath(rootDir.getPath(), wineBinAbsPath);
        final String winePath = wineDir.getPath();

        final AtomicReference<WineInfo> wineInfoRef = new AtomicReference<>();
        Callback<String> debugCallback = (line) -> {
            Pattern pattern = Pattern.compile("^wine\\-([0-9\\.]+)\\-?([0-9\\.]+)?", Pattern.CASE_INSENSITIVE);
            Matcher matcher = pattern.matcher(line);
            if (matcher.find()) {
                String version = matcher.group(1);
                String subversion = matcher.groupCount() >= 2 ? matcher.group(2) : null;
                wineInfoRef.set(new WineInfo(version, subversion, winePath));
            }
        };

        ProcessHelper.addDebugCallback(debugCallback);

        File linkFile = new File(rootDir, HOME_PATH);
        linkFile.delete();
        FileUtils.symlink(wineDir, linkFile);

        XEnvironment environment = new XEnvironment(context, imageFs);
        GuestProgramLauncherComponent guestProgramLauncherComponent = new GuestProgramLauncherComponent();
        guestProgramLauncherComponent.setGuestExecutable(wineBinRelPath+" --version");
        guestProgramLauncherComponent.setTerminationCallback((status) -> {
            callback.call(wineInfoRef.get());
            ProcessHelper.removeDebugCallback(debugCallback);
        });
        environment.addComponent(guestProgramLauncherComponent);
        environment.startEnvironmentComponents();
    }

    public static ArrayList<WineInfo> getInstalledWineInfos(Context context) {
        ArrayList<WineInfo> wineInfos = new ArrayList<>();
        wineInfos.add(WineInfo.MAIN_WINE_INFO);
        File installedWineDir = RootFS.find(context).getInstalledWineDir();

        File[] files = installedWineDir.listFiles();
        if (files != null) {
            for (File file : files) {
                String name = file.getName();
                if (name.startsWith("wine")) wineInfos.add(WineInfo.fromIdentifier(context, name));
            }
        }

        return wineInfos;
    }

    private static void setWindowMetrics(WineRegistryEditor registryEditor) {
        byte[] fontNormalData = (new MSLogFont()).toByteArray();
        byte[] fontBoldData = (new MSLogFont()).setWeight(700).toByteArray();
        registryEditor.setHexValues("Control Panel\\Desktop\\WindowMetrics", "CaptionFont", fontBoldData);
        registryEditor.setHexValues("Control Panel\\Desktop\\WindowMetrics", "IconFont", fontNormalData);
        registryEditor.setHexValues("Control Panel\\Desktop\\WindowMetrics", "MenuFont", fontNormalData);
        registryEditor.setHexValues("Control Panel\\Desktop\\WindowMetrics", "MessageFont", fontNormalData);
        registryEditor.setHexValues("Control Panel\\Desktop\\WindowMetrics", "SmCaptionFont", fontNormalData);
        registryEditor.setHexValues("Control Panel\\Desktop\\WindowMetrics", "StatusFont", fontNormalData);
    }

    public static void applySystemTweaks(Context context, WineInfo wineInfo) {
        File rootDir = RootFS.find(context).getRootDir();
        File systemRegFile = new File(rootDir, WINEPREFIX_PATH+"/system.reg");
        File userRegFile = new File(rootDir, WINEPREFIX_PATH+"/user.reg");

        try (WineRegistryEditor registryEditor = new WineRegistryEditor(systemRegFile)) {
            registryEditor.setStringValue("Software\\Classes\\.reg", null, "REGfile");
            registryEditor.setStringValue("Software\\Classes\\.reg", "Content Type", "application/reg");
            registryEditor.setStringValue("Software\\Classes\\REGfile\\Shell\\Open\\command", null, "C:\\windows\\regedit.exe /C \"%1\"");

            registryEditor.setStringValue("Software\\Classes\\dllfile\\DefaultIcon", null, "shell32.dll,-154");
            registryEditor.setStringValue("Software\\Classes\\lnkfile\\DefaultIcon", null, "shell32.dll,-30");
            registryEditor.setStringValue("Software\\Classes\\inifile\\DefaultIcon", null, "shell32.dll,-151");
        }

        final String[] direct3dLibs = {"d3d8", "d3d9", "d3d10", "d3d10_1", "d3d10core", "d3d11", "d3d12", "d3d12core", "ddraw", "dxgi", "wined3d"};
        final String[] xinputLibs = {"dinput", "dinput8", "xinput1_1", "xinput1_2", "xinput1_3", "xinput1_4", "xinput9_1_0", "xinputuap"};
        final String dllOverridesKey = "Software\\Wine\\DllOverrides";

        boolean isMainWineVersion = WineInfo.isMainWineVersion(wineInfo.identifier());

        try (WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile)) {
            for (String name : direct3dLibs) registryEditor.setStringValue(dllOverridesKey, name, "native,builtin");
            for (String name : xinputLibs) registryEditor.setStringValue(dllOverridesKey, name, isMainWineVersion ? "builtin,native" : "native,builtin");

            registryEditor.removeKey("Software\\Winlator\\WFM\\ContextMenu\\7-Zip");
            registryEditor.setStringValue("Software\\Winlator\\WFM\\ContextMenu\\7-Zip", "Open Archive", "Z:\\opt\\apps\\7-Zip\\7zFM.exe \"%FILE%\"");
            registryEditor.setStringValue("Software\\Winlator\\WFM\\ContextMenu\\7-Zip", "Extract Here", "Z:\\opt\\apps\\7-Zip\\7zG.exe x \"%FILE%\" -r -o\"%DIR%\" -y");
            registryEditor.setStringValue("Software\\Winlator\\WFM\\ContextMenu\\7-Zip", "Extract to Folder", "Z:\\opt\\apps\\7-Zip\\7zG.exe x \"%FILE%\" -r -o\"%DIR%\\%BASENAME%\" -y");

            setWindowMetrics(registryEditor);
        }

        File wineSystem32Dir = new File(rootDir, "/opt/wine/lib/wine/x86_64-windows");
        File wineSysWoW64Dir = new File(rootDir, "/opt/wine/lib/wine/i386-windows");
        File containerSystem32Dir = new File(rootDir, WINEPREFIX_PATH+"/drive_c/windows/system32");
        File containerSysWoW64Dir = new File(rootDir, WINEPREFIX_PATH+"/drive_c/windows/syswow64");

        final String[] dlnames = {"user32.dll", "shell32.dll", "dinput.dll", "dinput8.dll", "xinput1_1.dll", "xinput1_2.dll", "xinput1_3.dll", "xinput1_4.dll", "xinput9_1_0.dll", "xinputuap.dll", "winemenubuilder.exe", "explorer.exe"};
        for (String dlname : dlnames) {
            FileUtils.copy(new File(wineSysWoW64Dir, dlname), new File(containerSysWoW64Dir, dlname));
            FileUtils.copy(new File(wineSystem32Dir, dlname), new File(containerSystem32Dir, dlname));
        }
    }

    public static void overrideWinComponentDlls(Context context, Container container, String wincomponents) {
        final String dllOverridesKey = "Software\\Wine\\DllOverrides";
        File userRegFile = new File(container.getRootDir(), ".wine/user.reg");
        Iterator<String[]> oldWinComponentsIter = new KeyValueSet(container.getExtra("wincomponents", DEFAULT_WINCOMPONENTS)).iterator();

        try (WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile)) {
            JSONObject wincomponentsJSONObject = new JSONObject(FileUtils.readString(context, "wincomponents/wincomponents.json"));

            for (String[] wincomponent : new KeyValueSet(wincomponents)) {
                if (wincomponent[1].equals(oldWinComponentsIter.next()[1])) continue;
                String identifier = wincomponent[0];
                boolean useNative = wincomponent[1].equals("1");

                JSONArray dlnames = wincomponentsJSONObject.getJSONArray(identifier);
                for (int i = 0; i < dlnames.length(); i++) {
                    String dlname = dlnames.getString(i);
                    if (useNative) {
                        registryEditor.setStringValue(dllOverridesKey, dlname, "native,builtin");
                    }
                    else registryEditor.removeValue(dllOverridesKey, dlname);
                }
            }
        }
        catch (JSONException e) {}
    }

    public static void setWinComponentRegistryKeys(File systemRegFile, String identifier, boolean useNative) {
        if (identifier.equals("directsound")) {
            try (WineRegistryEditor registryEditor = new WineRegistryEditor(systemRegFile)) {
                final String key64 = "Software\\Classes\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}";
                final String key32 = "Software\\Classes\\Wow6432Node\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}";

                if (useNative) {
                    registryEditor.setStringValue(key32, "CLSID", "{E30629D1-27E5-11CE-875D-00608CB78066}");
                    registryEditor.setHexValue(key32, "FilterData", "02000000000080000100000000000000307069330200000000000000010000000000000000000000307479330000000038000000480000006175647300001000800000aa00389b710100000000001000800000aa00389b71");
                    registryEditor.setStringValue(key32, "FriendlyName", "Wave Audio Renderer");

                    registryEditor.setStringValue(key64, "CLSID", "{E30629D1-27E5-11CE-875D-00608CB78066}");
                    registryEditor.setHexValue(key64, "FilterData", "02000000000080000100000000000000307069330200000000000000010000000000000000000000307479330000000038000000480000006175647300001000800000aa00389b710100000000001000800000aa00389b71");
                    registryEditor.setStringValue(key64, "FriendlyName", "Wave Audio Renderer");
                }
                else {
                    registryEditor.removeKey(key32);
                    registryEditor.removeKey(key64);
                }
            }
        }
        else if (identifier.equals("wmdecoder")) {
            try (WineRegistryEditor registryEditor = new WineRegistryEditor(systemRegFile)) {
                if (useNative) {
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{2EEB4ADF-4578-4D10-BCA7-BB955F56320A}\\InprocServer32", null, "C:\\windows\\system32\\wmadmod.dll");
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{82D353DF-90BD-4382-8BC2-3F6192B76E34}\\InprocServer32", null, "C:\\windows\\system32\\wmvdecod.dll");
                }
                else {
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{2EEB4ADF-4578-4D10-BCA7-BB955F56320A}\\InprocServer32", null, "C:\\windows\\system32\\winegstreamer.dll");
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{82D353DF-90BD-4382-8BC2-3F6192B76E34}\\InprocServer32", null, "C:\\windows\\system32\\winegstreamer.dll");
                }
            }
        }
    }

    public static void updateWineprefix(Context context, final Callback<Integer> terminationCallback) {
        RootFS imageFs = RootFS.find(context);
        final File rootDir = imageFs.getRootDir();
        File tmpDir = imageFs.getTmpDir();
        if (!tmpDir.isDirectory()) tmpDir.mkdir();

        FileUtils.writeString(new File(rootDir, WINEPREFIX_PATH+"/.update-timestamp"), "0\n");

        EnvVars envVars = new EnvVars();
        envVars.put("WINEPREFIX", rootDir + WINEPREFIX_PATH);
        envVars.put("WINEDLLOVERRIDES", "mscoree,mshtml=d");

        XEnvironment environment = new XEnvironment(context, imageFs);
        GuestProgramLauncherComponent guestProgramLauncherComponent = new GuestProgramLauncherComponent();
        guestProgramLauncherComponent.setEnvVars(envVars);
        guestProgramLauncherComponent.setGuestExecutable("wine wineboot -u");
        guestProgramLauncherComponent.setTerminationCallback((status) -> {
            FileUtils.writeString(new File(rootDir, WINEPREFIX_PATH+"/.update-timestamp"), "disable\n");
            if (terminationCallback != null) terminationCallback.call(status);
        });
        environment.addComponent(guestProgramLauncherComponent);
        environment.startEnvironmentComponents();
    }

    public static void changeServicesStatus(Container container, boolean onlyEssential) {
        final String[] services = {"BITS:3", "Eventlog:2", "HTTP:3", "LanmanServer:3", "NDIS:2", "PlugPlay:2", "RpcSs:3", "scardsvr:3", "Schedule:3", "Spooler:3", "StiSvc:3", "TermService:3", "winebus:3", "winehid:3", "Winmgmt:3", "wuauserv:3", "winebth:3"};
        File systemRegFile = new File(container.getRootDir(), ".wine/system.reg");

        try (WineRegistryEditor registryEditor = new WineRegistryEditor(systemRegFile)) {
            registryEditor.setCreateKeyIfNotExist(false);
            String controlSetPath = registryEditor.getSymlinkValue("System\\CurrentControlSet", "SymbolicLinkValue");
            if (controlSetPath == null) {
                controlSetPath = "System\\CurrentControlSet";
            }

            for (String service : services) {
                String name = service.substring(0, service.indexOf(":"));
                int value = onlyEssential ? 4 : Character.getNumericValue(service.charAt(service.length()-1));
                registryEditor.setDwordValue(controlSetPath+"\\Services\\"+name, "Start", value);
            }
        }
    }

    public static void setSystemFont(WineRegistryEditor userRegistry, String faceName) {
        byte[] fontNormalData = new MSLogFont().setFaceName(faceName).toByteArray();
        byte[] fontBoldData = new MSLogFont().setFaceName(faceName).setWeight(700).toByteArray();
        userRegistry.setHexValues("Control Panel\\Desktop\\WindowMetrics", "CaptionFont", fontBoldData);
        userRegistry.setHexValues("Control Panel\\Desktop\\WindowMetrics", "IconFont", fontNormalData);
        userRegistry.setHexValues("Control Panel\\Desktop\\WindowMetrics", "MenuFont", fontNormalData);
        userRegistry.setHexValues("Control Panel\\Desktop\\WindowMetrics", "MessageFont", fontNormalData);
        userRegistry.setHexValues("Control Panel\\Desktop\\WindowMetrics", "SmCaptionFont", fontNormalData);
        userRegistry.setHexValues("Control Panel\\Desktop\\WindowMetrics", "StatusFont", fontNormalData);
    }

    public static void setWinVersion(Container container, int winVersionIdx) throws Throwable {
        WinVersions.WinVersion winVersion = WinVersions.getWinVersions()[winVersionIdx];
        String currentBuild = String.valueOf(winVersion.buildNumber);
        String currentVersion = winVersion.currentVersion;
        if (currentVersion == null) {
            currentVersion = ((int) winVersion.majorVersion) + "." + ((int) winVersion.minorVersion);
        }
        File systemRegFile = new File(container.getRootDir(), ".wine/system.reg");
        try (WineRegistryEditor registryEditor = new WineRegistryEditor(systemRegFile)) {
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentVersion", currentVersion);
            registryEditor.setDwordValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMajorVersionNumber", winVersion.majorVersion);
            registryEditor.setDwordValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMinorVersionNumber", winVersion.minorVersion);
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CSDVersion", winVersion.csdVersion);
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuild", currentBuild);
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuildNumber", currentBuild);
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "ProductName", "Microsoft " + winVersion.description);
            registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentVersion", currentVersion);
            registryEditor.setDwordValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMajorVersionNumber", winVersion.majorVersion);
            registryEditor.setDwordValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMinorVersionNumber", winVersion.minorVersion);
            registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CSDVersion", winVersion.csdVersion);
            registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuild", currentBuild);
            registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuildNumber", currentBuild);
            registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "ProductName", "Microsoft " + winVersion.description);
        }
    }

    public static boolean isWineprefixWasUpdated(Container container) {
        File file = new File(container.getRootDir(), "/.wine/.update-timestamp");
        String content = FileUtils.readString(file);
        if (!content.startsWith("disable")) {
            try {
                int updateTimestamp = Integer.parseInt(content.replaceAll("[\r\n]+", ""));
                if (updateTimestamp != 0) {
                    return FileUtils.writeString(file, "disable\n");
                }
                return false;
            } catch (NumberFormatException e) {
                return false;
            }
        }
        return false;
    }

    public static void changeBrowsersRegistryKey(Container container, boolean useAndroidBrowser) {
        File userRegFile = new File(container.getRootDir(), ".wine/user.reg");
        try (WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile)) {
            if (useAndroidBrowser) {
                registryEditor.setStringValue("Software\\Wine\\WineBrowser", "Browsers", "C:\\windows\\winhandler.exe /url");
            } else {
                registryEditor.setStringValue("Software\\Wine\\WineBrowser", "Browsers", "C:\\windows\\system32\\iexplore.exe");
            }
        }
    }

    public static String unixToDOSPath(String unixPath, Container container) {
        int index;
        String dosPath = "";
        String driveLetter = "";
        Iterator<Drive> it = container.drivesIterator().iterator();
        while (it.hasNext()) {
            Drive drive = it.next();
            if (unixPath.startsWith(drive.path)) {
                driveLetter = drive.letter + ":";
                dosPath = unixPath.substring(drive.path.length()).replace("/", "\\");
                break;
            }
        }
        if (dosPath.isEmpty() && (index = unixPath.indexOf("/.wine/drive_c")) != -1) {
            driveLetter = "C:";
            dosPath = unixPath.substring(index + 14).replace("/", "\\");
        }
        if (!dosPath.startsWith("\\")) {
            dosPath = dosPath + "\\";
        }
        String dosPath2 = driveLetter + StringUtils.removeEndSlash(dosPath);
        if (dosPath2.equals(driveLetter)) {
            return dosPath2 + "\\";
        }
        return dosPath2;
    }

    public static String dosToUnixPath(String dosPath, Container container) {
        int index = dosPath.indexOf(":");
        if (index == -1) {
            return "";
        }
        String driveLetter = dosPath.substring(0, index).toUpperCase(Locale.ENGLISH);
        String relativePath = StringUtils.removeStartSlash(dosPath.substring(index + 1).replace("\\", "/"));
        if (driveLetter.equals("C")) {
            return container.getRootDir() + "/.wine/drive_c/" + relativePath;
        }
        if (driveLetter.equals("Z")) {
            File rootDir = new File(container.getRootDir(), "../../");
            try {
                return rootDir.getCanonicalPath() + "/" + relativePath;
            } catch (IOException e) {
                return "";
            }
        }
        for (Drive drive : container.drivesIterator()) {
            if (drive.letter.equals(driveLetter)) {
                return drive.path + "/" + relativePath;
            }
        }
        return "";
    }
}
