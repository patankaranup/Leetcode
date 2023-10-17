class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int>child_to_parent;

        // MAKING ADJ AND checking whether every node has one parent 
        for(int i=0; i<n; i++){
            int node = i;
            int left_child = leftChild[i];
            int right_child = rightChild[i];
            if(left_child != -1){
                adj[node].push_back(left_child);
                if(child_to_parent.find(left_child) != child_to_parent.end()){
                    return false;
                }
                child_to_parent[left_child] = node;
            }
            if(right_child != -1){
                adj[node].push_back(right_child);
                if(child_to_parent.find(right_child) != child_to_parent.end()){
                    return false;
                }
                child_to_parent[right_child] = node;
            }
        }

        // getting root 
        int root = -1;
        for(int i=0; i<n; i++){
            if(child_to_parent.find(i) == child_to_parent.end()){
                if(root != -1){
                    return false;
                }
                root = i;
            }
        }
        if(root == -1){
            return false;
        }

        int count = 1;
        queue<int> que;
        vector<bool> visited(n,false);

        que.push(root);
        visited[root] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();
            for(auto &v : adj[u]){
                if(!visited[v]){
                    visited[v] = true;
                    count++;
                    que.push(v);
                }
                
            }
        }
        return count == n;
    }
};