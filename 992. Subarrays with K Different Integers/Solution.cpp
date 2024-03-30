class Solution {
public:
    // retues total count of subarrays where we having <= k distinct numbers 
    int slidingWindow(vector<int> &nums, int k){ 
        int result = 0;
        int i=0, j=0;
        unordered_map<int, int> mp;
        int n = nums.size();
        while(j<n){
            mp[nums[j ]]++;
            while(mp.size() > k){
                // shrink the window from left side using i pointer 
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]); 
                }
                i++;
            }
            // all subarrays ending at j pointer  
            result += (j-i+1);
            j++;
        }
        return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums,k) - slidingWindow(nums,--k);
    }
};