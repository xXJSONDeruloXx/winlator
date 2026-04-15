package com.winlator.container;

import com.winlator.core.AppUtils;
import com.winlator.core.EnvVars;
import com.winlator.core.FileUtils;
import com.winlator.core.KeyValueSet;
import com.winlator.core.WineInfo;
import com.winlator.core.WineThemeManager;
import com.winlator.widget.FrameRating;
import java.io.File;
import java.util.Iterator;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public class Container {
    public static final String DEFAULT_DRIVES = "D:" + AppUtils.DIRECTORY_DOWNLOADS + "E:/data/data/com.winlator/storage";
    private String cpuList;
    private String cpuListWoW64;
    private JSONObject extraData;
    public final int id;
    private String name;
    private File rootDir;
    private String screenSize = "1280x720";
    private String envVars = "ZINK_DESCRIPTORS=lazy ZINK_DEBUG=compact MESA_SHADER_CACHE_DISABLE=false MESA_SHADER_CACHE_MAX_SIZE=512MB mesa_glthread=true WINEESYNC=1 TU_DEBUG=noconform";
    private String graphicsDriver = "vortek,gladio";
    private String dxwrapper = "dxvk";
    private String dxwrapperConfig = "";
    private String graphicsDriverConfig = "";
    private String audioDriverConfig = "";
    private String wincomponents = "direct3d=1,directsound=1,directmusic=1,directshow=0,directplay=0,xaudio=1,vcrun2005=0,vcrun2010=1,wmdecoder=1";
    private String audioDriver = "alsa";
    private String drives = DEFAULT_DRIVES;
    private String wineVersion = WineInfo.MAIN_WINE_INFO.identifier();
    private byte hudMode = (byte) FrameRating.Mode.DISABLED.ordinal();
    private byte startupSelection = 1;
    private String desktopTheme = WineThemeManager.DEFAULT_DESKTOP_THEME;
    private String box64Preset = "INTERMEDIATE";

    public Container(int id) {
        this.id = id;
        this.name = "Container-" + id;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getScreenSize() {
        return this.screenSize;
    }

    public void setScreenSize(String screenSize) {
        this.screenSize = screenSize;
    }

    public String getEnvVars() {
        return this.envVars;
    }

    public void setEnvVars(String envVars) {
        this.envVars = envVars != null ? envVars : "";
    }

    public String getGraphicsDriver() {
        return this.graphicsDriver;
    }

    public void setGraphicsDriver(String graphicsDriver) {
        this.graphicsDriver = graphicsDriver;
    }

    public String getDXWrapper() {
        return this.dxwrapper;
    }

    public void setDXWrapper(String dxwrapper) {
        this.dxwrapper = dxwrapper;
    }

    public String getGraphicsDriverConfig() {
        return this.graphicsDriverConfig;
    }

    public void setGraphicsDriverConfig(String graphicsDriverConfig) {
        this.graphicsDriverConfig = graphicsDriverConfig != null ? graphicsDriverConfig : "";
    }

    public String getDXWrapperConfig() {
        return this.dxwrapperConfig;
    }

    public void setDXWrapperConfig(String dxwrapperConfig) {
        this.dxwrapperConfig = dxwrapperConfig != null ? dxwrapperConfig : "";
    }

    public String getAudioDriverConfig() {
        return this.audioDriverConfig;
    }

    public void setAudioDriverConfig(String audioDriverConfig) {
        this.audioDriverConfig = audioDriverConfig != null ? audioDriverConfig : "";
    }

    public String getAudioDriver() {
        return this.audioDriver;
    }

    public void setAudioDriver(String audioDriver) {
        this.audioDriver = audioDriver;
    }

    public String getWinComponents() {
        return this.wincomponents;
    }

    public void setWinComponents(String wincomponents) {
        this.wincomponents = wincomponents;
    }

    public String getDrives() {
        return this.drives;
    }

    public void setDrives(String drives) {
        this.drives = drives;
    }

    public byte getHUDMode() {
        return this.hudMode;
    }

    public void setHUDMode(byte hudMode) {
        this.hudMode = hudMode;
    }

    public byte getStartupSelection() {
        return this.startupSelection;
    }

    public void setStartupSelection(byte startupSelection) {
        this.startupSelection = startupSelection;
    }

    public String getCPUList() {
        return getCPUList(false);
    }

    public String getCPUList(boolean allowFallback) {
        String str = this.cpuList;
        if (str != null) {
            return str;
        }
        if (allowFallback) {
            return getFallbackCPUList();
        }
        return null;
    }

    public void setCPUList(String cpuList) {
        this.cpuList = (cpuList == null || cpuList.isEmpty()) ? null : cpuList;
    }

    public String getCPUListWoW64() {
        return getCPUListWoW64(false);
    }

    public String getCPUListWoW64(boolean allowFallback) {
        String str = this.cpuListWoW64;
        if (str != null) {
            return str;
        }
        if (allowFallback) {
            return getFallbackCPUListWoW64();
        }
        return null;
    }

    public void setCPUListWoW64(String cpuListWoW64) {
        this.cpuListWoW64 = (cpuListWoW64 == null || cpuListWoW64.isEmpty()) ? null : cpuListWoW64;
    }

    public String getBox64Preset() {
        return this.box64Preset;
    }

    public void setBox64Preset(String box64Preset) {
        this.box64Preset = box64Preset;
    }

    public File getRootDir() {
        return this.rootDir;
    }

    public void setRootDir(File rootDir) {
        this.rootDir = rootDir;
    }

    public void setExtraData(JSONObject extraData) {
        this.extraData = extraData;
    }

    public String getExtra(String name) {
        return getExtra(name, "");
    }

    public String getExtra(String name, String fallback) {
        try {
            JSONObject jSONObject = this.extraData;
            return (jSONObject == null || !jSONObject.has(name)) ? fallback : this.extraData.getString(name);
        } catch (JSONException e) {
            return fallback;
        }
    }

    public void putExtra(String name, Object value) {
        if (this.extraData == null) {
            this.extraData = new JSONObject();
        }
        try {
            if (value != null) {
                this.extraData.put(name, value);
            } else {
                this.extraData.remove(name);
            }
        } catch (JSONException e) {
        }
    }

    public String getWineVersion() {
        return this.wineVersion;
    }

    public void setWineVersion(String wineVersion) {
        this.wineVersion = wineVersion;
    }

    public File getConfigFile() {
        return new File(this.rootDir, ".container");
    }

    public File getUserDir() {
        return new File(this.rootDir, ".wine/drive_c/users/xuser/");
    }

    public File getStartMenuDir() {
        return new File(this.rootDir, ".wine/drive_c/ProgramData/Microsoft/Windows/Start Menu/");
    }

    public File getIconsDir(int size) {
        return new File(this.rootDir, ".local/share/icons/hicolor/" + size + "x" + size + "/apps/");
    }

    public String getDesktopTheme() {
        return this.desktopTheme;
    }

    public void setDesktopTheme(String desktopTheme) {
        this.desktopTheme = desktopTheme;
    }

    public Iterable<Drive> drivesIterator() {
        return drivesIterator(this.drives);
    }

    public static Iterable<Drive> drivesIterator(final String drives) {
        final int[] index = {drives.indexOf(":")};
        return new Iterable() { // from class: com.winlator.container.Container$$ExternalSyntheticLambda0
            @Override // java.lang.Iterable
            public final Iterator iterator() {
                return Container.lambda_drivesIterator_0(index, drives);
            }
        };
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ Iterator lambda_drivesIterator_0(final int[] index, final String drives) {
        return new Iterator<Drive>() { // from class: com.winlator.container.Container.1
            @Override // java.util.Iterator
            public boolean hasNext() {
                return index[0] != -1;
            }

            /* JADX WARN: Can't rename method to resolve collision */
            @Override // java.util.Iterator
            public Drive next() {
                String letter = String.valueOf(drives.charAt(index[0] - 1));
                int nextIndex = drives.indexOf(":", index[0] + 1);
                String str = drives;
                String path = str.substring(index[0] + 1, nextIndex != -1 ? nextIndex - 1 : str.length());
                index[0] = nextIndex;
                return new Drive(letter, path);
            }
        };
    }

    public void saveData() {
        try {
            JSONObject data = new JSONObject();
            data.put("id", this.id);
            data.put("name", this.name);
            data.put("screenSize", this.screenSize);
            data.put("envVars", this.envVars);
            data.put("cpuList", this.cpuList);
            data.put("cpuListWoW64", this.cpuListWoW64);
            data.put("graphicsDriver", this.graphicsDriver);
            data.put("dxwrapper", this.dxwrapper);
            if (!this.dxwrapperConfig.isEmpty()) {
                data.put("dxwrapperConfig", this.dxwrapperConfig);
            }
            if (!this.graphicsDriverConfig.isEmpty()) {
                data.put("graphicsDriverConfig", this.graphicsDriverConfig);
            }
            if (!this.audioDriverConfig.isEmpty()) {
                data.put("audioDriverConfig", this.audioDriverConfig);
            }
            data.put("audioDriver", this.audioDriver);
            data.put("wincomponents", this.wincomponents);
            data.put("drives", this.drives);
            data.put("hudMode", (int) this.hudMode);
            data.put("startupSelection", (int) this.startupSelection);
            data.put("box64Preset", this.box64Preset);
            data.put("desktopTheme", this.desktopTheme);
            data.put("extraData", this.extraData);
            if (!WineInfo.isMainWineVersion(this.wineVersion)) {
                data.put("wineVersion", this.wineVersion);
            }
            FileUtils.writeString(getConfigFile(), data.toString());
        } catch (JSONException e) {
        }
    }

    public void loadData(JSONObject data) throws JSONException {
        String key;
        this.wineVersion = WineInfo.MAIN_WINE_INFO.identifier();
        this.dxwrapperConfig = "";
        this.graphicsDriverConfig = "";
        this.audioDriverConfig = "";
        checkObsoleteOrMissingProperties(data);
        Iterator<String> it = data.keys();
        while (it.hasNext()) {
            key = it.next();
            switch (key) {
                case "name":
                    setName(data.getString(key));
                    break;
                case "screenSize":
                    setScreenSize(data.getString(key));
                    break;
                case "envVars":
                    setEnvVars(data.getString(key));
                    break;
                case "cpuList":
                    setCPUList(data.getString(key));
                    break;
                case "cpuListWoW64":
                    setCPUListWoW64(data.getString(key));
                    break;
                case "graphicsDriver":
                    setGraphicsDriver(data.getString(key));
                    break;
                case "wincomponents":
                    setWinComponents(data.getString(key));
                    break;
                case "dxwrapper":
                    setDXWrapper(data.getString(key));
                    break;
                case "dxwrapperConfig":
                    setDXWrapperConfig(data.getString(key));
                    break;
                case "graphicsDriverConfig":
                    setGraphicsDriverConfig(data.getString(key));
                    break;
                case "audioDriverConfig":
                    setAudioDriverConfig(data.getString(key));
                    break;
                case "drives":
                    setDrives(data.getString(key));
                    break;
                case "showFPS":
                    setHUDMode((byte) (data.getBoolean(key) ? FrameRating.Mode.SIMPLE : FrameRating.Mode.DISABLED).ordinal());
                    break;
                case "hudMode":
                    setHUDMode((byte) data.getInt(key));
                    break;
                case "startupSelection":
                    setStartupSelection((byte) data.getInt(key));
                    break;
                case "extraData":
                    JSONObject extraData = data.getJSONObject(key);
                    checkObsoleteOrMissingProperties(extraData);
                    setExtraData(extraData);
                    break;
                case "wineVersion":
                    setWineVersion(data.getString(key));
                    break;
                case "box64Preset":
                    setBox64Preset(data.getString(key));
                    break;
                case "audioDriver":
                    setAudioDriver(data.getString(key));
                    break;
                case "desktopTheme":
                    setDesktopTheme(data.getString(key));
                    break;
            }
        }
    }

    public static void checkObsoleteOrMissingProperties(JSONObject data) {
        try {
            if (data.has("extraData")) {
                JSONObject extraData = data.getJSONObject("extraData");
                int appVersion = Integer.parseInt(extraData.optString("appVersion", "0"));
                if (appVersion < 16 && data.has("envVars")) {
                    EnvVars defaultEnvVars = new EnvVars("ZINK_DESCRIPTORS=lazy ZINK_DEBUG=compact MESA_SHADER_CACHE_DISABLE=false MESA_SHADER_CACHE_MAX_SIZE=512MB mesa_glthread=true WINEESYNC=1 TU_DEBUG=noconform");
                    EnvVars envVars = new EnvVars(data.getString("envVars"));
                    for (String name : defaultEnvVars) {
                        if (!envVars.has(name)) {
                            envVars.put(name, defaultEnvVars.get(name));
                        }
                    }
                    data.put("envVars", envVars.toString());
                }
            }
            KeyValueSet wincomponents1 = new KeyValueSet("direct3d=1,directsound=1,directmusic=1,directshow=0,directplay=0,xaudio=1,vcrun2005=0,vcrun2010=1,wmdecoder=1");
            KeyValueSet wincomponents2 = new KeyValueSet(data.getString("wincomponents"));
            String result = "";
            for (String[] wincomponent1 : wincomponents1) {
                String value = wincomponent1[1];
                Iterator<String[]> it = wincomponents2.iterator();
                while (true) {
                    if (!it.hasNext()) {
                        break;
                    }
                    String[] wincomponent2 = it.next();
                    if (wincomponent1[0].equals(wincomponent2[0])) {
                        value = wincomponent2[1];
                        break;
                    }
                }
                StringBuilder sb = new StringBuilder();
                sb.append(result);
                sb.append(!result.isEmpty() ? "," : "");
                sb.append(wincomponent1[0]);
                sb.append("=");
                sb.append(value);
                result = sb.toString();
            }
            data.put("wincomponents", result);
        } catch (JSONException e) {
        }
    }

    public static String getFallbackCPUList() {
        String cpuList = "";
        int numProcessors = Runtime.getRuntime().availableProcessors();
        for (int i = 0; i < numProcessors; i++) {
            StringBuilder sb = new StringBuilder();
            sb.append(cpuList);
            sb.append(!cpuList.isEmpty() ? "," : "");
            sb.append(i);
            cpuList = sb.toString();
        }
        return cpuList;
    }

    public static String getFallbackCPUListWoW64() {
        String cpuList = "";
        int numProcessors = Runtime.getRuntime().availableProcessors();
        for (int i = numProcessors / 2; i < numProcessors; i++) {
            StringBuilder sb = new StringBuilder();
            sb.append(cpuList);
            sb.append(!cpuList.isEmpty() ? "," : "");
            sb.append(i);
            cpuList = sb.toString();
        }
        return cpuList;
    }
}
