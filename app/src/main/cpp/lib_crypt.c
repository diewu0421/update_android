//
// Created by ZLW on 2018/4/1.
//
#include <jni.h>
#include <stdio.h>
#include <string.h>

char* password = "buzhidaoLA510";
JNIEXPORT void JNICALL
Java_com_example_zlw_jnidemo_encrypt_Cryptor_crypt
        (
                JNIEnv *env, jclass type,
                jstring narmal_path_,
                jstring crypt_path_) {

    const char *normal_path = (*env)->GetStringUTFChars(env, narmal_path_, JNI_FALSE);
    const char *crypt_path = (*env)->GetStringUTFChars(env, crypt_path_, JNI_FALSE);
    FILE *pr = fopen(normal_path,"rb");
    FILE *pw = fopen(crypt_path,"wb");
    int i  = 0;
    int ch;
    int len = strlen(password);
    while ((ch = fgetc(pr)) != EOF) {
//       fwrite(ch ^ password[i],)
        fputc(ch ^ password[i % len], pw);
        i++;
    }
    fclose(pr);
    fclose(pw);
    (*env)->ReleaseStringChars(env, narmal_path_, normal_path);
    (*env)->ReleaseStringChars(env, crypt_path_, crypt_path);
}

JNIEXPORT void JNICALL
Java_com_example_zlw_jnidemo_encrypt_Cryptor_decrypt
        (
                JNIEnv *env, jclass type,
                jstring narmal_path_,
                jstring crypt_path_) {
    const char *normal_path = (*env)->GetStringUTFChars(env, narmal_path_, JNI_FALSE);
    const char *crypt_path = (*env)->GetStringUTFChars(env, crypt_path_, JNI_FALSE);
    FILE *pr = fopen(normal_path,"rb");
    FILE *pw = fopen(crypt_path,"wb");
    int i  = 0;
    int ch;
    int len = strlen(password);
    while ((ch = fgetc(pr)) != EOF) {
//       fwrite(ch ^ password[i],)
        fputc(ch ^ password[i % len], pw);
        i++;
    }
    fclose(pr);
    fclose(pw);
    (*env)->ReleaseStringChars(env, narmal_path_, normal_path);
    (*env)->ReleaseStringChars(env, crypt_path_, crypt_path);
}