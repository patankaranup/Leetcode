class Solution3 {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for (char &ch : word){
            if (isupper(ch)){
                count+=1;
            }
        }
        if (count == word.length() || count == 0 || (count == 1 && 
isupper(word[0]))){
            return true;
        } 
        return false;
    }
};
