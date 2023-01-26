from typing import List


class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        # [0,k)为奇数
        k, i = 0, 0
        for i in range(len(nums)):
            if nums[i] % 2:
                nums[k], nums[i] = nums[i], nums[k]
                k += 1
        return nums
