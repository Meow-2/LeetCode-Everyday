import heapq
# 最小堆


class Solution:
    def nthUglyNumber(self, n: int) -> int:
        hp = [1]
        hashset = {1}
        nums = [2, 3, 5]
        for _ in range(n):
            top = heapq.heappop(hp)
            for i in nums:
                temp = top*i
                if not temp in hashset:
                    hashset.add(temp)
                    heapq.heappush(hp, temp)
        return top
