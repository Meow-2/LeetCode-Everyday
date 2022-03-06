/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head)
            return nullptr;
        int       count = 0;
        ListNode* pre   = nullptr;
        for (auto* cur = head; cur; cur = cur->next) {
            pre = cur;
            count++;
        }
        k = k % count;
        if (!k)
            return head;
        count     = count - k;
        auto* cur = head;
        for (int i = 1; i != count; i++) {
            cur = cur->next;
        }
        auto* result = cur->next;
        cur->next    = nullptr;
        pre->next    = head;
        return result;
    }
};
// @lc code=end
