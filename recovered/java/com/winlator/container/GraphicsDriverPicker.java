package com.winlator.container;

import android.content.Context;
import android.widget.LinearLayout;
import com.winlator.core.KeyValueSet;
import com.winlator.core.StringUtils;
import com.winlator.widget.TaggedSelectionBox;

/* JADX INFO: loaded from: classes.dex */
public class GraphicsDriverPicker {
    private final LinearLayout container;

    public GraphicsDriverPicker(LinearLayout container, String selectedGraphicsDriver, String graphicsDriverConfig) {
        this.container = container;
        Context context = container.getContext();
        container.removeAllViews();
        String[] identifiers = GraphicsDrivers.parseIdentifiers(selectedGraphicsDriver);
        KeyValueSet[] configs = GraphicsDrivers.parseConfigs(selectedGraphicsDriver, graphicsDriverConfig);
        String[] apiNames = {"Vulkan", "OpenGL"};
        for (int i = 0; i < apiNames.length; i++) {
            final TaggedSelectionBox taggedSelectionBox = new TaggedSelectionBox(context);
            taggedSelectionBox.setLabel(apiNames[i]);
            taggedSelectionBox.setItems(GraphicsDrivers.getItems(apiNames[i]));
            taggedSelectionBox.setSelectedItem(GraphicsDrivers.getName(identifiers[i]));
            taggedSelectionBox.setTag(configs[i].toString());
            taggedSelectionBox.setOnButtonClickListener(new TaggedSelectionBox.OnButtonClickListener() { // from class: com.winlator.container.GraphicsDriverPicker$$ExternalSyntheticLambda0
                @Override // com.winlator.widget.TaggedSelectionBox.OnButtonClickListener
                public final void onClick() {
                    GraphicsDriverPicker.lambda$new$0(taggedSelectionBox);
                }
            });
            container.addView(taggedSelectionBox);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$new$0(TaggedSelectionBox taggedSelectionBox) {
        String graphicsDriver = StringUtils.parseIdentifier(taggedSelectionBox.getSelectedItem());
        showGraphicsDriverConfigDialog(graphicsDriver, taggedSelectionBox);
    }

    public String getGraphicsDriver() {
        StringBuilder graphicsDriver = new StringBuilder();
        for (int i = 0; i < this.container.getChildCount(); i++) {
            TaggedSelectionBox taggedSelectionBox = (TaggedSelectionBox) this.container.getChildAt(i);
            if (graphicsDriver.length() > 0) {
                graphicsDriver.append(',');
            }
            graphicsDriver.append(StringUtils.parseIdentifier(taggedSelectionBox.getSelectedItem()));
        }
        return graphicsDriver.toString();
    }

    public String getGraphicsDriverConfig() {
        StringBuilder graphicsDriverConfig = new StringBuilder();
        for (int i = 0; i < this.container.getChildCount(); i++) {
            TaggedSelectionBox taggedSelectionBox = (TaggedSelectionBox) this.container.getChildAt(i);
            if (graphicsDriverConfig.length() > 0) {
                graphicsDriverConfig.append('|');
            }
            graphicsDriverConfig.append(taggedSelectionBox.getTag().toString());
        }
        return graphicsDriverConfig.toString();
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Removed duplicated region for block: B:14:0x0026  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    private static void showGraphicsDriverConfigDialog(java.lang.String r1, android.view.View r2) {
        /*
            int r0 = r1.hashCode()
            switch(r0) {
                case -862428572: goto L1c;
                case -810705759: goto L12;
                case 112216388: goto L8;
                default: goto L7;
            }
        L7:
            goto L26
        L8:
            java.lang.String r0 = "virgl"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 2
            goto L27
        L12:
            java.lang.String r0 = "vortek"
            boolean r0 = r1.equals(r0)
            if (r0 == 0) goto L7
            r0 = 1
            goto L27
        L1c:
            java.lang.String r0 = "turnip"
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
            com.winlator.contentdialog.VirGLConfigDialog r0 = new com.winlator.contentdialog.VirGLConfigDialog
            r0.<init>(r2)
            r0.show()
            goto L46
        L34:
            com.winlator.contentdialog.VortekConfigDialog r0 = new com.winlator.contentdialog.VortekConfigDialog
            r0.<init>(r2)
            r0.show()
            goto L46
        L3d:
            com.winlator.contentdialog.TurnipConfigDialog r0 = new com.winlator.contentdialog.TurnipConfigDialog
            r0.<init>(r2)
            r0.show()
        L46:
            return
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.container.GraphicsDriverPicker.showGraphicsDriverConfigDialog(java.lang.String, android.view.View):void");
    }
}
