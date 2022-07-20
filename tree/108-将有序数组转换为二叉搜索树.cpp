/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* buildTree(int left, int right, vector<int>& nums)
    {
        if (left > right)
            return nullptr;
        int  mid    = left + (right - left) / 2;
        auto root   = new TreeNode(nums[mid]);
        root->left  = buildTree(left, mid - 1, nums);
        root->right = buildTree(mid + 1, right, nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) { return buildTree(0, nums.size() - 1, nums); }
};
// @lc code=end
