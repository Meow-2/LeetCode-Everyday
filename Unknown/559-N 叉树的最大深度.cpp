/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        else
        {
            int maxdepth = 1;
            for (auto child : root->children)
            {
                int depth = 1 + maxDepth(child);
                if (depth > maxdepth)
                    maxdepth = depth;
            }
            return maxdepth;
        }
    }
};
// @lc code=end
