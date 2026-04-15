package com.winlator.container;

import android.content.Context;
import android.widget.LinearLayout;
import com.winlator.core.KeyValueSet;
import com.winlator.core.StringUtils;
import com.winlator.widget.TaggedSelectionBox;

/* JADX INFO: loaded from: classes.dex */
public class DXWrapperPicker {
    private final LinearLayout container;

    public DXWrapperPicker(LinearLayout container, final GraphicsDriverPicker graphicsDriverPicker, String selectedDXWrapper, String dxwrapperConfig) {
        this.container = container;
        Context context = container.getContext();
        container.removeAllViews();
        KeyValueSet[] configs = DXWrappers.parseConfigs(selectedDXWrapper, dxwrapperConfig);
        String selectedDXWrapper2 = DXWrappers.parseIdentifier(selectedDXWrapper);
        String[] apiNames = {"Direct3D", "DirectX 12"};
        for (int i = 0; i < apiNames.length; i++) {
            final TaggedSelectionBox taggedSelectionBox = new TaggedSelectionBox(context);
            taggedSelectionBox.setLabel(apiNames[i]);
            taggedSelectionBox.setTag(configs[i].toString());
            if (i == 0) {
                taggedSelectionBox.setItems(DXWrappers.getName("wined3d"), DXWrappers.getName("dxvk"));
                if (selectedDXWrapper2.equals("wined3d") || selectedDXWrapper2.equals("dxvk")) {
                    taggedSelectionBox.setSelectedItem(DXWrappers.getName(selectedDXWrapper2));
                } else {
                    taggedSelectionBox.setSelectedItem(DXWrappers.getName("dxvk"));
                }
                final String[] oldDXWrapper = {selectedDXWrapper2};
                taggedSelectionBox.setOnItemSelectedListener(new TaggedSelectionBox.OnItemSelectedListener() { // from class: com.winlator.container.DXWrapperPicker$$ExternalSyntheticLambda1
                    @Override // com.winlator.widget.TaggedSelectionBox.OnItemSelectedListener
                    public final void onItemSelected(String str) {
                        DXWrapperPicker.lambda_new_0(oldDXWrapper, taggedSelectionBox, str);
                    }
                });
            } else {
                taggedSelectionBox.setItems(DXWrappers.getName("vkd3d"));
                taggedSelectionBox.setSelectedItem(taggedSelectionBox.getItems()[0]);
            }
            taggedSelectionBox.setOnButtonClickListener(new TaggedSelectionBox.OnButtonClickListener() { // from class: com.winlator.container.DXWrapperPicker$$ExternalSyntheticLambda0
                @Override // com.winlator.widget.TaggedSelectionBox.OnButtonClickListener
                public final void onClick() {
                    DXWrapperPicker.lambda_new_1(taggedSelectionBox, graphicsDriverPicker);
                }
            });
            container.addView(taggedSelectionBox);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_0(String[] oldDXWrapper, TaggedSelectionBox taggedSelectionBox, String item) {
        String dxwrapper = StringUtils.parseIdentifier(item);
        if (!oldDXWrapper[0].equals(dxwrapper)) {
            taggedSelectionBox.setTag("");
        }
        oldDXWrapper[0] = dxwrapper;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_1(TaggedSelectionBox taggedSelectionBox, GraphicsDriverPicker graphicsDriverPicker) {
        String dxwrapper = StringUtils.parseIdentifier(taggedSelectionBox.getSelectedItem());
        String graphicsDriver = GraphicsDrivers.parseIdentifiers(graphicsDriverPicker.getGraphicsDriver())[0];
        showDXWrapperConfigDialog(dxwrapper, graphicsDriver, taggedSelectionBox);
    }

    public String getDXWrapper() {
        TaggedSelectionBox taggedSelectionBox = (TaggedSelectionBox) this.container.getChildAt(0);
        return StringUtils.parseIdentifier(taggedSelectionBox.getSelectedItem());
    }

    public String getDXWrapperConfig() {
        StringBuilder dxwrapperConfig = new StringBuilder();
        for (int i = 0; i < this.container.getChildCount(); i++) {
            TaggedSelectionBox taggedSelectionBox = (TaggedSelectionBox) this.container.getChildAt(i);
            if (dxwrapperConfig.length() > 0) {
                dxwrapperConfig.append('|');
            }
            dxwrapperConfig.append(taggedSelectionBox.getTag().toString());
        }
        return dxwrapperConfig.toString();
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Removed duplicated region for block: B:14:0x0026  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    private static void showDXWrapperConfigDialog(java.lang.String r1, java.lang.String r2, android.view.View r3) {
        /*
            int r0 = r1.hashCode()
            switch(r0) {
                case 3098185: goto L1c;
                case 112260896: goto L12;
                case 1349510476: goto L8;
                default: goto L7;
            }
        L7:
            goto L26
        L8:
            java.lang.String r0 = "wined3d"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 2
            goto L27
        L12:
            java.lang.String r0 = "vkd3d"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 1
            goto L27
        L1c:
            java.lang.String r0 = "dxvk"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 0
            goto L27
        L26:
            r0 = -1
        L27:
            switch(r0) {
                case 0: goto L3d;
                case 1: goto L34;
                case 2: goto L2b;
                default: goto L2a;
            }
        L2a:
            goto L46
        L2b:
            com.winlator.contentdialog.WineD3DConfigDialog r0 = new com.winlator.contentdialog.WineD3DConfigDialog
            r0.<init>(r3)
            r0.show()
            goto L46
        L34:
            com.winlator.contentdialog.VKD3DConfigDialog r0 = new com.winlator.contentdialog.VKD3DConfigDialog
            r0.<init>(r3)
            r0.show()
            goto L46
        L3d:
            com.winlator.contentdialog.DXVKConfigDialog r0 = new com.winlator.contentdialog.DXVKConfigDialog
            r0.<init>(r2, r3)
            r0.show()
        L46:
            return
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.container.DXWrapperPicker.showDXWrapperConfigDialog(java.lang.String, java.lang.String, android.view.View):void");
    }
}
