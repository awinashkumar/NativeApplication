//
// Created by Awinash on 22-12-2016.
//

#include <jni.h>
#include <string>
#include <android/log.h>

extern "C"
jint
Java_com_example_test_mynativeapplication_MainActivity_addFromJNI(
        JNIEnv *env,
        jobject /* this */, jint a, jint b) {
    jint result;
    printf("a = %d, b = %d \n", a,b);
    __android_log_print(ANDROID_LOG_DEBUG,"XYZ","print a = %d  b = %d",a,b);
    result = a + b;
    return result;
}

