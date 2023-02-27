class Solution:
    def divide(self, a: int, b: int) -> int:
        sign = 1 if a > 0 and b > 0 or a < 0 and b < 0 else 0
        a, b = abs(a), abs(b)
        b_, res, i = b, 0, 1
        while a >= b:
            a -= b
            res += i
            b *= 2
            i *= 2
            if a < b:
                b, i = b_, 1
        res = res if sign else -res
        if res < -2**31 or res > 2**31-1:
            res = 2**31 - 1
        return res


if __name__ == '__main__':
    print(Solution().divide(15, 2))
