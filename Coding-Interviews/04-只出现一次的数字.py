from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            total = sum((num >> i) & 1 for num in nums)
            if total % 3:
                ans |= (1 << i)
        return ~(0xFFFFFFFF ^ ans) if ans & (1 << 31) else ans


if __name__ == '__main__':
    print(Solution().singleNumber([2, 2, 3, 2]))
