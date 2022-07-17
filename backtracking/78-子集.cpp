/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void backtrack(vector<int>& nums, int index, vector<vector<int>>& res, vector<int>& path)
    {
        res.push_back(path);
        if (index > nums.size() - 1) {
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1, res, path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int>         path;
        backtrack(nums, 0, res, path);
        return res;
    }
};
// @lc code=end
