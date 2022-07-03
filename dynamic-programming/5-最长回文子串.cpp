/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        auto length = s.length();
        if (length < 2)
            return s;
        vector<vector<bool>> dp{length, vector<bool>(length, false)};
        auto                 max_length   = 1;
        auto                 max_length_l = 0;
        for (int i = 0; i < length; i++)
            dp[i][i] = true;
        for (int L = 2; L <= length; L++) {
            for (int i = 0; i < length; i++) {
                int j = i + L - 1;
                if (j >= length)
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else {
                    if (j - i + 1 < 4) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (dp[i][j] && max_length < j - i + 1) {
                    max_length   = j - i + 1;
                    max_length_l = i;
                }
            }
        }
        return s.substr(max_length_l, max_length);
    }
};
// @lc code=end
