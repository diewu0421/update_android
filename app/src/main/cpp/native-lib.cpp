#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_Main3Activity_getStringFromC(JNIEnv *env, jobject instance) {

    // TODO

    printf("我被输出了");

    return env->NewStringUTF("我是返回的值");
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_Person_accessGetUUID(JNIEnv *env, jobject instance) {
//    jclass cls = env->GetObjectClass(instance);
//    jfieldID fid = env->GetStaticFieldID(cls, "uuid", "I");
//    jint value = env->GetStaticIntField(cls, fid);
//    value = 1232342344;
//    env->SetStaticIntField(cls, fid, value);

    jclass cls = env->GetObjectClass(instance);
    jmethodID mid = env->GetStaticMethodID(cls, "getUUID1", "()Ljava/lang/String;");
    jstring uuid_str = (jstring) env->CallStaticObjectMethod(cls, mid);
//    return env->NewStringUTF("Nihaosdfas");
    return uuid_str;
}


extern "C"
JNIEXPORT void* JNICALL
Java_com_example_zlw_jnidemo_Person_testStaticMethod(JNIEnv *env,jclass cls) {
//    jclass cls = env->GetObjectClass(instance);
//    jmethodID mid = env->GetStaticMethodID(cls, "getUUID1", "()Ljava/lang/String;");
//    jstring jstr = (jstring) env->CallStaticObjectMethod(cls, mid);
//    return jstr;
    return env->NewStringUTF("afsdf");
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_zlw_jnidemo_Person1_accessGetUUID2(
        JNIEnv *env, jobject instance) {

    jclass cls = env->GetObjectClass(instance);
    jfieldID fid = env->GetStaticFieldID(cls, "uuiD1", "Ljava/lang/String;");
    jstring uuid_str = (jstring) env->GetStaticObjectField(cls, fid);
//    jstring uuid_str = env->NewStringUTF("adsf");
    return uuid_str;
}