package com.winlator.contentdialog;

import android.content.Context;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.KeyValueSet;
import com.winlator.inputcontrols.ControlsProfile;
import com.winlator.inputcontrols.ExternalController;
import com.winlator.inputcontrols.InputControlsManager;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class GamepadPlayerConfigDialog extends ContentDialog {
    private InputControlsManager manager;

    public GamepadPlayerConfigDialog(final View anchor, byte number) {
        super(anchor.getContext(), R.layout.gamepad_player_config_dialog);
        setIcon(R.drawable.icon_gamepad);
        Context context = anchor.getContext();
        setTitle(context.getString(R.string.player) + " #" + (number + 1));
        KeyValueSet config = new KeyValueSet(anchor.getTag());
        final Spinner sSource = (Spinner) findViewById(R.id.SSource);
        byte mode = (byte) config.getInt("mode");
        final String selectedValue = config.get("name");
        final RadioGroup rgMode = (RadioGroup) findViewById(R.id.RGMode);
        rgMode.check(mode == 0 ? R.id.RBExternalController : R.id.RBControlsProfile);
        rgMode.setOnCheckedChangeListener((radioGroup, i) -> lambda_new_0(sSource, selectedValue, radioGroup, i));
        loadSourceSpinner(mode, sSource, selectedValue);
        final CheckBox cbEnableVibration = (CheckBox) findViewById(R.id.CBEnableVibration);
        cbEnableVibration.setChecked(config.getBoolean("vibration"));
        setOnConfirmCallback(new Runnable() { // from class: com.winlator.contentdialog.GamepadPlayerConfigDialog$$ExternalSyntheticLambda1
            @Override // java.lang.Runnable
            public final void run() {
                GamepadPlayerConfigDialog.lambda_new_1(rgMode, sSource, cbEnableVibration, anchor);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_0(Spinner sSource, String selectedValue, RadioGroup radioGroup, int checkedId) {
        loadSourceSpinner(checkedId == R.id.RBExternalController ? (byte) 0 : (byte) 1, sSource, selectedValue);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_1(RadioGroup rgMode, Spinner sSource, CheckBox cbEnableVibration, View anchor) {
        KeyValueSet newConfig = new KeyValueSet();
        newConfig.put("mode", Byte.valueOf(rgMode.getCheckedRadioButtonId() == R.id.RBExternalController ? (byte) 0 : (byte) 1));
        newConfig.put("name", sSource.getSelectedItemPosition() > 0 ? sSource.getSelectedItem().toString() : "");
        newConfig.put("vibration", cbEnableVibration.isChecked() ? "1" : "0");
        anchor.setTag(newConfig.toString());
    }

    private void loadSourceSpinner(byte mode, Spinner spinner, String selectedValue) {
        Context context = spinner.getContext();
        ArrayList<String> items = new ArrayList<>();
        items.add(context.getString(R.string.auto));
        if (mode == 0) {
            ArrayList<ExternalController> controllers = ExternalController.getControllers();
            for (ExternalController controller : controllers) {
                items.add(controller.getName());
            }
        } else {
            if (this.manager == null) {
                this.manager = new InputControlsManager(context);
            }
            ArrayList<ControlsProfile> profiles = this.manager.getProfiles();
            for (ControlsProfile profile : profiles) {
                profile.loadElements(null);
                if (profile.isVirtualGamepad()) {
                    items.add(profile.getName());
                }
            }
        }
        if (!selectedValue.isEmpty() && !items.contains(selectedValue)) {
            items.add(selectedValue);
        }
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, items));
        AppUtils.setSpinnerSelectionFromValue(spinner, selectedValue);
    }
}
