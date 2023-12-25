class Solution {
public:
    int n;
    int memo[101];
    int solve(int idx, string &s){
        if(memo[idx] != -1){
            return memo[idx];
        }
        // one valid partition found 
        if(idx == n){
            return memo[idx] = 1;
        }
        // we dont have any mapping for starting with 0 so return 0
        if(s[idx] == '0'){
            return memo[idx] = 0;
        }
        // take one digit 
        int noOfWays = solve(idx+1,s);
        // take two digit 
        if(idx+1 < n){
            if(s[idx] == '1' || (s[idx] == '2' && s[idx+1] <= '6')){
                noOfWays += solve(idx+2,s);
            }
        }
        return memo[idx] = noOfWays;
    }
    int numDecodings(string s) {
        n = s.length();
        memset(memo,-1,sizeof(memo));
        return solve(0,s);
    }
};