/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

#include <unordered_map>
using namespace std;
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        vector<int> hashmap(201, 0);
        ListNode*   pre = nullptr;
        ListNode*   cur = head;
        while (cur != nullptr) {
            if (hashmap[cur->val + 100]) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            }
            else {
                hashmap[cur->val + 100] = 1;
                pre                     = cur;
                cur                     = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end