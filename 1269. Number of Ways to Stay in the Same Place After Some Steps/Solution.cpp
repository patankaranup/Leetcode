class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;
    int n;
    ll memo[501][501];
    ll solve(int steps, int idx){
        if(steps == 0 && idx == 0){
            return 1;
        }
        if(idx < 0 || idx >= n || steps == 0){
            return 0;
        }
        if(memo[steps][idx] != -1){
            return memo[steps][idx];
        }
        ll stay = solve(steps-1,idx) % MOD;
        ll moveLeft = solve(steps-1,idx-1) % MOD;
        ll moveRight = solve(steps-1, idx+1) % MOD;
        return memo[steps][idx] = (stay+moveLeft+moveRight) % MOD;
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps/2 + 1);
        n = arrLen;
        memset(memo,-1,sizeof(memo));
        return solve(steps,0);
    }
};