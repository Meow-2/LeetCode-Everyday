/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummyNode = new ListNode(INT_MIN);
        ListNode* cur       = dummyNode;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = new ListNode(list1->val);
                cur       = cur->next;
                list1     = list1->next;
                continue;
            }
            cur->next = new ListNode(list2->val);
            cur       = cur->next;
            list2     = list2->next;
        }
        cur->next        = list2 ? list2 : list1;
        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
};
// @lc code=end
