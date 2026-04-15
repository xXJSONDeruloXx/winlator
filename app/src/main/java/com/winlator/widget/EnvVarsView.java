package com.winlator.widget;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import android.widget.TextView;
import android.widget.ToggleButton;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.EnvVars;
import com.winlator.core.UnitUtils;
import java.util.Arrays;
import java.util.Objects;

/* JADX INFO: loaded from: classes.dex */
public class EnvVarsView extends FrameLayout {
    public static final String[][] knownEnvVars = {new String[]{"ZINK_DESCRIPTORS", "SELECT", "auto", "lazy", "cached", "notemplates"}, new String[]{"ZINK_DEBUG", "SELECT_MULTIPLE", "nir", "spirv", "tgsi", "validation", "sync", "compact", "noreorder"}, new String[]{"ZINK_CONTEXT_THREADED", "CHECKBOX", "0", "1"}, new String[]{"WINEESYNC", "CHECKBOX", "0", "1"}, new String[]{"WINEDLLOVERRIDES", "TEXT"}, new String[]{"TU_DEBUG", "SELECT_MULTIPLE", "startup", "nir", "nobin", "sysmem", "gmem", "forcebin", "layout", "noubwc", "nomultipos", "nolrz", "nolrzfc", "perf", "perfc", "flushall", "syncdraw", "push_consts_per_stage", "rast_order", "unaligned_store", "log_skip_gmem_ops", "dynamic", "bos", "3d_load", "fdm", "noconform", "rd"}, new String[]{"DXVK_HUD", "SELECT_MULTIPLE", "devinfo", "fps", "frametimes", "submissions", "drawcalls", "pipelines", "descriptors", "memory", "gpuload", "version", "api", "cs", "compiler", "samplers"}, new String[]{"DXVK_LOG_LEVEL", "SELECT", "none", "error", "warn", "info", "debug"}, new String[]{"DXVK_ASYNC", "CHECKBOX", "0", "1"}, new String[]{"GALLIUM_HUD", "TEXT"}, new String[]{"MESA_SHADER_CACHE_DISABLE", "CHECKBOX", "false", "true"}, new String[]{"mesa_glthread", "CHECKBOX", "false", "true"}, new String[]{"MESA_EXTENSION_MAX_YEAR", "NUMBER"}, new String[]{"MESA_GL_VERSION_OVERRIDE", "TEXT"}, new String[]{"PULSE_LATENCY_MSEC", "NUMBER"}};
    private final LinearLayout container;
    private final TextView emptyTextView;
    private final LayoutInflater inflater;

    /* JADX INFO: Access modifiers changed from: private */
    interface GetValueCallback {
        String call();
    }

    public EnvVarsView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public EnvVarsView(Context context, AttributeSet attrs, int defStyleAttr) {
        this(context, attrs, defStyleAttr, 0);
    }

    public EnvVarsView(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        this.inflater = LayoutInflater.from(context);
        LinearLayout linearLayout = new LinearLayout(context);
        this.container = linearLayout;
        linearLayout.setOrientation(1);
        linearLayout.setLayoutParams(new LinearLayout.LayoutParams(-1, -2));
        addView(linearLayout);
        TextView textView = new TextView(context);
        this.emptyTextView = textView;
        textView.setText(R.string.no_items_to_display);
        textView.setTextSize(1, 16.0f);
        textView.setGravity(17);
        int padding = (int) UnitUtils.dpToPx(16.0f);
        textView.setPadding(padding, padding, padding, padding);
        addView(textView);
    }

    private String[] findKnownEnvVar(String name) {
        for (String[] values : knownEnvVars) {
            if (values[0].equals(name)) {
                return values;
            }
        }
        return null;
    }

    public String getEnvVars() {
        EnvVars envVars = new EnvVars();
        for (int i = 0; i < this.container.getChildCount(); i++) {
            View child = this.container.getChildAt(i);
            GetValueCallback getValueCallback = (GetValueCallback) child.getTag();
            String name = ((TextView) child.findViewById(R.id.TextView)).getText().toString();
            String value = getValueCallback.call().trim().replace(" ", "");
            if (!value.isEmpty()) {
                envVars.put(name, value);
            }
        }
        return envVars.toString();
    }

