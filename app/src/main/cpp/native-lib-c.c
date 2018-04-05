//
// Created by ZLW on 2018/3/29.
//

#include <jni.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_Main3Activity_getStringFromC(JNIEnv *env, jobject instance) {

    jclass cls = (*env)->GetObjectClass(env, instance);
    //属性的名称，属性签名
    jfieldID jid = (*env)->GetFieldID(env, cls, "mMember1", "Ljava/lang/String;");
    //jason >> super jason
    //获取key属性的值
    jstring jstr = (*env)->GetObjectField(env, instance, jid);
    //jstring -> c 字符串
    //最后一个参数 isCopy
    char *c_str = (char *) (*env)->GetStringUTFChars(env, jstr, (jboolean *) JNI_FALSE);
    //拼接得到新的字符串
    char text[20] = "super ";
    strcat(text, c_str);
    //c字符串   -》 jstring
    jstring new_jstr = (*env)->NewStringUTF(env, text);
    //修改key
    (*env)->SetObjectField(env, instance, jid, new_jstr);
    return new_jstr;
//   printf("zlw:content asdfasdf");
//   return (*env)->NewStringUTF(env,"nihao");
}

/**
 * 访问静态属性
*/
JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_Main3Activity_accessStaticField(
        JNIEnv *env, jobject instance) {
    jclass cls = (*env)->GetObjectClass(env, instance);
    jfieldID jfieldID1 = (*env)->GetStaticFieldID(env, cls, "count", "I");
    jint count_value = (*env)->GetStaticIntField(env, cls, jfieldID1);
    count_value++;
    (*env)->SetStaticIntField(env, cls, jfieldID1, count_value);
    return NULL;
}

/**
 * 访问java方法
*/
JNIEXPORT jint JNICALL
Java_com_example_zlw_jnidemo_Main3Activity_accessGetRandom(
        JNIEnv *env, jobject instance) {
    jclass cls = (*env)->GetObjectClass(env, instance);
    jmethodID jmethodID1 = (*env)->GetMethodID(env, cls, "genarateRandomInt", "(I)I");
    jint random_int = (*env)->CallIntMethod(env, instance, jmethodID1, 200);
    return random_int;
}

/**
 * 静态方法
 * @param env
 * @param instance
 * @return
 */
JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_Main3Activity_accessGetUUID(
        JNIEnv *env, jobject instance) {
    jclass cls = (*env)->GetObjectClass(env, instance);
//    jmethodID mid = (*env)->GetMethodID(env, cls, "getUUID", "()Ljava/lang/String;");
//    return (*env)->CallObjectMethod(env, instance, mid);

    jmethodID mid = (*env)->GetStaticMethodID(env, cls, "getUUID", "()Ljava/lang/String;");
    jstring jstatic_str = (*env)->CallStaticObjectMethod(env, cls, mid);
    return jstatic_str;
}

/**
 * 访问静态属性
*/
JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_Person_accessGetUUID34(
        JNIEnv *env, jobject instance) {
    jclass cls = (*env)->GetObjectClass(env, instance);
    jfieldID jfieldID1 = (*env)->GetStaticFieldID(env, cls, "uuid", "I");
    jint count_value = (*env)->GetStaticIntField(env, cls, jfieldID1);
    count_value = 5865;
    (*env)->SetStaticIntField(env, cls, jfieldID1, count_value);
    return NULL;
}

//访问构造方法
//使用java.util.Date产生一个当前的时间戳
//JNIEXPORT jobject JNICALL Java_com_example_zlw_jnidemo_Main3Activity_accessConstructor
//        (JNIEnv *env, jobject jobj){
//    jclass cls = (*env)->FindClass(env, "java/util/Date");
//    //jmethodID
//    jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
//    //实例化一个Date对象
//    jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
//    //调用getTime方法
//    jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");
//    jlong time = (*env)->CallLongMethod(env, date_obj, mid);
//
//    printf("\ntime:%lld\n",time);
//
//    return date_obj;
//}

JNIEXPORT jobject JNICALL Java_com_example_zlw_jnidemo_Main3Activity_accessConstructor
        (JNIEnv *env, jobject jobj) {
    jclass cls = (*env)->FindClass(env, "java/util/Date");
    //jmethodID
    jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
    //实例化一个Date对象
    jobject date_obj = (*env)->NewObject(env, cls, constructor_mid);
    //调用getTime方法
    jmethodID mid = (*env)->GetMethodID(env, cls, "getTime", "()J");
    jlong time = (*env)->CallLongMethod(env, date_obj, mid);

    printf("\ntime:%lld\n", time);

    return date_obj;
}

/**
 * 访问父类的方法
 * @param env
 * @param jobj
 * @return
 */
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_accessNonvirtualMethod
        (JNIEnv *env, jobject jobj) {
    jclass cls = (*env)->GetObjectClass(env, jobj);
    jfieldID fid = (*env)->GetFieldID(env, cls, "man", "Lcom/example/zlw/jnidemo/Human;");
    jobject man_obj = (*env)->GetObjectField(env, jobj, fid);
    //调用自己的方法
    //获取自己的Human类
    jclass human_cls = (*env)->FindClass(env, "com/example/zlw/jnidemo/Human");
    jmethodID sayHi_mid = (*env)->GetMethodID(env, human_cls, "sayHi", "()V");
    //调用Man自己类的方法
//    (*env)->CallVoidMethod(env, man_obj, sayHi_mid);
    //调用父类Human的方法
    (*env)->CallNonvirtualVoidMethod(env, man_obj, human_cls, sayHi_mid);

}


/**
 * 解决中文问题
 * @param env
 * @param jobj
 * @param in
 * @return
 */

