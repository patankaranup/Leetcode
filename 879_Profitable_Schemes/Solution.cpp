class Solution {
public:
    const int MOD = 1e9+7;
    int N;
    int memo[101][101][101];
    int solve(int idx, int curProfit, int people, vector<int>& group, vector<int>& profit, int &minProfit){
        if(people > N){
            return 0;
        }
        if( idx == group.size()){
            if(curProfit >=minProfit){
                return memo[idx][curProfit][people] = 1;
            } else {
                return memo[idx][curProfit][people] = 0;
            }
        }
        if(memo[idx][curProfit][people] != -1){
            return memo[idx][curProfit][people];
        }
        long long not_taken = solve(idx+1,curProfit,people,group,profit,minProfit)%MOD;
        long long taken = solve(idx+1,min(curProfit+profit[idx],minProfit),people+group[idx],group,profit,minProfit)%MOD;
        return memo[idx][curProfit][people] = (not_taken%MOD + taken%MOD)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N = n;
        memset(memo,-1,sizeof(memo));
        return solve(0, 0, 0, group, profit, minProfit);
    }
};