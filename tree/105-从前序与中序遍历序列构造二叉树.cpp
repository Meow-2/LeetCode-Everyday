/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
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
    vector<int> pre;
    vector<int> in;
    TreeNode*   buildtree(int l_pre, int r_pre, int l_in, int r_in)
    {
        if (l_pre > r_pre || l_in > r_in)
            return nullptr;
        auto root = new TreeNode(pre[l_pre]);
        int  i;
        for (i = l_in; i <= r_in && in[i] != pre[l_pre]; i++)
            ;
        int length  = i - l_in;
        root->left  = buildtree(l_pre + 1, l_pre + length, l_in, i - 1);
        root->right = buildtree(l_pre + length + 1, r_pre, i + 1, r_in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        pre = preorder;
        in  = inorder;
        return buildtree(0, pre.size() - 1, 0, in.size() - 1);
    }
};
// @lc code=end
