/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    // dp超时
    // int subarraySum(vector<int>& nums, int k)
    // {
    //     int n   = nums.size();
    //     int res = 0;
    //     // dp[i][j]: sum of [i,j]
    //     vector dp(n, vector<int>(n, 0));
    //     for (int L = 1; L <= n; L++) {
    //         for (int i = 0; i < n; i++) {
    //             int j = i + L - 1;
    //             if (j < n) {
    //                 if (i == j)
    //                     dp[i][j] = nums[i];
    //                 else
    //                     dp[i][j] = dp[i][j - 1] + nums[j];
    //                 if (dp[i][j] == k)
    //                     res++;
    //             }
    //         }
    //     }
    //     return res;
    // }

    // hash超时
    // int subarraySum(vector<int>& nums, int k)
    // {
    //     // 从0到以hash的下标为结尾的和
    //     vector hash(nums.size(), 0);
    //     int    sum   = 0;
    //     int    index = 0;
    //     auto   res   = 0;
    //     for_each(nums.begin(), nums.end(), [&](auto const x) {
    //         sum += x;
    //         if (sum == k)
    //             res++;
    //         hash[index++] = sum;
    //     });
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = i + 1; j < nums.size(); j++) {
    //             hash[j] -= nums[i];
    //             if (hash[j] == k)
    //                 res++;
    //         }
    //     }
    //     return res;
    // }

    int subarraySum(vector<int>& nums, int k)
    {
        int sum{0};
        int count{0};
        //前缀和和其对应的个数
        unordered_map<int, int> pre;
        pre[0] = 1;
        for (auto i : nums) {
            sum += i;
            if (pre.count(sum - k))
                count += pre[sum - k];
            pre[sum]++;
        }
        return count;
    }
};
// @lc code=end
