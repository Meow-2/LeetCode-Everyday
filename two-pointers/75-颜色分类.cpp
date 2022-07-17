/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        // [0,left)为0, (right,nums.size())为2
        // left为第一个1, right为第一个2
        int left  = 0;
        int right = nums.size() - 1;
        for (int i = 0; i <= right; i++) {
            if (nums[i] == 0) {
                swap(nums[left], nums[i]);
                left++;
                continue;
            }
            if (nums[i] == 2) {
                swap(nums[right], nums[i]);
                right--;
                i--;
                continue;
            }
        }
    }
};
// @lc code=end
