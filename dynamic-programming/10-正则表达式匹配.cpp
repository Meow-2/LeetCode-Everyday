/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

#include <iterator>
#include <string>
#include <vector>
using namespace std;
;
// @lc code=start
class Solution
{
public:
    // 失败的方法, 但是也值得记录
    // bool isCharMatch(char a, char b, )
    // {
    //     switch (b) {
    //     case '.': return true;
    //     default: return a == b;
    //     }
    // }
    // bool isMatch(string s, string p)
    // {
    //     int i = 0, j = 0;
    //     while (i < s.size() && j < p.size()) {
    //         if (j + 1 < p.size() && p[j + 1] == '*') {
    //             if (isCharMatch(s[i], p[j])) {
    //                 i++;
    //             }
    //             else
    //                 j = j + 2;
    //         }
    //         else if (isCharMatch(s[i], p[j])) {
    //             i++;
    //             j++;
    //         }
    //         else
    //             return false;
    //     }
    //     if (i < s.size())
    //         return false;
    //     for (; j < p.size(); j = j + 2) {
    //         if (p[j] != '.' && (j + 1 >= p.size() || p[j + 1] != '*'))
    //             return false;
    //     }
    //     return true;
    // }

    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        //当s为空串时,只有p全为*才能匹配成功, 求出了所有的dp[0][]的情况
        for (int i = 1; i <= n; i++) {
            if (p[i - 1] == '*')
                dp[0][i] = dp[0][i - 2];
        }
        //从dp[1][]开始求
        for (int i = 1; i <= m; i++) {
            // dp[][0]一定是无法匹配的false
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    // d[i][j] 有三种情况可能为true
                    //  1. d[i-1][j-2] 为 true, 则 matches(i,j-1) 即可
                    //  2. d[i][j-2] 为 true, a* matches 0 个字符即可
                    //  3. d[i-1][j] 为 true, 则 matches(i,j-1) 为 true 即可
                    dp[i][j] = dp[i][j - 2] || dp[i - 1][j - 2] && matches(i, j - 1) ||
                               dp[i - 1][j] && matches(i, j - 1);
                }
                else {
                    dp[i][j] = matches(i, j) && dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
// int main()
// {
//     Solution a;
//     a.isMatch("aa", "a*");
//     return 0;
// }
// @lc code=end
