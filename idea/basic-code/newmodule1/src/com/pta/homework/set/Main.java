package com.pta.homework.set;

import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        int n = S.length();
        int totalSum = 0;


        Set<String> uniqueSubstrings = new HashSet<>();


        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                String substring = S.substring(i, j + 1);
                if (!uniqueSubstrings.contains(substring)) {
                    uniqueSubstrings.add(substring);
                    Set<Character> uniqueChars = new HashSet<>();
                    for (char c : substring.toCharArray()) {
                        uniqueChars.add(c);
                    }
                    totalSum += uniqueChars.size();
                }
            }
        }

        System.out.println(totalSum);
    }
}
