package com.itheima.oop.Interface.Interface02;

public interface Inter1 {
    public abstract void method1();
    public abstract void method2();
    public abstract void method3();


    // default方法与别的接口同名且同时被一个实现类实现时必须被重写
    public default void method5(){
        System.out.println("Inter1中的default method5方法");
    };

    // static方法不能被实现类重写
    public static void method6(){
        System.out.println("Inter1中的static method6方法");
    }

    private void method(){
        // 记录一些本接口中使用的重复代码
    }

    private static void show(){
        // 记录一些本接口静态方法中使用的重复代码
    }

}
