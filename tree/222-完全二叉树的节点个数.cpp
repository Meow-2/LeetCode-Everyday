/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    // int countNodes(TreeNode* root)
    // {
    //     if (!root)
    //         return 0;
    //     return countNodes(root->left) + countNodes(root->right) + 1;
    // }
    bool isExist(TreeNode* root, int level, int k)
    {
        int       bits = 1 << (level - 1);
        TreeNode* node = root;
        while (node != nullptr && bits > 0) {
            if ((bits & k) == 0) {
                node = node->left;
            }
            else {
                node = node->right;
            }
            bits >>= 1;
        }
        return node != nullptr;
    }
    int countNodes(TreeNode* root)
    {
        if (!root)
            return 0;
        int  treeHeight = 0;
        auto temp       = root->left;
        while (temp) {
            treeHeight++;
            temp = temp->left;
        }
        int minCount = static_cast<int>(pow(2, treeHeight));
        int maxCount = static_cast<int>(pow(2, treeHeight + 1) - 1);
        int midCount = minCount + (maxCount - minCount + 1) / 2;
        while (minCount < maxCount) {
            if (isExist(root, treeHeight, midCount))
                minCount = midCount;
            else
                maxCount = midCount - 1;
            midCount = maxCount - (maxCount - minCount) / 2;
        }
        return minCount;
    }
};
// @lc code=end
