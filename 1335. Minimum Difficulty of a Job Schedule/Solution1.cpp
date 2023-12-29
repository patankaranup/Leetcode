class Solution1 {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(d>n){
            return -1;
        }
        // dp[i][j] == min difficult of doing job from idx to n-1 in j number of days 
        int dp[n+1][d+1];
        memset(dp,-1,sizeof(dp));
        // see base case in recursion for this 
        for(int i=0; i<n; i++){
            // if only one day left then do all jobs and then get max element from i to n-1 
            // t[i][1] idx of jd and number of days 1 
            dp[i][1] = *max_element(begin(jobDifficulty)+i,end(jobDifficulty));
        }
        // now iterate over the reamining days
        // days are days 
        // i is the length of the arr for first for loop 
        // j is the length of the arr for the second for loop 
        for(int days = 2; days<=d; days++){
            for(int i=0; i<=n-days; i++){
                int max_diff = INT_MIN;
                int ans = INT_MAX;
                for(int j=i; j<=n-days; j++){
                    max_diff = max(max_diff,jobDifficulty[j]);
                    ans = min(ans,max_diff+dp[j+1][days-1]);
                }
                dp[i][days] = ans;
            }
        }
        return dp[0][d];
    }
};