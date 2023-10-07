class Solution {
public:
    int N, M, K;
    int MOD = 1e9+7;
    int memo[51][51][101];
    
    int solve(int idx, int costForSearching, int maxSoFar){
        if(idx == N){
            if(costForSearching == K)
                return 1;
            return 0;
        }
        if(memo[idx][costForSearching][maxSoFar] != -1){
            return t[idx][costForSearching][maxSoFar];
        }
        int result = 0;
        for(int i = 1; i <= M; i++){
            if(i > maxSoFar){
                result = (result + solve(idx+1, costForSearching+1, i)) % MOD;
            } else{
                result = (result + solve(idx+1, costForSearching, maxSoFar)) % MOD;
            }   
        }
        return memo[idx][costForSearching][maxSoFar] = result % MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0);
    }
};

