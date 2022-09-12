/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        vector<int>      ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                auto top = q.front();
                q.pop();
                ret.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
        }
        return ret;
    }
};
