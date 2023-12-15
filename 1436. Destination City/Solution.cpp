class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> mp;
        for(auto &vec : paths){
            mp[vec[0]]++;
        }
        for(auto &vec : paths){
            if(!mp[vec[1]]){
                return vec[1];
            }
        }
        return "";
    }
};