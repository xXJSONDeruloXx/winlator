package com.winlator.widget;

import android.content.Context;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.LinearLayout;
import android.widget.TextView;
import androidx.appcompat.widget.ListPopupWindow;
import com.winlator.R;

/* JADX INFO: loaded from: classes.dex */
public class TaggedSelectionBox extends LinearLayout {
    private String[] items;
    private OnButtonClickListener onButtonClickListener;
    private OnItemSelectedListener onItemSelectedListener;

    public interface OnButtonClickListener {
        void onClick();
    }

    public interface OnItemSelectedListener {
        void onItemSelected(String str);
    }

    public TaggedSelectionBox(Context context) {
        this(context, null);
    }

    public TaggedSelectionBox(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public TaggedSelectionBox(Context context, AttributeSet attrs, int defStyleAttr) {
        this(context, attrs, defStyleAttr, 0);
    }

    public TaggedSelectionBox(final Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        setOrientation(0);
        setLayoutParams(new LinearLayout.LayoutParams(0, -2, 1.0f));
        LayoutInflater inflater = LayoutInflater.from(context);
        View contentView = inflater.inflate(R.layout.tagged_selection_box, (ViewGroup) this, false);
        LinearLayout llDisplayBox = (LinearLayout) contentView.findViewById(R.id.LLDisplayBox);
        llDisplayBox.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.widget.TaggedSelectionBox$$ExternalSyntheticLambda1
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                this.f$0.lambda$new$1(context, view);
            }
        });
        contentView.findViewById(R.id.BTSettings).setOnClickListener(new View.OnClickListener() { // from class: com.winlator.widget.TaggedSelectionBox$$ExternalSyntheticLambda0
            @Override // android.view.View.OnClickListener
            public final void onClick(View view) {
                this.f$0.lambda$new$2(view);
            }
        });
        addView(contentView);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$new$1(Context context, View v) {
        if (this.items == null) {
            return;
        }
        final ListPopupWindow popupWindow = new ListPopupWindow(context);
        popupWindow.setAdapter(new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, this.items));
        popupWindow.setAnchorView(v);
        popupWindow.setWidth(v.getWidth());
        popupWindow.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.winlator.widget.TaggedSelectionBox$$ExternalSyntheticLambda2
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView adapterView, View view, int i, long j) {
                this.f$0.lambda$new$0(popupWindow, adapterView, view, i, j);
            }
        });
        popupWindow.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$new$0(ListPopupWindow popupWindow, AdapterView parent, View view, int position, long id) {
        ((TextView) findViewById(R.id.TVName)).setText(this.items[position]);
        OnItemSelectedListener onItemSelectedListener = this.onItemSelectedListener;
        if (onItemSelectedListener != null) {
            onItemSelectedListener.onItemSelected(this.items[position]);
        }
        popupWindow.dismiss();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$new$2(View view) {
        OnButtonClickListener onButtonClickListener = this.onButtonClickListener;
        if (onButtonClickListener != null) {
            onButtonClickListener.onClick();
        }
    }

    public String getSelectedItem() {
        return ((TextView) findViewById(R.id.TVName)).getText().toString();
    }

    public void setSelectedItem(String selectedItem) {
        ((TextView) findViewById(R.id.TVName)).setText(selectedItem);
    }

    public void setLabel(String label) {
        ((TextView) findViewById(R.id.TVLabel)).setText(label);
    }

    public String[] getItems() {
        return this.items;
    }

    public void setItems(String... items) {
        this.items = items;
    }

    public OnButtonClickListener getOnButtonClickListener() {
        return this.onButtonClickListener;
    }

    public void setOnButtonClickListener(OnButtonClickListener onButtonClickListener) {
        this.onButtonClickListener = onButtonClickListener;
    }

    public OnItemSelectedListener getOnItemSelectedListener() {
        return this.onItemSelectedListener;
    }

    public void setOnItemSelectedListener(OnItemSelectedListener onItemSelectedListener) {
        this.onItemSelectedListener = onItemSelectedListener;
    }
}
