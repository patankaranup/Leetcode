class Solution {
public:
    const int MOD = 1e9+7;
    int memo[1001][1001];
    int solve(int n, int k){
        if(n==0){
            return 0;
        }
        if(k == 0){
            return 1;
        }
        if(memo[n][k] != -1){
            return memo[n][k];
        }
        int result = 0;
        for(int inv = 0; inv<=min(n-1,k); inv++){
            result = (result + solve(n-1,k-inv))%MOD;
        }
        return memo[n][k] = result;
    }
    int kInversePairs(int n, int k) {
        memset(memo,-1,sizeof(memo));
        return solve(n,k);
    }
};