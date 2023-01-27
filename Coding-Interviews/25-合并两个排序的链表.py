# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur1 = l1
        cur2 = l2
        dummy = ListNode(0)
        res = dummy
        while cur1 and cur2:
            if cur1.val <= cur2.val:
                res.next = cur1
                cur1 = cur1.next
            else:
                res.next = cur2
                cur2 = cur2.next
            res = res.next
        res.next = cur1 if cur1 else cur2
        return dummy.next
