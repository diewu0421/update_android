//
// Created by ZLW on 2018/4/2.
//
#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <android/log.h>

#define LOGE(FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,"jason",FORMAT,__VA_ARGS__)

/**
 * 获取文件的大小
 * @param fp
 * @return
 */
int get_file_size(const char *file_path) {
    FILE *fp = fopen(file_path, "rb");
    fseek(fp, 0, SEEK_END);
    return (int) ftell(fp);
}

JNIEXPORT void JNICALL
Java_com_example_zlw_jnidemo_difffile_DiffUtil_diff(
        JNIEnv *env, jclass type, jstring path, jstring pattern, jint num) {
    const char *file_path = (*env)->GetStringUTFChars(env, path, NULL);
    const char *pattern_str = (*env)->GetStringUTFChars(env, pattern, NULL);
//    LOGE("path is %s",file_path);
    LOGE("path is %s", file_path);
    //to do something
    char **sub_path = malloc(sizeof(char *) * num);
    for (int i = 0; i < num; ++i) {
        sub_path[i] = malloc(sizeof(char) * 100);
        sprintf(sub_path[i], pattern_str, i + 1);
        LOGE("sub path is %s", sub_path[i]);
    }

    int file_size = get_file_size(file_path);
    FILE *fpr = fopen(file_path, "rb");
    if (file_size % num == 0) {
        //如果是整除的情况
        //拿到子文件的大小，进行循环写入
        int sub_file_szie = file_size / num;
        for (int i = 0; i < num; ++i) {
            FILE *fpw = fopen(sub_path[i], "wb");
            for (int j = 0; j < sub_file_szie; ++j) {
                fputc(fgetc(fpr), fpw);
            }
            fclose(fpw);
        }
    } else {
        //不整除的情况
        //单个文件（暂时不包括最后一个)
        int sub_file_size = file_size / (num - 1);
        for (int i = 0; i < num - 1; ++i) {
            FILE *fpw = fopen(sub_path[i], "wb");
            for (int j = 0; j < sub_file_size; ++j) {
                fputc(fgetc(fpr), fpw);
            }
            fclose(fpw);
        }

//        if (file_size % (num - 1) != 0) {
            //the last one
            FILE *fpw = fopen(sub_path[num - 1], "wb");
            for (int i = 0; i < file_size % (num - 1); ++i) {
                fputc(fgetc(fpr), fpw);
            }
            fclose(fpw);
//        }
    }

    //关闭文件
    fclose(fpr);
    //释放内存
    for (int i = 0; i < num; ++i) {
        free(sub_path[i]);
    }
    free(sub_path);
    (*env)->ReleaseStringChars(env, path, file_path);
    (*env)->ReleaseStringChars(env, pattern, pattern_str);
}

/**
 * 合并文件
 * @param env
 * @param type
 * @param path
 * @param pattern
 * @param num
 */
JNIEXPORT void JNICALL
Java_com_example_zlw_jnidemo_difffile_DiffUtil_patch(
        JNIEnv *env, jclass type, jstring path, jstring pattern, jint num) {
    const char *file_path = (*env)->GetStringUTFChars(env, path, NULL);
    const char *pattern_str = (*env)->GetStringUTFChars(env, pattern, NULL);
    //to do something
    char **sub_path = malloc(sizeof(char *) * num);
    for (int i = 0; i < num; i++) {
        sub_path[i] = malloc(sizeof(char) * 100);
        sprintf(sub_path[i], pattern_str, i + 1);
    }

    FILE *fpw = fopen(file_path, "wb");
    for (int i = 0; i < num; i++) {
        int sub_file_size = get_file_size(sub_path[i]);
        FILE *fpr = fopen(sub_path[i],"rb");
        for (int j = 0; j < sub_file_size; j++) {
            fputc(fgetc(fpr),fpw);
        }
        fclose(fpr);
    }

    //关闭文件
    fclose(fpw);
    //释放内存
    for (int i = 0; i < num; i++) {
        free(sub_path[i]);
    }
    free(sub_path);
    (*env)->ReleaseStringChars(env, path, file_path);
    (*env)->ReleaseStringChars(env, pattern, pattern_str);
}

/**
 * 关闭文件
 * @param p
 */
void free_pointer(FILE *p) {
    fclose(p);
}
