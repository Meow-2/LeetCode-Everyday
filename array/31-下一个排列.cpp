/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int index = nums.size() - 1;
        while (index > 0 && nums[index] <= nums[index - 1])
            index--;
        // cout << "index:" << index << '\n';
        if (index == 0) {
            int i = index;
            int j = nums.size() - 1;
            while (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            return;
        }
        if (index == nums.size() - 1) {
            swap(nums[index], nums[index - 1]);
            return;
        }
        int index1 = nums.size() - 1;
        while (index1 > index && nums[index1] <= nums[index - 1])
            index1--;
        // cout << "index1:" << index1 << '\n';
        swap(nums[index1], nums[index - 1]);
        int i = index;
        int j = nums.size() - 1;
        // cout << "reverse:[" << i << "," << j << "]" << '\n';
        while (i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }
        return;
    }
};
// @lc code=end
