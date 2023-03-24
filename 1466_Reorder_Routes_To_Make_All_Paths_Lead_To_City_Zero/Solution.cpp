class Solution {
public:
    int count = 0;

    void dfs(int current, int parent, unordered_map<int,vector<pair<int,bool>>> &adj){
        for(auto &u : adj[current]){
            int v = u.first;
            int edge = u.second; // if true then original node else our node
            if(v != parent){
                if(edge){
                    count++;
                }
                dfs(v, current, adj);
            } 
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        // adj for graph
        unordered_map<int,vector<pair<int,bool>>> adj;
        for(auto &vec : connections){
            int a = vec[0];
            int b = vec[1];
            adj[a].push_back({b,true}); // original edge
            adj[b].push_back({a,false}); // duplicate edge
        }

        dfs(0,-1,adj);
        return count;
    }
};
