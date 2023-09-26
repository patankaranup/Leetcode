class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<bool> used(26,false);
        vector<int> lastIdx(26);
        string result;
        for(int i=0; i<n; i++){
            int ch = s[i] - 'a';
            lastIdx[ch] = i;
        }

        for(int i=0; i<n; i++){
            int ch = s[i];
            int idx = ch - 'a';
            if(used[idx]){
                continue;
            }
            while(result.length() > 0 && result.back() > ch && lastIdx[result.back() - 'a']>i){
                used[result.back() - 'a'] = false;
                result.pop_back();
            }
            result.push_back(ch);
            used[idx] = true;
        }
        return result;
    }
};