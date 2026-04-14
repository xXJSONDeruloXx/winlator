package com.winlator.winhandler;

import android.app.ActivityManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.IntentFilter;
import android.graphics.Bitmap;
import android.os.Build;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupMenu;
import android.widget.TextView;
import com.winlator.R;
import com.winlator.XServerDisplayActivity;
import com.winlator.contentdialog.ContentDialog;
import com.winlator.core.BatteryUtils;
import com.winlator.core.CPUStatus;
import com.winlator.core.Callback;
import com.winlator.core.ProcessHelper;
import com.winlator.core.StringUtils;
import com.winlator.core.UnitUtils;
import com.winlator.widget.CPUListView;
import com.winlator.xserver.Window;
import com.winlator.xserver.XLock;
import com.winlator.xserver.XServer;
import java.util.ArrayList;
import java.util.Locale;
import java.util.Timer;
import java.util.TimerTask;

/* JADX INFO: loaded from: classes.dex */
public class TaskManagerDialog extends ContentDialog implements OnGetProcessInfoListener {
    private final XServerDisplayActivity activity;
    private final BatteryInfo batteryInfo;
    private final Panel batteryPanel;
    private BroadcastReceiver batteryReceiver;
    private final Panel cpuPanel;
    private final LayoutInflater inflater;
    private final Object lock;
    private final Panel memoryPanel;
    private Timer timer;

    /* JADX INFO: Access modifiers changed from: package-private */
    public static /* synthetic */ void access$1000(TaskManagerDialog x0) {
        x0.update();
    }

    private static class BatteryInfo {
        private int level;
        private int temperature;
        private float voltage;

