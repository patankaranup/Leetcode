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
class Solution1 {
public:
    int cnt = 0;
    void solve(TreeNode* root, int value){
        if(!root) return;
        // make the bit set for the curr root val 
        value = (value ^ (1 << root->val)); 

        if(!root->left && !root->right){
            // count the number of set bits in the value
            if((value & (value-1)) == 0){
                cnt += 1;
            }
        }
        solve(root->left,value);
        solve(root->right,value);
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root,0);
        return cnt;
    }
};