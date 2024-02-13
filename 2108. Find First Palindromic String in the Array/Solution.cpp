class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &iter : words){
            if(iter == string(rbegin(iter),rend(iter))){
                return iter;
            }
        }
        return "";
    }
};