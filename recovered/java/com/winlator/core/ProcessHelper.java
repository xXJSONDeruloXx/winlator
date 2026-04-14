package com.winlator.core;

import android.os.Process;
import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Map;
import java.util.concurrent.Executors;

/* JADX INFO: loaded from: classes.dex */
public abstract class ProcessHelper {
    private static final ArrayList<Callback<String>> debugCallbacks = new ArrayList<>();

    public enum PState {
        RUNNING,
        SLEEPING,
        WAITING,
        ZOMBIE,
        STOPPED,
        DEAD,
        OTHER
    }

    public static class PStat {
        public int pid = 0;
        public String name = "";
        public PState state = PState.OTHER;
        public int parentPID = 0;
        public boolean guestProcess = false;

        public String toString() {
            return this.pid + " " + this.name + " " + this.state + " " + this.parentPID + " " + this.guestProcess;
        }
    }

    public static void suspendProcess(int pid) {
        Process.sendSignal(pid, 19);
    }

    public static void resumeProcess(int pid) {
        Process.sendSignal(pid, 18);
    }

    public static int exec(String command, EnvVars envVars, File workingDir) {
        return exec(command, envVars, workingDir, null);
    }

    public static int exec(String command, EnvVars envVars, File workingDir, Callback<Integer> terminationCallback) {
        int pid = -1;
        try {
            ProcessBuilder processBuilder = new ProcessBuilder(splitCommand(command)).directory(workingDir);
            if (debugCallbacks.isEmpty()) {
                processBuilder.redirectOutput(new File("/dev/null")).redirectErrorStream(true);
            }
            Map<String, String> environment = processBuilder.environment();
            for (String name : envVars) {
                environment.put(name, envVars.get(name));
            }
            Process process = processBuilder.start();
            Field pidField = process.getClass().getDeclaredField("pid");
            pidField.setAccessible(true);
            pid = pidField.getInt(process);
            pidField.setAccessible(false);
            if (!debugCallbacks.isEmpty()) {
                createDebugThread(process.getInputStream());
                createDebugThread(process.getErrorStream());
            }
            if (terminationCallback != null) {
                createWaitForThread(process, terminationCallback);
            }
        } catch (Exception e) {
        }
        return pid;
    }

    private static void createDebugThread(final InputStream inputStream) {
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.core.ProcessHelper$$ExternalSyntheticLambda1
            @Override // java.lang.Runnable
            public final void run() {
                ProcessHelper.lambda$createDebugThread$0(inputStream);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$createDebugThread$0(InputStream inputStream) {
        BufferedReader reader;
        try {
            reader = new BufferedReader(new InputStreamReader(inputStream));
        } catch (IOException e) {
            return;
        }
        while (true) {
            try {
                String line = reader.readLine();
                if (line != null) {
                    ArrayList<Callback<String>> arrayList = debugCallbacks;
                    synchronized (arrayList) {
                        if (!arrayList.isEmpty()) {
                            for (Callback<String> callback : arrayList) {
                                callback.call(line);
                            }
                        }
                    }
                } else {
                    reader.close();
                    return;
                }
            } finally {
            }
            return;
        }
    }

    private static void createWaitForThread(final Process process, final Callback<Integer> terminationCallback) {
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.core.ProcessHelper$$ExternalSyntheticLambda2
            @Override // java.lang.Runnable
            public final void run() {
                ProcessHelper.lambda$createWaitForThread$1(process, terminationCallback);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda$createWaitForThread$1(Process process, Callback terminationCallback) {
        try {
            int status = process.waitFor();
            terminationCallback.call(Integer.valueOf(status));
        } catch (InterruptedException e) {
        }
    }

    public static void removeAllDebugCallbacks() {
        ArrayList<Callback<String>> arrayList = debugCallbacks;
        synchronized (arrayList) {
            arrayList.clear();
        }
    }

    public static void addDebugCallback(Callback<String> callback) {
        ArrayList<Callback<String>> arrayList = debugCallbacks;
        synchronized (arrayList) {
            if (!arrayList.contains(callback)) {
                arrayList.add(callback);
            }
        }
    }

    public static void removeDebugCallback(Callback<String> callback) {
        ArrayList<Callback<String>> arrayList = debugCallbacks;
        synchronized (arrayList) {
            arrayList.remove(callback);
        }
    }

    public static String[] splitCommand(String command) {
        ArrayList<String> result = new ArrayList<>();
        boolean startedQuotes = false;
        String value = "";
        int i = 0;
        int count = command.length();
        while (true) {
            if (i < count) {
                char currChar = command.charAt(i);
                if (startedQuotes) {
                    if (currChar == '\"') {
                        startedQuotes = false;
                        if (!value.isEmpty()) {
                            result.add(value + '\"');
                            value = "";
                        }
                    } else {
                        value = value + currChar;
                    }
                } else if (currChar == '\"') {
                    startedQuotes = true;
                    value = value + '\"';
                } else {
                    char nextChar = i < count + (-1) ? command.charAt(i + 1) : (char) 0;
                    if (currChar == ' ' || (currChar == '\\' && nextChar == ' ')) {
                        if (currChar == '\\') {
                            value = value + ' ';
                            i++;
                        } else if (!value.isEmpty()) {
                            result.add(value);
                            value = "";
                        }
                    } else {
                        value = value + currChar;
                        if (i == count - 1) {
                            result.add(value);
                            value = "";
                        }
                    }
                }
                i++;
            } else {
                return (String[]) result.toArray(new String[0]);
            }
        }
    }

    public static int getAffinityMask(String cpuList) {
        if (cpuList == null || cpuList.isEmpty()) {
            return 0;
        }
        String[] values = cpuList.split(",");
        int affinityMask = 0;
        for (String value : values) {
            byte index = Byte.parseByte(value);
            affinityMask |= (int) Math.pow(2.0d, index);
        }
        return affinityMask;
    }

    public static int getAffinityMask(boolean[] cpuList) {
        int affinityMask = 0;
        for (int i = 0; i < cpuList.length; i++) {
            if (cpuList[i]) {
                affinityMask |= (int) Math.pow(2.0d, i);
            }
        }
        return affinityMask;
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    /* JADX WARN: Failed to restore switch over string. Please report as a decompilation issue */
    /* JADX WARN: Multi-variable type inference failed */
    /* JADX WARN: Removed duplicated region for block: B:21:0x0072  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public static java.util.List<com.winlator.core.ProcessHelper.PStat> getChildProcesses() {
        /*
            Method dump skipped, instruction units count: 378
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.core.ProcessHelper.getChildProcesses():java.util.List");
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ boolean lambda$getChildProcesses$2(File file, String name) {
        return new File(file, name).isDirectory() && name.matches("[0-9]+");
    }
}
