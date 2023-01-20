import bisect


# class Solution:
#     def findNumberIn2DArray(self, matrix: list[list[int]], target: int) -> bool:
#         for row in matrix:
#             i = 0
#             j = len(row)-1
#             # [i,j]
#             while i <= j:
#                 # j - i ==1时, mid = j
#                 mid = i + (j - i + 1)//2
#                 if row[mid] == target:
#                     return True
#                 elif row[mid] < target:
#                     i = mid + 1
#                 else:
#                     j = mid - 1
#         return False
# Z字查找, 将矩阵旋转45度就明白了, 从右上角开始作为mid, 每次消除一行或一列
class Solution:
    def findNumberIn2DArray(self, matrix: list[list[int]], target: int) -> bool:
        if matrix == []:
            return False
        x = 0
        y = len(matrix[0]) - 1
        while x < len(matrix) and y >= 0:
            if matrix[x][y] == target:
                return True
            elif matrix[x][y] < target:
                x += 1
            else:
                y -= 1
        return False


if __name__ == "__main__":
    a = [1, 2, 3, 4]
    idx = bisect.bisect_left(a, -1)
    print(idx)
