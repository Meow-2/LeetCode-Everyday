// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1034.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边界着色
 */

// @lc code=start
#include <unordered_map>
using namespace std;
class Solution
{
private:
    vector<pair<int, int>> change;
    bool isConnected[50][50];
    bool isOutOrder(vector<vector<int>> &grid, int row, int col)
    {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size())
            return true;
        else
            return false;
    }
    //判断（row，col）是否为边界，若为边界则将grid的颜色改变,并返回是否可以继续探索
    bool isBorder(vector<vector<int>> &grid, int row, int col, int origin, int color)
    {
        if (grid[row][col] != origin)
            return false;
        else
            isConnected[row][col] = true;
        if (row == 0 || col == 0 || row == grid.size() - 1 || col == grid[0].size() - 1)
        {
            change.push_back({row, col});
            return true;
        }
        if (grid[row][col - 1] != origin || grid[row][col + 1] != origin || grid[row - 1][col] != origin || grid[row + 1][col] != origin)
        {
            change.push_back({row, col});
            return true;
        }
        return true;
    }

    void Border(vector<vector<int>> &grid, int row, int col, int origin, int color)
    {
        if (isBorder(grid, row, col, origin, color))
        {

            if (!isOutOrder(grid, row + 1, col) && !isConnected[row + 1][col])
                Border(grid, row + 1, col, origin, color);
            if (!isOutOrder(grid, row - 1, col) && !isConnected[row - 1][col])
                Border(grid, row - 1, col, origin, color);
            if (!isOutOrder(grid, row, col - 1) && !isConnected[row][col - 1])
                Border(grid, row, col - 1, origin, color);
            if (!isOutOrder(grid, row, col + 1) && !isConnected[row][col + 1])
                Border(grid, row, col + 1, origin, color);
        }
    }

public:
    Solution()
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 50; j++)
                isConnected[i][j] = false;
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int row, int col, int color)
    {
        int origin = grid[row][col];
        Border(grid, row, col, origin, color);
        for (auto i : change)
            grid[i.first][i.second] = color;
        return grid;
    }
};
// @lc code=end
