package com.winlator;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SubMenu;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.PopupMenu;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.preference.PreferenceManager;
import com.winlator.box64.Box64PresetManager;
import com.winlator.container.Container;
import com.winlator.container.ContainerManager;
import com.winlator.container.DXWrapperPicker;
import com.winlator.container.Drive;
import com.winlator.container.GraphicsDriverPicker;
import com.winlator.container.GraphicsDrivers;
import com.winlator.contentdialog.AddEnvVarDialog;
import com.winlator.contentdialog.AudioDriverConfigDialog;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import com.winlator.core.EnvVars;
import com.winlator.core.FileUtils;
import com.winlator.core.KeyValueSet;
import com.winlator.core.PreloaderDialog;
import com.winlator.core.StringUtils;
import com.winlator.core.WineInfo;
import com.winlator.core.WineInstaller;
import com.winlator.core.WineRegistryEditor;
import com.winlator.core.WineThemeManager;
import com.winlator.core.WineUtils;
import com.winlator.widget.CPUListView;
import com.winlator.widget.ColorPickerView;
import com.winlator.widget.EnvVarsView;
import com.winlator.widget.FrameRating;
import com.winlator.widget.ImagePickerView;
import com.winlator.widget.SeekBar;
import com.winlator.win32.MSLogFont;
import com.winlator.win32.WinVersions;
import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ContainerDetailFragment extends Fragment {
    private Container container;
    private final int containerId;
    private ContainerManager manager;
    private Callback<String> openDirectoryCallback;
    private PreloaderDialog preloaderDialog;

    public ContainerDetailFragment() {
        this(0);
    }

    public ContainerDetailFragment(int containerId) {
        this.containerId = containerId;
    }

    @Override // androidx.fragment.app.Fragment
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setHasOptionsMenu(false);
        this.preloaderDialog = new PreloaderDialog(getActivity());
    }

    @Override // androidx.fragment.app.Fragment
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        String path;
        Callback<String> callback;
        if (requestCode == 4 && resultCode == -1) {
            if (data != null && (path = FileUtils.getFilePathFromUri(data.getData())) != null && (callback = this.openDirectoryCallback) != null) {
                callback.call(path);
            }
            this.openDirectoryCallback = null;
        }
    }

    @Override // androidx.fragment.app.Fragment
    public void onViewCreated(View view, Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        ((AppCompatActivity) getActivity()).getSupportActionBar().setTitle(isEditMode() ? R.string.edit_container : R.string.new_container);
    }

    public boolean isEditMode() {
        return this.container != null;
    }

    @Override // androidx.fragment.app.Fragment
    public View onCreateView(LayoutInflater inflater, ViewGroup root, Bundle savedInstanceState) {
        View vAudioDriverConfig;
        int iOrdinal;
        Spinner sStartupSelection;
        GraphicsDriverPicker graphicsDriverPicker;
        String string;
        Spinner sBox64Preset;
        String fallbackCPUList;
        final Context context = getContext();
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        final View view = inflater.inflate(R.layout.container_detail_fragment, root, false);
        ContainerManager containerManager = new ContainerManager(context);
        this.manager = containerManager;
        int i = this.containerId;
        this.container = i > 0 ? containerManager.getContainerById(i) : null;
        final EditText etName = (EditText) view.findViewById(R.id.ETName);
        if (isEditMode()) {
            etName.setText(this.container.getName());
        } else {
            etName.setText(getString(R.string.container) + "-" + this.manager.getNextContainerId());
        }
        final ArrayList<WineInfo> wineInfos = WineInstaller.getInstalledWineInfos(context);
        final Spinner sWineVersion = (Spinner) view.findViewById(R.id.SWineVersion);
        if (wineInfos.size() > 1) {
            loadWineVersionSpinner(view, sWineVersion, wineInfos);
        }
        loadScreenSizeSpinner(view, isEditMode() ? this.container.getScreenSize() : "1280x720");
        final String oldGraphicsDriverConfig = isEditMode() ? this.container.getGraphicsDriverConfig() : "";
        String selectedGraphicsDriver = isEditMode() ? this.container.getGraphicsDriver() : GraphicsDrivers.getDefaultDriver(context);
        GraphicsDriverPicker graphicsDriverPicker2 = new GraphicsDriverPicker((LinearLayout) view.findViewById(R.id.LLGraphicsDriver), selectedGraphicsDriver, oldGraphicsDriverConfig);
        String oldDXWrapperConfig = isEditMode() ? this.container.getDXWrapperConfig() : "";
        String selectedDXWrapper = isEditMode() ? this.container.getDXWrapper() : "dxvk";
        final DXWrapperPicker dxwrapperPicker = new DXWrapperPicker((LinearLayout) view.findViewById(R.id.LLDXWrapper), graphicsDriverPicker2, selectedDXWrapper, oldDXWrapperConfig);
        view.findViewById(R.id.BTHelpDXWrapper).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerDetailFragment$$ExternalSyntheticLambda0
            @Override // android.view.View.OnClickListener
            public final void onClick(View view2) {
                AppUtils.showHelpBox(context, view2, R.string.dxwrapper_help_content);
            }
        });
        final Spinner sAudioDriver = (Spinner) view.findViewById(R.id.SAudioDriver);
        AppUtils.setSpinnerSelectionFromIdentifier(sAudioDriver, isEditMode() ? this.container.getAudioDriver() : "alsa");
        View vAudioDriverConfig2 = view.findViewById(R.id.BTAudioDriverConfig);
        String oldDXWrapperConfig2 = isEditMode() ? this.container.getAudioDriverConfig() : "";
        vAudioDriverConfig2.setTag(oldDXWrapperConfig2);
        vAudioDriverConfig2.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerDetailFragment$$ExternalSyntheticLambda6
            @Override // android.view.View.OnClickListener
            public final void onClick(View view2) {
                ContainerDetailFragment.lambda_onCreateView_1(view2);
            }
        });
        final Spinner sHUDMode = (Spinner) view.findViewById(R.id.SHUDMode);
        if (isEditMode()) {
            vAudioDriverConfig = vAudioDriverConfig2;
            iOrdinal = this.container.getHUDMode();
        } else {
            vAudioDriverConfig = vAudioDriverConfig2;
            iOrdinal = FrameRating.Mode.DISABLED.ordinal();
        }
        sHUDMode.setSelection(iOrdinal);
        Spinner sStartupSelection2 = (Spinner) view.findViewById(R.id.SStartupSelection);
        byte oldStartupSelection = isEditMode() ? this.container.getStartupSelection() : (byte) -1;
        sStartupSelection2.setSelection(oldStartupSelection != -1 ? oldStartupSelection : (byte) 1);
        final Spinner sWinVersion = (Spinner) view.findViewById(R.id.SWinVersion);
        sWinVersion.setTag((byte) -1);
        Spinner sBox64Preset2 = (Spinner) view.findViewById(R.id.SBox64Preset);
        if (isEditMode()) {
            sStartupSelection = sStartupSelection2;
            string = this.container.getBox64Preset();
            graphicsDriverPicker = graphicsDriverPicker2;
        } else {
            sStartupSelection = sStartupSelection2;
            graphicsDriverPicker = graphicsDriverPicker2;
            string = preferences.getString("box64_preset", "INTERMEDIATE");
        }
        Box64PresetManager.loadSpinner(sBox64Preset2, string);
        final CPUListView cpuListView = (CPUListView) view.findViewById(R.id.CPUListView);
        final CPUListView cpuListViewWoW64 = (CPUListView) view.findViewById(R.id.CPUListViewWoW64);
        if (isEditMode()) {
            sBox64Preset = sBox64Preset2;
            fallbackCPUList = this.container.getCPUList(true);
        } else {
            sBox64Preset = sBox64Preset2;
            fallbackCPUList = Container.getFallbackCPUList();
        }
        cpuListView.setCheckedCPUList(fallbackCPUList);
        cpuListViewWoW64.setCheckedCPUList(isEditMode() ? this.container.getCPUListWoW64(true) : Container.getFallbackCPUListWoW64());
        createWineConfigurationTab(view);
        final EnvVarsView envVarsView = createEnvVarsTab(view);
        createWinComponentsTab(view, isEditMode() ? this.container.getWinComponents() : "direct3d=1,directsound=1,directmusic=1,directshow=0,directplay=0,xaudio=1,vcrun2005=0,vcrun2010=1,wmdecoder=1");
        createDrivesTab(view);
        AppUtils.setupTabLayout(view, R.id.TabLayout, (Callback<Integer>) tabResId -> lambda_onCreateView_2(sWinVersion, tabResId), R.id.LLTabWineConfiguration, R.id.LLTabWinComponents, R.id.LLTabEnvVars, R.id.LLTabDrives, R.id.LLTabAdvanced);
        final Spinner sStartupSelection3 = sStartupSelection;
        final View vAudioDriverConfig3 = vAudioDriverConfig;
        final GraphicsDriverPicker graphicsDriverPicker3 = graphicsDriverPicker;
        final Spinner spinner = sBox64Preset;
        view.findViewById(R.id.BTConfirm).setOnClickListener(view2 -> {
            try {
                lambda_onCreateView_5(etName, view, envVarsView, graphicsDriverPicker3, dxwrapperPicker, vAudioDriverConfig3, sAudioDriver, sHUDMode, cpuListView, cpuListViewWoW64, sStartupSelection3, spinner, oldGraphicsDriverConfig, context, wineInfos, sWineVersion, view2);
            } catch (Throwable e) {
                throw new RuntimeException(e);
            }
        });
        return view;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_onCreateView_1(View v) {
        new AudioDriverConfigDialog(v).show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_onCreateView_2(Spinner sWinVersion, Integer tabResId) {
        if (tabResId.intValue() != R.id.LLTabAdvanced || ((Byte) sWinVersion.getTag()).byteValue() != -1) {
            return;
        }
        WinVersions.loadSpinner(this.container, sWinVersion);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX WARN: Removed duplicated region for block: B:16:0x00ee A[Catch: JSONException -> 0x010f, TRY_ENTER, TRY_LEAVE, TryCatch #5 {JSONException -> 0x010f, blocks: (B:5:0x0064, B:16:0x00ee), top: B:58:0x0064 }] */
    /* JADX WARN: Removed duplicated region for block: B:19:0x00fe  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public /* synthetic */ void lambda_onCreateView_5(android.widget.EditText r23, final android.view.View r24, com.winlator.widget.EnvVarsView r25, com.winlator.container.GraphicsDriverPicker r26, com.winlator.container.DXWrapperPicker r27, android.view.View r28, android.widget.Spinner r29, android.widget.Spinner r30, com.winlator.widget.CPUListView r31, com.winlator.widget.CPUListView r32, android.widget.Spinner r33, android.widget.Spinner r34, java.lang.String r35, final android.content.Context r36, java.util.ArrayList r37, android.widget.Spinner r38, android.view.View r39) throws java.lang.Throwable {
        /*
            Method dump skipped, instruction units count: 469
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.ContainerDetailFragment.lambda_onCreateView_5(android.widget.EditText, android.view.View, com.winlator.widget.EnvVarsView, com.winlator.container.GraphicsDriverPicker, com.winlator.container.DXWrapperPicker, android.view.View, android.widget.Spinner, android.widget.Spinner, com.winlator.widget.CPUListView, com.winlator.widget.CPUListView, android.widget.Spinner, android.widget.Spinner, java.lang.String, android.content.Context, java.util.ArrayList, android.widget.Spinner, android.view.View):void");
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_onCreateView_4(View view, Container container) throws Throwable {
        if (container != null) {
            this.container = container;
            saveWineRegistryKeys(view);
        }
        this.preloaderDialog.close();
        getActivity().onBackPressed();
    }

    private void saveWineRegistryKeys(View view) throws Throwable {
        int newPosition;
        File userRegFile = new File(this.container.getRootDir(), ".wine/user.reg");
        WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile);
        try {
            Spinner sSystemFont = (Spinner) view.findViewById(R.id.SSystemFont);
            WineUtils.setSystemFont(registryEditor, sSystemFont.getSelectedItem().toString());
            SeekBar sbLogPixels = (SeekBar) view.findViewById(R.id.SBLogPixels);
            registryEditor.setDwordValue("Control Panel\\Desktop", "LogPixels", (int) sbLogPixels.getValue());
            Spinner sMouseWarpOverride = (Spinner) view.findViewById(R.id.SMouseWarpOverride);
            String[] mouseWarpOverrideValues = {"disable", "enable", "force"};
            registryEditor.setStringValue("Software\\Wine\\DirectInput", "MouseWarpOverride", mouseWarpOverrideValues[sMouseWarpOverride.getSelectedItemPosition()]);
            registryEditor.setStringValue("Software\\Wine\\Direct3D", "shader_backend", "glsl");
            registryEditor.setStringValue("Software\\Wine\\Direct3D", "UseGLSL", "enabled");
            registryEditor.close();
            Spinner sWinVersion = (Spinner) view.findViewById(R.id.SWinVersion);
            int oldPosition = ((Byte) sWinVersion.getTag()).byteValue();
            if (oldPosition == -1 || oldPosition == (newPosition = sWinVersion.getSelectedItemPosition())) {
                return;
            }
            WineUtils.setWinVersion(this.container, newPosition);
        } catch (Throwable th) {
            try {
                registryEditor.close();
            } catch (Throwable th2) {
                th.addSuppressed(th2);
            }
            throw th;
        }
    }

    private void createWineConfigurationTab(View view) {
        Context context = getContext();
        WineThemeManager.ThemeInfo desktopTheme = new WineThemeManager.ThemeInfo(isEditMode() ? this.container.getDesktopTheme() : WineThemeManager.DEFAULT_DESKTOP_THEME);
        RadioGroup rgDesktopTheme = (RadioGroup) view.findViewById(R.id.RGDesktopTheme);
        rgDesktopTheme.check(desktopTheme.theme == WineThemeManager.Theme.LIGHT ? R.id.RBLight : R.id.RBDark);
        final ImagePickerView ipvDesktopBackgroundImage = (ImagePickerView) view.findViewById(R.id.IPVDesktopBackgroundImage);
        ipvDesktopBackgroundImage.setSelectedSource(desktopTheme.wallpaperId);
        final ColorPickerView cpvDesktopBackgroundColor = (ColorPickerView) view.findViewById(R.id.CPVDesktopBackgroundColor);
        cpvDesktopBackgroundColor.setColor(desktopTheme.backgroundColor);
        Spinner sDesktopBackgroundType = (Spinner) view.findViewById(R.id.SDesktopBackgroundType);
        sDesktopBackgroundType.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ContainerDetailFragment.1
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view2, int position, long id) {
                WineThemeManager.BackgroundType type = WineThemeManager.BackgroundType.values()[position];
                ipvDesktopBackgroundImage.setVisibility(8);
                cpvDesktopBackgroundColor.setVisibility(8);
                if (type == WineThemeManager.BackgroundType.IMAGE) {
                    ipvDesktopBackgroundImage.setVisibility(0);
                } else if (type == WineThemeManager.BackgroundType.COLOR) {
                    cpvDesktopBackgroundColor.setVisibility(0);
                }
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        sDesktopBackgroundType.setSelection(desktopTheme.backgroundType.ordinal());
        File containerDir = isEditMode() ? this.container.getRootDir() : null;
        File userRegFile = new File(containerDir, ".wine/user.reg");
        WineRegistryEditor registryEditor = new WineRegistryEditor(userRegFile);
        try {
            Spinner sSystemFont = (Spinner) view.findViewById(R.id.SSystemFont);
            MSLogFont msLogFont = new MSLogFont().fromByteArray(registryEditor.getHexValues("Control Panel\\Desktop\\WindowMetrics", "CaptionFont"));
            AppUtils.setSpinnerSelectionFromValue(sSystemFont, msLogFont.getFaceName());
            SeekBar sbLogPixels = (SeekBar) view.findViewById(R.id.SBLogPixels);
            sbLogPixels.setValue(registryEditor.getDwordValue("Control Panel\\Desktop", "LogPixels", 96).intValue());
            List<String> mouseWarpOverrideList = Arrays.asList(context.getString(R.string.disable), context.getString(R.string.enable), context.getString(R.string.force));
            Spinner sMouseWarpOverride = (Spinner) view.findViewById(R.id.SMouseWarpOverride);
            sMouseWarpOverride.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, mouseWarpOverrideList));
            AppUtils.setSpinnerSelectionFromValue(sMouseWarpOverride, registryEditor.getStringValue("Software\\Wine\\DirectInput", "MouseWarpOverride", "disable"));
            registryEditor.close();
        } finally {
        }
    }

    public static String getScreenSize(View view) {
        Spinner sScreenSize = (Spinner) view.findViewById(R.id.SScreenSize);
        String value = sScreenSize.getSelectedItem().toString();
        if (sScreenSize.getSelectedItemPosition() == 0) {
            value = "1280x720";
            String strWidth = ((EditText) view.findViewById(R.id.ETScreenWidth)).getText().toString().trim();
            String strHeight = ((EditText) view.findViewById(R.id.ETScreenHeight)).getText().toString().trim();
            if (strWidth.matches("[0-9]+") && strHeight.matches("[0-9]+")) {
                int width = Integer.parseInt(strWidth);
                int height = Integer.parseInt(strHeight);
                if (width % 2 == 0 && height % 2 == 0) {
                    return width + "x" + height;
                }
            }
        }
        return StringUtils.parseIdentifier(value);
    }

    private String getDesktopTheme(View view) {
        Spinner sDesktopBackgroundType = (Spinner) view.findViewById(R.id.SDesktopBackgroundType);
        WineThemeManager.BackgroundType type = WineThemeManager.BackgroundType.values()[sDesktopBackgroundType.getSelectedItemPosition()];
        RadioGroup rgDesktopTheme = (RadioGroup) view.findViewById(R.id.RGDesktopTheme);
        ImagePickerView ipvDesktopBackgroundImage = (ImagePickerView) view.findViewById(R.id.IPVDesktopBackgroundImage);
        ColorPickerView cpvDesktopBackground = (ColorPickerView) view.findViewById(R.id.CPVDesktopBackgroundColor);
        WineThemeManager.Theme theme = rgDesktopTheme.getCheckedRadioButtonId() == R.id.RBLight ? WineThemeManager.Theme.LIGHT : WineThemeManager.Theme.DARK;
        String desktopTheme = theme + "," + type + "," + cpvDesktopBackground.getColorAsString();
        if (type == WineThemeManager.BackgroundType.IMAGE) {
            String selectedSource = ipvDesktopBackgroundImage.getSelectedSource();
            String wallpaperId = (selectedSource.equals("wallpaper-1") || !selectedSource.startsWith("wallpaper-")) ? "0" : selectedSource;
            File userWallpaperFile = WineThemeManager.getUserWallpaperFile(getContext());
            StringBuilder sb = new StringBuilder();
            sb.append(desktopTheme);
            sb.append(",");
            sb.append((userWallpaperFile.isFile() && selectedSource.equals("user-wallpaper")) ? Long.valueOf(userWallpaperFile.lastModified()) : wallpaperId);
            return sb.toString();
        }
        return desktopTheme;
    }

    public static void loadScreenSizeSpinner(View view, String selectedValue) {
        final Spinner sScreenSize = (Spinner) view.findViewById(R.id.SScreenSize);
        final LinearLayout llCustomScreenSize = (LinearLayout) view.findViewById(R.id.LLCustomScreenSize);
        sScreenSize.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ContainerDetailFragment.2
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view2, int position, long id) {
                llCustomScreenSize.setVisibility(sScreenSize.getSelectedItemPosition() == 0 ? 0 : 8);
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        boolean found = AppUtils.setSpinnerSelectionFromIdentifier(sScreenSize, selectedValue);
        if (!found) {
            sScreenSize.setSelection(0);
            String[] screenSize = selectedValue.split("x");
            ((EditText) view.findViewById(R.id.ETScreenWidth)).setText(screenSize[0]);
            ((EditText) view.findViewById(R.id.ETScreenHeight)).setText(screenSize[1]);
        }
    }

    public static String getWinComponents(View view) {
        ViewGroup parent = (ViewGroup) view.findViewById(R.id.LLTabWinComponents);
        ArrayList<View> views = new ArrayList<>();
        AppUtils.findViewsWithClass(parent, Spinner.class, views);
        String[] wincomponents = new String[views.size()];
        for (int i = 0; i < views.size(); i++) {
            Spinner spinner = (Spinner) views.get(i);
            wincomponents[i] = spinner.getTag() + "=" + spinner.getSelectedItemPosition();
        }
        return String.join(",", wincomponents);
    }

    public static void createWinComponentsTab(View view, String wincomponents) {
        Context context = view.getContext();
        LayoutInflater inflater = LayoutInflater.from(context);
        ViewGroup tabView = (ViewGroup) view.findViewById(R.id.LLTabWinComponents);
        ViewGroup directxSectionView = (ViewGroup) tabView.findViewById(R.id.LLWinComponentsDirectX);
        ViewGroup generalSectionView = (ViewGroup) tabView.findViewById(R.id.LLWinComponentsGeneral);
        for (String[] wincomponent : new KeyValueSet(wincomponents)) {
            String name = wincomponent[0];
            ViewGroup parent = (name.startsWith("direct") || name.startsWith("x")) ? directxSectionView : generalSectionView;
            View itemView = inflater.inflate(R.layout.wincomponent_list_item, parent, false);
            ((TextView) itemView.findViewById(R.id.TextView)).setText(StringUtils.getString(context, name));
            Spinner spinner = (Spinner) itemView.findViewById(R.id.Spinner);
            spinner.setSelection(Integer.parseInt(wincomponent[1]), false);
            spinner.setTag(name);
            parent.addView(itemView);
        }
    }

    private EnvVarsView createEnvVarsTab(View view) {
        final Context context = view.getContext();
        final EnvVarsView envVarsView = (EnvVarsView) view.findViewById(R.id.EnvVarsView);
        envVarsView.setEnvVars(new EnvVars(isEditMode() ? this.container.getEnvVars() : "ZINK_DESCRIPTORS=lazy ZINK_DEBUG=compact MESA_SHADER_CACHE_DISABLE=false MESA_SHADER_CACHE_MAX_SIZE=512MB mesa_glthread=true WINEESYNC=1 TU_DEBUG=noconform"));
        view.findViewById(R.id.BTAddEnvVar).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerDetailFragment$$ExternalSyntheticLambda1
            @Override // android.view.View.OnClickListener
            public final void onClick(View view2) {
                ContainerDetailFragment.lambda_createEnvVarsTab_6(context, envVarsView, view2);
            }
        });
        return envVarsView;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_createEnvVarsTab_6(Context context, EnvVarsView envVarsView, View v) {
        new AddEnvVarDialog(context, envVarsView).show();
    }

    private String getDrives(View view) {
        LinearLayout parent = (LinearLayout) view.findViewById(R.id.LLDrives);
        String drives = "";
        for (int i = 0; i < parent.getChildCount(); i++) {
            View child = parent.getChildAt(i);
            Spinner spinner = (Spinner) child.findViewById(R.id.Spinner);
            EditText editText = (EditText) child.findViewById(R.id.EditText);
            String path = editText.getText().toString().replace(":", "").trim();
            if (!path.isEmpty()) {
                drives = drives + spinner.getSelectedItem() + path;
            }
        }
        return drives;
    }

    private void createDrivesTab(View view) {
        final Context context = getContext();
        final LinearLayout parent = (LinearLayout) view.findViewById(R.id.LLDrives);
        final View emptyTextView = view.findViewById(R.id.TVDrivesEmptyText);
        final LayoutInflater inflater = LayoutInflater.from(context);
        String drives = isEditMode() ? this.container.getDrives() : Container.DEFAULT_DRIVES;
        final String[] driveLetters = new String[8];
        for (int i = 0; i < driveLetters.length; i++) {
            driveLetters[i] = ((char) (i + 68)) + ":";
        }
        final Callback<Drive> addItem = (Callback<Drive>) drive -> lambda_createDrivesTab_9(inflater, parent, context, driveLetters, emptyTextView, drive);
        for (Drive drive : Container.drivesIterator(drives)) {
            addItem.call(drive);
        }
        view.findViewById(R.id.BTAddDrive).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerDetailFragment$$ExternalSyntheticLambda3
            @Override // android.view.View.OnClickListener
            public final void onClick(View view2) {
                ContainerDetailFragment.lambda_createDrivesTab_10(parent, driveLetters, addItem, view2);
            }
        });
        if (drives.isEmpty()) {
            emptyTextView.setVisibility(0);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_createDrivesTab_9(LayoutInflater inflater, final LinearLayout parent, Context context, String[] driveLetters, final View emptyTextView, final Drive drive) {
        final View itemView = inflater.inflate(R.layout.drive_list_item, (ViewGroup) parent, false);
        Spinner spinner = (Spinner) itemView.findViewById(R.id.Spinner);
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, driveLetters));
        AppUtils.setSpinnerSelectionFromValue(spinner, drive.letter + ":");
        final EditText editText = (EditText) itemView.findViewById(R.id.EditText);
        editText.setText(drive.path);
        itemView.findViewById(R.id.BTSearch).setOnClickListener(view -> lambda_createDrivesTab_7(view, drive, editText));
        itemView.findViewById(R.id.BTRemove).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerDetailFragment$$ExternalSyntheticLambda2
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                ContainerDetailFragment.lambda_createDrivesTab_8(parent, itemView, emptyTextView, view);
            }
        });
        parent.addView(itemView);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_createDrivesTab_8(LinearLayout parent, View itemView, View emptyTextView, View v) {
        parent.removeView(itemView);
        if (parent.getChildCount() == 0) {
            emptyTextView.setVisibility(0);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_createDrivesTab_10(LinearLayout parent, String[] driveLetters, Callback addItem, View v) {
        if (parent.getChildCount() >= 8) {
            return;
        }
        String nextDriveLetter = String.valueOf(driveLetters[parent.getChildCount()].charAt(0));
        addItem.call(new Drive(nextDriveLetter, ""));
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: showDriveSearchPopupMenu, reason: merged with bridge method [inline-methods] */
    public void lambda_createDrivesTab_7(View anchorView, final Drive drive, final EditText editText) {
        final FragmentActivity activity = getActivity();
        PopupMenu popupMenu = new PopupMenu(activity, anchorView);
        if (Build.VERSION.SDK_INT >= 29) {
            popupMenu.setForceShowIcon(true);
        }
        popupMenu.inflate(R.menu.drive_search_popup_menu);
        Menu menu = popupMenu.getMenu();
        SubMenu subMenu = menu.findItem(R.id.menu_item_locations).getSubMenu();
        ArrayList<Container> containers = this.manager.getContainers();
        for (int i = 0; i < containers.size(); i++) {
            Container container = containers.get(i);
            subMenu.add(0, 0, container.id, container.getName() + " (Drive C:)");
        }
        final Fragment $this = this;
        popupMenu.setOnMenuItemClickListener(menuItem -> lambda_showDriveSearchPopupMenu_12(drive, editText, activity, $this, menuItem));
        popupMenu.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ boolean lambda_showDriveSearchPopupMenu_12(final Drive drive, final EditText editText, FragmentActivity activity, Fragment $this, MenuItem menuItem) {
        int itemId = menuItem.getItemId();
        if (itemId == R.id.menu_item_downloads) {
                String str = AppUtils.DIRECTORY_DOWNLOADS;
                drive.path = str;
                editText.setText(str);
        } else if (itemId == R.id.menu_item_internal_storage) {
                drive.path = "/data/data/com.winlator/storage";
                editText.setText("/data/data/com.winlator/storage");
        } else if (itemId == R.id.menu_item_open_directory) {
                this.openDirectoryCallback = new Callback() { // from class: com.winlator.ContainerDetailFragment$$ExternalSyntheticLambda11
                    @Override // com.winlator.core.Callback
                    public final void call(Object obj) {
                        ContainerDetailFragment.lambda_showDriveSearchPopupMenu_11(drive, editText, (String) obj);
                    }
                };
                Intent intent = new Intent("android.intent.action.OPEN_DOCUMENT_TREE");
                intent.putExtra("android.provider.extra.INITIAL_URI", Uri.fromFile(Environment.getExternalStorageDirectory()));
                activity.startActivityFromFragment($this, intent, 4);
        } else {
                Container container = this.manager.getContainerById(menuItem.getOrder());
                if (container != null) {
                    String path = container.getRootDir() + "/.wine/drive_c";
                    drive.path = path;
                    editText.setText(path);
                }
        }
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_showDriveSearchPopupMenu_11(Drive drive, EditText editText, String path) {
        drive.path = path;
        editText.setText(path);
    }

    private void loadWineVersionSpinner(View view, Spinner sWineVersion, ArrayList<WineInfo> wineInfos) {
        Context context = getContext();
        sWineVersion.setEnabled(!isEditMode());
        view.findViewById(R.id.LLWineVersion).setVisibility(0);
        sWineVersion.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, wineInfos));
        if (isEditMode()) {
            AppUtils.setSpinnerSelectionFromValue(sWineVersion, WineInfo.fromIdentifier(context, this.container.getWineVersion()).toString());
        }
    }
}
