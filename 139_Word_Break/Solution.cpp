class Solution {
public:
    int memo[301];
    unordered_set<string> st;
    int n;
    bool solve(int idx, string &s){
        // return true if we reached the last index
        if(idx>=n){
            return true;
        }
        // if the string given is already present return true
        if(st.find(s) != st.end()){
            return true;
        }
        if(memo[idx]!=-1){
            return memo[idx];
        }
        // now start breaking the string from 1st index 
        for(int l = 1; l<=n; l++){
            // check if the substr from idx to l is present in set then call another recursive function 
            string temp = s.substr(idx,l);
            if(st.find(temp) != st.end() && solve(idx+l,s)){
                return memo[idx] = true;
            }
        }
        return memo[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(memo,-1,sizeof(memo));
        // for accessing string in constant time
        for (string &word : wordDict){
            st.insert(word);
        }
        // start from idx 0 
        return solve(0,s);
    }
};