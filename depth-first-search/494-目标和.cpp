/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    unordered_map<string, int> mem;
    int                        dfs(vector<int>& nums, int pos, int target)
    {
        if (mem.count(to_string(pos) + '_' + to_string(target)))
            return mem[to_string(pos) + '_' + to_string(target)];
        if (pos == nums.size())
            return target == 0 ? 1 : 0;
        int res = dfs(nums, pos + 1, target - nums[pos]) + dfs(nums, pos + 1, target + nums[pos]);
        mem[to_string(pos) + '_' + to_string(target)] = res;
        return res;
    }
    int findTargetSumWays(vector<int>& nums, int target) { return dfs(nums, 0, target); }
};
// @lc code=end
