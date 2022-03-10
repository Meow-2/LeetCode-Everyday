/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    // vector<int> preorderTraversal(TreeNode* root)
    // {
    //     if (!root)
    //         return {};
    //     vector<int> result;
    //     vector<int> temp;
    //     result.push_back(root->val);
    //     for (auto i : preorderTraversal(root->left))
    //         result.push_back(i);
    //     for (auto i : preorderTraversal(root->right))
    //         result.push_back(i);
    //     return result;
    // }
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<TreeNode*> stack;
        vector<int>       result;
        stack.push_back(root);
        while (!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();
            if (node) {
                result.push_back(node->val);
                stack.push_back(node->right);
                stack.push_back(node->left);
            }
        }
        return result;
    }
};
// @lc code=end
