package com.winlator.contentdialog;

import android.content.Context;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.CheckBox;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.EnvVars;
import com.winlator.core.GeneralComponents;
import com.winlator.core.KeyValueSet;
import com.winlator.core.StringUtils;
import com.winlator.widget.GPUCardAdapter;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;

/* JADX INFO: loaded from: classes.dex */
public class WineD3DConfigDialog extends ContentDialog {
    public WineD3DConfigDialog(final View anchor) {
        super(anchor.getContext(), R.layout.wined3d_config_dialog);
        Context context = anchor.getContext();
        setIcon(R.drawable.icon_display_settings);
        setTitle("WineD3D " + context.getString(R.string.configuration));
        final Spinner sVersion = (Spinner) findViewById(R.id.SVersion);
        final Spinner sDDrawWrapper = (Spinner) findViewById(R.id.SDDrawWrapper);
        final Spinner sRenderer = (Spinner) findViewById(R.id.SRenderer);
        KeyValueSet config = new KeyValueSet(anchor.getTag());
        String version = config.get("version");
        GeneralComponents.initViews(GeneralComponents.Type.WINED3D, findViewById(R.id.WineD3DToolbox), sVersion, version, "10.10");
        AppUtils.setSpinnerSelectionFromIdentifier(sDDrawWrapper, config.get("ddrawWrapper", "wined3d"));
        AppUtils.setSpinnerSelectionFromIdentifier(sRenderer, config.get("renderer", "gl"));
        final CheckBox cbCSMT = (CheckBox) findViewById(R.id.CBCSMT);
        cbCSMT.setChecked(config.getInt("csmt", 3) != 0);
        GPUCardAdapter adapter = new GPUCardAdapter(context, android.R.layout.simple_spinner_dropdown_item);
        final Spinner sGPUName = (Spinner) findViewById(R.id.SGPUName);
        sGPUName.setAdapter((SpinnerAdapter) adapter);
        sGPUName.setSelection(adapter.getPositionByDeviceId(config.getInt("VideoPciDeviceID", 1728)));
        List<String> offscreenRenderingModeList = Arrays.asList("Backbuffer", "FBO");
        final Spinner sOffscreenRenderingMode = (Spinner) findViewById(R.id.SOffscreenRenderingMode);
        sOffscreenRenderingMode.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, offscreenRenderingModeList));
        AppUtils.setSpinnerSelectionFromValue(sOffscreenRenderingMode, config.get("OffscreenRenderingMode", "fbo"));
        final CheckBox cbStrictShaderMath = (CheckBox) findViewById(R.id.CBStrictShaderMath);
        cbStrictShaderMath.setChecked(config.getInt("strict_shader_math", 1) != 0);
        final Spinner sVideoMemorySize = (Spinner) findViewById(R.id.SVideoMemorySize);
        String videoMemorySize = config.get("VideoMemorySize", "2048");
        AppUtils.setSpinnerSelectionFromMemorySize(sVideoMemorySize, videoMemorySize);
        setOnConfirmCallback(new Runnable() { // from class: com.winlator.contentdialog.WineD3DConfigDialog$$ExternalSyntheticLambda0
            @Override // java.lang.Runnable
            public final void run() {
                WineD3DConfigDialog.lambda$new$0(sVersion, cbCSMT, sDDrawWrapper, sRenderer, sGPUName, sOffscreenRenderingMode, cbStrictShaderMath, sVideoMemorySize, anchor);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$new$0(Spinner sVersion, CheckBox cbCSMT, Spinner sDDrawWrapper, Spinner sRenderer, Spinner sGPUName, Spinner sOffscreenRenderingMode, CheckBox cbStrictShaderMath, Spinner sVideoMemorySize, View anchor) {
        KeyValueSet newConfig = new KeyValueSet();
        newConfig.put("version", sVersion.getSelectedItem().toString());
        newConfig.put("csmt", cbCSMT.isChecked() ? "3" : "0");
        String ddrawWrapper = StringUtils.parseIdentifier(sDDrawWrapper.getSelectedItem());
        if (!ddrawWrapper.equals("wined3d")) {
            newConfig.put("ddrawWrapper", ddrawWrapper);
        }
        String renderer = StringUtils.parseIdentifier(sRenderer.getSelectedItem());
        if (!renderer.equals("gl")) {
            newConfig.put("renderer", renderer);
        }
        GPUCardAdapter.GPUCard gpuCard = (GPUCardAdapter.GPUCard) sGPUName.getSelectedItem();
        newConfig.put("VideoPciDeviceID", String.valueOf(gpuCard.deviceId));
        newConfig.put("VideoPciVendorID", String.valueOf(gpuCard.vendorId));
        newConfig.put("OffscreenRenderingMode", sOffscreenRenderingMode.getSelectedItem().toString().toLowerCase(Locale.ENGLISH));
        newConfig.put("strict_shader_math", cbStrictShaderMath.isChecked() ? "1" : "0");
        newConfig.put("VideoMemorySize", StringUtils.parseMemorySize(sVideoMemorySize.getSelectedItem()));
        anchor.setTag(newConfig.toString());
    }

    public static void setEnvVars(KeyValueSet config, EnvVars envVars) {
        envVars.put("WINE_D3D_CONFIG", String.join(",", "renderer=" + config.get("renderer", "gl"), "csmt=" + config.getHexString("csmt", 3), "VideoPciDeviceID=" + config.getHexString("VideoPciDeviceID", 1728), "VideoPciVendorID=" + config.getHexString("VideoPciVendorID", 4318), "OffscreenRenderingMode=" + config.get("OffscreenRenderingMode", "fbo"), "strict_shader_math=" + config.getHexString("strict_shader_math", 1), "VideoMemorySize=" + config.get("VideoMemorySize", "2048")));
    }
}
