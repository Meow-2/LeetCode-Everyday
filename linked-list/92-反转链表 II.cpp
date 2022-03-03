/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* n;
        size_t    count = 1;
        ListNode* leftPre;
        ListNode* leftCur;
        while (cur != nullptr && count < right + 1) {
            // 遍历链表会改变的只有当前节点，所以先保存当前节点的指针
            n = cur->next;
            if (count == left) {
                leftPre = pre;
                leftCur = cur;
            }
            else if (count > left) {
                if (count == right) {
                    if (leftPre)
                        leftPre->next = cur;
                    leftCur->next = n;
                }
                cur->next = pre;
            }
            pre = cur;
            cur = n;
            count++;
        }
        return left == 1 ? pre : head;
    }
};
// @lc code=end
