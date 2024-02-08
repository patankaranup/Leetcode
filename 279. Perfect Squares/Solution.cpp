class Solution {
public:
    int memo[10001];
    int solve(int n){
        if(n == 0){
            return 0;
        }
        if(memo[n] != -1){
            return memo[n];
        }
        int mini = INT_MAX;
        for(int i=1; i*i<=n; i++){
            int result = 1 + solve(n-i*i);
            mini = min(mini,result);
        }
        return memo[n] = mini;
    }
    int numSquares(int n) {
        memset(memo,-1,sizeof(memo));
        return solve(n);
    }
};