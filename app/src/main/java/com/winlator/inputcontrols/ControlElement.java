package com.winlator.inputcontrols;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.PointF;
import android.graphics.Rect;
import com.winlator.core.Bitmask;
import com.winlator.core.CubicBezierInterpolator;
import com.winlator.math.Mathf;
import com.winlator.widget.InputControlsView;
import com.winlator.widget.TouchpadView;
import com.winlator.winhandler.MIDIHandler;
import com.winlator.winhandler.WinHandler;
import java.util.Arrays;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/* JADX INFO: loaded from: classes.dex */
public class ControlElement {
    private Binding[] bindings;
    private final Rect boundingBox;
    private int currentPointerId;
    private PointF currentPosition;
    private byte iconId;
    private final InputControlsView inputControlsView;
    private CubicBezierInterpolator interpolator;
    private float opacity;
    private byte orientation;
    private Path[] paths;
    private final Bitmask propertyFlags;
    private Range range;
    private float scale;
    private RangeScroller scroller;
    private boolean[] states;
    private String text;
    private Object touchTime;
    private short x;
    private short y;
    private Type type = Type.BUTTON;
    private Shape shape = Shape.CIRCLE;

    public enum Type {
        BUTTON,
        D_PAD,
        RANGE_BUTTON,
        STICK,
        TRACKPAD,
        MIDI_KEY,
        RADIAL_MENU;

        public static String[] names() {
            Type[] types = values();
            String[] names = new String[types.length];
            for (int i = 0; i < types.length; i++) {
                names[i] = types[i].name().replace("_", "-");
            }
            return names;
        }
    }

    public enum Shape {
        CIRCLE,
        RECT,
        ROUND_RECT,
        SQUARE;

        public static String[] names() {
            Shape[] shapes = values();
            String[] names = new String[shapes.length];
            for (int i = 0; i < shapes.length; i++) {
                names[i] = shapes[i].name().replace("_", " ");
            }
            return names;
        }
    }

    public enum Range {
        FROM_A_TO_Z(26),
        FROM_0_TO_9(10),
        FROM_F1_TO_F12(12),
        FROM_NP0_TO_NP9(10);

        public final byte max;

        Range(int max) {
            this.max = (byte) max;
        }

        public static String[] names() {
            Range[] ranges = values();
            String[] names = new String[ranges.length];
            for (int i = 0; i < ranges.length; i++) {
                names[i] = ranges[i].name().replace("_", " ");
            }
            return names;
        }
    }

    public ControlElement(InputControlsView inputControlsView) {
        Binding binding = Binding.NONE;
        this.bindings = new Binding[]{binding, binding, binding, binding};
        this.scale = 1.0f;
        this.opacity = 1.0f;
        this.currentPointerId = -1;
        this.boundingBox = new Rect();
        this.states = new boolean[4];
        this.propertyFlags = new Bitmask(new int[]{16});
        this.text = "";
        this.inputControlsView = inputControlsView;
    }

    private void reset() {
        this.bindings = new Binding[4];
        setBinding(Binding.NONE);
        this.scroller = null;
        this.text = "";
        switch (AnonymousClass1.$SwitchMap$com$winlator$inputcontrols$ControlElement$Type[this.type.ordinal()]) {
            case 1:
            case 2:
                Binding[] bindingArr = this.bindings;
                bindingArr[0] = Binding.KEY_W;
                bindingArr[1] = Binding.KEY_D;
                bindingArr[2] = Binding.KEY_S;
                bindingArr[3] = Binding.KEY_A;
                break;
            case 3:
                Binding[] bindingArr2 = this.bindings;
                bindingArr2[0] = Binding.MOUSE_MOVE_UP;
                bindingArr2[1] = Binding.MOUSE_MOVE_RIGHT;
                bindingArr2[2] = Binding.MOUSE_MOVE_DOWN;
                bindingArr2[3] = Binding.MOUSE_MOVE_LEFT;
                break;
            case 4:
                this.scroller = new RangeScroller(this.inputControlsView, this);
                break;
            case 5:
                this.shape = Shape.SQUARE;
                this.text = "C1";
                break;
            case 6:
                setBindingCount(3);
                break;
        }
        this.iconId = (byte) 0;
        this.range = null;
        this.propertyFlags.set(16);
    }

    public Type getType() {
        return this.type;
    }

    public void setType(Type type) {
        this.type = type;
        reset();
    }

    public byte getBindingCount() {
        return (byte) this.bindings.length;
    }

