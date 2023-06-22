class Solution {
public:
    int FEE;
    int dp[50001][2];
    int solve(vector<int>& prices,int n, int day,bool buy){
        if(day>=n){
            return 0;
        }
        int profit = 0;
        if(dp[day][buy]!=-1){
            return dp[day][buy];
        }
        if(buy){
            int buy_today = solve(prices,n,day+1,false) - prices[day]; // this one is for buying today 
            int buy_next_day = solve(prices,n,day+1,true); // this is for buying next day
            profit = max({profit,buy_today,buy_next_day});
        } else{
            int sell_today = solve(prices,n,day+1,true) + prices[day] - FEE; // sell today and pay the fees from profit
            int sell_next_day = solve(prices,n,day+1,false); // sell next_day 
            profit = max({profit,sell_today,sell_next_day});
        }
        return dp[day][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        FEE = fee;
        memset(dp,-1,sizeof(dp));
        bool buy = true;
        return solve(prices,n,0,buy);
    }
};
