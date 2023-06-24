class Solution {
public:
    int n;
    int dp[21][10003];
    int solve(vector<int>& rods, int idx, int diff){
        if(idx>=n){
            if(diff==0){
                return 0;
            } 
            return INT_MIN;
        }
        if(dp[idx][diff + 5000] != -1){ 
            return dp[idx][diff + 5000];
        }
        int no_rod = solve(rods,idx+1,diff);
        int add_to_len1 = rods[idx] + solve(rods,idx+1,diff+rods[idx]);
        int add_to_len2 = rods[idx] + solve(rods,idx+1,diff-rods[idx]);

        return dp[idx][diff + 5000] = max({no_rod,add_to_len1,add_to_len2});
    }
    int tallestBillboard(vector<int>& rods) {
        n = rods.size();    
        memset(dp,-1,sizeof(dp));
        return solve(rods,0,0)/2;
    }
};
