package com.rmsl.juce;

import android.content.Context;

public class Java
{
    static
    {
        System.loadLibrary("native-lib");
    }

    public native static void initialiseJUCE(Context context);
}