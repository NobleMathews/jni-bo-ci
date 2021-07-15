#include "org_test_TestParameters.h"
#include <iostream>
#include <string>

int someVal = 45;


JNIEXPORT jlong JNICALL Java_org_test_TestParameters_sumIntegers
  (JNIEnv* env, jobject thisObject, jint first, jint second){
    std::cout << "C++: The numbers received are : " << first << " and " << second << std::endl;
    return (long)first + (long)second;
}


JNIEXPORT jstring JNICALL Java_org_test_TestParameters_sayHelloToMe
  (JNIEnv* env, jobject thisObject, jstring name, jboolean isFemale){
    const char* nameCharPointer = env->GetStringUTFChars(name, NULL);
    std::cout << "C++: The string received is: " << nameCharPointer << std::endl;
    std::string title;
    if(isFemale){
        title = "Ms. ";
    }
    else{
        title = "Mr. ";
    }

    std::string fullName = title + nameCharPointer;
    return env->NewStringUTF(fullName.c_str());
}
