class Solution {
public:
    void dfs(int idx, int temp, int &ans, vector<int>& uniqChStr) {
          
            ans = max(ans, __builtin_popcount(temp));
          
            for (int i = idx; i < uniqChStr.size(); i++) {
                
                if ((temp & uniqChStr[i]) == 0) {                     
                    dfs(i + 1, temp | uniqChStr[i], ans, uniqChStr);
                }
            }
      }
    int maxLength(vector<string>& arr) {
        vector<int> uniqChStr;

        for (string &s : arr) {
            unordered_set<char> st(begin(s), end(s));
            
            if (st.size() != s.length())  
                continue;
            
            int val = 0; 
            for (char &ch : s) 
                val |= 1 << (ch - 'a');
            
            uniqChStr.push_back(val);
        }

        int ans = 0; 
        dfs(0, 0, ans, uniqChStr);
        return ans;
    }
};