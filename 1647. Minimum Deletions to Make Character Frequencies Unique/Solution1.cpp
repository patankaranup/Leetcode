class Solution1 {
public:
    int minDeletions(string s) {
        int freqTable[26] = {0};
        for(char &ch : s){
            freqTable[ch-'a']++;
        }
        int deletion = 0;
        sort(begin(freqTable),end(freqTable));

        for(int i=24; i>=0 && freqTable[i]>0; i--){
            if(freqTable[i]>=freqTable[i+1]){
                int prevFreq = freqTable[i];
                freqTable[i] = max(0,freqTable[i+1]-1);
                deletion += (prevFreq-freqTable[i]);
            }
        }
        return deletion;
    }
};