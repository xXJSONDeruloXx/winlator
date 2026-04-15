package com.winlator;

import android.app.Activity;
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
import android.widget.FrameLayout;
import android.widget.ImageView;
import android.widget.PopupMenu;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.recyclerview.widget.DividerItemDecoration;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.winlator.container.Container;
import com.winlator.container.ContainerManager;
import com.winlator.contentdialog.ContentDialog;
import com.winlator.contentdialog.StorageInfoDialog;
import com.winlator.core.PreloaderDialog;
import com.winlator.xenvironment.RootFS;
import java.util.ArrayList;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ContainersFragment extends Fragment {
    private TextView emptyTextView;
    private ContainerManager manager;
    private PreloaderDialog preloaderDialog;
    private RecyclerView recyclerView;

    @Override // androidx.fragment.app.Fragment
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setHasOptionsMenu(true);
        this.preloaderDialog = new PreloaderDialog(getActivity());
    }

    @Override // androidx.fragment.app.Fragment
    public void onViewCreated(View view, Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        this.manager = new ContainerManager(getContext());
        loadContainersList();
        ((AppCompatActivity) getActivity()).getSupportActionBar().setTitle(R.string.containers);
    }

    @Override // androidx.fragment.app.Fragment
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        FrameLayout frameLayout = (FrameLayout) inflater.inflate(R.layout.containers_fragment, container, false);
        RecyclerView recyclerView = (RecyclerView) frameLayout.findViewById(R.id.RecyclerView);
        this.recyclerView = recyclerView;
        Context context = recyclerView.getContext();
        this.emptyTextView = (TextView) frameLayout.findViewById(R.id.TVEmptyText);
        this.recyclerView.setLayoutManager(new LinearLayoutManager(context));
        DividerItemDecoration itemDecoration = new DividerItemDecoration(this.recyclerView.getContext(), 1);
        itemDecoration.setDrawable(ContextCompat.getDrawable(context, R.drawable.list_item_divider));
        this.recyclerView.addItemDecoration(itemDecoration);
        return frameLayout;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public void loadContainersList() {
        ArrayList<Container> containers = this.manager.getContainers();
        this.recyclerView.setAdapter(new ContainersAdapter(containers));
        if (containers.isEmpty()) {
            this.emptyTextView.setVisibility(0);
        }
    }

    @Override // androidx.fragment.app.Fragment
    public void onCreateOptionsMenu(Menu menu, MenuInflater menuInflater) {
        menuInflater.inflate(R.menu.containers_menu, menu);
    }

    @Override // androidx.fragment.app.Fragment
    public boolean onOptionsItemSelected(MenuItem menuItem) {
        if (menuItem.getItemId() == R.id.menu_item_add) {
            if (!RootFS.find(getContext()).isValid()) {
                return false;
            }
            FragmentManager fragmentManager = getParentFragmentManager();
            fragmentManager.beginTransaction().addToBackStack(null).replace(R.id.FLFragmentContainer, new ContainerDetailFragment()).commit();
            return true;
        }
        return super.onOptionsItemSelected(menuItem);
    }

    /* JADX INFO: Access modifiers changed from: private */
    class ContainersAdapter extends RecyclerView.Adapter<ContainersAdapter.ViewHolder> {
        private final List<Container> data;

        private class ViewHolder extends RecyclerView.ViewHolder {
            private final ImageView imageView;
            private final ImageView menuButton;
            private final ImageView runButton;
            private final TextView title;

            private ViewHolder(View view) {
                super(view);
                this.imageView = (ImageView) view.findViewById(R.id.ImageView);
                this.title = (TextView) view.findViewById(R.id.TVTitle);
                this.runButton = (ImageView) view.findViewById(R.id.BTRun);
                this.menuButton = (ImageView) view.findViewById(R.id.BTMenu);
            }
        }

        public ContainersAdapter(List<Container> data) {
            this.data = data;
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public final ViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
            return new ViewHolder(LayoutInflater.from(parent.getContext()).inflate(R.layout.container_list_item, parent, false));
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public void onBindViewHolder(ViewHolder holder, int position) {
            final Container item = this.data.get(position);
            holder.imageView.setImageResource(R.drawable.icon_container);
            holder.title.setText(item.getName());
            holder.runButton.setOnClickListener(view -> lambda_onBindViewHolder_0(item, view));
            holder.menuButton.setOnClickListener(view -> lambda_onBindViewHolder_1(view, item));
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_onBindViewHolder_0(Container item, View view) {
            runContainer(item);
        }

        @Override // androidx.recyclerview.widget.RecyclerView.Adapter
        public final int getItemCount() {
            return this.data.size();
        }

        /* JADX INFO: Access modifiers changed from: private */
        /* JADX INFO: renamed from: showListItemMenu, reason: merged with bridge method [inline-methods] */
        public void lambda_onBindViewHolder_1(View anchorView, final Container container) {
            final MainActivity activity = (MainActivity) ContainersFragment.this.getActivity();
            PopupMenu listItemMenu = new PopupMenu(activity, anchorView);
            listItemMenu.inflate(R.menu.container_popup_menu);
            if (Build.VERSION.SDK_INT >= 29) {
                listItemMenu.setForceShowIcon(true);
            }
            listItemMenu.setOnMenuItemClickListener(menuItem -> lambda_showListItemMenu_6(activity, container, menuItem));
            listItemMenu.show();
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ boolean lambda_showListItemMenu_6(MainActivity activity, final Container container, MenuItem menuItem) {
            int itemId = menuItem.getItemId();
            if (itemId == R.id.menu_item_duplicate) {
                    ContentDialog.confirm(ContainersFragment.this.getContext(), R.string.do_you_want_to_duplicate_this_container, () -> lambda_showListItemMenu_3(container));
            } else if (itemId == R.id.menu_item_edit) {
                    activity.showFragment(new ContainerDetailFragment(container.id));
            } else if (itemId == R.id.menu_item_file_manager) {
                    activity.showFragment(new ContainerFileManagerFragment(container.id));
            } else if (itemId == R.id.menu_item_info) {
                    new StorageInfoDialog(activity, container).show();
            } else if (itemId == R.id.menu_item_remove) {
                    ContentDialog.confirm(ContainersFragment.this.getContext(), R.string.do_you_want_to_remove_this_container, () -> lambda_showListItemMenu_5(container));
            }
            return true;
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_showListItemMenu_3(Container container) {
            ContainersFragment.this.preloaderDialog.show(R.string.duplicating_container);
            ContainersFragment.this.manager.duplicateContainerAsync(container, () -> lambda_showListItemMenu_2());
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_showListItemMenu_2() {
            ContainersFragment.this.preloaderDialog.close();
            ContainersFragment.this.loadContainersList();
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_showListItemMenu_5(Container container) {
            ContainersFragment.this.preloaderDialog.show(R.string.removing_container);
            ContainersFragment.this.manager.removeContainerAsync(container, () -> lambda_showListItemMenu_4());
        }

        /* JADX INFO: Access modifiers changed from: private */
        public /* synthetic */ void lambda_showListItemMenu_4() {
            ContainersFragment.this.preloaderDialog.close();
            ContainersFragment.this.loadContainersList();
        }

        private void runContainer(Container container) {
            Activity activity = ContainersFragment.this.getActivity();
            Intent intent = new Intent(activity, (Class<?>) XServerDisplayActivity.class);
            intent.putExtra("container_id", container.id);
            activity.startActivity(intent);
        }
    }
}
