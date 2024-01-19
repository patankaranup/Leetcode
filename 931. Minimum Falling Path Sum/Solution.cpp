class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int col=0; col<n; col++){
            dp[0][col] = matrix[0][col];
        }
        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){
                // get the above left val 
                int left = INT_MAX;
                if(col-1>=0) left = dp[row-1][col-1];
                // get the mid val 
                int mid = dp[row-1][col];
                // get the above right 
                int right = INT_MAX;
                if(col+1<n) right = dp[row-1][col+1];
                dp[row][col] = matrix[row][col] + min({left,mid,right});
            }
        }
        int ans = INT_MAX;
        for(int col = 0; col<n; col++){
            ans = min(ans,dp[n-1][col]);
        }
        return ans;
    }
};