package com.itheima.oop.Interface.Interface01;

public class Frag extends Animal implements Swim{
    public Frag() {
    }

    public Frag(String name, int age) {
        super(name, age);
    }

    @Override
    public void eat() {
        System.out.println("青蛙在吃东西");
    }

    @Override
    public void swim(){
        System.out.println("青蛙在游泳");
    }


}
