package com.itheima.oop.Static.Static02;

import java.util.ArrayList;

public class StudentClassProblem {
    public static void main(String[] args) {

        ArrayList<Student> list = new ArrayList<>();

        Student stu1 = new Student("zhangsan", 23, "男");
        Student stu2 = new Student("zhangsan", 24, "女");
        Student stu3 = new Student("zhangsan", 25, "男");


        list.add(stu1);
        list.add(stu2);
        list.add(stu3);

        int maxAge = StudentUtil.getMaxAverageStudent(list);
        System.out.println(maxAge);
    }
}
