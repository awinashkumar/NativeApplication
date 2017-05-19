//
// Created by Awinash on 22-12-2016.
//

#include <android/log.h>
#include <jni.h>
#include <stddef.h>

jdoubleArray Java_com_example_test_mynativeapplication_MainActivity_sumAbdAverage(
        JNIEnv *env,
        jobject obj,
        jintArray inJNIArray){

    // Step 1: Convert the incoming JNI jintarray to C's jint[]
    jint *inCArray = (*env)->GetIntArrayElements(env,inJNIArray,NULL);
    if(NULL == inCArray)
        return NULL;

    jsize length = (*env)->GetArrayLength(env,inJNIArray);

    // Step 2: Perform its intended operations
    jint sum = 0;
    for(int i= 0; i <length; i++){
        sum += inCArray[i];
    }

    jdouble average = (jdouble) sum / length;

    // release resources
    (*env)->ReleaseFloatArrayElements(env,inJNIArray,inCArray,0);

    jdouble outArray[] = {sum,average};

    // Step 3: Convert the C's Native jdouble[] to JNI jdoublearray, and return
    jdoubleArray outJNIArray = (*env)->NewDoubleArray(env,2); // allocate
    if(NULL == outArray)
        return NULL;

    (*env)->SetDoubleArrayRegion(env,outJNIArray,0,2,outArray); //copy

    return outJNIArray;




}

JNIEXPORT void JNICALL
Java_com_example_test_mynativeapplication_MainActivity_staticMethod(JNIEnv *env, jobject instance) {

    // TODO

}

JNIEXPORT jint JNICALL
Java_com_example_test_mynativeapplication_MainActivity_getFactorial(JNIEnv *env, jobject instance,
                                                                    jint number) {

    jint fact = 1;

    for(int i=1;i<=number;i++)
    {
        fact=fact*i;
    }

    return fact;
}