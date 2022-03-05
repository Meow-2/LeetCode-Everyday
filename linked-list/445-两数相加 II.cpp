/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        vector<int> stack1, stack2, result;
        while (l1) {
            stack1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stack2.push_back(l2->val);
            l2 = l2->next;
        }
        int sum      = 0;
        int carryBit = 0;
        int l1Val    = 0;
        int l2Val    = 0;
        while (!stack1.empty() || !stack2.empty()) {
            l1Val    = stack1.empty() ? 0 : stack1.back();
            l2Val    = stack2.empty() ? 0 : stack2.back();
            sum      = l1Val + l2Val + carryBit;
            carryBit = 0;
            if (sum >= 10) {
                carryBit = 1;
                sum %= 10;
            }
            result.push_back(sum);
            if (!stack1.empty())
                stack1.pop_back();
            if (!stack2.empty())
                stack2.pop_back();
        }
        if (carryBit)
            result.push_back(1);
        auto* l = new ListNode(result.back());
        result.pop_back();
        ListNode* cur = l;
        while (!result.empty()) {
            cur->next = new ListNode(result.back());
            result.pop_back();
            cur = cur->next;
        }
        return l;
    }
};
// @lc code=end
