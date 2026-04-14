package com.winlator;

import android.app.PictureInPictureParams;
import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowInsets;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.FrameLayout;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import androidx.appcompat.app.AppCompatActivity;
import androidx.drawerlayout.widget.DrawerLayout;
import androidx.preference.PreferenceManager;
import com.google.android.material.navigation.NavigationView;
import com.winlator.alsaserver.ALSAClient;
import com.winlator.container.Container;
import com.winlator.container.ContainerManager;
import com.winlator.container.DXWrappers;
import com.winlator.container.GraphicsDrivers;
import com.winlator.container.Shortcut;
import com.winlator.contentdialog.ActiveWindowsDialog;
import com.winlator.contentdialog.ContentDialog;
import com.winlator.contentdialog.DXVKConfigDialog;
import com.winlator.contentdialog.DebugDialog;
import com.winlator.contentdialog.ScreenEffectDialog;
import com.winlator.contentdialog.TurnipConfigDialog;
import com.winlator.contentdialog.VKD3DConfigDialog;
import com.winlator.contentdialog.VirGLConfigDialog;
import com.winlator.contentdialog.WineD3DConfigDialog;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import com.winlator.core.DefaultVersion;
import com.winlator.core.EnvVars;
import com.winlator.core.FileUtils;
import com.winlator.core.GeneralComponents;
import com.winlator.core.KeyValueSet;
import com.winlator.core.LocaleHelper;
import com.winlator.core.PreloaderDialog;
import com.winlator.core.ProcessHelper;
import com.winlator.core.StringUtils;
import com.winlator.core.TarCompressorUtils;
import com.winlator.core.Win32AppWorkarounds;
import com.winlator.core.WineInfo;
import com.winlator.core.WineInstaller;
import com.winlator.core.WineRegistryEditor;
import com.winlator.core.WineStartMenuCreator;
import com.winlator.core.WineThemeManager;
import com.winlator.core.WineUtils;
import com.winlator.inputcontrols.ControlsProfile;
import com.winlator.inputcontrols.ExternalController;
import com.winlator.inputcontrols.InputControlsManager;
import com.winlator.math.Mathf;
import com.winlator.renderer.GLRenderer;
import com.winlator.widget.FrameRating;
import com.winlator.widget.InputControlsView;
import com.winlator.widget.MagnifierView;
import com.winlator.widget.TouchpadView;
import com.winlator.widget.XServerView;
import com.winlator.winhandler.GamepadHandler;
import com.winlator.winhandler.TaskManagerDialog;
import com.winlator.winhandler.WinHandler;
import com.winlator.xconnector.UnixSocketConfig;
import com.winlator.xenvironment.RootFS;
import com.winlator.xenvironment.XEnvironment;
import com.winlator.xenvironment.components.ALSAServerComponent;
import com.winlator.xenvironment.components.GuestProgramLauncherComponent;
import com.winlator.xenvironment.components.NetworkInfoUpdateComponent;
import com.winlator.xenvironment.components.PulseAudioComponent;
import com.winlator.xenvironment.components.SysVSharedMemoryComponent;
import com.winlator.xenvironment.components.VirGLRendererComponent;
import com.winlator.xenvironment.components.VortekRendererComponent;
import com.winlator.xenvironment.components.XServerComponent;
import com.winlator.xserver.Property;
import com.winlator.xserver.ScreenInfo;
import com.winlator.xserver.Window;
import com.winlator.xserver.WindowManager;
import com.winlator.xserver.XServer;
import java.io.File;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Objects;
import java.util.concurrent.Executors;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public class XServerDisplayActivity extends AppCompatActivity implements NavigationView.OnNavigationItemSelectedListener {
    private KeyValueSet audioDriverConfig;
    private ClipboardManager clipboardManager;
    private Container container;
    private DebugDialog debugDialog;
    private DrawerLayout drawerLayout;
    private KeyValueSet[] dxwrapperConfig;
    private Runnable editInputControlsCallback;
    private XEnvironment environment;
    private FrameRating frameRating;
    private KeyValueSet[] graphicsDriverConfig;
    private InputControlsManager inputControlsManager;
    private InputControlsView inputControlsView;
    private MagnifierView magnifierView;
    private EnvVars overrideEnvVars;
    private SharedPreferences preferences;
    private RootFS rootFS;
    private String screenEffectProfile;
    private Shortcut shortcut;
    private TouchpadView touchpadView;
    private Win32AppWorkarounds win32AppWorkarounds;
    private String wincomponents;
    private WineInfo wineInfo;
    private XServer xServer;
    private XServerView xServerView;
    private String[] graphicsDriver = {"vortek", "gladio"};
    private String audioDriver = "alsa";
    private String dxwrapper = "dxvk";
    private ScreenInfo screenInfo = new ScreenInfo("1280x720");
    private final EnvVars envVars = new EnvVars();
    private final WinHandler winHandler = new WinHandler(this);
    private float globalCursorSpeed = 1.0f;
    private boolean capturePointerOnExternalMouse = true;
    private int frameRatingWindowId = -1;

    @Override // androidx.fragment.app.FragmentActivity, androidx.activity.ComponentActivity, androidx.core.app.ComponentActivity, android.app.Activity
    public void onCreate(Bundle savedInstanceState) {
        int preferredInputApiIdx;
        AppUtils.setActivityTheme(this);
        super.onCreate(savedInstanceState);
        AppUtils.hideSystemUI(this);
        AppUtils.keepScreenOn(this);
        setContentView(R.layout.xserver_display_activity);
        final PreloaderDialog preloaderDialog = new PreloaderDialog(this);
        SharedPreferences defaultSharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        this.preferences = defaultSharedPreferences;
        boolean useAndroidClipboardOnWine = defaultSharedPreferences.getBoolean("use_android_clipboard_on_wine", false);
        this.clipboardManager = useAndroidClipboardOnWine ? (ClipboardManager) getSystemService("clipboard") : null;
        DrawerLayout drawerLayout = (DrawerLayout) findViewById(R.id.DrawerLayout);
        this.drawerLayout = drawerLayout;
        drawerLayout.setOnApplyWindowInsetsListener(new View.OnApplyWindowInsetsListener() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda0
            @Override // android.view.View.OnApplyWindowInsetsListener
            public final WindowInsets onApplyWindowInsets(View view, WindowInsets windowInsets) {
                return XServerDisplayActivity.lambda$onCreate$0(view, windowInsets);
            }
        });
        this.drawerLayout.setDrawerLockMode(1);
        NavigationView navigationView = (NavigationView) findViewById(R.id.NavigationView);
        ProcessHelper.removeAllDebugCallbacks();
        boolean enableLogs = this.preferences.getBoolean("enable_wine_debug", false) || this.preferences.getInt("box64_logs", 0) >= 1;
        if (enableLogs) {
            DebugDialog debugDialog = new DebugDialog(this);
            this.debugDialog = debugDialog;
            ProcessHelper.addDebugCallback(debugDialog);
        }
        Menu menu = navigationView.getMenu();
        menu.findItem(R.id.menu_item_logs).setVisible(enableLogs);
        navigationView.setNavigationItemSelectedListener(this);
        this.rootFS = RootFS.find(this);
        if (!isGenerateWineprefix()) {
            ContainerManager containerManager = new ContainerManager(this);
            Container containerById = containerManager.getContainerById(getIntent().getIntExtra("container_id", 0));
            this.container = containerById;
            containerManager.activateContainer(containerById);
            boolean wineprefixNeedsUpdate = this.container.getExtra("wineprefixNeedsUpdate").equals("t");
            if (!wineprefixNeedsUpdate) {
                this.win32AppWorkarounds = new Win32AppWorkarounds(this);
                String wineVersion = this.container.getWineVersion();
                WineInfo wineInfoFromIdentifier = WineInfo.fromIdentifier(this, wineVersion);
                this.wineInfo = wineInfoFromIdentifier;
                if (wineInfoFromIdentifier != WineInfo.MAIN_WINE_INFO) {
                    this.rootFS.setWinePath(wineInfoFromIdentifier.path);
                }
                String shortcutPath = getIntent().getStringExtra("shortcut_path");
                if (shortcutPath != null && !shortcutPath.isEmpty()) {
                    this.shortcut = new Shortcut(this.container, new File(shortcutPath));
                }
                String graphicsDriver = this.container.getGraphicsDriver();
                this.audioDriver = this.container.getAudioDriver();
                String dxwrapper = this.container.getDXWrapper();
                this.wincomponents = this.container.getWinComponents();
                String dxwrapperConfig = this.container.getDXWrapperConfig();
                String graphicsDriverConfig = this.container.getGraphicsDriverConfig();
                this.audioDriverConfig = new KeyValueSet(this.container.getAudioDriverConfig());
                this.screenInfo = new ScreenInfo(this.container.getScreenSize());
                int preferredInputApiIdx2 = this.preferences.getInt("preferred_input_api", GamepadHandler.PreferredInputApi.AUTO.ordinal());
                Shortcut shortcut = this.shortcut;
                if (shortcut != null) {
                    int preferredInputApiIdx3 = preferredInputApiIdx2;
                    graphicsDriver = shortcut.getExtra("graphicsDriver", this.container.getGraphicsDriver());
                    this.audioDriver = this.shortcut.getExtra("audioDriver", this.container.getAudioDriver());
                    dxwrapper = this.shortcut.getExtra("dxwrapper", this.container.getDXWrapper());
                    this.wincomponents = this.shortcut.getExtra("wincomponents", this.container.getWinComponents());
                    dxwrapperConfig = this.shortcut.getExtra("dxwrapperConfig", this.container.getDXWrapperConfig());
                    String graphicsDriverConfig2 = this.shortcut.getExtra("graphicsDriverConfig", this.container.getGraphicsDriverConfig());
                    this.audioDriverConfig = new KeyValueSet(this.shortcut.getExtra("audioDriverConfig", this.container.getAudioDriverConfig()));
                    this.screenInfo = new ScreenInfo(this.shortcut.getExtra("screenSize", this.container.getScreenSize()));
                    String dinputMapperType = this.shortcut.getExtra("dinputMapperType");
                    if (!dinputMapperType.isEmpty()) {
                        this.winHandler.gamepadHandler.setDInputMapperType(Byte.parseByte(dinputMapperType));
                    }
                    String preferredInputApi = this.shortcut.getExtra("preferredInputApi");
                    if (!preferredInputApi.isEmpty()) {
                        preferredInputApiIdx3 = Byte.parseByte(preferredInputApi);
                    }
                    this.win32AppWorkarounds.applyStartupWorkarounds(!this.shortcut.wmClass.isEmpty() ? this.shortcut.wmClass : this.shortcut.path);
                    preferredInputApiIdx = preferredInputApiIdx3;
                    graphicsDriverConfig = graphicsDriverConfig2;
                } else {
                    Intent intent = getIntent();
                    if (intent.hasExtra("exec_path")) {
                        this.win32AppWorkarounds.applyStartupWorkarounds(FileUtils.getName(intent.getStringExtra("exec_path")));
                    }
                    preferredInputApiIdx = preferredInputApiIdx2;
                }
                this.graphicsDriver = GraphicsDrivers.parseIdentifiers(graphicsDriver);
                this.graphicsDriverConfig = GraphicsDrivers.parseConfigs(graphicsDriver, graphicsDriverConfig);
                this.dxwrapper = DXWrappers.parseIdentifier(dxwrapper);
                this.dxwrapperConfig = DXWrappers.parseConfigs(dxwrapper, dxwrapperConfig);
                this.winHandler.gamepadHandler.setPreferredInputApi(GamepadHandler.PreferredInputApi.values()[preferredInputApiIdx]);
            } else {
                preloaderDialog.lambda$showOnUiThread$0(R.string.updating_system_files);
                WineUtils.updateWineprefix(this, new Callback() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda2
                    @Override // com.winlator.core.Callback
                    public final void call(Object obj) {
                        this.f$0.lambda$onCreate$1((Integer) obj);
                    }
                });
                return;
            }
        }
        preloaderDialog.lambda$showOnUiThread$0(R.string.starting_up);
        this.inputControlsManager = new InputControlsManager(this);
        XServer xServer = new XServer(this, this.screenInfo);
        this.xServer = xServer;
        xServer.setWinHandler(this.winHandler);
        final boolean[] flags = new boolean[2];
        flags[0] = false;
        flags[1] = this.shortcut != null || getIntent().hasExtra("exec_path");
        this.xServer.windowManager.addOnWindowModificationListener(new WindowManager.OnWindowModificationListener() { // from class: com.winlator.XServerDisplayActivity.1
            @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
            public void onUpdateWindowContent(Window window) {
                if (window.id == XServerDisplayActivity.this.frameRatingWindowId) {
                    XServerDisplayActivity.this.frameRating.update();
                }
            }

            @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
            public void onMapWindow(Window window) {
                if (!flags[0] && window.isRenderable() && !window.getClassName().isEmpty()) {
                    XServerDisplayActivity.this.xServerView.getRenderer().setCursorVisible(true);
                    preloaderDialog.closeOnUiThread();
                    flags[0] = true;
                }
                if (flags[1] && window.attributes.isViewable() && window.isDesktopWindow()) {
                    window.attributes.setViewable(false);
                    if (window.attributes.isEnabled()) {
                        window.disableAllDescendants();
                    }
                }
                if (XServerDisplayActivity.this.win32AppWorkarounds != null) {
                    XServerDisplayActivity.this.win32AppWorkarounds.applyWindowWorkarounds(window);
                }
                XServerDisplayActivity.this.changeFrameRatingVisibility(window, true);
            }

            @Override // com.winlator.xserver.WindowManager.OnWindowModificationListener
            public void onUnmapWindow(Window window) {
                XServerDisplayActivity.this.changeFrameRatingVisibility(window, false);
            }
        });
        setupUI();
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda9
            @Override // java.lang.Runnable
            public final void run() throws Throwable {
                this.f$0.lambda$onCreate$2();
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ WindowInsets lambda$onCreate$0(View view, WindowInsets windowInsets) {
        return windowInsets.replaceSystemWindowInsets(0, 0, 0, 0);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$onCreate$1(Integer status) {
        if (status.intValue() == 0) {
            this.container.putExtra("wineprefixNeedsUpdate", null);
            this.container.putExtra("wincomponents", null);
            this.container.saveData();
            AppUtils.restartActivity(this);
            return;
        }
        finish();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$onCreate$2() throws Throwable {
        if (!isGenerateWineprefix()) {
            setupWineSystemFiles();
            extractGraphicsDriverFiles();
            changeWineAudioDriver();
        }
        setupXEnvironment();
    }

    @Override // androidx.appcompat.app.AppCompatActivity, android.app.Activity, android.view.ContextThemeWrapper, android.content.ContextWrapper
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(LocaleHelper.setSystemLocale(newBase));
    }

    @Override // androidx.fragment.app.FragmentActivity, androidx.activity.ComponentActivity, android.app.Activity
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        Runnable runnable;
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == 3 && resultCode == -1 && (runnable = this.editInputControlsCallback) != null) {
            runnable.run();
            this.editInputControlsCallback = null;
        }
    }

    @Override // android.app.Activity, android.view.Window.Callback
    public void onWindowFocusChanged(boolean hasFocus) {
        ClipboardManager clipboardManager;
        ClipData primaryClip;
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            if (this.capturePointerOnExternalMouse) {
                this.touchpadView.requestPointerCapture();
            }
            if (this.winHandler != null && (clipboardManager = this.clipboardManager) != null && clipboardManager.hasPrimaryClip() && (primaryClip = this.clipboardManager.getPrimaryClip()) != null && primaryClip.getItemCount() > 0) {
                this.winHandler.setClipboardData(primaryClip.getItemAt(0).getText().toString());
            }
        }
    }

    @Override // androidx.fragment.app.FragmentActivity, android.app.Activity
    public void onResume() {
        super.onResume();
        if (this.environment != null) {
            this.xServerView.onResume();
            this.environment.onResume();
        }
    }

    @Override // androidx.fragment.app.FragmentActivity, android.app.Activity
    public void onPause() {
        super.onPause();
        if (this.environment != null && !isInPictureInPictureMode()) {
            this.environment.onPause();
            this.xServerView.onPause();
        }
    }

    @Override // androidx.appcompat.app.AppCompatActivity, androidx.fragment.app.FragmentActivity, android.app.Activity
    protected void onDestroy() {
        this.winHandler.stop();
        XEnvironment xEnvironment = this.environment;
        if (xEnvironment != null) {
            xEnvironment.stopEnvironmentComponents();
        }
        super.onDestroy();
    }

    @Override // androidx.activity.ComponentActivity, android.app.Activity
    public void onBackPressed() {
        if (this.environment != null) {
            if (!this.drawerLayout.isDrawerOpen(8388611)) {
                this.drawerLayout.openDrawer(8388611);
            } else {
                this.drawerLayout.closeDrawers();
            }
        }
    }

    @Override // com.google.android.material.navigation.NavigationView.OnNavigationItemSelectedListener
    public boolean onNavigationItemSelected(MenuItem item) {
        final GLRenderer renderer = this.xServerView.getRenderer();
        switch (item.getItemId()) {
            case R.id.menu_item_active_windows /* 2131296722 */:
                new ActiveWindowsDialog(this).show();
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_exit /* 2131296734 */:
                exit();
                break;
            case R.id.menu_item_input_controls /* 2131296738 */:
                showInputControlsDialog();
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_keyboard /* 2131296740 */:
                AppUtils.showKeyboard(this);
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_logs /* 2131296742 */:
                this.debugDialog.show();
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_magnifier /* 2131296743 */:
                if (this.magnifierView == null) {
                    final FrameLayout container = (FrameLayout) findViewById(R.id.FLXServerDisplay);
                    MagnifierView magnifierView = new MagnifierView(this);
                    this.magnifierView = magnifierView;
                    magnifierView.setZoomButtonCallback(new Callback() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda4
                        @Override // com.winlator.core.Callback
                        public final void call(Object obj) {
                            this.f$0.lambda$onNavigationItemSelected$3(renderer, (Float) obj);
                        }
                    });
                    this.magnifierView.setZoomValue(renderer.getMagnifierZoom());
                    this.magnifierView.setHideButtonCallback(new Runnable() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda12
                        @Override // java.lang.Runnable
                        public final void run() {
                            this.f$0.lambda$onNavigationItemSelected$4(container);
                        }
                    });
                    container.addView(this.magnifierView);
                }
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_pip_mode /* 2131296747 */:
                PictureInPictureParams pipParams = new PictureInPictureParams.Builder().setAspectRatio(this.screenInfo.aspectRatio()).build();
                enterPictureInPictureMode(pipParams);
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_screen_effect /* 2131296751 */:
                new ScreenEffectDialog(this).show();
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_task_manager /* 2131296754 */:
                new TaskManagerDialog(this).show();
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_toggle_fullscreen /* 2131296755 */:
                renderer.toggleFullscreen();
                this.drawerLayout.closeDrawers();
                break;
            case R.id.menu_item_touchpad_help /* 2131296756 */:
                showTouchpadHelpDialog();
                break;
        }
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$onNavigationItemSelected$3(GLRenderer renderer, Float value) {
        renderer.setMagnifierZoom(Mathf.clamp(renderer.getMagnifierZoom() + value.floatValue(), 1.0f, 3.0f));
        this.magnifierView.setZoomValue(renderer.getMagnifierZoom());
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$onNavigationItemSelected$4(FrameLayout container) {
        container.removeView(this.magnifierView);
        this.magnifierView = null;
    }

    public SharedPreferences getPreferences() {
        return this.preferences;
    }

    private void exit() {
        this.winHandler.stop();
        XEnvironment xEnvironment = this.environment;
        if (xEnvironment != null) {
            xEnvironment.stopEnvironmentComponents();
        }
        Intent intent = getIntent();
        if (intent.hasExtra("exec_path")) {
            AppUtils.RestartApplicationOptions options = new AppUtils.RestartApplicationOptions();
            options.containerId = this.container.id;
            options.startPath = FileUtils.getDirname(intent.getStringExtra("exec_path"));
            AppUtils.restartApplication(this, options);
            return;
        }
        AppUtils.restartApplication(this);
    }

    private void setupWineSystemFiles() throws Throwable {
        String appVersion = String.valueOf(AppUtils.getVersionCode(this));
        String rfsVersion = String.valueOf(this.rootFS.getVersion());
        boolean containerDataChanged = false;
        boolean wineprefixWasUpdated = WineUtils.isWineprefixWasUpdated(this.container);
        if (!this.container.getExtra("appVersion").equals(appVersion) || !this.container.getExtra("rfsVersion").equals(rfsVersion) || wineprefixWasUpdated) {
            applyGeneralPatches(this.container);
            this.container.putExtra("appVersion", appVersion);
            this.container.putExtra("rfsVersion", rfsVersion);
            containerDataChanged = true;
        }
        if (verifyUserRegistry()) {
            containerDataChanged = true;
        }
        if (extractDXWrapperFiles()) {
            containerDataChanged = true;
        }
        if (!this.wincomponents.equals(this.container.getExtra("wincomponents"))) {
            extractWinComponentFiles();
            this.container.putExtra("wincomponents", this.wincomponents);
            containerDataChanged = true;
        }
        String desktopTheme = this.container.getDesktopTheme();
        if (!(desktopTheme + "," + this.xServer.screenInfo).equals(this.container.getExtra("desktopTheme"))) {
            WineThemeManager.apply(this, new WineThemeManager.ThemeInfo(desktopTheme), this.xServer.screenInfo);
            this.container.putExtra("desktopTheme", desktopTheme + "," + this.xServer.screenInfo);
            containerDataChanged = true;
        }
        WineStartMenuCreator.create(this, this.container);
        WineUtils.createDosdevicesSymlinks(this.container, true);
        String startupSelection = String.valueOf((int) this.container.getStartupSelection());
        if (!startupSelection.equals(this.container.getExtra("startupSelection")) || wineprefixWasUpdated) {
            Container container = this.container;
            WineUtils.changeServicesStatus(container, container.getStartupSelection() != 0);
            this.container.putExtra("startupSelection", startupSelection);
            containerDataChanged = true;
        }
        boolean openAndroidBrowserFromWine = this.preferences.getBoolean("open_android_browser_from_wine", true);
        String openAndroidBrowserFromWineStr = openAndroidBrowserFromWine ? "t" : "f";
        if (!openAndroidBrowserFromWineStr.equals(this.container.getExtra("openAndroidBrowserFromWine")) || wineprefixWasUpdated) {
            WineUtils.changeBrowsersRegistryKey(this.container, openAndroidBrowserFromWine);
            this.container.putExtra("openAndroidBrowserFromWine", openAndroidBrowserFromWineStr);
            containerDataChanged = true;
        }
        if (containerDataChanged) {
            this.container.saveData();
        }
    }

    private void setupXEnvironment() {
        String str;
        String rootPath = this.rootFS.getRootDir().getPath();
        this.envVars.put("MESA_DEBUG", "silent");
        this.envVars.put("MESA_NO_ERROR", "1");
        this.envVars.put("WINEPREFIX", rootPath + "/home/xuser/.wine");
        this.envVars.put("WINE_DO_NOT_CREATE_DXGI_DEVICE_MANAGER", "1");
        boolean enableWineDebug = this.preferences.getBoolean("enable_wine_debug", false);
        String wineDebugChannels = this.preferences.getString("wine_debug_channels", "warn,err,fixme");
        EnvVars envVars = this.envVars;
        if (!enableWineDebug || wineDebugChannels.isEmpty()) {
            str = "-all";
        } else {
            str = "+" + wineDebugChannels.replace(",", ",+");
        }
        envVars.put("WINEDEBUG", str);
        FileUtils.clear(this.rootFS.getTmpDir());
        GuestProgramLauncherComponent guestProgramLauncherComponent = new GuestProgramLauncherComponent();
        Container container = this.container;
        if (container != null) {
            if (container.getHUDMode() == FrameRating.Mode.FULL.ordinal()) {
                this.envVars.put("X11_WND_GPU_INFO", "1");
            }
            if (this.container.getStartupSelection() == 2) {
                this.winHandler.killProcess("services.exe");
            }
            String desktopName = (this.shortcut != null || getIntent().hasExtra("exec_path")) ? "nogui" : "shell";
            String guestExecutable = "wine explorer /desktop=" + desktopName + "," + this.xServer.screenInfo + " " + getWineStartCommand();
            guestProgramLauncherComponent.setGuestExecutable(guestExecutable);
            this.envVars.putAll(this.container.getEnvVars());
            Shortcut shortcut = this.shortcut;
            if (shortcut != null) {
                this.envVars.putAll(shortcut.getExtra("envVars"));
            }
            if (!this.envVars.has("WINEESYNC")) {
                this.envVars.put("WINEESYNC", "1");
            }
            Shortcut shortcut2 = this.shortcut;
            guestProgramLauncherComponent.setBox64Preset(shortcut2 != null ? shortcut2.getExtra("box64Preset", this.container.getBox64Preset()) : this.container.getBox64Preset());
        }
        XEnvironment xEnvironment = new XEnvironment(this, this.rootFS);
        this.environment = xEnvironment;
        xEnvironment.addComponent(new SysVSharedMemoryComponent(this.xServer, UnixSocketConfig.create(rootPath, "/tmp/.sysvshm/SM0")));
        this.environment.addComponent(new XServerComponent(this.xServer, UnixSocketConfig.create(rootPath, "/tmp/.X11-unix/X0")));
        this.environment.addComponent(new NetworkInfoUpdateComponent());
        if (this.audioDriver.equals("alsa")) {
            this.envVars.put("ANDROID_ALSA_SERVER", rootPath + "/tmp/.sound/AS0");
            this.envVars.put("ANDROID_ASERVER_USE_SHM", "true");
            ALSAClient.Options options = ALSAClient.Options.fromKeyValueSet(this.audioDriverConfig);
            this.environment.addComponent(new ALSAServerComponent(UnixSocketConfig.create(rootPath, "/tmp/.sound/AS0"), options));
        } else if (this.audioDriver.equals("pulseaudio")) {
            PulseAudioComponent pulseAudioComponent = new PulseAudioComponent(UnixSocketConfig.create(rootPath, "/tmp/.sound/PS0"));
            this.envVars.put("PULSE_SERVER", rootPath + "/tmp/.sound/PS0");
            if (!this.audioDriverConfig.isEmpty()) {
                this.envVars.put("PULSE_LATENCY_MSEC", Integer.valueOf(this.audioDriverConfig.getInt("latencyMillis", 16)));
                pulseAudioComponent.setVolume(this.audioDriverConfig.getFloat("volume", 1.0f));
                pulseAudioComponent.setPerformanceMode(this.audioDriverConfig.getInt("performanceMode", 1));
            } else {
                this.envVars.put("PULSE_LATENCY_MSEC", (byte) 16);
            }
            this.environment.addComponent(pulseAudioComponent);
        }
        if (this.graphicsDriver[0].equals("vortek")) {
            VortekRendererComponent.Options options2 = VortekRendererComponent.Options.fromKeyValueSet(this, this.graphicsDriverConfig[0]);
            VortekRendererComponent vortekRendererComponent = new VortekRendererComponent(this.xServer, UnixSocketConfig.create(rootPath, "/tmp/.vortek/V0"), options2);
            this.environment.addComponent(vortekRendererComponent);
        }
        if (this.graphicsDriver[1].equals("virgl")) {
            this.environment.addComponent(new VirGLRendererComponent(this.xServer, UnixSocketConfig.create(rootPath, "/tmp/.virgl/V0")));
        }
        guestProgramLauncherComponent.setEnvVars(this.envVars);
        guestProgramLauncherComponent.setTerminationCallback(new Callback() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda3
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                this.f$0.lambda$setupXEnvironment$5((Integer) obj);
            }
        });
        this.environment.addComponent(guestProgramLauncherComponent);
        if (isGenerateWineprefix()) {
            WineInfo wineInfo = (WineInfo) getIntent().getParcelableExtra("wine_info");
            this.wineInfo = wineInfo;
            if (wineInfo != null) {
                WineInstaller.generateWineprefix(wineInfo, this.environment);
            }
        }
        EnvVars envVars2 = this.overrideEnvVars;
        if (envVars2 != null) {
            this.envVars.putAll(envVars2);
            this.overrideEnvVars = null;
        }
        this.environment.startEnvironmentComponents();
        this.winHandler.start();
        this.envVars.clear();
        this.graphicsDriver = null;
        this.dxwrapperConfig = null;
        this.graphicsDriverConfig = null;
        this.audioDriver = null;
        this.audioDriverConfig = null;
        this.wincomponents = null;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$setupXEnvironment$5(Integer status) {
        exit();
    }

    private void setupUI() {
        ControlsProfile profile;
        FrameLayout rootView = (FrameLayout) findViewById(R.id.FLXServerDisplay);
        XServerView xServerView = new XServerView(this, this.xServer);
        this.xServerView = xServerView;
        final GLRenderer renderer = xServerView.getRenderer();
        renderer.setCursorVisible(false);
        renderer.setCursorColor(this.preferences.getInt("cursor_color", 16777215));
        renderer.setCursorScale(this.preferences.getFloat("cursor_scale", 1.0f));
        Shortcut shortcut = this.shortcut;
        renderer.setForceWindowsFullscreen(shortcut != null && shortcut.getExtra("forceFullscreen", "0").equals("1"));
        this.xServer.setRenderer(renderer);
        rootView.addView(this.xServerView);
        this.globalCursorSpeed = this.preferences.getFloat("cursor_speed", 1.0f);
        this.capturePointerOnExternalMouse = this.preferences.getBoolean("capture_pointer_on_external_mouse", true);
        TouchpadView touchpadView = new TouchpadView(this, this.xServer, this.capturePointerOnExternalMouse);
        this.touchpadView = touchpadView;
        touchpadView.setSensitivity(this.globalCursorSpeed);
        this.touchpadView.setMoveCursorToTouchpoint(this.preferences.getBoolean("move_cursor_to_touchpoint", false));
        this.touchpadView.setFourFingersTapCallback(new Runnable() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda8
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$setupUI$6();
            }
        });
        rootView.addView(this.touchpadView);
        InputControlsView inputControlsView = new InputControlsView(this);
        this.inputControlsView = inputControlsView;
        inputControlsView.setOverlayOpacity(this.preferences.getFloat("overlay_opacity", 0.4f));
        this.inputControlsView.setTouchpadView(this.touchpadView);
        this.inputControlsView.setXServer(this.xServer);
        this.inputControlsView.setVisibility(8);
        rootView.addView(this.inputControlsView);
        Container container = this.container;
        if (container != null && container.getHUDMode() != FrameRating.Mode.DISABLED.ordinal()) {
            FrameRating frameRating = new FrameRating(this);
            this.frameRating = frameRating;
            frameRating.setMode(FrameRating.Mode.values()[this.container.getHUDMode()]);
            this.frameRating.setVisibility(8);
            rootView.addView(this.frameRating);
        }
        Shortcut shortcut2 = this.shortcut;
        if (shortcut2 != null) {
            String controlsProfile = shortcut2.getExtra("controlsProfile");
            if (!controlsProfile.isEmpty() && (profile = this.inputControlsManager.getProfile(Integer.parseInt(controlsProfile))) != null) {
                showInputControls(profile);
            }
        }
        DrawerLayout drawerLayout = this.drawerLayout;
        Objects.requireNonNull(renderer);
        AppUtils.observeSoftKeyboardVisibility(drawerLayout, new Callback() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda5
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                renderer.setScreenOffsetYRelativeToCursor(((Boolean) obj).booleanValue());
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$setupUI$6() {
        if (!this.drawerLayout.isDrawerOpen(8388611)) {
            this.drawerLayout.openDrawer(8388611);
        }
    }

    private void showInputControlsDialog() {
        ContentDialog dialog = new ContentDialog(this, R.layout.input_controls_dialog);
        dialog.setTitle(R.string.input_controls);
        dialog.setIcon(R.drawable.icon_input_controls);
        final Spinner sProfile = (Spinner) dialog.findViewById(R.id.SProfile);
        final Runnable loadProfileSpinner = new Runnable() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda13
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$showInputControlsDialog$7(sProfile);
            }
        };
        loadProfileSpinner.run();
        final CheckBox cbRelativeMouseMovement = (CheckBox) dialog.findViewById(R.id.CBRelativeMouseMovement);
        cbRelativeMouseMovement.setChecked(this.xServer.isRelativeMouseMovement());
        final CheckBox cbShowTouchscreenControls = (CheckBox) dialog.findViewById(R.id.CBShowTouchscreenControls);
        cbShowTouchscreenControls.setChecked(this.inputControlsView.isShowTouchscreenControls());
        dialog.findViewById(R.id.BTSettings).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda1
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                this.f$0.lambda$showInputControlsDialog$9(sProfile, loadProfileSpinner, view);
            }
        });
        dialog.setOnConfirmCallback(new Runnable() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda11
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$showInputControlsDialog$10(cbRelativeMouseMovement, cbShowTouchscreenControls, sProfile);
            }
        });
        dialog.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$showInputControlsDialog$7(Spinner sProfile) {
        ArrayList<ControlsProfile> profiles = this.inputControlsManager.getProfiles(true);
        ArrayList<String> profileItems = new ArrayList<>();
        int selectedPosition = 0;
        profileItems.add("-- " + getString(R.string.disabled) + " --");
        for (int i = 0; i < profiles.size(); i++) {
            ControlsProfile profile = profiles.get(i);
            if (profile == this.inputControlsView.getProfile()) {
                selectedPosition = i + 1;
            }
            profileItems.add(profile.getName());
        }
        sProfile.setAdapter((SpinnerAdapter) new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, profileItems));
        sProfile.setSelection(selectedPosition);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$showInputControlsDialog$9(Spinner sProfile, final Runnable loadProfileSpinner, View v) {
        int position = sProfile.getSelectedItemPosition();
        Intent intent = new Intent(this, (Class<?>) MainActivity.class);
        intent.putExtra("edit_input_controls", true);
        intent.putExtra("selected_profile_id", position > 0 ? this.inputControlsManager.getProfiles().get(position - 1).id : 0);
        this.editInputControlsCallback = new Runnable() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda14
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$showInputControlsDialog$8(loadProfileSpinner);
            }
        };
        startActivityForResult(intent, 3);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$showInputControlsDialog$8(Runnable loadProfileSpinner) {
        hideInputControls();
        this.inputControlsManager.loadProfiles(true);
        loadProfileSpinner.run();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$showInputControlsDialog$10(CheckBox cbRelativeMouseMovement, CheckBox cbShowTouchscreenControls, Spinner sProfile) {
        this.xServer.setRelativeMouseMovement(cbRelativeMouseMovement.isChecked());
        this.inputControlsView.setShowTouchscreenControls(cbShowTouchscreenControls.isChecked());
        int position = sProfile.getSelectedItemPosition();
        if (position > 0) {
            showInputControls(this.inputControlsManager.getProfiles().get(position - 1));
        } else {
            hideInputControls();
        }
    }

    private void showInputControls(ControlsProfile profile) {
        this.inputControlsView.setVisibility(0);
        this.inputControlsView.requestFocus();
        this.inputControlsView.setProfile(profile);
        this.touchpadView.setSensitivity(profile.getCursorSpeed() * this.globalCursorSpeed);
        this.touchpadView.setPointerButtonRightEnabled(false);
        GLRenderer renderer = this.xServerView.getRenderer();
        if (profile.isDisableMouseInput()) {
            renderer.setCursorVisible(false);
            this.touchpadView.setEnabled(false);
        } else {
            renderer.setCursorVisible(true);
            this.touchpadView.setEnabled(true);
        }
        this.inputControlsView.invalidate();
    }

    private void hideInputControls() {
        this.inputControlsView.setShowTouchscreenControls(true);
        this.inputControlsView.setVisibility(8);
        this.inputControlsView.setProfile(null);
        this.touchpadView.setSensitivity(this.globalCursorSpeed);
        this.touchpadView.setPointerButtonLeftEnabled(true);
        this.touchpadView.setPointerButtonRightEnabled(true);
        if (!this.touchpadView.isEnabled()) {
            this.touchpadView.setEnabled(true);
            this.xServerView.getRenderer().setCursorVisible(true);
        }
        this.inputControlsView.invalidate();
    }

    private void extractGraphicsDriverFiles() {
        String cacheId;
        boolean changed;
        File rootDir;
        this.envVars.put("vblank_mode", "0");
        if (this.graphicsDriver[0].equals("turnip")) {
            cacheId = "" + this.graphicsDriver[0] + "-" + this.graphicsDriverConfig[0].get("version", "26.1.0");
        } else {
            cacheId = "" + this.graphicsDriver[0] + "-" + DefaultVersion.valueOf(this.graphicsDriver[0]);
        }
        String cacheId2 = cacheId + "-" + this.graphicsDriver[1] + "-" + DefaultVersion.valueOf(this.graphicsDriver[1]);
        changed = !cacheId2.equals(this.container.getExtra("graphicsDriver"));
        rootDir = this.rootFS.getRootDir();
        File libDir = this.rootFS.getLibDir();
        if (changed) {
            FileUtils.delete(new File(libDir, "libvulkan_freedreno.so"));
            FileUtils.delete(new File(libDir, "libvulkan_vortek.so"));
            FileUtils.delete(new File(libDir, "libGL.so.1.7.0"));
            File vulkanICDDir = new File(rootDir, "/usr/share/vulkan/icd.d");
            FileUtils.delete(vulkanICDDir);
            vulkanICDDir.mkdirs();
            this.container.putExtra("graphicsDriver", cacheId2);
            this.container.saveData();
        }
        if (this.graphicsDriver[0].equals("turnip")) {
            this.envVars.put("MESA_VK_WSI_PRESENT_MODE", "mailbox");
            TurnipConfigDialog.setEnvVars(this, this.graphicsDriverConfig[0], this.envVars);
            if (changed) {
                String version = this.graphicsDriverConfig[0].get("version", "26.1.0");
                GeneralComponents.extractFile(GeneralComponents.Type.TURNIP, this, version, "26.1.0");
            }
        } else if (this.graphicsDriver[0].equals("vortek") && changed) {
            TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "graphics_driver/vortek-2.1.tzst", rootDir);
        }
        switch (this.graphicsDriver[1]) {
            case "zink":
                this.envVars.put("GALLIUM_DRIVER", "zink");
                this.envVars.put("ZINK_CONTEXT_THREADED", "1");
                if (this.graphicsDriver[0].equals("vortek")) {
                    this.envVars.put("MESA_GL_VERSION_OVERRIDE", "3.3");
                }
                if (changed) {
                    TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "graphics_driver/zink-22.2.5.tzst", rootDir);
                    break;
                }
                break;
            case "virgl":
                this.envVars.put("GALLIUM_DRIVER", "virpipe");
                this.envVars.put("VIRGL_NO_READBACK", "true");
                this.envVars.put("VIRGL_SERVER_PATH", rootDir + "/tmp/.virgl/V0");
                VirGLConfigDialog.setEnvVars(this.graphicsDriverConfig[1], this.envVars);
                if (changed) {
                    TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "graphics_driver/virgl-23.1.9.tzst", rootDir);
                    break;
                }
                break;
            case "gladio":
                this.envVars.put("GLADIO_NO_ERROR", "1");
                if (changed) {
                    TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "graphics_driver/gladio-1.0.tzst", rootDir);
                    break;
                }
                break;
        }
    }

    private void showTouchpadHelpDialog() {
        ContentDialog dialog = new ContentDialog(this, R.layout.touchpad_help_dialog);
        dialog.setTitle(R.string.touchpad_help);
        dialog.setIcon(R.drawable.icon_help);
        dialog.findViewById(R.id.BTCancel).setVisibility(8);
        dialog.show();
    }

    @Override // android.app.Activity, android.view.Window.Callback
    public boolean dispatchGenericMotionEvent(MotionEvent event) {
        return (this.winHandler.onGenericMotionEvent(event) || this.touchpadView.onExternalMouseEvent(event) || !super.dispatchGenericMotionEvent(event)) ? false : true;
    }

    @Override // androidx.appcompat.app.AppCompatActivity, androidx.core.app.ComponentActivity, android.app.Activity, android.view.Window.Callback
    public boolean dispatchKeyEvent(KeyEvent event) {
        return !(this.inputControlsView.onKeyEvent(event) || this.winHandler.onKeyEvent(event) || !this.xServer.keyboard.onKeyEvent(event)) || (!ExternalController.isGameController(event.getDevice()) && super.dispatchKeyEvent(event));
    }

    public InputControlsView getInputControlsView() {
        return this.inputControlsView;
    }

    private boolean extractDXWrapperFiles() {
        String cacheId = "";
        if (this.dxwrapper.equals("dxvk")) {
            DXVKConfigDialog.setEnvVars(this, this.dxwrapperConfig[0], this.envVars);
            cacheId = "" + this.dxwrapper + "-" + this.dxwrapperConfig[0].get("version", DefaultVersion.DXVK(this.graphicsDriver[0]));
        } else if (this.dxwrapper.equals("wined3d")) {
            WineD3DConfigDialog.setEnvVars(this.dxwrapperConfig[0], this.envVars);
            cacheId = "" + this.dxwrapper + "-" + this.dxwrapperConfig[0].get("version", "10.10");
        }
        String ddrawWrapper = this.dxwrapperConfig[0].get("ddrawWrapper", "wined3d");
        String cacheId2 = cacheId + "-vkd3d-" + this.dxwrapperConfig[1].get("version", "2.14.1") + "-" + ddrawWrapper;
        boolean changed = !cacheId2.equals(this.container.getExtra("dxwrapper"));
        VKD3DConfigDialog.setEnvVars(this.dxwrapperConfig[1], this.envVars);
        if (ddrawWrapper.equals("cnc-ddraw")) {
            this.envVars.put("CNC_DDRAW_CONFIG_FILE", "C:\\ProgramData\\cnc-ddraw\\ddraw.ini");
        }
        if (!changed) {
            return false;
        }
        this.container.putExtra("dxwrapper", cacheId2);
        File rootDir = this.rootFS.getRootDir();
        File windowsDir = new File(rootDir, "/home/xuser/.wine/drive_c/windows");
        if (this.dxwrapper.equals("wined3d")) {
            String version = this.dxwrapperConfig[0].get("version", "10.10");
            if (!version.equals("10.10")) {
                GeneralComponents.extractFile(GeneralComponents.Type.WINED3D, this, version, "10.10");
            } else {
                String[] dlls = {"d3d8.dll", "d3d9.dll", "d3d10.dll", "d3d10_1.dll", "d3d10core.dll", "d3d11.dll", "d3d12.dll", "d3d12core.dll", "dxgi.dll", "ddraw.dll", "wined3d.dll"};
                restoreBuiltinDllFiles(dlls);
            }
        } else if (this.dxwrapper.equals("dxvk")) {
            final boolean[] hasD3D8DllFile = {false};
            final boolean[] hasD3D10DllFile = {false};
            GeneralComponents.extractFile(GeneralComponents.Type.DXVK, this, this.dxwrapperConfig[0].get("version"), DefaultVersion.DXVK(this.graphicsDriver[0]), new TarCompressorUtils.OnExtractFileListener() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda6
                @Override // com.winlator.core.TarCompressorUtils.OnExtractFileListener
                public final File onExtractFile(File file, long j) {
                    return XServerDisplayActivity.lambda$extractDXWrapperFiles$11(hasD3D10DllFile, hasD3D8DllFile, file, j);
                }
            });
            if (!hasD3D8DllFile[0]) {
                TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "dxwrapper/d8vk-1.0.tzst", windowsDir);
            }
            if (!hasD3D10DllFile[0]) {
                restoreBuiltinDllFiles("d3d10.dll", "d3d10_1.dll");
            }
        }
        GeneralComponents.extractFile(GeneralComponents.Type.VKD3D, this, this.dxwrapperConfig[1].get("version"), "2.14.1");
        if (!ddrawWrapper.equals("cnc-ddraw")) {
            restoreBuiltinDllFiles("ddraw.dll");
            return true;
        }
        File configFile = new File(rootDir, "/home/xuser/.wine/drive_c/ProgramData/cnc-ddraw/ddraw.ini");
        if (!configFile.isFile()) {
            FileUtils.copy(this, "dxwrapper/cnc-ddraw-6.6/ddraw.ini", configFile);
        }
        File shadersDir = new File(rootDir, "/home/xuser/.wine/drive_c/ProgramData/cnc-ddraw/Shaders");
        FileUtils.delete(shadersDir);
        FileUtils.copy(this, "dxwrapper/cnc-ddraw-6.6/Shaders", shadersDir);
        TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "dxwrapper/cnc-ddraw-6.6/ddraw.tzst", windowsDir);
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ File lambda$extractDXWrapperFiles$11(boolean[] hasD3D10DllFile, boolean[] hasD3D8DllFile, File destination, long size) {
        String name = destination.getName();
        if (name.equals("d3d10.dll")) {
            hasD3D10DllFile[0] = true;
        } else if (name.equals("d3d8.dll")) {
            hasD3D8DllFile[0] = true;
        }
        return destination;
    }

    private void extractWinComponentFiles() {
        JSONObject wincomponentsJSONObject;
        JSONObject wincomponentsJSONObject2;
        String string;
        File rootDir = this.rootFS.getRootDir();
        File windowsDir = new File(rootDir, "/home/xuser/.wine/drive_c/windows");
        File systemRegFile = new File(rootDir, "/home/xuser/.wine/system.reg");
        try {
            JSONObject wincomponentsJSONObject3 = new JSONObject(FileUtils.readString(this, "wincomponents/wincomponents.json"));
            Iterator<String[]> oldWinComponentsIter = new KeyValueSet(this.container.getExtra("wincomponents", "direct3d=0,directsound=0,directmusic=0,directshow=0,directplay=0,xaudio=0,vcrun2005=0,vcrun2010=0,wmdecoder=0")).iterator();
            ArrayList<String> builtinDlls = new ArrayList<>();
            for (String[] wincomponent : new KeyValueSet(this.wincomponents)) {
                if (!wincomponent[1].equals(oldWinComponentsIter.next()[1])) {
                    String identifier = wincomponent[0];
                    boolean useNative = wincomponent[1].equals("1");
                    if (useNative) {
                        TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "wincomponents/" + identifier + ".tzst", windowsDir);
                        wincomponentsJSONObject = wincomponentsJSONObject3;
                    } else {
                        JSONObject wincomponentJSONObject = wincomponentsJSONObject3.getJSONObject(identifier);
                        if (wincomponentJSONObject.getBoolean("restoreBuiltinDlls")) {
                            JSONArray dlnames = wincomponentJSONObject.getJSONArray("dlnames");
                            int i = 0;
                            while (i < dlnames.length()) {
                                String dlname = dlnames.getString(i);
                                if (dlname.endsWith(".exe")) {
                                    wincomponentsJSONObject2 = wincomponentsJSONObject3;
                                    string = dlname;
                                } else {
                                    StringBuilder sb = new StringBuilder();
                                    sb.append(dlname);
                                    wincomponentsJSONObject2 = wincomponentsJSONObject3;
                                    sb.append(".dll");
                                    string = sb.toString();
                                }
                                builtinDlls.add(string);
                                i++;
                                wincomponentsJSONObject3 = wincomponentsJSONObject2;
                            }
                            wincomponentsJSONObject = wincomponentsJSONObject3;
                        } else {
                            wincomponentsJSONObject = wincomponentsJSONObject3;
                            TarCompressorUtils.extract(TarCompressorUtils.Type.ZSTD, this, "wincomponents/" + identifier + ".tzst", windowsDir, new TarCompressorUtils.OnExtractFileListener() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda7
                                @Override // com.winlator.core.TarCompressorUtils.OnExtractFileListener
                                public final File onExtractFile(File file, long j) {
                                    return XServerDisplayActivity.lambda$extractWinComponentFiles$12(file, j);
                                }
                            });
                        }
                    }
                    WineUtils.setWinComponentRegistryKeys(systemRegFile, identifier, useNative);
                    wincomponentsJSONObject3 = wincomponentsJSONObject;
                }
            }
            if (!builtinDlls.isEmpty()) {
                restoreBuiltinDllFiles((String[]) builtinDlls.toArray(new String[0]));
            }
            WineUtils.overrideWinComponentDlls(this, this.container, this.wincomponents);
        } catch (JSONException e) {
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ File lambda$extractWinComponentFiles$12(File destination, long size) {
        String name = destination.getName();
        if (name.endsWith(".dll") || name.endsWith(".manifest") || name.endsWith("_deadbeef")) {
            FileUtils.delete(destination);
            return null;
        }
        return null;
    }

    private void restoreBuiltinDllFiles(String... dlls) {
        File rootDir = this.rootFS.getRootDir();
        File wineDir = new File(rootDir, this.rootFS.getWinePath());
        File wineSystem32Dir = new File(wineDir, "/lib/wine/x86_64-windows");
        File wineSysWoW64Dir = new File(wineDir, "/lib/wine/i386-windows");
        File containerSystem32Dir = new File(rootDir, "/home/xuser/.wine/drive_c/windows/system32");
        File containerSysWoW64Dir = new File(rootDir, "/home/xuser/.wine/drive_c/windows/syswow64");
        for (String dll : dlls) {
            FileUtils.copy(new File(wineSysWoW64Dir, dll), new File(containerSysWoW64Dir, dll));
            FileUtils.copy(new File(wineSystem32Dir, dll), new File(containerSystem32Dir, dll));
        }
    }

    private boolean isGenerateWineprefix() {
        return getIntent().getBooleanExtra("generate_wineprefix", false);
    }

    private String getWineStartCommand() {
        int spaceIndex;
        String str;
        String cmdArgs = "";
        String execPath = null;
        String execArgs = "";
        Shortcut shortcut = this.shortcut;
        if (shortcut != null) {
            String execArgs2 = shortcut.getExtra("execArgs");
            if (execArgs2.isEmpty()) {
                str = "";
            } else {
                str = " " + execArgs2;
            }
            execArgs = str;
            if (this.shortcut.path.endsWith(".lnk") || this.shortcut.path.contains("://")) {
                cmdArgs = "\"" + this.shortcut.path + "\"" + execArgs;
            } else {
                execPath = this.shortcut.path;
            }
        } else {
            Intent intent = getIntent();
            if (intent.hasExtra("exec_path")) {
                execPath = WineUtils.unixToDOSPath(intent.getStringExtra("exec_path"), this.container);
                if (execPath.endsWith(".lnk")) {
                    cmdArgs = "\"" + execPath + "\"";
                    execPath = null;
                }
            }
        }
        if (execPath != null) {
            String execDir = FileUtils.getDirname(execPath);
            String filename = FileUtils.getName(execPath);
            int dotIndex = filename.lastIndexOf(".");
            if (dotIndex != -1 && (spaceIndex = filename.indexOf(" ", dotIndex)) != -1) {
                execArgs = filename.substring(spaceIndex + 1) + execArgs;
                filename = filename.substring(0, spaceIndex);
            }
            cmdArgs = "/dir " + StringUtils.escapeDOSPath(execDir) + " \"" + filename + "\"" + execArgs;
        }
        if (cmdArgs.isEmpty()) {
            cmdArgs = "/dir C:\\windows \"wfm.exe\"";
        }
        EnvVars envVars = this.overrideEnvVars;
        if (envVars != null && envVars.has("EXTRA_EXEC_ARGS")) {
            cmdArgs = cmdArgs + " " + this.overrideEnvVars.get("EXTRA_EXEC_ARGS");
            this.overrideEnvVars.remove("EXTRA_EXEC_ARGS");
        }
        return "C:\\windows\\winhandler.exe " + cmdArgs;
    }

    public XServer getXServer() {
        return this.xServer;
    }

    public WinHandler getWinHandler() {
        return this.winHandler;
    }

    public XServerView getXServerView() {
        return this.xServerView;
    }

    public Container getContainer() {
        return this.container;
    }

    public EnvVars getOverrideEnvVars() {
        if (this.overrideEnvVars == null) {
            this.overrideEnvVars = new EnvVars();
        }
        return this.overrideEnvVars;
    }

    public void setDXWrapper(String dxwrapper) {
        this.dxwrapper = dxwrapper;
    }

    public ScreenInfo getScreenInfo() {
        return this.screenInfo;
    }

    public void setScreenInfo(ScreenInfo screenInfo) {
        this.screenInfo = screenInfo;
    }

    public void setWinComponents(String wincomponents) {
        this.wincomponents = wincomponents;
    }

    public DebugDialog getDebugDialog() {
        return this.debugDialog;
    }

    public String getScreenEffectProfile() {
        return this.screenEffectProfile;
    }

    public void setScreenEffectProfile(String screenEffectProfile) {
        this.screenEffectProfile = screenEffectProfile;
    }

    private void changeWineAudioDriver() {
        if (!this.audioDriver.equals(this.container.getExtra("audioDriver"))) {
            File rootDir = this.rootFS.getRootDir();
            File userRegFile = new File(rootDir, "/home/xuser/.wine/user.reg");
            WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile);
            try {
                if (this.audioDriver.equals("alsa")) {
                    registryEditor.setStringValue("Software\\Wine\\Drivers", "Audio", "alsa");
                } else if (this.audioDriver.equals("pulseaudio")) {
                    registryEditor.setStringValue("Software\\Wine\\Drivers", "Audio", "pulse");
                }
                registryEditor.close();
                this.container.putExtra("audioDriver", this.audioDriver);
                this.container.saveData();
            } catch (Throwable th) {
                try {
                    registryEditor.close();
                } catch (Throwable th2) {
                    th.addSuppressed(th2);
                }
                throw th;
            }
        }
    }

    private void applyGeneralPatches(Container container) {
        File rootDir = this.rootFS.getRootDir();
        FileUtils.delete(new File(rootDir, "/opt/apps"));
        TarCompressorUtils.Type type = TarCompressorUtils.Type.ZSTD;
        TarCompressorUtils.extract(type, this, "rootfs_patches.tzst", rootDir);
        TarCompressorUtils.extract(type, this, "pulseaudio.tzst", new File(getFilesDir(), "pulseaudio"));
        WineUtils.applySystemTweaks(this, this.wineInfo);
        container.putExtra("graphicsDriver", null);
        container.putExtra("dxwrapper", null);
        container.putExtra("desktopTheme", null);
        SettingsFragment.resetBox64Version(this);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void changeFrameRatingVisibility(Window window, boolean visible) {
        if (this.frameRating == null) {
            return;
        }
        if (visible) {
            boolean viewable = false;
            Window child = window.getChildCount() > 0 ? window.getChildren().get(0) : null;
            if (window.attributes.isMapped() && window.getWidth() >= 320 && window.getHeight() >= 200) {
                viewable = true;
            }
            if (viewable) {
                if (window.isSurface() || (child != null && child.isSurface())) {
                    Window frameRatingWindow = window.isSurface() ? window : child;
                    if (this.frameRating.getMode() == FrameRating.Mode.FULL) {
                        Property gpuInfo = frameRatingWindow.getProperty(75);
                        this.frameRating.setGPUInfo(gpuInfo != null ? new String(gpuInfo.data.array()) : "N/A");
                    }
                    this.frameRatingWindowId = frameRatingWindow.id;
                    this.frameRating.reset();
                    return;
                }
                return;
            }
            return;
        }
        if (window.id == this.frameRatingWindowId) {
            this.frameRatingWindowId = -1;
            runOnUiThread(new Runnable() { // from class: com.winlator.XServerDisplayActivity$$ExternalSyntheticLambda10
                @Override // java.lang.Runnable
                public final void run() {
                    this.f$0.lambda$changeFrameRatingVisibility$13();
                }
            });
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$changeFrameRatingVisibility$13() {
        this.frameRating.setVisibility(8);
    }

    public boolean verifyUserRegistry() {
        File userRegFile = new File(this.rootFS.getRootDir(), "/home/xuser/.wine/user.reg");
        String lastModified = String.valueOf(userRegFile.lastModified());
        if (!lastModified.equals(this.container.getExtra("userRegLastModified"))) {
            WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile);
            try {
                registryEditor.removeKey("Software\\Wow6432Node\\Wine", true);
                registryEditor.close();
                this.container.putExtra("userRegLastModified", lastModified);
                return true;
            } catch (Throwable th) {
                try {
                    registryEditor.close();
                } catch (Throwable th2) {
                    th.addSuppressed(th2);
                }
                throw th;
            }
        }
        return false;
    }
}
