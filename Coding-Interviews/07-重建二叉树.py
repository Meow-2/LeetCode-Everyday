# Definition for a binary tree node.
import bisect
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        res = TreeNode(preorder[0])
        # idx = bisect.bisect_left(inorder, preorder[0])
        # 不可以用这个, 因为inorder是没有排过序的
        idx = inorder.index(preorder[0])
        res.left = self.buildTree(preorder[1:idx+1], inorder[:idx])
        res.right = self.buildTree(preorder[idx+1:], inorder[idx+1:])
        return res


if __name__ == '__main__':
    Solution().buildTree([3, 9, 20, 15, 7], [9, 3, 15, 20, 7])
