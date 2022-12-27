class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] res = new int[2*n];

        int left = 0;
        int right = left+n;

        for (int i = 0; i<nums.length; i= i+2){
            res[i] = nums[left];
            res[i+1] = nums[right];
            left++;
            right= left+n;
        }
        return res;

        

        
    }
}
