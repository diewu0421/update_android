package com.example.zlw.jnidemo

import android.util.Log

/**
 * Human
 * @author zlw
 * @date 2018/3/31
 */

open class Human {
    open fun sayHi(){
        Log.e(TAG, "Sayhi")
    }

    companion object {
        val TAG = "Human"
    }
}
