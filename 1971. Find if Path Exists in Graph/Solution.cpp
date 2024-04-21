class Solution {
public:
    bool solve(unordered_map<int, vector<int>>& mp, int src, int dest, vector<bool>& visited) {
        if(src == dest){
            return true;
        }
        if(visited[src]){
            return false;
        }
        visited[src] = true;
        for(auto &it : mp[src]) {
            if(solve(mp, it, dest, visited)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination){
            return true;
        }
        unordered_map<int, vector<int>> mp;
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> visited(n, false);
        return solve(mp, source, destination, visited);
    }
};