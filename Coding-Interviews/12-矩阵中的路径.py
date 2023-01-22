from typing import List


class Solution:
    direction = [(1, 0), (0, 1), (-1, 0), (0, -1)]

    def isExist(self, x: int, y: int, board: List[List[str]], word: str) -> bool:
        if x < 0 or x >= len(board) or y < 0 or y >= len(board[0]):
            return False
        if board[x][y] != word[0]:
            return False
        if len(word) == 1:
            return True
        board[x][y] = '0'
        res = False
        for i, j in self.direction:
            res = res or self.isExist(x+i, y+j, board, word[1:])
        board[x][y] = word[0]  # 回溯
        return res

    def exist(self, board: List[List[str]], word: str) -> bool:
        for x in range(len(board)):
            for y in range(len(board[0])):
                if self.isExist(x, y, board, word):
                    return True
        return False
