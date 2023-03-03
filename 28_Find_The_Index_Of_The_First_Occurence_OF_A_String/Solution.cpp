class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();
        for(int i = 0; i<n; i++){
            if(haystack[i] == needle[0]){
                
                for(int j=0; j<needle.length(); j++){
                    if(haystack[i+j]!=needle[j]){
                        break;
                    }
                    if(j==m-1){
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};
