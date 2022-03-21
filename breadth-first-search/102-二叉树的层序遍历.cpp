/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <memory>
#include <queue>
#include <vector>
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
    std::vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        std::vector<int>              temp_result;
        std::vector<std::vector<int>> result;
        auto*                         thisLayer = new std::queue<TreeNode*>({root});
        auto*                         nextLayer = new std::queue<TreeNode*>();
        while (!thisLayer->empty() || !nextLayer->empty()) {
            auto* node = thisLayer->front();
            thisLayer->pop();
            temp_result.push_back(node->val);
            if (node->left)
                nextLayer->push(node->left);
            if (node->right)
                nextLayer->push(node->right);
            if (thisLayer->empty()) {
                auto x    = thisLayer;
                thisLayer = nextLayer;
                nextLayer = x;
                result.push_back(temp_result);
                temp_result = {};
            }
        }
        delete thisLayer;
        delete nextLayer;
        return result;
    }
};
// @lc code=end
