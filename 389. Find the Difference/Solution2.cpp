class Solution {
public:
    char findTheDifference(string s, string t) {
        int x_o_r = 0;
        for(char &ch : s){
            x_o_r = x_o_r^ch;
        }
        for(char &ch : t){
            x_o_r = x_o_r^ch;
        }
        return (char)x_o_r;
    }
};