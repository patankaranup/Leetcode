class Solution1 {
public:
    int numWays(vector<string>& words, string target) {
        int m = target.length(); // target length
        int k = words[0].size(); // word length in dict
        const int MOD = 1e9 + 7; 
        vector<vector<long long>> freq(26, vector<long long>(k));
        for(int col = 0; col < k; col++){
            for(string &word: words){
                char ch = word[col];
                freq[ch-'a'][col]++;
            }
        }
        vector<vector<int>> t(m+1,vector<int>(k+1,0));
        // total ways to form target of length i using dict words of each length j
        t[0][0] = 1;
        for(int i = 0; i<=m; i++){
            for(int j=0; j<=k; j++){
                // not taken 
                if(j<k){
                    t[i][j+1] = (t[i][j+1]+t[i][j])%MOD;
                }
                // taken
                if(i<m && j<k){
                    t[i+1][j+1] = (t[i+1][j+1] + t[i][j] * freq[target[i]-'a'][j])%MOD;
                }
                
            }
        }
        return t[m][k];
    }
};