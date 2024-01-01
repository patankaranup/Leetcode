class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        int cnt = 0;
        sort(begin(s),end(s));
        sort(begin(g),end(g));
        int i=0, j=0;
        while(j<n && i<m){
            if(g[i]<=s[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};