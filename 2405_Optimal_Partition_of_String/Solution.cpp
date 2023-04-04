class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        int count = 0;
        vector<int> lastSeen(26,-1);
        int currSubStr = 0;

        for(int i=0; i<n; i++){
            char ch = s[i];
            // in same substr that is duplicate 
            if(lastSeen[ch-'a'] >= currSubStr){
                count++;
                currSubStr = i;
            }
            lastSeen[ch-'a'] = i;
        }
        return count + 1;;
    }
};