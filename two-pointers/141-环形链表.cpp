/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        auto slow = head;
        auto fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (fast && fast == slow)
                return true;
        }
        return false;
    }
};
// @lc code=end
