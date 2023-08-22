class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber>0){
            columnNumber--;
            int lastNumberForAlphabet = columnNumber%26;
            columnNumber = columnNumber/26;
            char ch = lastNumberForAlphabet + 'A';
            s += ch;
        }
        reverse(begin(s),end(s));
        return s;
    }
};
