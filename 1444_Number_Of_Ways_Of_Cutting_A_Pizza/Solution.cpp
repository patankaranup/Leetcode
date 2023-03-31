class Solution {
public:
    int m, n;
    int apples[54][54];
    int dp[54][54][12];
    long long MOD = 1e9 + 7;
    
    int solve(int i, int j, int k) {
        // not enough apples for k people
        if(apples[i][j] < k)
            return 0;
        // only one person left 
        if(k == 1) {
            // if apples are more than 1 return 1 or 0
            return (apples[i][j] >= 1) ? 1 : 0;
        }
        
        // using memoization to prevent unnecessary computing
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        // if not then set to 0
        dp[i][j][k] = 0;
        // for horizontal cut of the array
        for (int h = i + 1; h < m; h++) {
            
            if (apples[i][j] - apples[h][j] > 0 && apples[h][j] >= k - 1) {
                
                dp[i][j][k] = (dp[i][j][k] % MOD + solve(h, j, k - 1) % MOD) % MOD;
                
            }
        }
        // for vertical cut of the array
        for (int v = j + 1; v < n; v++) {
            
            if (apples[i][j] - apples[i][v] > 0 && apples[i][v] >= k - 1) {
                dp[i][j][k] = (dp[i][j][k] % MOD + solve(i, v, k - 1) % MOD) % MOD;
            }
        }

        return dp[i][j][k];
        
    }
    
    int ways(vector<string>& pizza, int k) {
        m = pizza.size();
        n = pizza[0].length();
        
        memset(apples, 0, sizeof(apples));
        // making apple array 
        for(int i = m-1; i>=0; i--) {
            
            for(int j = n-1; j>=0; j--) {
                
                apples[i][j] = apples[i][j+1];
                
                for(int l = i; l<m; l++) {
                    apples[i][j] += (pizza[l][j]=='A');
                }
                
            }
            
        }
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, k);
        
    }
};