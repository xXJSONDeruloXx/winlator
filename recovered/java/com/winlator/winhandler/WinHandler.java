package com.winlator.winhandler;

import android.view.KeyEvent;
import android.view.MotionEvent;
import com.winlator.XServerDisplayActivity;
import com.winlator.core.FileUtils;
import com.winlator.core.GeneralComponents;
import com.winlator.core.StringUtils;
import com.winlator.xserver.XServer;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.UnknownHostException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.ArrayDeque;
import java.util.concurrent.Executors;

/* JADX INFO: loaded from: classes.dex */
public class WinHandler {
    private final ArrayDeque<Runnable> actions;
    protected final XServerDisplayActivity activity;
    public final GamepadHandler gamepadHandler;
    protected boolean initReceived;
    private InetAddress localhost;
    private MIDIHandler midiHandler;
    private OnGetProcessInfoListener onGetProcessInfoListener;
    protected final ByteBuffer receiveData;
    private final DatagramPacket receivePacket;
    private boolean running;
    protected final ByteBuffer sendData;
    private final DatagramPacket sendPacket;
    private DatagramSocket socket;

    public WinHandler(XServerDisplayActivity activity) {
        ByteBuffer byteBufferAllocate = ByteBuffer.allocate(128);
        ByteOrder byteOrder = ByteOrder.LITTLE_ENDIAN;
        ByteBuffer byteBufferOrder = byteBufferAllocate.order(byteOrder);
        this.sendData = byteBufferOrder;
        ByteBuffer byteBufferOrder2 = ByteBuffer.allocate(64).order(byteOrder);
        this.receiveData = byteBufferOrder2;
        this.sendPacket = new DatagramPacket(byteBufferOrder.array(), byteBufferOrder.capacity());
        this.receivePacket = new DatagramPacket(byteBufferOrder2.array(), byteBufferOrder2.capacity());
        this.actions = new ArrayDeque<>();
        this.initReceived = false;
        this.running = false;
        this.gamepadHandler = new GamepadHandler(this);
        this.activity = activity;
    }

    protected boolean sendPacket(int port) {
        return sendPacket(port, 64);
    }

