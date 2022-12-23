# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: 
Optional[TreeNode]) -> Optional[TreeNode]:
        # check both root nodes are not empty 
        if not root1 and not root2:
            return None
        # get the val of root node for both root
        val1 = root1.val if root1 else 0
        val2 = root2.val if root2 else 0
        # add the values
        root = TreeNode(val1+val2)
        # do the same procees for left and right nodes
        # get left and right val if root 1 or root 2 nodes exist or take 
None and return from the recur call
        root.left = self.mergeTrees(root1.left if root1 else None, 
root2.left if root2 else None) 
        root.right = self.mergeTrees(root1.right if root1 else None, 
root2.right if root2 else None)

        return root

