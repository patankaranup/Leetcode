class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length()>n){
            return "";
        }
        unordered_map<char,int> mp;
        // store the required char in map
        for(auto &ch : t){
            mp[ch]++;
        }
        int count_required = t.length();

        int i=0;
        int j=0;
        int start_idx = 0;
        int minWindowSize = INT_MAX;
        while(j<n){
            char ch = s[j];
            if(mp[ch] > 0){
                count_required--;
            }
            mp[ch]--;
            while(count_required == 0){
                // shrink the window from the left 
                int currWindowSize = j-i+1;
                if(minWindowSize>currWindowSize){
                    minWindowSize = currWindowSize;
                    start_idx = i;
                }
                char ithChar = s[i];
                mp[ithChar]++;
                if(mp[ithChar] > 0){
                    count_required++;
                }
                i++;
            }
            j++; 
        }
        return minWindowSize == INT_MAX ?  "" : s.substr(start_idx,minWindowSize);
    }
};