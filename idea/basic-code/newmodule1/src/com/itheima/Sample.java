package com.itheima;

public class Sample {
    public static void main(String[] args) {
        System.out.println(Runtime.getRuntime().availableProcessors());
        System.out.println(Runtime.getRuntime().maxMemory()); // 能从系统中获取的总内存大小
        System.out.println(Runtime.getRuntime().totalMemory());// 已经从系统获取的总内存大小
        System.out.println(Runtime.getRuntime().freeMemory()); // 剩余内存大小

        Integer x = 10;
        int y = x;
    }
}
