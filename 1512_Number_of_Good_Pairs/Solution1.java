class Solution1 {
    public int numIdenticalPairs(int[] nums) {

        int result = 0;
        int[] temp = new int[101];

        for (int i=0; i <nums.length;i++){
            result+=temp[nums[i]];
            temp[nums[i]]++;
        }
        return result;
        
    }
}
