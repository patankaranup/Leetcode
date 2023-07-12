class Solution {
public:
    bool isCycle(vector<vector<int>>& adj, int curr, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[curr] = true;
        inRecursion[curr] = true;
        
        for(int &v : adj[curr]) {
            //if not visited curr node, then we check for cycle in DFS
            if(visited[v] == false && isCycle(adj, v, visited, inRecursion)){
                return true;
            }
            // if it is visited then we check whether it is visited in curr recursion call stack and retur true
            else if(inRecursion[v] == true){
                return true;
            }       
        }
        // during backtracking we need to set the inRecursion to false    
        inRecursion[curr] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        vector<int> safeNodes;
        // this will call the is cycle method for all nodes and the onw which have cycle will be set to true in recursion    
        for(int i = 0; i<V; i++) {
            if(!visited[i]){
                isCycle(graph, i, visited, inRecursion);
            }
        }
        // adding safenodes i.e the nodes which are false
        for(int i = 0; i<V; i++) {
            if(inRecursion[i] == false){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
