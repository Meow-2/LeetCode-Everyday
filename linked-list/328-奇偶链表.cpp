/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    // ListNode* oddEvenList(ListNode* head)
    // {
    //     ListNode* evenHead = nullptr;
    //     ListNode* evenCur  = nullptr;
    //     ListNode* pre      = nullptr;
    //     ListNode* cur      = head;
    //     int       count    = 1;
    //     while (cur != nullptr) {
    //         if (count) {
    //             pre = cur;
    //             cur = cur->next;
    //             count--;
    //         }
    //         else {
    //             if (evenCur) {
    //                 evenCur->next = cur;
    //                 evenCur       = cur;
    //             }
    //             else {
    //                 evenHead = cur;
    //                 evenCur  = cur;
    //             }
    //             pre->next = cur->next;
    //             cur       = cur->next;
    //             count++;
    //         }
    //     }
    //     if (pre)
    //         pre->next = evenHead;
    //     if (evenCur)
    //         evenCur->next = nullptr;
    //     return head;
    // }
    ListNode* oddEvenList(ListNode* head)
    {
        //其实只需要遍历每个偶数节点就好了
        if (!head)
            return head;
        ListNode* evenHead = head->next;
        ListNode* even     = evenHead;
        ListNode* odd      = head;
        while (even != nullptr && even->next != nullptr) {
            odd->next  = even->next;
            odd        = odd->next;
            even->next = even->next->next;
            even       = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end
