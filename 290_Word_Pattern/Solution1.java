class Solution1 {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        stringstream ss(s);
        string token ;
        int countWords = 0;

        while(getline(ss, token, ' ')){
            words.push_back(token);
            countWords+=1;
        }
        int n = pattern.size();
        if (n != countWords){
            return false;
        }
        unordered_map<string, char> mp;
        set<char> usedchar;

        for (int i = 0; i<n; i++){
            string word = words[i];
            char ch = pattern[i];
            if (mp.find(word)== mp.end() && usedchar.find(ch) == 
usedchar.end()){
                usedchar.insert(ch);
                mp[word] = ch;

            } else if (mp[word] != pattern[i]){
                return false;
            }
        }
        return true;

    }
};
