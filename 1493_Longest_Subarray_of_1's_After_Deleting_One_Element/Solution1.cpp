class Solution {
public:
    int n;
    int findMax(vector<int>& nums, int idx){
        int currLen = 0;
        int maxLen = 0;
        for(int i=0; i<n; i++){
            if(i == idx){
                continue;
            }
            if(nums[i] == 1){
                currLen +=1;
                maxLen = max(currLen,maxLen);
            } else {
                currLen = 0; 
            }
        }
        return maxLen;
    }
    int longestSubarray(vector<int>& nums) {
        n = nums.size();
        int result = 0;
        bool zeroFound = false;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                zeroFound = true;
                result = max(result,findMax(nums,i));
            }
        }
        return zeroFound ? result : n-1;
    }
};