package com.itheima.oop.Interface;

public class Rabbit extends Animal{

    public Rabbit() {
    }

    public Rabbit(String name, int age) {
        super(name, age);
    }

    @Override
    public void eat(){
        System.out.println("兔子在吃东西");
    }




}