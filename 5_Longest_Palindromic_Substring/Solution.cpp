class Solution {
public:
    bool solve(string &s, int i, int j) {
        if(i>=j){
            return true;
        }
        if(s[i] == s[j]){
            return solve(s,i+1,j-1);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
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