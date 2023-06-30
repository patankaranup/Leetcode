class Solution1 {
public:
    int ROW; 
    int COL;
    vector<vector<int>> directions = {
        {-1,0},{0,1},{1,0},{0,-1}  
    };
    bool BFS(vector<vector<int>>& grid, int row, int col){
        queue<pair<int,int>> que;
        que.push({row,col});
        grid[row][col] = 1;
        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            int i = temp.first;
            int j = temp.second;
            if(i==ROW-1){
                // we reached the last row
                return true;
            }
            for(auto &dir : directions){
                int new_row = dir[0] + i;
                int new_col = dir[1] + j;
                // boundary check
                if(new_row>=0 && new_row<ROW && new_col>=0 && new_col<COL && grid[new_row][new_col] == 0){
                    que.push({new_row,new_col});
                    grid[new_row][new_col] = 1;
                }
            }
        }
        return false;
    };
    bool canCross(vector<vector<int>>& cells, int mid){
        // make a grid and fill with water till day = mid and then run dfs/bfs for every col in 0th row until you reach to the bottom of the grid i.e last row 
        vector<vector<int>> grid(ROW,vector<int>(COL));
        // filling with water = 1
        for(int i=0; i<=mid; i++){
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 1;
        }
        // now run dfs or bfs for all the cols in top 0th row until you reavh the bottom
        for(int j=0; j<COL; j++){
            if(grid[0][j] == 0 && BFS(grid, 0, j)){
                return true;
            } 
        }
        return false;
    };
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;  
        int l = 0;
        int r = cells.size()-1;
        int lastDay = 0;
        while(l<=r) {
            int mid = l + (r-l)/2;
            if(canCross(cells,mid)){
                lastDay = mid+1;
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        return lastDay;
    };
};