class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int res = INT_MIN;
        for(int i = 0; i < n-1; i++) {
            int l0 = 0;
            for(int j = 0; j <= i; j++) {
                if(s[j] == '0') {
                    l0++;
                }
            }
            int r1 = 0;
            for(int j = i+1; j < n; j++) {
                if(s[j] == '1') {
                    r1++;
                }
            }
            res = max(res, l0 + r1);
        }
        return res;
    }
};