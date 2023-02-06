import math
from collections import deque
from typing import List


class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res = []
        l, r, sum, win = 1, 0, 0, []  # [l,r]
        half = math.ceil(target/2)
        for r in range(1, half+1):
            sum += r
            win.append(r)
            while sum > target:
                sum -= l
                win.pop(0)
                l += 1
            if sum == target:
                res.append(win[:])
        return res


if __name__ == '__main__':
    Solution().findContinuousSequence(9)
