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
    //二刷
    // #define isleft(ch) (ch == '(' || ch == '{' || ch == '[')
    // bool isValid(string s)
    // {
    //     unordered_map<char, char> dict = {{'}', '{'}, {']', '['}, {')', '('}};
    //     stack<char>               stc;
    //     for (auto const& ch : s) {
    //         if (isleft(ch))
    //             stc.push(ch);
    //         else if (!stc.empty() && stc.top() == dict[ch]) {
    //             stc.pop();
    //         }
    //         else {
    //             return false;
    //         }
    //     }
    //     return stc.empty() ? true : false;
    // }
};
// @lc code=end
