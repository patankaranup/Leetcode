class Solution {
public:
    int memo[1001][1001];
    int m,n;
    int solve(int i,int j,string &s1,string &s2){
        if(i>=m && j>=n){
            return 0;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(i>=m){
            return s2[j] + solve(i,j+1,s1,s2);
        }
        if(j>=n){
            return s1[i] + solve(i+1,j,s1,s2);
        }
        if(s1[i] == s2[j]){
            return solve(i+1,j+1,s1,s2);
        }
        int delete_i = s1[i] + solve(i+1,j,s1,s2);
        int delete_j = s2[j] + solve(i,j+1,s1,s2);
        return memo[i][j] = min(delete_i,delete_j);
    }
    int minimumDeleteSum(string s1, string s2) {
        m = s1.length();
        n = s2.length();
        memset(memo,-1,sizeof(memo));
        return solve(0,0,s1,s2);
    }   
};