class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        int i=0; 
        int j=n/2;
        int cntl = 0, cntr = 0;
        unordered_set<char> st;
        st.insert({'a','e','i','o','u','A','E','I','O','U'});
        while(i<n/2 && j<n){
            if(st.find(s[i]) != st.end()) cntl++;
            if(st.find(s[j]) != st.end()) cntr++;
            i++;
            j++;
        }
        return cntl == cntr;
    }
};