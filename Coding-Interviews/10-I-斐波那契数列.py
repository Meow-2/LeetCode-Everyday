class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        MOD = 10**9+7
        dp = [0]*(n+1)
        dp[0] = 0
        dp[1] = 1
        for i in range(2, n+1):
            dp[i] = dp[i-1] + dp[i-2]
        return dp[n] % MOD


# class Solution:
#     def fib(self, n: int) -> int:
#         MOD = 10 ** 9 + 7
#         if n < 2:
#             return n
#         a, b, c = 0, 0, 1
#         for _ in range(2, n+1):
#             a, b = b, c
#             c = a + b
#         return c % MOD
