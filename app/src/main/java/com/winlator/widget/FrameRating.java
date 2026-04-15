package com.winlator.widget;

import android.app.ActivityManager;
import android.content.Context;
import android.os.SystemClock;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.LinearLayout;
import android.widget.TextView;
import com.winlator.R;
import com.winlator.box64.Box64Utils;
import com.winlator.core.CPUStatus;
import com.winlator.core.StringUtils;
import java.util.Locale;

/* JADX INFO: loaded from: classes.dex */
public class FrameRating extends FrameLayout implements Runnable {
    private ActivityManager activityManager;
    private String cpuInfo;
    private final LinearLayout cpuPanel;
    private final LinearLayout fpsPanel;
    private short frameCount;
    private final LinearLayout gpuPanel;
    private float lastFPS;
    private long lastTime;
    private ActivityManager.MemoryInfo memoryInfo;
    private Mode mode;
    private final LinearLayout ramPanel;
    private byte tick;

    public enum Mode {
        DISABLED,
        SIMPLE,
        FULL
    }

    public FrameRating(Context context) {
        this(context, null);
    }

    public FrameRating(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public FrameRating(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        this.lastTime = 0L;
        this.frameCount = (short) 0;
        this.lastFPS = 0.0f;
        this.mode = Mode.SIMPLE;
        this.cpuInfo = null;
        this.tick = (byte) 0;
        View view = LayoutInflater.from(context).inflate(R.layout.frame_rating, (ViewGroup) this, false);
        this.fpsPanel = (LinearLayout) view.findViewById(R.id.LLFPSPanel);
        this.gpuPanel = (LinearLayout) view.findViewById(R.id.LLGPUPanel);
        this.ramPanel = (LinearLayout) view.findViewById(R.id.LLRAMPanel);
        this.cpuPanel = (LinearLayout) view.findViewById(R.id.LLCPUPanel);
        addView(view);
        setupPanels();
    }

    /* JADX INFO: renamed from: com.winlator.widget.FrameRating$1, reason: invalid class name */
    static /* synthetic */ class AnonymousClass1 {
        static final /* synthetic */ int[] $SwitchMap$com$winlator$widget$FrameRating$Mode;

        static {
            int[] iArr = new int[Mode.values().length];
            $SwitchMap$com$winlator$widget$FrameRating$Mode = iArr;
            try {
                iArr[Mode.DISABLED.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                $SwitchMap$com$winlator$widget$FrameRating$Mode[Mode.SIMPLE.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            try {
                $SwitchMap$com$winlator$widget$FrameRating$Mode[Mode.FULL.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
        }
    }

    private void setupPanels() {
        switch (AnonymousClass1.$SwitchMap$com$winlator$widget$FrameRating$Mode[this.mode.ordinal()]) {
            case 1:
                this.fpsPanel.setVisibility(8);
                this.gpuPanel.setVisibility(8);
                this.ramPanel.setVisibility(8);
                this.cpuPanel.setVisibility(8);
                this.activityManager = null;
                this.memoryInfo = null;
                break;
            case 2:
                this.fpsPanel.setVisibility(0);
                this.gpuPanel.setVisibility(8);
                this.ramPanel.setVisibility(8);
                this.cpuPanel.setVisibility(8);
                this.activityManager = null;
                this.memoryInfo = null;
                break;
            case 3:
                this.fpsPanel.setVisibility(0);
                this.gpuPanel.setVisibility(0);
                this.ramPanel.setVisibility(0);
                this.cpuPanel.setVisibility(0);
                Context context = getContext();
                this.activityManager = (ActivityManager) context.getSystemService("activity");
                this.memoryInfo = new ActivityManager.MemoryInfo();
                break;
        }
    }

    public Mode getMode() {
        return this.mode;
    }

    public void setMode(Mode mode) {
        this.mode = mode;
        setupPanels();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_setGPUInfo_0(String gpuInfo) {
        ((TextView) this.gpuPanel.getChildAt(1)).setText(gpuInfo);
    }

    public void setGPUInfo(final String gpuInfo) {
        post(() -> lambda_setGPUInfo_0(gpuInfo));
    }

    public void reset() {
        this.frameCount = (short) 0;
        this.lastTime = SystemClock.elapsedRealtime();
        this.lastFPS = 0.0f;
        this.tick = (byte) 2;
    }

    public void update() {
        long time = SystemClock.elapsedRealtime();
        if (time >= 500 + this.lastTime) {
            this.lastFPS = (this.frameCount * 1000) / (time - this.lastTime);
            post(this);
            this.lastTime = time;
            this.frameCount = (short) 0;
        }
        this.frameCount = (short) (this.frameCount + 1);
    }

    @Override // java.lang.Runnable
    public void run() {
        if (getVisibility() == 8) {
            setVisibility(0);
        }
        ((TextView) this.fpsPanel.getChildAt(1)).setText(String.format(Locale.ENGLISH, "%.1f", Float.valueOf(this.lastFPS)));
        if (this.mode == Mode.FULL) {
            byte b = (byte) (this.tick + 1);
            this.tick = b;
            if (b >= 2) {
                this.tick = (byte) 0;
                this.activityManager.getMemoryInfo(this.memoryInfo);
                ActivityManager.MemoryInfo memoryInfo = this.memoryInfo;
                long usedMem = memoryInfo.totalMem - memoryInfo.availMem;
                String ramText = StringUtils.formatBytes(usedMem, false) + "/" + StringUtils.formatBytes(this.memoryInfo.totalMem);
                ((TextView) this.ramPanel.getChildAt(1)).setText(ramText);
                if (this.cpuInfo == null) {
                    this.cpuInfo = "Box64 v" + Box64Utils.extractBinVersion(this.cpuPanel.getContext());
                }
                short[] clockSpeeds = CPUStatus.getCurrentClockSpeeds();
                int maxClockSpeed = 0;
                for (short clockSpeed : clockSpeeds) {
                    maxClockSpeed = Math.max(maxClockSpeed, (int) clockSpeed);
                }
                ((TextView) this.cpuPanel.getChildAt(1)).setText(CPUStatus.formatClockSpeed(maxClockSpeed) + " | " + this.cpuInfo);
            }
        }
    }
}
