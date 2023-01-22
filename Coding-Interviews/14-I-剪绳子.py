# 一维dp, 注意这里的max有三个值, 因为 dp 存的是切成 m 段的最大积, 而 m > 1, 所以至少切两段
# 而计算dp[n]的时候,已经满足了m>1,所以需要比较dp[i-j]和i-j
class Solution:
    def cuttingRope(self, n: int) -> int:
        dp = [0]*(n+1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n+1):
            for j in range(1, i):
                dp[i] = max(dp[i], j*dp[i-j], j*(i-j))
        return dp[n]
