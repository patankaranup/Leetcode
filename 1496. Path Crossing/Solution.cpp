class Solution {
public:
    bool isPathCrossing(string path) {
        // start at origin 
        int x = 0;
        int y = 0;
        unordered_set<string> st;
        // insert it to the set 
        string key = to_string(x) + "_" + to_string(y);
        st.insert(key);
        // iterate on paths 
        for(char &ch : path) {
            if(ch == 'E') {
                x += 1;
            } else if(ch == 'W') {
                x -= 1;
            } else if(ch == 'N') {
                y += 1;
            } else {
                y -= 1;
            }
            key = to_string(x) + "_" + to_string(y);
            if(st.find(key) != st.end()) {
                return true;
            }
            st.insert(key);
        }
        return false;
    }
};