package com.winlator.contentdialog;

import android.app.Activity;
import android.widget.TextView;
import com.google.android.material.progressindicator.CircularProgressIndicator;
import com.winlator.R;
import com.winlator.container.Container;
import com.winlator.core.Callback;
import com.winlator.core.FileUtils;
import com.winlator.core.StringUtils;
import java.io.File;
import java.util.concurrent.atomic.AtomicLong;

/* JADX INFO: loaded from: classes.dex */
public class StorageInfoDialog extends ContentDialog {
    public StorageInfoDialog(final Activity activity, final Container container) {
        super(activity, R.layout.container_storage_info_dialog);
        setTitle(R.string.storage_info);
        setIcon(R.drawable.icon_info);
        final AtomicLong driveCSize = new AtomicLong();
        driveCSize.set(0L);
        final AtomicLong cacheSize = new AtomicLong();
        cacheSize.set(0L);
        final AtomicLong totalSize = new AtomicLong();
        totalSize.set(0L);
        final TextView tvDriveCSize = (TextView) findViewById(R.id.TVDriveCSize);
        final TextView tvCacheSize = (TextView) findViewById(R.id.TVCacheSize);
        final TextView tvTotalSize = (TextView) findViewById(R.id.TVTotalSize);
        final TextView tvUsedSpace = (TextView) findViewById(R.id.TVUsedSpace);
        final CircularProgressIndicator circularProgressIndicator = (CircularProgressIndicator) findViewById(R.id.CircularProgressIndicator);
        final long internalStorageSize = FileUtils.getInternalStorageSize();
        final Runnable updateUI = new Runnable() { // from class: com.winlator.contentdialog.StorageInfoDialog$$ExternalSyntheticLambda4
            @Override // java.lang.Runnable
            public final void run() {
                StorageInfoDialog.lambda_new_0(tvDriveCSize, driveCSize, tvCacheSize, cacheSize, tvTotalSize, totalSize, internalStorageSize, tvUsedSpace, circularProgressIndicator);
            }
        };
        File rootDir = container.getRootDir();
        File driveCDir = new File(rootDir, ".wine/drive_c");
        final File containerCacheDir = new File(rootDir, ".cache");
        final File globalCacheDir = activity.getCacheDir();
        final AtomicLong lastTime = new AtomicLong(System.currentTimeMillis());
        final Callback<Long> onAddSize = new Callback() { // from class: com.winlator.contentdialog.StorageInfoDialog$$ExternalSyntheticLambda3
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                StorageInfoDialog.lambda_new_1(totalSize, lastTime, activity, updateUI, (Long) obj);
            }
        };
        FileUtils.getSizeAsync(driveCDir, new Callback() { // from class: com.winlator.contentdialog.StorageInfoDialog$$ExternalSyntheticLambda0
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                StorageInfoDialog.lambda_new_2(driveCSize, onAddSize, (Long) obj);
            }
        });
        FileUtils.getSizeAsync(containerCacheDir, new Callback() { // from class: com.winlator.contentdialog.StorageInfoDialog$$ExternalSyntheticLambda1
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                StorageInfoDialog.lambda_new_3(cacheSize, onAddSize, (Long) obj);
            }
        });
        FileUtils.getSizeAsync(globalCacheDir, new Callback() { // from class: com.winlator.contentdialog.StorageInfoDialog$$ExternalSyntheticLambda2
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                StorageInfoDialog.lambda_new_4(cacheSize, onAddSize, (Long) obj);
            }
        });
        ((TextView) findViewById(R.id.BTCancel)).setText(R.string.clear_cache);
        setOnCancelCallback(new Runnable() { // from class: com.winlator.contentdialog.StorageInfoDialog$$ExternalSyntheticLambda5
            @Override // java.lang.Runnable
            public final void run() {
                StorageInfoDialog.lambda_new_5(containerCacheDir, globalCacheDir, container);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_0(TextView tvDriveCSize, AtomicLong driveCSize, TextView tvCacheSize, AtomicLong cacheSize, TextView tvTotalSize, AtomicLong totalSize, long internalStorageSize, TextView tvUsedSpace, CircularProgressIndicator circularProgressIndicator) {
        tvDriveCSize.setText(StringUtils.formatBytes(driveCSize.get()));
        tvCacheSize.setText(StringUtils.formatBytes(cacheSize.get()));
        tvTotalSize.setText(StringUtils.formatBytes(totalSize.get()));
        int progress = (int) ((totalSize.get() / internalStorageSize) * 100.0d);
        tvUsedSpace.setText(progress + "%");
        circularProgressIndicator.setProgress(progress, true);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_1(AtomicLong totalSize, AtomicLong lastTime, Activity activity, Runnable updateUI, Long size) {
        totalSize.addAndGet(size.longValue());
        long currTime = System.currentTimeMillis();
        int elapsedTime = (int) (currTime - lastTime.get());
        if (elapsedTime > 30) {
            activity.runOnUiThread(updateUI);
            lastTime.set(currTime);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_2(AtomicLong driveCSize, Callback onAddSize, Long size) {
        driveCSize.addAndGet(size.longValue());
        onAddSize.call(size);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_3(AtomicLong cacheSize, Callback onAddSize, Long size) {
        cacheSize.addAndGet(size.longValue());
        onAddSize.call(size);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_4(AtomicLong cacheSize, Callback onAddSize, Long size) {
        cacheSize.addAndGet(size.longValue());
        onAddSize.call(size);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_5(File containerCacheDir, File globalCacheDir, Container container) {
        FileUtils.clear(containerCacheDir);
        FileUtils.clear(globalCacheDir);
        container.putExtra("desktopTheme", null);
        container.saveData();
    }
}
