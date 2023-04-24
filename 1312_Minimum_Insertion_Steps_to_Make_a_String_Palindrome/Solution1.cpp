class Solution1 {
public:
    int n;
    int memo[501][501];
    int solve(string& s, int i, int j){
        if(i>=j){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(s[i] == s[j]){
            return memo[i][j] = solve(s,i+1,j-1);
        } else {
            return memo[i][j] = 1 + min(solve(s,i+1,j),solve(s,i,j-1));
        }
    }
    int minInsertions(string s) {
        n = s.length();
        memset(memo,-1,sizeof(memo));
        return solve(s,0,n-1);
    }
};