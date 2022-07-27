/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int not_zero_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i])
                swap(nums[i], nums[not_zero_index++]);
        }
        return;
    }
};
// @lc code=end
