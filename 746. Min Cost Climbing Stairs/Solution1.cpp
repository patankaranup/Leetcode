class Solution {
public:
    int n;
    int memo[1001];
    int solve(int idx, vector<int>& cost){
        if(idx>=n){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }
        int take_1_step = solve(idx+1,cost) + cost[idx];
        int take_2_step = solve(idx+2,cost) + cost[idx];
        return memo[idx] = min(take_1_step,take_2_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        memset(memo,-1,sizeof(memo));
        return min(solve(0,cost),solve(1,cost));
    }
};
