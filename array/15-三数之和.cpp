/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <algorithm>
#include <memory>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int                 i = 0, j = 0, k = 0;
        vector<vector<int>> res;
        //排序, 方便去重
        sort(nums.begin(), nums.end());
        while (i < nums.size()) {
            int target = 0 - nums[i];
            int left   = i + 1;
            int right  = nums.size() - 1;
            // 对撞指针
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    // 防止重复, 如果nums[left]前一个值和它一样, 那么说明已经统计过了
                    // 当然如果 left = i + 1 的话, 那就说明还没有统计过
                    if (nums[left] != nums[left - 1] || left == i + 1)
                        res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] < target)
                    left++;
                else
                    right--;
            }
            // i++; 如果 i++ 之后还是原来的 i ,则继续 i++, 直到不是原来的 i, 防止重复
            do {
                i++;
            } while (i < nums.size() && nums[i] == nums[i - 1]);
        }
        return res;
    }
};
// @lc code=end
