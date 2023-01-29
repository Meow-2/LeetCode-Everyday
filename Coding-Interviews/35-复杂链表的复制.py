"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

# 可以继续优化, 将hash表改为旧节点到新节点的映射, 也是遍历两遍, 但是可以节省空间
# https://leetcode.cn/problems/fu-za-lian-biao-de-fu-zhi-lcof/solution/by-ac_oier-6atv/


class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        res = Node(head.val)
        cur1, cur2 = head, res
        id2order, order2id, cnt = {id(cur1): 0}, [cur2], 1
        cur1 = cur1.next
        while cur1:
            id2order[id(cur1)] = cnt
            cnt += 1
            cur2.next = Node(cur1.val)
            cur1, cur2 = cur1.next, cur2.next
            order2id.append(cur2)
        cur1, cur2 = head, res
        while cur1:
            if cur1.random:
                cur2.random = order2id[id2order[id(cur1.random)]]
            cur1, cur2 = cur1.next, cur2.next
        return res
