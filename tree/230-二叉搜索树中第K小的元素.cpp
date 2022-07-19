/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */
#include <stack>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int              count = 0;
        stack<TreeNode*> s;
        auto             cur = root;
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        while (!s.empty()) {
            auto top = s.top();
            s.pop();
            if (++count == k) {
                return top->val;
            }
            auto temp = top->right;
            while (temp) {
                s.push(temp);
                temp = temp->left;
            }
        }
        return 0;
    }
};
// @lc code=end
