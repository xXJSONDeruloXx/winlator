package com.winlator.contentdialog;

import android.content.Context;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.winlator.R;
import com.winlator.container.Container;
import com.winlator.container.FileInfo;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import com.winlator.core.FileUtils;
import com.winlator.core.StringUtils;
import com.winlator.core.UnitUtils;
import com.winlator.core.WineUtils;
import java.text.DateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.concurrent.atomic.AtomicLong;

/* JADX INFO: loaded from: classes.dex */
public class FileInfoDialog extends ContentDialog {
    /* JADX WARN: Illegal instructions before constructor call */
    public FileInfoDialog(Context context, FileInfo file, Container container) {
        super(context, R.layout.file_info_dialog);
        String formattedType;
        ArrayList<String[]> lines;
        Context context2 = context;
        findViewById(R.id.BTCancel).setVisibility(8);
        setTitle(R.string.information);
        setIcon(R.drawable.icon_info);
        String formattedType2 = "";
        switch (AnonymousClass1.$SwitchMap$com$winlator$container$FileInfo$Type[file.type.ordinal()]) {
            case 1:
                formattedType2 = context2.getString(R.string.file);
                break;
            case 2:
                formattedType2 = context2.getString(R.string.drive);
                break;
            case 3:
                formattedType2 = context2.getString(R.string.folder);
                break;
        }
        ArrayList<String[]> lines2 = new ArrayList<>();
        int i = 0;
        lines2.add(new String[]{context2.getString(R.string.type), formattedType2});
        if (file.type == FileInfo.Type.DIRECTORY) {
            lines2.add(new String[]{context2.getString(R.string.contains), file.getItemCount() + " " + context2.getString(R.string.items)});
        }
        if (file.type == FileInfo.Type.FILE) {
            lines2.add(new String[]{context2.getString(R.string.size), StringUtils.formatBytes(file.getSize())});
        } else {
            lines2.add(new String[]{context2.getString(R.string.size), "?"});
        }
        if (file.type != FileInfo.Type.DRIVE) {
            lines2.add(new String[]{context2.getString(R.string.location), WineUtils.unixToDOSPath(FileUtils.getDirname(file.path), container)});
        }
        Date date = new Date(file.toFile().lastModified());
        String modified = DateFormat.getDateTimeInstance(3, 3).format(date);
        lines2.add(new String[]{context2.getString(R.string.modified), modified});
        LinearLayout linearLayout = (LinearLayout) findViewById(R.id.LLContent);
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(-2, -2);
        params.width = AppUtils.getPreferredDialogWidth(context);
        linearLayout.setLayoutParams(params);
        ViewGroup.LayoutParams params2 = new LinearLayout.LayoutParams(-2, -2);
        int paddingRight = (int) UnitUtils.dpToPx(8.0f);
        for (String[] columns : lines2) {
            LinearLayout row = new LinearLayout(context2);
            row.setLayoutParams(params2);
            row.setOrientation(i);
            TextView tvLabel = new TextView(context2);
            tvLabel.setLayoutParams(params2);
            tvLabel.setPadding(0, 0, paddingRight, 0);
            tvLabel.setTextSize(1, 16.0f);
            tvLabel.setText(columns[0] + ":");
            tvLabel.setTypeface(tvLabel.getTypeface(), 1);
            row.addView(tvLabel);
            final TextView tvValue = new TextView(context2);
            tvValue.setLayoutParams(params2);
            tvValue.setTextSize(1, 16.0f);
            tvValue.setMaxLines(1);
            tvValue.setText(columns[1]);
            if (!columns[1].equals("?")) {
                formattedType = formattedType2;
                lines = lines2;
            } else {
                final AtomicLong lastTime = new AtomicLong();
                final AtomicLong totalSize = new AtomicLong();
                formattedType = formattedType2;
                lines = lines2;
                FileUtils.getSizeAsync(file.toFile(), new Callback() { // from class: com.winlator.contentdialog.FileInfoDialog$$ExternalSyntheticLambda0
                    @Override // com.winlator.core.Callback
                    public final void call(Object obj) {
                        FileInfoDialog.lambda_new_1(totalSize, lastTime, tvValue, (Long) obj);
                    }
                });
            }
            row.addView(tvValue);
            linearLayout.addView(row);
            context2 = context;
            i = 0;
            formattedType2 = formattedType;
            lines2 = lines;
        }
    }

    /* JADX INFO: renamed from: com.winlator.contentdialog.FileInfoDialog$1, reason: invalid class name */
    static /* synthetic */ class AnonymousClass1 {
        static final /* synthetic */ int[] $SwitchMap$com$winlator$container$FileInfo$Type;

        static {
            int[] iArr = new int[FileInfo.Type.values().length];
            $SwitchMap$com$winlator$container$FileInfo$Type = iArr;
            try {
                iArr[FileInfo.Type.FILE.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                $SwitchMap$com$winlator$container$FileInfo$Type[FileInfo.Type.DRIVE.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            try {
                $SwitchMap$com$winlator$container$FileInfo$Type[FileInfo.Type.DIRECTORY.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_1(final AtomicLong totalSize, AtomicLong lastTime, final TextView tvValue, Long size) {
        totalSize.addAndGet(size.longValue());
        long currTime = System.currentTimeMillis();
        int elapsedTime = (int) (currTime - lastTime.get());
        if (lastTime.get() == 0 || elapsedTime > 30) {
            tvValue.post(new Runnable() { // from class: com.winlator.contentdialog.FileInfoDialog$$ExternalSyntheticLambda1
                @Override // java.lang.Runnable
                public final void run() {
                    FileInfoDialog.lambda_new_0(tvValue, totalSize);
                }
            });
            lastTime.set(currTime);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_new_0(TextView tvValue, AtomicLong totalSize) {
        tvValue.setText(StringUtils.formatBytes(totalSize.get()));
    }
}
