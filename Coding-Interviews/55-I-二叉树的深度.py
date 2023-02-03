# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:

        # 这其实是后序遍历
        def dfs(root: TreeNode) -> int:
            if not root:
                return 0
            return max(dfs(root.left), dfs(root.right))+1
        return dfs(root)
