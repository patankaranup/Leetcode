class Solution {
public:
    int memo[59];
    int solve(int n){
        if(n==1){
            return 1;
        }
        if(memo[n] != -1){
            return memo[n];
        }
        int result = 0;
        int product = 1;
        for(int i=1; i<=n-1; i++){
            product = i * max(n-i, solve(n-i));
            result = max(product,result);
        }
        return memo[n] = result;
    }
    int integerBreak(int n) {
        memset(memo,-1,sizeof(memo));
        return solve(n);
    }
};