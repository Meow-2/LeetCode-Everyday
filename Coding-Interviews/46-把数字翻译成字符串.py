
class Solution:
    def translateNum(self, num: int) -> int:
        s = str(num)
        dp = [1]*(len(s)+1)
        for i in range(2, len(s)+1):
            dp[i] = dp[i-1] + (dp[i-2] if "10" <= s[i-2:i] < "26" else 0)
        return dp[len(s)]


if __name__ == '__main__':
    Solution().translateNum(506)
