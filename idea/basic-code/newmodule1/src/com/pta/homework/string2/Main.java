package com.pta.homework.string2;

import java.util.Scanner;

public class Main {

    static int[] josephus1(int n, int m, int k,boolean[] twins) {
        int a = 0;
        for (boolean b : twins) {
            if (b) a++;
        }
        int[] result = new int[n + a];
        int j = 0;

        boolean[] isSelected = new boolean[n + 1];
        int count = 0;
        int t = 0;

        isSelected[k] = true;
        result[j++] = k;
        count++;
        if (twins[k]) {
            result[j++] = k;
            count++;
        }
        while(count < n) {
            if(!isSelected[k]) t++;
            if(t == m) {
                result[j++] = k;
                isSelected[k] = true;
                t = 0;
                count++;
                if(twins[k]) {
                    result[j++] = k;
                    count++;
                }
            }
            k++;
            if(k > n) k = 1;
        }

        return result;

    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String[] split = s.split("\\s+");
        int enrollment = Integer.valueOf(split[0]);
        int admissions = Integer.valueOf(split[1]);
        String schoolCode = split[2].substring(0, 3);
        int first = Integer.valueOf(split[2].substring(3));
        int interval = Integer.valueOf(split[3]);
        String s1 = scanner.nextLine();
        String[] split2 = s1.split("\\s+");
        boolean[] isTwins = new boolean[enrollment + 1];
        if (!split2[0].equals("0")) {
            for (String str : split2) {
                int i = Integer.valueOf(str.substring(3));
                isTwins[i] = true;
            }
        }
        int[] result = josephus1(enrollment, interval, first, isTwins);
        for (int i = 0; i < admissions; i++) {
            System.out.println(schoolCode + String.format("%04d", result[i]));
        }
    }
}



