class Solution {
public:
    int MOD = 1e9+7;
    int countHomogenous(string s) {
        int n = s.length();
        int result = 0;
        int curr_len = 0;
        for(int i=0; i<n; i++) {
            if(i>0 && s[i] == s[i-1]){
                curr_len++;
            } else {
                curr_len = 1;
            }
            result = (result + curr_len) % MOD;
        }
        return result;
    }
};