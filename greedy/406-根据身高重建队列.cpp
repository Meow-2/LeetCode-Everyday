/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include <algorithm>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
    {
        sort(people.begin(), people.end(), [](auto const& x, auto const& y) {
            return x[0] > y[0] || (x[0] == y[0] && x[1] < y[1]);
        });
        vector<vector<int>> res;
        for (auto const& i : people) {
            if (res.empty()) {
                res.push_back(i);
                continue;
            }
            int count = 0;
            int index = 0;
            while (count < i[1]) {
                if (res[index][0] >= i[0])
                    count++;
                index++;
            }
            res.insert(res.begin() + index, i);
        }
        return res;
    }
};
// @lc code=end
int main()
{
    Solution            a;
    vector<vector<int>> v = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    a.reconstructQueue(v);
    return 0;
}