    public byte getFirstBindingIndex() {
        byte i = 0;
        while (true) {
            Binding[] bindingArr = this.bindings;
            if (i >= bindingArr.length) {
                return (byte) 0;
            }
            if (bindingArr[i] != Binding.NONE) {
                return i;
            }
            i = (byte) (i + 1);
        }
    }

    public void setBindingCount(int bindingCount) {
        this.bindings = new Binding[bindingCount];
        setBinding(Binding.NONE);
        this.states = new boolean[bindingCount];
        this.propertyFlags.set(16);
    }

    public Shape getShape() {
        return this.shape;
    }

    public void setShape(Shape shape) {
        this.shape = shape;
        this.propertyFlags.set(16);
    }

    public Range getRange() {
        Range range = this.range;
        return range != null ? range : Range.FROM_A_TO_Z;
    }

    public void setRange(Range range) {
        this.range = range;
    }

    public byte getOrientation() {
        return this.orientation;
    }

    public void setOrientation(byte orientation) {
        this.orientation = orientation;
        this.propertyFlags.set(16);
    }

    public boolean isToggleSwitch() {
        return this.propertyFlags.isSet(8);
    }

    public void setToggleSwitch(boolean toggleSwitch) {
        this.propertyFlags.set(8, toggleSwitch);
    }

    public boolean isMouseMoveMode() {
        return this.propertyFlags.isSet(32);
    }

    public void setMouseMoveMode(boolean mouseMoveMode) {
        this.propertyFlags.set(32, mouseMoveMode);
    }

    public Binding getBindingAt(int index) {
        Binding[] bindingArr = this.bindings;
        return index < bindingArr.length ? bindingArr[index] : Binding.NONE;
    }

    public void setBindingAt(int index, Binding binding) {
        Binding[] bindingArr = this.bindings;
        if (index >= bindingArr.length) {
            int oldLength = bindingArr.length;
            Binding[] bindingArr2 = (Binding[]) Arrays.copyOf(bindingArr, index + 1);
            this.bindings = bindingArr2;
            Arrays.fill(bindingArr2, oldLength, bindingArr2.length, Binding.NONE);
            this.states = new boolean[this.bindings.length];
            this.propertyFlags.set(16);
        }
        this.bindings[index] = binding;
    }

    public void setBinding(Binding binding) {
        Arrays.fill(this.bindings, binding);
    }

    public float getScale() {
        return this.scale;
    }

    public void setScale(float scale) {
        this.scale = scale;
        this.propertyFlags.set(16);
    }

    public float getOpacity() {
        return this.opacity;
    }

    public void setOpacity(float opacity) {
        this.opacity = opacity;
    }

    public short getX() {
        return this.x;
    }

    public void setX(int x) {
        this.x = (short) x;
        this.propertyFlags.set(16);
    }

    public short getY() {
        return this.y;
    }

    public void setY(int y) {
        this.y = (short) y;
        this.propertyFlags.set(16);
    }

    public void setSelected(boolean selected) {
        if (this.type == Type.RADIAL_MENU) {
            this.propertyFlags.set(4, selected);
        }
        this.propertyFlags.set(1, selected);
    }

    public String getText() {
        return this.text;
    }

    public void setText(String text) {
        this.text = text != null ? text : "";
    }

    public byte getIconId() {
        return this.iconId;
    }

    public void setIconId(int iconId) {
        this.iconId = (byte) iconId;
    }

    public Rect getBoundingBox() {
        if (this.propertyFlags.isSet(16)) {
            computeBoundingBox();
        }
        return this.boundingBox;
    }

    private Rect computeBoundingBox() {
        int snappingSize = this.inputControlsView.getSnappingSize();
        int halfWidth = 0;
        int halfHeight = 0;
        switch (AnonymousClass1.$SwitchMap$com$winlator$inputcontrols$ControlElement$Type[this.type.ordinal()]) {
            case 1:
                halfWidth = snappingSize * 7;
                halfHeight = snappingSize * 7;
                break;
            case 2:
            case 3:
                halfWidth = snappingSize * 6;
                halfHeight = snappingSize * 6;
                break;
            case 4:
                halfWidth = snappingSize * ((this.bindings.length * 4) / 2);
                halfHeight = snappingSize * 2;
                if (this.orientation == 1) {
                    halfWidth = halfHeight;
                    halfHeight = halfWidth;
                }
                break;
            case 5:
            case 7:
                switch (AnonymousClass1.$SwitchMap$com$winlator$inputcontrols$ControlElement$Shape[this.shape.ordinal()]) {
                    case 1:
                    case 2:
                        halfWidth = snappingSize * 4;
                        halfHeight = snappingSize * 2;
                        break;
                    case 3:
                        halfWidth = (int) (snappingSize * 2.5f);
                        halfHeight = (int) (snappingSize * 2.5f);
                        break;
                    case 4:
                        halfWidth = snappingSize * 3;
                        halfHeight = snappingSize * 3;
                        break;
                }
                break;
            case 6:
                halfWidth = snappingSize * 3;
                halfHeight = snappingSize * 3;
                break;
        }
        float f = this.scale;
        int halfWidth2 = (int) (halfWidth * f);
        int halfHeight2 = (int) (halfHeight * f);
        Rect rect = this.boundingBox;
        short s = this.x;
        short s2 = this.y;
        rect.set(s - halfWidth2, s2 - halfHeight2, s + halfWidth2, s2 + halfHeight2);
        this.propertyFlags.unset(16);
        this.paths = null;
        return this.boundingBox;
    }

