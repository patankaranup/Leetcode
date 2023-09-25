class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        char ans;
        for(char &ch : s){
            mp[ch]++;
        }
        for(char &ch : t){
            mp[ch]--;
            if(mp[ch] < 0){
                ans = ch;
                return ans;
            }
        }
        return ans;
    }
};