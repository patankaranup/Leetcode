class Solution {
public:
    int n;
    vector<vector<int>> memo;
    
    int solve(int l, int r, string& s){
        if(l == r)
            return 1;
        
        else if(l > r)
            return 0;
        
        if(memo[l][r] != -1)
            return memo[l][r];

        // for similar characters in string 
        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;

        if(i == r+1)
            return 1;

        int similar_characters = 1 + solve(i,r,s);


        // for inserting new characters 
        int new_characters = INT_MAX;

        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = solve(i,j-1,s) + solve(j,r,s);
                
                new_characters = min(new_characters, x);
            }
        }

        return memo[l][r] = min(new_characters, similar_characters);
    }

    int strangePrinter(string s) {
        n = s.length() ;
        
        memo.resize(n,vector<int>(n+1, -1));
        
        return solve(0, n-1, s);
    }
};