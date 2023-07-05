class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int maxLen = 0;
        int i = 0; 
        for(int j = 0; j<nums.size(); j++){
            if(nums[j] == 0){
                zeroCount++;
            }
            while(zeroCount>1){
               if(nums[i] == 0){
                    zeroCount--;
               }
               i++;
            }
            maxLen = max(maxLen,j-i);
        }
        return maxLen;
    }
};