JNIEXPORT jstring JNICALL Java_com_example_zlw_jnidemo_Main3Activity_chineseChars
        (JNIEnv *env, jobject jobj, jstring in) {
    //得到c的字符串
//    char *c_str = (char *) (*env)->GetStringUTFChars(env, in, JNI_FALSE);

    //得到jstring
    //c - jstring
    char *c_str = "马蓉与宋哲";
//    jstring new_str = (*env)->NewStringUTF(env, c_str);
//    return new_str;
    jclass string_cls = (*env)->FindClass(env, "java/lang/String");
    jmethodID constructor_mid = (*env)->GetMethodID(env, string_cls, "<init>",
                                                    "([BLjava/lang/String;)V");
    jbyteArray datas = (*env)->NewByteArray(env, strlen(c_str));
    //复制数据到新创建的数组内
    (*env)->SetByteArrayRegion(env, datas, 0, strlen(c_str), c_str);
    jstring charname = (*env)->NewStringUTF(env, "utf-8");
    jstring new_str = (*env)->NewObject(env, string_cls, constructor_mid, datas, charname);
    return new_str;
}

int compare_fun(int *a, int *b) {
    return (*a) - (*b);
}


/**
 * 传入数组
 * @param env
 * @param jobj
 * @param array
 */
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_giveArray
        (JNIEnv *env, jobject jobj, jintArray array) {
    jint *elems = (*env)->GetIntArrayElements(env, array, NULL);
    int len = (*env)->GetArrayLength(env, array);
    qsort(elems, len, sizeof(jint), compare_fun);
    (*env)->ReleaseIntArrayElements(env, array, elems, 0);
}

/**
 * 返回数组
 * @param env
 * @param jobj
 * @param array
 */
JNIEXPORT jintArray JNICALL Java_com_example_zlw_jnidemo_Main3Activity_getArray
        (JNIEnv *env, jobject jobj, jint len) {
    jintArray jint_array = (*env)->NewIntArray(env, len);
    jint *elems = (*env)->GetIntArrayElements(env, jint_array, NULL);
    int i = 0;
    for (int i = 0; i < len; ++i) {
        elems[i] = i;
    }
    (*env)->ReleaseIntArrayElements(env, jint_array, elems, 0);
    return jint_array;
}

//JIN 引用变量
//引用类型：局部引用和全局应用
//作用：在JNI中告知虚拟机何时回收一个JNI变量

JNIEXPORT jintArray JNICALL Java_com_example_zlw_jnidemo_Main3Activity_localRef
                            (JNIEnv *env, jobject jobj) {
    int i = 0;
    for (; i < 5; ++i) {
        jclass cls = (*env)->FindClass(env, "java/util/Date");
        jmethodID constructor_mid = (*env)->GetMethodID(env, cls, "<init>", "()V");
        jobject data_obj = (*env)->NewObject(env, cls, constructor_mid);

        //释放对象
        (*env)->DeleteLocalRef(env, data_obj);

        printf("release 释放对象成功");
    }
}

/**
 * 创建一个全局异常
 */
jstring globalRef = NULL;
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_createGlobalRef
        (JNIEnv *env, jobject jobj) {
    jstring obj = (*env)->NewStringUTF(env, "Jni devolopment is powerful!");
    globalRef = (*env)->NewGlobalRef(env, obj);

}

/**
 * 获取全局引用
 * @param env
 * @param jobj
 * @return
 */
JNIEXPORT jstring JNICALL Java_com_example_zlw_jnidemo_Main3Activity_getGlobalRef
        (JNIEnv *env, jobject jobj) {
    return globalRef;
}

/**
 * 删除全局引用
 * @param env
 * @param jobj
 */
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_deleteGlobalRef
        (JNIEnv *env, jobject jobj) {
    (*env)->DeleteGlobalRef(env, globalRef);

}

/**
 * 弱全局应用
 * @param env
 * @param jobj
 */
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_weakGlobalRef
        (JNIEnv *env, jobject jobj) {

}
/**
 * 处理异常
 * @param env
 * @param jobj
 */
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_handleException
        (JNIEnv *env, jobject jobj) {
    jclass cls = (*env)->GetObjectClass(env, jobj);
    jfieldID fid = (*env)->GetFieldID(env, cls,"key2", "Ljava/lang/String;");
    //检测是否发生异常
    jthrowable jthrowable1 = (*env)->ExceptionOccurred(env);
    if (jthrowable1 != NULL) {
        //清除异常
        (*env)->ExceptionClear(env);
        //补救措施
        fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
    }
    jstring str = (*env)->GetObjectField(env,jobj,fid);
    char *c_str = (char *) (*env)->GetStringUTFChars(env, str, NULL);
    if (strcmp(c_str, "zlw2") != 0) {
        jclass exception_cls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, exception_cls, "key's value is not valid");
    }
}

/**
 * 缓存策略
 * @param env
 * @param jobj
 */
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_cache
        (JNIEnv *env, jobject jobj) {

    jclass cls = (*env)->GetObjectClass(env,jobj);
//    static jboolean isGet = NULL;
    static jfieldID key_id = NULL;
    if (key_id == NULL) {
        key_id = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
        printf("getFieldId");
    }
}

jfieldID  fid;
jmethodID mid;
JNIEXPORT void JNICALL Java_com_example_zlw_jnidemo_Main3Activity_initIDs
        (JNIEnv *env, jclass cls) {
//    fid = (*env)->GetFieldID(env, cls, "key", "Ljava/lang/String;");
//    mid = (*env)->GetMethodID(env, cls, "genarateRandomInt", "(I)I");
    printf("Niha");
}

