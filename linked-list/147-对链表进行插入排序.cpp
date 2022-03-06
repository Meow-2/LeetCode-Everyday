/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head)
    {
        ListNode* dummyNode = new ListNode(INT_MIN, head);
        ListNode* cur       = head;
        ListNode* sorted    = dummyNode;
        while (cur) {
            if (sorted->val <= cur->val)
                sorted = sorted->next;
            else {
                sorted->next      = cur->next;
                ListNode* compare = dummyNode->next;
                ListNode* pre     = dummyNode;
                while (compare->val < cur->val) {
                    pre     = compare;
                    compare = compare->next;
                }
                pre->next = cur;
                cur->next = compare;
            }
            cur = sorted->next;
        }
        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
};
// @lc code=end
