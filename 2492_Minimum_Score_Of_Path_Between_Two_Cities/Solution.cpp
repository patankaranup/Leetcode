class Solution {
public:
    void dfs(int u, unordered_map<int, vector<pair<int, int>>> &adj, vector<bool> &visited, int &result){
        visited[u] = true;
        // for another cities
        for(auto &P: adj[u]){
            int v = P.first;
            int d = P.second;

            result = min(result,d);
            if(!visited[v]){
                dfs(v, adj,visited,result);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        // map for storing graph
        unordered_map<int, vector<pair<int, int>>> adj;

        // created adj
        for(auto &vec : roads){
            int u = vec[0]; // city 
            int v = vec[1]; // another city 
            int d = vec[2]; // distance between them
            // for bidirectional graph
            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<bool> visited(n, false);
        int result = INT_MAX;
        // call dfs on the graph
        dfs(1,adj,visited,result);
        return result;
    }
};
