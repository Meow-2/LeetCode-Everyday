/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* dummyNode      = new ListNode(0, head);
        ListNode* cur            = head;
        ListNode* pre            = dummyNode;
        ListNode* n              = nullptr;
        ListNode* reverseHead    = nullptr;
        ListNode* reverseHeadPre = nullptr;
        int       count          = 0;
        while (cur) {
            count++;
            if (count == 1) {
                reverseHead    = cur;
                reverseHeadPre = pre;
                pre            = cur;
                cur            = cur->next;
                continue;
            }
            if (count == k) {
                count                = 0;
                reverseHeadPre->next = cur;
                reverseHead->next    = cur->next;
            }
            n         = cur->next;
            cur->next = pre;
            pre       = count ? cur : reverseHead;
            cur       = n;
        }
        if (count) {
            cur = pre;
            pre = nullptr;
            while (cur != reverseHead) {
                n         = cur->next;
                cur->next = pre;
                pre       = cur;
                cur       = n;
            }
            cur->next = pre;
        }
        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
};
// @lc code=end
