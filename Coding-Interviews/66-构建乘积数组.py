class Solution:
    def constructArr(self, a: List[int]) -> List[int]:
        res, right = [0]*len(a), [0]*len(a)
        sum = 1
        for i in range(len(right)-1, -1, -1):
            right[i] = sum
            sum *= a[i]
        sum = 1
        for i in range(len(a)):
            res[i] = right[i]*sum
            sum *= a[i]
        return res
