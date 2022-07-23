/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include <cstddef>
#include <unordered_set>
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        auto                     i = headA;
        auto                     j = headB;
        unordered_set<ListNode*> s;
        while (i || j) {
            if (i) {
                if (s.count(i))
                    return i;
                s.insert(i);
                i = i->next;
            }
            if (j) {
                if (s.count(j))
                    return j;
                s.insert(j);
                j = j->next;
            }
        }
        return nullptr;
    }
};
// @lc code=end
