# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def isSame(root1, root2):
            if not root2 and not root1:
                return True
            if not root2 or not root1 or root1.val != root2.val:
                return False
            return isSame(root1.left, root2.right) and isSame(root1.right, root2.left)

        return isSame(root.right, root.left) if root else True
