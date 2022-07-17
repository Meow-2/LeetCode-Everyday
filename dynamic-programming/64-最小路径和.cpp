/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        // dp[i][j] 代表到grid[i][j]的最短路径和
        int                 m = grid.size();
        int                 n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            dp[0][i] = grid[0][i] + dp[0][i - 1];
        for (int j = 1; j < m; j++)
            dp[j][0] = grid[j][0] + dp[j - 1][0];
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[j][i] = min(dp[j][i - 1] + grid[j][i], dp[j - 1][i] + grid[j][i]);
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
