class Solution1 {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        // number of edges between cities
        int edges = roads.size();
        int result = INT_MIN;
        // matrix for finding connection between two nodes in constant time 
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        // indegree that is how many incoming nodes at every node 
        vector<int> indegree(n,0);

        for(auto &road : roads){
            int u = road[0];
            int v = road[1];
            // mark connected in matrix
            matrix[u][v] = 1;
            matrix[v][u] = 1;

            // increase indegree count of both nodes 
            indegree[u]+=1;
            indegree[v]+=1;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int ith_rank = indegree[i];
                int jth_rank = indegree[j];
                int total_rank = ith_rank+jth_rank;
                if(matrix[i][j] != -1){
                    total_rank -=1;
                }
                result = max(result,total_rank);
            }
        }
        return result;
    }
};