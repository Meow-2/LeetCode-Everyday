# from typing import List
#
#
# class Solution:
#     def minArray(self, numbers: List[int]) -> int:
#         if len(numbers) == 1:
#             return numbers[0]
#         if numbers[0] < numbers[-1]:
#             return numbers[0]
#         for i in numbers:
#             if i < numbers[0]:
#                 return i
#         return numbers[0]

# 二分法
# 二分法的精髓在与如何确定target的区间, 也就是如何缩小这个区间
# 这里可以将nums[mid]和nums[j]比较
from typing import List


class Solution:
    def minArray(self, numbers: List[int]) -> int:
        i, j = 0, len(numbers)-1
        while i < j:
            mid = i + (j-i)//2
            if numbers[mid] < numbers[j]:
                j = mid
            elif numbers[mid] > numbers[j]:
                i = mid+1
            else:
                j -= 1
        return numbers[i]
