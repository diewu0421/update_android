package com.example.zlw.jnidemo.udpate.utils

import android.os.Environment
import java.io.File

/**
 * Constants1
 * @author zlw
 * @date 2018/4/4
 */
class Constants1 {
    companion object {
        @JvmField
        val PATCH_FILE = "apk.patch"
        @JvmField
        val SD_PATH = Environment.getExternalStorageDirectory().absolutePath + File.separator
        @JvmField
        val NEW_APK_PATH = SD_PATH + "jni_demo_new_apk.apk"
        @JvmField
        val PATCH_PATH = SD_PATH + PATCH_FILE
    }
}