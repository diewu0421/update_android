package com.example.zlw.jnidemo.encrypt

import android.os.Environment

import java.io.File

/**
 * Cryptor
 *
 * @author zlw
 * @date 2018/4/1
 */

object Cryptor {

    init {

        System.loadLibrary("lib_crypt")
    }

    external fun crypt(narmal_path: String, crypt_path: String)
    external fun decrypt(crypt_path: String, normal_path: String)

}
