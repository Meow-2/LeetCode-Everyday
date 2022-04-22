/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // int hight(TreeNode* root)
    // {
    //     if (!root)
    //         return 0;
    //     return std::max(hight(root->left), hight(root->right)) + 1;
    // }

    // bool isBalanced(TreeNode* root)
    // {
    //     if (root == nullptr)
    //         return true;
    //     return std::abs(hight(root->left) - hight(root->right)) <= 1 && isBalanced(root->right)
    //     &&
    //            isBalanced(root->left);
    // }

    int hight(TreeNode* root)
    {
        if (!root)
            return 0;
        int left  = hight(root->left);
        int right = hight(root->right);
        if (left == -1 || right == -1 || abs(right - left) > 1)
            return -1;
        return max(right, left) + 1;
    }
    bool isBalanced(TreeNode* root)
    {
        return hight(root) >= 0;
    }
};
// @lc code=end
