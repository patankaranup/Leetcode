class Solution {
public:
    typedef long long ll;
    const ll MOD = 1e9+7;
    vector<vector<int>> directions = {
        {-1,0}, {1,0}, {0,-1}, {0,1}
    };
    int memo[51][51][51];
    ll solve(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow < 0 || startRow >= m || startColumn < 0 || startColumn >= n){
            return 1;
        }
        if(maxMove <= 0){
            return 0;
        }
        if(memo[maxMove][startRow][startColumn] != -1){
            return memo[maxMove][startRow][startColumn];
        }   
        ll ans = 0;
        for(auto &dir : directions){
            int new_row = startRow + dir[0];
            int new_col = startColumn + dir[1];
            ans = (ans + solve(m, n, maxMove-1, new_row, new_col)) % MOD;
        }
        return memo[maxMove][startRow][startColumn] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo,-1,sizeof(memo));
        return solve(m,n,maxMove,startRow,startColumn);
    }
};