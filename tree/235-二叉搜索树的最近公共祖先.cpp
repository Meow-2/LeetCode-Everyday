/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
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
    // TreeNode* res{nullptr};
    // bool      dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    // {
    //     if (!root)
    //         return false;
    //     bool l = dfs(root->left, p, q);
    //     bool r = dfs(root->right, p, q);
    //     if ((l && r) || ((root == p || root == q) && (l || r)))
    //         res = root;
    //     return l || r || root == p || root == q;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    // {
    //     dfs(root, p, q);
    //     return res;
    // }
    void backtrack(TreeNode* cur, TreeNode* p, vector<TreeNode*>& path, vector<TreeNode*>& p_path)
    {
        if (!cur)
            return;
        if (cur == p) {
            // cout << path[0] << '\n';
            p_path = path;
            // cout << p_path[0] << '\n';
            return;
        }
        // if (cur->left) {
        path.push_back(cur->left);
        backtrack(cur->left, p, path, p_path);
        path.pop_back();
        // }

        // if (cur->right) {
        path.push_back(cur->right);
        backtrack(cur->right, p, path, p_path);
        path.pop_back();
        // }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // cout << "root:" << root;
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;
        vector<TreeNode*> path = {root};
        path.push_back(root);
        // cout << "path_root:" << path[0] << '\n';
        backtrack(root, p, path, p_path);
        backtrack(root, q, path, q_path);
        // cout << p_path << '\n';
        // cout << q_path << '\n';
        int i = 0;
        for (i = 0; i < p_path.size() && i < q_path.size() && p_path[i] == q_path[i]; i++)
            ;
        return p_path[i - 1];
    }
};
// @lc code=end
