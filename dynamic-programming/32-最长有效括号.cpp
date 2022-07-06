/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 超时
    // int longestValidParentheses(string s)
    // {
    //     if (s.size() < 2)
    //         return 0;
    //     size_t               max_size = 0;
    //     vector<vector<bool>> dp{s.size(), vector<bool>(s.size(), false)};
    //     // base case
    //     for (int i = 0; i < s.size() - 1; i++) {
    //         if (s[i] == '(' && s[i + 1] == ')') {
    //             dp[i][i + 1] = true;
    //             max_size     = 2;
    //             // string a     = dp[i][i + 1] ? "true" : "false";
    //             // cout << "i:" << i << ' ' << "j:" << i + 1 << ' ' << a << '\n';
    //         }
    //     }
    //     for (int L = 4; L <= s.size(); L += 2) {
    //         for (int i = 0; i + L - 1 < s.size(); i++) {
    //             int j    = i + L - 1;
    //             dp[i][j] = (dp[i + 1][j - 1] && s[i] == '(' && s[j] == ')') ||
    //                        (dp[i + 2][j] && s[i] == '(' && s[i + 1] == ')') ||
    //                        (dp[i][j - 2] && s[j - 1] == '(' && s[j] == ')');
    //             for (int l = 2; l < L; l += 2)
    //                 if (dp[i][i + l - 1] && dp[i + l][j])
    //                     dp[i][j] = true;
    //             // string a = dp[i][j] ? "true" : "false";
    //             // cout << "i:" << i << ' ' << "j:" << j << ' ' << a << '\n';
    //             if (dp[i][j])
    //                 max_size = L;
    //         }
    //     }
    //     return max_size;
    // }

    int longestValidParentheses(string s)
    {
        int         maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};
// @lc code=end
