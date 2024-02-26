/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // both root nodes are the same, i.e., null
        if (p == null && q == null) {
            return true;
        }
        // any one of the root nodes is the same, return false
        if (p == null || q == null) {
            return false;
        }
        // values are different, return false
        if (p.val != q.val) {
            return false;
        }
        // going to the left and right of the root node (calling recursively dfs)
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
