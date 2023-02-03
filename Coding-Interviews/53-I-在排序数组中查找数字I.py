# 排序数组, 考虑二分


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not len(nums):
            return 0
        # 查找左边界
        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + (r-l)//2
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        left, right = 0, -1
        if nums[l] == target:
            left = l
        # 查找右边界, 这时候 l 不必重新初始化为0
        r = len(nums) - 1
        while l < r:
            mid = l + (r-l+1)//2
            if nums[mid] <= target:
                l = mid
            else:
                r = mid - 1
        if nums[r] == target:
            right = r
        return right - left + 1
