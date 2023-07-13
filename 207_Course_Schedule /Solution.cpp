class Solution {
public:
    bool topoSort(unordered_map<int, vector<int>> &adj, int numCourses, vector<int> &indegree){
        queue<int> que;

        // to update the number of nodes we visit if count = numcourses than no cycle found else cylce was there
        int count = 0;

        // kahns algo put all nodes that have indegree 0
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                count++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int &v : adj[u]){
                indegree[v]-=1;
                if(indegree[v] == 0){
                    count++;
                    que.push(v);
                }
            }
            
        }
        if(count == numCourses){
            // we visited all courses 
            return true;
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        // kahns algorithm all have indegree set to 0 at first
        vector<int> indegree(numCourses,0);
        for(auto &vec : prerequisites){
            int a = vec[0];
            int b = vec[1];
            // b to a
            adj[b].push_back(a);
            indegree[a]++;
        }

        // if we are stuck in cycle then we cannot complete all courses 
        return topoSort(adj,numCourses,indegree);       
    }
};