    private String getBindingTextAt(int index) {
        Binding binding = getBindingAt(index);
        String text = binding.toString().replace("NUMPAD ", "NP").replace("BUTTON ", "");
        if (text.length() > 7) {
            String[] parts = text.split(" ");
            StringBuilder sb = new StringBuilder();
            for (String part : parts) {
                sb.append(part.charAt(0));
            }
            StringBuilder sb2 = new StringBuilder();
            sb2.append(binding.isMouse() ? "M" : "");
            sb2.append((Object) sb);
            return sb2.toString();
        }
        return text;
    }

    private String getDisplayText() {
        String str = this.text;
        if (str != null && !str.isEmpty()) {
            return this.text;
        }
        if (this.type == Type.BUTTON) {
            StringBuilder sb = new StringBuilder();
            byte i = 0;
            while (true) {
                Binding[] bindingArr = this.bindings;
                if (i >= bindingArr.length) {
                    break;
                }
                if (bindingArr[i] != Binding.NONE) {
                    if (sb.length() > 0) {
                        sb.append("+");
                    }
                    sb.append(getBindingTextAt(i));
                }
                i = (byte) (i + 1);
            }
            if (sb.length() > 0) {
                return sb.toString();
            }
        }
        return getBindingTextAt(0);
    }

    private static float getTextSizeForWidth(Paint paint, String text, float desiredWidth) {
        paint.setTextSize(48.0f);
        return (48.0f * desiredWidth) / paint.measureText(text);
    }

