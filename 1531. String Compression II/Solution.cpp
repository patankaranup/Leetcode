int memo[101][27][101][101]; 
class Solution {
public:
    int n;
    int solve(string &s, int i, int prevChar, int count, int k ){
        if(k < 0){
            return INT_MAX;
        }
    
        if(i >= n){
            return 0;
        }
        
        if(memo[i][prevChar][count][k] != -1) {
            return memo[i][prevChar][count][k];
        }
        int delete_ith_idx = solve(s, i+1, prevChar, count, k-1);
        int keep_ith_idx   = 0;
        int curr_char = s[i]-'a';
        if(curr_char == prevChar) {
             int new_cnt = 0;
             if(count == 1 || count == 9 || count == 99) {
                new_cnt = 1;
             }
            keep_ith_idx = new_cnt + solve(s, i+1, prevChar, count+1, k);
        } else {
            keep_ith_idx = 1 + solve(s, i+1, curr_char, 1, k);
        }
        return memo[i][prevChar][count][k] = min(delete_ith_idx, keep_ith_idx);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        n = s.length();
        memset(memo, -1, sizeof(memo));
        return solve(s, 0, 26, 0, k);
    }
};