#include "org_test_impl_Employee.h"
#include <iostream>
#include <cstring>


int verifyName(jstring nameStr, JNIEnv *env){
    char * nativeString;
    const char * _nativeString = env->GetStringUTFChars(nameStr, 0);
    nativeString = strdup(_nativeString);
    env->ReleaseStringUTFChars(nameStr, _nativeString);

    char buffer[10];
    strcpy(buffer, nativeString);

    int len = sizeof(buffer);

    if (len <= 10) {
        return 1;
    }

    return 0;
}

JNIEXPORT jstring JNICALL Java_org_test_impl_Employee_setName
  (JNIEnv *env, jobject thisObject, jstring firstName, jstring lastName){

    int verifiedFirstName = verifyName(firstName, env);
    int verifiedLastName = verifyName(lastName, env);

    return firstName;
}

JNIEXPORT jint JNICALL Java_org_test_impl_Employee_setId
  (JNIEnv *env, jobject thisObject, jint id){
    std::cout << "C++: The employee id received is : " << id << std::endl;
    return id;
}



//int verifyName(jstring nameStr, JNIEnv *env){
//    char * nativeString;
//    const char * _nativeString = env->GetStringUTFChars(nameStr, 0);
//    nativeString = strdup(_nativeString);
//    env->ReleaseStringUTFChars(nameStr, _nativeString);
//
//    char buffer[10];
//    strcpy(buffer, nativeString);
//
//    int len = sizeof(buffer);
//
//    if (len <= 10) {
//        return 1;
//    }
//
//    return 0;
//}

