package com.itheima.demo.ArrayList;

import java.util.ArrayList;

public class ArrayListSample1 {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        // 使用包装类Integer而不是int  ArrayList不能存储基本数据类型 只能存储引用数据类型 byte-Byte, char-Character ...

        list.add(1);
        list.add(2);
        list.add(3);
        list.add(4);
        list.add(5);


        System.out.print("[");
        for (int i = 0; i < list.size(); i++) {
            if (i != list.size() - 1) {
                System.out.print(list.get(i) + ", ");
            }
            else System.out.print(list.get(i));
        }
        System.out.println("]");





    }
}