    protected boolean sendPacket(int port, int packetLength) {
        try {
            int size = this.sendData.position();
            if (size == 0) {
                return false;
            }
            this.sendPacket.setAddress(this.localhost);
            this.sendPacket.setPort(port);
            this.sendPacket.setLength(packetLength);
            this.socket.send(this.sendPacket);
            this.sendPacket.setLength(64);
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    protected boolean sendPacket(int port, byte[] data) {
        try {
            this.sendPacket.setData(data);
            this.sendPacket.setAddress(this.localhost);
            this.sendPacket.setPort(port);
            this.socket.send(this.sendPacket);
            this.sendPacket.setData(this.sendData.array());
            return true;
        } catch (IOException e) {
            return false;
        }
    }

    public void exec(String command) {
        String command2 = command.trim();
        if (command2.isEmpty()) {
            return;
        }
        String[] cmdList = command2.split(" ", 2);
        final String filename = cmdList[0];
        final String parameters = cmdList.length > 1 ? cmdList[1] : "";
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda11
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$exec$0(filename, parameters);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$exec$0(String filename, String parameters) {
        byte[] filenameBytes = filename.getBytes();
        byte[] parametersBytes = parameters.getBytes();
        this.sendData.rewind();
        this.sendData.put((byte) 2);
        this.sendData.putInt(filenameBytes.length + parametersBytes.length + 8);
        this.sendData.putInt(filenameBytes.length);
        this.sendData.putInt(parametersBytes.length);
        this.sendData.put(filenameBytes);
        this.sendData.put(parametersBytes);
        sendPacket(7946);
    }

    public void killProcess(String processName) {
        killProcess(processName, 0);
    }

    public void killProcess(final String processName, final int pid) {
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda9
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$killProcess$1(processName, pid);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$killProcess$1(String processName, int pid) {
        this.sendData.rewind();
        this.sendData.put((byte) 3);
        if (processName == null) {
            this.sendData.putInt(0);
        } else {
            byte[] bytes = processName.getBytes();
            int minLength = Math.min(bytes.length, 55);
            this.sendData.putInt(minLength);
            this.sendData.put(bytes, 0, minLength);
        }
        this.sendData.putInt(pid);
        sendPacket(7946);
    }

    public void listProcesses() {
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda1
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$listProcesses$2();
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$listProcesses$2() {
        OnGetProcessInfoListener onGetProcessInfoListener;
        this.sendData.rewind();
        this.sendData.put((byte) 4);
        this.sendData.putInt(0);
        if (!sendPacket(7946) && (onGetProcessInfoListener = this.onGetProcessInfoListener) != null) {
            onGetProcessInfoListener.onGetProcessInfo(0, 0, null);
        }
    }

    public void setProcessAffinity(final String processName, final int affinityMask) {
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda8
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$setProcessAffinity$3(processName, affinityMask);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$setProcessAffinity$3(String processName, int affinityMask) {
        byte[] bytes = processName.getBytes();
        this.sendData.rewind();
        this.sendData.put((byte) 6);
        this.sendData.putInt(bytes.length + 9);
        this.sendData.putInt(0);
        this.sendData.putInt(affinityMask);
        this.sendData.put((byte) bytes.length);
        this.sendData.put(bytes);
        sendPacket(7946);
    }

    public void setProcessAffinity(final int pid, final int affinityMask) {
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda5
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$setProcessAffinity$4(pid, affinityMask);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$setProcessAffinity$4(int pid, int affinityMask) {
        this.sendData.rewind();
        this.sendData.put((byte) 6);
        this.sendData.putInt(9);
        this.sendData.putInt(pid);
        this.sendData.putInt(affinityMask);
        this.sendData.put((byte) 0);
        sendPacket(7946);
    }

    public void mouseEvent(final int flags, final int dx, final int dy, final int wheelDelta) {
        if (this.initReceived) {
            addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda6
                @Override // java.lang.Runnable
                public final void run() {
                    this.f$0.lambda$mouseEvent$5(flags, dx, dy, wheelDelta);
                }
            });
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$mouseEvent$5(int flags, int dx, int dy, int wheelDelta) {
        this.sendData.rewind();
        this.sendData.put((byte) 7);
        this.sendData.putInt(10);
        this.sendData.putInt(flags);
        this.sendData.putShort((short) dx);
        this.sendData.putShort((short) dy);
        this.sendData.putShort((short) wheelDelta);
        this.sendData.put((byte) ((flags & 1) != 0 ? 1 : 0));
        sendPacket(7946);
    }

    public void bringToFront(String processName) {
        bringToFront(processName, 0L);
    }

    public void bringToFront(final String processName, final long handle) {
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda10
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$bringToFront$7(processName, handle);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$bringToFront$7(String processName, long handle) {
        this.sendData.rewind();
        this.sendData.put((byte) 12);
        byte[] bytes = processName.getBytes();
        int minLength = Math.min(bytes.length, 51);
        this.sendData.putInt(minLength);
        this.sendData.put(bytes, 0, minLength);
        this.sendData.putLong(handle);
        sendPacket(7946);
    }

    public void showDesktop() {
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda4
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$showDesktop$8();
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$showDesktop$8() {
        this.sendData.rewind();
        this.sendData.put((byte) 18);
        this.sendData.putInt(0);
        sendPacket(7946);
    }

    public void setClipboardData(final String data) {
        addAction(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda7
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$setClipboardData$9(data);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$setClipboardData$9(String data) {
        this.sendData.rewind();
        byte[] bytes = data.getBytes();
        this.sendData.put((byte) 14);
        this.sendData.putInt(bytes.length);
        if (sendPacket(7946)) {
            sendPacket(7946, bytes);
        }
    }

    protected void addAction(Runnable action) {
        synchronized (this.actions) {
            this.actions.add(action);
            this.actions.notify();
        }
    }

    public void setOnGetProcessInfoListener(OnGetProcessInfoListener onGetProcessInfoListener) {
        synchronized (this.actions) {
            this.onGetProcessInfoListener = onGetProcessInfoListener;
        }
    }

    private void startSendThread() {
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda3
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$startSendThread$10();
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$startSendThread$10() {
        while (this.running) {
            synchronized (this.actions) {
                while (this.initReceived && !this.actions.isEmpty()) {
                    this.actions.poll().run();
                }
                try {
                    this.actions.wait();
                } catch (InterruptedException e) {
                }
            }
        }
    }

    public void stop() {
        this.running = false;
        DatagramSocket datagramSocket = this.socket;
        if (datagramSocket != null) {
            datagramSocket.close();
            this.socket = null;
        }
        synchronized (this.actions) {
            this.actions.notify();
        }
        MIDIHandler mIDIHandler = this.midiHandler;
        if (mIDIHandler != null) {
            mIDIHandler.close();
            this.midiHandler.destroy();
            this.midiHandler = null;
        }
    }

    private void handleRequest(byte requestCode, int port) throws IOException {
        switch (requestCode) {
            case 1:
                this.initReceived = true;
                synchronized (this.actions) {
                    this.actions.notify();
                    break;
                }
                return;
            case 5:
                if (this.onGetProcessInfoListener == null) {
                    return;
                }
                ByteBuffer byteBuffer = this.receiveData;
                byteBuffer.position(byteBuffer.position() + 4);
                int numProcesses = this.receiveData.getShort();
                int index = this.receiveData.getShort();
                int pid = this.receiveData.getInt();
                long memoryUsage = this.receiveData.getLong();
                int affinityMask = this.receiveData.getInt();
                boolean wow64Process = this.receiveData.get() == 1;
                byte[] bytes = new byte[32];
                this.receiveData.get(bytes);
                String name = StringUtils.fromANSIString(bytes);
                this.onGetProcessInfoListener.onGetProcessInfo(index, numProcesses, new ProcessInfo(pid, name, memoryUsage, affinityMask, wow64Process));
                return;
            case 8:
                this.gamepadHandler.handleGetGamepadRequest(port);
                return;
            case 10:
                this.gamepadHandler.handleReleaseGamepadRequest(port);
                return;
            case 13:
                short x = this.receiveData.getShort();
                short y = this.receiveData.getShort();
                XServer xServer = this.activity.getXServer();
                xServer.pointer.setX(x);
                xServer.pointer.setY(y);
                this.activity.getXServerView().requestRender();
                return;
            case 15:
                int requestLength = this.receiveData.getInt();
                byte[] data = new byte[requestLength];
                this.socket.receive(new DatagramPacket(data, data.length));
                FileUtils.openIntent(this.activity, new String(data));
                return;
            case 16:
                boolean isMidiOut = this.receiveData.get() == 1;
                if (this.midiHandler == null) {
                    this.midiHandler = new MIDIHandler(this);
                }
                if (isMidiOut) {
                    this.midiHandler.open(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda2
                        @Override // java.lang.Runnable
                        public final void run() {
                            this.f$0.lambda$handleRequest$11();
                        }
                    });
                    return;
                } else {
                    this.midiHandler.outputPortConnect();
                    this.midiHandler.addClient(port);
                    return;
                }
            case 17:
                MIDIHandler mIDIHandler = this.midiHandler;
                if (mIDIHandler != null) {
                    mIDIHandler.outputPortDisconnect();
                    this.midiHandler.close();
                    return;
                }
                return;
            case 19:
                this.gamepadHandler.handleSetGamepadStateRequest(port);
                return;
            default:
                return;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$handleRequest$11() {
        if (this.midiHandler.init()) {
            String soundfont = this.activity.getPreferences().getString("soundfont", "SONiVOX-EAS-GM-Wavetable");
            this.midiHandler.loadSoundFont(GeneralComponents.getDefinitivePath(GeneralComponents.Type.SOUNDFONT, this.activity, soundfont));
        }
    }

    public void start() {
        try {
            this.localhost = InetAddress.getLocalHost();
        } catch (UnknownHostException e) {
            try {
                this.localhost = InetAddress.getByName("127.0.0.1");
            } catch (UnknownHostException e2) {
            }
        }
        this.running = true;
        startSendThread();
        Executors.newSingleThreadExecutor().execute(new Runnable() { // from class: com.winlator.winhandler.WinHandler$$ExternalSyntheticLambda0
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$start$12();
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$start$12() {
        try {
            DatagramSocket datagramSocket = new DatagramSocket((SocketAddress) null);
            this.socket = datagramSocket;
            datagramSocket.setReuseAddress(true);
            this.socket.bind(new InetSocketAddress((InetAddress) null, 7947));
            while (this.running) {
                this.socket.receive(this.receivePacket);
                synchronized (this.actions) {
                    this.receiveData.rewind();
                    byte requestCode = this.receiveData.get();
                    handleRequest(requestCode, this.receivePacket.getPort());
                }
            }
        } catch (IOException e) {
        }
    }

    public boolean onGenericMotionEvent(MotionEvent event) {
        return this.gamepadHandler.onGenericMotionEvent(event);
    }

    public boolean onKeyEvent(KeyEvent event) {
        return this.gamepadHandler.onKeyEvent(event);
    }

    public MIDIHandler getMIDIhandler() {
        if (this.midiHandler == null) {
            this.midiHandler = new MIDIHandler(this);
        }
        return this.midiHandler;
    }
}
