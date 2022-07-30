/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int  res{0};
    void dfs(TreeNode* root, long long targetSum)
    {
        if (!root)
            return;
        if (root->val == targetSum)
            res++;
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
    }
    void dfsEveryNode(TreeNode* root, long long targetSum)
    {
        if (!root)
            return;
        dfs(root, targetSum);
        dfsEveryNode(root->left, targetSum);
        dfsEveryNode(root->right, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum)
    {
        dfsEveryNode(root, targetSum);
        return res;
    }
};
// @lc code=end
