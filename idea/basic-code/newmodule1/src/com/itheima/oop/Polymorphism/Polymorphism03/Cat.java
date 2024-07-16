package com.itheima.oop.Polymorphism.Polymorphism03;

public class Cat extends Animal{

    public Cat() {
    }

    public Cat(int age, String color) {
        super(age, color);
    }

    @Override
    public void eat(String something){
        System.out.println(getAge() + "岁的" + getColor() + "颜色的猫咪吃鱼");
    }

    public void catchMouse(){
        System.out.println("猫抓老鼠");
    }
}
