class Solution1 {
public:
    const int MOD = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        // dices n and target is changing 
        int dp[n+1][target+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i=1; i<n+1; i++){
            for(int j=1; j<target+1; j++){
                // nothing new here copy paste from recursion solution with validations 
                int no_of_ways = 0;
                for(int face = 1; face <= k; face++){
                    if(face <= j){
                        no_of_ways = (dp[i][j]%MOD + dp[i-1][j-face]%MOD) %MOD;
                        dp[i][j] = no_of_ways;
                    }
                }
            }
        }
        return dp[n][target];
    }
};