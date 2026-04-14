package com.winlator.winhandler;

import android.content.SharedPreferences;
import android.view.KeyEvent;
import android.view.MotionEvent;
import com.winlator.core.ArrayUtils;
import com.winlator.inputcontrols.ControlsProfile;
import com.winlator.inputcontrols.ExternalController;
import com.winlator.inputcontrols.GamepadSlot;
import com.winlator.inputcontrols.GamepadState;
import com.winlator.inputcontrols.GamepadVibration;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

/* JADX INFO: loaded from: classes.dex */
public class GamepadHandler {
    private GamepadPlayerConfig[] gamepadPlayerConfigs;
    private final WinHandler winHandler;
    private final List<GamepadClient> gamepadClients = new CopyOnWriteArrayList();
    private PreferredInputApi preferredInputApi = PreferredInputApi.AUTO;
    private byte dinputMapperType = 1;
    private final GamepadSlot[] gamepadSlots = new GamepadSlot[4];
    private final ArrayList<ExternalController> connectedControllers = new ArrayList<>(4);

    public enum PreferredInputApi {
        AUTO,
        DINPUT,
        XINPUT,
        BOTH
    }

    /* JADX INFO: Access modifiers changed from: private */
    static class GamepadClient {
        private final boolean[] enabledSlots;
        private final boolean isXInput;
        private final int port;
        private final int processId;
        private boolean updatedOnce;

        private GamepadClient(int port, int processId, boolean isXInput) {
            this.enabledSlots = new boolean[4];
            this.updatedOnce = false;
            this.port = port;
            this.processId = processId;
            this.isXInput = isXInput;
        }
    }

    public GamepadHandler(WinHandler winHandler) {
        this.winHandler = winHandler;
    }

    private void updateGamepadSlots() {
        if (this.gamepadPlayerConfigs == null) {
            SharedPreferences preferences = this.winHandler.activity.getPreferences();
            this.gamepadPlayerConfigs = new GamepadPlayerConfig[4];
            for (byte i = 0; i < 4; i = (byte) (i + 1)) {
                this.gamepadPlayerConfigs[i] = new GamepadPlayerConfig(preferences.getString("gamepad_player" + ((int) i), ""));
            }
        }
        ControlsProfile profile = this.winHandler.activity.getInputControlsView().getProfile();
        boolean useVirtualGamepad = profile != null && profile.isVirtualGamepad();
        for (byte i2 = 0; i2 < 4; i2 = (byte) (i2 + 1)) {
            this.gamepadSlots[i2] = null;
        }
        synchronized (this.connectedControllers) {
            ExternalController.updateConnectedControllers(this.connectedControllers);
        }
        boolean autoAssign = true;
        for (byte i3 = 0; i3 < 4; i3 = (byte) (i3 + 1)) {
            GamepadPlayerConfig config = this.gamepadPlayerConfigs[i3];
            if (!config.name.isEmpty()) {
                if (config.mode == 0) {
                    Iterator<ExternalController> it = this.connectedControllers.iterator();
                    while (true) {
                        if (it.hasNext()) {
                            ExternalController controller = it.next();
                            if (controller.getName().equals(config.name)) {
                                this.gamepadSlots[i3] = controller;
                                autoAssign = false;
                                break;
                            }
                        }
                    }
                } else if (useVirtualGamepad && profile.getName().equals(config.name)) {
                    this.gamepadSlots[i3] = profile;
                    autoAssign = false;
                }
            }
        }
        if (autoAssign) {
            if (useVirtualGamepad) {
                this.gamepadSlots[0] = profile;
            }
            int index = 0;
            for (byte i4 = 0; i4 < 4; i4 = (byte) (i4 + 1)) {
                GamepadSlot[] gamepadSlotArr = this.gamepadSlots;
                if (gamepadSlotArr[i4] == null) {
                    gamepadSlotArr[i4] = index < this.connectedControllers.size() ? this.connectedControllers.get(index) : null;
                    index++;
                }
            }
        }
    }

