/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <queue>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        queue<TreeNode*>    q;
        int                 n = 0;
        if (root) {
            q.push(root);
            n = 1;
        }
        while (!q.empty()) {
            vector<int> temp;
            int         temp_n = 0;
            for (int i = 0; i < n; i++) {
                auto f = q.front();
                q.pop();
                temp.push_back(f->val);
                if (f->left) {
                    q.push(f->left);
                    temp_n++;
                }
                if (f->right) {
                    q.push(f->right);
                    temp_n++;
                }
            }
            n = temp_n;
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end
