class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> charToIndex;
        unordered_map<string, int> wordToIndex;

        stringstream  ss(s);
        string token;
        int countTokens = 0;
        int i = 0;
        int n = pattern.size();

        while(ss>>token){
            countTokens+=1;
            if (i==n || charToIndex[pattern[i]]!=wordToIndex[token]){
                return false;

            }
            charToIndex[pattern[i]] = i+1;
            wordToIndex[token] = i+1;
            i+=1;
        }
        if (countTokens != n || i != n){
            return false;
        }
        return true;
    }
};
