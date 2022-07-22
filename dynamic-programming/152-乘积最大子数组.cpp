/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <climits>
#include <linux/limits.h>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 二维dp暴力超时
    // int maxProduct(vector<int>& nums)
    // {
    //     int n = nums.size();
    //     dp[i][j]表示nums[i]到nums[j]的乘积
    //     vector dp(n, vector(n, 1));
    //     int    res = INT_MIN;
    //     for (int i = 0; i < n; i++) {
    //         dp[i][i] = nums[i];
    //         res      = max(res, dp[i][i]);
    //     }
    //     for (int l = 2; l <= n; l++) {
    //         for (int i = 0; i < n; i++) {
    //             int j = i + l - 1;
    //             if (j < n) {
    //                 dp[i][j] = dp[i][j - 1] * nums[j];
    //                 res      = max(res, dp[i][j]);
    //             }
    //         }
    //     }
    //     return res;
    // }

    // 一维dp, 优化前
    // int maxProduct(vector<int>& nums)
    // {
    //     int n = nums.size();
    //     // dp[i]表示以nums[i]结尾的连续数组的最大非0乘积,
    //     vector      dp(n, 1);
    //     vector<int> v;
    //     int         res          = INT_MIN;
    //     int         nearest_zero = -1;
    //     dp[0]                    = nums[0];
    //     if (nums[0] < 0)
    //         v.push_back(0);
    //     else if (nums[0] == 0)
    //         nearest_zero = 0;
    //     res = max(res, dp[0]);
    //     for (int i = 1; i < n; i++) {
    //         if (nums[i] == 0) {
    //             dp[i]        = 0;
    //             nearest_zero = i;
    //             v.clear();
    //         }
    //         else if (nums[i] > 0)
    //             dp[i] = dp[i - 1] > 0 ? dp[i - 1] * nums[i] : nums[i];
    //         else {
    //             if (v.size() == 0)
    //                 dp[i] = nums[i];
    //             else if (v.size() % 2) {
    //                 //如果前面有奇数个负数
    //                 dp[i] = nums[i] * dp[v.front()];
    //                 if (i - v.front() > 1)
    //                     dp[i] = dp[i] * dp[i - 1];
    //                 if (v.front() - nearest_zero > 1)
    //                     dp[i] = dp[i] * dp[v.front() - 1];
    //             }
    //             else {
    //                 //如果前面有偶数个负数
    //                 dp[i] = nums[i] * dp[i - 1] / dp[v.front()];
    //                 if (v.front() - nearest_zero > 1)
    //                     dp[i] = dp[i] / dp[v.front() - 1];
    //                 ;
    //             }
    //             v.push_back(i);
    //         }
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }

    // 一维dp, 优化后
    // int maxProduct(vector<int>& nums)
    // {
    //     int    n = nums.size();
    //     vector dp(n + 1, 1);
    //     dp[0]             = 0;
    //     int lt_zero_count = 0;
    //     int first_lt_zero = -1;
    //     int res           = INT_MIN;
    //     for (int i = 1; i < n + 1; i++) {
    //         if (nums[i - 1] == 0) {
    //             dp[i]         = 0;
    //             lt_zero_count = 0;
    //             first_lt_zero = -1;
    //         }
    //         else if (nums[i - 1] > 0) {
    //             dp[i] = dp[i - 1] > 0 ? dp[i - 1] * nums[i - 1] : nums[i - 1];
    //         }
    //         else {
    //             if (lt_zero_count % 2) {
    //                 // 已有奇数个负数
    //                 dp[i] = nums[i - 1] * nums[first_lt_zero];
    //                 if (i - 1 - first_lt_zero > 1)
    //                     dp[i] *= dp[i - 1];
    //                 if (dp[first_lt_zero] > 0)
    //                     dp[i] *= dp[first_lt_zero];
    //             }
    //             else {
    //                 if (first_lt_zero == -1) {
    //                     first_lt_zero = i - 1;
    //                     dp[i]         = nums[i - 1];
    //                 }
    //                 else {
    //                     dp[i] = dp[i - 1] * nums[i - 1] / nums[first_lt_zero];
    //                     if (dp[first_lt_zero] > 0)
    //                         dp[i] /= dp[first_lt_zero];
    //                 }
    //             }
    //             lt_zero_count++;
    //         }
    //         res = max(res, dp[i]);
    //     }
    //     return res;
    // }

    // 两个一维dp, 分别记录以nums[i]为结尾的连续子序列的最大、最小乘积
    // int maxProduct(vector<int>& nums)
    // {
    //     int    n = nums.size();
    //     vector dp_min(n, 1);
    //     vector dp_max(n, 1);
    //     dp_min[0] = dp_max[0] = nums[0];
    //     auto res              = dp_max[0];
    //     for (int i = 1; i < n; i++) {
    //         if (nums[i] == 0)
    //             dp_max[i] = dp_min[i] = 0;
    //         else if (nums[i] > 0) {
    //             dp_max[i] = dp_max[i - 1] > 0 ? dp_max[i - 1] * nums[i] : nums[i];
    //             dp_min[i] = dp_min[i - 1] * nums[i];
    //         }
    //         else {
    //             dp_max[i] = dp_min[i - 1] < 0 ? dp_min[i - 1] * nums[i] : nums[i];
    //             dp_min[i] = dp_max[i - 1] > 0 ? dp_max[i - 1] * nums[i] : nums[i];
    //         }
    //         res = max(res, dp_max[i]);
    //     }
    //     return res;
    // }
    int maxProduct(vector<int>& nums)
    {
        int    n = nums.size();
        vector dp_min(n, 1);
        vector dp_max(n, 1);
        dp_min[0] = dp_max[0] = nums[0];
        auto res              = dp_max[0];
        for (int i = 1; i < n; i++) {
            dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            dp_min[i] = min(nums[i], min(dp_min[i - 1] * nums[i], dp_max[i - 1] * nums[i]));
            res       = max(res, dp_max[i]);
        }
        return res;
    }
};
// @lc code=end