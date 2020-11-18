package com.yihe;

import Demo.CalendarDemo;
import Demo.HttpRequest;
import sun.misc.OSEnvironment;

public class Main {

    public static void main(String[] args) {
//        InoutDemo inoutDemo = new InoutDemo();
//        inoutDemo.inputFromIn();
//        inoutDemo.print();
//        inoutDemo.testFormat();
//        try {
//            inoutDemo.testFile();
//        } catch (FileNotFoundException e) {
//
//        } catch (Exception e) {
//
//        }

//        ArraysDemo arraysDemo = new ArraysDemo();
//        for (int i = 0; i < 5; ++i)
//            arraysDemo.testRandomNumber();

//        OperatorDemo operatorDemo = new OperatorDemo();
//        operatorDemo.test();

//        CalendarDemo classDemo = new CalendarDemo();
////        classDemo.test();
//        classDemo.printCalendar();

        HttpRequest httpRequest = new HttpRequest();
        boolean suc = httpRequest.get("http://funshion-mipdx.cn.miaozhen.com/x/gif?m1a=41873501BA058AD97D73ADB707F1FA05&ns=36.102.208.154&type=ott");
        if (suc) {
            System.out.print(httpRequest.getResponseData());
        } else {
            System.out.printf("Error code %d", httpRequest.getCode());
        }
    }
}
