from math import pow
from typing import List


class Solution:
    def printNumbers(self, n: int) -> List[int]:
        max = 0
        for i in range(0, n):
            max += 9*int(pow(10, i))
        res = [i for i in range(1, max+1)]
        return res
