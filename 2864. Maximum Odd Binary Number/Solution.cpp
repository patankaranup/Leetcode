class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt = count(s.begin(),s.end(),'1');
        int n = s.length();
        string res(n,'0');
        res[n-1]='1';
        int i=0;
        cnt--;
        while(cnt--){
            res[i] = '1';
            i++;
        }
        return res;
    }
};