    public boolean containsName(String name) {
        for (int i = 0; i < this.container.getChildCount(); i++) {
            View child = this.container.getChildAt(i);
            String text = ((TextView) child.findViewById(R.id.TextView)).getText().toString();
            if (name.equals(text)) {
                return true;
            }
        }
        return false;
    }

    public void add(String name, String value) {
        Context context;
        final View itemView;
        final String[] knownEnvVar;
        String type;
        GetValueCallback getValueCallback;
        context = getContext();
        itemView = this.inflater.inflate(R.layout.env_vars_list_item, (ViewGroup) this.container, false);
        ((TextView) itemView.findViewById(R.id.TextView)).setText(name);
        knownEnvVar = findKnownEnvVar(name);
        type = knownEnvVar != null ? knownEnvVar[1] : "TEXT";
        switch (type) {
            case "CHECKBOX":
                final ToggleButton toggleButton = (ToggleButton) itemView.findViewById(R.id.ToggleButton);
                toggleButton.setVisibility(0);
                toggleButton.setChecked(value.equals("1") || value.equals("true"));
                getValueCallback = new GetValueCallback() { // from class: com.winlator.widget.EnvVarsView$$ExternalSyntheticLambda3
                    @Override // com.winlator.widget.EnvVarsView.GetValueCallback
                    public final String call() {
                        return EnvVarsView.lambda_add_0(toggleButton, knownEnvVar);
                    }
                };
                break;
            case "SELECT":
                String[] items = (String[]) Arrays.copyOfRange(knownEnvVar, 2, knownEnvVar.length);
                final Spinner spinner = (Spinner) itemView.findViewById(R.id.Spinner);
                spinner.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, items));
                AppUtils.setSpinnerSelectionFromValue(spinner, value);
                spinner.setVisibility(0);
                getValueCallback = new GetValueCallback() { // from class: com.winlator.widget.EnvVarsView$$ExternalSyntheticLambda2
                    @Override // com.winlator.widget.EnvVarsView.GetValueCallback
                    public final String call() {
                        return EnvVarsView.lambda_add_1(spinner);
                    }
                };
                break;
            case "SELECT_MULTIPLE":
                final MultiSelectionComboBox comboBox = (MultiSelectionComboBox) itemView.findViewById(R.id.MultiSelectionComboBox);
                comboBox.setItems((String[]) Arrays.copyOfRange(knownEnvVar, 2, knownEnvVar.length));
                comboBox.setSelectedItems(value.split(","));
                comboBox.setVisibility(0);
                Objects.requireNonNull(comboBox);
                getValueCallback = new GetValueCallback() { // from class: com.winlator.widget.EnvVarsView$$ExternalSyntheticLambda4
                    @Override // com.winlator.widget.EnvVarsView.GetValueCallback
                    public final String call() {
                        return comboBox.getSelectedItemsAsString();
                    }
                };
                break;
            case "TEXT":
            case "NUMBER":
            default:
                final EditText editText = (EditText) itemView.findViewById(R.id.EditText);
                editText.setVisibility(0);
                editText.setText(value);
                if (type.equals("NUMBER")) {
                    editText.setInputType(2);
                }
                getValueCallback = new GetValueCallback() { // from class: com.winlator.widget.EnvVarsView$$ExternalSyntheticLambda1
                    @Override // com.winlator.widget.EnvVarsView.GetValueCallback
                    public final String call() {
                        return EnvVarsView.lambda_add_2(editText);
                    }
                };
                break;
        }
        itemView.setTag(getValueCallback);
        itemView.findViewById(R.id.BTRemove).setOnClickListener(view -> lambda_add_3(itemView, view));
        this.container.addView(itemView);
        this.emptyTextView.setVisibility(8);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ String lambda_add_0(ToggleButton toggleButton, String[] knownEnvVar) {
        return toggleButton.isChecked() ? knownEnvVar[3] : knownEnvVar[2];
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ String lambda_add_1(Spinner spinner) {
        return spinner.getSelectedItem().toString();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ String lambda_add_2(EditText editText) {
        return editText.getText().toString();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_add_3(View itemView, View v) {
        this.container.removeView(itemView);
        if (this.container.getChildCount() == 0) {
            this.emptyTextView.setVisibility(0);
        }
    }

    public void setEnvVars(EnvVars envVars) {
        this.container.removeAllViews();
        for (String name : envVars) {
            add(name, envVars.get(name));
        }
    }
}
