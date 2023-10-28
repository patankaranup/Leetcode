class Solution {
public:
    int MOD = 1e9+7;
    int a = 0, e = 1, i = 2, o = 3, u = 4;
    vector<vector<long long>> memo;
    long long solve(int ch, int n) {
        if(n == 0) {
            return 1;
        }

        if(memo[ch][n] != -1) {
            return memo[ch][n];
        }

        if(ch == a) {
            return memo[ch][n] = solve(e, n-1) % MOD;
        } else if(ch == e) {
            return memo[ch][n] = (solve(a, n-1) + solve(i, n-1)) % MOD;
        } else if(ch == i) {
            return memo[ch][n] = (solve(a, n-1) + solve(e, n-1) + solve(o, n-1) + solve(u, n-1)) % MOD;
        } else if(ch == o) {
            return memo[ch][n] = (solve(i, n-1) + solve(u, n-1)) % MOD;
        } else { 
            return memo[ch][n] = solve(a, n-1) % MOD;
        }


        return memo[ch][n] = 0;
    }

    int countVowelPermutation(int n) {
        memo.resize(5, vector<long long>(n+1, -1));
        long result = 0;

        result = (result + solve(a, n-1)) % MOD;
        result = (result + solve(e, n-1)) % MOD;
        result = (result + solve(i, n-1)) % MOD;
        result = (result + solve(o, n-1)) % MOD;
        result = (result + solve(u, n-1)) % MOD;

        return result;

    }
};