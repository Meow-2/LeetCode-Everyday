/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        if (!root)
            return nullptr;
        auto temp   = mirrorTree(root->left);
        auto temp1  = mirrorTree(root->right);
        root->left  = temp1;
        root->right = temp;
        return root;
    }
};
