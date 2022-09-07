/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> reversePrint(ListNode* head)
    {
        vector<int> ret;
        ListNode*   cur = head;
        while (cur) {
            ret.push_back(cur->val);
            cur = cur->next;
        }

        return std::move(vector<int>(ret.rbegin(), ret.rend()));
    }
};
