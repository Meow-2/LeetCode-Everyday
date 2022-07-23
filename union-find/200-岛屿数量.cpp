/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // unordered_map<string, string> uf;
    // int                           count{0};
    // string find(string const& x) { return uf[x] == x ? x : uf[x] = find(uf[x]); }
    // string mapPairToStr(int x, int y) { return to_string(x) + to_string(y); }
    // void   merge(string const& x, string const& y)
    // {
    //     auto root_x = find(x);
    //     auto root_y = find(y);
    //     if (root_x == root_y)
    //         return;
    //     uf[root_y] = root_x;
    //     count--;
    //     return;
    // }
    // int numIslands(vector<vector<char>>& grid)
    // {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             if (grid[i][j] == '1') {
    //                 uf[mapPairToStr(i, j)] = mapPairToStr(i, j);
    //                 count++;
    //                 if (i - 1 >= 0 && grid[i - 1][j] == '1')
    //                     merge(mapPairToStr(i - 1, j), mapPairToStr(i, j));
    //                 if (j - 1 >= 0 && grid[i][j - 1] == '1')
    //                     merge(mapPairToStr(i, j - 1), mapPairToStr(i, j));
    //             }
    //         }
    //     }
    //     return count;
    // }
    bool isInArea(vector<vector<char>>& grid, int i, int j)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;
        return true;
    }
    void dfs(vector<vector<char>>& grid, int i, int j)
    {

        if (!isInArea(grid, i, j))
            return;
        if (grid[i][j] != '1')
            return;
        grid[i][j] = '2';
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i + 1, j);
        return;
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int res = 0;
        int m   = grid.size();
        int n   = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
// @lc code=end
