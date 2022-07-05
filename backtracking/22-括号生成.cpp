/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void backtrack(int left_bracket, int right_bracket, string& path, vector<string>& res)
    {
        if (left_bracket == 0 && right_bracket == 0) {
            res.push_back(path);
            return;
        }
        if (left_bracket > 0) {
            path.push_back('(');
            backtrack(left_bracket - 1, right_bracket + 1, path, res);
            path.pop_back();
        }
        if (right_bracket > 0) {
            path.push_back(')');
            backtrack(left_bracket, right_bracket - 1, path, res);
            path.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string         path;
        // 剩余可用的左括号数量
        int left_bracket = n;
        // 剩余可用的右括号数量
        int right_bracket = 0;
        backtrack(n, 0, path, res);
        return res;
    }
};
// @lc code=end
