package com.pta.homework;

class Animal {
    public Animal(){
        System.out.println("Animal ");
    }
}

class Dog extends Animal{
    public Dog()
    {
        System.out.println("Dog");
    }
}


public class Main {

    public static void main(String[] args) {
        Dog dog = new Dog();
        String s1 = "abcd";
        int[] arr = {1,2,3,4,5};
        System.out.println(s1.length());
        System.out.println(arr.length);
    }
}
