class Solution {
public:
    int minDeletions(string s) {
        int freqTable[26] = {0};
        for(char &ch : s){
            freqTable[ch-'a']++;
        }
        int deletion = 0;
        unordered_set<int> st;

        for(int i=0; i<26; i++){
            while(freqTable[i] > 0 && st.find(freqTable[i]) != st.end()){
                freqTable[i]-=1;
                deletion++;
            }
            st.insert(freqTable[i]);
        }
        return deletion;
    }
};