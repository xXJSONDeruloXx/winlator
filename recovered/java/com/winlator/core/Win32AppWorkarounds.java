package com.winlator.core;

import com.winlator.XServerDisplayActivity;
import com.winlator.container.Container;
import com.winlator.winhandler.WinHandler;
import com.winlator.xserver.ScreenInfo;
import com.winlator.xserver.Window;
import java.util.Locale;

/* JADX INFO: loaded from: classes.dex */
public class Win32AppWorkarounds {
    private final XServerDisplayActivity activity;
    private final short taskAffinityMask;
    private final short taskAffinityMaskWoW64;

    /* JADX INFO: Access modifiers changed from: private */
    interface DXWrapperWorkaround extends Workaround {
        String getValue();
    }

    /* JADX INFO: Access modifiers changed from: private */
    interface EnvVarsWorkaround extends Workaround {
        void apply(EnvVars envVars);
    }

    /* JADX INFO: Access modifiers changed from: private */
    interface ScreenSizeWorkaround extends Workaround {
        String getValue();
    }

    /* JADX INFO: Access modifiers changed from: private */
    interface WinComponentsWorkaround extends Workaround {
        void setValue(KeyValueSet keyValueSet);
    }

    /* JADX INFO: Access modifiers changed from: private */
    interface WindowWorkaround extends Workaround {
        void apply(Window window);
    }

    private interface Workaround {
    }

    private static class MultiWorkaround implements Workaround {
        private final Workaround[] list;
    }

    public Win32AppWorkarounds(XServerDisplayActivity activity) {
        this.activity = activity;
        Container container = activity.getContainer();
        this.taskAffinityMask = (short) ProcessHelper.getAffinityMask(container.getCPUList(true));
        this.taskAffinityMaskWoW64 = (short) ProcessHelper.getAffinityMask(container.getCPUListWoW64(true));
    }

    private void applyWorkaround(Workaround workaround) {
        if (workaround instanceof EnvVarsWorkaround) {
            ((EnvVarsWorkaround) workaround).apply(this.activity.getOverrideEnvVars());
            return;
        }
        if (workaround instanceof ScreenSizeWorkaround) {
            this.activity.setScreenInfo(new ScreenInfo(((ScreenSizeWorkaround) workaround).getValue()));
            return;
        }
        if (workaround instanceof DXWrapperWorkaround) {
            this.activity.setDXWrapper(((DXWrapperWorkaround) workaround).getValue());
        } else if (workaround instanceof WinComponentsWorkaround) {
            KeyValueSet wincomponents = new KeyValueSet("direct3d=1,directsound=1,directmusic=1,directshow=0,directplay=0,xaudio=1,vcrun2005=0,vcrun2010=1,wmdecoder=1");
            ((WinComponentsWorkaround) workaround).setValue(wincomponents);
            this.activity.setWinComponents(wincomponents.toString());
        }
    }

    public void applyStartupWorkarounds(String className) {
        Workaround workaround = getWorkaroundFor(className);
        if (workaround == null) {
            return;
        }
        if (workaround instanceof MultiWorkaround) {
            for (Workaround workaround2 : ((MultiWorkaround) workaround).list) {
                applyWorkaround(workaround2);
            }
            return;
        }
        applyWorkaround(workaround);
    }

    private void setProcessAffinity(Window window, int processAffinity) {
        int processId = window.getProcessId();
        String className = window.getClassName();
        WinHandler winHandler = this.activity.getWinHandler();
        if (className.equals("steam.exe")) {
            return;
        }
        if (processId > 0) {
            winHandler.setProcessAffinity(processId, processAffinity);
        } else if (!className.isEmpty()) {
            winHandler.setProcessAffinity(window.getClassName(), processAffinity);
        }
    }

    public void applyWindowWorkarounds(Window window) {
        Workaround workaround = getWorkaroundFor(window.getClassName());
        boolean canApplyProcessAffinity = false;
        if (workaround instanceof WindowWorkaround) {
            ((WindowWorkaround) workaround).apply(window);
        } else if (workaround instanceof MultiWorkaround) {
            Workaround[] workaroundArr = ((MultiWorkaround) workaround).list;
            int length = workaroundArr.length;
            int i = 0;
            while (true) {
                if (i >= length) {
                    break;
                }
                Workaround workaround2 = workaroundArr[i];
                if (!(workaround2 instanceof WindowWorkaround)) {
                    i++;
                } else {
                    ((WindowWorkaround) workaround2).apply(window);
                    break;
                }
            }
        }
        int windowGroup = window.getWMHintsValue(Window.WMHints.WINDOW_GROUP);
        if (window.isRenderable() && !window.getClassName().isEmpty() && windowGroup == window.id) {
            canApplyProcessAffinity = true;
        }
        if (canApplyProcessAffinity) {
            int processAffinity = window.isWoW64() ? this.taskAffinityMaskWoW64 : this.taskAffinityMask;
            if (processAffinity != 0) {
                setProcessAffinity(window, processAffinity);
            }
        }
    }

