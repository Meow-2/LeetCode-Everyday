# 这题也可以二分, 二分只要能保证, 可以通过当前条件缩小[left,right]即可
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        left, right = 0, len(nums)
        while left < right:
            mid = left + (right - left)//2
            if mid < nums[mid]:
                right = mid
            else:
                left = left + 1
        return right
