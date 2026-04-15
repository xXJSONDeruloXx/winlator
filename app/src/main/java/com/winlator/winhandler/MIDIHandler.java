package com.winlator.winhandler;

import android.media.midi.MidiDevice;
import android.media.midi.MidiDeviceInfo;
import android.media.midi.MidiManager;
import android.media.midi.MidiOutputPort;
import android.media.midi.MidiReceiver;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.net.SocketTimeoutException;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.Iterator;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/* JADX INFO: loaded from: classes.dex */
public class MIDIHandler {
    private ExecutorService executorService;
    private final List<Integer> midiInClients;
    private long nativePtr;
    private boolean opened;
    private MidiOutputPort outputPort;
    private final MidiReceiver outputPortReceiver;
    private final ByteBuffer receiveData;
    private final DatagramPacket receivePacket;
    private DatagramSocket socket;
    private final WinHandler winHandler;

    private native void controlChange(long j, int i, int i2, int i3);

    private native void destroy(long j);

    private native void keyPressure(long j, int i, int i2, int i3);

    private native void loadSoundFont(long j, String str);

    private native long nativeAllocate();

    private native void noteOff(long j, int i, int i2);

    private native void noteOn(long j, int i, int i2, int i3);

    private native void pitchBend(long j, int i, int i2);

    private native void programChange(long j, int i, int i2);

    public MIDIHandler(WinHandler winHandler) {
        ByteBuffer byteBufferOrder = ByteBuffer.allocate(16).order(ByteOrder.LITTLE_ENDIAN);
        this.receiveData = byteBufferOrder;
        this.receivePacket = new DatagramPacket(byteBufferOrder.array(), 16);
        this.opened = false;
        this.midiInClients = new CopyOnWriteArrayList();
        this.outputPortReceiver = new MidiReceiver() { // from class: com.winlator.winhandler.MIDIHandler.1
            @Override // android.media.midi.MidiReceiver
            public void onSend(byte[] data, int offset, int count, long timestamp) throws IOException {
                for (int i = offset; i < count; i += 3) {
                    MIDIHandler.this.sendShortMsg(data[i + 0], (byte) 0, data[i + 1], data[i + 2]);
                }
            }
        };
        this.winHandler = winHandler;
    }

    static {
        System.loadLibrary("midihandler");
    }

