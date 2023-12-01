class Solution1 {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();
        int len1_i = 0; int i = 0;
        int len2_i = 0; int j = 0;
        while(len1_i < m && len2_i < n) {
            if(word1[len1_i][i] != word2[len2_i][j]){
                return false;
            }
            i++;
            j++;
            if(i == word1[len1_i].length()) {
                i = 0;
                len1_i++;
            }
            if(j == word2[len2_i].length()) {
                j = 0;
                len2_i++;
            }
        }
        if(len1_i == m && len2_i == n){
            return true;
        }
        return false;
    }
};