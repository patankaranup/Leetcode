class Solution {
public:
    int M,N;
    int memo[101][101];
    int solve(int i, int j){
        if(i>=M || j>=N){
            return 0;
        }
        if(i==M-1 && j==N-1){
            return 1;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int go_right = solve(i,j+1);
        int go_down = solve(i+1,j);
        return memo[i][j] = go_right + go_down;
    }
    int uniquePaths(int m, int n) {
        M = m;
        N = n;
        memset(memo,-1,sizeof(memo));
        return solve(0,0);
    }
};