package com.winlator.widget;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.widget.FrameLayout;
import android.widget.TextView;
import androidx.preference.PreferenceManager;
import com.winlator.R;
import com.winlator.core.Callback;
import com.winlator.core.UnitUtils;
import com.winlator.math.Mathf;

/* JADX INFO: loaded from: classes.dex */
public class MagnifierView extends FrameLayout {
    private Runnable hideButtonCallback;
    private short lastX;
    private short lastY;
    private final SharedPreferences preferences;
    private boolean restoreSavedPosition;
    private TextView textView;
    private Callback<Float> zoomButtonCallback;

    public MagnifierView(Context context) {
        this(context, null);
    }

    public MagnifierView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public MagnifierView(Context context, AttributeSet attrs, int defStyleAttr) {
        this(context, attrs, defStyleAttr, 0);
    }

    public MagnifierView(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        this.restoreSavedPosition = true;
        this.lastX = (short) 0;
        this.lastY = (short) 0;
        this.preferences = PreferenceManager.getDefaultSharedPreferences(context);
        setLayoutParams(new FrameLayout.LayoutParams(-2, -2));
        View contentView = LayoutInflater.from(context).inflate(R.layout.magnifier_view, (ViewGroup) this, false);
        final PointF startPoint = new PointF();
        final boolean[] isActionDown = {false};
        contentView.findViewById(R.id.BTMove).setOnTouchListener((view, motionEvent) -> lambda_new_0(startPoint, isActionDown, view, motionEvent));
        contentView.findViewById(R.id.BTZoomPlus).setOnClickListener(view -> lambda_new_1(view));
        contentView.findViewById(R.id.BTZoomMinus).setOnClickListener(view -> lambda_new_2(view));
        contentView.findViewById(R.id.BTHide).setOnClickListener(view -> lambda_new_3(view));
        this.textView = (TextView) contentView.findViewById(R.id.TextView);
        addView(contentView);
    }

    /* JADX INFO: Access modifiers changed from: private */
    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    public /* synthetic */ boolean lambda_new_0(PointF startPoint, boolean[] isActionDown, View v, MotionEvent event) {
        switch (event.getAction()) {
            case 0:
                startPoint.x = event.getX();
                startPoint.y = event.getY();
                isActionDown[0] = true;
                return true;
            case 1:
                if (isActionDown[0] && this.lastX > 0 && this.lastY > 0) {
                    this.preferences.edit().putString("magnifier_view", ((int) this.lastX) + "|" + ((int) this.lastY)).apply();
                }
                this.lastX = (short) 0;
                this.lastY = (short) 0;
                isActionDown[0] = false;
                return true;
            case 2:
                if (isActionDown[0]) {
                    float newX = getX() + (event.getX() - startPoint.x);
                    float newY = getY() + (event.getY() - startPoint.y);
                    movePanel(newX, newY);
                }
                return true;
            default:
                return true;
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_1(View v) {
        Callback<Float> callback = this.zoomButtonCallback;
        if (callback != null) {
            callback.call(Float.valueOf(0.25f));
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_2(View v) {
        Callback<Float> callback = this.zoomButtonCallback;
        if (callback != null) {
            callback.call(Float.valueOf(-0.25f));
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_new_3(View v) {
        Runnable runnable = this.hideButtonCallback;
        if (runnable != null) {
            runnable.run();
        }
    }

    public void setZoomValue(float value) {
        this.textView.setText(((int) (100.0f * value)) + "%");
    }

    @Override // android.widget.FrameLayout, android.view.ViewGroup, android.view.View
    protected void onLayout(boolean changed, int left, int top, int right, int bottom) {
        super.onLayout(changed, left, top, right, bottom);
        if (this.restoreSavedPosition) {
            float x = 1000000.0f;
            float y = 1000000.0f;
            String config = this.preferences.getString("magnifier_view", null);
            if (config != null) {
                try {
                    String[] parts = config.split("\\|");
                    x = Short.parseShort(parts[0]);
                    y = Short.parseShort(parts[1]);
                } catch (NumberFormatException e) {
                }
            }
            movePanel(x, y);
            this.restoreSavedPosition = false;
        }
    }

    private void movePanel(float x, float y) {
        int padding = (int) UnitUtils.dpToPx(8.0f);
        ViewGroup parent = (ViewGroup) getParent();
        int width = getWidth();
        int height = getHeight();
        int parentWidth = parent.getWidth();
        int parentHeight = parent.getHeight();
        float x2 = Mathf.clamp(x, padding, (parentWidth - padding) - width);
        float y2 = Mathf.clamp(y, padding, (parentHeight - padding) - height);
        setX(x2);
        setY(y2);
        this.lastX = (short) x2;
        this.lastY = (short) y2;
    }

    public Callback<Float> getZoomButtonCallback() {
        return this.zoomButtonCallback;
    }

    public void setZoomButtonCallback(Callback<Float> zoomButtonCallback) {
        this.zoomButtonCallback = zoomButtonCallback;
    }

    public Runnable getHideButtonCallback() {
        return this.hideButtonCallback;
    }

    public void setHideButtonCallback(Runnable hideButtonCallback) {
        this.hideButtonCallback = hideButtonCallback;
    }
}
