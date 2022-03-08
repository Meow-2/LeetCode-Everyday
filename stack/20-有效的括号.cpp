/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        int a[256];
        a[']'] = '[';
        a[')'] = '(';
        a['}'] = '{';
        stack<char> st;
        for (auto ch : s) {
            if (st.empty() || ch == '[' || ch == '(' || ch == '{')
                st.push(ch);
            else if (st.top() == a[ch])
                st.pop();
            else
                return false;
        }
        return st.empty() ? true : false;
    }
};
// @lc code=end
