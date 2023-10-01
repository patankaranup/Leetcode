class Solution1 {
public:
    string reverseWords(string s) {
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                int j=i;
                while(j<n && s[j] != ' '){
                    j++;
                }
                reverse(begin(s) + i,begin(s) + j);
                i = j;
            }
        }
        return s;
    }
};