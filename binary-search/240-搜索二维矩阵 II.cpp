/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 当搜索的元素在矩阵四个角时会超时, 可能是代码bug, 不想调了,
    // 而且感觉递归这么多次还不如直接遍历快 bool isInArea(int p0, int p1, int p2, int p3)
    // {
    //     if (p0 > p2 || p1 > p3)
    //         return false;
    //     return true;
    // }
    // bool search(int p0, int p1, int p2, int p3, vector<vector<int>> matrix, int target)
    // {
    //     if (!isInArea(p0, p1, p2, p3))
    //         return false;
    //     int mid_m = p0 + (p2 - p0) / 2;
    //     int mid_n = p1 + (p3 - p1) / 2;
    //     if (matrix[mid_m][mid_n] == target)
    //         return true;
    //     bool flag0 = false;
    //     bool flag1 = false;
    //     bool flag2 = false;
    //     if (matrix[mid_m][mid_n] > target) {
    //         flag0 = search(p0, p1, mid_m - 1, mid_n - 1, matrix, target);
    //         flag1 = search(p0, mid_n, mid_m - 1, mid_n, matrix, target);
    //         flag2 = search(mid_m, p1, mid_m, mid_n - 1, matrix, target);
    //     }
    //     else {
    //         flag0 = search(p0, mid_n + 1, mid_m, p3, matrix, target);
    //         flag1 = search(mid_m + 1, p1, p2, mid_n, matrix, target);
    //         flag2 = search(mid_m + 1, mid_n + 1, p2, p3, matrix, target);
    //     }
    //     return flag0 || flag1 || flag2;
    // }
    // bool searchMatrix(vector<vector<int>>& matrix, int target)
    // {
    //     int    m = matrix.size();
    //     int    n = matrix[0].size();
    //     vector isSearch(m, vector<int>(n, 0));
    //     return search(0, 0, m - 1, n - 1, matrix, target);
    // }
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for (const auto& row : matrix) {
            auto it = lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end