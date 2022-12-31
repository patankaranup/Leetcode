class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] res = new int[nums.length];
        for (int i = 0; i <nums.length;i++){
            for (int j = 0; j<nums.lenght;j++){
                if (nums[i]>nums[j]){
                    res[i] +=1;
                }
            }
        }
        return res;
        
    }
}
