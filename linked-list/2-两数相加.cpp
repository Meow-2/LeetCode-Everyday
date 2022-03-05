/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;{}
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        if (!l1 || !l2)
            return nullptr;
        int       l1Val;
        int       l2Val;
        int       carryBit = 0;
        int       sum      = 0;
        ListNode* result   = nullptr;
        ListNode* cur      = result;
        while (l1 || l2) {
            l1Val    = l1 ? l1->val : 0;
            l2Val    = l2 ? l2->val : 0;
            sum      = l1Val + l2Val + carryBit;
            carryBit = 0;
            if (sum >= 10) {
                sum      = sum % 10;
                carryBit = 1;
            }
            if (result) {
                cur->next = new ListNode(sum);
                cur       = cur->next;
            }
            else {
                result = new ListNode(sum);
                cur    = result;
            }
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carryBit)
            cur->next = new ListNode(carryBit);
        return result;
    }
};
// @lc code=end
