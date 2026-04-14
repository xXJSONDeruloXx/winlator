package com.google.android.material.datepicker;

import android.content.Context;
import android.text.format.DateUtils;
import java.util.Date;
import java.util.Locale;
import java.util.TimeZone;

/* JADX INFO: loaded from: classes.dex */
class DateStrings {
    static String getYearMonth(Context context, long timeInMillis) {
        long offsetMillis = TimeZone.getDefault().getOffset(timeInMillis);
        return DateUtils.formatDateTime(context, timeInMillis - offsetMillis, 36);
    }

    static String getMonthDayOfWeekDay(long timeInMillis) {
        return getMonthDayOfWeekDay(timeInMillis, Locale.getDefault());
    }

    static String getMonthDayOfWeekDay(long timeInMillis, Locale locale) {
        return UtcDates.getAbbrMonthWeekdayDayFormat(locale).format(new Date(timeInMillis));
    }

    static String getYearMonthDayOfWeekDay(long timeInMillis) {
        return getYearMonthDayOfWeekDay(timeInMillis, Locale.getDefault());
    }

    static String getYearMonthDayOfWeekDay(long timeInMillis, Locale locale) {
        return UtcDates.getYearAbbrMonthWeekdayDayFormat(locale).format(new Date(timeInMillis));
    }
}
