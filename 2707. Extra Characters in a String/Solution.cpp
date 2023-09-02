class Solution {
public:
    int n;
    unordered_set<string> st;
    int memo[51];
    int solve(int idx, string &s){
        if(idx>=n){
            return 0;
        }
        if(memo[idx] != -1){
            return memo[idx];
        }

        string currString = "";
        int minExtra = n;
        for(int i=idx; i<n; i++){
            currString.push_back(s[i]);
            int currExtra = (st.find(currString) == st.end()) ? currString.length() : 0;
            int nextExtra = solve(i+1,s);
            int totalExtra = currExtra + nextExtra;
            minExtra = min(minExtra,totalExtra);
        }
        return memo[idx] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        memset(memo,-1,sizeof(memo));
        for(string &word : dictionary){
            st.insert(word);
        }
        return solve(0,s);
    }
};