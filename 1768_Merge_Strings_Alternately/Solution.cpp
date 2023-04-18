class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int m = word1.length();
        int n = word2.length();
        int i = 0;
        while(i<m || i<n){
            if(i<m){
                result.push_back(word1[i]);
            }
            if(i<n){
                result.push_back(word2[i]);
            }
            i++;
        }       
        return result; 
    }
};