package com.itheima.demo.Static;

public class Test {
    public static void main(String[] args) {

        StaticSample_Student.teacherName = "Sensei";

        StaticSample_Student stu1 = new StaticSample_Student();
        stu1.name = "张三";
        stu1.age = 24;

        stu1.show1();

        StaticSample_Student.staticMethod();



    }
}
