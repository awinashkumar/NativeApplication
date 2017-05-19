//
// Created by Awinash on 15-04-2017.
//

#include <jni.h>
#include <stdio.h>
#include <android/log.h>

void Java_com_example_test_mynativeapplication_MainActivity_modifyInstanceVariable(
        JNIEnv *env, jobject thisObj){

    // Get a reference to this object's class
    jclass thisJclass = (*env)->GetObjectClass(env,thisObj);

    // Get the Field ID of the instance variables "number"
    jfieldID findNumber = (*env)->GetFieldID(env,thisJclass, "number","I");

    if(NULL == findNumber){
        return;
    }

    // Get the int given the Field ID
    jint number = (*env)->GetIntField(env, thisObj, findNumber);

    printf("In C, the int is %d\n", number);
    __android_log_print(ANDROID_LOG_DEBUG,"XYZ","print number = %d ",number);

    // Change the variable
    number = 425;
    (*env)->SetIntField(env,thisObj,findNumber,number);

    // Get the Field ID of the instance variables "message"
    jfieldID findMessage = (*env)->GetFieldID(env,thisJclass,"message", "Ljava/lang/String;");
    if (NULL == findMessage) return;

    // String
    // Get the object given the Field ID
    jstring message = (*env)->GetObjectField(env,thisObj,findMessage);

    // Create a C-string with the JNI String
    const char *cstr = (*env)->GetStringUTFChars(env,message,NULL);
    if(NULL == cstr)
        return;

    printf("In C, the string is %s\n", cstr);
    __android_log_print(ANDROID_LOG_DEBUG,"XYZ","print message = %s ",cstr);
    (*env)->ReleaseStringUTFChars(env, message, cstr);

    // Create a new C-string and assign to the JNI string
    message = (*env)->NewStringUTF(env, "Hello from C message");
    if (NULL == message) return;

    // modify the instance variables
    (*env)->SetObjectField(env, thisObj,findMessage, message);
}