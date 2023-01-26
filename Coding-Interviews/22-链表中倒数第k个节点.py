# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        cnt = 0
        cur, res = head, head
        while cur and cnt < k:
            cur = cur.next
            cnt += 1
        if not cur:
            return head
        while cur:
            res = res.next
            cur = cur.next
        return res
