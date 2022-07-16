/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(),
             [](vector<int> const& a, vector<int> const& b) { return a[0] < b[0]; });
        auto left = intervals[0][0], right = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= right && intervals[i][1] > right) {
                right = intervals[i][1];
            }
            else if (intervals[i][0] > right) {
                result.push_back({left, right});
                left  = intervals[i][0];
                right = intervals[i][1];
            }
        }
        result.push_back({left, right});
        return result;
    }
};
// @lc code=end
