import java.util.Arrays;
import java.util.Scanner;

public class vector {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)     arr[i] = sc.nextInt();

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= 75)
            {
                int pre = i;
                while (i < n && arr[i] >= 75)
                {
                    i++;
                }
                if (i - pre >= 3)
                {
                    ans++;
                }
            }

        }
    System.out.println(ans);


    }
}
