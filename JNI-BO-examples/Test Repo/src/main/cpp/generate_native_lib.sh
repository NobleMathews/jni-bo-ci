javac -h . ../java/org/test/*.java ../java/org/test/api/*.java ../java/org/test/impl/*.java
# Remember to set your JAVA_HOME env var
g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin org_test_TestObjects.cpp -o org_test_TestObjects.o
g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin org_test_TestParameters.cpp -o org_test_TestParameters.o
g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin org_test_impl_Employee.cpp -o org_test_impl_Employee.o
g++ -c -fPIC -I${JAVA_HOME}/include -I${JAVA_HOME}/include/darwin org_test_impl_Student.cpp -o org_test_impl_Student.o
g++ -dynamiclib -o ../../../native/macos/libnative.dylib org_test_TestObjects.o org_test_TestParameters.o org_test_impl_Employee.o org_test_impl_Student.o -lc