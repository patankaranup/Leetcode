class Solution {
public:
    int m, n, N;
    int memo[101][101][201];
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3){
        if(i==m && j==n && k==N){
            return true;
        }
        if(k==N){
            return false;
        }
        if(memo[i][j][k] != -1){
            return memo[i][j][k];
        }
        bool result = false;
        // take i from string 1 if it matches k in string 3
        if(s1[i] == s3[k]){
            result = solve(i+1,j,k+1,s1,s2,s3);
        }
        if(result){
            return memo[i][j][k] = true;
        }
        // take j from string 2 if it matches k in string 3
        if(s2[j] == s3[k]){
            result = solve(i,j+1,k+1,s1,s2,s3);
        }
        if(result){
            return memo[i][j][k] = true;
        }
        return memo[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        m = s1.length();
        n = s2.length();
        N = s3.length();
        memset(memo,-1,sizeof(memo));
        if(m+n != N){
            return false;
        }
        return solve(0,0,0,s1,s2,s3);
    }
};