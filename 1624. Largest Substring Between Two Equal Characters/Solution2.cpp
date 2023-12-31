class Solution2 {
public:
    typedef vector<int> vi;
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        vi vec(26,-1);
        int res = -1;
        for(int i=0; i<n; i++){
            char ch = s[i];
            if(vec[ch-'a'] == -1){
                vec[ch-'a'] = i;
            } else {
                res = max(res,i-vec[ch-'a']-1);
            }
        }
        return res;
    }
};