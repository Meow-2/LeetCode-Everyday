/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
#include <cmath>
#include <vector>
class Solution
{
public:
    void dfs(TreeNode* root, std::vector<int> path, std::vector<vector<int>>& all_path)
    {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right) {
            all_path.push_back(path);
            return;
        }
        dfs(root->left, path, all_path);
        dfs(root->right, path, all_path);
    }
    int sumNumbers(TreeNode* root)
    {
        vector<vector<int>> all_path;
        vector<int>         path;
        int                 res = 0;
        dfs(root, path, all_path);
        for (auto i : all_path) {
            int sum = 0;
            int k   = 0;
            for (auto j = i.rbegin(); j < i.rend(); j++) {
                sum += *j * pow(10, k);
                k++;
            }
            res += sum;
        }
        return res;
    }
};
// @lc code=end
