class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for(int l=1; l<=n/2; l++){
            if(n%l == 0){
                int times = n/l;
                string subStr = s.substr(0,l);
                string str = "";
                while(times--){
                    str += subStr;
                }
                if(s == str){
                    return true;
                }
            }
        }
        return false;
    }
};