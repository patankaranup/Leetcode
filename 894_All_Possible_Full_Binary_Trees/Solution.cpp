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
    unordered_map<int,vector<TreeNode*>> mp;

    vector<TreeNode*> solve(int n){
        // if even then we cannot construct full binary tree so return empty vector
        if(n%2 == 0){
            return {};
        }
        // if only one node is there then it is complete binary tree we can return the node 
        if(n==1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }
        if(mp.find(n) != mp.end()){
            return mp[n];
        }
        vector<TreeNode*> result;
        
        // we will start from 1 and increase i with +2 since we can only make FBT with odd numbers
        for(int i=1; i<n; i+=2){
            vector<TreeNode*> leftAllFBT = solve(i);
            vector<TreeNode*> rightAllFBT = solve(n-i-1);

            for(auto &L : leftAllFBT){
                for(auto &R : rightAllFBT){
                    TreeNode* root = new TreeNode(0);
                    root->left = L;
                    root->right = R;
                    result.push_back(root);
                }
            }
        }
        return mp[n] = result;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};