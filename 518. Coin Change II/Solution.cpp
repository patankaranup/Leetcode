class Solution {
public:
    int n;
    int memo[301][5001];
    int solve(int idx, int amount, vector<int>& coins){
        // amount 0 means we got 1 way
        if(amount == 0){
            return memo[idx][amount] = 1;
        }
        // if amount !equal to 0 and idx is out of bound return 0
        if(idx >= n || amount < 0){
            return 0;
        }
        if(memo[idx][amount] != -1){
            return memo[idx][amount];
        }
        // see whether we can take this coin or not and then call recursive function
        if(coins[idx]>amount){
            return memo[idx][amount] = solve(idx+1,amount,coins);
        }
        // simple take and skip code
        int take_coin = solve(idx,amount-coins[idx],coins); // if we take coin than we have to start with idx since we can take that coins infinite number of times

        int skip_coin = solve(idx+1, amount, coins); // if we skip coin than idx+1 and amount will be same for next recursion
        return memo[idx][amount] = take_coin + skip_coin;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        memset(memo,-1,sizeof(memo));
        return solve(0,amount,coins);
    }
};