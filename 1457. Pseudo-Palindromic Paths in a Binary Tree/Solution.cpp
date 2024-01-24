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
    int cnt = 0;
    void solve(TreeNode* root, vector<int> &freq){
        if(!root) return;
        freq[root->val]++; 
        if(!root->left && !root->right){
            int odd_cnt = 0;
            for(int i=0; i<10; i++){
                if(freq[i] % 2 != 0){
                    odd_cnt++;
                }
            }
            if(odd_cnt<=1){
                cnt++;
            }
        }
        solve(root->left,freq);
        solve(root->right,freq);
        freq[root->val]--; 
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        solve(root,freq);
        return cnt;
    }
};