class Solution {
public:
    int z , o;
    int l, h;
    const int MOD = 1e9 + 7;
    int recursion(int len, vector<int> &dp){
        if(len>h){
            return 0;
        }
        if(dp[len] != -1){
            return dp[len];
        }
        bool addOne = false;
        if(len>=l){
            // we have to add 1
            addOne = true;
        }
        int appendZero = recursion(len+z,dp);
        int appendOne = recursion(len+o,dp);
        return dp[len] = (addOne + appendZero + appendOne)%MOD; 
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        z = zero;
        o = one;
        l = low;
        h = high;
        vector<int> dp(high+1,-1);
        return recursion(0,dp);
    }
};

