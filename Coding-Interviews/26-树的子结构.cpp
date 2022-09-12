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
    bool match(TreeNode* A, TreeNode* B)
    {
        if (!B)
            return true;
        if (!A)
            return false;
        return A->val == B->val && match(A->left, B->left) && match(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        if (!A && !B)
            return true;
        if (!A || !B)
            return false;
        return match(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};
