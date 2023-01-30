"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""

# 使用中序遍历构造也可以


class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        def trans(node):
            if not node:
                return None, None
            head, node.left = trans(node.left)
            if node.left:
                node.left.right = node
            node.right, tail = trans(node.right)
            if node.right:
                node.right.left = node
            return head if head else node, tail if tail else node

        if not root:
            return None
        head, tail = trans(root)
        head.left = tail
        tail.right = head
        return head
