/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    unordered_map<int, int> hash;
    bool check(vector<int>& preorder, vector<int>& inorder, int pre_index0, int pre_index1,
               int in_index0, int in_index1)
    {
        if (pre_index0 > pre_index1 || in_index0 > in_index1)
            return false;
        if (pre_index0 < 0 || pre_index0 > preorder.size() - 1)
            return false;
        if (pre_index1 < 0 || pre_index1 > preorder.size() - 1)
            return false;
        if (in_index0 < 0 || in_index0 > inorder.size() - 1)
            return false;
        if (in_index1 < 0 || in_index1 > inorder.size() - 1)
            return false;
        return true;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_index0, int pre_index1,
                    int in_index0, int in_index1)
    {
        if (!check(preorder, inorder, pre_index0, pre_index1, in_index0, in_index1))
            return nullptr;
        auto root   = new TreeNode(preorder[pre_index0]);
        int  i      = hash[preorder[pre_index0]];
        root->left  = build(preorder, inorder, pre_index0 + 1, pre_index0 + (i - in_index0),
                            in_index0, i - 1);
        root->right = build(preorder, inorder, pre_index0 + (i - in_index0) + 1, pre_index1, i + 1,
                            in_index1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
