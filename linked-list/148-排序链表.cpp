/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    // 链表三路快排超时了，，，太悲伤了，，，我写了一晚上啊，，，
    // pair<ListNode*, ListNode*> partition(ListNode* head)
    // {
    //     if (!head)
    //         return {nullptr, nullptr};
    //     auto*     lessThanKHead = new ListNode(0);
    //     ListNode* lessThanK     = lessThanKHead;
    //     ListNode* equalsToK     = head;
    //     ListNode* equalsToKHead = head;
    //     auto*     moreThanKHead = new ListNode(0);
    //     ListNode* moreThanK     = moreThanKHead;
    //     ListNode* cur           = head->next;
    //     while (cur != nullptr) {
    //         if (cur->val < head->val) {
    //             lessThanK->next = cur;
    //             lessThanK       = lessThanK->next;
    //         }
    //         else if (cur->val == head->val) {
    //             equalsToK->next = cur;
    //             equalsToK       = equalsToK->next;
    //         }
    //         else {
    //             moreThanK->next = cur;
    //             moreThanK       = moreThanK->next;
    //         }
    //         cur = cur->next;
    //     }
    //     lessThanK->next   = nullptr;
    //     equalsToK->next   = nullptr;
    //     moreThanK->next   = nullptr;
    //     auto HeadAndTail0 = partition(lessThanKHead->next);
    //     auto HeadAndTail1 = partition(moreThanKHead->next);
    //     if (HeadAndTail0.second)
    //         HeadAndTail0.second->next = equalsToKHead;
    //     equalsToK->next = HeadAndTail1.first;
    //     return {HeadAndTail0.first    ? HeadAndTail0.first
    //             : lessThanKHead->next ? lessThanKHead
    //                                   : equalsToKHead,
    //             HeadAndTail1.second ? HeadAndTail1.second : equalsToK};
    // }
    // ListNode* sortList(ListNode* head)
    // {
    //     auto temp = partition(head);
    //     return temp.first;
    // }
    ListNode* sortList(ListNode* head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        auto* slow = head;
        auto* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto* n         = slow->next;
        slow->next      = nullptr;
        auto* i         = sortList(head);
        auto* j         = sortList(n);
        auto* dummyNode = new ListNode(0, nullptr);
        auto* cur       = dummyNode;
        while (i || j) {
            if (!i) {
                cur->next = j;
                cur       = cur->next;
                j         = j->next;
                continue;
            }
            if (!j) {
                cur->next = i;
                cur       = cur->next;
                i         = i->next;
                continue;
            }
            if (i->val < j->val) {
                cur->next = i;
                cur       = cur->next;
                i         = i->next;
                continue;
            }
            cur->next = j;
            cur       = cur->next;
            j         = j->next;
        }
        ListNode* temp = dummyNode->next;
        delete dummyNode;
        return temp;
    }
};
// @lc code=end
