/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root)
    {
        if (!root)
            return {};
        vector<int>      result;
        queue<TreeNode*> bfs({root});
        while (!bfs.empty()) {
            int num = static_cast<int>(bfs.size());
            for (int i = 0; i < num; i++) {
                auto* node = bfs.front();
                bfs.pop();
                if (node->left)
                    bfs.push(node->left);
                if (node->right)
                    bfs.push(node->right);
                if (i == num - 1)
                    result.push_back(node->val);
            }
        }
        return result;
    }
};
// @lc code=end
