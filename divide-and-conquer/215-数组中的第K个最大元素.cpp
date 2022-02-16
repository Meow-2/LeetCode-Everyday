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
        int left  = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int slow = left;
            int i    = left;
            while (i <= right) {
                if (nums[i] >= nums[left]) {
                    swap(nums[i], nums[slow++]);
                }
                i++;
            }
            swap(nums[left], nums[slow - 1]);
            if (slow - left == k)
                return nums[slow - 1];
            else if (slow - left > k) {
                right = slow - 2;
            }
            else {
                k    = k - slow + left;
                left = slow;
            }
        }
        return nums[left];
    }
};
// @lc code=end