class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        vector<int> dp(n,1);
        vector<int> prev_idx(n,-1);
        int last_taken_idx = 0;
        int maxi_len = 1;
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        prev_idx[i] = j;
                    }
                    if(dp[i]>maxi_len){
                        maxi_len = dp[i];
                        last_taken_idx = i;
                    }
                }
            }
        }
        vector<int> res;
        while(last_taken_idx != -1){
            res.push_back(nums[last_taken_idx]);
            last_taken_idx = prev_idx[last_taken_idx];
        }
        return res;
    }
};