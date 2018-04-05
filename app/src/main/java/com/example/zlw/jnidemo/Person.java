package com.example.zlw.jnidemo;

import java.util.UUID;

import kotlin.jvm.JvmStatic;

/**
 * Person
 *
 * @author zlw
 * @date 2018/3/30
 */

public class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public static String getUUID1(){
        return UUID.randomUUID().toString();
    }

    native String accessGetUUID();
    public static native String testStaticMethod();

    public int[] names;
    static {
        System.loadLibrary("native-lib");
//        testStaticMethod();

    }
}
