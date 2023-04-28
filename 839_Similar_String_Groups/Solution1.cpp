class Solution1 {
public:
    void dfs(int u,unordered_map<int, vector<int>> &adj, vector<bool> &visited){
        visited[u] = true;
        for(auto &v : adj[u]){
            if(!visited[v]){
                dfs(v,adj,visited);
            }
        }
    }
    bool isSimilar (string &s1, string &s2){
        int m = s1.length();
        int diff = 0;
        for(int i = 0; i<m; i++){
            if(s1[i] != s2[i]){
                diff++;
            }
        }
        return diff == 2 || diff == 0;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        unordered_map<int, vector<int>> adj;
        for (int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isSimilar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n,false); 
        int count = 0;
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i,adj,visited); 
                count++;
            }
        }
        return count;
    }
};