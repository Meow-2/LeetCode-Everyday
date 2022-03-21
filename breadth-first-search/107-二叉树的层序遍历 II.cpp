/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*>    bfs({root});
        while (!bfs.empty()) {
            vector<int> temp;
            size_t      num = bfs.size();
            for (int i = 0; i < num; i++) {
                auto node = bfs.front();
                bfs.pop();
                if (node->left)
                    bfs.push(node->left);
                if (node->right)
                    bfs.push(node->right);
                temp.push_back(node->val);
            }
            result.push_back(temp);
        }
        return vector<vector<int>>(result.rbegin(), result.rend());
    }
};
// @lc code=end
