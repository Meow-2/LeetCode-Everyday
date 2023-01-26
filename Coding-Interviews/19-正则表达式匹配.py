class Solution:

    def isMatch(self, s: str, p: str) -> bool:
        # dp[i][j] s 的前i个和p的前j个是否匹配
        def match(s: str, p: str) -> bool:
            return s == p or p == '.'
        m = len(s)+1
        n = len(p)+1
        dp = [[False]*n for _ in range(m)]
        dp[0][0] = True
        for i in range(2, n):
            if i % 2 == 0 and p[i-1] == '*':
                dp[0][i] = dp[0][i-2]
        for i in range(1, m):
            for j in range(1, n):
                if p[j-1] == '.':
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == '*':
                    dp[i][j] = dp[i][j-1] or dp[i][j-2] or \
                        (dp[i-1][j] and match(s[i-1], p[j-2])) or \
                        (dp[i-1][j-1] and match(s[i-1], p[j-2]))
                else:
                    dp[i][j] = dp[i-1][j-1] and match(s[i-1], p[j-1])

        return dp[len(s)][len(p)]
