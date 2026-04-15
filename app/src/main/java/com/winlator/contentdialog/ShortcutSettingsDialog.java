package com.winlator.contentdialog;

import android.content.Context;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.PopupMenu;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import com.winlator.ContainerDetailFragment;
import com.winlator.R;
import com.winlator.ShortcutsFragment;
import com.winlator.box64.Box64PresetManager;
import com.winlator.container.DXWrapperPicker;
import com.winlator.container.GraphicsDriverPicker;
import com.winlator.container.Shortcut;
import com.winlator.core.AppUtils;
import com.winlator.core.EnvVars;
import com.winlator.core.StringUtils;
import com.winlator.inputcontrols.ControlsProfile;
import com.winlator.inputcontrols.InputControlsManager;
import com.winlator.widget.EnvVarsView;
import com.winlator.winhandler.GamepadHandler;
import java.io.File;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class ShortcutSettingsDialog extends ContentDialog {
    private final ShortcutsFragment fragment;
    private InputControlsManager inputControlsManager;
    private final Shortcut shortcut;

    public ShortcutSettingsDialog(ShortcutsFragment fragment, Shortcut shortcut) {
        super(fragment.getContext(), R.layout.shortcut_settings_dialog);
        this.fragment = fragment;
        this.shortcut = shortcut;
        setTitle(shortcut.name);
        setIcon(R.drawable.icon_settings);
        createContentView();
    }

    private void createContentView() {
        final Context context = this.fragment.getContext();
        this.inputControlsManager = new InputControlsManager(context);
        LinearLayout llContent = (LinearLayout) findViewById(R.id.LLContent);
        llContent.getLayoutParams().width = AppUtils.getPreferredDialogWidth(context);
        final EditText etName = (EditText) findViewById(R.id.ETName);
        etName.setText(this.shortcut.name);
        final EditText etExecArgs = (EditText) findViewById(R.id.ETExecArgs);
        etExecArgs.setText(this.shortcut.getExtra("execArgs"));
        View contentView = getContentView();
        Shortcut shortcut = this.shortcut;
        ContainerDetailFragment.loadScreenSizeSpinner(contentView, shortcut.getExtra("screenSize", shortcut.container.getScreenSize()));
        Shortcut shortcut2 = this.shortcut;
        final String oldGraphicsDriverConfig = shortcut2.getExtra("graphicsDriverConfig", shortcut2.container.getGraphicsDriverConfig());
        Shortcut shortcut3 = this.shortcut;
        String selectedGraphicsDriver = shortcut3.getExtra("graphicsDriver", shortcut3.container.getGraphicsDriver());
        final GraphicsDriverPicker graphicsDriverPicker = new GraphicsDriverPicker((LinearLayout) findViewById(R.id.LLGraphicsDriver), selectedGraphicsDriver, oldGraphicsDriverConfig);
        Shortcut shortcut4 = this.shortcut;
        String oldDXWrapperConfig = shortcut4.getExtra("dxwrapperConfig", shortcut4.container.getDXWrapperConfig());
        Shortcut shortcut5 = this.shortcut;
        String selectedDXWrapper = shortcut5.getExtra("dxwrapper", shortcut5.container.getDXWrapper());
        final DXWrapperPicker dxwrapperPicker = new DXWrapperPicker((LinearLayout) findViewById(R.id.LLDXWrapper), graphicsDriverPicker, selectedDXWrapper, oldDXWrapperConfig);
        findViewById(R.id.BTHelpDXWrapper).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.contentdialog.ShortcutSettingsDialog$$ExternalSyntheticLambda0
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                AppUtils.showHelpBox(context, view, R.string.dxwrapper_help_content);
            }
        });
        final Spinner sAudioDriver = (Spinner) findViewById(R.id.SAudioDriver);
        Shortcut shortcut6 = this.shortcut;
        AppUtils.setSpinnerSelectionFromIdentifier(sAudioDriver, shortcut6.getExtra("audioDriver", shortcut6.container.getAudioDriver()));
        final View vAudioDriverConfig = findViewById(R.id.BTAudioDriverConfig);
        Shortcut shortcut7 = this.shortcut;
        vAudioDriverConfig.setTag(shortcut7.getExtra("audioDriverConfig", shortcut7.container.getAudioDriverConfig()));
        vAudioDriverConfig.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.contentdialog.ShortcutSettingsDialog$$ExternalSyntheticLambda3
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                ShortcutSettingsDialog.lambda_createContentView_1(view);
            }
        });
        final CheckBox cbForceFullscreen = (CheckBox) findViewById(R.id.CBForceFullscreen);
        cbForceFullscreen.setChecked(this.shortcut.getExtra("forceFullscreen", "0").equals("1"));
        final Spinner sBox64Preset = (Spinner) findViewById(R.id.SBox64Preset);
        Shortcut shortcut8 = this.shortcut;
        Box64PresetManager.loadSpinner(sBox64Preset, shortcut8.getExtra("box64Preset", shortcut8.container.getBox64Preset()));
        final Spinner sControlsProfile = (Spinner) findViewById(R.id.SControlsProfile);
        loadControlsProfileSpinner(sControlsProfile, this.shortcut.getExtra("controlsProfile", "0"));
        final Spinner sDInputMapperType = (Spinner) findViewById(R.id.SDInputMapperType);
        sDInputMapperType.setSelection(Byte.parseByte(this.shortcut.getExtra("dinputMapperType", String.valueOf(1))));
        final Spinner sPreferredInputApi = (Spinner) findViewById(R.id.SPreferredInputApi);
        sPreferredInputApi.setSelection(Byte.parseByte(this.shortcut.getExtra("preferredInputApi", String.valueOf(GamepadHandler.PreferredInputApi.AUTO.ordinal()))));
        View contentView2 = getContentView();
        Shortcut shortcut9 = this.shortcut;
        ContainerDetailFragment.createWinComponentsTab(contentView2, shortcut9.getExtra("wincomponents", shortcut9.container.getWinComponents()));
        final EnvVarsView envVarsView = createEnvVarsTab();
        AppUtils.setupTabLayout(getContentView(), R.id.TabLayout, R.id.LLTabWinComponents, R.id.LLTabEnvVars, R.id.LLTabAdvanced);
        findViewById(R.id.BTExtraArgsMenu).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.contentdialog.ShortcutSettingsDialog$$ExternalSyntheticLambda1
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                ShortcutSettingsDialog.lambda_createContentView_3(context, etExecArgs, view);
            }
        });
        setOnConfirmCallback(() -> lambda_createContentView_5(etName, graphicsDriverPicker, dxwrapperPicker, vAudioDriverConfig, sAudioDriver, etExecArgs, cbForceFullscreen, envVarsView, sBox64Preset, sControlsProfile, sDInputMapperType, sPreferredInputApi, oldGraphicsDriverConfig, context));
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_createContentView_1(View v) {
        new AudioDriverConfigDialog(v).show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_createContentView_3(Context context, final EditText etExecArgs, View v) {
        PopupMenu popupMenu = new PopupMenu(context, v);
        popupMenu.inflate(R.menu.extra_args_popup_menu);
        popupMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() { // from class: com.winlator.contentdialog.ShortcutSettingsDialog$$ExternalSyntheticLambda4
            @Override // android.widget.PopupMenu.OnMenuItemClickListener
            public final boolean onMenuItemClick(MenuItem menuItem) {
                return ShortcutSettingsDialog.lambda_createContentView_2(etExecArgs, menuItem);
            }
        });
        popupMenu.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ boolean lambda_createContentView_2(EditText etExecArgs, MenuItem menuItem) {
        CharSequence charSequence;
        String value = String.valueOf(menuItem.getTitle());
        String execArgs = etExecArgs.getText().toString();
        if (!execArgs.contains(value)) {
            if (execArgs.isEmpty()) {
                charSequence = value;
            } else {
                charSequence = execArgs + " " + value;
            }
            etExecArgs.setText(charSequence);
            return true;
        }
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_createContentView_5(EditText etName, GraphicsDriverPicker graphicsDriverPicker, DXWrapperPicker dxwrapperPicker, View vAudioDriverConfig, Spinner sAudioDriver, EditText etExecArgs, CheckBox cbForceFullscreen, EnvVarsView envVarsView, Spinner sBox64Preset, Spinner sControlsProfile, Spinner sDInputMapperType, Spinner sPreferredInputApi, String oldGraphicsDriverConfig, final Context context) {
        String name = etName.getText().toString().trim();
        if (!this.shortcut.name.equals(name) && !name.isEmpty()) {
            renameShortcut(name);
            return;
        }
        String graphicsDriver = graphicsDriverPicker.getGraphicsDriver();
        String dxwrapper = dxwrapperPicker.getDXWrapper();
        String dxwrapperConfig = dxwrapperPicker.getDXWrapperConfig();
        String graphicsDriverConfig = graphicsDriverPicker.getGraphicsDriverConfig();
        String audioDriverConfig = vAudioDriverConfig.getTag().toString();
        String audioDriver = StringUtils.parseIdentifier(sAudioDriver.getSelectedItem());
        String screenSize = ContainerDetailFragment.getScreenSize(getContentView());
        String execArgs = etExecArgs.getText().toString();
        this.shortcut.putExtra("execArgs", !execArgs.isEmpty() ? execArgs : null);
        Shortcut shortcut = this.shortcut;
        shortcut.putExtra("screenSize", !screenSize.equals(shortcut.container.getScreenSize()) ? screenSize : null);
        Shortcut shortcut2 = this.shortcut;
        shortcut2.putExtra("graphicsDriver", !graphicsDriver.equals(shortcut2.container.getGraphicsDriver()) ? graphicsDriver : null);
        Shortcut shortcut3 = this.shortcut;
        shortcut3.putExtra("dxwrapper", !dxwrapper.equals(shortcut3.container.getDXWrapper()) ? dxwrapper : null);
        Shortcut shortcut4 = this.shortcut;
        shortcut4.putExtra("dxwrapperConfig", !dxwrapperConfig.equals(shortcut4.container.getDXWrapperConfig()) ? dxwrapperConfig : null);
        Shortcut shortcut5 = this.shortcut;
        shortcut5.putExtra("graphicsDriverConfig", !graphicsDriverConfig.equals(shortcut5.container.getGraphicsDriverConfig()) ? graphicsDriverConfig : null);
        Shortcut shortcut6 = this.shortcut;
        shortcut6.putExtra("audioDriver", !audioDriver.equals(shortcut6.container.getAudioDriver()) ? audioDriver : null);
        Shortcut shortcut7 = this.shortcut;
        shortcut7.putExtra("audioDriverConfig", !audioDriverConfig.equals(shortcut7.container.getAudioDriverConfig()) ? audioDriverConfig : null);
        this.shortcut.putExtra("forceFullscreen", cbForceFullscreen.isChecked() ? "1" : null);
        String wincomponents = ContainerDetailFragment.getWinComponents(getContentView());
        Shortcut shortcut8 = this.shortcut;
        shortcut8.putExtra("wincomponents", !wincomponents.equals(shortcut8.container.getWinComponents()) ? wincomponents : null);
        String envVars = envVarsView.getEnvVars();
        this.shortcut.putExtra("envVars", !envVars.isEmpty() ? envVars : null);
        String box64Preset = Box64PresetManager.getSpinnerSelectedId(sBox64Preset);
        Shortcut shortcut9 = this.shortcut;
        shortcut9.putExtra("box64Preset", !box64Preset.equals(shortcut9.container.getBox64Preset()) ? box64Preset : null);
        ArrayList<ControlsProfile> profiles = this.inputControlsManager.getProfiles(true);
        int controlsProfile = sControlsProfile.getSelectedItemPosition() > 0 ? profiles.get(sControlsProfile.getSelectedItemPosition() - 1).id : 0;
        this.shortcut.putExtra("controlsProfile", controlsProfile > 0 ? String.valueOf(controlsProfile) : null);
        int dinputMapperType = sDInputMapperType.getSelectedItemPosition();
        this.shortcut.putExtra("dinputMapperType", dinputMapperType != 1 ? String.valueOf(dinputMapperType) : null);
        int preferredInputApi = sPreferredInputApi.getSelectedItemPosition();
        this.shortcut.putExtra("preferredInputApi", preferredInputApi != GamepadHandler.PreferredInputApi.AUTO.ordinal() ? String.valueOf(preferredInputApi) : null);
        this.shortcut.saveData();
        boolean requireRestart = graphicsDriver.equals("vortek") && VortekConfigDialog.isRequireRestart(oldGraphicsDriverConfig, graphicsDriverConfig);
        if (requireRestart) {
            ContentDialog.confirm(context, R.string.the_settings_have_been_changed_do_you_want_to_restart_the_app, new Runnable() { // from class: com.winlator.contentdialog.ShortcutSettingsDialog$$ExternalSyntheticLambda5
                @Override // java.lang.Runnable
                public final void run() {
                    AppUtils.restartApplication(context);
                }
            });
        }
    }

    private void renameShortcut(String newName) {
        String newName2 = StringUtils.clearReservedChars(newName);
        File parent = this.shortcut.file.getParentFile();
        File newFile = new File(parent, newName2 + ".desktop");
        if (!newFile.isFile()) {
            this.shortcut.file.renameTo(newFile);
        }
        File linkFile = new File(parent, this.shortcut.name + ".lnk");
        if (linkFile.isFile()) {
            File newFile2 = new File(parent, newName2 + ".lnk");
            if (!newFile2.isFile()) {
                linkFile.renameTo(newFile2);
            }
        }
        this.fragment.refreshContent();
    }

    private EnvVarsView createEnvVarsTab() {
        View view = getContentView();
        final Context context = view.getContext();
        final EnvVarsView envVarsView = (EnvVarsView) view.findViewById(R.id.EnvVarsView);
        envVarsView.setEnvVars(new EnvVars(this.shortcut.getExtra("envVars")));
        view.findViewById(R.id.BTAddEnvVar).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.contentdialog.ShortcutSettingsDialog$$ExternalSyntheticLambda2
            @Override // android.view.View.OnClickListener
            public final void onClick(View view2) {
                ShortcutSettingsDialog.lambda_createEnvVarsTab_6(context, envVarsView, view2);
            }
        });
        return envVarsView;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_createEnvVarsTab_6(Context context, EnvVarsView envVarsView, View v) {
        new AddEnvVarDialog(context, envVarsView).show();
    }

    private void loadControlsProfileSpinner(Spinner spinner, String selectedValue) {
        Context context = this.fragment.getContext();
        ArrayList<ControlsProfile> profiles = this.inputControlsManager.getProfiles(true);
        ArrayList<String> values = new ArrayList<>();
        values.add(context.getString(R.string.none));
        int selectedPosition = 0;
        int selectedId = Integer.parseInt(selectedValue);
        for (int i = 0; i < profiles.size(); i++) {
            ControlsProfile profile = profiles.get(i);
            if (profile.id == selectedId) {
                selectedPosition = i + 1;
            }
            values.add(profile.getName());
        }
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, values));
        spinner.setSelection(selectedPosition, false);
    }
}
