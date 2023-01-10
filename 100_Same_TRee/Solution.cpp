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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both root node are same that is null 
        if (p==NULL && q==NULL){
            return true;
        }
        // any of the one root node is same return false
        if (p==NULL || q==NULL){
            return false;
        }
        // value is also same if not return false
        if (p-> val != q->val){
            return false;
        }

        // going to right and left of the root node (calling recursively dfs)
        return isSameTree(p->left, q-> left) && isSameTree(p->right,q->right);

    }
};
