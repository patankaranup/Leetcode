class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto &num : arr){
            mp[num]++;
        }
        unordered_set<int> st;
        for(auto &iter:mp){
            st.insert(iter.second);
        }
        return st.size() == mp.size();
    }
};