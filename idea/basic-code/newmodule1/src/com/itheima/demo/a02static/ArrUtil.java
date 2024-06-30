package com.itheima.demo.a02static;

public class ArrUtil {

    private ArrUtil() {}

    public static String printArr(int[] arr) {
        StringBuilder sb = new StringBuilder();

        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i != arr.length - 1) {
                sb.append(arr[i]).append(", ");
            }
            else sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    public static double getAverage(double[] arr)
    {
        double sum = 0;
        for (double j : arr) {
            sum += j;
        }
        return sum / arr.length;
    }

    public static int getAverage(int[] arr)
    {
        int sum = 0;
        for (int j : arr) {
            sum += j;
        }
        return sum;
    }

}
