//
// Created by ZLW on 2018/4/5.
//
#include <jni.h>
#include "bzip2/bspatch.c"
#include <android/log.h>
JNIEXPORT void JNICALL
Java_com_example_zlw_jnidemo_udpate_utils_BsPatch_patch(JNIEnv *env, jclass type,
                                                        jstring oldfile_jstr,
                                                        jstring newfile_jstr,
                                                        jstring patchfile_jstr) {
    int argc = 4;
    char* oldfile = (char*)(*env)->GetStringUTFChars(env,oldfile_jstr, NULL);
    char* newfile = (char*)(*env)->GetStringUTFChars(env,newfile_jstr, NULL);
    char* patchfile = (char*)(*env)->GetStringUTFChars(env,patchfile_jstr, NULL);

    //参数（第一个参数无效）
    char *argv[4];
    argv[0] = "bspatch";
    argv[1] = oldfile;
    argv[2] = newfile;
    argv[3] = patchfile;

    bspatch_main(argc,argv);

    (*env)->ReleaseStringUTFChars(env,oldfile_jstr, oldfile);
    (*env)->ReleaseStringUTFChars(env,newfile_jstr, newfile);
    (*env)->ReleaseStringUTFChars(env,patchfile_jstr, patchfile);
//    __android_log_print(ANDROID_LOG_ERROR, "zlwzlw", "I'm a %s", "boy");
}

