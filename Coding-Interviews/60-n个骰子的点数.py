from typing import List


class Solution:
    def dicesProbability(self, n: int) -> List[float]:
        # dp[i][j] 表示前 i 个骰子和为 j 的概率
        # return dp[i]
        dp = [[0]*(6*n + 1) for _ in range(n+1)]
        dp[1][1:7] = [1/6]*6
        for i in range(2, n+1):
            # 前 n - 1 个骰子的sum, 加上第n个骰子可能的值[1,6]
            for j in range(i-1, 6*(i-1)+1):
                for k in range(1, 7):
                    dp[i][j+k] += dp[i-1][j]/6
        return dp[n][n:]


if __name__ == '__main__':
    print(Solution().dicesProbability(2))
