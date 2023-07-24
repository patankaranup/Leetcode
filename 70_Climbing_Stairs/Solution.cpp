class Solution {
public:
    int memo[46];
    int solve(int n){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(memo[n]!=-1){
            return memo[n];
        }
        int take1Step = solve(n-1);
        int take2Steps = solve(n-2);
        return memo[n] = take1Step + take2Steps;
    }
    int climbStairs(int n) {
        memset(memo,-1,sizeof(memo));
        return solve(n);
    }
};