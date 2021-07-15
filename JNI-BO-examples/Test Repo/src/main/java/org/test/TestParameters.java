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

public class TestParameters {
    static {
        System.loadLibrary("native");
    }

    public native long sumIntegers(int first, int second);

    public native String sayHelloToMe(String name, boolean isFemale);

    public static void main(String[] args) {
        TestParameters instance = new TestParameters();
        String name = "John";
        boolean isFemale = false;
        String hello = instance.sayHelloToMe(name, isFemale);
        System.out.println("Java: My full name: " + hello);

        int val1 = 456;
        int val2 = 44;
        long sumFromNative = instance.sumIntegers(val1, val2);
        System.out.println("Java: The sum coming from native code is: " + sumFromNative);
    }

}
