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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        auto      cur = head;
        while (cur) {
            auto next_cur = cur->next;
            auto next_pre = cur;
            cur->next     = pre;
            cur           = next_cur;
            pre           = next_pre;
        }
        return pre;
    }
};
