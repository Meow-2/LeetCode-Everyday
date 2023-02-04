class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        xor = 0
        # ^ 是异或
        for i in nums:
            xor ^= i
        m = 1
        while m & xor == 0:
            m <<= 1
        target1, target2 = 0, 0
        for i in nums:
            if m & i:
                target1 ^= i
            else:
                target2 ^= i
        return [target1, target2]
