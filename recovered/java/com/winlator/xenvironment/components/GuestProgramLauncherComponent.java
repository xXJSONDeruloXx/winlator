package com.winlator.xenvironment.components;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Process;
import androidx.preference.PreferenceManager;
import com.winlator.box64.Box64PresetManager;
import com.winlator.core.Callback;
import com.winlator.core.EnvVars;
import com.winlator.core.FileUtils;
import com.winlator.core.GeneralComponents;
import com.winlator.core.LocaleHelper;
import com.winlator.core.ProcessHelper;
import com.winlator.widget.LogView;
import com.winlator.xenvironment.EnvironmentComponent;
import com.winlator.xenvironment.RootFS;
import java.io.File;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class GuestProgramLauncherComponent extends EnvironmentComponent {
    private String box64Preset = "CONSERVATIVE";
    private EnvVars envVars;
    private String guestExecutable;
    private Callback<Integer> terminationCallback;
    private static int pid = -1;
    private static final Object lock = new Object();

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void start() {
        synchronized (lock) {
            stop();
            extractBox64File();
            copyDefaultBox64RCFile();
            pid = execGuestProgram();
        }
    }

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void stop() {
        synchronized (lock) {
            int i = pid;
            if (i != -1) {
                Process.killProcess(i);
                pid = -1;
            }
        }
    }

    public void setTerminationCallback(Callback<Integer> terminationCallback) {
        this.terminationCallback = terminationCallback;
    }

    public void setGuestExecutable(String guestExecutable) {
        this.guestExecutable = guestExecutable;
    }

    public void setEnvVars(EnvVars envVars) {
        this.envVars = envVars;
    }

    public void setBox64Preset(String box64Preset) {
        this.box64Preset = box64Preset;
    }

    private int execGuestProgram() {
        RootFS rootFS = this.environment.getRootFS();
        File rootDir = rootFS.getRootDir();
        EnvVars envVars = new EnvVars();
        addBox64EnvVars(envVars);
        LocaleHelper.setEnvVars(envVars);
        envVars.put("HOME", rootDir + "/home/xuser");
        envVars.put("USER", "xuser");
        envVars.put("TMPDIR", rootDir + "/tmp");
        envVars.put("DISPLAY", ":0");
        envVars.put("PATH", rootDir + rootFS.getWinePath() + "/bin:" + rootDir + "/usr/local/bin:" + rootDir + "/usr/bin");
        envVars.put("LD_LIBRARY_PATH", rootFS.getLibDir().getPath());
        StringBuilder sb = new StringBuilder();
        sb.append(rootDir);
        sb.append("/lib/x86_64-linux-gnu");
        envVars.put("BOX64_LD_LIBRARY_PATH", sb.toString());
        envVars.put("ANDROID_SYSVSHM_SERVER", rootDir + "/tmp/.sysvshm/SM0");
        EnvVars envVars2 = this.envVars;
        if (envVars2 != null) {
            envVars.putAll(envVars2);
        }
        File shmDir = new File(rootDir, "/tmp/shm");
        if (!shmDir.isDirectory()) {
            shmDir.mkdirs();
        }
        String command = rootDir + "/usr/local/bin/box64 " + this.guestExecutable;
        return ProcessHelper.exec(command, envVars, rootDir, new Callback() { // from class: com.winlator.xenvironment.components.GuestProgramLauncherComponent$$ExternalSyntheticLambda0
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                this.f$0.lambda$execGuestProgram$0((Integer) obj);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$execGuestProgram$0(Integer status) {
        synchronized (lock) {
            pid = -1;
        }
        Callback<Integer> callback = this.terminationCallback;
        if (callback != null) {
            callback.call(status);
        }
    }

    private void extractBox64File() {
        Context context = this.environment.getContext();
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        String box64Version = preferences.getString("box64_version", "0.4.0");
        String currentBox64Version = preferences.getString("current_box64_version", "");
        if (!box64Version.equals(currentBox64Version)) {
            GeneralComponents.extractFile(GeneralComponents.Type.BOX64, context, box64Version, "0.4.0");
            preferences.edit().putString("current_box64_version", box64Version).apply();
        }
    }

    private void copyDefaultBox64RCFile() {
        Context context = this.environment.getContext();
        RootFS rootFS = this.environment.getRootFS();
        FileUtils.copy(context, "box64/default.box64rc", new File(rootFS.getRootDir(), "/etc/config.box64rc"));
    }

    private void addBox64EnvVars(EnvVars envVars) {
        File parent;
        Context context = this.environment.getContext();
        RootFS rootFS = this.environment.getRootFS();
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        int box64Logs = preferences.getInt("box64_logs", 0);
        boolean saveToFile = preferences.getBoolean("save_logs_to_file", false);
        envVars.put("BOX64_NOBANNER", box64Logs >= 1 ? "0" : "1");
        envVars.put("BOX64_DYNAREC", "1");
        envVars.put("BOX64_UNITYPLAYER", "0");
        if (box64Logs >= 1) {
            envVars.put("BOX64_LOG", "1");
            envVars.put("BOX64_DYNAREC_MISSING", "1");
            if (box64Logs == 2) {
                envVars.put("BOX64_SHOWSEGV", "1");
                envVars.put("BOX64_DLSYM_ERROR", "1");
                envVars.put("BOX64_TRACE_FILE", "stderr");
                if (saveToFile && (parent = new File(preferences.getString("log_file", LogView.getLogFile().getPath())).getParentFile()) != null && parent.isDirectory()) {
                    File traceDir = new File(parent, "trace");
                    if (!traceDir.isDirectory()) {
                        traceDir.mkdirs();
                    }
                    FileUtils.clear(traceDir);
                    envVars.put("BOX64_TRACE_FILE", traceDir + "/box64-%pid.txt");
                }
            }
        }
        envVars.putAll(Box64PresetManager.getEnvVars(context, this.box64Preset));
        File box64RCFile = new File(rootFS.getRootDir(), "/etc/config.box64rc");
        envVars.put("BOX64_RCFILE", box64RCFile.getPath());
    }

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void onPause() {
        synchronized (lock) {
            if (pid != -1) {
                List<ProcessHelper.PStat> processes = ProcessHelper.getChildProcesses();
                for (int i = processes.size() - 1; i >= 0; i--) {
                    ProcessHelper.PStat process = processes.get(i);
                    if (process.guestProcess && process.state != ProcessHelper.PState.STOPPED) {
                        ProcessHelper.suspendProcess(process.pid);
                    }
                }
            }
        }
    }

    @Override // com.winlator.xenvironment.EnvironmentComponent
    public void onResume() {
        synchronized (lock) {
            if (pid != -1) {
                List<ProcessHelper.PStat> processes = ProcessHelper.getChildProcesses();
                for (int i = 0; i < processes.size(); i++) {
                    ProcessHelper.PStat process = processes.get(i);
                    if (process.guestProcess && process.state == ProcessHelper.PState.STOPPED) {
                        ProcessHelper.resumeProcess(process.pid);
                    }
                }
            }
        }
    }
}
