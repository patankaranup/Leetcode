class Solution {
public:
    int n;
    vector<string> result;
    unordered_map<char,string>mp;
    void combinations(int idx, string &digits, string &s){
        if(idx>=n){
            result.push_back(s);
            return;
        }
        char ch = digits[idx];
        string letters = mp[ch];
        for(int i=0; i<letters.length(); i++){
            // do 
            s.push_back(letters[i]);
            // explore
            combinations(idx+1,digits,s);
            // undo
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.length();
        if(n==0){
            return {};
        }
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz"; 
        string s;
        combinations(0,digits,s);
        return result;
    }
};