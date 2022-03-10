/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int>       result;
        vector<TreeNode*> stack;
        vector<int>       stack_result;
        if (root)
            stack.push_back(root);
        while (!stack.empty()) {
            auto* top = stack.back();
            stack.pop_back();
            stack_result.push_back(top->val);
            if (top->left)
                stack.push_back(top->left);
            if (top->right)
                stack.push_back(top->right);
        }
        while (!stack_result.empty()) {
            result.push_back(stack_result.back());
            stack_result.pop_back();
        }
        return result;
    }
};
// @lc code=end
