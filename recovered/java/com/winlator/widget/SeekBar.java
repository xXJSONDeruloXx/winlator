package com.winlator.widget;

import android.content.Context;
import android.content.res.TypedArray;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.LinearGradient;
import android.graphics.Paint;
import android.graphics.RectF;
import android.graphics.Shader;
import android.os.Bundle;
import android.os.Parcelable;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.widget.ImageView;
import androidx.appcompat.widget.AppCompatImageView;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.StringUtils;
import com.winlator.core.UnitUtils;
import com.winlator.math.Mathf;
import java.text.DecimalFormat;

/* JADX INFO: loaded from: classes.dex */
public class SeekBar extends AppCompatImageView {
    private final float barHeight;
    private final int colorPrimary;
    private final int colorSecondary;
    private DecimalFormat decimalFormat;
    private LinearGradient glossyEffectGradient;
    private float maxValue;
    private float minValue;
    private float normalizedValue;
    private OnValueChangeListener onValueChangeListener;
    private float padding;
    private final Paint paint;
    private final RectF rect;
    private float step;
    private String suffix;
    private final int textColor;
    private float textSize;
    private final float thumbRadius;
    private final float thumbSize;

    public interface OnValueChangeListener {
        void onValueChangeListener(SeekBar seekBar, float f);
    }

    public SeekBar(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public SeekBar(Context context, AttributeSet attrs, int defStyle) {
        super(context, attrs, defStyle);
        this.paint = new Paint(1);
        this.minValue = 0.0f;
        this.maxValue = 100.0f;
        this.step = 1.0f;
        this.normalizedValue = 0.0f;
        this.textSize = UnitUtils.dpToPx(16.0f);
        this.textColor = -9211021;
        this.barHeight = UnitUtils.dpToPx(6.0f);
        float fDpToPx = UnitUtils.dpToPx(20.0f);
        this.thumbSize = fDpToPx;
        this.rect = new RectF();
        this.colorPrimary = -2631721;
        this.colorSecondary = AppUtils.getThemeColor(context, R.attr.colorAccent);
        if (attrs != null) {
            TypedArray ta = context.obtainStyledAttributes(attrs, R.styleable.SeekBar, 0, 0);
            this.minValue = ta.getFloat(1, this.minValue);
            this.maxValue = ta.getFloat(0, this.maxValue);
            this.suffix = ta.getString(3);
            this.textSize = ta.getDimension(4, this.textSize);
            setStep(ta.getFloat(2, this.step));
            setValue(ta.getFloat(5, 0.0f));
            ta.recycle();
        }
        this.thumbRadius = fDpToPx / 2.0f;
        setFocusable(true);
        setFocusableInTouchMode(true);
    }

    public String getSuffix() {
        return this.suffix;
    }

    public synchronized void setSuffix(String suffix) {
        this.suffix = suffix;
    }

    public OnValueChangeListener getOnValueChangeListener() {
        return this.onValueChangeListener;
    }

    public void setOnValueChangeListener(OnValueChangeListener onValueChangeListener) {
        this.onValueChangeListener = onValueChangeListener;
    }

    public float getValue() {
        float f = this.minValue;
        return f + (this.normalizedValue * (this.maxValue - f));
    }

    public synchronized void setValue(float value) {
        float fRoundTo = Mathf.roundTo(value, this.step);
        float f = this.minValue;
        this.normalizedValue = Mathf.clamp((fRoundTo - f) / (this.maxValue - f), 0.0f, 1.0f);
        postInvalidate();
    }

    public float getStep() {
        return this.step;
    }

    public synchronized void setStep(float step) {
        this.step = step;
        String[] parts = String.valueOf(Mathf.fract(step)).split("\\.");
        int decimalPlaces = parts[parts.length - 1].length();
        StringBuilder sb = new StringBuilder();
        sb.append("0.");
        sb.append(StringUtils.repeat(decimalPlaces > 1 ? '0' : '#', decimalPlaces));
        String format = sb.toString();
        this.decimalFormat = new DecimalFormat(format);
    }

    public float getMinValue() {
        return this.minValue;
    }

    public synchronized void setMinValue(float minValue) {
        this.minValue = minValue;
    }

    public float getMaxValue() {
        return this.maxValue;
    }

    public synchronized void setMaxValue(float maxValue) {
        this.maxValue = maxValue;
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    @Override // android.view.View
    public boolean onTouchEvent(MotionEvent event) {
        if (!isEnabled()) {
            return false;
        }
        switch (event.getAction()) {
            case 0:
                setPressed(isInThumbRange(event.getX()));
                if (!isPressed()) {
                    return super.onTouchEvent(event);
                }
                setNormalizedValue(event.getX());
                if (getParent() != null) {
                    getParent().requestDisallowInterceptTouchEvent(true);
                }
                invalidate();
                return true;
            case 1:
                if (isPressed()) {
                    setNormalizedValue(event.getX());
                    setPressed(false);
                }
                invalidate();
                OnValueChangeListener onValueChangeListener = this.onValueChangeListener;
                if (onValueChangeListener != null) {
                    onValueChangeListener.onValueChangeListener(this, getValue());
                }
                return true;
            case 2:
                if (isPressed()) {
                    setNormalizedValue(event.getX());
                    invalidate();
                }
                return true;
            case 3:
                if (isPressed()) {
                    setPressed(false);
                }
                invalidate();
                return true;
            default:
                return true;
        }
    }

    @Override // android.widget.ImageView, android.view.View
    protected synchronized void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
        int margin = (int) UnitUtils.dpToPx(2.0f);
        int width = (int) UnitUtils.dpToPx(220.0f);
        int height = (int) (this.thumbSize + margin);
        setMeasuredDimension(ImageView.resolveSizeAndState(width + margin, widthMeasureSpec, 0), ImageView.resolveSizeAndState(height, heightMeasureSpec, 0));
    }

    @Override // android.widget.ImageView, android.view.View
    protected synchronized void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        int width = getWidth();
        int height = getHeight();
        if (width != 0 && height != 0) {
            float centerY = height * 0.5f;
            this.paint.setTextSize(this.textSize);
            this.paint.setStyle(Paint.Style.FILL);
            this.paint.setColor(-9211021);
            this.paint.setAntiAlias(true);
            StringBuilder sb = new StringBuilder();
            sb.append(this.decimalFormat.format(getValue()));
            String str = this.suffix;
            if (str == null) {
                str = "";
            }
            sb.append(str);
            String text = sb.toString();
            int i = 4 + ((Mathf.fract(this.step) > 0.0f || this.minValue < 0.0f) ? 1 : 0);
            String str2 = this.suffix;
            int repeatCount = i + (str2 != null ? str2.length() : 0);
            float textWidth = this.paint.measureText(StringUtils.repeat('0', repeatCount));
            canvas.drawText(text, width - this.paint.measureText(text), (this.textSize / 3.0f) + centerY, this.paint);
            this.padding = this.thumbSize + textWidth;
            float screenCoord = getScreenCoord();
            RectF rectF = this.rect;
            float f = this.barHeight;
            rectF.set(0.0f, centerY - (f * 0.5f), width - textWidth, (f * 0.5f) + centerY);
            this.paint.setColor(-2631721);
            float cornerRadius = this.rect.height() * 0.5f;
            canvas.drawRoundRect(this.rect, cornerRadius, cornerRadius, this.paint);
            this.paint.setShader(null);
            this.rect.right = screenCoord;
            this.paint.setColor(this.colorSecondary);
            canvas.drawRoundRect(this.rect, cornerRadius, cornerRadius, this.paint);
            this.rect.right = width - textWidth;
            if (this.glossyEffectGradient == null) {
                this.glossyEffectGradient = new LinearGradient(0.0f, 0.0f, 0.0f, height, new int[]{872415231, 0}, new float[]{0.5f, 0.5f}, Shader.TileMode.CLAMP);
            }
            this.paint.setShader(this.glossyEffectGradient);
            canvas.drawRoundRect(this.rect, cornerRadius, cornerRadius, this.paint);
            this.paint.setShader(null);
            canvas.drawCircle(screenCoord, centerY, this.thumbRadius, this.paint);
            this.paint.setColor(getThumbHoleColor());
            canvas.drawCircle(screenCoord, centerY, this.thumbRadius * 0.5f, this.paint);
        }
    }

