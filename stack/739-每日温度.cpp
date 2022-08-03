/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        vector     ans(temperatures.size(), 0);
        stack<int> s;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end