    public void outputPortConnect() {
        String selectedDevice = this.winHandler.activity.getPreferences().getString("midi_input_device", "auto");
        if (selectedDevice.equals("none")) {
            return;
        }
        MidiManager mm = (MidiManager) this.winHandler.activity.getSystemService("midi");
        MidiDeviceInfo[] infos = mm.getDevices();
        for (MidiDeviceInfo info : infos) {
            if (info.getOutputPortCount() > 0) {
                Bundle properties = info.getProperties();
                if (selectedDevice.equals("auto") || selectedDevice.equalsIgnoreCase(properties.getString("name"))) {
                    mm.openDevice(info, midiDevice -> lambda_outputPortConnect_0(midiDevice), new Handler(Looper.getMainLooper()));
                    return;
                }
            }
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_outputPortConnect_0(MidiDevice device) {
        synchronized (this.outputPortReceiver) {
            if (device != null) {
                if (this.outputPort == null) {
                    MidiOutputPort midiOutputPortOpenOutputPort = device.openOutputPort(0);
                    this.outputPort = midiOutputPortOpenOutputPort;
                    midiOutputPortOpenOutputPort.connect(this.outputPortReceiver);
                }
            }
        }
    }

    public void outputPortDisconnect() {
        synchronized (this.outputPortReceiver) {
            MidiOutputPort midiOutputPort = this.outputPort;
            if (midiOutputPort != null) {
                midiOutputPort.disconnect(this.outputPortReceiver);
                this.outputPort = null;
            }
        }
    }

    public boolean init() {
        if (this.nativePtr != 0) {
            return true;
        }
        long nativePtr = nativeAllocate();
        if (nativePtr != 0) {
            this.nativePtr = nativePtr;
            return true;
        }
        return false;
    }

    public void addClient(int port) {
        if (!this.midiInClients.contains(Integer.valueOf(port))) {
            this.midiInClients.add(Integer.valueOf(port));
        }
    }

    /* JADX WARN: Failed to analyze thrown exceptions
    java.util.ConcurrentModificationException
    	at java.base/java.util.ArrayList$Itr.checkForComodification(Unknown Source)
    	at java.base/java.util.ArrayList$Itr.next(Unknown Source)
    	at jadx.core.dex.visitors.MethodThrowsVisitor.processInstructions(MethodThrowsVisitor.java:130)
    	at jadx.core.dex.visitors.MethodThrowsVisitor.visit(MethodThrowsVisitor.java:68)
    	at jadx.core.dex.visitors.MethodThrowsVisitor.checkInsn(MethodThrowsVisitor.java:178)
    	at jadx.core.dex.visitors.MethodThrowsVisitor.processInstructions(MethodThrowsVisitor.java:131)
    	at jadx.core.dex.visitors.MethodThrowsVisitor.visit(MethodThrowsVisitor.java:68)
     */
    public boolean sendShortMsg(byte command, byte channel, byte param1, byte param2) {
        if (!this.winHandler.initReceived || this.midiInClients.isEmpty()) {
            return false;
        }
        final ByteBuffer sendData = ByteBuffer.allocate(8).order(ByteOrder.LITTLE_ENDIAN);
        sendData.putInt(0, (byte) (command | channel));
        sendData.put(1, param1);
        sendData.put(2, param2);
        Iterator<Integer> it = this.midiInClients.iterator();
        while (it.hasNext()) {
            final int port = it.next().intValue();
            this.winHandler.addAction(() -> lambda_sendShortMsg_1(port, sendData));
        }
        return true;
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_sendShortMsg_1(int port, ByteBuffer sendData) {
        this.winHandler.sendPacket(port, sendData.array());
    }

    public void open(final Runnable callback) {
        close();
        this.opened = true;
        ExecutorService executorServiceNewSingleThreadExecutor = Executors.newSingleThreadExecutor();
        this.executorService = executorServiceNewSingleThreadExecutor;
        executorServiceNewSingleThreadExecutor.execute(() -> lambda_open_2(callback));
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_open_2(Runnable callback) {
        try {
            DatagramSocket datagramSocket = new DatagramSocket((SocketAddress) null);
            this.socket = datagramSocket;
            datagramSocket.setReuseAddress(true);
            this.socket.setSoTimeout(1000);
            this.socket.bind(new InetSocketAddress((InetAddress) null, 7950));
            if (callback != null) {
                callback.run();
            }
            while (this.opened) {
                try {
                    this.socket.receive(this.receivePacket);
                    this.receiveData.rewind();
                    if (this.receiveData.get() == 1) {
                    }
                    processData(this.receiveData.get(), this.receiveData.get(), this.receiveData.get());
                } catch (SocketTimeoutException e) {
                }
            }
        } catch (IOException e2) {
        }
    }

    public void close() {
        this.midiInClients.clear();
        if (this.opened) {
            this.opened = false;
            ExecutorService executorService = this.executorService;
            if (executorService != null) {
                try {
                    executorService.awaitTermination(2L, TimeUnit.SECONDS);
                } catch (InterruptedException e) {
                }
                this.executorService = null;
            }
            DatagramSocket datagramSocket = this.socket;
            if (datagramSocket != null) {
                datagramSocket.close();
                this.socket = null;
            }
        }
    }

    private void processData(byte status, byte param1, byte param2) {
        int command = status & 240;
        int channel = status & 15;
        switch (command) {
            case 128:
                noteOff(this.nativePtr, channel, param1);
                break;
            case 144:
                noteOn(this.nativePtr, channel, param1, param2);
                break;
            case 160:
                keyPressure(this.nativePtr, channel, param1, param2);
                break;
            case 176:
                controlChange(this.nativePtr, channel, param1, param2);
                break;
            case 192:
                programChange(this.nativePtr, channel, param1);
                break;
            case 224:
                pitchBend(this.nativePtr, channel, (param2 << 7) + param1);
                break;
        }
    }

    public void noteOn(int channel, int note, int velocity) {
        noteOn(this.nativePtr, channel, note, velocity);
    }

    public void noteOff(int channel, int note) {
        noteOff(this.nativePtr, channel, note);
    }

    public void loadSoundFont(String soundfontPath) {
        loadSoundFont(this.nativePtr, soundfontPath);
    }

    public void programChange(int channel, int program) {
        programChange(this.nativePtr, channel, program);
    }

    public void destroy() {
        long j = this.nativePtr;
        if (j != 0) {
            destroy(j);
            this.nativePtr = 0L;
        }
    }

    public static String[] getInstrumentNames() {
        return new String[]{"Acoustic Piano", "Bright Acoustic Piano", "Electric Grand Piano", "Honky-tonk Piano", "Electric Piano 1", "Electric Piano 2", "Harpsichord", "Clavi", "Celesta", "Glockenspiel", "Music Box", "Vibraphone", "Marimba", "Xylophone", "Tubular Bells", "Dulcimer", "Drawbar Organ", "Percussive Organ", "Rock Organ", "Church Organ", "Reed Organ", "Accordion", "Harmonica", "Tango Accordion", "Acoustic Guitar (nylon)", "Acoustic Guitar (steel)", "Electric Guitar (jazz)", "Electric Guitar (clean)", "Electric Guitar (muted)", "Overdriven Guitar", "Distortion Guitar", "Guitar harmonics", "Acoustic Bass", "Electric Bass (finger)", "Electric Bass (pick)", "Fretless Bass", "Slap Bass 1", "Slap Bass 2", "Synth Bass 1", "Synth Bass 2", "Violin", "Viola", "Cello", "Contrabass", "Tremolo Strings", "Pizzicato Strings", "Orchestral Harp", "Timpani", "String Ensemble 1", "String Ensemble 2", "SynthStrings 1", "SynthStrings 2", "Choir Aahs", "Voice Oohs", "Synth Voice", "Orchestra Hit", "Trumpet", "Trombone", "Tuba", "Muted Trumpet", "French Horn", "Brass Section", "SynthBrass 1", "SynthBrass 2", "Soprano Sax", "Alto Sax", "Tenor Sax", "Baritone Sax", "Oboe", "English Horn", "Bassoon", "Clarinet", "Piccolo", "Flute", "Recorder", "Pan Flute", "Blown Bottle", "Shakuhachi", "Whistle", "Ocarina", "Lead 1 (square)", "Lead 2 (sawtooth)", "Lead 3 (calliope)", "Lead 4 (chiff)", "Lead 5 (charang)", "Lead 6 (voice)", "Lead 7 (fifths)", "Lead 8 (bass + lead)", "Pad 1 (new age)", "Pad 2 (warm)", "Pad 3 (polysynth)", "Pad 4 (choir)", "Pad 5 (bowed)", "Pad 6 (metallic)", "Pad 7 (halo)", "Pad 8 (sweep)", "FX 1 (rain)", "FX 2 (soundtrack)", "FX 3 (crystal)", "FX 4 (atmosphere)", "FX 5 (brightness)", "FX 6 (goblins)", "FX 7 (echoes)", "FX 8 (sci-fi)", "Sitar", "Banjo", "Shamisen", "Koto", "Kalimba", "Bag pipe", "Fiddle", "Shanai", "Tinkle Bell", "Agogo", "Steel Drums", "Woodblock", "Taiko Drum", "Melodic Tom", "Synth Drum", "Reverse Cymbal", "Guitar Fret Noise", "Breath Noise", "Seashore", "Bird Tweet", "Telephone Ring", "Helicopter", "Applause", "Gunshot"};
    }

    public static String[] getNotes() {
        String[] symbols = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
        String[] notes = new String[symbols.length * 6];
        int index = 0;
        for (byte i = 1; i <= 6; i = (byte) (i + 1)) {
            int length = symbols.length;
            int i2 = 0;
            while (i2 < length) {
                String symbol = symbols[i2];
                notes[index] = symbol + ((int) i);
                i2++;
                index++;
            }
        }
        return notes;
    }

    public static int parseNoteNumber(String note) {
        int offset;
        Pattern pattern = Pattern.compile("^([A-Za-z#]+)([0-9]{1})$");
        Matcher matcher = pattern.matcher(note);
        int octave = 1;
        if (matcher.find()) {
            note = matcher.group(1);
            octave = Integer.parseInt(matcher.group(2));
        }
        offset = (octave - 1) * 12;
        switch (note) {
            case "C":
                return offset + 0;
            case "C#":
            case "Db":
                return offset + 1;
            case "D":
                return offset + 2;
            case "D#":
            case "Eb":
                return offset + 3;
            case "E":
                return offset + 4;
            case "F":
                return offset + 5;
            case "F#":
            case "Gb":
                return offset + 6;
            case "G":
                return offset + 7;
            case "G#":
            case "Ab":
                return offset + 8;
            case "A":
                return offset + 9;
            case "A#":
            case "Bb":
                return offset + 10;
            case "B":
                return offset + 11;
            default:
                return -1;
        }
    }
}
