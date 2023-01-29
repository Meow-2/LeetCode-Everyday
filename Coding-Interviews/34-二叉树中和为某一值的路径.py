# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
        res, path = [], []

        def dfs(node, target):
            if not node:
                return
            target -= node.val
            path.append(node.val)
            if not target and not node.right and not node.left:
                res.append(path[:])
            dfs(node.left, target)
            dfs(node.right, target)
            path.pop()

        dfs(root, target)
        return res

# class Solution:
#     def pathSum(self, root: TreeNode, target: int) -> List[List[int]]:
#         res, path = [], []
#
#         def dfs(node, target, path, res):
#             if not node:
#                 return
#             target -= node.val
#             path.append(node.val)
#             if not target and not node.right and not node.left:
#                 res.append(path[:])
#             dfs(node.left, target, path[:], res)
#             dfs(node.right, target, path[:], res)
#             path.pop()
#
#         dfs(root, target, path, res)
#         return res
#
