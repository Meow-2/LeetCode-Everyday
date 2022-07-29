/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include <ostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> m;
        for (auto i : nums)
            m[i]++;
        auto cmp = [](pair<int, int> const& x, pair<int, int> const& y) {
            return x.second > y.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        int count = 0;
        for (auto& i : m) {
            if (count < k) {
                q.push(i);
                count++;
            }
            else if (i.second > q.top().second) {
                q.pop();
                q.push(i);
            }
        }
        vector res(k, 0);
        for (auto& i : res) {
            i = q.top().first;
            q.pop();
        }
        return res;
    }
};
// @lc code=end
// int main()
// {
//     Solution a;
//     vector   v = {1, 1, 1, 2, 2, 3};
//     a.topKFrequent(v, 2);
//     return -1;
// }