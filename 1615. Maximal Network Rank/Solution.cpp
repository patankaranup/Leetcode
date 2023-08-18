class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // number of edges between cities
        int edges = roads.size();
        // adjacency list between city and its adjacent cities using unordered set to find in O(1)
        unordered_map<int,unordered_set<int>> adj; 
        // result init
        int result = INT_MIN;
        // making adjacency list bidirectional
        for(int i=0; i<edges; i++){
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        // count rank between two city that is city is connected to how many another cities 
        // i and j th city connected to how many differnct cities ie rank of i and j
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int rank_i = adj[i].size();
                int rank_j = adj[j].size();
                int total_rank = rank_i + rank_j;
                // total rank - 1 if there is conncetion between ith jth city 
                if(adj[i].find(j) != adj[i].end()){
                    total_rank -=1;
                }
                // update the result
                result = max(total_rank,result);
            }
        }
        return result;
    }
};