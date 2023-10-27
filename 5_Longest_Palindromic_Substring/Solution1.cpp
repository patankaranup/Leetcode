class Solution1 {
public:
    int memo[1001][1001];
    bool solve(string &s, int i, int j) {
        if(i>=j){
            return true;
        }
        if(memo[i][j] != -1){
            return memo[i][j];
        }
        if(s[i] == s[j]){
            return memo[i][j] = solve(s,i+1,j-1);
        }
        return memo[i][j] = false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        memset(memo,-1,sizeof(memo));
        int max_len = INT_MIN;
        int start_idx = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(solve(s,i,j)){
                    int curr_len = j-i+1;
                    if(curr_len>max_len){
                        max_len = curr_len;
                        start_idx = i;
                    }
                }
            }
        }
        return s.substr(start_idx, max_len);
    }
};