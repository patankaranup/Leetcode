class Solution {
public:
    int n;
    int memo[2501][2501];
    int solve(int curr_idx,int prev_idx, vector<int>& nums){
        if(curr_idx >= n){
            return 0;
        }
        if(prev_idx != -1 && memo[curr_idx][prev_idx] != -1){
            return memo[curr_idx][prev_idx];
        }
        // take 
        int take = 0;
        if(prev_idx == -1 || nums[curr_idx] > nums[prev_idx]){
            take = 1 + solve(curr_idx+1,curr_idx,nums);
        }
        // skip
        int skip = solve(curr_idx+1,prev_idx,nums);

        if(prev_idx != -1){
            memo[curr_idx][prev_idx] = max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(0,-1,nums);
    }
};