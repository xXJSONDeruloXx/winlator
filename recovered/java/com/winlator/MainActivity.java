package com.winlator;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.Configuration;
import android.net.Uri;
import android.os.Bundle;
import android.view.MenuItem;
import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;
import androidx.drawerlayout.widget.DrawerLayout;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.preference.PreferenceManager;
import com.google.android.material.navigation.NavigationView;
import com.winlator.contentdialog.AboutDialog;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import com.winlator.core.LocaleHelper;
import com.winlator.core.PreloaderDialog;
import com.winlator.xenvironment.RootFSInstaller;

/* JADX INFO: loaded from: classes.dex */
public class MainActivity extends AppCompatActivity implements NavigationView.OnNavigationItemSelectedListener {
    private Fragment currentFragment;
    private DrawerLayout drawerLayout;
    private Callback<Uri> openFileCallback;
    private SharedPreferences preferences;
    private int selectedProfileId;
    public final PreloaderDialog preloaderDialog = new PreloaderDialog(this);
    private boolean editInputControls = false;

    @Override // androidx.fragment.app.FragmentActivity, androidx.activity.ComponentActivity, androidx.core.app.ComponentActivity, android.app.Activity
    protected void onCreate(Bundle savedInstanceState) {
        AppUtils.setActivityTheme(this);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_activity);
        this.drawerLayout = (DrawerLayout) findViewById(R.id.DrawerLayout);
        NavigationView navigationView = (NavigationView) findViewById(R.id.NavigationView);
        navigationView.setNavigationItemSelectedListener(this);
        setSupportActionBar((Toolbar) findViewById(R.id.Toolbar));
        ActionBar actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
        this.preferences = PreferenceManager.getDefaultSharedPreferences(this);
        Intent intent = getIntent();
        boolean booleanExtra = intent.getBooleanExtra("edit_input_controls", false);
        this.editInputControls = booleanExtra;
        if (booleanExtra) {
            this.selectedProfileId = intent.getIntExtra("selected_profile_id", 0);
            actionBar.setHomeAsUpIndicator(R.drawable.icon_action_bar_back);
            onNavigationItemSelected(navigationView.getMenu().findItem(R.id.menu_item_input_controls));
            navigationView.setCheckedItem(R.id.menu_item_input_controls);
            return;
        }
        boolean showShortcutsFirst = this.preferences.getBoolean("show_shortcuts_first", false);
        int selectedMenuItemId = intent.getIntExtra("selected_menu_item_id", 0);
        int menuItemId = selectedMenuItemId > 0 ? selectedMenuItemId : showShortcutsFirst ? R.id.menu_item_shortcuts : R.id.menu_item_containers;
        actionBar.setHomeAsUpIndicator(R.drawable.icon_action_bar_menu);
        onNavigationItemSelected(navigationView.getMenu().findItem(menuItemId));
        navigationView.setCheckedItem(menuItemId);
        if (!requestAppPermissions()) {
            RootFSInstaller.installIfNeeded(this);
        }
        int containerId = intent.getIntExtra("container_id", 0);
        String startPath = intent.getStringExtra("start_path");
        if (containerId > 0 && startPath != null) {
            showFragment(new ContainerFileManagerFragment(containerId, startPath));
        }
    }

    @Override // androidx.appcompat.app.AppCompatActivity, android.app.Activity, android.view.ContextThemeWrapper, android.content.ContextWrapper
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(LocaleHelper.setSystemLocale(newBase));
    }

    @Override // androidx.fragment.app.FragmentActivity, androidx.activity.ComponentActivity, android.app.Activity
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == 1) {
            if (grantResults.length > 0 && grantResults[0] == 0) {
                RootFSInstaller.installIfNeeded(this);
            } else {
                finish();
            }
        }
    }

    @Override // androidx.fragment.app.FragmentActivity, androidx.activity.ComponentActivity, android.app.Activity
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        Callback<Uri> callback;
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == 2 && resultCode == -1 && (callback = this.openFileCallback) != null) {
            callback.call(data.getData());
            this.openFileCallback = null;
        }
    }

    @Override // androidx.appcompat.app.AppCompatActivity, androidx.fragment.app.FragmentActivity, androidx.activity.ComponentActivity, android.app.Activity, android.content.ComponentCallbacks
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        int i = newConfig.orientation;
        if (i == 2 || i == 1) {
            Fragment fragment = this.currentFragment;
            if (fragment instanceof BaseFileManagerFragment) {
                ((BaseFileManagerFragment) fragment).onOrientationChanged();
            }
        }
    }

    @Override // androidx.activity.ComponentActivity, android.app.Activity
    public void onBackPressed() {
        Fragment fragment = this.currentFragment;
        if (fragment != null && fragment.isVisible()) {
            Fragment fragment2 = this.currentFragment;
            if (fragment2 instanceof BaseFileManagerFragment) {
                BaseFileManagerFragment fileManagerFragment = (BaseFileManagerFragment) fragment2;
                if (fileManagerFragment.onBackPressed()) {
                    return;
                }
            } else if (fragment2 instanceof ContainersFragment) {
                finish();
            }
        }
        showFragment(new ContainersFragment());
    }

    public void setOpenFileCallback(Callback<Uri> openFileCallback) {
        this.openFileCallback = openFileCallback;
    }

    private boolean requestAppPermissions() {
        if (ContextCompat.checkSelfPermission(this, "android.permission.WRITE_EXTERNAL_STORAGE") == 0 && ContextCompat.checkSelfPermission(this, "android.permission.READ_EXTERNAL_STORAGE") == 0) {
            return false;
        }
        String[] permissions = {"android.permission.WRITE_EXTERNAL_STORAGE", "android.permission.READ_EXTERNAL_STORAGE"};
        ActivityCompat.requestPermissions(this, permissions, 1);
        return true;
    }

    @Override // android.app.Activity
    public boolean onOptionsItemSelected(MenuItem menuItem) {
        int itemId = menuItem.getItemId();
        if (itemId == R.id.menu_item_add || itemId == R.id.menu_item_home || itemId == R.id.menu_item_view_style || itemId == R.id.menu_item_new_folder) {
            return super.onOptionsItemSelected(menuItem);
        }
        if (this.editInputControls) {
            setResult(-1);
            finish();
        } else {
            Fragment fragment = this.currentFragment;
            if (fragment instanceof BaseFileManagerFragment) {
                BaseFileManagerFragment fileManagerFragment = (BaseFileManagerFragment) fragment;
                if (fileManagerFragment.onOptionsMenuClicked()) {
                    return true;
                }
            }
            this.drawerLayout.openDrawer(8388611);
        }
        return true;
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    @Override // com.google.android.material.navigation.NavigationView.OnNavigationItemSelectedListener
    public boolean onNavigationItemSelected(MenuItem item) {
        FragmentManager fragmentManager = getSupportFragmentManager();
        if (fragmentManager.getBackStackEntryCount() > 0) {
            fragmentManager.popBackStack((String) null, 1);
        }
        switch (item.getItemId()) {
            case R.id.menu_item_about /* 2131296721 */:
                new AboutDialog(this).show();
                return true;
            case R.id.menu_item_containers /* 2131296726 */:
                this.preferences.edit().putBoolean("show_shortcuts_first", false).apply();
                showFragment(new ContainersFragment());
                return true;
            case R.id.menu_item_input_controls /* 2131296738 */:
                showFragment(new InputControlsFragment(this.selectedProfileId));
                return true;
            case R.id.menu_item_settings /* 2131296752 */:
                showFragment(new SettingsFragment());
                return true;
            case R.id.menu_item_shortcuts /* 2131296753 */:
                this.preferences.edit().putBoolean("show_shortcuts_first", true).apply();
                showFragment(new ShortcutsFragment());
                return true;
            default:
                return true;
        }
    }

    public void showFragment(Fragment fragment) {
        FragmentManager fragmentManager = getSupportFragmentManager();
        fragmentManager.beginTransaction().replace(R.id.FLFragmentContainer, fragment).commit();
        this.drawerLayout.closeDrawer(8388611);
        this.currentFragment = fragment;
    }
}
