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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (!root)
            return {};
        vector<vector<int>> ret;
        queue<TreeNode*>    q;
        q.push(root);
        while (!q.empty()) {
            vector<int> cur;
            auto        cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                auto front = q.front();
                q.pop();
                cur.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            ret.push_back(cur);
        }
        return ret;
    }
};
