/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <algorithm>
#include <cstdio>
using namespace std;
// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (n > m)
            swap(m, n);
        long long result = 1;
        for (int i = 0; i < n - 1; i++) {
            result = result * (m - 1 + n - 1 - i) / (i + 1);
            // result *= (m - 1 + n - 1 - i) / (i + 1);
        }
        return result;
    }
};
// @lc code=end
