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
    ListNode* getKthFromEnd(ListNode* head, int k)
    {
        auto cur    = head;
        auto next_k = head;
        for (int i = 0; i < k; i++) {
            next_k = next_k->next;
        }
        while (next_k) {
            next_k = next_k->next;
            cur    = cur->next;
        }
        return cur;
    }
};
