package com.itheima.demo.Extends;

// Java中只能单继承：一个子类只能继承一个父类  不能多继承  能多重继承  分为直接父类和间接父类
public class Animal {  // 无继承默认继承Object类

    // 子类只能访问父类非私有的成员

    public void eat()
    {
        System.out.println("吃");
    }
    public void drink()
    {
        System.out.println("喝");
    }

}
