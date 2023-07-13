class Solution1 {
public:
    bool isCycleDFS(unordered_map<int, vector<int>> &adj, int currNode, vector<bool> &visited, vector<bool> &inRecursion){
        visited[currNode] = true;
        inRecursion[currNode] = true;

        for(int &nextNode : adj[currNode]){
            // if we have not visited then we check for cycle in further recursive call
            if(visited[nextNode] == false && isCycleDFS(adj,nextNode,visited,inRecursion)){
                return true;
            } else if(inRecursion[nextNode] == true){
                // if we have visited and it is in current recursive cycle we find the cycle
                return true;
            }
        }
        inRecursion[currNode] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> inRecursion(numCourses,false);
        unordered_map<int, vector<int>> adj;
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            //b to a
            adj[b].push_back(a);
        }
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion)){
                return false;
            }
                
        }

        // if we are stuck in cycle then we cannot complete all courses 
        return true;
    }
};