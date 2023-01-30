# python int 是没有大小限制的, 所以按位求和的方式是有点问题的, 因为没有符号位
# 使用摩尔投票法
import collections
from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate

# 哈希表法
# class Solution:
# def majorityElement(self, nums: List[int]) -> int:
#     counts = collections.Counter(nums)
#     return max(counts, key=counts.get)

# max(counts, key=counts.get) 是用于从字典 counts 中找出键值对中值最大的键。
# counts.keys()：返回 counts 字典的所有键，作为 max 函数的可迭代对象。
# key=counts.get：是 max 函数的关键字参数，用于指定对比键的大小的函数，这里是使用字典的 get 方法。
# 因此，最终代码的意思是在 counts 字典的键中找到值最大的键，并返回该键。
