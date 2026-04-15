package com.winlator.core;

import android.R;
import android.app.Activity;
import android.app.Dialog;
import android.view.Window;
import android.widget.TextView;

/* JADX INFO: loaded from: classes.dex */
public class PreloaderDialog {
    private final Activity activity;
    private Dialog dialog;

    public PreloaderDialog(Activity activity) {
        this.activity = activity;
    }

    private void create() {
        if (this.dialog != null) {
            return;
        }
        Dialog dialog = new Dialog(this.activity, android.R.style.Theme_Translucent_NoTitleBar_Fullscreen);
        this.dialog = dialog;
        dialog.requestWindowFeature(1);
        this.dialog.setCancelable(false);
        this.dialog.setCanceledOnTouchOutside(false);
        this.dialog.setContentView(com.winlator.R.layout.preloader_dialog);
        Window window = this.dialog.getWindow();
        if (window != null) {
            window.clearFlags(16);
            window.clearFlags(8);
        }
    }

    public synchronized void show(int textResId) {
        if (isShowing()) {
            return;
        }
        close();
        if (this.dialog == null) {
            create();
        }
        ((TextView) this.dialog.findViewById(com.winlator.R.id.TextView)).setText(textResId);
        this.dialog.show();
    }

    public void showOnUiThread(final int textResId) {
        this.activity.runOnUiThread(() -> show(textResId));
    }

    public synchronized void close() {
        try {
            Dialog dialog = this.dialog;
            if (dialog != null) {
                dialog.dismiss();
            }
        } catch (Exception e) {
        }
    }

    public void closeOnUiThread() {
        this.activity.runOnUiThread(() -> close());
    }

    public boolean isShowing() {
        Dialog dialog = this.dialog;
        return dialog != null && dialog.isShowing();
    }
}
