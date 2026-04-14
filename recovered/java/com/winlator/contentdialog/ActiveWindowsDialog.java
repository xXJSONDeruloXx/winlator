package com.winlator.contentdialog;

import android.graphics.Bitmap;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.winlator.R;
import com.winlator.XServerDisplayActivity;
import com.winlator.core.Callback;
import com.winlator.core.ImageUtils;
import com.winlator.core.UnitUtils;
import com.winlator.renderer.GLRenderer;
import com.winlator.xserver.Drawable;
import com.winlator.xserver.Window;
import com.winlator.xserver.XLock;
import com.winlator.xserver.XServer;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class ActiveWindowsDialog extends ContentDialog {
    private final XServerDisplayActivity activity;

    public ActiveWindowsDialog(final XServerDisplayActivity activity) {
        super(activity, R.layout.active_windows_dialog);
        this.activity = activity;
        setCancelable(false);
        setTitle(R.string.active_windows);
        setIcon(R.drawable.icon_active_windows);
        Button showDesktopButton = (Button) findViewById(R.id.BTCancel);
        showDesktopButton.setVisibility(0);
        showDesktopButton.setText(R.string.show_desktop);
        showDesktopButton.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.contentdialog.ActiveWindowsDialog$$ExternalSyntheticLambda0
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                this.f$0.lambda$new$0(activity, view);
            }
        });
        ArrayList<Window> windows = collectActiveWindows();
        loadWindowViews(windows);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$new$0(XServerDisplayActivity activity, View v) {
        activity.getWinHandler().showDesktop();
        dismiss();
    }

    private void loadWindowViews(ArrayList<Window> windows) {
        LayoutInflater inflater;
        boolean z;
        boolean z2 = false;
        if (windows.isEmpty()) {
            findViewById(R.id.TVEmptyText).setVisibility(0);
            return;
        }
        XServer xServer = this.activity.getXServer();
        LinearLayout llWindowList = (LinearLayout) findViewById(R.id.LLWindowList);
        llWindowList.removeAllViews();
        GLRenderer renderer = xServer.getRenderer();
        LayoutInflater inflater2 = LayoutInflater.from(this.activity);
        float iconSize = UnitUtils.dpToPx(24.0f);
        int imageHeight = (int) UnitUtils.dpToPx(116.0f);
        int i = windows.size() - 1;
        while (i >= 0) {
            final Window window = windows.get(i);
            Window parent = window.getParent();
            View itemView = inflater2.inflate(R.layout.active_window_list_item, llWindowList, z2);
            ImageView ivIcon = (ImageView) itemView.findViewById(R.id.IVIcon);
            final ImageView ivWindow = (ImageView) itemView.findViewById(R.id.IVWindow);
            TextView tvName = (TextView) itemView.findViewById(R.id.TVName);
            String title = window.getName();
            if (title.isEmpty()) {
                title = parent.getName();
            }
            tvName.setText(title);
            Bitmap icon = xServer.pixmapManager.getWindowIcon(window);
            if (icon == null) {
                icon = xServer.pixmapManager.getWindowIcon(parent);
            }
            XServer xServer2 = xServer;
            ivIcon.setImageResource(R.drawable.taskmgr_process);
            if (icon != null) {
                ivIcon.setImageBitmap(icon);
            }
            if (!window.isIconic()) {
                Drawable content = window.getContent();
                inflater = inflater2;
                int[] scaledSize = ImageUtils.getScaledSize(content.width, content.height, 0.0f, imageHeight);
                tvName.setMaxWidth((int) (scaledSize[0] - iconSize));
                z = true;
                ivWindow.setLayoutParams(new FrameLayout.LayoutParams(scaledSize[0], scaledSize[1]));
                renderer.takeWindowScreenshot(content, new Callback() { // from class: com.winlator.contentdialog.ActiveWindowsDialog$$ExternalSyntheticLambda2
                    @Override // com.winlator.core.Callback
                    public final void call(Object obj) {
                        ActiveWindowsDialog.lambda$loadWindowViews$2(ivWindow, (Bitmap) obj);
                    }
                });
                z2 = false;
            } else {
                inflater = inflater2;
                z = true;
                z2 = false;
                itemView.findViewById(R.id.IVHidden).setVisibility(0);
                itemView.findViewById(R.id.IVDashedFrame).setVisibility(0);
                tvName.setMaxWidth((int) (imageHeight - iconSize));
                ivWindow.setLayoutParams(new FrameLayout.LayoutParams(imageHeight, imageHeight));
            }
            ivWindow.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.contentdialog.ActiveWindowsDialog$$ExternalSyntheticLambda1
                @Override // android.view.View.OnClickListener
                public final void onClick(View view) {
                    this.f$0.lambda$loadWindowViews$3(window, view);
                }
            });
            llWindowList.addView(itemView);
            i--;
            xServer = xServer2;
            inflater2 = inflater;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$loadWindowViews$2(final ImageView ivWindow, final Bitmap bitmap) {
        ivWindow.post(new Runnable() { // from class: com.winlator.contentdialog.ActiveWindowsDialog$$ExternalSyntheticLambda3
            @Override // java.lang.Runnable
            public final void run() {
                ivWindow.setImageBitmap(bitmap);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$loadWindowViews$3(Window window, View v) {
        this.activity.getWinHandler().bringToFront(window.getClassName(), window.getHandle());
        dismiss();
    }

    private void collectActiveWindows(Window window, ArrayList<Window> result) {
        if (window.isRenderable()) {
            XServer xServer = this.activity.getXServer();
            if ((window != xServer.windowManager.rootWindow && !window.isDesktopWindow() && !window.getName().isEmpty()) || window.isSurface()) {
                result.add(window);
            }
            for (Window child : window.getChildren()) {
                collectActiveWindows(child, result);
            }
        }
    }

    private ArrayList<Window> collectActiveWindows() {
        XServer xServer = this.activity.getXServer();
        ArrayList<Window> result = new ArrayList<>();
        XLock lock = xServer.lock(XServer.Lockable.WINDOW_MANAGER, XServer.Lockable.DRAWABLE_MANAGER);
        try {
            collectActiveWindows(xServer.windowManager.rootWindow, result);
            if (lock != null) {
                lock.close();
            }
            return result;
        } catch (Throwable th) {
            if (lock != null) {
                try {
                    lock.close();
                } catch (Throwable th2) {
                    th.addSuppressed(th2);
                }
            }
            throw th;
        }
    }
}
