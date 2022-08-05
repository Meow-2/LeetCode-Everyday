/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // bool dfs(vector<int>& nums, int pos, int target, unordered_map<int, int>& mem)
    // {
    //     // cout << " pos: " << pos << " target: " << target << '\n';
    //     if (target == 0)
    //         return true;
    //     if (target < 0 || pos == nums.size())
    //         return false;
    //     if (mem.count(target) && pos >= mem[target])
    //         return false;
    //     // if (dfs(nums, pos + 1, target - nums[pos], mem))
    //     //     return true;
    //     // if (dfs(nums, pos + 1, target, mem))
    //     //     return true;
    //     for (int i = pos; i < nums.size(); i++) {
    //         if (dfs(nums, i + 1, target - nums[i], mem))
    //             return true;
    //     }
    //     if (!mem.count(target))
    //         mem[target] = pos;
    //     else if (pos < mem[target])
    //         mem[target] = pos;
    //     return false;
    // }
    // bool canPartition(vector<int>& nums)
    // {
    //     int sum = 0;
    //     for_each(nums.begin(), nums.end(), [&](int const& x) { sum += x; });
    //     if (sum % 2)
    //         return false;
    //     int                     target = sum / 2;
    //     unordered_map<int, int> mem;
    //     // sort(nums.begin(), nums.end());
    //     return dfs(nums, 0, target, mem);
    // }

    // 转化为01背包问题动态规划
    bool canPartition(vector<int>& nums)
    {
        int sum     = 0;
        int max_num = INT_MIN;
        for_each(nums.begin(), nums.end(), [&](int const& x) {
            max_num = x > max_num ? x : max_num;
            sum += x;
        });
        if (sum % 2)
            return false;
        int target = sum / 2;
        if (max_num > target)
            return false;
        // dp[i][j] 表示 nums[0,i]能否凑出j
        vector dp(nums.size(), vector<bool>(target + 1, false));
        // base case
        for (int i = 0; i < nums.size(); i++)
            dp[i][0] = true;
        for (int i = 0; i < target + 1; i++)
            dp[0][i] = nums[0] == i ? true : false;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j < target + 1; j++)
                if (j - nums[i] >= 0)
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                else
                    dp[i][j] = dp[i - 1][j];
        }
        return dp[nums.size() - 1][target];
    }
};
// @lc code=end
int main()
{
    Solution a;
    // vector   v = {1, 2, 3, 5, 17, 6, 14, 12, 6};
    vector v = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
                100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    // vector v = {100, 100, 100, 100, 100, 100, 100, 100, 100,
    //             100, 100, 100, 100, 100, 100, 100, 100, 100};
    std::cout << a.canPartition(v);
    return 0;
}