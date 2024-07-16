package com.itheima.oop.Extends01;

public class Test2 {
    public static void main(String[] args) {

        Students stu1 = new Students();
        OverseasStudents stu2 = new OverseasStudents();

        stu1.lunch();
        stu2.lunch();

    }
}

class Person{

    public void eat()
    {
        System.out.println("吃米饭吃菜");
    }
    public void drink(){
        System.out.println("喝开水");
    }
}

class Students extends Person{

    public void lunch(){
        eat();
        drink();
    }
}

class OverseasStudents extends Person{

    @Override
    public void eat(){  // 当父类方法不能满足子类要求时 进行方法重写 重写后将会覆盖虚方法表中对应的方法
        System.out.println("吃西餐");
    }

    @Override
    public void drink(){
        System.out.println("喝凉水");
    }

    public void lunch()
    {
        this.eat(); // 调用重写方法
        this.drink();

        super.eat(); // 调用未重写的父类方法
        super.drink();

    }

}