package com.itheima.demo.String;

import java.util.StringJoiner;

public class StringJoinerSample {
    public static void main(String[] args) {

        // StringJoiner 为一个可变的操作字符串的容器 拼接时可以指定间隔符号 开始符号 结束符号

        StringJoiner sj = new StringJoiner(", ", "[", "]");
        sj.add("aaa").add("bbb").add("ccc");
        String s = sj.toString();
        System.out.println(s);

    }

}
