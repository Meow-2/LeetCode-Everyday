# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from typing import List
from collections import deque


class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        q, layer, res = deque(), 1, []
        q.append(root)
        while q:
            line = []
            cnt = len(q)
            for i in range(0, cnt):
                node = q.popleft()
                line.append(node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            res.append(line if layer % 2 else line[::-1])
            layer += 1
        return res
