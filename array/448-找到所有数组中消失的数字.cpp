/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        vector<int> res;
        int         n = nums.size();
        for (int i = 0; i < n; i++) {
            unsigned int getNumsI = nums[i] % n ? nums[i] % n : n;
            nums[getNumsI - 1] += n;
        }
        for (int i = 0; i < n; i++)
            if (nums[i] <= n)
                res.push_back(i + 1);
        return res;
    }
};
// @lc code=end
