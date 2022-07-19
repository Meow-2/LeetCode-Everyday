/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSame(TreeNode* root0, TreeNode* root1)
    {
        if (!root0 && !root1)
            return true;
        if (!root0 || !root1)
            return false;
        if (root0->val != root1->val)
            return false;
        return isSame(root0->left, root1->right) && isSame(root0->right, root1->left);
    }
    bool isSymmetric(TreeNode* root) { return isSame(root->left, root->right); }
};
// @lc code=end
