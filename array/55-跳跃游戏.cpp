/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    // 超时
    // void dfs(vector<int>& nums, int index, bool& result)
    // {
    //     if (index >= nums.size() - 1) {
    //         result = true;
    //         return;
    //     }
    //     if (nums[index] == 0)
    //         return;
    //     for (int i = nums[index]; i > 0; i--)
    //         dfs(nums, index + i, result);
    // }
    // bool canJump(vector<int>& nums)
    // {
    //     auto result = false;
    //     dfs(nums, 0, result);
    //     return result;
    // }
    bool canJump(vector<int>& nums)
    {
        int maxIndexCanGo = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                maxIndexCanGo = max(maxIndexCanGo, i + nums[i]);
            else if (maxIndexCanGo <= i && i != nums.size() - 1) {
                return false;
            }
        }
        return true;
    }
    // 超时
    // bool canJump(vector<int>& nums)
    // {
    //     vector<bool> dp(nums.size(), false);
    //     dp[0] = true;
    //     for (int i = 0; i < nums.size(); i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (dp[j] == true && i <= j + nums[j])
    //                 dp[i] = true;
    //         }
    //     }
    //     return dp[nums.size() - 1];
    // }
};
// @lc code=end
