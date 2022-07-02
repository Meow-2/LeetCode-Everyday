/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
#include <vector>
class Solution
{
public:
    void dfs(TreeNode* root, int targetSum, int curSum, std::vector<std::vector<int>>& res,
             std::vector<int> path)
    {
        if (!root)
            return;
        curSum += root->val;
        if (targetSum == curSum && !root->left && !root->right) {
            path.push_back(root->val);
            res.push_back(path);
            return;
        }
        path.push_back(root->val);
        dfs(root->left, targetSum, curSum, res, path);
        dfs(root->right, targetSum, curSum, res, path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int>         path;
        int                 curSum = 0;
        dfs(root, targetSum, curSum, res, path);
        return res;
    }
};
// @lc code=end
