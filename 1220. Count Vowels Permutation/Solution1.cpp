class Solution1 {
public:
    int MOD = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;

    int countVowelPermutation(int n) {
        long long dp[5][n+1];
        dp[a][1] = 1;
        dp[e][1] = 1;
        dp[i][1] = 1;
        dp[o][1] = 1;
        dp[u][1] = 1;

        for(int len = 2; len <= n; len++){
            dp[a][len] = (dp[e][len-1] + dp[u][len-1] + dp[i][len-1]) % MOD;
            dp[e][len] = (dp[a][len-1] + dp[i][len-1]) % MOD;
            dp[i][len] = (dp[e][len-1] + dp[o][len-1]) % MOD;
            dp[o][len] = (dp[i][len-1]) % MOD;
            dp[u][len] = (dp[i][len-1] + dp[o][len-1]) % MOD;
        }

        long long ans = 0;
        for(int i=0; i<5; i++){
            ans = (ans + dp[i][n]) % MOD;
        }
        return ans;
    }
};
