# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        res = []

        def serializeRoot(node):
            if not node:
                res.append("#,")
                return
            res.append(str(node.val)+",")
            serializeRoot(node.left)
            serializeRoot(node.right)

        serializeRoot(root)
        return ''.join(res)

    def deserialize(self, data: str):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        idx = 0
        data = data.split(',')[:-1]

        def deserializeStr():
            nonlocal idx
            if idx >= len(data):
                return None
            if data[idx] == '#':
                idx += 1
                return None
            root = TreeNode(int(data[idx]))
            idx += 1
            root.left = deserializeStr()
            root.right = deserializeStr()
            return root

        return deserializeStr()
