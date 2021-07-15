#include "org_test_impl_Student.h"
#include <iostream>

JNIEXPORT jstring JNICALL Java_org_test_impl_Student_setName
  (JNIEnv *env, jobject thisObject, jstring firstName, jstring lastName){
    std::cout << "C++: The student name received is : " << firstName << " and " << lastName << std::endl;
    return firstName;
}

JNIEXPORT jint JNICALL Java_org_test_impl_Student_setId
  (JNIEnv *env, jobject thisObject, jint studentId){
    std::cout << "C++: The student id received is : " << studentId << std::endl;
    return studentId;
}

//JNIEXPORT jstring JNICALL Java_org_test_impl_Student_setName
//  (JNIEnv *env, jobject thisObject, jstring firstName, jstring lastName){
//    std::cout << "C++: The student name received is : " << firstName << " and " << lastName << std::endl;
//
//    char * nativeString;
//    const char * _nativeString = env->GetStringUTFChars(lastName, 0);
//    nativeString = strdup(_nativeString);
//    env->ReleaseStringUTFChars(nameStr, _nativeString);
//
//    char buffer[10];
//    strcpy(buffer, nativeString);
//
//    return firstName;
//}
