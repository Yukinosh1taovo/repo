package com.itheima.basic.String;

import java.util.Scanner;

public class StringSample {

    public static void main(String[] args) {


        String s1 = "abc"; // 直接赋值 存储在堆的串池当中

        String s2 = new String("abc"); // 使用new赋值 存储在堆中

        byte[] bytes3 = {97, 98, 99};

        String s3 = new String(bytes3); // String s = new String(byte[] s);  将数字按照ascii码表转为字符再赋值

        char[] chars4 = {'a', 'b', 'c'};

        String s4 = new String(chars4); // String s = new String(char[] s);

        String s5 = "abc";

        System.out.println(s1);
        System.out.println(s2);
        System.out.println(s3);
        System.out.println(s4);

        System.out.println(s1 == s2); // == 比较地址
        System.out.println(s1 == s5); // 在串池的相同字符串 地址相同

        System.out.println(s1.equals(s2)); // boolean equals(String s) 比较两个字符串是否一致
        s1 = "Abc";
        System.out.println(s1.equalsIgnoreCase(s2)); // boolean equalsIgnoreCase(String s) // 忽略大小写比较

        Scanner sc = new Scanner(System.in);
        String s = sc.next();  // next()结果为new创建的 存储在堆中




    }

}
