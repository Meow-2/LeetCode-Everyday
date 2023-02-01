class Solution:
    # 数字范围    digit    count     位数数量
    # 1-9         1        9         9 = 9*start*digit
    # 10-99       2        90        180
    # 100-999     3        900       2700
    # start-end
    # 1. 确定n所在数字的位数,记为digit
    # 2. 确定n所在的数字,记为num
    # 3. 确定n是num中的哪一数位,并返回结果
    def findNthDigit(self, n: int) -> int:
        digit, start, count = 1, 1, 9
        while n > count:  # 1.
            n -= count
            start *= 10
            digit += 1
            count = 9 * start * digit
        num = start + (n - 1) // digit  # 2.
        return int(str(num)[(n - 1) % digit])  # 3.
