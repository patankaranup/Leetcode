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
    bool checkSymmetry(TreeNode* l, TreeNode* r){
        // both leaf node are null
        if(l == NULL && r == NULL){
            return true;
        }
        // anyone of them is null
        if(l == NULL || r == NULL){
            return false;
        }
        // check the current node and then check left and right of both the node
        if((l->val == r->val) && checkSymmetry(l->left,r->right) && checkSymmetry(l->right,r->left)){
            return true;
        }
        return false;

    }
    bool isSymmetric(TreeNode* root) {
        // return true if root node is null
        if(!root){
            return true;
        }
        return checkSymmetry(root->left, root->right);
    }
};
