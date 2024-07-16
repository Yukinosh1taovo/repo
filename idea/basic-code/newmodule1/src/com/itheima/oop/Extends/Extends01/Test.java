package com.itheima.oop.Extends.Extends01;

public class Test
{
    public static void main(String[] args) {
        RagDoll cat1 = new RagDoll();

        cat1.eat(); // 间接父类方法
        cat1.drink();
        cat1.catchMouse(); // 直接父类方法
    }
}
