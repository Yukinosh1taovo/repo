package com.itheima.algorithm;

import java.util.ArrayList;

public class Search {
    public static void main(String[] args) {
    int[] arr = {131, 127, 147, 81, 103, 23, 7, 79, 81};
    int num = 81;
        System.out.println(basicSearch(arr, num));

    }

    public static ArrayList<Integer> basicSearch(int[] arr, int num){

        ArrayList<Integer> res = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num){
                res.add(i);
            }
        }
        return res;
    }

}
