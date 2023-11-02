class Solution {
public:
    void inorder(TreeNode* root, vector<TreeNode*>&arr){
        if (!root) return ;
        inorder(root -> left,arr);
        arr.push_back(root);
        inorder(root -> right,arr);
    }
    int BFS_WithAVG(TreeNode* root){
        int avg = 0;
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            avg += node -> val;
            count++;
            if (node->left){
                q.push(node->left);
            }
            if (node -> right){
                q.push(node->right);
            }
        }
        return avg/count;
    }
    int averageOfSubtree(TreeNode* root) {
        vector<TreeNode*>arr;
        inorder(root,arr);
        int count = 0;
        for (int i = 0; i < arr.size(); i++){
            if (arr[i]->val == BFS_WithAVG(arr[i])){
                count++;
            }
        }
        return count;
    }
};