    private int getThumbHoleColor() {
        int r = Mathf.clamp(Color.red(this.colorSecondary) - 30, 0, 255);
        int g = Mathf.clamp(Color.green(this.colorSecondary) - 30, 0, 255);
        int b = Mathf.clamp(Color.blue(this.colorSecondary) - 30, 0, 255);
        return Color.rgb(r, g, b);
    }

    @Override // android.view.View
    protected Parcelable onSaveInstanceState() {
        Bundle bundle = new Bundle();
        bundle.putParcelable("SUPER", super.onSaveInstanceState());
        bundle.putFloat("normalizedValue", this.normalizedValue);
        return bundle;
    }

    @Override // android.view.View
    protected void onRestoreInstanceState(Parcelable parcel) {
        Bundle bundle = (Bundle) parcel;
        super.onRestoreInstanceState(bundle.getParcelable("SUPER"));
        this.normalizedValue = bundle.getFloat("normalizedValue");
    }

    private boolean isInThumbRange(float touchX) {
        return Math.abs(touchX - getScreenCoord()) <= this.thumbRadius;
    }

    private float getScreenCoord() {
        return this.thumbRadius + (this.normalizedValue * (getWidth() - this.padding));
    }

    private void setNormalizedValue(float touchX) {
        int width = getWidth();
        float f = this.padding;
        if (width - f <= 0.0f) {
            return;
        }
        float normalizedStep = this.step / (this.maxValue - this.minValue);
        this.normalizedValue = Mathf.clamp(Mathf.roundTo((touchX - this.thumbRadius) / (width - f), normalizedStep), 0.0f, 1.0f);
    }
}
