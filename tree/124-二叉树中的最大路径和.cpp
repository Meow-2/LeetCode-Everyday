/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */
#include <algorithm>
#include <climits>
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
    //返回以 root 为起点的最大路径和不以 root 为起点的最大路径
    pair<long long, long long> maxPathSum_(TreeNode* root)
    {
        if (!root)
            return {INT_MIN, INT_MIN};
        if (!root->left && !root->right)
            return {root->val, INT_MIN};
        auto [l_root, l_noroot] = maxPathSum_(root->left);
        // printf("root->val: %d, l_root: %d, l_noroot: %d\n", root->val, l_root, l_noroot);
        auto [r_root, r_noroot] = maxPathSum_(root->right);
        // printf("root->val: %d, r_root: %d, r_noroot: %d\n", root->val, r_root, r_noroot);
        return {
            max(max(l_root + root->val, r_root + root->val), (long long)root->val),
            max(max(max(l_noroot, r_noroot), max(l_root, r_root)), l_root + r_root + root->val)};
    }

    int maxPathSum(TreeNode* root)
    {
        auto [x, y] = maxPathSum_(root);
        return max(x, y);
    }
};
// @lc code=end
