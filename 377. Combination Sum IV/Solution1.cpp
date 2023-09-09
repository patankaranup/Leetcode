class Solution1 {
public:
    int n;
    int memo[1001];
    int solve(vector<int>& nums, int target){
        if(target == 0){
            return 1;
        }
        if(target<0){
            return 0;
        }
        if(memo[target] != -1){
            return memo[target];
        }
        int result = 0;
        for(int i=0; i<n; i++){ 
            // here for loop will do the work of rejecting idx
            int take = solve(nums,target-nums[i]);
            result += take;
        }
        return memo[target] = result;
    }   
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(memo,-1,sizeof(memo));
        return solve(nums,target);
    }
};