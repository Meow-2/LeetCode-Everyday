/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x)
    {
        ListNode* lessThanXHead = nullptr;
        ListNode* lessThanX     = nullptr;
        ListNode* greaThanXHead = nullptr;
        ListNode* pre           = nullptr;
        ListNode* cur           = head;
        while (cur != nullptr) {
            if (cur->val < x) {
                if (pre)
                    pre->next = cur->next;
                if (lessThanXHead) {
                    lessThanX->next = cur;
                    lessThanX       = cur;
                }
                else {
                    lessThanXHead = cur;
                    lessThanX     = lessThanXHead;
                }
                cur = cur->next;
            }
            else {
                if (!greaThanXHead)
                    greaThanXHead = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        if (lessThanXHead)
            lessThanX->next = greaThanXHead;
        return lessThanXHead == nullptr ? greaThanXHead : lessThanXHead;
    }
};

// @lc code=end