    private Workaround getWorkaroundFor(String className) {
        String appIdentifier;
        if (className.startsWith("steam://")) {
            appIdentifier = className.substring(className.lastIndexOf("/") + 1);
        } else {
            appIdentifier = className.toLowerCase(Locale.ENGLISH);
        }
        switch (appIdentifier) {
            case "sonicgenerations.exe":
            case "71340":
            case "valkyria.exe":
            case "294860":
                return new EnvVarsWorkaround() { // from class: com.winlator.core.Win32AppWorkarounds$$ExternalSyntheticLambda2
                    @Override // com.winlator.core.Win32AppWorkarounds.EnvVarsWorkaround
                    public final void apply(EnvVars envVars) {
                        envVars.put("WINEESYNC", "0");
                    }
                };
            case "blacklist_game.exe":
            case "blacklist_dx11_game.exe":
                return new EnvVarsWorkaround() { // from class: com.winlator.core.Win32AppWorkarounds$$ExternalSyntheticLambda1
                    @Override // com.winlator.core.Win32AppWorkarounds.EnvVarsWorkaround
                    public final void apply(EnvVars envVars) {
                        this.f$0.lambda$getWorkaroundFor$1(envVars);
                    }
                };
            case "fate.exe":
                return new ScreenSizeWorkaround() { // from class: com.winlator.core.Win32AppWorkarounds$$ExternalSyntheticLambda4
                    @Override // com.winlator.core.Win32AppWorkarounds.ScreenSizeWorkaround
                    public final String getValue() {
                        return Win32AppWorkarounds.lambda$getWorkaroundFor$2();
                    }
                };
            case "ffxii_tza.exe":
                final ScreenInfo screenInfo = this.activity.getScreenInfo();
                return new ScreenSizeWorkaround() { // from class: com.winlator.core.Win32AppWorkarounds$$ExternalSyntheticLambda3
                    @Override // com.winlator.core.Win32AppWorkarounds.ScreenSizeWorkaround
                    public final String getValue() {
                        return Win32AppWorkarounds.lambda$getWorkaroundFor$3(screenInfo);
                    }
                };
            case "chronocross_launcher.exe":
                return new WindowWorkaround() { // from class: com.winlator.core.Win32AppWorkarounds$$ExternalSyntheticLambda6
                    @Override // com.winlator.core.Win32AppWorkarounds.WindowWorkaround
                    public final void apply(Window window) {
                        Win32AppWorkarounds.lambda$getWorkaroundFor$4(window);
                    }
                };
            case "dino.exe":
            case "dino2.exe":
            case "bof4.exe":
                return new WinComponentsWorkaround() { // from class: com.winlator.core.Win32AppWorkarounds$$ExternalSyntheticLambda5
                    @Override // com.winlator.core.Win32AppWorkarounds.WinComponentsWorkaround
                    public final void setValue(KeyValueSet keyValueSet) {
                        keyValueSet.put("directshow", "1");
                    }
                };
            case "discipl2.exe":
                return new DXWrapperWorkaround() { // from class: com.winlator.core.Win32AppWorkarounds$$ExternalSyntheticLambda0
                    @Override // com.winlator.core.Win32AppWorkarounds.DXWrapperWorkaround
                    public final String getValue() {
                        return Win32AppWorkarounds.lambda$getWorkaroundFor$6();
                    }
                };
            default:
                return null;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$getWorkaroundFor$1(EnvVars envVars) {
        envVars.put("WINEOVERRIDEAFFINITYMASK", Short.valueOf(this.taskAffinityMaskWoW64));
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ String lambda$getWorkaroundFor$2() {
        return "1024x768";
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ String lambda$getWorkaroundFor$3(ScreenInfo screenInfo) {
        return (screenInfo.width + 4) + "x" + (screenInfo.height + 4);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$getWorkaroundFor$4(Window window) {
        window.attributes.setTransparent(true);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ String lambda$getWorkaroundFor$6() {
        return "wined3d";
    }
}
