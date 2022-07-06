/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;
// @lc code=start
class Solution
{
public:
    // int search(vector<int>& nums, int target)
    // {
    //     int left  = 0;
    //     int right = nums.size() - 1;
    //     while (left <= right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] == target)
    //             return mid;
    //         if (nums[left] > nums[right]) {
    //             if (nums[mid] < target) {
    //                 if (nums[mid] < nums[left] && nums[right] < target) {
    //                     right = mid - 1;
    //                     continue;
    //                 }
    //                 else {
    //                     left = mid + 1;
    //                     continue;
    //                 }
    //             }
    //             else {
    //                 if (nums[mid] > nums[right] && nums[left] > target) {
    //                     left = mid + 1;
    //                     continue;
    //                 }
    //                 else {
    //                     right = mid - 1;
    //                     continue;
    //                 }
    //             }
    //         }
    //         else {
    //             if (nums[mid] < target) {
    //                 left = mid + 1;
    //                 continue;
    //             }
    //             else {
    //                 right = mid - 1;
    //                 continue;
    //             }
    //         }
    //     }
    //     return -1;
    // }
    int search(vector<int>& nums, int target)
    {
        int left  = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > nums[right] && target < nums[left]) {
                left = mid + 1;
                continue;
            }
            if (nums[mid] < nums[left] && target > nums[right]) {
                right = mid - 1;
                continue;
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
        return -1;
    }
};
// @lc code=end
