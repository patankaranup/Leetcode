class Solution {
public:
    int memo[101][101];
    bool solve(int idx, int open, string &s, int n){
        if(idx == n){
            if(open == 0) return true;
            else          return false;
        }
        if(memo[idx][open] != -1){
            return memo[idx][open];
        }
        bool isValid = false;
        if(s[idx] == '*'){
            isValid |= solve(idx+1, open+1, s, n);
            isValid |= solve(idx+1, open, s, n);
            if(open>0){
                isValid |= solve(idx+1, open-1, s, n);
            }
        }else if(s[idx] == '('){
            isValid |= solve(idx+1, open+1, s, n);
        }else if(open>0){
            isValid |= solve(idx+1, open-1, s, n);
        }
        return memo[idx][open] = isValid;
    }
    bool checkValidString(string s) {
        int n = s.length();
        memset(memo,-1,sizeof(memo));
        return solve(0,0,s,n);
    }
};