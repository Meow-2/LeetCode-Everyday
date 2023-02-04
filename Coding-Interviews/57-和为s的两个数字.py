# 双指针
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        l, r = 0, len(nums)-1
        while l < r:
            if target - nums[l] == nums[r]:
                return [nums[l], nums[r]]
            elif target - nums[l] > nums[r]:
                l += 1
            else:
                r -= 1
        return None
