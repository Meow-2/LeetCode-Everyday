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
    void dfs(TreeNode* root, long long targetSum, int& res)
    {
        if (!root)
            return;
        targetSum -= root->val;
        if (targetSum == 0)
            res += 1;
        dfs(root->left, targetSum, res);
        dfs(root->right, targetSum, res);
    }
    void dfsEveryNode(TreeNode* root, long long targetSum, int& res)
    {
        if (!root)
            return;
        dfs(root, targetSum, res);
        dfsEveryNode(root->left, targetSum, res);
        dfsEveryNode(root->right, targetSum, res);
    }
    int pathSum(TreeNode* root, int targetSum)
    {
        int res = 0;
        dfsEveryNode(root, targetSum, res);
        return res;
    }
};
// @lc code=end
