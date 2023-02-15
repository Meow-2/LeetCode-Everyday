# class Solution:
# def add(self, a: int, b: int) -> int:
#     # python中没有int
#     x = 0xffffffff
#     a, b = a & x, b & x
#     res, cnt = 0, 0
#     for i in range(32):
#         if a & (1 << i) and b & (1 << i):
#             if cnt:
#                 res |= 1 << i
#             cnt = 1
#         elif a & (1 << i) or b & (1 << i):
#             if cnt:
#                 cnt = 1
#             else:
#                 res |= 1 << i
#                 cnt = 0
#         elif cnt:
#             res |= 1 << i
#             cnt = 0
#     return res if res <= 0x7fffffff else ~(res ^ x)


class Solution:
    def add(self, a: int, b: int) -> int:
        x = 0xffffffff
        a, b = a & x, b & x
        if not b:
            return a if a <= 0x7fffffff else ~(a ^ x)
        else:
            return self.add(a ^ b, (a & b) << 1)
