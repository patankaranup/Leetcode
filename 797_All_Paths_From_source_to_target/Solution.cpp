class Solution {
public:

    void dfs(int u, int target, vector<vector<int>>& graph, vector<int> 
temp, vector<vector<int>>& result){
        temp.push_back(u);
        if (u==target){
            result.push_back(temp);
        } else {
            for (int &v : graph[u]){
                dfs(v, target,graph,temp,result);
            }
        }
        temp.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        int source = 0;
        int target = n-1;

        vector<vector<int>> result;

        vector<int> temp;

        dfs(source,target,graph,temp,result);

        return result;

        
    }
};
