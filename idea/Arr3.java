import java.util.Scanner;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Arr3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        double[] arr = new double[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextDouble();

        double[] _max = new double[n];
        double[] _min = new double[n];

        _max[n - 1] = arr[n - 1];
        _min[0] = arr[0];

        for (int i = 1; i < n; i++)
        {
            _max[n - i - 1] = max(_max[n - i], arr[n - i - 1]);
            _min[i] = min(_min[i - 1], arr[i]);
        }

        for (double num : _max)
            System.out.print(num + " ");
        System.out.print("\n");

        for (double num : _min)
            System.out.print(num + " ");
        System.out.print("\n");

        double ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans = max(_max[i + 1] - _min[i], ans);
        }

        System.out.print(ans);  // 时间复杂度O(n) 空间复杂度O(n)


    }
}
