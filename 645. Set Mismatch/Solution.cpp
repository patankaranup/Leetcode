class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        int duplicate = -1;
        int missing   = -1;
        
        for(int i = 0; i<n; i++) {
            int num = abs(nums[i]);
            if(nums[num-1] < 0) duplicate = num;
            else nums[num-1] *= (-1);
        }
        
        for(int i = 0; i<n; i++) {
            if(nums[i] > 0) {
                missing = i+1;
                break;
            }
        }
        return {duplicate, missing};
    }
};