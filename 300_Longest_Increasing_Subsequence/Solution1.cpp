class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Patience Sorting Algorithm 
        int n = nums.size();
        vector<int> sortedArray;
        for(int i=0; i<n; i++){
            // find element just greater than nums[i] 
            auto ptr = lower_bound(begin(sortedArray),end(sortedArray),nums[i]);
            if(ptr == end(sortedArray)){
                // we didnt found any grater element than this so add to sortedArray
                sortedArray.push_back(nums[i]);
            } else {
                *ptr = nums[i];
            }
        }
        return sortedArray.size();
    }
};