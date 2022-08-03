/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        if (!root1 && !root2)
            return nullptr;
        if (root1 && root2) {
            auto r   = new TreeNode(root1->val + root2->val);
            r->left  = mergeTrees(root1->left, root2->left);
            r->right = mergeTrees(root1->right, root2->right);
            return r;
        }
        if (root1) {
            auto r   = new TreeNode(root1->val);
            r->left  = mergeTrees(root1->left, nullptr);
            r->right = mergeTrees(root1->right, nullptr);
            return r;
        }
        auto r   = new TreeNode(root2->val);
        r->left  = mergeTrees(nullptr, root2->left);
        r->right = mergeTrees(nullptr, root2->right);
        return r;
    }
};
// @lc code=end
