# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# class Solution:
#     def reversePrint(self, head: ListNode) -> List[int]:
#         res = []
#         while head:
#             res.append(head.val)
#             head = head.next
#         return res[::-1]

# 递归写法: 先走至链表末端，回溯时依次将节点值加入列表
class Solution:
    def reversePrint(self, head: ListNode) -> List[int]:
        return self.reversePrint(head.next) + [head.val] if head else []
