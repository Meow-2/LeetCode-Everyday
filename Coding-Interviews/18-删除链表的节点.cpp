#include <memory>
using namespace std;
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
    ListNode* deleteNode(ListNode* head, int val)
    {
        auto dummy  = make_unique<ListNode>(0);
        dummy->next = head;
        auto pre    = dummy.get();
        auto cur    = head;
        while (cur) {
            if (cur->val == val)
                break;
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return dummy->next;
    }
};
