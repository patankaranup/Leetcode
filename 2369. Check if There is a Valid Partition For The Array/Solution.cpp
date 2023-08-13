class Solution {
public:
    int n;
    
    bool solve(int idx, vector<int>& nums, int memo[]){
        if(idx>=n){
            return true;
        }
        bool result = false;
        if(memo[idx] != -1){
            return memo[idx]; 
        }
        // condition 1 
        if(idx+1 < n && nums[idx] == nums[idx+1]){ 
            result = solve(idx+2,nums, memo);
        }
        if(result){
            return true;
        }
        // condition 2
        if(idx+2 < n && nums[idx] == nums[idx+1] && nums[idx+1] == nums[idx+2]){
            result = solve(idx+3,nums,memo);
        }
        if(result){
            return true;
        }
        // condition 3
        if(idx+2 < n &&(nums[idx+1] - nums[idx] == 1) && (nums[idx+2] - nums[idx+1] == 1)){
            result = solve(idx+3,nums,memo);
        }
        return memo[idx] = result;
    }
    bool validPartition(vector<int>& nums) {
        n = nums.size();
        int memo[n+1];
        memset(memo,-1,sizeof(memo));
        return solve(0,nums,memo);
    }
};
