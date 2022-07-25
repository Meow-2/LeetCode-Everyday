/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // int numSquares(int n)
    // {
    // dp[i]表示 i 的完全平方数的最少数量
    //     vector dp(n + 1, 0);
    //     dp[0] = 0;
    //     vector<int> perfect_squares;
    //     for (int i = 1; i < n + 1; i++) {
    //         if (i * i < n + 1)
    //             dp[i * i] = 1;
    //         if (dp[i] == 1) {
    //             perfect_squares.push_back(i);
    //             continue;
    //         }
    //         int min_ = INT_MAX;
    //         for (auto j : perfect_squares)
    //             min_ = min(min_, 1 + dp[i - j]);
    //         dp[i] = min_;
    //     }
    //     return dp[n];
    // }
    int numSquares(int n)
    {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};
// @lc code=end