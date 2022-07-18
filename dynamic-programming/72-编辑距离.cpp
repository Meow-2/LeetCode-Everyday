/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int                 m = word1.size();
        int                 n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= n; i++) {
            dp[0][i] = i;
        }
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = min(dp[j][i - 1] + 1, dp[j - 1][i] + 1);
                dp[j][i] = min(dp[j][i], (word1[j - 1] == word2[i - 1] ? dp[j - 1][i - 1]
                                                                       : (dp[j - 1][i - 1] + 1)));
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
