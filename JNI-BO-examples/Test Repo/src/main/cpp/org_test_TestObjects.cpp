#include "org_test_TestObjects.h"
#include "org_test_impl_Employee.h"
#include <iostream>

JNIEXPORT jobject JNICALL Java_org_test_TestObjects_createUser
  (JNIEnv *env, jobject thisObject, jstring name, jdouble balance){

    jclass userDataClass = env->FindClass("org/test/UserObject");
    jobject newUserData = env->AllocObject(userDataClass);

    jfieldID nameField = env->GetFieldID(userDataClass , "name", "Ljava/lang/String;");
    jfieldID balanceField = env->GetFieldID(userDataClass , "balance", "D");

    env->SetObjectField(newUserData, nameField, name);
    env->SetDoubleField(newUserData, balanceField, balance);

//    char * nativeString;
//    const char * _nativeString = env->GetStringUTFChars(name, 0);
//    nativeString = strdup(_nativeString);
//    env->ReleaseStringUTFChars(nameStr, _nativeString);
//
//    char buffer[10];
//    strcpy(buffer, nativeString);

    return newUserData;
}

JNIEXPORT jstring JNICALL Java_org_test_TestObjects_printUserData
  (JNIEnv *env, jobject thisObject, jobject userData){

  	jclass userDataClass = env->GetObjectClass(userData);
  	jmethodID methodId = env->GetMethodID(userDataClass, "getUserInfo", "()Ljava/lang/String;");

    jstring result = (jstring)env->CallObjectMethod(userData, methodId);

    std::cout << "C++: User data is: " << env->GetStringUTFChars(result, NULL) << std::endl;

    return result;
}

//JNIEXPORT jobject JNICALL Java_org_test_TestObjects_createUser
//  (JNIEnv *env, jobject thisObject, jstring name, jdouble balance){
//
//    jclass userDataClass = env->FindClass("org/test/UserObject");
//    jobject newUserData = env->AllocObject(userDataClass);
//
//    jfieldID nameField = env->GetFieldID(userDataClass , "name", "Ljava/lang/String;");
//    jfieldID balanceField = env->GetFieldID(userDataClass , "balance", "D");
//
//    env->SetObjectField(newUserData, nameField, name);
//    env->SetDoubleField(newUserData, balanceField, balance);
//
//    int nameVerified = verifyName(name, env);
//
//    return newUserData;
//}
//
//JNIEXPORT jstring JNICALL Java_org_test_TestObjects_printUserData
//  (JNIEnv *env, jobject thisObject, jobject userData){
//
//  	jclass userDataClass = env->GetObjectClass(userData);
//  	jmethodID methodId = env->GetMethodID(userDataClass, "getUserInfo", "()Ljava/lang/String;");
//
//    jstring result = (jstring)env->CallObjectMethod(userData, methodId);
//
//    char * nativeString;
//    const char * _nativeString = env->GetStringUTFChars(result, 0);
//    nativeString = strdup(_nativeString);
//    env->ReleaseStringUTFChars(nameStr, _nativeString);
//
//    char buffer[10];
//    strcpy(buffer, nativeString);
//
//    std::cout << "C++: User data is: " << env->GetStringUTFChars(result, NULL) << std::endl;
//
//    return result;
//}

