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
class Dfs {
public:
    // for this problem visualize a binary tree in a array and have the index of root as 1 and left child 2*i and right child 
2*i+1
    int countNodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        return 1 +  countNodes(root->left) + countNodes(root->right);
    }

    bool depthFirstSearch(TreeNode* root, int currentIndex, int totalNodes){
        // if the root is Null then it is a complete binary tree
        if(root == NULL){
            return true;
        }
        // else if index is greter than totalnodes than it is incomplete bt 
        if(currentIndex > totalNodes){
            return false;
        }
        return depthFirstSearch(root->left,2*currentIndex,totalNodes) && 
                depthFirstSearch(root->right,2*currentIndex+1,totalNodes);

    }

    bool isCompleteTree(TreeNode* root) {
        int totalNodes = countNodes(root);
        int currentIndex = 1;
        return depthFirstSearch(root,currentIndex,totalNodes);
    }
};
