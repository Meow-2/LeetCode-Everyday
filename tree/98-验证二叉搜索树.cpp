/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <climits>
#include <stack>
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
    bool isValidBST(TreeNode* root)
    {
        long long        lastNode = LONG_LONG_MIN;
        stack<TreeNode*> stc;
        auto             curNode = root;
        while (curNode) {
            stc.push(curNode);
            curNode = curNode->left;
        }
        while (!stc.empty()) {
            auto topNode = stc.top();
            if (topNode->val <= lastNode)
                return false;
            lastNode = topNode->val;
            stc.pop();
            auto temp = topNode->right;
            while (temp) {
                stc.push(temp);
                temp = temp->left;
            }
        }
        return true;
    }
};
// @lc code=end
