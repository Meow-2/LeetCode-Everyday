/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <type_traits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // void rotateRange(int left, int right, vector<vector<int>>& matrix)
    // {
    //     if (left >= right)
    //         return;
    //     int len              = right - left;
    //     int temp0            = matrix[left][right];
    //     matrix[left][right]  = matrix[left][left];
    //     int temp1            = matrix[right][right];
    //     matrix[right][right] = temp0;
    //     int temp2            = matrix[right][left];
    //     matrix[right][left]  = temp1;
    //     matrix[left][left]   = temp2;
    //     // matrix[left][left];
    //     // matrix[left][right]
    //     // matrix[right][right]
    //     // matrix[right][left]
    //     for (int i = 1; i < len; i++) {
    //         temp0                    = matrix[left + i][right];
    //         matrix[left + i][right]  = matrix[left][left + i];
    //         temp1                    = matrix[right][right - i];
    //         matrix[right][right - i] = temp0;
    //         temp2                    = matrix[right - i][left];
    //         matrix[right - i][left]  = temp1;
    //         matrix[left][left + i]   = temp2;
    //     }
    //     rotateRange(left + 1, right - 1, matrix);
    // }
    // void rotate(vector<vector<int>>& matrix)
    // {
    //     rotateRange(0, matrix.size() - 1, matrix);
    //     return;
    // }
    void rotateRange(int left, int right, vector<vector<int>>& matrix)
    {
        if (left >= right)
            return;
        for (int i = 0; i < right - left; i++) {
            int temp                 = matrix[left][left + i];
            matrix[left][left + i]   = matrix[right - i][left];
            matrix[right - i][left]  = matrix[right][right - i];
            matrix[right][right - i] = matrix[left + i][right];
            matrix[left + i][right]  = temp;
        }
        rotateRange(left + 1, right - 1, matrix);
    }
    void rotate(vector<vector<int>>& matrix)
    {
        rotateRange(0, matrix.size() - 1, matrix);
        return;
    }
};
// @lc code=end
