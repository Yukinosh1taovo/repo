package com.itheima.oop.Interface;

public class Test {
    public static void main(String[] args) {
        Frag f = new Frag("小青", 1);
        System.out.println(f.getName() + "," + f.getAge());
        f.eat();
        f.swim();

    }
}
