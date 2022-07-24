/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector res(nums.size(), 1);
        int    product_front  = 1;
        int    product_behind = 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size() && j >= 0; i++, j--) {
            res[i] = res[i] * product_front;
            res[j] = res[j] * product_behind;
            product_front *= nums[i];
            product_behind *= nums[j];
        }
        return res;
    }
};
// @lc code=end
