class Solution {
public:
    int minSteps(string s, string t) {
        int freq_S[26] = {0};
        int freq_T[26] = {0};
        for(auto &ch : s){
            freq_S[ch-'a']++;
        }
        for(auto &ch : t){
            freq_T[ch-'a']++;
        }
        int cnt = 0;
        for(int i=0; i<26; i++){
            if(freq_S[i]>freq_T[i]) {
                cnt = cnt + freq_S[i] - freq_T[i];
            }
        }
        return cnt;
    }
};