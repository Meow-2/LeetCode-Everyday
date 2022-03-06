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
    // 简单解法,时间复杂度 O(n)，空间复杂度 O(n)
    // bool isPalindrome(ListNode* head)
    // {
    //     if (!head)
    //         return false;
    //     vector temp;
    //     for (auto* i = head; i; i = i->next) {
    //         temp.push_back(i->val);
    //     }
    //     int left  = 0;
    //     int right = temp.size() - 1;
    //     while (left < right) {
    //         if (temp[left] != temp[right])
    //             return false;
    //         left++;
    //         right--;
    //     }
    //     return true;
    // }
    // 时间复杂度 O(n),空间复杂度
    // O（1），先求中间节点，遍历找到中间节点，反转中间节点之后的链表，然后遍历前后是否一样
    bool isPalindrome(ListNode* head)
    {
        if (!head)
            return false;
        if (!head->next)
            return true;
        // 计数求中间节点
        // int count = 0;
        // for (auto* i = head; i; i = i->next)
        //     count++;
        // auto* mid = head;
        // for (int i = 1; i != count / 2; i++)
        //     mid = mid->next;
        // if (count % 2)
        //     mid = mid->next;
        //快慢指针求中间节点
        ListNode* pre  = nullptr;
        ListNode* n    = nullptr;
        auto*     slow = head;
        auto*     fast = head->next;
        while (fast && fast->next) {
            n          = slow->next;
            slow->next = pre;
            pre        = slow;
            slow       = n;
            fast       = fast->next->next;
        }
        auto* right = slow->next;
        slow->next  = pre;
        auto* left  = fast ? slow : pre;
        while (right) {
            if (left->val != right->val)
                return false;
            right = right->next;
            left  = left->next;
        }
        return true;
    }
};
// @lc code=end