    /* JADX INFO: renamed from: com.winlator.inputcontrols.ControlElement$1, reason: invalid class name */
    static /* synthetic */ class AnonymousClass1 {
        static final /* synthetic */ int[] $SwitchMap$com$winlator$inputcontrols$ControlElement$Range;
        static final /* synthetic */ int[] $SwitchMap$com$winlator$inputcontrols$ControlElement$Shape;
        static final /* synthetic */ int[] $SwitchMap$com$winlator$inputcontrols$ControlElement$Type;

        static {
            int[] iArr = new int[Range.values().length];
            $SwitchMap$com$winlator$inputcontrols$ControlElement$Range = iArr;
            try {
                iArr[Range.FROM_A_TO_Z.ordinal()] = 1;
            } catch (NoSuchFieldError e) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Range[Range.FROM_0_TO_9.ordinal()] = 2;
            } catch (NoSuchFieldError e2) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Range[Range.FROM_F1_TO_F12.ordinal()] = 3;
            } catch (NoSuchFieldError e3) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Range[Range.FROM_NP0_TO_NP9.ordinal()] = 4;
            } catch (NoSuchFieldError e4) {
            }
            int[] iArr2 = new int[Shape.values().length];
            $SwitchMap$com$winlator$inputcontrols$ControlElement$Shape = iArr2;
            try {
                iArr2[Shape.RECT.ordinal()] = 1;
            } catch (NoSuchFieldError e5) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Shape[Shape.ROUND_RECT.ordinal()] = 2;
            } catch (NoSuchFieldError e6) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Shape[Shape.SQUARE.ordinal()] = 3;
            } catch (NoSuchFieldError e7) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Shape[Shape.CIRCLE.ordinal()] = 4;
            } catch (NoSuchFieldError e8) {
            }
            int[] iArr3 = new int[Type.values().length];
            $SwitchMap$com$winlator$inputcontrols$ControlElement$Type = iArr3;
            try {
                iArr3[Type.D_PAD.ordinal()] = 1;
            } catch (NoSuchFieldError e9) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[Type.STICK.ordinal()] = 2;
            } catch (NoSuchFieldError e10) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[Type.TRACKPAD.ordinal()] = 3;
            } catch (NoSuchFieldError e11) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[Type.RANGE_BUTTON.ordinal()] = 4;
            } catch (NoSuchFieldError e12) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[Type.MIDI_KEY.ordinal()] = 5;
            } catch (NoSuchFieldError e13) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[Type.RADIAL_MENU.ordinal()] = 6;
            } catch (NoSuchFieldError e14) {
            }
            try {
                $SwitchMap$com$winlator$inputcontrols$ControlElement$Type[Type.BUTTON.ordinal()] = 7;
            } catch (NoSuchFieldError e15) {
            }
        }
    }

    private static Binding getRangeBindingForIndex(Range range, int index) {
        switch (AnonymousClass1.$SwitchMap$com$winlator$inputcontrols$ControlElement$Range[range.ordinal()]) {
            case 1:
                return Binding.valueOf("KEY_" + ((char) (index + 65)));
            case 2:
                return Binding.valueOf("KEY_" + ((index + 1) % 10));
            case 3:
                return Binding.valueOf("KEY_F" + (index + 1));
            case 4:
                return Binding.valueOf("KEY_KP_" + ((index + 1) % 10));
            default:
                return Binding.NONE;
        }
    }

    private static String getRangeTextForIndex(Range range, int index) {
        switch (AnonymousClass1.$SwitchMap$com$winlator$inputcontrols$ControlElement$Range[range.ordinal()]) {
            case 1:
                return String.valueOf((char) (index + 65));
            case 2:
                return String.valueOf((index + 1) % 10);
            case 3:
                return "F" + (index + 1);
            case 4:
                return "NP" + ((index + 1) % 10);
            default:
                return "";
        }
    }

    /* JADX WARN: Removed duplicated region for block: B:119:0x06b6  */
    /* JADX WARN: Removed duplicated region for block: B:132:0x0727  */
    /* JADX WARN: Removed duplicated region for block: B:83:0x0558  */
    /* JADX WARN: Removed duplicated region for block: B:96:0x05cb  */
    /*
        Code decompiled incorrectly, please refer to instructions dump.
        To view partially-correct add '--show-bad-code' argument
    */
    public void draw(android.graphics.Canvas r48) {
        /*
            Method dump skipped, instruction units count: 2302
            To view this dump add '--comments-level debug' option
        */
        throw new UnsupportedOperationException("Method not decompiled: com.winlator.inputcontrols.ControlElement.draw(android.graphics.Canvas):void");
    }

    private void drawIcon(Canvas canvas, float cx, float cy, float width, float height, int iconId, boolean automargin) {
        int margin;
        Paint paint = this.inputControlsView.getPaint();
        Bitmap icon = this.inputControlsView.getIcon((byte) iconId);
        paint.setColorFilter(this.propertyFlags.isSet(2) ? this.inputControlsView.getDarkColorFilter() : this.inputControlsView.getLightColorFilter());
        float snappingSize = this.inputControlsView.getSnappingSize();
        if (automargin) {
            Shape shape = this.shape;
            margin = (int) (((shape == Shape.CIRCLE || shape == Shape.SQUARE) ? 2.0f : 1.0f) * snappingSize * this.scale);
        } else {
            margin = 0;
        }
        int halfSize = (int) ((Math.min(width, height) - margin) * 0.5f);
        Rect srcRect = new Rect(0, 0, icon.getWidth(), icon.getHeight());
        Rect dstRect = new Rect((int) (cx - halfSize), (int) (cy - halfSize), (int) (halfSize + cx), (int) (cy + halfSize));
        canvas.drawBitmap(icon, srcRect, dstRect, paint);
        paint.setColorFilter(null);
    }

    public JSONObject toJSONObject() {
        Range range;
        try {
            JSONObject elementJSONObject = new JSONObject();
            elementJSONObject.put("type", this.type.name());
            elementJSONObject.put("shape", this.shape.name());
            JSONArray bindingsJSONArray = new JSONArray();
            for (Binding binding : this.bindings) {
                bindingsJSONArray.put(binding.name());
            }
            elementJSONObject.put("bindings", bindingsJSONArray);
            elementJSONObject.put("scale", Float.valueOf(this.scale));
            float f = this.opacity;
            if (f < 1.0f) {
                elementJSONObject.put("opacity", Float.valueOf(f));
            }
            elementJSONObject.put("x", this.x / this.inputControlsView.getMaxWidth());
            elementJSONObject.put("y", this.y / this.inputControlsView.getMaxHeight());
            elementJSONObject.put("toggleSwitch", this.propertyFlags.isSet(8));
            elementJSONObject.put("text", this.text);
            elementJSONObject.put("iconId", this.iconId);
            if (this.type == Type.RANGE_BUTTON && (range = this.range) != null) {
                elementJSONObject.put("range", range.name());
                int i = this.orientation;
                if (i != 0) {
                    elementJSONObject.put("orientation", i);
                }
            }
            if (this.propertyFlags.isSet(32)) {
                elementJSONObject.put("mouseMoveMode", true);
            }
            return elementJSONObject;
        } catch (JSONException e) {
            return null;
        }
    }

    public boolean containsPoint(float x, float y) {
        if (this.type == Type.RADIAL_MENU && this.propertyFlags.isSet(4)) {
            float outerRadius = this.boundingBox.width() + (this.inputControlsView.getSnappingSize() * this.scale);
            return Mathf.distance((float) this.boundingBox.centerX(), (float) this.boundingBox.centerY(), x, y) < outerRadius;
        }
        return getBoundingBox().contains((int) (x + 0.5f), (int) (0.5f + y));
    }

    private boolean isKeepButtonPressedAfterMinTime() {
        Binding binding = getBindingAt(0);
        if (this.propertyFlags.isSet(8)) {
            return false;
        }
        return binding == Binding.GAMEPAD_BUTTON_L3 || binding == Binding.GAMEPAD_BUTTON_R3;
    }

    public boolean handleTouchDown(int pointerId, float x, float y) {
        if (this.currentPointerId != -1 || !containsPoint(x, y)) {
            return false;
        }
        this.currentPointerId = pointerId;
        Type type = this.type;
        if (type == Type.BUTTON) {
            if (isKeepButtonPressedAfterMinTime()) {
                this.touchTime = Long.valueOf(System.currentTimeMillis());
            }
            if (!this.propertyFlags.isSet(8) || !this.propertyFlags.isSet(1)) {
                this.inputControlsView.handleInputEvent(this.bindings, true);
            }
            if (this.propertyFlags.isSet(32)) {
                this.inputControlsView.getTouchpadView().mouseMove(x, y, 0);
            }
            this.propertyFlags.set(2);
            this.inputControlsView.invalidate();
            return true;
        }
        if (type == Type.RANGE_BUTTON) {
            this.scroller.handleTouchDown(x, y);
            this.propertyFlags.set(2);
            this.inputControlsView.invalidate();
            return true;
        }
        if (type == Type.MIDI_KEY) {
            WinHandler winHandler = this.inputControlsView.getXServer().getWinHandler();
            if (winHandler != null) {
                byte note = (byte) (MIDIHandler.parseNoteNumber(this.text) + 12);
                winHandler.getMIDIhandler().sendShortMsg((byte) -112, (byte) 0, note, (byte) 127);
                this.propertyFlags.set(2);
                this.inputControlsView.invalidate();
            }
            return true;
        }
        if (type == Type.RADIAL_MENU) {
            if (!this.propertyFlags.isSet(4)) {
                this.propertyFlags.set(4);
            } else if (Mathf.distance(this.boundingBox.centerX(), this.boundingBox.centerY(), x, y) < this.boundingBox.width() * 0.5f) {
                this.propertyFlags.unset(4);
            }
            this.inputControlsView.invalidate();
            return true;
        }
        if (type == Type.TRACKPAD) {
            if (this.currentPosition == null) {
                this.currentPosition = new PointF();
            }
            this.currentPosition.set(x, y);
        }
        return handleTouchMove(pointerId, x, y);
    }

    public boolean handleTouchMove(int pointerId, float x, float y) {
        Type type;
        float offsetX;
        float offsetY;
        Rect boundingBox;
        float radius;
        TouchpadView touchpadView;
        int i = this.currentPointerId;
        if (pointerId == i && ((type = this.type) == Type.D_PAD || type == Type.STICK || type == Type.TRACKPAD)) {
            Rect boundingBox2 = getBoundingBox();
            float radius2 = boundingBox2.width() * 0.5f;
            TouchpadView touchpadView2 = this.inputControlsView.getTouchpadView();
            Type type2 = this.type;
            Type type3 = Type.TRACKPAD;
            if (type2 == type3) {
                if (this.currentPosition == null) {
                    this.currentPosition = new PointF();
                }
                PointF pointF = this.currentPosition;
                float[] deltaPoint = touchpadView2.computeDeltaPoint(pointF.x, pointF.y, x, y);
                offsetX = deltaPoint[0];
                offsetY = deltaPoint[1];
                this.currentPosition.set(x, y);
            } else {
                float localX = x - boundingBox2.left;
                float localY = y - boundingBox2.top;
                float offsetX2 = localX - radius2;
                float offsetY2 = localY - radius2;
                float distance = Mathf.lengthSq(radius2 - localX, radius2 - localY);
                if (distance > radius2 * radius2) {
                    float angle = (float) Math.atan2(offsetY2, offsetX2);
                    radius2 = radius2;
                    offsetX2 = (float) (Math.cos(angle) * ((double) radius2));
                    offsetY2 = (float) (Math.sin(angle) * ((double) radius2));
                }
                float deltaX = Mathf.clamp(offsetX2 / radius2, -1.0f, 1.0f);
                offsetX = deltaX;
                offsetY = Mathf.clamp(offsetY2 / radius2, -1.0f, 1.0f);
            }
            Type type4 = this.type;
            float f = 3.0f;
            byte b = 3;
            if (type4 == Type.STICK) {
                if (this.currentPosition == null) {
                    this.currentPosition = new PointF();
                }
                PointF pointF2 = this.currentPosition;
                pointF2.x = boundingBox2.left + (offsetX * radius2) + radius2;
                pointF2.y = boundingBox2.top + (offsetY * radius2) + radius2;
                boolean[] states = new boolean[4];
                states[0] = offsetY <= -0.15f;
                states[1] = offsetX >= 0.15f;
                states[2] = offsetY >= 0.15f;
                states[3] = offsetX <= -0.15f;
                byte i2 = 0;
                for (byte b2 = 4; i2 < b2; b2 = 4) {
                    float value = (i2 == 1 || i2 == b) ? offsetX : offsetY;
                    Binding binding = getBindingAt(i2);
                    if (binding.isGamepad()) {
                        this.inputControlsView.handleInputEvent(binding, true, Mathf.clamp(Math.max(0.0f, Math.abs(value) - 0.01f) * Mathf.sign(value) * f, -1.0f, 1.0f));
                        this.states[i2] = true;
                    } else {
                        boolean state = binding.isMouseMove() ? states[i2] || states[(i2 + 2) % 4] : states[i2];
                        this.inputControlsView.handleInputEvent(binding, state, value);
                        this.states[i2] = state;
                    }
                    i2 = (byte) (i2 + 1);
                    f = 3.0f;
                    b = 3;
                }
                this.inputControlsView.invalidate();
                return true;
            }
            if (type4 == type3) {
                boolean[] states2 = new boolean[4];
                states2[0] = offsetY <= -0.8f;
                states2[1] = offsetX >= 0.8f;
                states2[2] = offsetY >= 0.8f;
                states2[3] = offsetX <= -0.8f;
                int cursorDx = 0;
                int cursorDy = 0;
                byte i3 = 0;
                while (i3 < 4) {
                    float value2 = (i3 == 1 || i3 == 3) ? offsetX : offsetY;
                    Binding binding2 = getBindingAt(i3);
                    if (binding2.isGamepad()) {
                        if (this.interpolator == null) {
                            this.interpolator = new CubicBezierInterpolator();
                        }
                        if (Math.abs(value2) > 4.0f) {
                            value2 *= 3.0f;
                        }
                        boundingBox = boundingBox2;
                        radius = radius2;
                        touchpadView = touchpadView2;
                        this.interpolator.set(0.075f, 0.95f, 0.45f, 0.95f);
                        float interpolatedValue = this.interpolator.getInterpolation(Math.min(1.0f, Math.abs(value2 / 20.0f)));
                        this.inputControlsView.handleInputEvent(binding2, true, Mathf.clamp(Mathf.sign(value2) * interpolatedValue, -1.0f, 1.0f));
                        this.states[i3] = true;
                    } else {
                        boundingBox = boundingBox2;
                        radius = radius2;
                        touchpadView = touchpadView2;
                        if (Math.abs(value2) > 6.0f) {
                            value2 *= 1.5f;
                        }
                        if (binding2 == Binding.MOUSE_MOVE_LEFT || binding2 == Binding.MOUSE_MOVE_RIGHT) {
                            int cursorDy2 = Mathf.roundPoint(value2);
                            cursorDx = cursorDy2;
                        } else if (binding2 == Binding.MOUSE_MOVE_UP || binding2 == Binding.MOUSE_MOVE_DOWN) {
                            cursorDy = Mathf.roundPoint(value2);
                        } else {
                            this.inputControlsView.handleInputEvent(binding2, states2[i3], value2);
                            this.states[i3] = states2[i3];
                        }
                    }
                    i3 = (byte) (i3 + 1);
                    boundingBox2 = boundingBox;
                    radius2 = radius;
                    touchpadView2 = touchpadView;
                }
                if (cursorDx != 0 || cursorDy != 0) {
                    this.inputControlsView.getXServer().injectPointerMoveDelta(cursorDx, cursorDy);
                    return true;
                }
                return true;
            }
            boolean[] states3 = new boolean[4];
            states3[0] = offsetY <= -0.3f;
            states3[1] = offsetX >= 0.3f;
            states3[2] = offsetY >= 0.3f;
            states3[3] = offsetX <= -0.3f;
            byte i4 = 0;
            while (i4 < 4) {
                float value3 = (i4 == 1 || i4 == 3) ? offsetX : offsetY;
                Binding binding3 = getBindingAt(i4);
                boolean state2 = binding3.isMouseMove() ? states3[i4] || states3[(i4 + 2) % 4] : states3[i4];
                this.inputControlsView.handleInputEvent(binding3, state2, value3);
                this.states[i4] = state2;
                i4 = (byte) (i4 + 1);
            }
            return true;
        }
        if (pointerId == i && this.type == Type.RANGE_BUTTON) {
            this.scroller.handleTouchMove(x, y);
            if (this.scroller.isScrolling()) {
                this.propertyFlags.unset(2);
                this.inputControlsView.invalidate();
                return true;
            }
            return true;
        }
        if (pointerId == i && this.type == Type.BUTTON && this.propertyFlags.isSet(32)) {
            this.inputControlsView.getTouchpadView().mouseMove(x, y, 2);
            return true;
        }
        return false;
    }

    public boolean handleTouchUp(int pointerId, float x, float y) {
        if (pointerId != this.currentPointerId) {
            return false;
        }
        Type type = this.type;
        if (type == Type.BUTTON) {
            boolean selected = this.propertyFlags.isSet(1);
            if (isKeepButtonPressedAfterMinTime() && this.touchTime != null) {
                selected = System.currentTimeMillis() - ((Long) this.touchTime).longValue() > 300;
                if (!selected) {
                    this.inputControlsView.handleInputEvent(this.bindings, false);
                }
                this.propertyFlags.set(1, selected);
                this.touchTime = null;
            } else if (!this.propertyFlags.isSet(8) || this.propertyFlags.isSet(1)) {
                this.inputControlsView.handleInputEvent(this.bindings, false);
            }
            if (this.propertyFlags.isSet(8)) {
                this.propertyFlags.set(1, selected ? false : true);
            }
            if (this.propertyFlags.isSet(32)) {
                this.inputControlsView.getTouchpadView().mouseMove(0.0f, 0.0f, 1);
            }
            this.propertyFlags.unset(2);
            this.inputControlsView.invalidate();
        } else if (type == Type.MIDI_KEY) {
            WinHandler winHandler = this.inputControlsView.getXServer().getWinHandler();
            if (winHandler != null) {
                byte note = (byte) (MIDIHandler.parseNoteNumber(this.text) + 12);
                winHandler.getMIDIhandler().sendShortMsg((byte) -128, (byte) 0, note, (byte) 127);
                this.propertyFlags.unset(2);
                this.inputControlsView.invalidate();
            }
        } else if (type == Type.RADIAL_MENU) {
            if (this.propertyFlags.isSet(4)) {
                handleRadialMenuClick(x, y);
            }
            this.inputControlsView.invalidate();
        } else if (type == Type.RANGE_BUTTON || type == Type.D_PAD || type == Type.STICK || type == Type.TRACKPAD) {
            byte i = 0;
            while (true) {
                boolean[] zArr = this.states;
                if (i >= zArr.length) {
                    break;
                }
                if (zArr[i]) {
                    this.inputControlsView.handleInputEvent(getBindingAt(i), false);
                }
                this.states[i] = false;
                i = (byte) (i + 1);
            }
            Type type2 = this.type;
            if (type2 == Type.RANGE_BUTTON) {
                this.scroller.handleTouchUp();
                this.propertyFlags.unset(2);
                this.inputControlsView.invalidate();
            } else if (type2 == Type.STICK) {
                this.inputControlsView.invalidate();
            }
            if (this.currentPosition != null) {
                this.currentPosition = null;
            }
        }
        this.currentPointerId = -1;
        return true;
    }

    private void handleRadialMenuClick(float x, float y) {
        final ControlElement controlElement;
        int snappingSize;
        Binding clickedBinding;
        int i;
        float outerRadius;
        char c;
        ControlElement controlElement2;
        float f;
        ControlElement controlElement3 = this;
        float f2 = x;
        int snappingSize2 = controlElement3.inputControlsView.getSnappingSize();
        float cx = controlElement3.boundingBox.centerX();
        float cy = controlElement3.boundingBox.centerY();
        float innerRadius = (controlElement3.boundingBox.width() * 0.5f) + (snappingSize2 * 0.5f);
        float outerRadius2 = controlElement3.boundingBox.width() + (snappingSize2 * controlElement3.scale);
        float startAngle = 0.0f;
        Binding clickedBinding2 = Binding.NONE;
        int i2 = 0;
        int j = 0;
        while (true) {
            if (i2 > controlElement3.bindings.length) {
                controlElement = controlElement3;
                break;
            }
            float t = (float) i2 / controlElement3.bindings.length;
            float outerRadius3 = outerRadius2;
            float endAngle = (float) ((((double) t) * 3.141592653589793d * 2.0d) + 4.71238898038469d);
            if (i2 <= 0) {
                snappingSize = snappingSize2;
                clickedBinding = clickedBinding2;
                i = i2;
                outerRadius = outerRadius3;
                c = 0;
                controlElement2 = controlElement3;
                f = f2;
            } else {
                float middleAngle = (startAngle + endAngle) * 0.5f;
                snappingSize = snappingSize2;
                float touchAreaCenter = (innerRadius + outerRadius3) * 0.5f;
                clickedBinding = clickedBinding2;
                i = i2;
                float touchAreaX = (short) (((double) cx) + (Math.cos(middleAngle) * ((double) touchAreaCenter)));
                float touchAreaY = (short) (((double) cy) + (Math.sin(middleAngle) * ((double) touchAreaCenter)));
                float lineAx = (float) (((double) cx) + (Math.cos(startAngle) * ((double) touchAreaCenter)));
                float lineAy = (float) (((double) cy) + (Math.sin(startAngle) * ((double) touchAreaCenter)));
                int j2 = j;
                float lineBx = (float) (((double) cx) + (Math.cos(endAngle) * ((double) touchAreaCenter)));
                outerRadius = outerRadius3;
                float lineBy = (float) (((double) cy) + (Math.sin(endAngle) * ((double) touchAreaCenter)));
                f = x;
                c = 0;
                if (Mathf.distance(touchAreaX, touchAreaY, f, y) > Mathf.distance(lineAx, lineAy, lineBx, lineBy) * 0.5f || Mathf.distance(cx, cy, f, y) <= innerRadius || Mathf.distance(cx, cy, f, y) > outerRadius) {
                    controlElement2 = this;
                    j = j2 + 1;
                } else {
                    controlElement = this;
                    Binding clickedBinding3 = controlElement.bindings[j2];
                    clickedBinding2 = clickedBinding3;
                    break;
                }
            }
            startAngle = endAngle;
            f2 = f;
            snappingSize2 = snappingSize;
            clickedBinding2 = clickedBinding;
            outerRadius2 = outerRadius;
            i2 = i + 1;
            controlElement3 = controlElement2;
        }
        if (clickedBinding2 != Binding.NONE) {
            controlElement.propertyFlags.unset(4);
            final Binding finalBinding = clickedBinding2;
            controlElement.inputControlsView.handleInputEvent(finalBinding, true);
            controlElement.inputControlsView.postDelayed(() -> lambda_handleRadialMenuClick_0(finalBinding), 30L);
        }
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_handleRadialMenuClick_0(Binding finalBinding) {
        this.inputControlsView.handleInputEvent(finalBinding, false);
    }

    public int getLightColor() {
        float opacity = this.inputControlsView.isEditMode() ? Math.max(0.15f, this.opacity) : this.opacity;
        return Color.argb((int) (this.inputControlsView.getOverlayOpacity() * opacity * 255.0f), 255, 255, 255);
    }

    public int getDarkColor() {
        float opacity = this.inputControlsView.isEditMode() ? Math.max(0.15f, this.opacity) : this.opacity;
        return Color.argb((int) (this.inputControlsView.getOverlayOpacity() * opacity * 255.0f), 0, 0, 0);
    }

    public int getHighlightColor() {
        return Color.argb((int) (this.inputControlsView.getOverlayOpacity() * 255.0f), 2, 119, 189);
    }
}
