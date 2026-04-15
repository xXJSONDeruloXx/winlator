package com.winlator.contentdialog;

import android.content.Context;
import android.view.View;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.DefaultVersion;
import com.winlator.core.EnvVars;
import com.winlator.core.FileUtils;
import com.winlator.core.GeneralComponents;
import com.winlator.core.KeyValueSet;
import com.winlator.core.StringUtils;
import com.winlator.widget.GPUCardAdapter;
import com.winlator.xenvironment.RootFS;
import java.io.File;

/* JADX INFO: loaded from: classes.dex */
public class DXVKConfigDialog extends ContentDialog {
    public DXVKConfigDialog(String graphicsDriver, final View anchor) {
        super(anchor.getContext(), R.layout.dxvk_config_dialog);
        setIcon(R.drawable.icon_display_settings);
        Context context = anchor.getContext();
        setTitle("DXVK " + context.getString(R.string.configuration));
        final Spinner sVersion = (Spinner) findViewById(R.id.SVersion);
        final Spinner sFramerate = (Spinner) findViewById(R.id.SFramerate);
        final Spinner sMaxDeviceMemory = (Spinner) findViewById(R.id.SMaxDeviceMemory);
        final Spinner sCustomDevice = (Spinner) findViewById(R.id.SCustomDevice);
        final Spinner sDDrawWrapper = (Spinner) findViewById(R.id.SDDrawWrapper);
        KeyValueSet config = new KeyValueSet(anchor.getTag());
        AppUtils.setSpinnerSelectionFromIdentifier(sFramerate, config.get("framerate", "0"));
        AppUtils.setSpinnerSelectionFromMemorySize(sMaxDeviceMemory, config.get("maxDeviceMemory", "0"));
        AppUtils.setSpinnerSelectionFromIdentifier(sDDrawWrapper, config.get("ddrawWrapper", "wined3d"));
        String version = config.get("version");
        String defaultVersion = DefaultVersion.DXVK(graphicsDriver);
        GeneralComponents.initViews(GeneralComponents.Type.DXVK, findViewById(R.id.DXVKToolbox), sVersion, version, defaultVersion);
        GPUCardAdapter adapter = new GPUCardAdapter(context, android.R.layout.simple_spinner_dropdown_item, R.string.none);
        sCustomDevice.setAdapter((SpinnerAdapter) adapter);
        String customDevice = config.get("customDevice");
        if (customDevice.contains(":")) {
            try {
                int deviceId = Integer.parseInt(customDevice.split(":")[0], 16);
                sCustomDevice.setSelection(adapter.getPositionByDeviceId(deviceId));
            } catch (NumberFormatException e) {
            }
        }
        setOnConfirmCallback(new Runnable() { // from class: com.winlator.contentdialog.DXVKConfigDialog$$ExternalSyntheticLambda0
            @Override // java.lang.Runnable
            public final void run() {
                DXVKConfigDialog.lambda_new_0(sVersion, sFramerate, sMaxDeviceMemory, sDDrawWrapper, sCustomDevice, anchor);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_0(Spinner sVersion, Spinner sFramerate, Spinner sMaxDeviceMemory, Spinner sDDrawWrapper, Spinner sCustomDevice, View anchor) {
        KeyValueSet newConfig = new KeyValueSet();
        newConfig.put("version", sVersion.getSelectedItem().toString());
        newConfig.put("framerate", StringUtils.parseNumber(sFramerate.getSelectedItem()));
        newConfig.put("maxDeviceMemory", StringUtils.parseMemorySize(sMaxDeviceMemory.getSelectedItem()));
        String ddrawWrapper = StringUtils.parseIdentifier(sDDrawWrapper.getSelectedItem());
        if (!ddrawWrapper.equals("wined3d")) {
            newConfig.put("ddrawWrapper", ddrawWrapper);
        }
        GPUCardAdapter.GPUCard gpuCard = (GPUCardAdapter.GPUCard) sCustomDevice.getSelectedItem();
        if (gpuCard.deviceId > 0) {
            newConfig.put("customDevice", String.format("%04x", Integer.valueOf(gpuCard.deviceId)) + ":" + String.format("%04x", Integer.valueOf(gpuCard.vendorId)) + ":" + gpuCard.name);
        }
        anchor.setTag(newConfig.toString());
    }

    public static void setEnvVars(Context context, KeyValueSet config, EnvVars envVars) {
        if (config.get("version").contains("async")) {
            envVars.put("DXVK_ASYNC", "1");
        }
        envVars.put("DXVK_STATE_CACHE_PATH", RootFS.getDosUserCachePath());
        envVars.put("DXVK_LOG_LEVEL", "none");
        File rootDir = RootFS.find(context).getRootDir();
        File dxvkConfigFile = new File(rootDir, "/home/xuser/.config/dxvk.conf");
        FileUtils.delete(dxvkConfigFile);
        String content = getDXVKConfigContent(config);
        if (FileUtils.writeString(dxvkConfigFile, content)) {
            envVars.put("DXVK_CONFIG_FILE", RootFS.getDosUserConfigPath() + "\\dxvk.conf");
        }
    }

    private static String getDXVKConfigContent(KeyValueSet config) {
        String content = "";
        String maxDeviceMemory = config.get("maxDeviceMemory");
        if (!maxDeviceMemory.isEmpty() && !maxDeviceMemory.equals("0")) {
            content = ("dxgi.maxDeviceMemory = " + maxDeviceMemory + "\n") + "dxgi.maxSharedMemory = " + maxDeviceMemory + "\n";
        }
        String framerate = config.get("framerate");
        if (!framerate.isEmpty() && !framerate.equals("0")) {
            content = (content + "dxgi.maxFrameRate = " + framerate + "\n") + "d3d9.maxFrameRate = " + framerate + "\n";
        }
        String customDevice = config.get("customDevice");
        if (customDevice.contains(":")) {
            String[] parts = customDevice.split(":");
            content = (((((content + "dxgi.customDeviceId = " + parts[0] + "\n") + "dxgi.customVendorId = " + parts[1] + "\n") + "d3d9.customDeviceId = " + parts[0] + "\n") + "d3d9.customVendorId = " + parts[1] + "\n") + "dxgi.customDeviceDesc = \"" + parts[2] + "\"\n") + "d3d9.customDeviceDesc = \"" + parts[2] + "\"\n";
        }
        return (((content + "d3d11.constantBufferRangeCheck = \"True\"\n\n") + "[GTA5.exe]\n") + "dxgi.maxDeviceMemory = 512\n") + "dxgi.maxSharedMemory = 512\n";
    }
}
