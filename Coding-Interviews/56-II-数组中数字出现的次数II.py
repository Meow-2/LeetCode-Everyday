class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        for i in range(31):
            sum = 0
            for j in nums:
                sum += 1 if j & (1 << i) else 0
            res |= (1 << i) if sum % 3 else 0
        return res
