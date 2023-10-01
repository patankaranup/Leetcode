class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string result = "";
        string token = "";
        while(ss>>token){
            reverse(begin(token),end(token));
            result += token + " ";
        }
        int n = result.length();
        return result.substr(0,n-1);
    }
};