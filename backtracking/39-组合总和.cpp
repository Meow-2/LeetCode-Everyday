/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    void backtrack(int begin_index, vector<int>& candidates, int target, vector<vector<int>>& res,
                   vector<int>& path)
    {
        auto sum = accumulate(path.begin(), path.end(), 0);
        if (sum > target)
            return;
        if (sum == target) {
            res.push_back(path);
            return;
        }
        for (int i = begin_index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            backtrack(i, candidates, target, res, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int>         path;
        backtrack(0, candidates, target, res, path);
        return res;
    }
};
// @lc code=end
