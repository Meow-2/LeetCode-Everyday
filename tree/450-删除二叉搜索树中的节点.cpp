/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    TreeNode* dfs(TreeNode* root, int key)
    {
        if (!root)
            return root;
        if (root->val == key) {
            auto cur = root->right;
            if (!cur)
                root->right = root->left;
            else {
                while (cur->left)
                    cur = cur->left;
                cur->left = root->left;
            }
            root->left = nullptr;
            return root->right;
        }
        root->left  = dfs(root->left, key);
        root->right = dfs(root->right, key);
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        root = dfs(root, key);
        return root;
    }
};
// @lc code=end
