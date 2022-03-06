/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // 遍历两遍
    // ListNode* removeNthFromEnd(ListNode* head, int n)
    // {
    //     if (n < 1 || !head)
    //         return nullptr;
    //     auto* dummyNode = new ListNode(0, head);
    //     auto* cur       = head;
    //     int   count     = 0;
    //     while (cur) {
    //         count++;
    //         cur = cur->next;
    //     }
    //     if (n > count)
    //         return nullptr;
    //     int result = count - n + 1;
    //     count      = 0;
    //     cur        = dummyNode;
    //     while (++count < result) {
    //         cur = cur->next;
    //     }
    //     ListNode* temp = cur->next;
    //     cur->next      = cur->next->next;
    //     delete temp;
    //     return dummyNode->next;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto*     dummyNode = new ListNode(0, head);
        ListNode* left      = dummyNode;
        ListNode* right     = dummyNode->next;
        int       count     = 1;
        while (right) {
            if (count < n + 1) {
                count++;
                right = right->next;
            }
            else {
                right = right->next;
                left  = left->next;
            }
        }
        if (count == n + 1) {
            ListNode* temp = left->next;
            left->next     = left->next->next;
            delete temp;
        }
        return dummyNode->next;
    }
};
// @lc code=end
