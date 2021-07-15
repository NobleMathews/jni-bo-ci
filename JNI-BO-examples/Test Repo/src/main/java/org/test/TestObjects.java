/*
 * Copyright (c) 2021, WSO2 Inc. (http://www.wso2.org) All Rights Reserved.
 *
 * WSO2 Inc. licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */
package org.test;

import org.test.api.Person;

public class TestObjects {

    static private String gl_name = "Global John Doe";


    static {
        System.loadLibrary("native");
    }

    static void foo(String a) {
        String f = a;
    }

    public native String printUserData(UserObject user);

    public native UserObject createUser(String userName, double balance);

    public static void main(String[] args) {
        TestObjects instance = new TestObjects();
        String name = "John Doe";
        String otherName = name;
        otherName = name;
        double salary = 450.67;

        instance.createUser(otherName, salary);
        instance.createUser("Some Name", 670.432);
        UserObject userObject = instance.createUser(gl_name, salary);
        instance.printUserData(userObject);
        foo("Test");
    }

    private static boolean verifyPersonInfo(Person person){
        String firstNameToSet = "Sam";
        String lastNameToSet = "Jason";
        person.setName(firstNameToSet, lastNameToSet);

        int idToSet = 2345;
        person.setId(idToSet);

        return true;
    }
}
