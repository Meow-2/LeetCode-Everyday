class Solution:
    def numWays(self, n: int) -> int:
        if n == 0:
            return 1
        if n == 1:
            return 1
        if n == 2:
            return 2
        dp = [0]*(n+1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2
        for i in range(3, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n] % (10**9+7)

# 滚动数组
# class SolutionL:
#     def numWays(self, n: int) -> int:
#         a, b = 1, 1
#         MOD = 10**9 + 7
#         for _ in range(n):
#             a, b = b, a+b
#         return c % MOD
