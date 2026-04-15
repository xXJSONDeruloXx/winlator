package com.winlator.widget;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Path;
import android.util.ArraySet;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;
import com.winlator.core.UnitUtils;
import java.util.Iterator;

/* JADX INFO: loaded from: classes.dex */
public class SimplePianoKeyboard extends View {
    private final float SHARP_KEY_SCALE;
    private int octaves;
    private OnKeyListener onKeyListener;
    private final Paint paint;
    private final Path path;
    private final ArraySet<Byte> pressedKeys;

    public interface OnKeyListener {
        void onKeyDown(int i);

        void onKeyUp(int i);
    }

    public SimplePianoKeyboard(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public SimplePianoKeyboard(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        this.SHARP_KEY_SCALE = 0.6f;
        this.paint = new Paint(1);
        this.path = new Path();
        this.octaves = 1;
        this.pressedKeys = new ArraySet<>();
    }

    public int getOctaves() {
        return this.octaves;
    }

    public void setOctaves(int octaves) {
        this.octaves = octaves;
    }

    public OnKeyListener getOnKeyListener() {
        return this.onKeyListener;
    }

    public void setOnKeyListener(OnKeyListener onKeyListener) {
        this.onKeyListener = onKeyListener;
    }

    @Override // android.view.View
    protected void onDraw(Canvas canvas) {
        boolean sharpKeyPressed;
        int width;
        int i;
        byte index;
        int j;
        int i2;
        super.onDraw(canvas);
        int width2 = getWidth();
        int height = getHeight();
        if (width2 != 0 && height != 0) {
            float strokeWidth = UnitUtils.dpToPx(2.0f);
            int i3 = 7;
            float keyWidth = width2 / (this.octaves * 7);
            float sharpKeyWidth = keyWidth * 0.6f;
            float sharpKeyBottom = height * 0.6f;
            this.paint.setStrokeWidth(strokeWidth);
            float radius = UnitUtils.dpToPx(6.0f);
            int i4 = 3;
            float[] bottomRadius = {0.0f, 0.0f, 0.0f, 0.0f, radius, radius, radius, radius};
            float offsetX = strokeWidth * 0.5f;
            float startY = strokeWidth * 0.5f;
            float endY = height - (strokeWidth * 0.5f);
            byte index2 = 0;
            int i5 = 0;
            while (i5 < this.octaves) {
                float offsetX2 = offsetX;
                int j2 = 0;
                while (j2 < i3) {
                    if (j2 != i4 && j2 != 0) {
                        boolean sharpKeyPressed2 = this.pressedKeys.contains(Byte.valueOf(index2));
                        index2 = (byte) (index2 + 1);
                        sharpKeyPressed = sharpKeyPressed2;
                    } else {
                        sharpKeyPressed = false;
                    }
                    this.path.reset();
                    this.path.addRoundRect(offsetX2, startY, offsetX2 + keyWidth, endY, bottomRadius, Path.Direction.CW);
                    this.paint.setStyle(Paint.Style.FILL);
                    this.paint.setColor(this.pressedKeys.contains(Byte.valueOf(index2)) ? -4144960 : -1);
                    canvas.drawPath(this.path, this.paint);
                    this.paint.setStyle(Paint.Style.STROKE);
                    this.paint.setColor(-16777216);
                    canvas.drawPath(this.path, this.paint);
                    byte index3 = (byte) (index2 + 1);
                    if (j2 == 3 || j2 == 0) {
                        width = width2;
                        i = 3;
                        index = index3;
                        j = j2;
                        i2 = i5;
                    } else {
                        this.path.reset();
                        i = 3;
                        index = index3;
                        j = j2;
                        i2 = i5;
                        width = width2;
                        this.path.addRoundRect(offsetX2 - (sharpKeyWidth * 0.5f), startY, offsetX2 + (sharpKeyWidth * 0.5f), sharpKeyBottom, bottomRadius, Path.Direction.CW);
                        this.paint.setStyle(Paint.Style.FILL);
                        this.paint.setColor(sharpKeyPressed ? -10461088 : -16777216);
                        canvas.drawPath(this.path, this.paint);
                        if (sharpKeyPressed) {
                            this.paint.setStyle(Paint.Style.STROKE);
                            this.paint.setColor(-16777216);
                            canvas.drawPath(this.path, this.paint);
                        }
                    }
                    offsetX2 += keyWidth - (strokeWidth * 0.5f);
                    j2 = j + 1;
                    i5 = i2;
                    i4 = i;
                    index2 = index;
                    width2 = width;
                    i3 = 7;
                }
                i5++;
                offsetX = offsetX2;
                i3 = 7;
            }
        }
    }

    private byte keyIndexFromTouchPoint(float touchX, float touchY) {
        int width = getWidth();
        int height = getHeight();
        float keyWidth = width / (this.octaves * 7);
        float sharpKeyWidth = keyWidth * 0.6f;
        float sharpKeyBottom = height * 0.6f;
        float offsetX = 0.0f;
        byte index = 0;
        for (int i = 0; i < this.octaves; i++) {
            for (int j = 0; j < 7; j++) {
                if (j != 3 && j != 0) {
                    if (touchX >= offsetX - (sharpKeyWidth * 0.5f) && touchX <= (0.5f * sharpKeyWidth) + offsetX && touchY <= sharpKeyBottom) {
                        return index;
                    }
                    index = (byte) (index + 1);
                }
                if (touchX >= offsetX && touchX <= offsetX + keyWidth) {
                    return index;
                }
                index = (byte) (index + 1);
                offsetX += keyWidth;
            }
        }
        return (byte) -1;
    }

    @Override // android.view.View
    public boolean onTouchEvent(MotionEvent event) {
        int action = event.getAction();
        if (action == 0) {
            byte index = keyIndexFromTouchPoint(event.getX(), event.getY());
            if (index != -1) {
                OnKeyListener onKeyListener = this.onKeyListener;
                if (onKeyListener != null) {
                    onKeyListener.onKeyDown(index);
                }
                this.pressedKeys.add(Byte.valueOf(index));
                postInvalidate();
                return true;
            }
        } else if (action == 1) {
            if (this.onKeyListener != null) {
                Iterator<Byte> it = this.pressedKeys.iterator();
                while (it.hasNext()) {
                    this.onKeyListener.onKeyUp(it.next().byteValue());
                }
            }
            this.pressedKeys.clear();
            postInvalidate();
            return true;
        }
        return super.onTouchEvent(event);
    }
}
