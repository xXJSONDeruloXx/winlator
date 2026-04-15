package com.winlator.core;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.RectF;
import com.winlator.win32.MSBitmap;
import com.winlator.xenvironment.RootFS;
import com.winlator.xserver.ScreenInfo;
import java.io.File;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public abstract class WineThemeManager {
    public static final String DEFAULT_DESKTOP_THEME = Theme.LIGHT + "," + BackgroundType.IMAGE + ",#0277bd";

    public enum BackgroundType {
        IMAGE,
        COLOR
    }

    public enum Theme {
        LIGHT,
        DARK
    }

    public static class ThemeInfo {
        public final int backgroundColor;
        public final BackgroundType backgroundType;
        public final Theme theme;
        public final String wallpaperId;

        public ThemeInfo(String value) {
            String[] values = value.split(",");
            this.theme = Theme.valueOf(values[0]);
            if (values.length < 3) {
                this.backgroundColor = Color.parseColor(values[1]);
                this.backgroundType = BackgroundType.IMAGE;
            } else {
                this.backgroundType = BackgroundType.valueOf(values[1]);
                this.backgroundColor = Color.parseColor(values[2]);
            }
            String lastValue = values[values.length - 1];
            this.wallpaperId = lastValue.startsWith("wallpaper-") ? lastValue : lastValue.equals("0") ? "wallpaper-1" : "user-wallpaper";
        }
    }

    public static void apply(Context context, ThemeInfo themeInfo, ScreenInfo screenInfo) throws Throwable {
        Throwable th;
        File rootDir = RootFS.find(context).getRootDir();
        File userRegFile = new File(rootDir, "/home/xuser/.wine/user.reg");
        String background = Color.red(themeInfo.backgroundColor) + " " + Color.green(themeInfo.backgroundColor) + " " + Color.blue(themeInfo.backgroundColor);
        BackgroundType backgroundType = themeInfo.backgroundType;
        BackgroundType backgroundType2 = BackgroundType.IMAGE;
        if (backgroundType == backgroundType2) {
            createWallpaperBMPFile(context, themeInfo.wallpaperId, screenInfo);
        }
        WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile);
        try {
            if (themeInfo.backgroundType == backgroundType2) {
                registryEditor.setStringValue("Control Panel\\Desktop", "Wallpaper", RootFS.getDosUserCachePath() + "\\wallpaper.bmp");
            } else {
                registryEditor.removeValue("Control Panel\\Desktop", "Wallpaper");
            }
            Theme theme = themeInfo.theme;
                if (theme == Theme.LIGHT) {
                    registryEditor.setStringValue("Control Panel\\Colors", "ActiveBorder", "245 245 245");
                    registryEditor.setStringValue("Control Panel\\Colors", "ActiveTitle", "96 125 139");
                    registryEditor.setStringValue("Control Panel\\Colors", "Background", background);
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonAlternateFace", "245 245 245");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonDkShadow", "158 158 158");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonFace", "245 245 245");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonHilight", "224 224 224");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonLight", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonShadow", "158 158 158");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonText", "0 0 0");
                    registryEditor.setStringValue("Control Panel\\Colors", "GradientActiveTitle", "96 125 139");
                    registryEditor.setStringValue("Control Panel\\Colors", "GradientInactiveTitle", "117 117 117");
                    registryEditor.setStringValue("Control Panel\\Colors", "GrayText", "158 158 158");
                    registryEditor.setStringValue("Control Panel\\Colors", "Hilight", "2 136 209");
                    registryEditor.setStringValue("Control Panel\\Colors", "HilightText", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "HotTrackingColor", "2 136 209");
                    registryEditor.setStringValue("Control Panel\\Colors", "InactiveBorder", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "InactiveTitle", "117 117 117");
                    registryEditor.setStringValue("Control Panel\\Colors", "InactiveTitleText", "200 200 200");
                    registryEditor.setStringValue("Control Panel\\Colors", "InfoText", "0 0 0");
                    registryEditor.setStringValue("Control Panel\\Colors", "InfoWindow", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "Menu", "245 245 245");
                    registryEditor.setStringValue("Control Panel\\Colors", "MenuBar", "245 245 245");
                    registryEditor.setStringValue("Control Panel\\Colors", "MenuHilight", "2 136 209");
                    registryEditor.setStringValue("Control Panel\\Colors", "MenuText", "0 0 0");
                    registryEditor.setStringValue("Control Panel\\Colors", "Scrollbar", "245 245 245");
                    registryEditor.setStringValue("Control Panel\\Colors", "TitleText", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "Window", "245 245 245");
                    registryEditor.setStringValue("Control Panel\\Colors", "WindowFrame", "158 158 158");
                    registryEditor.setStringValue("Control Panel\\Colors", "WindowText", "0 0 0");
                } else if (theme == Theme.DARK) {
                    registryEditor.setStringValue("Control Panel\\Colors", "ActiveBorder", "48 48 48");
                    registryEditor.setStringValue("Control Panel\\Colors", "ActiveTitle", "33 33 33");
                    registryEditor.setStringValue("Control Panel\\Colors", "Background", background);
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonAlternateFace", "33 33 33");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonDkShadow", "0 0 0");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonFace", "33 33 33");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonHilight", "48 48 48");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonLight", "48 48 48");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonShadow", "0 0 0");
                    registryEditor.setStringValue("Control Panel\\Colors", "ButtonText", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "GradientActiveTitle", "33 33 33");
                    registryEditor.setStringValue("Control Panel\\Colors", "GradientInactiveTitle", "33 33 33");
                    registryEditor.setStringValue("Control Panel\\Colors", "GrayText", "117 117 117");
                    registryEditor.setStringValue("Control Panel\\Colors", "Hilight", "2 136 209");
                    registryEditor.setStringValue("Control Panel\\Colors", "HilightText", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "HotTrackingColor", "2 136 209");
                    registryEditor.setStringValue("Control Panel\\Colors", "InactiveBorder", "48 48 48");
                    registryEditor.setStringValue("Control Panel\\Colors", "InactiveTitle", "33 33 33");
                    registryEditor.setStringValue("Control Panel\\Colors", "InactiveTitleText", "117 117 117");
                    registryEditor.setStringValue("Control Panel\\Colors", "InfoText", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "InfoWindow", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "Menu", "33 33 33");
                    registryEditor.setStringValue("Control Panel\\Colors", "MenuBar", "48 48 48");
                    registryEditor.setStringValue("Control Panel\\Colors", "MenuHilight", "2 136 209");
                    registryEditor.setStringValue("Control Panel\\Colors", "MenuText", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "Scrollbar", "48 48 48");
                    registryEditor.setStringValue("Control Panel\\Colors", "TitleText", "255 255 255");
                    registryEditor.setStringValue("Control Panel\\Colors", "Window", "48 48 48");
                    registryEditor.setStringValue("Control Panel\\Colors", "WindowFrame", "0 0 0");
                    registryEditor.setStringValue("Control Panel\\Colors", "WindowText", "255 255 255");
                }
                registryEditor.close();
        } catch (Throwable ex) {
            try {
                registryEditor.close();
            } catch (Throwable ignored) {
            }
            throw ex;
        }
    }

    private static void createWallpaperBMPFile(Context context, String wallpaperId, ScreenInfo screenInfo) {
        int secondaryColor;
        Bitmap wallpaperBitmap;
        Canvas canvas;
        float scale;
        int outputWidth = (int) Math.ceil((480.0f / screenInfo.height) * screenInfo.width);
        Bitmap outputBitmap = Bitmap.createBitmap(outputWidth, 480, Bitmap.Config.ARGB_8888);
        Paint paint = new Paint(1);
        Canvas canvas2 = new Canvas(outputBitmap);
        File userWallpaperFile = getUserWallpaperFile(context);
        if (wallpaperId.equals("user-wallpaper") && userWallpaperFile.isFile()) {
            Bitmap image = BitmapFactory.decodeFile(userWallpaperFile.getPath());
            Rect srcRect = new Rect(0, 0, image.getWidth(), image.getHeight());
            Rect dstRect = new Rect(0, 0, outputWidth, 480);
            canvas2.drawBitmap(image, srcRect, dstRect, paint);
        } else if (wallpaperId.startsWith("wallpaper-")) {
            String wallpaperDir = "wallpapers/" + wallpaperId;
            try {
                JSONObject config = new JSONObject(FileUtils.readString(context, wallpaperDir + "/config.json"));
                int primaryColor = Color.parseColor(config.optString("primaryColor", "#ffffff"));
                int secondaryColor2 = Color.parseColor(config.optString("secondaryColor", "#ffffff"));
                String orientation = config.optString("orientation", "none");
                float scale2 = (float) config.optDouble("scale", 1.0d);
                Bitmap wallpaperBitmap2 = ImageUtils.getBitmapFromAsset(context, wallpaperDir + "/image.png");
                paint.setStyle(Paint.Style.FILL);
                if (!orientation.equals("horizontal")) {
                    secondaryColor = secondaryColor2;
                    wallpaperBitmap = wallpaperBitmap2;
                    canvas = canvas2;
                    scale = scale2;
                    if (orientation.equals("vertical")) {
                        paint.setColor(primaryColor);
                        canvas.drawRect(0.0f, 0.0f, outputWidth, 240.0f, paint);
                        paint.setColor(secondaryColor);
                        canvas.drawRect(0.0f, 240.0f, outputWidth, 480.0f, paint);
                    }
                } else {
                    paint.setColor(primaryColor);
                    wallpaperBitmap = wallpaperBitmap2;
                    canvas = canvas2;
                    scale = scale2;
                    canvas2.drawRect(0.0f, 0.0f, outputWidth * 0.5f, 480.0f, paint);
                    paint.setColor(secondaryColor2);
                    secondaryColor = secondaryColor2;
                    canvas.drawRect(outputWidth * 0.5f, 0.0f, outputWidth, 480.0f, paint);
                }
                float targetSize = scale * 480.0f;
                float centerX = (outputWidth - targetSize) * 0.5f;
                float centerY = (480.0f - targetSize) * 0.5f;
                Rect srcRect2 = new Rect(0, 0, wallpaperBitmap.getWidth(), wallpaperBitmap.getHeight());
                RectF dstRect2 = new RectF(centerX, centerY, centerX + targetSize, centerY + targetSize);
                canvas.drawBitmap(wallpaperBitmap, srcRect2, dstRect2, paint);
            } catch (JSONException e) {
                return;
            }
        }
        RootFS rootFS = RootFS.find(context);
        MSBitmap.create(outputBitmap, new File(rootFS.getRootDir(), "/home/xuser/.cache/wallpaper.bmp"));
    }

    public static File getUserWallpaperFile(Context context) {
        return new File(RootFS.find(context).getRootDir(), "/home/xuser/.config/user-wallpaper.png");
    }
}
