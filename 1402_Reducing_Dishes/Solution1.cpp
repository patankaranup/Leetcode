class Solution1 {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(begin(satisfaction),end(satisfaction));
        int n = satisfaction.size();
        vector<vector<long long>> dp (501, vector<long long>(501,INT_MIN));
        // t[i][j] max value for 0 to ... i food and time is curently j
        // at time 0 we have no value 
        for(int i=0; i<501; i++){
            dp[i][0] = 0;
        }
        // cooking started at time 1 and with the 0th food t[0][1]
        dp[0][1] = satisfaction[0]*1;

        for(int i=1; i<n; i++){
            for(int time = 1; time<=n; time++){
                long long include = satisfaction[i]*time + dp[i-1][time-1];
                long long exclude = dp[i-1][time];

                dp[i][time] = max(include,exclude);
            }
        }
        // we need to return the maximum value from 0 to n-1 food i.e last row 
        long long ans = 0;
        for(int time = 1; time<=n; time++){
            ans = max(ans, dp[n-1][time]);
        }
        return ans;
    }
};