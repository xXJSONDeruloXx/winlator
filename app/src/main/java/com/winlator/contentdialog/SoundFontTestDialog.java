package com.winlator.contentdialog;

import android.content.Context;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Spinner;
import android.widget.SpinnerAdapter;
import com.winlator.R;
import com.winlator.core.GeneralComponents;
import com.winlator.widget.SimplePianoKeyboard;
import com.winlator.winhandler.MIDIHandler;

/* JADX INFO: loaded from: classes.dex */
public class SoundFontTestDialog extends ContentDialog {
    public SoundFontTestDialog(Context context, String soundfont) {
        super(context, R.layout.soundfont_test_dialog);
        setIcon(R.drawable.icon_piano);
        setTitle(soundfont);
        String soundfontPath = GeneralComponents.getDefinitivePath(GeneralComponents.Type.SOUNDFONT, context, soundfont);
        final MIDIHandler midiHandler = new MIDIHandler(null);
        midiHandler.init();
        midiHandler.loadSoundFont(soundfontPath);
        final int[] channel = {0};
        final Spinner sInstrument = (Spinner) findViewById(R.id.SInstrument);
        Spinner sChannel = (Spinner) findViewById(R.id.SChannel);
        sChannel.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.contentdialog.SoundFontTestDialog.1
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> adapterView, View view, int position, long id) {
                int[] iArr = channel;
                iArr[0] = position == 1 ? 9 : 0;
                midiHandler.programChange(iArr[0], sInstrument.getSelectedItemPosition());
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> adapterView) {
            }
        });
        sInstrument.setAdapter((SpinnerAdapter) new ArrayAdapter(context, android.R.layout.simple_spinner_dropdown_item, MIDIHandler.getInstrumentNames()));
        sInstrument.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() { // from class: com.winlator.contentdialog.SoundFontTestDialog.2
            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onItemSelected(AdapterView<?> adapterView, View view, int position, long id) {
                midiHandler.programChange(0, position);
            }

            @Override // android.widget.AdapterView.OnItemSelectedListener
            public void onNothingSelected(AdapterView<?> adapterView) {
            }
        });
        SimplePianoKeyboard pianoKeyboard = (SimplePianoKeyboard) findViewById(R.id.SimplePianoKeyboard);
        pianoKeyboard.setOnKeyListener(new SimplePianoKeyboard.OnKeyListener() { // from class: com.winlator.contentdialog.SoundFontTestDialog.3
            @Override // com.winlator.widget.SimplePianoKeyboard.OnKeyListener
            public void onKeyDown(int index) {
                midiHandler.noteOn(channel[0], index + 60, 100);
            }

            @Override // com.winlator.widget.SimplePianoKeyboard.OnKeyListener
            public void onKeyUp(int index) {
                midiHandler.noteOff(channel[0], index + 60);
            }
        });
        findViewById(R.id.LLBottomBar).setVisibility(8);
    }
}
