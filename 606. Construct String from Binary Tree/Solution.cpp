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
    string tree2str(TreeNode* root) {
        if(root == NULL) {
            return "";
        }
        string str = to_string(root->val);
        string left = tree2str(root->left);
        string right = tree2str(root->right);
        // if both are empty print the root        
        if(!root->left && !root->right) {
            return str;
        }
        // if right is empty print only left
        if(!root->right) {
            return str + "(" + left + ")";
        }
        // if left is empty then print empty brackets
        if(!root->left) {
            return str + "()" + "(" + right + ")";
        }
        // if both are present print the format 
        return str + "(" + left + ")" + "(" + right + ")";
    }
};