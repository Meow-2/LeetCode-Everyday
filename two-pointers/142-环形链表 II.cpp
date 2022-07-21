/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode* detectCycle(ListNode* head)
    {
        auto ptr  = head;
        auto slow = head;
        auto fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
            if (fast && slow == fast) {
                while (slow != ptr) {
                    slow = slow->next;
                    ptr  = ptr->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
// @lc code=end
