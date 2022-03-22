/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> f(n + 1);
        for (int i = 1; i < n + 1; i++) {
            int minfn = INT_MAX;
            for (int j = 1; j * j <= i; j++) {
                minfn = min(minfn, 1 + f[i - static_cast<int>(pow(j, 2))]);
            }
            f[i] = minfn;
        }
        return f[n];
    }
};
// @lc code=end
