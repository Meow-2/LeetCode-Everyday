/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        // dp[i][0] 第i天结束后持有股票, 可能是第i天买的, 也可是之前买的
        // dp[i][1] 第i天结束后不持有股票, 且处于冷冻期, 说明是第i天卖的, 第i+1天处于冷冻期
        // dp[i][2] 第i天结束后不持有股票, 且不处于冷冻期, 第i天结束后不处于冷冻期,
        // 所以第i天可以是冷冻期, 也就是第i-1天结束后处于冷冻期

        vector dp(prices.size(), vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]);
    }
};
// @lc code=end
