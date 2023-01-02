class Solution1 {
public:
    bool allCapital(string word){
        for (char &ch : word){
            if(ch<'A' || ch>'Z'){
                return false;
            }
        }
        return true;
    }
    bool allSmallWord(string word){
        for (char &ch : word){
            if(ch<'a' || ch>'z'){
                return false;
            }
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        if (allCapital(word) || allSmallWord(word) || 
allSmallWord(word.substr(1))){
            return true;
        }
        return false;
    }
};
