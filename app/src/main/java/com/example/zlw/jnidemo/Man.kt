package com.example.zlw.jnidemo

import android.util.Log

/**
 * Man
 * @author zlw
 * @date 2018/3/31
 */

class Man : Human() {
    override fun sayHi() {
        Log.e(TAG, "sayHi 男人打招呼2")
    }
}
