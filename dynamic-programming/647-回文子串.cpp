/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countSubstrings(string s)
    {
        int    res{0};
        vector dp(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            res++;
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                res++;
            }
        }
        for (int L = 3; L <= s.size(); L++) {
            for (int i = 0; i < s.size(); i++) {
                int j = i + L - 1;
                if (j < s.size()) {
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                    if (dp[i][j])
                        res++;
                }
            }
        }
        return res;
    }
};
// @lc code=end
