class Solution {
public:
    int n;
    int memo[101];
    int solve(vector<int>& nums, int idx){

        if(idx>=n){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }

        int steal_idx = nums[idx] + solve(nums,idx+2);
        int skip_idx = solve(nums,idx+1);

        return memo[idx] = max(steal_idx,skip_idx);

    }
    int rob(vector<int>& nums) {
        n = nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(nums,0);
    }
};