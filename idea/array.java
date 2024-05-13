import java.util.Scanner;

public class array {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)     arr[i] = sc.nextInt();

        for (int i = 0; i < n - 1; i++)
        {
            int max_index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[max_index])
                {
                    max_index = j;
                }
            }
            if (max_index != i) {
                int temp = arr[i];
                arr[i] = arr[max_index];
                arr[max_index] = temp;
            }
        }



        System.out.print("[");
        System.out.print(arr[0]);
        for (int i = 1; i < n; i++)
        {
            System.out.print(", " + arr[i]);
        }
        System.out.print("]");
        sc.close();
    }

}