    private boolean isAnyGamepadConnected() {
        for (GamepadSlot gamepadSlot : this.gamepadSlots) {
            if (gamepadSlot != null) {
                return true;
            }
        }
        return false;
    }

    public void handleGetGamepadRequest(final int port) {
        GamepadClient client;
        int xinputClientIndex;
        PreferredInputApi preferredInputApi;
        final boolean isXInput = this.winHandler.receiveData.get() == 1;
        boolean notify = this.winHandler.receiveData.get() == 1;
        int processId = this.winHandler.receiveData.getInt();
        boolean updatedOnce = this.winHandler.receiveData.get() == 1;
        updateGamepadSlots();
        if (!isAnyGamepadConnected() || (((preferredInputApi = this.preferredInputApi) == PreferredInputApi.DINPUT && isXInput) || (preferredInputApi == PreferredInputApi.XINPUT && !isXInput))) {
            notify = false;
        }
        final boolean[] forceDisable = !isXInput ? new boolean[4] : null;
        int clientIndex = findGamepadClientIndex(Integer.valueOf(port), null, null);
        if (notify) {
            if (clientIndex == -1) {
                List<GamepadClient> list = this.gamepadClients;
                GamepadClient gamepadClient = new GamepadClient(port, processId, isXInput);
                client = gamepadClient;
                list.add(gamepadClient);
            } else {
                client = this.gamepadClients.get(clientIndex);
            }
            client.updatedOnce = updatedOnce;
            for (byte i = 0; i < 4; i = (byte) (i + 1)) {
                client.enabledSlots[i] = this.winHandler.receiveData.get() == 1;
            }
            if (!isXInput && this.preferredInputApi == PreferredInputApi.AUTO && (xinputClientIndex = findGamepadClientIndex(null, Integer.valueOf(processId), true)) != -1) {
                GamepadClient xinputClient = this.gamepadClients.get(xinputClientIndex);
                if (xinputClient.updatedOnce) {
                    for (byte i2 = 0; i2 < 4; i2 = (byte) (i2 + 1)) {
                        if (xinputClient.enabledSlots[i2]) {
                            client.enabledSlots[i2] = false;
                            forceDisable[i2] = true;
                        }
                    }
                }
            }
        } else if (clientIndex != -1) {
            this.gamepadClients.remove(clientIndex);
        }
        this.winHandler.addAction(new Runnable() { // from class: com.winlator.winhandler.GamepadHandler$$ExternalSyntheticLambda1
            @Override // java.lang.Runnable
            public final void run() {
                this.f$0.lambda$handleGetGamepadRequest$0(isXInput, port, forceDisable);
            }
        });
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$handleGetGamepadRequest$0(boolean isXInput, int port, boolean[] forceDisable) {
        if (isXInput) {
            this.winHandler.sendData.rewind();
            this.winHandler.sendData.put((byte) 8);
            for (byte i = 0; i < 4; i = (byte) (i + 1)) {
                int i2 = 1;
                this.winHandler.sendData.put((byte) (this.gamepadSlots[i] != null ? 1 : 0));
                ByteBuffer byteBuffer = this.winHandler.sendData;
                GamepadPlayerConfig[] gamepadPlayerConfigArr = this.gamepadPlayerConfigs;
                if (gamepadPlayerConfigArr == null || !gamepadPlayerConfigArr[i].vibration) {
                    i2 = 0;
                }
                byteBuffer.put((byte) i2);
            }
            this.winHandler.sendPacket(port, 16);
            return;
        }
        this.winHandler.sendData.rewind();
        this.winHandler.sendData.put((byte) 8);
        this.winHandler.sendData.put(this.dinputMapperType);
        for (byte i3 = 0; i3 < 4; i3 = (byte) (i3 + 1)) {
            GamepadSlot[] gamepadSlotArr = this.gamepadSlots;
            if (gamepadSlotArr[i3] != null && !forceDisable[i3]) {
                String name = gamepadSlotArr[i3].getName();
                byte[] bytes = name.getBytes();
                byte nameLength = (byte) Math.min((int) ((byte) bytes.length), 31);
                this.winHandler.sendData.put(nameLength);
                this.winHandler.sendData.put(bytes, 0, nameLength);
            } else {
                this.winHandler.sendData.put((byte) 0);
            }
        }
        this.winHandler.sendPacket(port, 128);
    }

    public void sendGamepadState(GamepadSlot gamepadSlot) {
        final byte slot;
        if (!this.winHandler.initReceived || this.gamepadClients.isEmpty() || (slot = (byte) ArrayUtils.indexOf(this.gamepadSlots, gamepadSlot)) == -1) {
            return;
        }
        final GamepadState state = gamepadSlot.getGamepadState();
        for (final GamepadClient client : this.gamepadClients) {
            if (client.enabledSlots[slot]) {
                this.winHandler.addAction(new Runnable() { // from class: com.winlator.winhandler.GamepadHandler$$ExternalSyntheticLambda0
                    @Override // java.lang.Runnable
                    public final void run() {
                        this.f$0.lambda$sendGamepadState$1(client, slot, state);
                    }
                });
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda$sendGamepadState$1(GamepadClient client, byte slot, GamepadState state) {
        int packetLength = client.isXInput ? 16 : 128;
        this.winHandler.sendData.rewind();
        this.winHandler.sendData.put((byte) 9);
        this.winHandler.sendData.put(slot);
        state.writeTo(this.winHandler.sendData);
        this.winHandler.sendPacket(client.port, packetLength);
    }

    public void handleReleaseGamepadRequest(int port) {
        int index = findGamepadClientIndex(Integer.valueOf(port), null, null);
        if (index != -1) {
            this.gamepadClients.remove(index);
        }
    }

    public void handleSetGamepadStateRequest(int port) {
        byte slot = this.winHandler.receiveData.get();
        if (slot < 0 || slot >= 4) {
            return;
        }
        int leftMotorSpeed = this.winHandler.receiveData.getInt();
        int rightMotorSpeed = this.winHandler.receiveData.getInt();
        GamepadSlot gamepadSlot = this.gamepadSlots[slot];
        if (gamepadSlot == null) {
            return;
        }
        GamepadVibration vibration = gamepadSlot.getGamepadVibration();
        vibration.vibrate(leftMotorSpeed, rightMotorSpeed);
    }

    private int findGamepadClientIndex(Integer port, Integer processId, Boolean isXInput) {
        for (int i = 0; i < this.gamepadClients.size(); i++) {
            GamepadClient client = this.gamepadClients.get(i);
            if ((port == null || client.port == port.intValue()) && ((isXInput == null || client.isXInput == isXInput.booleanValue()) && (processId == null || client.processId == processId.intValue()))) {
                return i;
            }
        }
        return -1;
    }

    private ExternalController getConnectedControllerById(int deviceId) {
        synchronized (this.connectedControllers) {
            for (ExternalController controller : this.connectedControllers) {
                if (controller.getDeviceId() == deviceId) {
                    return controller;
                }
            }
            return null;
        }
    }

    protected boolean onGenericMotionEvent(MotionEvent event) {
        boolean handled = false;
        ExternalController controller = getConnectedControllerById(event.getDeviceId());
        if (controller != null && (handled = controller.updateStateFromMotionEvent(event))) {
            sendGamepadState(controller);
        }
        return handled;
    }

    protected boolean onKeyEvent(KeyEvent event) {
        boolean handled = false;
        ExternalController controller = getConnectedControllerById(event.getDeviceId());
        if (controller != null && event.getRepeatCount() == 0) {
            int action = event.getAction();
            if (action == 0 || action == 1) {
                handled = controller.updateStateFromKeyEvent(event);
            }
            if (handled) {
                sendGamepadState(controller);
            }
        }
        return handled;
    }

    public void setDInputMapperType(byte dinputMapperType) {
        this.dinputMapperType = dinputMapperType;
    }

    public void setPreferredInputApi(PreferredInputApi preferredInputApi) {
        this.preferredInputApi = preferredInputApi;
    }
}
