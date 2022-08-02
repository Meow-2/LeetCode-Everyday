/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
            res += (x & (1 << i)) ^ (y & (1 << i)) ? 1 : 0;
        return res;
    }
};
// @lc code=end
