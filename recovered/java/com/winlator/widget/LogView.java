package com.winlator.widget;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.PointF;
import android.os.Environment;
import android.text.format.DateFormat;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.View;
import androidx.preference.PreferenceManager;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.FileUtils;
import com.winlator.core.UnitUtils;
import com.winlator.math.Mathf;
import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;

/* JADX INFO: loaded from: classes.dex */
public class LogView extends View {
    private final float defaultTextSize;
    private boolean isActionDown;
    private final PointF lastPoint;
    private final ArrayList<String> lines;
    private final Object lock;
    private final float minScrollThumbSize;
    private final Paint paint;
    private final PrintStream printStream;
    private final float rowHeight;
    private final PointF scrollPosition;
    private final PointF scrollSize;
    private boolean scrollingHorizontally;
    private boolean scrollingVertically;

    public LogView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public LogView(Context context, AttributeSet attrs, int defStyleAttr) {
        this(context, attrs, defStyleAttr, 0);
    }

    public LogView(Context context, AttributeSet attrs, int defStyleAttr, int defStyleRes) {
        super(context, attrs, defStyleAttr, defStyleRes);
        this.paint = new Paint(1);
        this.lines = new ArrayList<>();
        this.rowHeight = UnitUtils.dpToPx(30.0f);
        this.defaultTextSize = UnitUtils.dpToPx(16.0f);
        this.minScrollThumbSize = UnitUtils.dpToPx(6.0f);
        this.lastPoint = new PointF();
        this.scrollPosition = new PointF();
        this.scrollSize = new PointF();
        this.isActionDown = false;
        this.scrollingHorizontally = false;
        this.scrollingVertically = false;
        this.lock = new Object();
        SharedPreferences preferences = PreferenceManager.getDefaultSharedPreferences(context);
        String logPath = preferences.getString("log_file", getLogFile().getPath());
        boolean saveToFile = preferences.getBoolean("save_logs_to_file", false);
        File logFile = new File(logPath);
        FileUtils.delete(logFile);
        if (saveToFile) {
            PrintStream printStream = null;
            try {
                printStream = new PrintStream(new BufferedOutputStream(new FileOutputStream(logFile), 65536));
            } catch (IOException e) {
            }
            this.printStream = printStream;
            return;
        }
        this.printStream = null;
    }

    @Override // android.view.View
    protected void onSizeChanged(int w, int h, int oldw, int oldh) {
        super.onSizeChanged(w, h, oldw, oldh);
        computeScrollSize();
    }

    @Override // android.view.View
    protected void onDraw(Canvas canvas) {
        int count;
        int i;
        int colorPrimaryText;
        super.onDraw(canvas);
        int width = getWidth();
        int height = getHeight();
        if (width == 0 || height == 0) {
            return;
        }
        synchronized (this.lock) {
            this.paint.setStyle(Paint.Style.FILL);
            Context context = getContext();
            int colorPrimaryText2 = 1056964608;
            if (!this.lines.isEmpty()) {
                this.paint.setTextSize(this.defaultTextSize);
                float textHeight = this.paint.getFontSpacing();
                float rowY = -this.scrollPosition.y;
                int colorPrimarySurface = AppUtils.getThemeColor(context, R.attr.colorPrimarySurface);
                int colorSecondarySurface = AppUtils.getThemeColor(context, R.attr.colorSecondarySurface);
                int colorPrimaryText3 = AppUtils.getThemeColor(context, R.attr.colorPrimaryText);
                int count2 = this.lines.size();
                float rowY2 = rowY;
                int i2 = 0;
                while (i2 < count2) {
                    float f = this.rowHeight;
                    if (rowY2 + f < 0.0f || rowY2 >= height) {
                        count = count2;
                        i = colorPrimaryText2;
                        colorPrimaryText = colorPrimaryText3;
                        rowY2 += f;
                        i2++;
                        colorPrimaryText3 = colorPrimaryText;
                        count2 = count;
                        colorPrimaryText2 = i;
                    } else {
                        this.paint.setColor(i2 % 2 != 0 ? colorPrimarySurface : colorSecondarySurface);
                        count = count2;
                        colorPrimaryText = colorPrimaryText3;
                        canvas.drawRect(-this.scrollPosition.x, rowY2, width, rowY2 + this.rowHeight, this.paint);
                        this.paint.setColor(colorPrimaryText);
                        i = 1056964608;
                        float centerY = (rowY2 - this.paint.ascent()) + ((this.rowHeight - textHeight) * 0.5f);
                        i2 = i2;
                        canvas.drawText(this.lines.get(i2), -this.scrollPosition.x, centerY, this.paint);
                        rowY2 += this.rowHeight;
                        i2++;
                        colorPrimaryText3 = colorPrimaryText;
                        count2 = count;
                        colorPrimaryText2 = i;
                    }
                }
                drawScrollThumbs(canvas);
                return;
            }
            this.paint.setTextSize(UnitUtils.dpToPx(20.0f));
            this.paint.setColor(AppUtils.getThemeColor(context, R.attr.colorSecondaryText));
            String text = getContext().getString(R.string.no_items_to_display);
            float centerX = (width - this.paint.measureText(text)) * 0.5f;
            float centerY2 = ((height - this.paint.getFontSpacing()) * 0.5f) - this.paint.ascent();
            canvas.drawText(text, centerX, centerY2, this.paint);
        }
    }

