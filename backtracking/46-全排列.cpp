/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <type_traits>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& path)
    {
        if (nums.size() == 0)
            res.push_back(path);
        for (int i = 0; i < nums.size(); i++) {
            auto num = nums[i];
            path.push_back(num);
            nums.erase(nums.begin() + i);
            backtrack(nums, res, path);
            nums.insert(nums.begin() + i, num);
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int>         path;
        backtrack(nums, res, path);
        return res;
    }
};
// @lc code=end
