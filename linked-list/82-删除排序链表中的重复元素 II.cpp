/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* cur       = dummyNode;
        int       temp      = INT_MIN;
        while (cur->next) {
            if (cur->next->next && cur->next->next->val == cur->next->val)
                temp = cur->next->val;
            if (cur->next->val == temp) {
                ListNode* n = cur->next;
                cur->next   = cur->next->next;
                delete n;
            }
            else {
                cur = cur->next;
            }
        }
        return dummyNode->next;
    }
};
// @lc code=end
