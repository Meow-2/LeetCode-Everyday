import sys
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # dp[i]表示以nums[i]结尾的子数组最大和, 仅判断当前要不要单独成段即可
        dp = [0]*len(nums)
        dp[0] = nums[0]
        res = dp[0]
        for i in range(1, len(nums)):
            dp[i] = max(nums[i], dp[i-1]+nums[i])
            res = max(dp[i], res)
        return res
