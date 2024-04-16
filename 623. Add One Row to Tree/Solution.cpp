/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth, int curr){
        if(!root){
            return NULL;
        }
        if(curr == depth-1){
            TreeNode* oldLeft = root->left;
            TreeNode* rightLeft = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            root->left->left = oldLeft;
            root->right->right = rightLeft;
            return root;
        }
        root->left  = solve(root->left, val, depth, curr+1);
        root->right = solve(root->right, val, depth, curr+1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        return solve(root, val, depth, 1);
    }
};