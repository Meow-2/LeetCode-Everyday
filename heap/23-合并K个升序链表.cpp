/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    // ListNode* mergeKLists(vector<ListNode*>& lists)
    // {
    //     auto              head = new ListNode();
    //     auto              cur  = head;
    //     vector<ListNode*> list;
    //     for (auto& i : lists)
    //         if (i)
    //             list.push_back(i);
    //     while (!list.empty()) {
    //         ListNode* temp  = nullptr;
    //         auto      index = list.begin();
    //         for (auto i = list.begin(); i != list.end(); i++) {
    //             if (temp) {
    //                 if (temp->val > (*i)->val) {
    //                     temp  = *i;
    //                     index = i;
    //                 }
    //             }
    //             else
    //                 temp = *i;
    //         }
    //         cur->next = temp;
    //         cur       = cur->next;
    //         if (temp->next)
    //             *index = temp->next;
    //         else
    //             list.erase(index);
    //     }
    //     return head->next;
    // }
    struct node
    {
        int       val;
        ListNode* nodeAdress;
        node(int a, ListNode* b) : val(a), nodeAdress(b)
        {}
        bool operator<(const node& a) const
        {
            return this->val > a.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        auto                 head = new ListNode();
        auto                 cur  = head;
        priority_queue<node> q;
        for (auto& i : lists)
            if (i)
                q.push(node(i->val, i));
        while (!q.empty()) {
            auto n = q.top();
            q.pop();
            cur->next = n.nodeAdress;
            cur       = cur->next;
            if (n.nodeAdress->next)
                q.push(node(n.nodeAdress->next->val, n.nodeAdress->next));
        }
        return head->next;
    }
};
// @lc code=end
