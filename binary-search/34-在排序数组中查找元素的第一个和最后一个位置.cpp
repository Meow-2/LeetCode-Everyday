/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int  left = 0, right = nums.size() - 1;
        int  res_left = -1, res_right = -1;
        bool is_res_left_get  = false;
        bool is_res_right_get = false;
        while (left <= right && !(is_res_left_get && is_res_right_get)) {
            int mid = left + (right - left) / 2;
            // cout << "left:" << left << " right:" << right << " mid:" << mid << '\n';
            if (nums[mid] == target) {
                // cout << "nums[mid] == target: " << mid << ":" << nums[mid] << "=" << target <<
                // '\n';
                if (!is_res_right_get) {
                    // cout << "res right not found yet" << '\n';
                    if (mid == nums.size() - 1 ||
                        (mid + 1 < nums.size() && nums[mid + 1] > target)) {
                        // cout << "res right found!" << '\n';
                        is_res_right_get = true;
                        res_right        = mid;
                        right            = mid;
                        left             = 0;
                        continue;
                    }
                    left = mid + 1;
                    continue;
                }
                if (!is_res_left_get) {
                    // cout << "res left not found yet" << '\n';
                    if (mid == 0 || (mid - 1 >= 0 && nums[mid - 1] < target)) {
                        // cout << "res left found!" << '\n';
                        is_res_left_get = true;
                        res_left        = mid;
                        left            = mid;
                        right           = nums.size() - 1;
                        continue;
                    }
                    right = mid - 1;
                    continue;
                }
            }
            if (nums[mid] < target) {
                left = mid + 1;
                continue;
            }
            if (nums[mid] > target) {
                right = mid - 1;
                continue;
            }
        }
        return {res_left, res_right};
    }
};
// @lc code=end
