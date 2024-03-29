class Solution1 {
public:
    int lcs(string& s1, string& s2){
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> t(m+1, vector<int>(n+1));
        for(int i = 0; i<m+1; i++){
            for(int j = 0; j<n+1; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                } else if(s1[i-1] == s2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                } else {
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        return t[m][n];
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(begin(s2),end(s2));
        int m = s.length();
        return lcs(s,s2);
    }
};