package com.winlator;

import android.content.Context;
import android.graphics.BitmapFactory;
import android.graphics.PointF;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import com.winlator.core.AppUtils;
import com.winlator.core.FileUtils;
import com.winlator.core.LocaleHelper;
import com.winlator.core.UnitUtils;
import com.winlator.inputcontrols.Binding;
import com.winlator.inputcontrols.ControlElement;
import com.winlator.inputcontrols.ControlsProfile;
import com.winlator.inputcontrols.InputControlsManager;
import com.winlator.math.Mathf;
import com.winlator.widget.InputControlsView;
import com.winlator.widget.NumberPicker;
import com.winlator.widget.SeekBar;
import com.winlator.winhandler.MIDIHandler;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;

/* JADX INFO: loaded from: classes.dex */
public class ControlsEditorActivity extends AppCompatActivity implements View.OnClickListener {
    private InputControlsView inputControlsView;
    private ControlsProfile profile;
    private View toolbox;

    @Override // androidx.fragment.app.FragmentActivity, androidx.activity.ComponentActivity, androidx.core.app.ComponentActivity, android.app.Activity
    public void onCreate(Bundle bundle) {
        AppUtils.setActivityTheme(this);
        super.onCreate(bundle);
        AppUtils.hideSystemUI(this);
        setContentView(R.layout.controls_editor_activity);
        InputControlsView inputControlsView = new InputControlsView(this);
        this.inputControlsView = inputControlsView;
        inputControlsView.setEditMode(true);
        this.inputControlsView.setOverlayOpacity(0.6f);
        this.profile = InputControlsManager.loadProfile(this, ControlsProfile.getProfileFile(this, getIntent().getIntExtra("profile_id", 0)));
        ((TextView) findViewById(R.id.TVProfileName)).setText(this.profile.getName());
        this.inputControlsView.setProfile(this.profile);
        FrameLayout container = (FrameLayout) findViewById(R.id.FLContainer);
        container.addView(this.inputControlsView, 0);
        container.findViewById(R.id.BTAddElement).setOnClickListener(this);
        container.findViewById(R.id.BTRemoveElement).setOnClickListener(this);
        container.findViewById(R.id.BTElementSettings).setOnClickListener(this);
        this.toolbox = container.findViewById(R.id.Toolbox);
        final PointF startPoint = new PointF();
        final boolean[] isActionDown = {false};
        container.findViewById(R.id.BTMove).setOnTouchListener((view, motionEvent) -> lambda_onCreate_0(startPoint, isActionDown, view, motionEvent));
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    public /* synthetic */ boolean lambda_onCreate_0(PointF startPoint, boolean[] isActionDown, View v, MotionEvent event) {
        switch (event.getAction()) {
            case 0:
                startPoint.x = event.getX();
                startPoint.y = event.getY();
                isActionDown[0] = true;
                return true;
            case 1:
                isActionDown[0] = false;
                return true;
            case 2:
                if (isActionDown[0]) {
                    float newX = this.toolbox.getX() + (event.getX() - startPoint.x);
                    float newY = this.toolbox.getY() + (event.getY() - startPoint.y);
                    moveToolbox(newX, newY);
                }
                return true;
            default:
                return true;
        }
    }

    @Override // androidx.appcompat.app.AppCompatActivity, android.app.Activity, android.view.ContextThemeWrapper, android.content.ContextWrapper
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(LocaleHelper.setSystemLocale(newBase));
    }

    private void moveToolbox(float x, float y) {
        int padding = (int) UnitUtils.dpToPx(8.0f);
        ViewGroup parent = (ViewGroup) this.toolbox.getParent();
        int width = this.toolbox.getWidth();
        int height = this.toolbox.getHeight();
        int parentWidth = parent.getWidth();
        int parentHeight = parent.getHeight();
        float x2 = Mathf.clamp(x, padding, (parentWidth - padding) - width);
        float y2 = Mathf.clamp(y, padding, (parentHeight - padding) - height);
        this.toolbox.setX(x2);
        this.toolbox.setY(y2);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View v) {
        int id = v.getId();
        if (id == R.id.BTAddElement) {
                if (!this.inputControlsView.addElement()) {
                    AppUtils.showToast(this, R.string.no_profile_selected);
                }
        } else if (id == R.id.BTElementSettings) {
                ControlElement selectedElement = this.inputControlsView.getSelectedElement();
                if (selectedElement != null) {
                    showControlElementSettings(v);
                } else {
                    AppUtils.showToast(this, R.string.no_control_element_selected);
                }
        } else if (id == R.id.BTRemoveElement) {
                if (!this.inputControlsView.removeElement()) {
                    AppUtils.showToast(this, R.string.no_control_element_selected);
                }
        }
    }

