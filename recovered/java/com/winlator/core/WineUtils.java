package com.winlator.core;

import android.content.Context;
import com.winlator.container.Container;
import com.winlator.container.Drive;
import com.winlator.win32.MSLogFont;
import com.winlator.win32.WinVersions;
import com.winlator.xenvironment.RootFS;
import com.winlator.xenvironment.XEnvironment;
import com.winlator.xenvironment.components.GuestProgramLauncherComponent;
import java.io.File;
import java.io.IOException;
import java.util.Iterator;
import java.util.Locale;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public abstract class WineUtils {
    public static void createDosdevicesSymlinks(Container container, boolean addDriveCDRom) {
        File rootDir = container.getRootDir();
        String dosdevicesPath = new File(rootDir, ".wine/dosdevices").getPath();
        File[] files = new File(dosdevicesPath).listFiles();
        if (files != null) {
            for (File file : files) {
                if (file.getName().matches("[a-z]:")) {
                    file.delete();
                }
            }
        }
        FileUtils.symlink("../drive_c", dosdevicesPath + "/c:");
        FileUtils.symlink("../../../../", dosdevicesPath + "/z:");
        if (addDriveCDRom) {
            File driveX = new File(rootDir, ".wine/drive_x");
            if (!driveX.isDirectory()) {
                driveX.mkdir();
                FileUtils.chmod(driveX, 505);
            }
            String serial = String.format(Locale.ENGLISH, "%-8x", 88).replace(' ', '0');
            FileUtils.writeString(new File(driveX, ".windows-serial"), serial + "\n");
            FileUtils.symlink("../drive_x", dosdevicesPath + "/x:");
        }
        for (Drive drive : container.drivesIterator()) {
            File linkTarget = new File(drive.path);
            String path = linkTarget.getAbsolutePath();
            if (!linkTarget.isDirectory() && path.startsWith("/data/data/com.winlator/storage")) {
                linkTarget.mkdirs();
                FileUtils.chmod(linkTarget, 505);
            }
            FileUtils.symlink(path, dosdevicesPath + "/" + drive.letter.toLowerCase(Locale.ENGLISH) + ":");
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

    public static void applySystemTweaks(Context context, WineInfo wineInfo) {
        Throwable th;
        WineRegistryEditor registryEditor;
        Throwable th2;
        int length;
        int i;
        String str;
        int i2;
        File userRegFile;
        String[] direct3dLibs;
        String name;
        File rootDir = RootFS.find(context).getRootDir();
        File userCacheDir = new File(rootDir, "/home/xuser/.cache");
        if (!userCacheDir.isDirectory()) {
            userCacheDir.mkdirs();
        }
        File userConfigDir = new File(rootDir, "/home/xuser/.config");
        if (!userConfigDir.isDirectory()) {
            userConfigDir.mkdirs();
        }
        File systemRegFile = new File(rootDir, "/home/xuser/.wine/system.reg");
        File userRegFile2 = new File(rootDir, "/home/xuser/.wine/user.reg");
        WineRegistryEditor registryEditor2 = new WineRegistryEditor(systemRegFile);
        try {
            registryEditor2.setStringValue("Software\\Wine\\Drives", "x:", "cdrom");
            registryEditor2.setStringValue("Software\\Classes\\.reg", null, "REGfile");
            registryEditor2.setStringValue("Software\\Classes\\.reg", "Content Type", "application/reg");
            registryEditor2.setStringValue("Software\\Classes\\REGfile\\Shell\\Open\\command", null, "C:\\windows\\regedit.exe /C \"%1\"");
            registryEditor2.setStringValue("Software\\Classes\\dllfile\\DefaultIcon", null, "shell32.dll,-154");
            registryEditor2.setStringValue("Software\\Classes\\lnkfile\\DefaultIcon", null, "shell32.dll,-30");
            registryEditor2.setStringValue("Software\\Classes\\inifile\\DefaultIcon", null, "shell32.dll,-151");
            File corefontsAddedFile = new File(userConfigDir, "corefonts.added");
            if (!corefontsAddedFile.isFile()) {
                try {
                    setupSystemFonts(registryEditor2);
                    FileUtils.writeString(corefontsAddedFile, String.valueOf(System.currentTimeMillis()));
                } catch (Throwable th3) {
                    th = th3;
                    try {
                        registryEditor2.close();
                        throw th;
                    } catch (Throwable th4) {
                        th.addSuppressed(th4);
                        throw th;
                    }
                }
            }
            registryEditor2.close();
            String[] direct3dLibs2 = {"d3d8", "d3d9", "d3d10", "d3d10_1", "d3d10core", "d3d11", "d3d12", "d3d12core", "ddraw", "dxgi", "wined3d"};
            String[] inputLibs = {"dinput", "dinput8", "xinput1_1", "xinput1_2", "xinput1_3", "xinput1_4", "xinput9_1_0", "xinputuap"};
            boolean isMainWineVersion = WineInfo.isMainWineVersion(wineInfo.identifier());
            File wineSystem32Dir = new File(rootDir, "/opt/wine/lib/wine/x86_64-windows");
            File wineSysWoW64Dir = new File(rootDir, "/opt/wine/lib/wine/i386-windows");
            File containerSystem32Dir = new File(rootDir, "/home/xuser/.wine/drive_c/windows/system32");
            File containerSysWoW64Dir = new File(rootDir, "/home/xuser/.wine/drive_c/windows/syswow64");
            WineRegistryEditor registryEditor3 = new WineRegistryEditor(userRegFile2);
            try {
                length = direct3dLibs2.length;
                i = 0;
            } catch (Throwable th5) {
                registryEditor = registryEditor3;
                th2 = th5;
            }
            while (true) {
                File userCacheDir2 = userCacheDir;
                str = "native,builtin";
                File userConfigDir2 = userConfigDir;
                if (i >= length) {
                    break;
                }
                try {
                    File systemRegFile2 = systemRegFile;
                    registryEditor = registryEditor3;
                    int i3 = length;
                    try {
                        registryEditor.setStringValue("Software\\Wine\\DllOverrides", direct3dLibs2[i], "native,builtin");
                        i++;
                        length = i3;
                        userCacheDir = userCacheDir2;
                        userConfigDir = userConfigDir2;
                        registryEditor3 = registryEditor;
                        systemRegFile = systemRegFile2;
                    } catch (Throwable th6) {
                        th2 = th6;
                    }
                } catch (Throwable th7) {
                    registryEditor = registryEditor3;
                    th2 = th7;
                }
                try {
                    registryEditor.close();
                    throw th2;
                } catch (Throwable th8) {
                    th2.addSuppressed(th8);
                    throw th2;
                }
            }
            registryEditor = registryEditor3;
            try {
                int length2 = inputLibs.length;
                int i4 = 0;
                while (i4 < length2) {
                    String name2 = inputLibs[i4];
                    if (isMainWineVersion) {
                        i2 = length2;
                        userRegFile = userRegFile2;
                        direct3dLibs = direct3dLibs2;
                        name = str;
                        registryEditor.setStringValue("Software\\Wine\\DllOverrides", name2, "builtin,native");
                    } else {
                        i2 = length2;
                        registryEditor.setStringValue("Software\\Wine\\DllOverrides", name2, str);
                        name = str;
                        userRegFile = userRegFile2;
                        try {
                            direct3dLibs = direct3dLibs2;
                            try {
                                FileUtils.copy(new File(wineSysWoW64Dir, name2 + ".dll"), new File(containerSysWoW64Dir, name2 + ".dll"));
                                FileUtils.copy(new File(wineSystem32Dir, name2 + ".dll"), new File(containerSystem32Dir, name2 + ".dll"));
                            } catch (Throwable th9) {
                                th2 = th9;
                            }
                        } catch (Throwable th10) {
                            th2 = th10;
                        }
                    }
                    i4++;
                    length2 = i2;
                    str = name;
                    userRegFile2 = userRegFile;
                    direct3dLibs2 = direct3dLibs;
                }
                registryEditor.removeKey("Software\\Winlator\\WFM\\ContextMenu\\7-Zip");
                registryEditor.setStringValue("Software\\Winlator\\WFM\\ContextMenu\\7-Zip", "Open Archive", "Z:\\opt\\apps\\7-Zip\\7zFM.exe \"%FILE%\"");
                registryEditor.setStringValue("Software\\Winlator\\WFM\\ContextMenu\\7-Zip", "Extract Here", "Z:\\opt\\apps\\7-Zip\\7zG.exe x \"%FILE%\" -r -o\"%DIR%\" -y");
                registryEditor.setStringValue("Software\\Winlator\\WFM\\ContextMenu\\7-Zip", "Extract to Folder", "Z:\\opt\\apps\\7-Zip\\7zG.exe x \"%FILE%\" -r -o\"%DIR%\\%BASENAME%\" -y");
                registryEditor.setStringValue("Software\\Wine\\AddonsURL", null, "https://raw.githubusercontent.com/brunodev85/winlator/main/wine_addons/");
                registryEditor.setStringValue("Software\\Wine\\Drivers", "Graphics", "x11");
                registryEditor.close();
            } catch (Throwable th11) {
                th2 = th11;
            }
        } catch (Throwable th12) {
            th = th12;
        }
    }

    public static void changeBrowsersRegistryKey(Container container, boolean useAndroidBrowser) {
        File userRegFile = new File(container.getRootDir(), ".wine/user.reg");
        WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile);
        try {
            if (useAndroidBrowser) {
                registryEditor.setStringValue("Software\\Wine\\WineBrowser", "Browsers", "C:\\windows\\winhandler.exe /url");
            } else {
                registryEditor.setStringValue("Software\\Wine\\WineBrowser", "Browsers", "C:\\windows\\system32\\iexplore.exe");
            }
            registryEditor.close();
        } catch (Throwable th) {
            try {
                registryEditor.close();
            } catch (Throwable th2) {
                th.addSuppressed(th2);
            }
            throw th;
        }
    }

    public static void overrideWinComponentDlls(Context context, Container container, String wincomponents) {
        Throwable th;
        String dllOverridesKey;
        String dllOverridesKey2 = "Software\\Wine\\DllOverrides";
        File userRegFile = new File(container.getRootDir(), ".wine/user.reg");
        Iterator<String[]> oldWinComponentsIter = new KeyValueSet(container.getExtra("wincomponents", "direct3d=0,directsound=0,directmusic=0,directshow=0,directplay=0,xaudio=0,vcrun2005=0,vcrun2010=0,wmdecoder=0")).iterator();
        try {
            WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile);
            try {
                try {
                    try {
                        JSONObject wincomponentsJSONObject = new JSONObject(FileUtils.readString(context, "wincomponents/wincomponents.json"));
                        try {
                            for (String[] wincomponent : new KeyValueSet(wincomponents)) {
                                if (!wincomponent[1].equals(oldWinComponentsIter.next()[1])) {
                                    String identifier = wincomponent[0];
                                    boolean useNative = wincomponent[1].equals("1");
                                    JSONObject wincomponentJSONObject = wincomponentsJSONObject.getJSONObject(identifier);
                                    JSONArray dlnames = wincomponentJSONObject.getJSONArray("dlnames");
                                    int i = 0;
                                    while (i < dlnames.length()) {
                                        String dlname = dlnames.getString(i);
                                        JSONObject wincomponentsJSONObject2 = wincomponentsJSONObject;
                                        if (useNative) {
                                            dllOverridesKey = dllOverridesKey2;
                                            try {
                                                registryEditor.setStringValue("Software\\Wine\\DllOverrides", dlname, "native,builtin");
                                            } catch (Throwable th2) {
                                                th = th2;
                                                try {
                                                    registryEditor.close();
                                                    throw th;
                                                } catch (Throwable th3) {
                                                    th.addSuppressed(th3);
                                                    throw th;
                                                }
                                            }
                                        } else {
                                            dllOverridesKey = dllOverridesKey2;
                                            registryEditor.removeValue("Software\\Wine\\DllOverrides", dlname);
                                        }
                                        i++;
                                        wincomponentsJSONObject = wincomponentsJSONObject2;
                                        dllOverridesKey2 = dllOverridesKey;
                                    }
                                }
                            }
                            registryEditor.close();
                        } catch (Throwable th4) {
                            th = th4;
                            th = th;
                            registryEditor.close();
                            throw th;
                        }
                    } catch (Throwable th5) {
                        th = th5;
                        th = th;
                        registryEditor.close();
                        throw th;
                    }
                } catch (Throwable th6) {
                    th = th6;
                }
            } catch (JSONException e) {
            }
        } catch (JSONException e2) {
        }
    }

    public static void setWinComponentRegistryKeys(File systemRegFile, String identifier, boolean useNative) {
        WineRegistryEditor registryEditor;
        if (identifier.equals("directsound")) {
            registryEditor = new WineRegistryEditor(systemRegFile);
            try {
                if (useNative) {
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}", "CLSID", "{E30629D1-27E5-11CE-875D-00608CB78066}");
                    registryEditor.setHexValue("Software\\Classes\\Wow6432Node\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}", "FilterData", "02000000000080000100000000000000307069330200000000000000010000000000000000000000307479330000000038000000480000006175647300001000800000aa00389b710100000000001000800000aa00389b71");
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}", "FriendlyName", "Wave Audio Renderer");
                    registryEditor.setStringValue("Software\\Classes\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}", "CLSID", "{E30629D1-27E5-11CE-875D-00608CB78066}");
                    registryEditor.setHexValue("Software\\Classes\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}", "FilterData", "02000000000080000100000000000000307069330200000000000000010000000000000000000000307479330000000038000000480000006175647300001000800000aa00389b710100000000001000800000aa00389b71");
                    registryEditor.setStringValue("Software\\Classes\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}", "FriendlyName", "Wave Audio Renderer");
                } else {
                    registryEditor.removeKey("Software\\Classes\\Wow6432Node\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}");
                    registryEditor.removeKey("Software\\Classes\\CLSID\\{083863F1-70DE-11D0-BD40-00A0C911CE86}\\Instance\\{E30629D1-27E5-11CE-875D-00608CB78066}");
                }
                registryEditor.close();
                return;
            } finally {
                try {
                    registryEditor.close();
                } catch (Throwable th) {
                    th.addSuppressed(th);
                }
            }
        }
        if (identifier.equals("wmdecoder")) {
            registryEditor = new WineRegistryEditor(systemRegFile);
            try {
                if (useNative) {
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{2EEB4ADF-4578-4D10-BCA7-BB955F56320A}\\InprocServer32", null, "C:\\windows\\syswow64\\wmadmod.dll");
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{82D353DF-90BD-4382-8BC2-3F6192B76E34}\\InprocServer32", null, "C:\\windows\\syswow64\\wmvdecod.dll");
                } else {
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{2EEB4ADF-4578-4D10-BCA7-BB955F56320A}\\InprocServer32", null, "C:\\windows\\syswow64\\winegstreamer.dll");
                    registryEditor.setStringValue("Software\\Classes\\Wow6432Node\\CLSID\\{82D353DF-90BD-4382-8BC2-3F6192B76E34}\\InprocServer32", null, "C:\\windows\\syswow64\\winegstreamer.dll");
                }
                registryEditor.close();
            } catch (Throwable th2) {
                throw th2;
            }
        }
    }

    public static void updateWineprefix(Context context, final Callback<Integer> terminationCallback) {
        RootFS rootFS = RootFS.find(context);
        final File rootDir = rootFS.getRootDir();
        File tmpDir = rootFS.getTmpDir();
        if (!tmpDir.isDirectory()) {
            tmpDir.mkdir();
        }
        FileUtils.writeString(new File(rootDir, "/home/xuser/.wine/.update-timestamp"), "0\n");
        EnvVars envVars = new EnvVars();
        envVars.put("WINEPREFIX", rootDir + "/home/xuser/.wine");
        envVars.put("WINEDLLOVERRIDES", "mscoree,mshtml=d");
        XEnvironment environment = new XEnvironment(context, rootFS);
        GuestProgramLauncherComponent guestProgramLauncherComponent = new GuestProgramLauncherComponent();
        guestProgramLauncherComponent.setEnvVars(envVars);
        guestProgramLauncherComponent.setGuestExecutable("wine wineboot -u");
        guestProgramLauncherComponent.setTerminationCallback(new Callback() { // from class: com.winlator.core.WineUtils$$ExternalSyntheticLambda0
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                WineUtils.lambda$updateWineprefix$0(rootDir, terminationCallback, (Integer) obj);
            }
        });
        environment.addComponent(guestProgramLauncherComponent);
        environment.startEnvironmentComponents();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$updateWineprefix$0(File rootDir, Callback terminationCallback, Integer status) {
        FileUtils.writeString(new File(rootDir, "/home/xuser/.wine/.update-timestamp"), "disable\n");
        if (terminationCallback != null) {
            terminationCallback.call(status);
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

    public static void changeServicesStatus(Container container, boolean onlyEssential) {
        String[] services = {"BITS:3", "Eventlog:2", "HTTP:3", "LanmanServer:3", "NDIS:2", "PlugPlay:2", "RpcSs:3", "scardsvr:3", "Schedule:3", "Spooler:3", "StiSvc:3", "TermService:3", "winebus:3", "winehid:3", "Winmgmt:3", "wuauserv:3", "winebth:3"};
        File systemRegFile = new File(container.getRootDir(), ".wine/system.reg");
        WineRegistryEditor registryEditor = new WineRegistryEditor(systemRegFile);
        try {
            registryEditor.setCreateKeyIfNotExist(false);
            String controlSetPath = registryEditor.getSymlinkValue("System\\CurrentControlSet", "SymbolicLinkValue");
            if (controlSetPath == null) {
                controlSetPath = "System\\CurrentControlSet";
            }
            for (String service : services) {
                String name = service.substring(0, service.indexOf(":"));
                int value = onlyEssential ? 4 : Character.getNumericValue(service.charAt(service.length() - 1));
                registryEditor.setDwordValue(controlSetPath + "\\Services\\" + name, "Start", value);
            }
            registryEditor.close();
        } finally {
        }
    }

    public static String unixToDOSPath(String unixPath, Container container) {
        int index;
        String dosPath = "";
        String driveLetter = "";
        Iterator<Drive> it = container.drivesIterator().iterator();
        while (true) {
            if (!it.hasNext()) {
                break;
            }
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
            String unixPath = container.getRootDir() + "/.wine/drive_c/" + relativePath;
            return unixPath;
        }
        if (driveLetter.equals("Z")) {
            File rootDir = new File(container.getRootDir(), "../../");
            try {
                String unixPath2 = rootDir.getCanonicalPath() + "/" + relativePath;
                return unixPath2;
            } catch (IOException e) {
                return "";
            }
        }
        for (Drive drive : container.drivesIterator()) {
            if (drive.letter.equals(driveLetter)) {
                String unixPath3 = drive.path + "/" + relativePath;
                return unixPath3;
            }
        }
        return "";
    }

    public static void setWinVersion(Container container, int winVersionIdx) throws Throwable {
        Throwable th;
        WinVersions.WinVersion winVersion = WinVersions.getWinVersions()[winVersionIdx];
        String currentBuild = String.valueOf(winVersion.buildNumber);
        String currentVersion = winVersion.currentVersion;
        if (currentVersion == null) {
            currentVersion = ((int) winVersion.majorVersion) + "." + ((int) winVersion.minorVersion);
        }
        File systemRegFile = new File(container.getRootDir(), ".wine/system.reg");
        WineRegistryEditor registryEditor = new WineRegistryEditor(systemRegFile);
        try {
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentVersion", currentVersion);
            registryEditor.setDwordValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMajorVersionNumber", winVersion.majorVersion);
            registryEditor.setDwordValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMinorVersionNumber", winVersion.minorVersion);
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CSDVersion", winVersion.csdVersion);
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuild", currentBuild);
            registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuildNumber", currentBuild);
            StringBuilder sb = new StringBuilder();
            sb.append("Microsoft ");
            try {
                sb.append(winVersion.description);
                registryEditor.setStringValue("Software\\Wow6432Node\\Microsoft\\Windows NT\\CurrentVersion", "ProductName", sb.toString());
                registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentVersion", currentVersion);
                registryEditor.setDwordValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMajorVersionNumber", winVersion.majorVersion);
                registryEditor.setDwordValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentMinorVersionNumber", winVersion.minorVersion);
                registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CSDVersion", winVersion.csdVersion);
                registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuild", currentBuild);
                registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "CurrentBuildNumber", currentBuild);
                registryEditor.setStringValue("Software\\Microsoft\\Windows NT\\CurrentVersion", "ProductName", "Microsoft " + winVersion.description);
                registryEditor.close();
            } catch (Throwable th2) {
                th = th2;
                try {
                    registryEditor.close();
                    throw th;
                } catch (Throwable th3) {
                    th.addSuppressed(th3);
                    throw th;
                }
            }
        } catch (Throwable th4) {
            th = th4;
        }
    }

    private static void setupSystemFonts(WineRegistryEditor registryEditor) {
        String[][] corefonts = {new String[]{"Andale Mono (TrueType)", "andalemo.ttf"}, new String[]{"Arial (TrueType)", "arial.ttf"}, new String[]{"Arial Black (TrueType)", "ariblk.ttf"}, new String[]{"Arial Bold (TrueType)", "arialbd.ttf"}, new String[]{"Arial Bold Italic (TrueType)", "arialbi.ttf"}, new String[]{"Arial Italic (TrueType)", "ariali.ttf"}, new String[]{"Comic Sans MS (TrueType)", "comic.ttf"}, new String[]{"Comic Sans MS Bold (TrueType)", "comicbd.ttf"}, new String[]{"Courier New (TrueType)", "cour.ttf"}, new String[]{"Courier New Bold (TrueType)", "courbd.ttf"}, new String[]{"Courier New Bold Italic (TrueType)", "courbi.ttf"}, new String[]{"Courier New Italic (TrueType)", "couri.ttf"}, new String[]{"Georgia (TrueType)", "georgia.ttf"}, new String[]{"Georgia Bold (TrueType)", "georgiab.ttf"}, new String[]{"Georgia Bold Italic (TrueType)", "georgiaz.ttf"}, new String[]{"Georgia Italic (TrueType)", "georgiai.ttf"}, new String[]{"Impact (TrueType)", "impact.ttf"}, new String[]{"Times New Roman (TrueType)", "times.ttf"}, new String[]{"Times New Roman Bold (TrueType)", "timesbd.ttf"}, new String[]{"Times New Roman Bold Italic (TrueType)", "timesbi.ttf"}, new String[]{"Times New Roman Italic (TrueType)", "timesi.ttf"}, new String[]{"Trebuchet MS (TrueType)", "trebuc.ttf"}, new String[]{"Trebuchet MS Bold (TrueType)", "trebucbd.ttf"}, new String[]{"Trebuchet MS Bold Italic (TrueType)", "trebucbi.ttf"}, new String[]{"Trebuchet MS Italic (TrueType)", "trebucit.ttf"}, new String[]{"Verdana (TrueType)", "verdana.ttf"}, new String[]{"Verdana Bold (TrueType)", "verdanab.ttf"}, new String[]{"Verdana Bold Italic (TrueType)", "verdanaz.ttf"}, new String[]{"Verdana Italic (TrueType)", "verdanai.ttf"}, new String[]{"Webdings (TrueType)", "webdings.ttf"}};
        registryEditor.setStringValues("Software\\Microsoft\\Windows\\CurrentVersion\\Fonts", corefonts);
        registryEditor.setStringValues("Software\\Microsoft\\Windows NT\\CurrentVersion\\Fonts", corefonts);
        String[][] wineFonts = {new String[]{"Marlett (TrueType)", "Z:\\opt\\wine\\share\\wine\\fonts\\marlett.ttf"}, new String[]{"Symbol (TrueType)", "Z:\\opt\\wine\\share\\wine\\fonts\\symbol.ttf"}, new String[]{"Tahoma (TrueType)", "Z:\\opt\\wine\\share\\wine\\fonts\\tahoma.ttf"}, new String[]{"Tahoma Bold (TrueType)", "Z:\\opt\\wine\\share\\wine\\fonts\\tahomabd.ttf"}, new String[]{"Wingdings (TrueType)", "Z:\\opt\\wine\\share\\wine\\fonts\\wingding.ttf"}};
        registryEditor.setStringValues("Software\\Microsoft\\Windows\\CurrentVersion\\Fonts", wineFonts);
        registryEditor.setStringValues("Software\\Microsoft\\Windows NT\\CurrentVersion\\Fonts", wineFonts);
    }
}
