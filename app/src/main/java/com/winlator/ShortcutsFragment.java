package com.winlator;

import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.TextView;
import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;
import com.winlator.BaseFileManagerFragment;
import com.winlator.container.Container;
import com.winlator.container.Shortcut;
import com.winlator.contentdialog.ContentDialog;
import com.winlator.contentdialog.CreateFolderDialog;
import com.winlator.contentdialog.ShortcutSettingsDialog;
import com.winlator.core.AppUtils;
import com.winlator.core.ArrayUtils;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ShortcutsFragment extends BaseFileManagerFragment<Shortcut> {
    @Override // com.winlator.BaseFileManagerFragment, androidx.fragment.app.Fragment
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.viewStyle = BaseFileManagerFragment.ViewStyle.valueOf(this.preferences.getString("shortcuts_view_style", "GRID"));
    }

    @Override // com.winlator.BaseFileManagerFragment
    public void refreshContent() {
        super.refreshContent();
        Shortcut selectedFolder = !this.folderStack.isEmpty() ? (Shortcut) this.folderStack.peek() : null;
        ArrayList<Shortcut> shortcuts = this.manager.loadShortcuts(selectedFolder);
        this.recyclerView.setAdapter(new ShortcutsAdapter(shortcuts));
        this.emptyTextView.setVisibility(shortcuts.isEmpty() ? 0 : 8);
    }

    @Override // androidx.fragment.app.Fragment
    public void onCreateOptionsMenu(Menu menu, MenuInflater menuInflater) {
        menuInflater.inflate(R.menu.shortcuts_menu, menu);
        refreshViewStyleMenuItem(menu.findItem(R.id.menu_item_view_style));
    }

    private void createFolder() {
        clearClipboard();
        if (this.manager.getContainers().isEmpty()) {
            return;
        }
        CreateFolderDialog createFolderDialog = new CreateFolderDialog(this.manager);
        createFolderDialog.setOnCreateFolderListener((container, str) -> lambda_createFolder_0(container, str));
        createFolderDialog.show();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_createFolder_0(Container container, String name) {
        File desktopDir = new File(container.getUserDir(), "Desktop");
        File parent = !this.folderStack.isEmpty() ? ((Shortcut) this.folderStack.peek()).file : desktopDir;
        File file = new File(parent, name);
        if (file.isDirectory()) {
            AppUtils.showToast(getContext(), R.string.there_already_file_with_that_name);
        } else {
            file.mkdir();
            refreshContent();
        }
    }

    @Override // com.winlator.BaseFileManagerFragment
    protected void pasteFiles() {
        if (this.folderStack.isEmpty()) {
            clearClipboard();
            AppUtils.showToast(getContext(), R.string.you_cannot_paste_files_here);
        } else {
            this.clipboard.targetDir = ((Shortcut) this.folderStack.peek()).file;
            super.pasteFiles();
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void instantiateClipboard(Shortcut shortcut, boolean cutMode) {
        clearClipboard();
        File linkFile = shortcut.getLinkFile();
        File[] files = {new File(shortcut.file.getParentFile(), shortcut.file.getName())};
        if (shortcut.file.isFile()) {
            files = (File[]) ArrayUtils.concat(files, new File[]{new File(linkFile.getParentFile(), linkFile.getName())});
        }
        this.clipboard = new BaseFileManagerFragment.Clipboard(files, cutMode);
        this.pasteButton.setVisibility(0);
    }

    @Override // androidx.fragment.app.Fragment
    public boolean onOptionsItemSelected(MenuItem menuItem) {
        int itemId = menuItem.getItemId();
        if (itemId == R.id.menu_item_view_style) {
            BaseFileManagerFragment.ViewStyle viewStyle = this.viewStyle;
            BaseFileManagerFragment.ViewStyle viewStyle2 = BaseFileManagerFragment.ViewStyle.GRID;
            if (viewStyle == viewStyle2) {
                viewStyle2 = BaseFileManagerFragment.ViewStyle.LIST;
            }
            setViewStyle(viewStyle2);
            this.preferences.edit().putString("shortcuts_view_style", this.viewStyle.name()).apply();
            refreshViewStyleMenuItem(menuItem);
            return true;
        }
        if (itemId == R.id.menu_item_new_folder) {
            createFolder();
            return true;
        }
        return super.onOptionsItemSelected(menuItem);
    }

    @Override // com.winlator.BaseFileManagerFragment
    protected String getHomeTitle() {
        return getString(R.string.shortcuts);
    }

    /* JADX INFO: Access modifiers changed from: private */
    class ShortcutsAdapter extends RecyclerView.Adapter<ShortcutsAdapter.ViewHolder> {
        private final List<Shortcut> data;

        private class ViewHolder extends RecyclerView.ViewHolder {
            private final ImageView imageView;
            private final ImageView menuButton;
            private final ImageView runButton;
            private final TextView subtitle;
            private final TextView title;

            private ViewHolder(View view) {
                super(view);
                this.imageView = (ImageView) view.findViewById(R.id.ImageView);
                this.title = (TextView) view.findViewById(R.id.TVTitle);
                this.subtitle = (TextView) view.findViewById(R.id.TVSubtitle);
                this.runButton = (ImageView) view.findViewById(R.id.BTRun);
                this.menuButton = (ImageView) view.findViewById(R.id.BTMenu);
            }
        }

        public ShortcutsAdapter(List<Shortcut> data) {
            this.data = data;
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            int resource = ShortcutsFragment.this.viewStyle == BaseFileManagerFragment.ViewStyle.LIST ? R.layout.file_list_item : R.layout.file_grid_item;
            return new ViewHolder(LayoutInflater.from(parent.getContext()).inflate(resource, parent, false));
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public void onBindViewHolder(ViewHolder holder, int position) {
            final Shortcut item = this.data.get(position);
            if (item.icon != null) {
                holder.imageView.setImageBitmap(item.icon);
            } else {
                int iconResId = item.file.isDirectory() ? R.drawable.container_folder : R.drawable.container_file_link;
                holder.imageView.setImageResource(iconResId);
            }
            holder.title.setText(item.name);
            holder.subtitle.setText(item.container.getName());
            if (item.file.isDirectory()) {
                holder.runButton.setImageResource(R.drawable.icon_open);
            } else {
                holder.runButton.setImageResource(R.drawable.icon_run);
            }
            holder.imageView.setOnClickListener(view -> lambda_onBindViewHolder_0(item, view));
            holder.runButton.setOnClickListener(view -> lambda_onBindViewHolder_1(item, view));
            holder.menuButton.setOnClickListener(view -> lambda_onBindViewHolder_2(view, item));
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_onBindViewHolder_0(Shortcut item, View v) {
            runFromShortcut(item);
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_onBindViewHolder_1(Shortcut item, View v) {
            runFromShortcut(item);
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public final int getItemCount() {
            return this.data.size();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: showListItemMenu, reason: merged with bridge method [inline-methods] */
        public void lambda_onBindViewHolder_2(View anchorView, final Shortcut shortcut) {
            final Context context = ShortcutsFragment.this.getContext();
            PopupMenu listItemMenu = new PopupMenu(context, anchorView);
            if (Build.VERSION.SDK_INT >= 29) {
                listItemMenu.setForceShowIcon(true);
            }
            listItemMenu.inflate(R.menu.file_manager_popup_menu);
            Menu menu = listItemMenu.getMenu();
            menu.findItem(R.id.menu_item_rename).setVisible(false);
            menu.findItem(R.id.menu_item_add_favorite).setVisible(false);
            menu.findItem(R.id.menu_item_info).setVisible(false);
            listItemMenu.setOnMenuItemClickListener(menuItem -> lambda_showListItemMenu_4(shortcut, context, menuItem));
            listItemMenu.show();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
        public /* synthetic */ boolean lambda_showListItemMenu_4(final Shortcut shortcut, Context context, MenuItem menuItem) {
            int itemId = menuItem.getItemId();
            if (itemId == R.id.menu_item_copy || itemId == R.id.menu_item_cut) {
                    ShortcutsFragment.this.instantiateClipboard(shortcut, itemId == R.id.menu_item_cut);
                    return true;
            } else if (itemId == R.id.menu_item_remove) {
                    ShortcutsFragment.this.clearClipboard();
                    ContentDialog.confirm(context, R.string.do_you_want_to_remove_this_file, () -> lambda_showListItemMenu_3(shortcut));
                    return true;
            } else if (itemId == R.id.menu_item_settings) {
                    ShortcutsFragment.this.clearClipboard();
                    new ShortcutSettingsDialog(ShortcutsFragment.this, shortcut).show();
                    return true;
            } else {
                    return true;
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_showListItemMenu_3(Shortcut shortcut) {
            shortcut.remove();
            ShortcutsFragment.this.refreshContent();
        }

        /* JADX WARN: Type inference incomplete: some casts might be missing */
        private void runFromShortcut(Shortcut shortcut) {
            AppCompatActivity appCompatActivity = (AppCompatActivity) ShortcutsFragment.this.getActivity();
            if (shortcut.file.isDirectory()) {
                ShortcutsFragment.this.folderStack.push(shortcut);
                ShortcutsFragment.this.refreshContent();
                ActionBar supportActionBar = appCompatActivity.getSupportActionBar();
                supportActionBar.setHomeAsUpIndicator(R.drawable.icon_action_bar_back);
                supportActionBar.setTitle(shortcut.name);
                return;
            }
            Intent intent = new Intent(appCompatActivity, (Class<?>) XServerDisplayActivity.class);
            intent.putExtra("container_id", shortcut.container.id);
            intent.putExtra("shortcut_path", shortcut.file.getPath());
            appCompatActivity.startActivity(intent);
        }
    }
}
