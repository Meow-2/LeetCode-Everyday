class Solution:
    def sumNums(self, n: int) -> int:
        return n > 0 and (self.sumNums(n-1) + n)
