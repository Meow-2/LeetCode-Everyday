/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */
#include <memory>
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
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;
        auto i     = head1;
        auto j     = head2;
        auto dummy = make_unique<ListNode>(-1);
        auto cur   = dummy.get();
        while (i || j) {
            if (!i) {
                cur->next = j;
                break;
            }
            if (!j) {
                cur->next = i;
                break;
            }
            if (i->val < j->val) {
                cur->next = i;
                i         = i->next;
                cur       = cur->next;
            }
            else {
                cur->next = j;
                j         = j->next;
                cur       = cur->next;
            }
        }
        return dummy->next;
    }
    ListNode* sort(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        auto mid      = head;
        auto fast     = head;
        auto slow     = head;
        auto pre_slow = head;
        while (fast) {
            pre_slow = slow;
            slow     = slow->next;
            fast     = fast->next;
            if (fast)
                fast = fast->next;
        }
        mid           = pre_slow;
        auto mid_next = mid->next;
        mid->next     = nullptr;
        auto head1    = sort(head);
        auto head2    = sort(mid_next);
        return merge(head1, head2);
    }
    ListNode* sortList(ListNode* head)
    {
        head = sort(head);
        return head;
    }

    // 冒泡排序超时
    // ListNode* sortList(ListNode* head)
    // {
    //     if (!head || !head->next)
    //         return head;
    //     auto dummy = std::make_unique<ListNode>(-1, head);
    //     bool flag  = true;
    //     while (flag) {
    //         flag     = false;
    //         auto cur = dummy->next;
    //         auto pre = dummy.get();
    //         while (cur->next) {
    //             if (cur->next->val < cur->val) {
    //                 flag            = true;
    //                 pre->next       = cur->next;
    //                 cur->next       = cur->next->next;
    //                 pre->next->next = cur;
    //                 pre             = pre->next;
    //             }
    //             else {
    //                 cur = cur->next;
    //                 pre = pre->next;
    //             }
    //         }
    //     }
    //     return dummy->next;
    // }
};
// @lc code=end
