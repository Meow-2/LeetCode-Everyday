# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        newRoot = TreeNode(root.val)
        newRoot.left = self.mirrorTree(root.right)
        newRoot.right = self.mirrorTree(root.left)
        return newRoot
