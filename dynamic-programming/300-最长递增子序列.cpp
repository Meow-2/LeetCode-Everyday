/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        // dp[i]表示以nums[i]结尾的最大递增子序列长度
        vector dp(nums.size(), 0);
        dp[0]   = 1;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
                if (nums[j] == nums[i])
                    dp[i] = max(dp[j], dp[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end
