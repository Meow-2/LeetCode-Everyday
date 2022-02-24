/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

#include <algorithm>
#include <ios>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        if (nums.size() < 4)
            return {};
        sort(nums.begin(), nums.end());
        int                 i = 0;
        vector<vector<int>> result;
        while (i < nums.size() - 3) {
            int j = i + 1;
            while (j < nums.size() - 2) {
                int leave = target - nums[i] - nums[j];
                int left  = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (nums[left] + nums[right] < leave)
                        left++;
                    else if (nums[left] + nums[right] > leave)
                        right--;
                    else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        while (left < nums.size() && nums[left] == nums[left - 1])
                            left++;
                    }
                }
                j++;
                while (j < nums.size() && nums[j] == nums[j - 1])
                    j++;
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
        return result;
    }
};
// @lc code=end
