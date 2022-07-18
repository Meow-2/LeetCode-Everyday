/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */
#include <climits>
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> const& array)
    {
        int         res = 0;
        int         n   = array.size();
        vector<int> left(n, -1), right(n, -1);
        // monotonous, 单调
        stack<int> mono;
        for (int i = 0; i < n; i++) {
            while (!mono.empty() && array[mono.top()] >= array[i])
                mono.pop();
            left[i] = mono.empty() ? -1 : mono.top();
            mono.push(i);
        }
        mono = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!mono.empty() && array[mono.top()] >= array[i])
                mono.pop();
            right[i] = mono.empty() ? n : mono.top();
            mono.push(i);
        }
        for (int i = 0; i < n; i++) {
            res = max(res, array[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int                 res = 0;
        int                 m   = matrix.size();
        int                 n   = matrix[0].size();
        vector<vector<int>> mat(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = matrix[i][j] - '0';
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (mat[i][j] == 1 && mat[i - 1][j] != 0)
                    mat[i][j] = mat[i - 1][j] + 1;
            }
        }
        for (int i = 0; i < m; i++) {
            res = max(res, maxArea(mat[i]));
        }
        return res;
    }
    // 错误
    // int calS(int i, int j, pair<int, int> pa)
    // {
    //     if (pa.first == -1)
    //         return 0;
    //     return (i - pa.first + 1) * (j - pa.second + 1);
    // }
    // int maximalRectangle(vector<vector<char>>& matrix)
    // {
    //     int                            m   = matrix.size();
    //     int                            n   = matrix[0].size();
    //     int                            res = 0;
    //     vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {-1, -1}));
    //     dp[0][0] = matrix[0][0] == '0' ? pair{-1, -1} : pair{0, 0};
    //     res      = max(res, calS(0, 0, dp[0][0]));
    //     for (int i = 1; i < m; i++) {
    //         if (matrix[i][0] == '1') {
    //             dp[i][0] = matrix[i - 1][0] == '0' ? pair{i, 0} : dp[i - 1][0];
    //             printf("dp[%d][%d]={%d,%d}\n", i, 0, dp[i][0].first, dp[i][0].second);
    //             res = max(res, calS(i, 0, dp[i][0]));
    //         }
    //     }
    //     for (int i = 1; i < n; i++) {
    //         if (matrix[0][i] == '1') {
    //             dp[0][i] = matrix[0][i - 1] == '0' ? pair{0, i} : dp[0][i - 1];
    //             printf("dp[%d][%d]={%d,%d}\n", 0, i, dp[0][i].first, dp[0][i].second);
    //             res = max(res, calS(0, i, dp[0][i]));
    //         }
    //     }
    //     for (int i = 1; i < m; i++) {
    //         for (int j = 1; j < n; j++) {
    //             if (matrix[i][j] == '1') {
    //                 if (matrix[i - 1][j] == '0' && matrix[i][j - 1] == '0')
    //                     dp[i][j] = pair{i, j};
    //                 else if (matrix[i - 1][j] != '0' && matrix[i][j - 1] != '0') {
    //                     if (matrix[i - 1][j - 1] == '0')
    //                         dp[i][j] = (i - dp[i - 1][j].first) > (j - dp[i][j - 1].second)
    //                                        ? pair{dp[i - 1][j].first, j}
    //                                        : pair{i, dp[i][j - 1].second};
    //                     else
    //                         dp[i][j] = pair{max(dp[i - 1][j - 1].first, dp[i - 1][j].first),
    //                                         max(dp[i - 1][j - 1].second, dp[i][j -
    //                                         1].second)};
    //                 }
    //                 else if (matrix[i - 1][j] == '0')
    //                     dp[i][j] = pair{i, dp[i][j - 1].second};
    //                 else
    //                     dp[i][j] = pair{dp[i - 1][j].first, j};
    //                 printf("dp[%d][%d]={%d,%d}\n", i, j, dp[i][j].first, dp[i][j].second);
    //                 res = max(res, calS(i, j, dp[i][j]));
    //             }
    //         }
    //     }
    //     return res;
    // }
};
// @lc code=end
int main()
{
    Solution             a;
    vector<vector<char>> x = {{'1', '0', '1', '0', '0'},
                              {'1', '0', '1', '1', '1'},
                              {'1', '1', '1', '1', '1'},
                              {'1', '0', '0', '1', '0'}};
    a.maximalRectangle(x);
}
