class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        if n == 1:
            return x
        if n < 0:
            n = -n
            x = 1/x
        half = self.myPow(x, n//2)
        if n % 2:
            return half*half*x
        return half*half