    private void showControlElementSettings(View anchorView) {
        final ControlElement element = this.inputControlsView.getSelectedElement();
        final View view = LayoutInflater.from(this).inflate(R.layout.control_element_settings, (ViewGroup) null);
        Runnable updateLayout = () -> lambda_showControlElementSettings_1(element, view);
        loadTypeSpinner(element, (Spinner) view.findViewById(R.id.SType), updateLayout);
        loadShapeSpinner(element, (Spinner) view.findViewById(R.id.SShape));
        loadRangeSpinner(element, (Spinner) view.findViewById(R.id.SRange));
        loadNoteSpinner(element, (Spinner) view.findViewById(R.id.SNote));
        RadioGroup rgOrientation = (RadioGroup) view.findViewById(R.id.RGOrientation);
        rgOrientation.check(element.getOrientation() == 1 ? R.id.RBVertical : R.id.RBHorizontal);
        rgOrientation.setOnCheckedChangeListener((radioGroup, i) -> lambda_showControlElementSettings_2(element, radioGroup, i));
        NumberPicker npColumns = (NumberPicker) view.findViewById(R.id.NPColumns);
        npColumns.setValue(element.getBindingCount());
        npColumns.setOnValueChangeListener((numberPicker, i) -> lambda_showControlElementSettings_3(element, numberPicker, i));
        NumberPicker npBindings = (NumberPicker) view.findViewById(R.id.NPBindings);
        npBindings.setValue(element.getBindingCount());
        npBindings.setOnValueChangeListener((numberPicker, i) -> lambda_showControlElementSettings_4(element, view, numberPicker, i));
        SeekBar sbScale = (SeekBar) view.findViewById(R.id.SBScale);
        sbScale.setOnValueChangeListener((seekBar, f) -> lambda_showControlElementSettings_5(element, seekBar, f));
        sbScale.setValue(element.getScale() * 100.0f);
        SeekBar sbOpacity = (SeekBar) view.findViewById(R.id.SBOpacity);
        sbOpacity.setOnValueChangeListener((seekBar, f) -> lambda_showControlElementSettings_6(element, seekBar, f));
        sbOpacity.setValue(element.getOpacity() * 100.0f);
        CheckBox cbToggleSwitch = (CheckBox) view.findViewById(R.id.CBToggleSwitch);
        cbToggleSwitch.setChecked(element.isToggleSwitch());
        cbToggleSwitch.setOnCheckedChangeListener((compoundButton, z) -> lambda_showControlElementSettings_7(element, compoundButton, z));
        CheckBox cbMouseMoveMode = (CheckBox) view.findViewById(R.id.CBMouseMoveMode);
        cbMouseMoveMode.setChecked(element.isMouseMoveMode());
        cbMouseMoveMode.setOnCheckedChangeListener((compoundButton, z) -> lambda_showControlElementSettings_8(element, compoundButton, z));
        final EditText etCustomText = (EditText) view.findViewById(R.id.ETCustomText);
        etCustomText.setText(element.getText());
        final LinearLayout llIconList = (LinearLayout) view.findViewById(R.id.LLIconList);
        loadIcons(llIconList, element.getIconId());
        updateLayout.run();
        PopupWindow popupWindow = AppUtils.showPopupWindow(anchorView, view, 340, 0);
        popupWindow.setOnDismissListener(() -> lambda_showControlElementSettings_9(element, llIconList, etCustomText));
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_1(ControlElement element, View view) {
        ControlElement.Type type = element.getType();
        view.findViewById(R.id.LLShape).setVisibility(8);
        view.findViewById(R.id.CBToggleSwitch).setVisibility(8);
        view.findViewById(R.id.CBMouseMoveMode).setVisibility(8);
        view.findViewById(R.id.LLCustomTextIcon).setVisibility(8);
        view.findViewById(R.id.LLRangeOptions).setVisibility(8);
        view.findViewById(R.id.LLMIDIKeyOptions).setVisibility(8);
        view.findViewById(R.id.LLRadialMenuOptions).setVisibility(8);
        switch (AnonymousClass7.$SwitchMap$com$winlator$inputcontrols$ControlElement$Type[type.ordinal()]) {
            case 1:
                view.findViewById(R.id.LLShape).setVisibility(0);
                view.findViewById(R.id.CBToggleSwitch).setVisibility(0);
                view.findViewById(R.id.CBMouseMoveMode).setVisibility(0);
                view.findViewById(R.id.LLCustomTextIcon).setVisibility(0);
                break;
            case 2:
                view.findViewById(R.id.LLRangeOptions).setVisibility(0);
                break;
            case 3:
                view.findViewById(R.id.LLMIDIKeyOptions).setVisibility(0);
                break;
            case 4:
                ((NumberPicker) view.findViewById(R.id.NPBindings)).setValue(element.getBindingCount());
                view.findViewById(R.id.LLRadialMenuOptions).setVisibility(0);
                break;
        }
        loadBindingSpinners(element, view);
    }

    /* JADX INFO: renamed from: com.winlator.ControlsEditorActivity$7, reason: invalid class name */
    static /* synthetic */ class AnonymousClass7 {
        static final /* synthetic */ int[] $SwitchMap$com$winlator$inputcontrols$ControlElement$Type;

        static {
            int[] iArr = new int[ControlElement.Type.values().length];
            $SwitchMap$com$winlator$inputcontrols$ControlElement$Type = iArr;
            try {
                iArr[ControlElement.Type.BUTTON.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[ControlElement.Type.RANGE_BUTTON.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[ControlElement.Type.MIDI_KEY.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[ControlElement.Type.RADIAL_MENU.ordinal()] = 4;
            } catch (NoSuchFieldError e4) {
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_2(ControlElement element, RadioGroup group, int checkedId) {
        element.setOrientation((byte) (checkedId == R.id.RBVertical ? 1 : 0));
        this.profile.save();
        this.inputControlsView.invalidate();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_3(ControlElement element, NumberPicker numberPicker, int value) {
        element.setBindingCount(value);
        this.profile.save();
        this.inputControlsView.invalidate();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_4(ControlElement element, View view, NumberPicker numberPicker, int value) {
        element.setBindingCount(value);
        loadBindingSpinners(element, view);
        this.profile.save();
        this.inputControlsView.invalidate();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_5(ControlElement element, SeekBar seekBar, float value) {
        element.setScale(value / 100.0f);
        this.profile.save();
        this.inputControlsView.invalidate();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_6(ControlElement element, SeekBar seekBar, float value) {
        element.setOpacity(value / 100.0f);
        this.profile.save();
        this.inputControlsView.invalidate();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_7(ControlElement element, CompoundButton buttonView, boolean isChecked) {
        element.setToggleSwitch(isChecked);
        this.profile.save();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_8(ControlElement element, CompoundButton buttonView, boolean isChecked) {
        element.setMouseMoveMode(isChecked);
        this.profile.save();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_showControlElementSettings_9(ControlElement element, LinearLayout llIconList, EditText etCustomText) {
        byte iconId = 0;
        if (element.getType() == ControlElement.Type.BUTTON) {
            int i = 0;
            while (true) {
                if (i >= llIconList.getChildCount()) {
                    break;
                }
                View child = llIconList.getChildAt(i);
                if (!child.isSelected()) {
                    i++;
                } else {
                    iconId = ((Byte) child.getTag()).byteValue();
                    break;
                }
            }
            String text = etCustomText.getText().toString().trim();
            element.setText(text);
        }
        element.setIconId(iconId);
        this.profile.save();
        this.inputControlsView.invalidate();
    }

    private void loadTypeSpinner(final ControlElement element, Spinner spinner, final Runnable callback) {
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, ControlElement.Type.names()));
        spinner.setSelection(element.getType().ordinal(), false);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ControlsEditorActivity.1
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                ControlElement.Type newType = ControlElement.Type.values()[position];
                if (newType == element.getType()) {
                    return;
                }
                element.setType(newType);
                ControlsEditorActivity.this.profile.save();
                callback.run();
                ControlsEditorActivity.this.inputControlsView.invalidate();
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
    }

    private void loadShapeSpinner(final ControlElement element, Spinner spinner) {
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, ControlElement.Shape.names()));
        spinner.setSelection(element.getShape().ordinal(), false);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ControlsEditorActivity.2
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                element.setShape(ControlElement.Shape.values()[position]);
                ControlsEditorActivity.this.profile.save();
                ControlsEditorActivity.this.inputControlsView.invalidate();
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
    }

    private void loadBindingSpinners(ControlElement element, View view) {
        LinearLayout container = (LinearLayout) view.findViewById(R.id.LLBindings);
        container.removeAllViews();
        ControlElement.Type type = element.getType();
        if (type == ControlElement.Type.BUTTON) {
            byte first = element.getFirstBindingIndex();
            byte count = 0;
            for (byte i = 0; i < element.getBindingCount(); i = (byte) (i + 1)) {
                if (i <= first || element.getBindingAt(i) != Binding.NONE) {
                    byte count2 = (byte) (count + 1);
                    loadBindingSpinner(element, container, i, count == 0 ? R.string.binding : 0);
                    count = count2;
                }
            }
            return;
        }
        if (type == ControlElement.Type.D_PAD || type == ControlElement.Type.STICK || type == ControlElement.Type.TRACKPAD) {
            loadBindingSpinner(element, container, 0, R.string.binding_up);
            loadBindingSpinner(element, container, 1, R.string.binding_right);
            loadBindingSpinner(element, container, 2, R.string.binding_down);
            loadBindingSpinner(element, container, 3, R.string.binding_left);
            return;
        }
        if (type == ControlElement.Type.RADIAL_MENU) {
            for (byte i2 = 0; i2 < element.getBindingCount(); i2 = (byte) (i2 + 1)) {
                loadBindingSpinner(element, container, i2, 0);
            }
        }
    }

    private void loadBindingSpinner(final ControlElement element, final LinearLayout container, final int index, int titleResId) {
        View view = LayoutInflater.from(this).inflate(R.layout.binding_field, (ViewGroup) container, false);
        LinearLayout titleBar = (LinearLayout) view.findViewById(R.id.LLTitleBar);
        if (titleResId > 0) {
            titleBar.setVisibility(0);
            ((TextView) view.findViewById(R.id.TVTitle)).setText(titleResId);
        } else {
            titleBar.setVisibility(8);
        }
        final Spinner sBindingType = (Spinner) view.findViewById(R.id.SBindingType);
        final Spinner sBinding = (Spinner) view.findViewById(R.id.SBinding);
        ControlElement.Type type = element.getType();
        if (type == ControlElement.Type.BUTTON || type == ControlElement.Type.RADIAL_MENU) {
            ImageButton addButton = (ImageButton) view.findViewById(R.id.BTAdd);
            addButton.setVisibility(0);
            addButton.setOnClickListener(view2 -> lambda_loadBindingSpinner_10(container, element, view2));
        }
        final Runnable update = () -> lambda_loadBindingSpinner_11(sBindingType, sBinding, element, index);
        sBindingType.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ControlsEditorActivity.3
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view2, int position, long id) {
                update.run();
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        Binding selectedBinding = element.getBindingAt(index);
        if (selectedBinding.isKeyboard()) {
            sBindingType.setSelection(0, false);
        } else if (selectedBinding.isMouse()) {
            sBindingType.setSelection(1, false);
        } else if (selectedBinding.isGamepad()) {
            sBindingType.setSelection(2, false);
        }
        sBinding.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ControlsEditorActivity.4
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view2, int position, long id) {
                Binding binding = Binding.NONE;
                switch (sBindingType.getSelectedItemPosition()) {
                    case 0:
                        binding = Binding.keyboardBindingValues()[position];
                        break;
                    case 1:
                        binding = Binding.mouseBindingValues()[position];
                        break;
                    case 2:
                        binding = Binding.gamepadBindingValues()[position];
                        break;
                }
                if (binding != element.getBindingAt(index)) {
                    element.setBindingAt(index, binding);
                    ControlsEditorActivity.this.profile.save();
                    ControlsEditorActivity.this.inputControlsView.invalidate();
                }
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
        update.run();
        container.addView(view);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_loadBindingSpinner_10(LinearLayout container, ControlElement element, View v) {
        int nextIndex = container.getChildCount();
        if (nextIndex < element.getBindingCount()) {
            loadBindingSpinner(element, container, nextIndex, 0);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_loadBindingSpinner_11(Spinner sBindingType, Spinner sBinding, ControlElement element, int index) {
        String[] bindingEntries = null;
        switch (sBindingType.getSelectedItemPosition()) {
            case 0:
                bindingEntries = Binding.keyboardBindingLabels();
                break;
            case 1:
                bindingEntries = Binding.mouseBindingLabels();
                break;
            case 2:
                bindingEntries = Binding.gamepadBindingLabels();
                break;
        }
        sBinding.setAdapter((SpinnerAdapter) new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, bindingEntries));
        AppUtils.setSpinnerSelectionFromValue(sBinding, element.getBindingAt(index).toString());
    }

    private void loadRangeSpinner(final ControlElement element, Spinner spinner) {
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, ControlElement.Range.names()));
        spinner.setSelection(element.getRange().ordinal(), false);
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ControlsEditorActivity.5
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                element.setRange(ControlElement.Range.values()[position]);
                ControlsEditorActivity.this.profile.save();
                ControlsEditorActivity.this.inputControlsView.invalidate();
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
    }

    private void loadNoteSpinner(final ControlElement element, Spinner spinner) {
        final String[] notes = MIDIHandler.getNotes();
        spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(this, android.R.layout.simple_spinner_dropdown_item, notes));
        AppUtils.setSpinnerSelectionFromValue(spinner, element.getText());
        spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.ControlsEditorActivity.6
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                element.setText(notes[position]);
                ControlsEditorActivity.this.profile.save();
                ControlsEditorActivity.this.inputControlsView.invalidate();
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> parent) {
            }
        });
    }

    private void loadIcons(final LinearLayout parent, byte selectedId) {
        String str;
        String str2 = "inputcontrols/icons/";
        boolean z = false;
        byte[] iconIds = new byte[0];
        try {
            String[] filenames = getAssets().list("inputcontrols/icons/");
            iconIds = new byte[filenames.length];
            for (int i = 0; i < filenames.length; i++) {
                iconIds[i] = Byte.parseByte(FileUtils.getBasename(filenames[i]));
            }
        } catch (IOException e) {
        }
        Arrays.sort(iconIds);
        int size = (int) UnitUtils.dpToPx(40.0f);
        int margin = (int) UnitUtils.dpToPx(2.0f);
        int padding = (int) UnitUtils.dpToPx(4.0f);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(size, size);
        params.setMargins(margin, 0, margin, 0);
        int length = iconIds.length;
        int i2 = 0;
        while (i2 < length) {
            byte id = iconIds[i2];
            final ImageView imageView = new ImageView(this);
            imageView.setLayoutParams(params);
            imageView.setPadding(padding, padding, padding, padding);
            imageView.setBackgroundResource(R.drawable.icon_background);
            imageView.setTag(Byte.valueOf(id));
            imageView.setSelected(id == selectedId ? true : z);
            imageView.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ControlsEditorActivity$$ExternalSyntheticLambda0
                @Override // android.view.View.OnClickListener
                public final void onClick(View view) {
                    ControlsEditorActivity.lambda_loadIcons_12(parent, imageView, view);
                }
            });
            try {
                InputStream is = getAssets().open(str2 + ((int) id) + ".png");
                try {
                    imageView.setImageBitmap(BitmapFactory.decodeStream(is));
                } finally {
                    if (is != null) is.close();
                }
                str = str2;
            } catch (IOException e3) {
                str = str2;
            }
            parent.addView(imageView);
            i2++;
            str2 = str;
            z = false;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_loadIcons_12(LinearLayout parent, ImageView imageView, View v) {
        for (int i = 0; i < parent.getChildCount(); i++) {
            parent.getChildAt(i).setSelected(false);
        }
        imageView.setSelected(true);
    }
}
