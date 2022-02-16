/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int left     = 0;
        int right    = 0;   //[left,right)为子数组
        int sum      = 0;
        int minLenth = nums.size() + 1;
        while (right < nums.size()) {
            sum += nums[right++];
            while (sum >= target) {
                minLenth = min(minLenth, right - left);
                sum -= nums[left++];
            }
        }
        return minLenth == nums.size() + 1 ? 0 : minLenth;
    }
};
// @lc code=end