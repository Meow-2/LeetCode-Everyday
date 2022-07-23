/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        // dp[i]表示以i结尾的最大和
        vector dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = dp[0] + nums[2];
        for (int i = 3; i < n; i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
        return max(dp[n - 1], dp[n - 2]);
    }
};
// @lc code=end
