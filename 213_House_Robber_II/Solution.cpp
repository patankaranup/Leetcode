class Solution {
public:
    int n;
    int memo[101];
    int solve(vector<int>& nums,int start_idx,int last_idx){
        if(start_idx>last_idx){
            return 0;
        }
        if(memo[start_idx] != -1){
            return memo[start_idx];
        }
        // for this revisit house robber 1
        int take_House = nums[start_idx] + solve(nums,start_idx+2,last_idx);
        int skip_House = solve(nums,start_idx+1,last_idx);

        return memo[start_idx] = max(take_House,skip_House);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1){
            return nums[0];
        }
        // if we take 1st house we cannot take last house because it is circularly adjacent 
        memset(memo,-1,sizeof(memo));
        int take_1st_House = solve(nums,0,n-2);
        // if we skip 1st house we can take last house because it will not be circularly adjacent
        memset(memo,-1,sizeof(memo));
        int skip_1st_House = solve(nums,1,n-1);
        return max(take_1st_House,skip_1st_House);
    }
};