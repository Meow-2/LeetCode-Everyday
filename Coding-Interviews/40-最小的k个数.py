import heapq
from typing import List


# heapq相当与在list上操作
# 使用heapq实现最大堆和最小堆
# https://blog.csdn.net/a284365/article/details/123592517
class Solution:
    def getLeastNumbers(self, arr: List[int], k: int) -> List[int]:
        if not k:
            return []
        hp = []
        for i, e in enumerate(arr):
            if i < k:
                # heapq默认是最小堆, 所以这里 e越大, 越排在前面
                heapq.heappush(hp, (-e, e))
            elif e < hp[0][1]:
                heapq.heappushpop(hp, (-e, e))
        return [x for _, x in hp]
