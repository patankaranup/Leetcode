import java.util.*;

class Solution {
    public int[] sortedSquares(int[] nums) {
        int length = nums.length;
        int[] result = new int[length];
        int begin = 0;
        int end = length-1;
        int i = length-1;
        while (i>=0){
            if (nums[begin]*nums[begin] > nums[end]*nums[end]) {
                result[i] = (nums[begin]*nums[begin]);
                begin+=1;
                i--;
            }
            else{
                result[i] = (nums[end]*nums[end]);
            
                end-=1;
                i--;

            }
                
        }
        return result;

    }
}