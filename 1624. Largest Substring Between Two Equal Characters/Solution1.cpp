class Solution1  {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        unordered_map<char,int> mp;
        int res = -1;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(mp.find(ch) == mp.end()){
                mp[ch] = i;
            } else {
                res = max(res,i-mp[ch]-1);
            }
        }
        return res;
    }
};