class Solution {
public:
    void longestPrefixSuffix(string &pattern, vector<int> &LPS, int n){
        // length of previous prefix and suffix which were equal 
        int length = 0;
        // if only one charater is present then the LPS is 0
        LPS[0] = 0;
        // starting from index 1 since 0 is already processes 
        int i=1;
        while(i<n){
            if(pattern[i] == pattern[length]){
                length++;
                LPS[i] = length;
                i++;
            } else {
                // checking for index range 
                if(length != 0){
                    length = LPS[length-1];
                } else {
                    LPS[i] = 0;
                    i++;
                }
            }
        }
    }
    vector<int> KMP(string &s, string &pattern){
        int n = s.length();
        int m = pattern.length();
        vector<int> result;
        vector<int> lps(m,0);
        longestPrefixSuffix(pattern,lps,m);
        
        int i = 0;
        int j = 0;
        
        while(i<n){
            if(pattern[j] == s[i]){
                i++;
                j++;
            }
            if(j==m){
                result.push_back(i-j);
                j = lps[j-1];
            } else if(i<n && pattern[j] != s[i]){
                if(j!=0){
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
        return result;
    }
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int n = s.length();
        // both of this will be sorted so we can apply BinSearch on this 
        vector<int> i_indices = KMP(s,a);
        vector<int> j_indices = KMP(s,b);
        
        vector<int> result;
        
        for(int &idx : i_indices){
            int left = max(0,idx-k);
            int right = min(n-1,idx+k);
            auto it = lower_bound(begin(j_indices), end(j_indices), left);
            if(it != j_indices.end() && *it <= right) {
                result.push_back(idx);
            }
        }
        return result;
    }
};