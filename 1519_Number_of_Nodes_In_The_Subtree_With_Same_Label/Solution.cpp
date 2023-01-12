class Solution {
public:
    vector<int> dfs(unordered_map<int , vector<int>> &adj, int curr, int parent, vector<int> &result, string 
&labels){
        // Create a vector to count the occurences of each label in the current subtree
        vector<int> my_count(26, 0) ;
        // Get the label of the current node
        char my_label = labels[curr];
        // Set the count of the current node's label to 1
        my_count[my_label - 'a'] =1;
        // Iterate through the children of the current node
        for (int &v : adj[curr]) {
            if (v == parent){
                // Skip the current node if it's the parent node
                continue;
            }
            // Call the dfs function recursively for each child node
            vector<int> child_count(26,0);
            child_count = dfs(adj,v,curr,result,labels);
            // Add the count of each label from the child subtree to the my_count vector
            for (int i = 0; i<26; i++){
                my_count[i] += child_count[i];
            }
        }
        // Assign the count of the current node's label to the corresponding element in the result vector
        result[curr] = my_count[my_label-'a'];
        // Return the my_count vector
        return my_count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        // Create an unordered_map to represent the adjacency list of the tree
        unordered_map<int , vector<int>> adj;

        // Iterate through the edges array and add each edge to the adjacency list
        for (auto &v : edges){
            int u = v[0];
            int w = v[1];
            adj[u].push_back(w);
            adj[w].push_back(u);
        }
        // Create a vector to store the result
        vector<int> result(n, 0);
        // Call the dfs function to traverse the tree and count the subtrees
        dfs(adj, 0, -1, result, labels);
        // Return the result vector
        return result ;
    }
};

