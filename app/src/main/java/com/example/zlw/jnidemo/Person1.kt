package com.example.zlw.jnidemo

import java.util.UUID

/**
 * Person
 *
 * @author zlw
 * @date 2018/3/30
 */

class Person1(private val name: String) {

    //这里有个坑，不能使用internal
    external fun accessGetUUID2(): String

    companion object {

        public val uuiD1: String = "234214"

        ////            get() = UUID.randomUUID().toString()
//            get () {
//                return UUID.randomUUID().toString()
//            }
        init {
            System.loadLibrary("native-lib")
        }
    }

}
