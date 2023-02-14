import sys
from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # dp[i]第i天卖出的最大利润
        res = 0
        dp = [0] * len(prices)
        for i in range(1, len(prices)):
            dp[i] = max(prices[i] - prices[i-1] + dp[i-1], 0)
            res = max(res, dp[i])
        return res


if __name__ == '__main__':
    print(Solution().maxProfit([7, 1, 5, 3, 6, 4]))
