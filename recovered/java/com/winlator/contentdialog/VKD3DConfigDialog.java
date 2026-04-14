package com.winlator.contentdialog;

import android.content.Context;
import android.view.View;
import android.widget.Spinner;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.EnvVars;
import com.winlator.core.GeneralComponents;
import com.winlator.core.KeyValueSet;
import com.winlator.xenvironment.RootFS;

/* JADX INFO: loaded from: classes.dex */
public class VKD3DConfigDialog extends ContentDialog {
    public VKD3DConfigDialog(final View anchor) {
        super(anchor.getContext(), R.layout.vkd3d_config_dialog);
        Context context = anchor.getContext();
        setIcon(R.drawable.icon_display_settings);
        setTitle("VKD3D " + context.getString(R.string.configuration));
        final Spinner sVersion = (Spinner) findViewById(R.id.SVersion);
        final Spinner sFeatureLevel = (Spinner) findViewById(R.id.SFeatureLevel);
        KeyValueSet config = new KeyValueSet(anchor.getTag());
        AppUtils.setSpinnerSelectionFromValue(sFeatureLevel, config.get("featureLevel", "12.2"));
        String version = config.get("version");
        GeneralComponents.initViews(GeneralComponents.Type.VKD3D, findViewById(R.id.VKD3DToolbox), sVersion, version, "2.14.1");
        setOnConfirmCallback(new Runnable() { // from class: com.winlator.contentdialog.VKD3DConfigDialog$$ExternalSyntheticLambda0
            @Override // java.lang.Runnable
            public final void run() {
                VKD3DConfigDialog.lambda$new$0(sVersion, sFeatureLevel, anchor);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$new$0(Spinner sVersion, Spinner sFeatureLevel, View anchor) {
        KeyValueSet newConfig = new KeyValueSet();
        newConfig.put("version", sVersion.getSelectedItem().toString());
        newConfig.put("featureLevel", sFeatureLevel.getSelectedItem().toString());
        anchor.setTag(newConfig.toString());
    }

    public static void setEnvVars(KeyValueSet config, EnvVars envVars) {
        envVars.put("DXVK_LOG_LEVEL", "none");
        envVars.put("DXVK_STATE_CACHE_PATH", RootFS.getDosUserCachePath());
        envVars.put("VKD3D_FEATURE_LEVEL", config.get("featureLevel", "12.2").replace(".", "_"));
        envVars.put("VKD3D_SHADER_CACHE_PATH", RootFS.getDosUserCachePath());
    }
}
