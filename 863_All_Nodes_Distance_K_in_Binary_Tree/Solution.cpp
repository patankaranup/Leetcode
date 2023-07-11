class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    void addParentNode(TreeNode* root) {
        if(!root){
            return;
        }
        if(root->left){
            parent[root->left] = root;
        }
        addParentNode(root->left);
        
        if(root->right){
            parent[root->right] = root;
        }
            
        addParentNode(root->right);
    }
    
    void BFS(TreeNode* target, int k, vector<int>& result) {
        
        queue<TreeNode*> que;
        que.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);
        
        while(!que.empty()) {
            
            int n = que.size();
            if(k == 0){
                break;
            }
            while(n--) {
                TreeNode* curr = que.front();
                que.pop();
                // for left child
                if(curr->left && !visited.count(curr->left->val)) {
                    que.push(curr->left);
                    visited.insert(curr->left->val);
                }
                // for right child
                if(curr->right && !visited.count(curr->right->val)) {
                    que.push(curr->right);
                    visited.insert(curr->right->val);
                }
                // for parent
                if(parent.count(curr) && !visited.count(parent[curr]->val)) {
                    que.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            k--;
        }
        // after we have traverse k levels return the elements that are in queue
        while(!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        
        addParentNode(root);
        
        BFS(target, k, result);
        return result;
    }
};

