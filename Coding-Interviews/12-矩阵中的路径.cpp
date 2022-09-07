#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         rows = board.size();
//         cols = board[0].size();
//         for(int i = 0; i < rows; i++) {
//             for(int j = 0; j < cols; j++) {
//                 if(dfs(board, word, i, j, 0)) return true;
//             }
//         }
//         return false;
//     }
// private:
//     int rows, cols;
//     bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
//         if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
//         if(k == word.size() - 1) return true;
//         board[i][j] = '\0';
//         bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) ||
//                       dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
//         board[i][j] = word[k];
//         return res;
//     }
// };
//

class Solution
{
public:
    vector<vector<char>> board_;
    string               word_;

    bool isArea(int x, int y, vector<vector<bool>> const& path)
    {
        if (x < 0 || x > board_.size() - 1)
            return false;
        if (y < 0 || y > board_[0].size() - 1)
            return false;
        if (path[x][y])
            return false;
        return true;
    }
    bool dfs(int x, int y, int index, vector<vector<bool>>& path)
    {
        if (!isArea(x, y, path))
            return false;
        if (board_[x][y] != word_[index])
            return false;
        index++;
        if (index == word_.size())
            return true;
        path[x][y] = true;
        auto ret   = dfs(x + 1, y, index, path) || dfs(x - 1, y, index, path) ||
                   dfs(x, y + 1, index, path) || dfs(x, y - 1, index, path);
        path[x][y] = false;
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        board_ = board;
        word_  = word;
        vector<vector<bool>> path(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(i, j, 0, path))
                    return true;
            }
        }
        return false;
    }
};
