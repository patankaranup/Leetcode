class Solution1 {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            return true;
        } 
        return false;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();
        int i=0; 
        int j=n/2;
        int cntl = 0, cntr = 0;
        while(i<n/2 && j<n){
            if(isVowel(s[i])) cntl++;
            if(isVowel(s[j])) cntr++;
            i++;
            j++;
        }
        return cntl == cntr;
    }
};