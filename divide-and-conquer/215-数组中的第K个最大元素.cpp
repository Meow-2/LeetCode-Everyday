/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int slow = 1;
        int i    = 1;
        while (i < nums.size()) {
            if (nums[i] <= nums[0]) {
                swap(nums[i], nums[slow++]);
            }
            i++;
        }
        swap(nums[0], nums[slow - 1]);
    }
};
// @lc code=end
