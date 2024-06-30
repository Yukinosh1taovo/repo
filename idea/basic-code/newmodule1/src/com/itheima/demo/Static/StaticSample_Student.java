package com.itheima.demo.Static;

// 静态方法只能访问静态变量和静态方法 (静态方法中，只能访问静态)

// 非静态方法可以访问静态变量或者静态方法，也可以访问非静态的成员变量和非静态的成员方法 (非静态方法可以访问所有)

// 静态方法中没有this关键字

public class StaticSample_Student {
    String name;
    int age;
    static String teacherName; // 静态成员变量

    public void show1()  // 非静态方法 有隐藏的this

    {
        System.out.println(name + ", " + age + ", " + teacherName);
    }

//  非静态方法 有隐藏的this      调用时将对象的地址值赋值给this
/*
        public void show1(StaticSample_Student this)
        {
            System.out.println(this.name + ", " + this.age + ", " + teacherName);
        }
*/

    public static void staticMethod() // 静态方法
    {
        System.out.println("静态方法");
        System.out.println(teacherName);
        // System.out.println(this.name);  无法访问 报错
        // this.show1(); 无法访问 报错
    }


}
