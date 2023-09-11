class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        
        vector<vector<int>> mp(n+1);
        vector<vector<int>> result;
        
        for(int i = 0; i<n; i++) {
            int gs = groupSizes[i];
            mp[gs].push_back(i);
            if(mp[gs].size() == gs) {
                result.push_back(mp[gs]);
                mp[gs] = {};
            }
        }
        return result;
    }
};