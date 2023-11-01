package com.video.yuv;

public class NativeLib {

    // Used to load the 'yuv' library on application startup.
    static {
        System.loadLibrary("yuv");
    }

    /**
     * A native method that is implemented by the 'yuv' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}