/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head)
    {
        if (!head)
            return true;
        auto           slow      = head;
        auto           fast      = head;
        auto           slow_next = slow->next;
        decltype(slow) slow_pre  = nullptr;
        bool           isOdd     = false;
        while (fast) {
            fast = fast->next;
            if (!fast) {
                isOdd = true;
                break;
            }
            fast       = fast->next;
            slow->next = slow_pre;
            slow_pre   = slow;
            slow       = slow_next;
            slow_next  = slow->next;
        }
        decltype(slow) mid0 = slow_pre;
        decltype(slow) mid1 = isOdd ? slow_next : slow;
        while (mid0 && mid1) {
            if (mid0->val != mid1->val)
                return false;
            mid0 = mid0->next;
            mid1 = mid1->next;
        }
        return mid0 || mid1 ? false : true;
    }
};
// @lc code=end
