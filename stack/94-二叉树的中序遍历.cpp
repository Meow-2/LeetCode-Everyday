/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int>       result;
        vector<TreeNode*> stack;
        while (root) {
            stack.push_back(root);
            root = root->left;
        }
        while (!stack.empty()) {
            auto* temp = stack.back();
            stack.pop_back();
            result.push_back(temp->val);
            temp = temp->right;
            while (temp) {
                stack.push_back(temp);
                temp = temp->left;
            }
        }
        return result;
    }
};
// @lc code=end
