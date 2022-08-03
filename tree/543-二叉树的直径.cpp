/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 */
#include <tuple>
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
    //过root和不过root的最长路径和高
    tuple<int, int, int> maxPath(TreeNode* root)
    {
        if (!root)
            return make_tuple(0, 0, 0);
        auto [left_ac_root, left_no_root, left_h]    = maxPath(root->left);
        auto [right_ac_root, right_no_root, right_h] = maxPath(root->right);
        return make_tuple(left_h + right_h,
                          max(max(left_ac_root, right_ac_root), max(left_no_root, right_no_root)),
                          1 + max(left_h, right_h));
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        auto [ac_root, no_root, h] = maxPath(root);
        return max(ac_root, no_root);
    }
};
// @lc code=end
