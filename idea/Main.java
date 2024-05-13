import java.util.Scanner;

public class Main {
    class Solution {
        public void moveZeroes(int[] nums) {

            int l = 0, r = 0;
            while (r < nums.length))
            {
                while (nums[r] == 0) r++;

                nums[l] = nums[r];
                l++;
                r++;

            }
            while (l < nums.length))   nums[l] = 0;



        }
    }
}