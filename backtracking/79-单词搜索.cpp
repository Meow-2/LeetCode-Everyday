/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void backtrack(vector<vector<char>> const& board, string const& word, bool& res,
                   vector<vector<bool>>& hasSearch, int i, int j, int searchIndex, int m, int n)
    {
        if (searchIndex >= word.size())
            res = true;
        if (i + 1 < m && !hasSearch[i + 1][j] && board[i + 1][j] == word[searchIndex]) {
            hasSearch[i + 1][j] = true;
            backtrack(board, word, res, hasSearch, i + 1, j, searchIndex + 1, m, n);
            hasSearch[i + 1][j] = false;
        }
        if (j + 1 < n && !hasSearch[i][j + 1] && board[i][j + 1] == word[searchIndex]) {
            hasSearch[i][j + 1] = true;
            backtrack(board, word, res, hasSearch, i, j + 1, searchIndex + 1, m, n);
            hasSearch[i][j + 1] = false;
        }
        if (i - 1 >= 0 && !hasSearch[i - 1][j] && board[i - 1][j] == word[searchIndex]) {
            hasSearch[i - 1][j] = true;
            backtrack(board, word, res, hasSearch, i - 1, j, searchIndex + 1, m, n);
            hasSearch[i - 1][j] = false;
        }
        if (j - 1 >= 0 && !hasSearch[i][j - 1] && board[i][j - 1] == word[searchIndex]) {
            hasSearch[i][j - 1] = true;
            backtrack(board, word, res, hasSearch, i, j - 1, searchIndex + 1, m, n);
            hasSearch[i][j - 1] = false;
        }
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        int                    m   = board.size();
        int                    n   = board[0].size();
        bool                   res = false;
        vector<vector<bool>>   hasSearch(m, vector<bool>(n, false));
        vector<pair<int, int>> root;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    root.emplace_back(i, j);
                }
            }
        }
        while (!res && !root.empty()) {
            int i = root.back().first;
            int j = root.back().second;
            root.pop_back();
            hasSearch[i][j] = true;
            backtrack(board, word, res, hasSearch, i, j, 1, m, n);
            hasSearch[i][j] = false;
        }
        return res;
    }
};
// @lc code=end
