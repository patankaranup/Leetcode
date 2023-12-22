class Solution2 {
public:
    int maxScore(string s) {
        int n = s.length();
        int zeros = 0;
        int ones  = 0;
        int res = INT_MIN;
        
        for(int i = 0; i < n-1; i++) {
            if(s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            res = max(res, zeros - ones);
        }
        if(s[n-1] == '1') {
            ones++;
        }
        return res+ones;
    }
};