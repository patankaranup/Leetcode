class Solution1 {
public:
    typedef pair<int, pair<int,int>> P;
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if(m == 0 || n == 0 || grid[0][0] != 0)
            return -1;
        auto isSafe = [&](int x, int y) {
            return x>=0 && x<m && y>=0 && y<n;
        };

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        priority_queue<P,vector<P>, greater<P>> pq;

        pq.push({0,{0,0}});
        result[0][0] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            pair<int, int> node = pq.top().second; 
            int x = node.first;
            int y = node.second;
            pq.pop();

            for(auto dir : directions){
                int x_ = dir[0] + x;
                int y_ = dir[1] + y;
                int dist = 1;
                if(isSafe(x_,y_) && grid[x_][y_]==0 && d+dist < result[x_][y_]){
                    pq.push({d+dist,{x_,y_}});
                    result[x_][y_] = d+dist; 
                }
            }
        }
        if(result[m-1][n-1] == INT_MAX){
            return -1;
        } else {
            return result[m-1][n-1] + 1;
        }

    }
};