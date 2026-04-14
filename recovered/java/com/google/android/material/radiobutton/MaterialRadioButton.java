package com.google.android.material.radiobutton;

import android.R;
import android.content.Context;
import android.content.res.ColorStateList;
import android.content.res.TypedArray;
import android.util.AttributeSet;
import androidx.appcompat.widget.AppCompatRadioButton;
import androidx.core.widget.CompoundButtonCompat;
import com.google.android.material.R$attr;
import com.google.android.material.R$style;
import com.google.android.material.R$styleable;
import com.google.android.material.color.MaterialColors;
import com.google.android.material.internal.ThemeEnforcement;
import com.google.android.material.resources.MaterialResources;
import com.google.android.material.theme.overlay.MaterialThemeOverlay;

/* JADX INFO: loaded from: classes.dex */
public class MaterialRadioButton extends AppCompatRadioButton {
    private static final int DEF_STYLE_RES = R$style.Widget_MaterialComponents_CompoundButton_RadioButton;
    private static final int[][] ENABLED_CHECKED_STATES = {new int[]{R.attr.state_enabled, R.attr.state_checked}, new int[]{R.attr.state_enabled, -16842912}, new int[]{-16842910, R.attr.state_checked}, new int[]{-16842910, -16842912}};
    private ColorStateList materialThemeColorsTintList;
    private boolean useMaterialThemeColors;

    public MaterialRadioButton(Context context, AttributeSet attrs) {
        this(context, attrs, R$attr.radioButtonStyle);
    }

    /* JADX WARN: Illegal instructions before constructor call */
    public MaterialRadioButton(Context context, AttributeSet attrs, int defStyleAttr) {
        int i = DEF_STYLE_RES;
        super(MaterialThemeOverlay.wrap(context, attrs, defStyleAttr, i), attrs, defStyleAttr);
        Context context2 = getContext();
        TypedArray attributes = ThemeEnforcement.obtainStyledAttributes(context2, attrs, R$styleable.MaterialRadioButton, defStyleAttr, i, new int[0]);
        int i2 = R$styleable.MaterialRadioButton_buttonTint;
        if (attributes.hasValue(i2)) {
            CompoundButtonCompat.setButtonTintList(this, MaterialResources.getColorStateList(context2, attributes, i2));
        }
        this.useMaterialThemeColors = attributes.getBoolean(R$styleable.MaterialRadioButton_useMaterialThemeColors, false);
        attributes.recycle();
    }

    @Override // android.widget.TextView, android.view.View
    protected void onAttachedToWindow() {
        super.onAttachedToWindow();
        if (this.useMaterialThemeColors && CompoundButtonCompat.getButtonTintList(this) == null) {
            setUseMaterialThemeColors(true);
        }
    }

    public void setUseMaterialThemeColors(boolean useMaterialThemeColors) {
        this.useMaterialThemeColors = useMaterialThemeColors;
        if (useMaterialThemeColors) {
            CompoundButtonCompat.setButtonTintList(this, getMaterialThemeColorsTintList());
        } else {
            CompoundButtonCompat.setButtonTintList(this, null);
        }
    }

    private ColorStateList getMaterialThemeColorsTintList() {
        if (this.materialThemeColorsTintList == null) {
            int colorControlActivated = MaterialColors.getColor(this, R$attr.colorControlActivated);
            int colorOnSurface = MaterialColors.getColor(this, R$attr.colorOnSurface);
            int colorSurface = MaterialColors.getColor(this, R$attr.colorSurface);
            int[][] iArr = ENABLED_CHECKED_STATES;
            int[] radioButtonColorList = new int[iArr.length];
            radioButtonColorList[0] = MaterialColors.layer(colorSurface, colorControlActivated, 1.0f);
            radioButtonColorList[1] = MaterialColors.layer(colorSurface, colorOnSurface, 0.54f);
            radioButtonColorList[2] = MaterialColors.layer(colorSurface, colorOnSurface, 0.38f);
            radioButtonColorList[3] = MaterialColors.layer(colorSurface, colorOnSurface, 0.38f);
            this.materialThemeColorsTintList = new ColorStateList(iArr, radioButtonColorList);
        }
        return this.materialThemeColorsTintList;
    }
}
