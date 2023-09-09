class Solution {
public:
    int n;
    int memo[201][1001];
    int solve(int idx,vector<int>& nums,int target){
        if(target == 0){
            return 1;
        }
        if(idx>=n || target < 0){
            return 0;
        }
        if(memo[idx][target] != -1){
            return memo[idx][target];
        }
        int take = solve(0,nums,target-nums[idx]);
        int skip = solve(idx+1,nums,target);
        return memo[idx][target] = take+skip;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(0,nums,target);
    }
};