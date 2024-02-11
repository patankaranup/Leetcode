class Solution {
public:
    int n,m;
    int memo[71][71][71];
    int solve(vector<vector<int>>& grid, int curr_row, int r1_curr_col, int r2_curr_col){
        if(curr_row >= n){
            return 0;
        }
        if(memo[curr_row][r1_curr_col][r2_curr_col] != -1){
            return memo[curr_row][r1_curr_col][r2_curr_col];
        }
        // for robot 1 cherries 
        int cherries = grid[curr_row][r1_curr_col];
        if(r1_curr_col != r2_curr_col){
            cherries += grid[curr_row][r2_curr_col];
        }
        // possible directions for robot 1 
        int result = 0;
        for(int r1_val = -1; r1_val <= 1; r1_val++){
            // possible directions for robot 2
            for(int r2_val = -1; r2_val <= 1; r2_val++){
                int new_row = curr_row + 1;
                int new_col_r1 = r1_curr_col + r1_val;
                int new_col_r2 = r2_curr_col + r2_val;
                if(new_col_r1 >= 0 && new_col_r1 < m && new_col_r2 >=0 && new_col_r2 < m){
                    result = max(result, solve(grid,new_row,new_col_r1,new_col_r2));
                }
            }
        }
        return memo[curr_row][r1_curr_col][r2_curr_col] = cherries + result;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int r1_curr_col = 0;
        int r2_curr_col = m-1;
        int row          = 0;
        memset(memo,-1,sizeof(memo));
        return solve(grid,row,r1_curr_col,r2_curr_col);
    }
};