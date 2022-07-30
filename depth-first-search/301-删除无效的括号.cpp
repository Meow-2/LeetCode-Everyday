/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 枝剪条件
    int         max_score = 0;
    int         max_len   = 0;
    string      s;
    set<string> res;
    void        backtrack(string& cur, int score, int pos)
    {
        // cout << "cur: " << cur << " score: " << score << " pos: " << pos << '\n';
        if (score < 0 || score > max_score)
            return;
        if (pos == s.size()) {
            if (score != 0)
                return;
            if (cur.size() == max_len) {
                res.insert(cur);
                return;
            }
            if (cur.size() > max_len) {
                res.clear();
                res.insert(cur);
                max_len = static_cast<int>(cur.size());
                return;
            }
            return;
        }
        if (s[pos] == '(') {
            cur.push_back('(');
            backtrack(cur, ++score, ++pos);
            cur.pop_back();
            backtrack(cur, --score, pos);
            return;
        }
        else if (s[pos] == ')') {
            cur.push_back(')');
            backtrack(cur, --score, ++pos);
            cur.pop_back();
            backtrack(cur, ++score, pos);
            return;
        }
        else {
            cur.push_back(s[pos]);
            backtrack(cur, score, ++pos);
            cur.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s_)
    {
        s               = s_;
        int left_count  = 0;
        int right_count = 0;
        for (auto ch : s) {
            if (ch == '(')
                left_count++;
            else if (ch == ')')
                right_count++;
        }
        max_score = min(left_count, right_count);
        string cur;
        backtrack(cur, 0, 0);
        return {res.begin(), res.end()};
    }
};
// @lc code=end
int main()
{
    Solution a;
    a.removeInvalidParentheses("(())))(((((vp)()((");
    for (auto& i : a.res)
        cout << i << '\n';
    return 0;
}