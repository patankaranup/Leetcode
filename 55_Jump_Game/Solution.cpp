class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n  = nums.size();
        int max_reach = 0;

        for (int i =0 ; i<n; i++){
            if (i > max_reach) {
                return false;
            }
            max_reach = max(nums[i]+i, max_reach);
        }
        return true;
        
    }
};