    private void drawScrollThumbs(Canvas canvas) {
        float scrollThumbX = getScrollThumbX();
        float scrollThumbY = getScrollThumbY();
        float scrollThumbWidth = getScrollThumbWidth();
        float scrollThumbHeight = getScrollThumbHeight();
        this.paint.setColor(855638016);
        float radius = this.minScrollThumbSize * 0.5f;
        canvas.drawRoundRect(scrollThumbX, getHeight() - this.minScrollThumbSize, scrollThumbX + scrollThumbWidth, getHeight(), radius, radius, this.paint);
        canvas.drawRoundRect(getWidth() - this.minScrollThumbSize, scrollThumbY, getWidth(), scrollThumbY + scrollThumbHeight, radius, radius, this.paint);
    }

    public float getScrollMaxLeft() {
        return Math.max(0.0f, this.scrollSize.x - getWidth());
    }

    public float getScrollMaxTop() {
        return Math.max(0.0f, this.scrollSize.y - getHeight());
    }

    public float getScrollThumbX() {
        float width = getWidth();
        float f = this.scrollSize.x;
        if (f <= 0.0f || f <= width) {
            return -3.4028235E38f;
        }
        return this.scrollPosition.x * (width / f);
    }

    public float getScrollThumbY() {
        float height = getHeight();
        float f = this.scrollSize.y;
        if (f <= 0.0f || f <= height) {
            return -3.4028235E38f;
        }
        return this.scrollPosition.y * (height / f);
    }

    public float getScrollThumbWidth() {
        float width = getWidth();
        float f = this.scrollSize.x;
        if (f <= 0.0f || f <= width) {
            return 0.0f;
        }
        return Math.max(width - ((getScrollMaxLeft() / this.scrollSize.x) * width), this.minScrollThumbSize);
    }

    public float getScrollThumbHeight() {
        float height = getHeight();
        float f = this.scrollSize.y;
        if (f <= 0.0f || f <= height) {
            return 0.0f;
        }
        return Math.max(height - ((getScrollMaxTop() / this.scrollSize.y) * height), this.minScrollThumbSize);
    }

    private void computeScrollSize() {
        int width = getWidth();
        int height = getHeight();
        if (width == 0 || height == 0) {
            return;
        }
        float maxWidth = 0.0f;
        this.paint.setTextSize(this.defaultTextSize);
        int count = this.lines.size();
        for (int i = 0; i < count; i++) {
            maxWidth = Math.max(this.paint.measureText(this.lines.get(i)), maxWidth);
        }
        this.scrollSize.x = Math.max(maxWidth, width);
        this.scrollSize.y = Math.max(this.rowHeight * this.lines.size(), height);
        this.scrollPosition.set(0.0f, getScrollMaxTop());
    }

    public void clear() {
        synchronized (this.lock) {
            this.lines.clear();
        }
        postInvalidate();
    }

    public void append(String line) {
        synchronized (this.lock) {
            String content = line.replace("\n", "");
            if (content.isEmpty()) {
                return;
            }
            String logLine = "[" + ((Object) DateFormat.format("HH:mm:ss", System.currentTimeMillis())) + "]  " + content;
            this.lines.add(logLine);
            PrintStream printStream = this.printStream;
            if (printStream != null) {
                printStream.append((CharSequence) (logLine + "\n"));
                this.printStream.flush();
            }
            computeScrollSize();
            postInvalidate();
        }
    }

    public static File getLogFile() {
        File parent = new File(Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOCUMENTS), "Winlator");
        if (!parent.isDirectory()) {
            parent.mkdirs();
        }
        return new File(parent, "logs.txt");
    }

    public void exportToFile() {
        File logFile = getLogFile();
        String logPath = logFile.getPath();
        if (logFile.isFile()) {
            logFile.delete();
        }
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter(logFile));
            try {
                synchronized (this.lock) {
                    for (String line : this.lines) {
                        writer.write(line + "\n");
                    }
                }
                String path = logPath.substring(logPath.indexOf(Environment.DIRECTORY_DOCUMENTS));
                Context context = getContext();
                AppUtils.showToast(context, context.getString(R.string.logs_exported_to) + " " + path);
                writer.close();
            } finally {
            }
        } catch (IOException e) {
        }
    }

    /* JADX WARN: Can't fix incorrect switch cases order, some code will duplicate */
    @Override // android.view.View
    public boolean onTouchEvent(MotionEvent event) {
        switch (event.getAction()) {
            case 0:
                this.lastPoint.set(event.getX(), event.getY());
                this.isActionDown = true;
                this.scrollingHorizontally = false;
                this.scrollingVertically = false;
                return true;
            case 1:
                this.isActionDown = false;
                return true;
            case 2:
                if (this.isActionDown) {
                    float dx = event.getX() - this.lastPoint.x;
                    float dy = event.getY() - this.lastPoint.y;
                    if (Math.abs(dx) > 10.0f) {
                        this.scrollingHorizontally = true;
                    }
                    if (Math.abs(dy) > 10.0f) {
                        this.scrollingVertically = true;
                    }
                    if (this.scrollingHorizontally) {
                        PointF pointF = this.scrollPosition;
                        pointF.x = Mathf.clamp(pointF.x - dx, 0.0f, getScrollMaxLeft());
                        this.lastPoint.set(event.getX(), event.getY());
                        invalidate();
                    }
                    if (this.scrollingVertically) {
                        PointF pointF2 = this.scrollPosition;
                        pointF2.y = Mathf.clamp(pointF2.y - dy, 0.0f, getScrollMaxTop());
                        this.lastPoint.set(event.getX(), event.getY());
                        invalidate();
                    }
                }
                return true;
            default:
                return true;
        }
    }
}
