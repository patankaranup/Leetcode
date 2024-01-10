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
    int result = INT_MIN;
    int solve(TreeNode* root, int start){
        if(!root){
            return 0;
        }
        int left_h = solve(root->left,start);
        int right_h = solve(root->right,start);
        if(root->val == start){
            result = max(left_h,right_h);
            return -1;
        } else if(left_h>=0 && right_h>=0){
            return max(left_h,right_h) + 1;
        } else {
            int dist = abs(left_h) + abs(right_h);
            result = max(result,dist);
            return min(left_h,right_h) -1;
        }

    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root,start);
        return result;
    }
};