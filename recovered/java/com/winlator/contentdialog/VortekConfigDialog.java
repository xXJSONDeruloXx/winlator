package com.winlator.contentdialog;

import android.content.Context;
import android.view.View;
import android.widget.Spinner;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.GPUHelper;
import com.winlator.core.GeneralComponents;
import com.winlator.core.KeyValueSet;
import com.winlator.core.StringUtils;
import com.winlator.widget.MultiSelectionComboBox;
import com.winlator.xenvironment.components.VortekRendererComponent;

/* JADX INFO: loaded from: classes.dex */
public class VortekConfigDialog extends ContentDialog {
    public static final String DEFAULT_VK_MAX_VERSION;

    static {
        StringBuilder sb = new StringBuilder();
        int i = VortekRendererComponent.VK_MAX_VERSION;
        sb.append(GPUHelper.vkVersionMajor(i));
        sb.append(".");
        sb.append(GPUHelper.vkVersionMinor(i));
        DEFAULT_VK_MAX_VERSION = sb.toString();
    }

    public VortekConfigDialog(final View anchor) {
        super(anchor.getContext(), R.layout.vortek_config_dialog);
        Context context = anchor.getContext();
        setIcon(R.drawable.icon_display_settings);
        setTitle("Vortek " + context.getString(R.string.configuration));
        final Spinner sAdrenotoolsDriver = (Spinner) findViewById(R.id.SAdrenotoolsDriver);
        final Spinner sVkMaxVersion = (Spinner) findViewById(R.id.SVkMaxVersion);
        final Spinner sMaxDeviceMemory = (Spinner) findViewById(R.id.SMaxDeviceMemory);
        final Spinner sImageCacheSize = (Spinner) findViewById(R.id.SImageCacheSize);
        final Spinner sResourceMemoryType = (Spinner) findViewById(R.id.SResourceMemoryType);
        final MultiSelectionComboBox mscbExposedExtensions = (MultiSelectionComboBox) findViewById(R.id.MSCBExposedExtensions);
        final String[] deviceExtensions = GPUHelper.vkGetDeviceExtensions();
        mscbExposedExtensions.setPopupWindowWidth(360);
        mscbExposedExtensions.setDisplayText(context.getString(R.string.multiselection_combobox_display_text));
        mscbExposedExtensions.setItems(deviceExtensions);
        KeyValueSet config = new KeyValueSet(anchor.getTag());
        String exposedDeviceExtensionsVal = config.get("exposedDeviceExtensions", "all");
        if (exposedDeviceExtensionsVal.equals("all")) {
            mscbExposedExtensions.setSelectedItems(deviceExtensions);
        } else if (!exposedDeviceExtensionsVal.isEmpty()) {
            mscbExposedExtensions.setSelectedItems(exposedDeviceExtensionsVal.split("\\|"));
        }
        String adrenotoolsDriver = config.get("adrenotoolsDriver");
        GeneralComponents.initViews(GeneralComponents.Type.ADRENOTOOLS_DRIVER, findViewById(R.id.AdrenotoolsDriverToolbox), sAdrenotoolsDriver, adrenotoolsDriver, "System");
        AppUtils.setSpinnerSelectionFromValue(sVkMaxVersion, config.get("vkMaxVersion", DEFAULT_VK_MAX_VERSION));
        AppUtils.setSpinnerSelectionFromMemorySize(sMaxDeviceMemory, config.get("maxDeviceMemory", "0"));
        AppUtils.setSpinnerSelectionFromNumber(sImageCacheSize, config.get("imageCacheSize", String.valueOf(256)));
        sResourceMemoryType.setSelection(config.getInt("resourceMemoryType"));
        setOnConfirmCallback(new Runnable() { // from class: com.winlator.contentdialog.VortekConfigDialog$$ExternalSyntheticLambda0
            @Override // java.lang.Runnable
            public final void run() {
                VortekConfigDialog.lambda$new$0(sAdrenotoolsDriver, sVkMaxVersion, sMaxDeviceMemory, sImageCacheSize, sResourceMemoryType, mscbExposedExtensions, deviceExtensions, anchor);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$new$0(Spinner sAdrenotoolsDriver, Spinner sVkMaxVersion, Spinner sMaxDeviceMemory, Spinner sImageCacheSize, Spinner sResourceMemoryType, MultiSelectionComboBox mscbExposedExtensions, String[] deviceExtensions, View anchor) {
        KeyValueSet newConfig = new KeyValueSet();
        newConfig.put("adrenotoolsDriver", sAdrenotoolsDriver.getSelectedItem());
        newConfig.put("vkMaxVersion", StringUtils.parseNumber(sVkMaxVersion.getSelectedItem(), "0"));
        newConfig.put("maxDeviceMemory", StringUtils.parseMemorySize(sMaxDeviceMemory.getSelectedItem()));
        newConfig.put("imageCacheSize", StringUtils.parseNumber(sImageCacheSize.getSelectedItem()));
        newConfig.put("resourceMemoryType", Integer.valueOf(sResourceMemoryType.getSelectedItemPosition()));
        String[] selectedItems = mscbExposedExtensions.getSelectedItems();
        if (selectedItems.length > 0) {
            if (selectedItems.length == deviceExtensions.length) {
                newConfig.put("exposedDeviceExtensions", "all");
            } else {
                newConfig.put("exposedDeviceExtensions", String.join("|", selectedItems));
            }
        }
        anchor.setTag(newConfig.toString());
    }

    public static boolean isRequireRestart(String oldGraphicsDriverConfig, String newGraphicsDriverConfig) {
        if (oldGraphicsDriverConfig.equals(newGraphicsDriverConfig)) {
            return false;
        }
        String oldAdrenotoolsDriver = new KeyValueSet(oldGraphicsDriverConfig).get("adrenotoolsDriver");
        String newAdrenotoolsDriver = new KeyValueSet(newGraphicsDriverConfig).get("adrenotoolsDriver");
        return (oldAdrenotoolsDriver.isEmpty() || newAdrenotoolsDriver.isEmpty() || newAdrenotoolsDriver.equals(oldAdrenotoolsDriver)) ? false : true;
    }
}
