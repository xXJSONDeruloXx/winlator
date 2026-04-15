package com.winlator.container;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import com.winlator.core.FileUtils;
import com.winlator.core.StringUtils;
import java.io.File;
import java.util.Iterator;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public class Shortcut {
    public final Container container;
    private final JSONObject extraData = new JSONObject();
    public final File file;
    public final Bitmap icon;
    public final File iconFile;
    public final String name;
    public final String path;
    public final String wmClass;

    public Shortcut(Container container, File file) {
        String str = null;
        Container container2 = container;
        this.container = container2;
        this.file = file;
        String str2 = "";
        if (file.isDirectory()) {
            this.name = file.getName();
            this.path = null;
            this.icon = null;
            this.iconFile = null;
            this.wmClass = "";
            return;
        }
        short[] iconSizes = {64, 48, 32, 24, 16, 128, 256};
        int i = 1;
        String section = "";
        String wmClass = "";
        File iconFile = null;
        Bitmap icon = null;
        String execArgs = "";
        for (String line : FileUtils.readLines(file, true)) {
            if (!line.startsWith("#")) {
                if (line.startsWith("[")) {
                    section = line.substring(i, line.indexOf("]"));
                    str = str2;
                } else {
                    int index = line.indexOf("=");
                    if (index != -1) {
                        String key = line.substring(0, index);
                        String value = line.substring(index + 1);
                        if (section.equals("Desktop Entry")) {
                            execArgs = key.equals("Exec") ? value : execArgs;
                            if (!key.equals("Icon")) {
                                str = str2;
                            } else {
                                int length = iconSizes.length;
                                File iconFile2 = iconFile;
                                int i2 = 0;
                                while (true) {
                                    if (i2 >= length) {
                                        str = str2;
                                        iconFile = iconFile2;
                                        break;
                                    }
                                    int i3 = length;
                                    short iconSize = iconSizes[i2];
                                    str = str2;
                                    iconFile2 = new File(container2.getIconsDir(iconSize), value + ".png");
                                    if (!iconFile2.isFile()) {
                                        i2++;
                                        container2 = container;
                                        length = i3;
                                        str2 = str;
                                    } else {
                                        icon = BitmapFactory.decodeFile(iconFile2.getPath());
                                        iconFile = iconFile2;
                                        break;
                                    }
                                }
                            }
                            if (key.equals("StartupWMClass")) {
                                wmClass = value;
                            }
                        } else {
                            str = str2;
                            if (section.equals("Extra Data")) {
                                try {
                                    this.extraData.put(key, value);
                                } catch (JSONException e) {
                                }
                            }
                        }
                    }
                }
                container2 = container;
                str2 = str;
                i = 1;
            }
        }
        String str3 = str2;
        this.name = FileUtils.getBasename(file.getPath());
        this.icon = icon;
        this.iconFile = iconFile;
        this.wmClass = wmClass;
        String path = !execArgs.isEmpty() ? StringUtils.unescapeDOSPath(execArgs.substring(execArgs.lastIndexOf("wine ") + 4)) : str3;
        int index2 = path.indexOf("start.exe ");
        this.path = index2 != -1 ? path.substring(index2 + 10) : path;
        Container.checkObsoleteOrMissingProperties(this.extraData);
    }

    public String getExtra(String name) {
        return getExtra(name, "");
    }

    public String getExtra(String name, String fallback) {
        try {
            return this.extraData.has(name) ? this.extraData.getString(name) : fallback;
        } catch (JSONException e) {
            return fallback;
        }
    }

    public void putExtra(String name, String value) {
        try {
            if (value != null) {
                this.extraData.put(name, value);
            } else {
                this.extraData.remove(name);
            }
        } catch (JSONException e) {
        }
    }

    public void saveData() {
        String content = "[Desktop Entry]\n";
        for (String line : FileUtils.readLines(this.file)) {
            if (line.contains("[Extra Data]")) {
                break;
            }
            if (!line.contains("[Desktop Entry]") && !line.isEmpty()) {
                content = content + line + "\n";
            }
        }
        if (this.extraData.length() > 0) {
            content = content + "\n[Extra Data]\n";
            Iterator<String> keys = this.extraData.keys();
            while (keys.hasNext()) {
                String key = keys.next();
                try {
                    content = content + key + "=" + this.extraData.getString(key) + "\n";
                } catch (JSONException e) {
                }
            }
        }
        FileUtils.writeString(this.file, content);
    }

    public File getLinkFile() {
        String name = this.file.getName().replace(".desktop", ".lnk");
        return new File(this.file.getParentFile(), name);
    }

    public void remove() {
        if (this.file.isDirectory()) {
            FileUtils.delete(this.file);
            return;
        }
        File linkFile = getLinkFile();
        if (this.file.delete()) {
            File file = this.iconFile;
            if (file != null) {
                file.delete();
            }
            if (linkFile.isFile()) {
                linkFile.delete();
            }
        }
    }
}
