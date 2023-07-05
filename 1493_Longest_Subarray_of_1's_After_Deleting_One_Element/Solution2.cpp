class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int last_zero_idx = -1;
        int maxLen = 0;
        while(j<nums.size()){
            if(nums[j] == 0){
                i = last_zero_idx + 1;
                last_zero_idx = j;
            }
            maxLen = max(maxLen,j-i);
            j++;
        }
        return maxLen;
    }
};