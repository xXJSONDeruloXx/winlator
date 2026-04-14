package com.winlator.widget;

import android.content.Context;
import android.util.ArraySet;
import android.util.AttributeSet;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.CheckedTextView;
import androidx.appcompat.widget.AppCompatTextView;
import androidx.appcompat.widget.ListPopupWindow;
import com.winlator.R;
import com.winlator.core.UnitUtils;
import java.util.ArrayList;
import java.util.Collections;

/* JADX INFO: loaded from: classes.dex */
public class MultiSelectionComboBox extends AppCompatTextView {
    private String displayText;
    private String[] items;
    private int popupWindowWidth;
    private final ArraySet<String> selectedItemSet;

    public MultiSelectionComboBox(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public MultiSelectionComboBox(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        this.selectedItemSet = new ArraySet<>();
        this.popupWindowWidth = 260;
    }

    public String getDisplayText() {
        return this.displayText;
    }

    public void setDisplayText(String displayText) {
        this.displayText = displayText;
    }

    public int getPopupWindowWidth() {
        return this.popupWindowWidth;
    }

    public void setPopupWindowWidth(int popupWindowWidth) {
        this.popupWindowWidth = popupWindowWidth;
    }

    public String[] getItems() {
        return this.items;
    }

    public void setItems(String[] items) {
        this.items = items;
        updateDisplayText();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void updateDisplayText() {
        String str = this.displayText;
        if (str != null && !str.isEmpty()) {
            String itemCount = String.valueOf(this.items.length);
            String selectedItemCount = String.valueOf(this.selectedItemSet.size());
            setText(this.displayText.replaceFirst("%d", selectedItemCount).replaceFirst("%d", itemCount));
            return;
        }
        setText(getSelectedItemsAsString());
    }

    public void setSelectedItems(String[] selectedItems) {
        Collections.addAll(this.selectedItemSet, selectedItems);
        updateDisplayText();
    }

    public String[] getSelectedItems() {
        ArrayList<String> selectedItems = new ArrayList<>();
        for (String item : this.items) {
            if (this.selectedItemSet.contains(item)) {
                selectedItems.add(item);
            }
        }
        return (String[]) selectedItems.toArray(new String[0]);
    }

    public String getSelectedItemsAsString() {
        String result = "";
        for (String item : this.items) {
            if (this.selectedItemSet.contains(item)) {
                StringBuilder sb = new StringBuilder();
                sb.append(result);
                sb.append(!result.isEmpty() ? "," : "");
                sb.append(item);
                result = sb.toString();
            }
        }
        return result;
    }

    @Override // android.view.View
    public boolean performClick() {
        String[] strArr = this.items;
        if (strArr == null || strArr.length == 0) {
            return true;
        }
        final ArrayAdapter<String> adapter = new ArrayAdapter<String>(getContext(), R.layout.simple_list_item_multiple_choice, this.items) { // from class: com.winlator.widget.MultiSelectionComboBox.1
            @Override // android.widget.ArrayAdapter, android.widget.Adapter
            public View getView(int position, View convertView, ViewGroup parent) {
                CheckedTextView checkedTextView = (CheckedTextView) super.getView(position, convertView, parent);
                checkedTextView.setChecked(MultiSelectionComboBox.this.selectedItemSet.contains(MultiSelectionComboBox.this.items[position]));
                MultiSelectionComboBox.this.updateDisplayText();
                return checkedTextView;
            }
        };
        ListPopupWindow popupWindow = new ListPopupWindow(getContext());
        popupWindow.setAdapter(adapter);
        popupWindow.setAnchorView(this);
        popupWindow.setWidth((int) UnitUtils.dpToPx(this.popupWindowWidth));
        popupWindow.setOnItemClickListener(new AdapterView.OnItemClickListener() { // from class: com.winlator.widget.MultiSelectionComboBox$$ExternalSyntheticLambda0
            @Override // android.widget.AdapterView.OnItemClickListener
            public final void onItemClick(AdapterView adapterView, View view, int i, long j) {
                this.f$0.lambda$performClick$0(adapter, adapterView, view, i, j);
            }
        });
        popupWindow.show();
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$performClick$0(ArrayAdapter adapter, AdapterView parent, View view, int position, long id) {
        String item = this.items[position];
        if (this.selectedItemSet.contains(item)) {
            this.selectedItemSet.remove(item);
        } else {
            this.selectedItemSet.add(item);
        }
        adapter.notifyDataSetChanged();
    }
}
