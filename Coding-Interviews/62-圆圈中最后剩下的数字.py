class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        # f(n) = (f(n-1)+ m%n)%n
        res = 0
        for i in range(1, n+1):
            res = (res + m % i) % i
        return res


if __name__ == '__main__':
    print(Solution().lastRemaining(5, 3))
