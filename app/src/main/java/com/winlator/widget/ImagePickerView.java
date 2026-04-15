package com.winlator.widget;

import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Rect;
import android.graphics.RectF;
import android.net.Uri;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import com.winlator.MainActivity;
import com.winlator.R;
import com.winlator.core.AppUtils;
import com.winlator.core.Callback;
import com.winlator.core.FileUtils;
import com.winlator.core.ImageUtils;
import com.winlator.core.UnitUtils;
import com.winlator.core.WineThemeManager;
import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/* JADX INFO: loaded from: classes.dex */
public class ImagePickerView extends View implements View.OnClickListener {
    private final List<String> defaultSources;
    private final Bitmap icon;
    private String selectedSource;

    public ImagePickerView(Context context, AttributeSet attrs) {
        this(context, attrs, 0);
    }

    public ImagePickerView(Context context, AttributeSet attrs, int defStyleAttr) {
        super(context, attrs, defStyleAttr);
        this.defaultSources = Arrays.asList("wallpaper-1", "wallpaper-2", "wallpaper-3");
        this.selectedSource = "wallpaper-1";
        this.icon = BitmapFactory.decodeResource(context.getResources(), R.drawable.icon_image_picker);
        setBackgroundResource(R.drawable.combo_box);
        setClickable(true);
        setFocusable(true);
        setOnClickListener(this);
    }

    public String getSelectedSource() {
        return this.selectedSource;
    }

    public void setSelectedSource(String selectedSource) {
        this.selectedSource = selectedSource;
    }

    @Override // android.view.View
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        int width = getWidth();
        int height = getHeight();
        if (width == 0 || height == 0) {
            return;
        }
        float rectSize = height - UnitUtils.dpToPx(12.0f);
        float startX = ((width - rectSize) * 0.5f) - UnitUtils.dpToPx(16.0f);
        float startY = (height - rectSize) * 0.5f;
        Paint paint = new Paint(1);
        Rect srcRect = new Rect(0, 0, this.icon.getWidth(), this.icon.getHeight());
        RectF dstRect = new RectF(startX, startY, startX + rectSize, startY + rectSize);
        canvas.drawBitmap(this.icon, srcRect, dstRect, paint);
    }

    @Override // android.view.View.OnClickListener
    public void onClick(View anchor) {
        final Context context = getContext();
        final File userWallpaperFile = WineThemeManager.getUserWallpaperFile(context);
        LayoutInflater inflater = LayoutInflater.from(context);
        View view = inflater.inflate(R.layout.image_picker_view, (ViewGroup) null);
        LinearLayout llImageList = (LinearLayout) view.findViewById(R.id.LLImageList);
        final PopupWindow[] popupWindow = {null};
        ArrayList<String> sources = new ArrayList<>(this.defaultSources);
        if (userWallpaperFile.isFile()) {
            sources.add("user-wallpaper");
        }
        for (final String source : sources) {
            View itemView = inflater.inflate(R.layout.image_picker_list_item, (ViewGroup) llImageList, false);
            ImageView imageView = (ImageView) itemView.findViewById(R.id.ImageView);
            if (source.startsWith("wallpaper-")) {
                imageView.setImageBitmap(ImageUtils.getBitmapFromAsset(context, "wallpapers/" + source + "/image.png"));
            } else if (source.equals("user-wallpaper")) {
                imageView.setImageBitmap(BitmapFactory.decodeFile(userWallpaperFile.getPath()));
                View removeButton = itemView.findViewById(R.id.BTRemove);
                removeButton.setVisibility(0);
                removeButton.setOnClickListener(view2 -> lambda_onClick_0(userWallpaperFile, popupWindow, view2));
            }
            if (source.equals(this.selectedSource)) {
                itemView.setBackgroundResource(R.drawable.bordered_panel);
            }
            itemView.setOnClickListener(view2 -> lambda_onClick_1(source, popupWindow, view2));
            llImageList.addView(itemView);
        }
        View browseButton = view.findViewById(R.id.BTBrowse);
        browseButton.setOnClickListener(new View.OnClickListener() { // from class: com.winlator.widget.ImagePickerView$$ExternalSyntheticLambda0
            @Override // android.view.View.OnClickListener
            public final void onClick(View view2) {
                ImagePickerView.lambda_onClick_3(context, userWallpaperFile, popupWindow, view2);
            }
        });
        popupWindow[0] = AppUtils.showPopupWindow(anchor, view, 0, 200);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_onClick_0(File userWallpaperFile, PopupWindow[] popupWindow, View v) {
        FileUtils.delete(userWallpaperFile);
        this.selectedSource = "wallpaper-1";
        popupWindow[0].dismiss();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public /* synthetic */ void lambda_onClick_1(String source, PopupWindow[] popupWindow, View v) {
        this.selectedSource = source;
        popupWindow[0].dismiss();
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_onClick_3(final Context context, final File userWallpaperFile, final PopupWindow[] popupWindow, View v) {
        MainActivity activity = (MainActivity) context;
        Intent intent = new Intent("android.intent.action.PICK");
        intent.setType("image/*");
        activity.setOpenFileCallback(new Callback() { // from class: com.winlator.widget.ImagePickerView$$ExternalSyntheticLambda3
            @Override // com.winlator.core.Callback
            public final void call(Object obj) {
                ImagePickerView.lambda_onClick_2(context, userWallpaperFile, popupWindow, (Uri) obj);
            }
        });
        activity.startActivityForResult(intent, 2);
    }

    /* JADX INFO: Access modifiers changed from: private */
    public static /* synthetic */ void lambda_onClick_2(Context context, File userWallpaperFile, PopupWindow[] popupWindow, Uri data) {
        Bitmap bitmap = ImageUtils.getBitmapFromUri(context, data, 1280);
        if (bitmap == null) {
            return;
        }
        ImageUtils.save(bitmap, userWallpaperFile, Bitmap.CompressFormat.PNG, 100);
        popupWindow[0].dismiss();
    }
}
