import heapq
from typing import List


# 超时
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        hp, res = [], []
        for i in range(k):
            heapq.heappush(hp, (-nums[i], i))
        res.append(-hp[0][0])
        for r in range(k, len(nums)):
            heapq.heappush(hp, (-nums[r], r))
            while hp[0][1] < r - k + 1:
                heapq.heappop(hp)
            res.append(-hp[0][0])
        return res


if __name__ == '__main__':
    Solution().maxSlidingWindow([1, -1], 1)
