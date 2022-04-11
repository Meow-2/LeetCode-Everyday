/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // bool isDvIg(TreeNode* q, TreeNode* p)
    // {
    //     if (q && p && q->val == p->val)
    //         return isDvIg(q->left, p->right) && isDvIg(q->right, p->left);
    //     else if (!q && !p)
    //         return true;
    //     return false;
    // }
    // bool isSymmetric(TreeNode* root)
    // {
    //     if (!root)
    //         return true;
    //     return isDvIg(root->left, root->right);
    // }
    bool isSymmetric(TreeNode* root)
    {
        if (!root)
            return true;
        std::queue<TreeNode*> leftTree{{root->left}};
        std::queue<TreeNode*> rightTree{{root->right}};
        while (!leftTree.empty() && !rightTree.empty()) {
            auto node1 = leftTree.front();
            auto node2 = rightTree.front();
            if (node1 && node2) {
                if (node1->val != node2->val) {
                    return false;
                }
                leftTree.push(node1->left);
                leftTree.push(node1->right);
                rightTree.push(node2->right);
                rightTree.push(node2->left);
            }
            else if (!(!node1 && !node2)) {
                return false;
            }
            leftTree.pop();
            rightTree.pop();
        }
        if (leftTree.empty() && rightTree.empty())
            return true;
        else
            return false;
    }
};

// @lc code=end
