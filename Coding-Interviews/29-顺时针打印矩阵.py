from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        def printCircle(startX, startY, lengthX, lengthY, res: List[int]):
            for i in range(0, lengthX):
                res.append(matrix[startX][startY+i])
            for i in range(0, lengthY-2):
                res.append(matrix[startX + 1 + i][startY+lengthX-1])
            if lengthY > 1:
                for i in range(0, lengthX):
                    res.append(matrix[startX + lengthY - 1]
                               [startY + lengthX - 1 - i])
            if lengthX > 1:
                for i in range(0, lengthY-2):
                    res.append(matrix[startX + lengthY - 2 - i][startY])
        res = []
        lenY = len(matrix)
        lenX = len(matrix[0])
        for i in range(0, (min(lenX, lenY) + 1)//2):
            printCircle(i, i, lenX - 2*i, lenY-2*i, res)
        return res


if __name__ == '__main__':
    print(Solution().spiralOrder([[7], [9], [6]]))
