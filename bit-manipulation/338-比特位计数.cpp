/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector res(n + 1, 0);
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < 32; j++)
                res[i] += i & (1 << j) ? 1 : 0;
        return res;
    }
};
// @lc code=end
