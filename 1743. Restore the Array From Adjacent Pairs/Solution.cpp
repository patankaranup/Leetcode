class Solution {
public:
    vector<int> result;
    void dfs(int curr_node, int prev_node, unordered_map<int,vector<int>> &adj){
        result.push_back(curr_node);
        for(auto &new_node : adj[curr_node]){
            if(new_node != prev_node){
                dfs(new_node, curr_node, adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>> mp;
        for(auto &vec : adjacentPairs){
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        int start = -1;
        for(auto &iter : mp){
            if(iter.second.size() == 1){
                start = iter.first;
                break;
            }
        }
        dfs(start,INT_MAX,mp);
        return result;
    }
};