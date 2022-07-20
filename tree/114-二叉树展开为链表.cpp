/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

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
    void flatten(TreeNode* root)
    {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        auto temp  = root->left;
        root->left = nullptr;
        if (!temp)
            return;
        auto cur = temp;
        while (cur->right) {
            cur = cur->right;
        }
        cur->right  = root->right;
        root->right = temp;
        return;
    }
};
// @lc code=end
