/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), 
left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& result){
        if (root == NULL){
            return ;
        } 
        // ( PLR (Print Left Right) )
        result.push_back(root->val); // visit the val
        preorder(root->left,result); // check for left val
        preorder(root->right, result); // check for right val
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result ;

        preorder(root,result);

        return result;
    }
};
