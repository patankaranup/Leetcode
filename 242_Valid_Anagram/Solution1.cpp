class Solution1 {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_frq(26,0);
        for(auto &ch : s){
            s_frq[ch-'a']++;
        }
        for(auto &ch : t){
            s_frq[ch-'a']--;
        }
        for(int i=0; i<26; i++){
            if(s_frq[i] != 0){
                return false;
            }
        }
        return true;
    }
};