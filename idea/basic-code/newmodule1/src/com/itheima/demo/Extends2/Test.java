package com.itheima.demo.Extends2;



// 构造方法  非private和private 子类都不能继承
// 成员变量  非private和private 子类都能继承  但是private情况下不能直接调用 需要使用get set方法
// 成员方法    private static final 不能继承(不会加载到虚方法表中)  其他能继承(加载到虚方法表中)

// 直接调用成员变量调用遵循就近原则 先局部后本类成员变量再父类成员变量  this从本类成员变量开始  super从父类成员变量开始


