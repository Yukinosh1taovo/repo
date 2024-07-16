package com.itheima.basic.ArrayList;

import java.util.ArrayList;

public class ArrayListSample {
    public static void main(String[] args) {

        // 集合使用

        ArrayList<String> list = new ArrayList<>();

        list.add("aaa");
        list.add("aaa");
        list.add("bbb");
        list.add("ccc");
        list.add("ddd");

        list.remove("aaa");

        list.remove(1);

        list.set(2, "eee");




        System.out.print("[");
        for (int i = 0; i < list.size(); i++) {  // ArrayList 的遍历
            if (i != list.size() - 1)
            {
                System.out.print(list.get(i) + ", ");
            }
            else
            {
                System.out.print(list.get(i));
            }
        }
        System.out.print("]");
    }
}
