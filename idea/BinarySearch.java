import java.util.Arrays;
import java.util.Scanner;

public class BinarySearch
{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int target = sc.nextInt();
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        Arrays.sort(arr);

        int l = -1, r = n;
        while (l + 1 != r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] >= target)
                r = mid;
            else
                l = mid;
        }
        if (arr[r] != target)
            System.out.println(-1);
        else
            System.out.println(r);
    }
}
