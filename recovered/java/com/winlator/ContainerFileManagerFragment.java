package com.winlator;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
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
import androidx.fragment.app.FragmentActivity;
import androidx.recyclerview.widget.RecyclerView;
import com.winlator.BaseFileManagerFragment;
import com.winlator.container.Container;
import com.winlator.container.FileInfo;
import com.winlator.contentdialog.ContentDialog;
import com.winlator.contentdialog.FileInfoDialog;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import com.winlator.core.FileUtils;
import com.winlator.core.StringUtils;
import com.winlator.core.WineUtils;
import com.winlator.win32.MSIcon;
import com.winlator.win32.MSLink;
import com.winlator.win32.PEParser;
import java.io.File;
import java.lang.ref.WeakReference;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Executor;
import java.util.concurrent.Executors;

/* JADX INFO: loaded from: classes.dex */
public class ContainerFileManagerFragment extends BaseFileManagerFragment<FileInfo> {
    private Container container;
    private final int containerId;
    private String startPath;

    public ContainerFileManagerFragment(int containerId) {
        this(containerId, null);
    }

    public ContainerFileManagerFragment(int containerId, String startPath) {
        this.containerId = containerId;
        this.startPath = startPath;
    }

    @Override // com.winlator.BaseFileManagerFragment, androidx.fragment.app.Fragment
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        this.container = this.manager.getContainerById(this.containerId);
        this.viewStyle = BaseFileManagerFragment.ViewStyle.valueOf(this.preferences.getString("container_file_manager_view_style", "GRID"));
        String str = this.startPath;
        if (str != null) {
            setCurrentWorkingPath(WineUtils.unixToDOSPath(str, this.container));
            this.startPath = null;
        }
    }

    @Override // com.winlator.BaseFileManagerFragment
    public void refreshContent() {
        super.refreshContent();
        FileInfo parent = !this.folderStack.isEmpty() ? (FileInfo) this.folderStack.peek() : null;
        ArrayList<FileInfo> files = this.manager.loadFiles(this.container, parent);
        this.recyclerView.setAdapter(new FileInfoAdapter(files));
        this.emptyTextView.setVisibility(files.isEmpty() ? 0 : 8);
        updateActionBarTitle();
    }

    @Override // androidx.fragment.app.Fragment
    public void onCreateOptionsMenu(Menu menu, MenuInflater menuInflater) {
        menuInflater.inflate(R.menu.container_file_manager_menu, menu);
        refreshViewStyleMenuItem(menu.findItem(R.id.menu_item_view_style));
    }

    private void createFolder() {
        clearClipboard();
        if (this.folderStack.isEmpty()) {
            return;
        }
        ContentDialog.prompt(getContext(), R.string.new_folder, null, new Callback() { // from class: com.winlator.ContainerFileManagerFragment$$ExternalSyntheticLambda0
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                this.f$0.lambda$createFolder$0((String) obj);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$createFolder$0(String name) {
        File file = new File(((FileInfo) this.folderStack.peek()).toFile(), name);
        if (file.isDirectory()) {
            AppUtils.showToast(getContext(), R.string.there_already_file_with_that_name);
        } else {
            file.mkdir();
            refreshContent();
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void instantiateClipboard(FileInfo file, boolean cutMode) {
        clearClipboard();
        this.clipboard = new BaseFileManagerFragment.Clipboard(new File[]{new File(file.path)}, cutMode);
        this.pasteButton.setVisibility(0);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void addFavorite(FileInfo file) throws Throwable {
        Context context = getContext();
        File favoritesDir = new File(this.container.getUserDir(), context.getString(R.string.favorites));
        File targetFile = new File(favoritesDir, FileUtils.getBasename(file.name) + ".lnk");
        if (!targetFile.exists()) {
            MSLink.LinkInfo linkInfo = new MSLink.LinkInfo();
            linkInfo.targetPath = WineUtils.unixToDOSPath(file.path, this.container);
            linkInfo.isDirectory = file.type == FileInfo.Type.DIRECTORY;
            boolean success = MSLink.createFile(linkInfo, targetFile);
            if (success) {
                AppUtils.showToast(context, R.string.file_added_to_favorites);
            }
        }
    }

    @Override // com.winlator.BaseFileManagerFragment
    protected void pasteFiles() {
        if (this.folderStack.isEmpty()) {
            clearClipboard();
            AppUtils.showToast(getContext(), R.string.you_cannot_paste_files_here);
        } else {
            this.clipboard.targetDir = ((FileInfo) this.folderStack.peek()).toFile();
            super.pasteFiles();
        }
    }

    @Override // androidx.fragment.app.Fragment
    public boolean onOptionsItemSelected(MenuItem menuItem) {
        int itemId = menuItem.getItemId();
        switch (itemId) {
            case R.id.menu_item_home /* 2131296736 */:
                this.folderStack.clear();
                refreshContent();
                return true;
            case R.id.menu_item_new_folder /* 2131296744 */:
                createFolder();
                return true;
            case R.id.menu_item_view_style /* 2131296757 */:
                BaseFileManagerFragment.ViewStyle viewStyle = this.viewStyle;
                BaseFileManagerFragment.ViewStyle viewStyle2 = BaseFileManagerFragment.ViewStyle.GRID;
                if (viewStyle == viewStyle2) {
                    viewStyle2 = BaseFileManagerFragment.ViewStyle.LIST;
                }
                setViewStyle(viewStyle2);
                this.preferences.edit().putString("container_file_manager_view_style", this.viewStyle.name()).apply();
                refreshViewStyleMenuItem(menuItem);
                return true;
            default:
                return super.onOptionsItemSelected(menuItem);
        }
    }

    /* JADX WARN: Type inference incomplete: some casts might be missing */
    private void setCurrentWorkingPath(String str) {
        String[] strArrSplit = StringUtils.removeEndSlash(str).split("\\\\");
        String str2 = "";
        this.folderStack.clear();
        for (String str3 : strArrSplit) {
            if (!str3.isEmpty()) {
                String strDosToUnixPath = WineUtils.dosToUnixPath(str2 + str3, this.container);
                if (str2.isEmpty() && str3.matches("[A-Za-z]:")) {
                    this.folderStack.push((T) new FileInfo(this.container, str3, strDosToUnixPath, FileInfo.Type.DRIVE));
                } else {
                    this.folderStack.push((T) new FileInfo(this.container, strDosToUnixPath, FileInfo.Type.DIRECTORY));
                }
                str2 = str2 + str3 + "\\";
            }
        }
        updateActionBarTitle();
    }

    private String getCurrentWorkingPath() {
        if (!this.folderStack.isEmpty()) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < this.folderStack.size(); i++) {
                if (i > 0) {
                    sb.append("\\");
                }
                sb.append(((FileInfo) this.folderStack.elementAt(i)).getDisplayName());
            }
            if (this.folderStack.size() == 1) {
                sb.append("\\");
            }
            return sb.toString();
        }
        return "";
    }

    private void updateActionBarTitle() {
        AppCompatActivity activity = (AppCompatActivity) getActivity();
        ActionBar actionBar = activity.getSupportActionBar();
        if (!this.folderStack.isEmpty()) {
            actionBar.setHomeAsUpIndicator(R.drawable.icon_action_bar_back);
            actionBar.setTitle(getCurrentWorkingPath());
        } else {
            actionBar.setHomeAsUpIndicator(R.drawable.icon_action_bar_menu);
            actionBar.setTitle(getHomeTitle());
        }
    }

    @Override // com.winlator.BaseFileManagerFragment
    protected String getHomeTitle() {
        return this.container.getName();
    }

    /* JADX INFO: Access modifiers changed from: private */
    static class LoadIconTask {
        private boolean canceled;
        private final Executor executor;
        private final ContainerFileManagerFragment fragment;
        private final WeakReference<ImageView> imageViewWeakRef;

        private LoadIconTask(ContainerFileManagerFragment fragment, ImageView imageView) {
            this.executor = Executors.newSingleThreadExecutor();
            this.canceled = false;
            this.fragment = fragment;
            this.imageViewWeakRef = new WeakReference<>(imageView);
        }

        public void loadAsync(final FileInfo file) {
            this.executor.execute(new Runnable() { // from class: com.winlator.ContainerFileManagerFragment$LoadIconTask$$ExternalSyntheticLambda0
                @Override // java.lang.Runnable
                public final void run() {
                    this.f$0.lambda$loadAsync$1(file);
                }
            });
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda$loadAsync$1(FileInfo file) {
            final Object icon = this.fragment.getIconForFile(file);
            final ImageView imageView = this.imageViewWeakRef.get();
            if (imageView != null && !this.canceled) {
                imageView.post(new Runnable() { // from class: com.winlator.ContainerFileManagerFragment$LoadIconTask$$ExternalSyntheticLambda1
                    @Override // java.lang.Runnable
                    public final void run() {
                        this.f$0.lambda$loadAsync$0(icon, imageView);
                    }
                });
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda$loadAsync$0(Object icon, ImageView imageView) {
            if (this.canceled) {
                return;
            }
            if (icon instanceof Bitmap) {
                imageView.setImageBitmap((Bitmap) icon);
            } else {
                imageView.setImageResource(((Integer) icon).intValue());
            }
        }

        public void cancel() {
            this.canceled = true;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    class FileInfoAdapter extends RecyclerView.Adapter<ViewHolder> {
        private final List<FileInfo> data;

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

        public FileInfoAdapter(List<FileInfo> data) {
            this.data = data;
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            int resource = ContainerFileManagerFragment.this.viewStyle == BaseFileManagerFragment.ViewStyle.LIST ? R.layout.file_list_item : R.layout.file_grid_item;
            return new ViewHolder(LayoutInflater.from(parent.getContext()).inflate(resource, parent, false));
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public void onBindViewHolder(ViewHolder holder, int position) {
            Context context = ContainerFileManagerFragment.this.getContext();
            final FileInfo item = this.data.get(position);
            FileInfo.Type type = item.type;
            if (item.type == FileInfo.Type.DRIVE) {
                String driveText = ContainerFileManagerFragment.this.getContext().getString(R.string.drive);
                holder.title.setText(driveText + " (" + item.name + ")");
            } else {
                MSLink.LinkInfo linkInfo = item.getLinkinfo();
                if (linkInfo != null && linkInfo.isDirectory) {
                    type = FileInfo.Type.DIRECTORY;
                }
                holder.title.setText(item.getDisplayName());
            }
            holder.subtitle.setVisibility(8);
            holder.runButton.setImageResource(R.drawable.icon_open);
            if (type == FileInfo.Type.DIRECTORY && !ContainerFileManagerFragment.this.folderStack.isEmpty()) {
                holder.subtitle.setText(item.getItemCount() + " " + context.getString(R.string.items));
                holder.subtitle.setVisibility(0);
            } else if (type == FileInfo.Type.FILE) {
                holder.runButton.setImageResource(R.drawable.icon_run);
                holder.subtitle.setText(StringUtils.formatBytes(item.getSize()));
                holder.subtitle.setVisibility(0);
            }
            if (type == FileInfo.Type.FILE) {
                holder.imageView.setImageResource(R.drawable.container_file);
                LoadIconTask loadIconTask = (LoadIconTask) holder.imageView.getTag();
                if (loadIconTask != null) {
                    loadIconTask.cancel();
                }
                LoadIconTask loadIconTask2 = new LoadIconTask(holder.imageView);
                loadIconTask2.loadAsync(item);
                holder.imageView.setTag(loadIconTask2);
            } else {
                holder.imageView.setImageResource(((Integer) ContainerFileManagerFragment.this.getIconForFile(item)).intValue());
            }
            holder.imageView.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerFileManagerFragment$FileInfoAdapter$$ExternalSyntheticLambda2
                @Override // android.view.View.OnClickListener
                public final void onClick(View view) {
                    this.f$0.lambda$onBindViewHolder$0(item, view);
                }
            });
            holder.runButton.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerFileManagerFragment$FileInfoAdapter$$ExternalSyntheticLambda0
                @Override // android.view.View.OnClickListener
                public final void onClick(View view) {
                    this.f$0.lambda$onBindViewHolder$1(item, view);
                }
            });
            holder.menuButton.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.ContainerFileManagerFragment$FileInfoAdapter$$ExternalSyntheticLambda1
                @Override // android.view.View.OnClickListener
                public final void onClick(View view) {
                    this.f$0.lambda$onBindViewHolder$2(item, view);
                }
            });
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda$onBindViewHolder$0(FileInfo item, View v) {
            openFile(item);
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda$onBindViewHolder$1(FileInfo item, View v) {
            openFile(item);
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public final int getItemCount() {
            return this.data.size();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: showListItemMenu, reason: merged with bridge method [inline-methods] */
        public void lambda$onBindViewHolder$2(View anchorView, final FileInfo file) {
            final Context context = ContainerFileManagerFragment.this.getContext();
            PopupMenu listItemMenu = new PopupMenu(context, anchorView);
            if (Build.VERSION.SDK_INT >= 29) {
                listItemMenu.setForceShowIcon(true);
            }
            listItemMenu.inflate(R.menu.file_manager_popup_menu);
            Menu menu = listItemMenu.getMenu();
            menu.findItem(R.id.menu_item_settings).setVisible(false);
            if (ContainerFileManagerFragment.this.folderStack.isEmpty()) {
                menu.findItem(R.id.menu_item_cut).setVisible(false);
                menu.findItem(R.id.menu_item_remove).setVisible(false);
                menu.findItem(R.id.menu_item_rename).setVisible(false);
                menu.findItem(R.id.menu_item_add_favorite).setVisible(false);
            } else if (((FileInfo) ContainerFileManagerFragment.this.folderStack.peek()).name.equals("Favorites")) {
                menu.findItem(R.id.menu_item_add_favorite).setVisible(false);
            }
            listItemMenu.setOnMenuItemClickListener(new PopupMenu.OnMenuItemClickListener() { // from class: com.winlator.ContainerFileManagerFragment$FileInfoAdapter$$ExternalSyntheticLambda3
                @Override // android.widget.PopupMenu.OnMenuItemClickListener
                public final boolean onMenuItemClick(MenuItem menuItem) {
                    return this.f$0.lambda$showListItemMenu$5(file, context, menuItem);
                }
            });
            listItemMenu.show();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
        public /* synthetic */ boolean lambda$showListItemMenu$5(final FileInfo file, Context context, MenuItem menuItem) throws Throwable {
            int itemId = menuItem.getItemId();
            switch (itemId) {
                case R.id.menu_item_add_favorite /* 2131296724 */:
                    ContainerFileManagerFragment.this.addFavorite(file);
                    return true;
                case R.id.menu_item_copy /* 2131296727 */:
                case R.id.menu_item_cut /* 2131296728 */:
                    ContainerFileManagerFragment.this.instantiateClipboard(file, itemId == R.id.menu_item_cut);
                    return true;
                case R.id.menu_item_info /* 2131296737 */:
                    new FileInfoDialog(context, file, ContainerFileManagerFragment.this.container).show();
                    return true;
                case R.id.menu_item_remove /* 2131296749 */:
                    ContainerFileManagerFragment.this.clearClipboard();
                    ContentDialog.confirm(context, R.string.do_you_want_to_remove_this_file, new Runnable() { // from class: com.winlator.ContainerFileManagerFragment$FileInfoAdapter$$ExternalSyntheticLambda5
                        @Override // java.lang.Runnable
                        public final void run() {
                            this.f$0.lambda$showListItemMenu$3(file);
                        }
                    });
                    return true;
                case R.id.menu_item_rename /* 2131296750 */:
                    ContainerFileManagerFragment.this.clearClipboard();
                    ContentDialog.prompt(context, R.string.rename, file.name, new Callback() { // from class: com.winlator.ContainerFileManagerFragment$FileInfoAdapter$$ExternalSyntheticLambda4
                        @Override // com.winlator.core.Callback
                        public final void call(Object obj) {
                            this.f$0.lambda$showListItemMenu$4(file, (String) obj);
                        }
                    });
                    return true;
                default:
                    return true;
            }
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda$showListItemMenu$3(FileInfo file) {
            ContainerFileManagerFragment.this.removeFile(file.toFile());
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda$showListItemMenu$4(FileInfo file, String newName) {
            file.renameTo(newName);
            ContainerFileManagerFragment.this.refreshContent();
        }

        /* JADX WARN: Type inference incomplete: some casts might be missing */
        private void openFile(FileInfo fileInfo) {
            FragmentActivity activity = ContainerFileManagerFragment.this.getActivity();
            MSLink.LinkInfo linkinfo = fileInfo.getLinkinfo();
            boolean z = true;
            if (linkinfo == null ? fileInfo.type != FileInfo.Type.FILE : linkinfo.isDirectory) {
                z = false;
            }
            if (z) {
                Intent intent = new Intent(activity, (Class<?>) XServerDisplayActivity.class);
                intent.putExtra("container_id", ContainerFileManagerFragment.this.container.id);
                intent.putExtra("exec_path", fileInfo.path);
                activity.startActivity(intent);
                return;
            }
            ContainerFileManagerFragment.this.folderStack.push((T) fileInfo);
            ContainerFileManagerFragment.this.refreshContent();
        }
    }

    public Object getIconForFile(FileInfo file) {
        Bitmap bitmap;
        FileInfo.Type type = file.type;
        FileInfo.Type type2 = FileInfo.Type.DIRECTORY;
        Integer numValueOf = Integer.valueOf(R.drawable.container_folder);
        if (type == type2) {
            Context context = getContext();
            if (file.path.endsWith("xuser/" + context.getString(R.string.documents))) {
                return Integer.valueOf(R.drawable.container_folder_documents);
            }
            if (file.path.endsWith("xuser/" + context.getString(R.string.favorites))) {
                return Integer.valueOf(R.drawable.container_folder_favorites);
            }
            return numValueOf;
        }
        if (type == FileInfo.Type.DRIVE) {
            return Integer.valueOf(R.drawable.container_drive);
        }
        String extension = FileUtils.getExtension(file.path);
        switch (extension) {
            case "exe":
                Bitmap bitmap2 = PEParser.extractIcon(file.toFile());
                return bitmap2 != null ? bitmap2 : Integer.valueOf(R.drawable.container_file_window);
            case "bat":
                return Integer.valueOf(R.drawable.container_file_window);
            case "ico":
                Bitmap bitmap3 = MSIcon.decodeFile(file.toFile());
                if (bitmap3 != null) {
                    return bitmap3;
                }
                break;
            case "dll":
                return Integer.valueOf(R.drawable.container_file_library);
            case "lnk":
                MSLink.LinkInfo linkInfo = file.getLinkinfo();
                if (linkInfo != null) {
                    if (linkInfo.isDirectory) {
                        return numValueOf;
                    }
                    String targetPath = linkInfo.iconLocation;
                    if (targetPath == null) {
                        targetPath = linkInfo.targetPath;
                    }
                    String targetPath2 = WineUtils.dosToUnixPath(targetPath, this.container);
                    if (targetPath2.endsWith(".ico")) {
                        bitmap = MSIcon.decodeFile(new File(targetPath2));
                    } else {
                        bitmap = PEParser.extractIcon(new File(targetPath2), linkInfo.iconIndex);
                    }
                    if (bitmap != null) {
                        return bitmap;
                    }
                }
                return Integer.valueOf(R.drawable.container_file_link);
        }
        return Integer.valueOf(R.drawable.container_file);
    }
}
