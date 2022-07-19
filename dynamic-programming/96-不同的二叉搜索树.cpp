/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        // dp[i]表示i个递增的数能组成多少二叉搜索树
        // dp[i] = f(1) + f(2) + f(3) + ... + f(i), f(i)表示以i为根的二叉搜索树的数量
        vector dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};
// @lc code=end
