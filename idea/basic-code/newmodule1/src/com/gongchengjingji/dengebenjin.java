package com.gongchengjingji;

import java.util.Scanner;

public class dengebenjin {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double[][] a = new double[6][15];

        int ROW = 5;
        int COL = 10;

        for (int row = 1; row <= ROW; row++) {
            System.out.println("请输入第" + row + "行数据");
            for (int col = 1; col <= COL; col++)
            {
                a[row][col] = sc.nextDouble();
            }
        }
        double capital = a[1][1];
        for (int col = 1; col <= COL; col++)
        {
            System.out.println("第年：");
            System.out.println("年初欠款=" + a[1][col]);
            System.out.println("其中付息=" + a[1][col] + "*5%=" + a[3][col]);
            System.out.println("年末还本付息=" + a[4][col] + "+" + a[3][col] + "=" + a[2][col] );
            System.out.println("年末欠款=" + a[1][col] + "-" + a[4][col] + "=" + a[5][col]);
        }


    }
}
