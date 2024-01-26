class Solution1 {
public:
    typedef long long ll;
    const ll MOD = 1e9+7;
    vector<vector<int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        // dp[i][j][k] number of paths when you are at i and j pos with moves equals to k 
        int dp[51][51][51];
        memset(dp,0,sizeof(dp));

        for(int k=1; k<=maxMove; ++k){
            for(int i=0; i<m; ++i){
                for(int j=0; j<n; ++j){
                    for(auto &dir : directions){
                        int new_row = i + dir[0];
                        int new_col = j + dir[1];
                        if(new_row < 0 || new_row >= m || new_col < 0 || new_col >= n){
                            dp[i][j][k] = (dp[i][j][k] + 1) % MOD;
                        } else {
                            dp[i][j][k] = (dp[i][j][k] + dp[new_row][new_col][k-1]) % MOD;
                        }
                    }
                }
            }
        }
        return dp[startRow][startColumn][maxMove];
    }
};