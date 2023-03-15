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
class Bfs {
public:
    bool isCompleteTree(TreeNode* root) {
        // using bfs 
        queue<TreeNode*> que;

        que.push(root);

        bool isPastNodeNull = false;
        // loop until the q is not empty
        while(!que.empty()){
            // get the first node of the queue
            TreeNode* node = que.front();
            que.pop();

            if(node == NULL){
                isPastNodeNull = true;
            }
            else {
                if(isPastNodeNull == true){
                    return false;
                } else {
                    que.push(node->left);
                    que.push(node->right);
                }
            }
        }
        return true;
    }
};
