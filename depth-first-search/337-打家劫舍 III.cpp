/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */
#include <cstdio>
#include <utility>
using namespace std;
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
    // rob root, not rob root
    pair<int, int> rob_(TreeNode* root)
    {
        if (!root)
            return {0, 0};
        auto p_left     = rob_(root->left);
        auto p_right    = rob_(root->right);
        int  robroot    = root->val + p_left.second + p_right.second;
        int  notrobroot = max(p_left.first, p_left.second) + max(p_right.first, p_right.second);
        // std::printf("rob_(%d): robroot %d, notrobroot %d\n", root->val, robroot, notrobroot);
        return {robroot, notrobroot};
    }

    int rob(TreeNode* root)
    {
        auto res = rob_(root);
        return max(res.first, res.second);
    }
};
// @lc code=end
