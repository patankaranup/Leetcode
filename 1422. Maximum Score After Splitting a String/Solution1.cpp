class Solution1 {
public:
    int maxScore(string s) {
        int n = s.length();
        // 1 PASS 
        int t1 = count(begin(s), end(s), '1');
        int res = INT_MIN;
        // INT TOTAL LEFT lzeroERO 
        int lzero = 0;
        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                t1--;
            } else {
                lzero++;
            }
            res = max(res, lzero + t1);
        }
        return res;
    }
};