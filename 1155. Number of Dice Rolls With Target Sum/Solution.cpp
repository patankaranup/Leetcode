class Solution {
public:
    long long MOD = 1e9+7;
    int memo[31][1001];
    int solve(int dices, int faces, int target){
        if(dices == 0 && target == 0){
            return memo[dices][target] = 1;
        }
        if(target <= 0 || dices <= 0){
            return memo[dices][target] = 0;
        }
        if(memo[dices][target] != -1){
            return memo[dices][target];
        }
        int no_of_ways = 0;
        // no of faces on dices 
        for(int i=1; i<=faces; i++){
            if(target-i >= 0){
                no_of_ways = (no_of_ways + solve(dices-1,faces,target-i))%MOD;
            }
        }
        return memo[dices][target] = no_of_ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(memo, -1, sizeof(memo));
        return solve(n,k,target);
    }
};