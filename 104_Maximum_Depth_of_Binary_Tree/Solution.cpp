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
    int maxDepth(TreeNode* root) {
        // return 0 if root is nu;;
        if(root==NULL) {
            return 0;
        } 
        // find the max depth of the left half
        int lh = maxDepth(root -> left);
        // find the max depth of the right half
        int rh = maxDepth(root -> right);
        // finally return 1 + maximum height of left half or right half
        return  1 + max(lh,rh);
    }
};
