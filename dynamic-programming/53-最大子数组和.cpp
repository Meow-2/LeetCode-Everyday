/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        // dp[i] 表示以下标i结尾的最大子序列和, 故只需要找出最大的dp[i]即可
        vector<int> dp(nums.size(), INT_MIN);
        dp[0]      = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[i]  = dp[i - 1] > 0 ? dp[i - 1] + nums[i] : nums[i];
            result = max(dp[i], result);
        }
        return result;
    }
};
// @lc code=end
