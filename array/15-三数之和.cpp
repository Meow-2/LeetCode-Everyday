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
        if (nums.size() < 3)
            return {};
        int                 i = 0;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        while (i < nums.size() - 2) {
            if (nums[i] > 0)
                break;
            else {
                int target = 0 - nums[i];
                int left   = i + 1;
                int right  = nums.size() - 1;
                while (left < right) {
                    if (nums[left] + nums[right] < target)
                        left++;
                    else if (nums[left] + nums[right] > target)
                        right--;
                    else {
                        result.push_back({nums[i], nums[left], nums[right]});
                        left++;
                        while (left < nums.size() && nums[left] == nums[left - 1])
                            left++;
                    }
                }
            }
            i++;
            while (i < nums.size() - 2 && nums[i] == nums[i - 1])
                i++;
        }
        return result;
    }
};
// @lc code=end
