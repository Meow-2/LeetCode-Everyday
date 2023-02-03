# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        cnt = 0
        res = -1

        def dfs(root: TreeNode):
            # 也可以使用类变量来维护 cnt,res, 就不用写nonlocal声明了
            # 而需要使用self.cnt, self.res
            nonlocal cnt, res
            if not root:
                return
            dfs(root.right)
            # 提前返回, 在回溯的过程中, 如果cnt 已经满足条件, 则直接返回
            if cnt == k:
                return
            cnt += 1
            if cnt == k:
                res = root.val
            dfs(root.left)

        dfs(root)
        return res
