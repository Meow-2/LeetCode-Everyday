/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        vector<vector<int>> result;
        bool                ifReverse = false;
        queue<TreeNode*>    bfs({root});
        while (!bfs.empty()) {
            vector<int> temp;
            int         num = static_cast<int>(bfs.size());
            for (int i = 0; i < num; i++) {
                auto node = bfs.front();
                bfs.pop();
                if (node->left)
                    bfs.push(node->left);
                if (node->right)
                    bfs.push(node->right);
                temp.push_back(node->val);
            }
            if (ifReverse)
                temp = vector<int>(temp.rbegin(), temp.rend());
            result.push_back(temp);
            ifReverse = !ifReverse;
        }
        return result;
    }
};
// @lc code=end