        private BatteryInfo() {
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    static class Panel {
        private View[] itemViews;
        private PopupMenu popupMenu;
        private View view;

        private Panel() {
        }

        /* JADX INFO: Access modifiers changed from: private */
        public void setTitle(String title) {
            ((TextView) this.view.findViewById(R.id.TVTitle)).setText(title);
        }

        /* JADX INFO: Access modifiers changed from: private */
        public void setIconAt(int index, int icon) {
            ((ImageView) this.itemViews[index].findViewById(R.id.ImageView)).setImageResource(icon);
        }

        /* JADX INFO: Access modifiers changed from: private */
        public void setTextAt(int index, String value) {
            ((TextView) this.itemViews[index].findViewById(R.id.TextView)).setText(value);
        }

        /* JADX INFO: Access modifiers changed from: private */
        public void setPopupMenuItems(ArrayList<String> items) {
            if (this.popupMenu == null) {
                View menuButton = this.view.findViewById(R.id.BTMenu);
                this.popupMenu = new PopupMenu(this.view.getContext(), menuButton);
                menuButton.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.winhandler.TaskManagerDialog$Panel$$ExternalSyntheticLambda0
                    @Override // android.view.View.OnClickListener
                    public final void onClick(View view) {
                        this.f$0.lambda$setPopupMenuItems$0(view);
                    }
                });
                menuButton.setVisibility(0);
            }
            Menu menu = this.popupMenu.getMenu();
            menu.clear();
            for (String item : items) {
                menu.add(item);
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda$setPopupMenuItems$0(View v) {
            this.popupMenu.show();
        }
    }

    public TaskManagerDialog(final XServerDisplayActivity activity) {
        super(activity, R.layout.task_manager_dialog);
        this.lock = new Object();
        this.batteryInfo = new BatteryInfo();
        this.activity = activity;
        setCancelable(false);
        setTitle(R.string.task_manager);
        setIcon(R.drawable.icon_task_manager);
        Button cancelButton = (Button) findViewById(R.id.BTCancel);
        cancelButton.setText(R.string.new_task);
        cancelButton.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda1
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                this.f$0.lambda$new$1(activity, view);
            }
        });
        setOnDismissListener(new DialogInterface.OnDismissListener() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda0
            @Override // android.content.DialogInterface.OnDismissListener
            public final void onDismiss(DialogInterface dialogInterface) {
                this.f$0.lambda$new$2(activity, dialogInterface);
            }
        });
        this.inflater = LayoutInflater.from(activity);
        this.batteryReceiver = new BroadcastReceiver() { // from class: com.winlator.winhandler.TaskManagerDialog.1
            @Override // android.content.BroadcastReceiver
            public void onReceive(Context context, Intent intent) {
                String action = intent.getAction();
                if (action != null && action.equals("android.intent.action.BATTERY_CHANGED")) {
                    int voltage = intent.getIntExtra("voltage", 0);
                    int temperature = intent.getIntExtra("temperature", 0);
                    int level = intent.getIntExtra("level", 0);
                    int scale = intent.getIntExtra("scale", 0);
                    TaskManagerDialog.this.batteryInfo.voltage = voltage / 1000.0f;
                    TaskManagerDialog.this.batteryInfo.temperature = (int) (temperature / 10.0f);
                    TaskManagerDialog.this.batteryInfo.level = (int) ((level / scale) * 100.0f);
                }
            }
        };
        IntentFilter filter = new IntentFilter();
        filter.addAction("android.intent.action.BATTERY_CHANGED");
        activity.registerReceiver(this.batteryReceiver, filter);
        Panel panelCreatePanel = createPanel(2);
        this.cpuPanel = panelCreatePanel;
        panelCreatePanel.setIconAt(0, R.drawable.icon_cpu);
        panelCreatePanel.setIconAt(1, R.drawable.icon_temperature);
        Panel panelCreatePanel2 = createPanel(1);
        this.memoryPanel = panelCreatePanel2;
        panelCreatePanel2.setIconAt(0, R.drawable.icon_memory);
        Panel panelCreatePanel3 = createPanel(2);
        this.batteryPanel = panelCreatePanel3;
        panelCreatePanel3.setIconAt(0, R.drawable.icon_power);
        panelCreatePanel3.setIconAt(1, R.drawable.icon_temperature);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$new$1(final XServerDisplayActivity activity, View v) {
        dismiss();
        ContentDialog.prompt(activity, R.string.new_task, "taskmgr.exe", new Callback() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda4
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                TaskManagerDialog.lambda$new$0(activity, (String) obj);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$new$0(XServerDisplayActivity activity, String command) {
        activity.getWinHandler().exec(command);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$new$2(XServerDisplayActivity activity, DialogInterface dialog) {
        BroadcastReceiver broadcastReceiver = this.batteryReceiver;
        if (broadcastReceiver != null) {
            activity.unregisterReceiver(broadcastReceiver);
        }
        Timer timer = this.timer;
        if (timer != null) {
            timer.cancel();
            this.timer = null;
        }
        activity.getWinHandler().setOnGetProcessInfoListener(null);
    }

    private Panel createPanel(int numItems) {
        LinearLayout llPanelList = (LinearLayout) findViewById(R.id.LLPanelList);
        View view = this.inflater.inflate(R.layout.task_manager_panel, (ViewGroup) llPanelList, false);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(-1, -2);
        if (llPanelList.getChildCount() > 0) {
            params.setMargins(0, (int) UnitUtils.dpToPx(6.0f), 0, 0);
        }
        view.setLayoutParams(params);
        llPanelList.addView(view);
        LinearLayout llItemList = (LinearLayout) view.findViewById(R.id.LLItemList);
        Panel panel = new Panel();
        panel.view = view;
        panel.itemViews = new View[numItems];
        for (int i = 0; i < numItems; i++) {
            View itemView = this.inflater.inflate(R.layout.task_manager_panel_item, (ViewGroup) llItemList, false);
            panel.itemViews[i] = itemView;
            llItemList.addView(itemView);
        }
        return panel;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void update() {
        synchronized (this.lock) {
            this.activity.getWinHandler().listProcesses();
            LinearLayout container = (LinearLayout) findViewById(R.id.LLProcessList);
            if (container.getChildCount() == 0) {
                findViewById(R.id.TVEmptyText).setVisibility(0);
            }
        }
        updateCPUPanel();
        updateMemoryPanel();
        updateBatteryPanel();
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX INFO: renamed from: showListItemMenu, reason: merged with bridge method [inline-methods] */
    public void lambda$onGetProcessInfo$6(View anchorView, final ProcessInfo processInfo) {
        PopupMenu listItemMenu = new PopupMenu(this.activity, anchorView);
        if (Build.VERSION.SDK_INT >= 29) {
            listItemMenu.setForceShowIcon(true);
        }
        listItemMenu.inflate(R.menu.process_popup_menu);
        listItemMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda3
            @Override // android.widget.PopupMenu.OnMenuItemClickListener
            public final boolean onMenuItemClick(MenuItem menuItem) {
                return this.f$0.lambda$showListItemMenu$4(processInfo, menuItem);
            }
        });
        listItemMenu.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ boolean lambda$showListItemMenu$4(final ProcessInfo processInfo, MenuItem menuItem) {
        int itemId = menuItem.getItemId();
        final WinHandler winHandler = this.activity.getWinHandler();
        switch (itemId) {
            case R.id.menu_item_bring_to_front /* 2131296725 */:
                winHandler.bringToFront(processInfo.name);
                dismiss();
                break;
            case R.id.menu_item_end_process /* 2131296733 */:
                ContentDialog.confirm(this.activity, R.string.do_you_want_to_end_this_process, new Runnable() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda7
                    @Override // java.lang.Runnable
                    public final void run() {
                        TaskManagerDialog.lambda$showListItemMenu$3(winHandler, processInfo);
                    }
                });
                break;
            case R.id.menu_item_process_affinity /* 2131296748 */:
                showProcessorAffinityDialog(processInfo);
                break;
        }
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$showListItemMenu$3(WinHandler winHandler, ProcessInfo processInfo) {
        winHandler.killProcess(null, processInfo.pid);
    }

    private void showProcessorAffinityDialog(final ProcessInfo processInfo) {
        ContentDialog dialog = new ContentDialog(this.activity, R.layout.cpu_list_dialog);
        dialog.setTitle(processInfo.name);
        dialog.setIcon(R.drawable.icon_cpu);
        final CPUListView cpuListView = (CPUListView) dialog.findViewById(R.id.CPUListView);
        cpuListView.setCheckedCPUList(processInfo.getCPUList());
        dialog.setOnConfirmCallback(new Runnable() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda6
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$showProcessorAffinityDialog$5(processInfo, cpuListView);
            }
        });
        dialog.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$showProcessorAffinityDialog$5(ProcessInfo processInfo, CPUListView cpuListView) {
        WinHandler winHandler = this.activity.getWinHandler();
        winHandler.setProcessAffinity(processInfo.pid, ProcessHelper.getAffinityMask(cpuListView.getCheckedCPUList()));
        update();
    }

    @Override // android.app.Dialog
    public void show() {
        update();
        this.activity.getWinHandler().setOnGetProcessInfoListener(this);
        Timer timer = new Timer();
        this.timer = timer;
        timer.schedule(new AnonymousClass2(), 0L, 1000L);
        super.show();
    }

    /* JADX INFO: renamed from: com.winlator.winhandler.TaskManagerDialog$2, reason: invalid class name */
    class AnonymousClass2 extends TimerTask {
        AnonymousClass2() {
        }

        @Override // java.util.TimerTask, java.lang.Runnable
        public void run() {
            XServerDisplayActivity xServerDisplayActivity = TaskManagerDialog.this.activity;
            final TaskManagerDialog taskManagerDialog = TaskManagerDialog.this;
            xServerDisplayActivity.runOnUiThread(new Runnable() { // from class: com.winlator.winhandler.TaskManagerDialog$2$$ExternalSyntheticLambda0
                @Override // java.lang.Runnable
                public final void run() {
                    TaskManagerDialog.access$1000(taskManagerDialog);
                }
            });
        }
    }

    @Override // com.winlator.winhandler.OnGetProcessInfoListener
    public void onGetProcessInfo(final int index, final int numProcesses, final ProcessInfo processInfo) {
        this.activity.runOnUiThread(new Runnable() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda5
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$onGetProcessInfo$7(numProcesses, index, processInfo);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$onGetProcessInfo$7(int numProcesses, int index, final ProcessInfo processInfo) {
        Bitmap icon;
        synchronized (this.lock) {
            LinearLayout container = (LinearLayout) findViewById(R.id.LLProcessList);
            setBottomBarText(this.activity.getString(R.string.processes) + ": " + numProcesses);
            if (numProcesses == 0) {
                container.removeAllViews();
                findViewById(R.id.TVEmptyText).setVisibility(0);
                return;
            }
            findViewById(R.id.TVEmptyText).setVisibility(8);
            int childCount = container.getChildCount();
            View itemView = index < childCount ? container.getChildAt(index) : this.inflater.inflate(R.layout.process_info_list_item, (ViewGroup) container, false);
            TextView textView = (TextView) itemView.findViewById(R.id.TVName);
            StringBuilder sb = new StringBuilder();
            sb.append(processInfo.name);
            sb.append(processInfo.wow64Process ? " *32" : "");
            textView.setText(sb.toString());
            ((TextView) itemView.findViewById(R.id.TVPID)).setText(String.valueOf(processInfo.pid));
            ((TextView) itemView.findViewById(R.id.TVMemoryUsage)).setText(processInfo.getFormattedMemoryUsage());
            itemView.findViewById(R.id.BTMenu).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.winhandler.TaskManagerDialog$$ExternalSyntheticLambda2
                @Override // android.view.View.OnClickListener
                public final void onClick(View view) {
                    this.f$0.lambda$onGetProcessInfo$6(processInfo, view);
                }
            });
            XServer xServer = this.activity.getXServer();
            XLock xlock = xServer.lock(XServer.Lockable.WINDOW_MANAGER);
            try {
                Window window = xServer.windowManager.findWindowWithProcessId(processInfo.pid);
                if (xlock != null) {
                    xlock.close();
                }
                ImageView ivIcon = (ImageView) itemView.findViewById(R.id.IVIcon);
                ivIcon.setImageResource(R.drawable.taskmgr_process);
                if (window != null && (icon = xServer.pixmapManager.getWindowIcon(window)) != null) {
                    ivIcon.setImageBitmap(icon);
                }
                if (index >= childCount) {
                    container.addView(itemView);
                }
                if (index == numProcesses - 1 && childCount > numProcesses) {
                    for (int i = childCount - 1; i >= numProcesses; i--) {
                        container.removeViewAt(i);
                    }
                }
            } finally {
            }
        }
    }

    private void updateCPUPanel() {
        short[] clockSpeeds = CPUStatus.getCurrentClockSpeeds();
        float totalClockSpeed = 0.0f;
        int maxClockSpeed = 0;
        int selectedClockSpeed = 0;
        ArrayList<String> popupMenuItems = new ArrayList<>();
        for (int i = 0; i < clockSpeeds.length; i++) {
            totalClockSpeed += clockSpeeds[i];
            int currentMaxClockSpeed = CPUStatus.getMaxClockSpeed(i);
            maxClockSpeed = Math.max(maxClockSpeed, currentMaxClockSpeed);
            selectedClockSpeed = Math.max(selectedClockSpeed, (int) clockSpeeds[i]);
            popupMenuItems.add("CPU" + i + ": " + CPUStatus.formatClockSpeed(clockSpeeds[i]) + "/" + CPUStatus.formatClockSpeed(currentMaxClockSpeed));
        }
        int i2 = clockSpeeds.length;
        float avgClockSpeed = totalClockSpeed / i2;
        byte cpuUsagePercent = (byte) ((avgClockSpeed / maxClockSpeed) * 100.0f);
        this.cpuPanel.setTitle("CPU (" + ((int) cpuUsagePercent) + "%)");
        this.cpuPanel.setTextAt(0, CPUStatus.formatClockSpeed(selectedClockSpeed));
        this.cpuPanel.setTextAt(1, CPUStatus.getTemperature() + "ºC");
        this.cpuPanel.setPopupMenuItems(popupMenuItems);
    }

    private void updateMemoryPanel() {
        ActivityManager activityManager = (ActivityManager) this.activity.getSystemService("activity");
        ActivityManager.MemoryInfo memoryInfo = new ActivityManager.MemoryInfo();
        activityManager.getMemoryInfo(memoryInfo);
        long usedMem = memoryInfo.totalMem - memoryInfo.availMem;
        byte memUsagePercent = (byte) ((usedMem / r2) * 100.0d);
        this.memoryPanel.setTitle(this.activity.getString(R.string.memory) + " (" + ((int) memUsagePercent) + "%)");
        this.memoryPanel.setTextAt(0, StringUtils.formatBytes(usedMem, false) + "/" + StringUtils.formatBytes(memoryInfo.totalMem));
    }

    private void updateBatteryPanel() {
        int currentMicroamperes = BatteryUtils.getCurrentMicroamperes(this.activity);
        this.batteryPanel.setTitle(this.activity.getString(R.string.battery) + " (" + this.batteryInfo.level + "%)");
        Panel panel = this.batteryPanel;
        StringBuilder sb = new StringBuilder();
        Locale locale = Locale.ENGLISH;
        sb.append(String.format(locale, "%.2f", Float.valueOf(BatteryUtils.computePower(currentMicroamperes, this.batteryInfo.voltage))));
        sb.append(" W");
        panel.setTextAt(0, sb.toString());
        this.batteryPanel.setTextAt(1, this.batteryInfo.temperature + "ºC");
        ArrayList<String> popupMenuItems = new ArrayList<>();
        popupMenuItems.add(this.activity.getString(R.string.voltage) + ": " + String.format(locale, "%.2f", Float.valueOf(this.batteryInfo.voltage)) + " V");
        popupMenuItems.add(this.activity.getString(R.string.current) + ": " + (currentMicroamperes / 1000) + " mA");
        int capacity = BatteryUtils.getCapacity(this.activity);
        if (capacity > 0) {
            popupMenuItems.add(this.activity.getString(R.string.capacity) + ": " + capacity + " mAh");
        }
        this.batteryPanel.setPopupMenuItems(popupMenuItems);
    }
}
