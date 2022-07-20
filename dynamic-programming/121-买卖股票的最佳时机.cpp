/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
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
        int n = prices.size();
        // dp[i]表示第i天买入的股票能卖出的最大价格
        vector<int> dp(n + 1, 0);
        dp[n] = prices[n - 1];
        for (int i = n - 1; i > 0; i--) {
            dp[i] = max(prices[i - 1], dp[i + 1]);
        }
        int max_ = INT_MIN;
        for (int i = 1; i <= n; i++) {
            max_ = max(max_, dp[i] - prices[i - 1]);
        }
        return max_;
    }
};
// @lc code=end
