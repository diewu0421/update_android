package com.example.zlw.jnidemo.difffile

/**
 * DiffUtil
 * @author zlw
 * @date 2018/4/2
 */
object DiffUtil {

    init {
        System.loadLibrary("libdiff")

    }

    external fun diff(path: String, pattern: String, fileNum: Int)
    external fun patch(path: String, pattern: String, fileNum: Int)
}