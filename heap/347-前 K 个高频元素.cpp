/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        map<int, int> a;
        vector<int>   result;
        for (auto& i : nums)
            a[i]++;
        priority_queue<pair<int, int>> q;
        for (auto& j : a)
            q.push({j.second, j.first});
        for (int i = 0; i < k; i++) {
            result.push_back(q.top().second);
            q.pop();
        }
        return result;
    }
};
// @lc code=end
