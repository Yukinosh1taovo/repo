package com.itheima.oop.Polymorphism01;

// 成员变量 ： 编译看左边 运行看左边
// 成员方法 ： 编译看左边 运行看右边

// 多态的弊端   不能调用子类的特有方法
// 解决方法    转换为子类对象

class Animal {
    public int age = 3;
    public void eat()
    {
        System.out.println("动物在吃东西");
    }
}

class Dog extends Animal{
    public int age = 8;
    @Override
    public void eat()
    {
        System.out.println("狗在吃东西");
    }

    public void lookHome(){
        System.out.println("狗在看家");
    }
}

public class Test {
    public static void main(String[] args) {
        Animal a = new Dog();
        System.out.println(a.age); // 成员变量 编译看左边 检查Animal类中是否有age变量 然后运行看左边 输出父类的age变量 结果为 3
        a.eat(); // 成员方法 编译看左边 检查Animal类中是否有eat()方法 然后运行看右边 运行子类对象重写的eat()方法 输出结果为"狗在吃东西"
        // a.lookHome(); 无法执行 编译时父类不存在该子类独有的方法

        Dog d = (Dog) a;
        d.lookHome(); //调用成功
    }
}
