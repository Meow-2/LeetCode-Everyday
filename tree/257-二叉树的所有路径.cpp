/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */
#include <cstddef>
#include <stack>
#include <string>
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
// 迭代解法
class Solution
{
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string>   answer;
        TreeNode*        cur = root;
        stack<TreeNode*> stc_node;
        // 记录stack<TreeNode*>中每个节点的路径
        stack<string> stc_path;
        stc_node.push(cur);
        stc_path.push(to_string(cur->val));
        while (!stc_node.empty()) {
            cur = stc_node.top();
            stc_node.pop();
            string path = stc_path.top();
            stc_path.pop();
            if (!cur->right && !cur->left) {
                answer.push_back(path);
            }
            else {
                if (cur->right) {
                    stc_node.push(cur->right);
                    stc_path.push(path + "->" + to_string(cur->right->val));
                }
                if (cur->left) {
                    stc_node.push(cur->left);
                    stc_path.push(path + "->" + to_string(cur->left->val));
                }
            }
        }
        return answer;
    }
};
// 递归解法
// class Solution {
// public:
//     void helper(TreeNode* root,vector<string>& answer,string curr){
//         if(!root)return;
//         if(root->left||root->right)curr+=(to_string(root->val)+"->");
//         else{
//             curr+=(to_string(root->val));
//             answer.push_back(curr);
//         }
//         helper(root->left,answer,curr);
//         helper(root->right,answer,curr);
//     }
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string> answer;
//         string curr="";
//         helper(root,answer,curr);
//         return answer;
//     }
// };
// @lc code=end
