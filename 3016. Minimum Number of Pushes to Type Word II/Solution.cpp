class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();

        vector<int> freq(26,0);
        for(char &ch : word){
            freq[ch-'a']++; 
        }

        sort(rbegin(freq),rend(freq));

        int result = 0;
        for(int i=0; i<26; i++){
            int f = freq[i];
            // because we only have 8 keybuttons in the keypad 
            int no_of_press = (i/8)+1;
            int pushes = f * no_of_press;
            result += pushes;
        }
        return result;
    }
};      