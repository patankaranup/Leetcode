class Solution {
public:
    int memo[38];
    int solve(int n){
        if(n<1){
            return 0;
        }
        if(n==1 || n==2){
            return 1;
        }
        if(memo[n] != -1){
            return memo[n];
        }
        int one   = solve(n-1);
        int two   = solve(n-2);
        int three = solve(n-3);
        return memo[n] = one+two+three;
    }
    int tribonacci(int n) {
        memset(memo, -1, sizeof(memo));
        return solve(n);
    }
};