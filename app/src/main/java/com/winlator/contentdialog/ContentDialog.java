package com.winlator.contentdialog;

import android.app.Dialog;
import android.content.Context;
import android.util.SparseBooleanArray;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class ContentDialog extends Dialog {
    private final View contentView;
    private Runnable onCancelCallback;
    private Runnable onConfirmCallback;

    public ContentDialog(Context context) {
        this(context, 0);
    }

    public ContentDialog(Context context, int layoutResId) {
        super(context, R.style.ContentDialog);
        View viewInflate = LayoutInflater.from(context).inflate(R.layout.content_dialog, (ViewGroup) null);
        this.contentView = viewInflate;
        if (layoutResId > 0) {
            FrameLayout frameLayout = (FrameLayout) viewInflate.findViewById(R.id.FrameLayout);
            frameLayout.setVisibility(0);
            View view = LayoutInflater.from(context).inflate(layoutResId, (ViewGroup) frameLayout, false);
            frameLayout.addView(view);
        }
        View confirmButton = viewInflate.findViewById(R.id.BTConfirm);
        confirmButton.setOnClickListener(view2 -> lambda_new_0(view2));
        View cancelButton = viewInflate.findViewById(R.id.BTCancel);
        cancelButton.setOnClickListener(view2 -> lambda_new_1(view2));
        setContentView(viewInflate);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_0(View v) {
        Runnable runnable = this.onConfirmCallback;
        if (runnable != null) {
            runnable.run();
        }
        dismiss();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_1(View v) {
        Runnable runnable = this.onCancelCallback;
        if (runnable != null) {
            runnable.run();
        }
        dismiss();
    }

    public View getContentView() {
        return this.contentView;
    }

    public void setOnConfirmCallback(Runnable onConfirmCallback) {
        this.onConfirmCallback = onConfirmCallback;
    }

    public void setOnCancelCallback(Runnable onCancelCallback) {
        this.onCancelCallback = onCancelCallback;
    }

    @Override // android.app.Dialog
    public void setTitle(int titleResId) {
        setTitle(getContext().getString(titleResId));
    }

    public void setIcon(int iconResId) {
        ImageView imageView = (ImageView) findViewById(R.id.IVIcon);
        imageView.setImageResource(iconResId);
        imageView.setVisibility(0);
    }

    public void setTitle(String title) {
        LinearLayout titleBar = (LinearLayout) findViewById(R.id.LLTitleBar);
        TextView tvTitle = (TextView) findViewById(R.id.TVTitle);
        if (title != null && !title.isEmpty()) {
            tvTitle.setText(title);
            titleBar.setVisibility(0);
        } else {
            tvTitle.setText("");
            titleBar.setVisibility(8);
        }
    }

    public void setBottomBarText(String bottomBarText) {
        TextView tvBottomBarText = (TextView) findViewById(R.id.TVBottomBarText);
        if (bottomBarText != null && !bottomBarText.isEmpty()) {
            tvBottomBarText.setText(bottomBarText);
            tvBottomBarText.setVisibility(0);
        } else {
            tvBottomBarText.setText("");
            tvBottomBarText.setVisibility(8);
        }
    }

    public void setMessage(int msgResId, int iconResId) {
        setMessage(getContext().getString(msgResId), iconResId);
    }

    public void setMessage(String message, int iconResId) {
        TextView tvMessage = (TextView) findViewById(R.id.TVMessage);
        ImageView imageView = (ImageView) findViewById(R.id.IVMessageIcon);
        imageView.setVisibility(8);
        if (message != null && !message.isEmpty()) {
            tvMessage.setText(message);
            tvMessage.setVisibility(0);
            if (iconResId > 0) {
                imageView.setImageResource(iconResId);
                imageView.setVisibility(0);
                return;
            }
            return;
        }
        tvMessage.setText("");
        tvMessage.setVisibility(8);
    }

    public static void confirm(Context context, int msgResId, Runnable callback) {
        ContentDialog dialog = new ContentDialog(context);
        dialog.setCancelable(false);
        dialog.setMessage(msgResId, R.drawable.content_dialog_type_confirm);
        dialog.setOnConfirmCallback(callback);
        dialog.show();
    }

    public static void prompt(Context context, int titleResId, String defaultText, final Callback<String> callback) {
        ContentDialog dialog = new ContentDialog(context);
        final EditText editText = (EditText) dialog.findViewById(R.id.EditText);
        editText.setHint(R.string.untitled);
        if (defaultText != null) {
            editText.setText(defaultText);
        }
        editText.setVisibility(0);
        dialog.setTitle(titleResId);
        dialog.setOnConfirmCallback(new Runnable() { // from class: com.winlator.contentdialog.ContentDialog$$ExternalSyntheticLambda2
            @Override // java.lang.Runnable
            public final void run() {
                ContentDialog.lambda_prompt_2(editText, callback);
            }
        });
        dialog.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_prompt_2(EditText editText, Callback callback) {
        String text = editText.getText().toString().trim();
        if (!text.isEmpty()) {
            callback.call(text);
        }
    }

    public static void showSelectionList(Context context, int titleResId, String[] items, boolean multiSelection, Callback<ArrayList<Integer>> callback) {
        showSelectionList(context, context.getString(titleResId), items, multiSelection, callback);
    }

    public static void showSelectionList(Context context, String title, String[] items, boolean multiSelection, final Callback<ArrayList<Integer>> callback) {
        ContentDialog dialog = new ContentDialog(context);
        final ListView listView = (ListView) dialog.findViewById(R.id.ListView);
        listView.getLayoutParams().width = AppUtils.getPreferredDialogWidth(context);
        listView.setChoiceMode(multiSelection ? 2 : 1);
        int layoutResId = multiSelection ? android.R.layout.simple_list_item_multiple_choice : android.R.layout.simple_list_item_single_choice;
        listView.setAdapter((ListAdapter) new ArrayAdapter(context, layoutResId, items));
        listView.setVisibility(0);
        dialog.setTitle(title);
        dialog.setOnConfirmCallback(new Runnable() { // from class: com.winlator.contentdialog.ContentDialog$$ExternalSyntheticLambda3
            @Override // java.lang.Runnable
            public final void run() {
                ContentDialog.lambda_showSelectionList_3(listView, callback);
            }
        });
        dialog.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_showSelectionList_3(ListView listView, Callback callback) {
        ArrayList<Integer> result = new ArrayList<>();
        SparseBooleanArray checkedItemPositions = listView.getCheckedItemPositions();
        for (int i = 0; i < checkedItemPositions.size(); i++) {
            if (checkedItemPositions.valueAt(i)) {
                result.add(Integer.valueOf(checkedItemPositions.keyAt(i)));
            }
        }
        callback.call(result);
    }
}
