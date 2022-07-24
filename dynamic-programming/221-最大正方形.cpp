/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m   = matrix.size();
        int n   = matrix[0].size();
        int res = INT_MIN;
        // dp[i][j]表示以matrix[i][j]为右下角的最大正方形的边长
        vector dp(m, vector(n, 0));
        // 遇到错误多检查是不是 base case 写错了
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            res      = max(res, dp[i][0]);
        }
        for (int i = 0; i < n; i++) {
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            res      = max(res, dp[0][i]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                    res      = max(res, dp[i][j]);
                    continue;
                }
                dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
                res      = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
// @lc code=end
