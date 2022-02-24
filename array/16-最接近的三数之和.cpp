/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int i   = 0;
        int sum = 0;
        int gap = INT_MAX;
        while (i < nums.size() - 2) {
            int left  = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int tempSum = nums[i] + nums[left] + nums[right];
                int tempGap = abs(target - tempSum);
                if (tempGap < gap) {
                    sum = tempSum;
                    gap = tempGap;
                }
                if (tempSum > target)
                    right--;
                else if (tempSum < target)
                    left++;
                else
                    return tempSum;
            }
            i++;
            while (i < nums.size() && nums[i] == nums[i - 1])
                i++;
        }
        return sum;
    }
};
// @lc code=end
