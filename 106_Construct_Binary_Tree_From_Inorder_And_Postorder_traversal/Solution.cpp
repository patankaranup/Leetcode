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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd){
        // base case: empty tree
        if(inStart>inEnd || postStart > postEnd){
            return nullptr;
        }
        // root node is the last element of postorder array
        TreeNode* root = new TreeNode(postorder[postEnd]);
        // find the index of root in inorder array
        int i  = inStart;
        for(;i<=inEnd; i++){
            if(inorder[i] == root->val){
                break;
            }
        }
        // calculate the left size and right size of inorder
        int leftSize = i-inStart;
        int rightSize = inEnd-i;

        // recursively build left and right subtrees
        root->left = helper(inorder,postorder, inStart, i-1, postStart, postStart+leftSize - 1);
        root->right = helper(inorder,postorder, i+1, inEnd, postEnd-rightSize, postEnd-1);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || postorder.empty() || inorder.size() != postorder.size()){
            return nullptr;
        }
        int n = inorder.size();
        int inStart = 0;
        int inEnd = n-1;
        int postStart = 0;
        int postEnd = n-1;
        return helper(inorder,postorder, inStart, inEnd, postStart, postEnd);
         
    }
};
