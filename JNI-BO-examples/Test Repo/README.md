# jni-example
An example JNI project

# How to run
- Navigate to src/main/cpp and execute the generate_native_lib.sh script. This will generate header files for native methods
- Add/modify the relevant cpp files and implement the logic
- Navigate to the root of the project and build using mvn (`mvn clean install`)
- Execute the project as `java -cp target/test-project-1.0-SNAPSHOT.jar -Djava.library.path=native/macos/ org.test.TestObjects`
