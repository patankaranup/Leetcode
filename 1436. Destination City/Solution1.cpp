class Solution1 {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(auto &vec : paths){
            st.insert(vec[0]);
        }
        for(auto &vec : paths){
            if(st.find(vec[1]) == st.end()){
                return vec[1];
            }
        }
        return "";
    }
};