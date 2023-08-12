class Solution {
public:
    int m;
    int n;
    int memo[101][101];
    int solve(int i, int j, vector<vector<int>>& obstacleGrid){
        if(i>=m || j>=n){
            return 0;
        }
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int go_left = solve(i+1,j,obstacleGrid);
        
        int go_right = solve(i,j+1,obstacleGrid);

        return memo[i][j] = go_left + go_right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memset(memo,-1,sizeof(memo));
        return solve(0,0,obstacleGrid);
    }
};