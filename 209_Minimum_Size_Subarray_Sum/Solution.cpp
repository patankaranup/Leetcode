class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int min_len = INT_MAX;
        while(j<n){
            sum += nums[j];
            // if found the sum which is greater or equal to target try to make the len smaller 
            while(sum>=target){
                min_len = min(min_len,(j-i+1));
                sum -= nums[i];
                i++;
            } 
            j++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};
