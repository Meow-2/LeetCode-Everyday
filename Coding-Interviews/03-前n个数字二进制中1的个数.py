from typing import List


# 偶数：二进制表示中，偶数中 1 的个数一定和除以 2 之后的那个数一样多。因为最低位是 0，除以 2 就是右移一位，也就是把那个 0 抹掉而已，所以 1 的个数是不变的

class Solution:
    def countBits(self, n: int) -> List[int]:
        dp = [0]*n
        for i in range(1, n):
            if i % 2:
                dp[i] = dp[i-1]+1
            else:
                continue_1_num = 0
                while (i-1) & (1 << continue_1_num):
                    continue_1_num += 1
                dp[i] = dp[i-1] - continue_1_num + 1
        return dp


if __name__ == '__main__':
    print(Solution().countBits(5))
