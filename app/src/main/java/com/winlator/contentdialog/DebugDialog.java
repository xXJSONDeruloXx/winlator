package com.winlator.contentdialog;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.LinearLayout;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import com.winlator.core.UnitUtils;
import com.winlator.widget.LogView;

/* JADX INFO: loaded from: classes.dex */
public class DebugDialog extends ContentDialog implements Callback<String> {
    private final LogView logView;
    private boolean paused;

    public DebugDialog(Context context) {
        super(context, R.layout.debug_dialog);
        this.paused = false;
        setIcon(R.drawable.icon_debug);
        setTitle(context.getString(R.string.logs));
        LogView logView = (LogView) findViewById(R.id.LogView);
        this.logView = logView;
        logView.getLayoutParams().width = (int) UnitUtils.dpToPx(UnitUtils.pxToDp(AppUtils.getScreenWidth()) * 0.7f);
        findViewById(R.id.BTCancel).setVisibility(8);
        LinearLayout llBottomBarPanel = (LinearLayout) findViewById(R.id.LLBottomBarPanel);
        llBottomBarPanel.setVisibility(0);
        View toolbarView = LayoutInflater.from(context).inflate(R.layout.debug_toolbar, (ViewGroup) llBottomBarPanel, false);
        toolbarView.findViewById(R.id.BTClear).setOnClickListener(view -> lambda_new_0(view));
        toolbarView.findViewById(R.id.BTPause).setOnClickListener(view -> lambda_new_1(view));
        toolbarView.findViewById(R.id.BTExport).setOnClickListener(view -> lambda_new_2(view));
        llBottomBarPanel.addView(toolbarView);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_0(View v) {
        this.logView.clear();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_1(View v) {
        boolean z = !this.paused;
        this.paused = z;
        ((ImageButton) v).setImageResource(z ? R.drawable.icon_play : R.drawable.icon_pause);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_2(View v) {
        this.logView.exportToFile();
    }

    @Override // com.winlator.core.Callback
    public void call(String line) {
        if (!this.paused) {
            this.logView.append(line + "\n");
        }
    }
}
