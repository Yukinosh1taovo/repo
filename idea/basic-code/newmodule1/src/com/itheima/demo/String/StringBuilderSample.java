package com.itheima.demo.String;

public class StringBuilderSample {
    public static void main(String[] args) {

        // StingBuilder 为一个可变的操作字符串的容器 可以高效的拼接字符串
        // String 内容不可变 拼接内存效率低   StringBuilder StringJoiner 内容可变 拼接内存效率高

        /*
        *   使用StringBuilder场景：
        *      1. 字符串的拼接
        *      2. 字符串的反转
        * */

        StringBuilder sb = new StringBuilder("abc"); // StringBuilder sb = new StringBuilder(String s);
        // StringBuilder 不可直接赋值

        sb.append("aaa");
        sb.append(124);
        sb.append("1.234");
        System.out.println(sb);

        sb.reverse();
        System.out.println(sb);
        System.out.println(sb.length());

        String s = sb.toString(); // 转为String 使用Sting方法 substring replace
    }

    public static String StringBuilderAppend() {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < 10000; i++) {
            sb.append("abc");
        }
        return sb.toString();

    }
}
