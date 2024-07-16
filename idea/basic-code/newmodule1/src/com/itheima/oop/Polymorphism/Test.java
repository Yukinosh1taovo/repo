package com.itheima.oop.Polymorphism;

public class Test {
    public static void main(String[] args) {

        Student s = new Student();
        s.setName("张三");
        s.setAge(18);

        Teacher t = new Teacher();
        t.setAge(30);
        t.setName("王");

        Administrator admin = new Administrator();
        admin.setAge(35);
        admin.setName("管理员");



        // 多态体现 同一个方法可以输入不同类型的参数
        register(s);
        register(t);
        register(admin);


    }

    public static void register(Person p){
        p.show();
    }
}
