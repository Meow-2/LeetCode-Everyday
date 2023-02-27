
# 使用位运算模拟二进制加法
# from collections import deque
#
#
# class Solution:
#     def addBinary(self, a, b) -> str:
#         x, y = int(a, 2), int(b, 2)
#         while y:
#             answer = x ^ y
#             carry = (x & y) << 1
#             x, y = answer, carry
#         return bin(x)[2:]


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = list(a)
        b = list(b)
        res, cnt = deque(), 0
        for i in range(max(len(a), len(b))):
            a_bit = int(a[-1-i]) if i < len(a) else 0
            b_bit = int(b[-1-i]) if i < len(b) else 0
            sum = a_bit + b_bit + cnt
            if sum > 1:
                cnt = 1
                sum -= 2
            else:
                cnt = 0
            res.appendleft(str(sum))
        if cnt:
            res.appendleft(str(cnt))
        return ''.join(res)


if __name__ == '__main__':
    print(Solution().addBinary("1010", "1011"))
