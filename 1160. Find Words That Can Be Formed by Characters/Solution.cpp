class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26,0);
        for(auto &ch : chars){
            charCount[ch-'a']++;
        }
        int ans = 0;
        for(auto &word : words){
            vector<int> wordCount(26,0);
            for(auto &ch:word){
                wordCount[ch-'a']++;
            }
            bool isPossible = true;
            for(int i=0; i<26; i++){
                if(wordCount[i]>charCount[i]){
                    isPossible = false;
                    break;
                }
            }
            if(isPossible){
                ans += word.length();
            }
        }
        return ans;
    }
};