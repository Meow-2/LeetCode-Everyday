class Solution:
    def findRepeatNumber(self, nums: [int]) -> int:
        i = 0
        while i < len(nums):
            if (nums[i] == i):
                i += 1
                continue
            else:
                if nums[i] == nums[nums[i]]:
                    return nums[i]
                nums[nums[i]], nums[i] = nums[i], nums[nums[i]]
        return -1


if __name__ == "__main__":
    Solution().findRepeatNumber([1, 2, 3, 3, 4])
