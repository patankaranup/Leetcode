class Solution {
public:
    int n;
    long long recursion(int idx, vector<vector<int>>& questions,vector<long long> & dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        // long long  points = questions[idx][0];
        // long long  new_index = idx + questions[idx][1] +1;
        long long  taken = questions[idx][0] + recursion(idx + questions[idx][1] +1,questions, dp);
        long long  notTaken = recursion(idx+1,questions,dp);
        return dp[idx] = max(taken,notTaken);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        vector<long long> dp(n+1,-1);
        return recursion(0,questions,dp);
    }
};
